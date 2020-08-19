from config import config
from person import Person
from group import Group
from canvas_api_client.v1_client import CanvasAPIv1
import sys
import http.client
import json

"""
This module provides a collection of utilities and a thin wrapper
interface with the Canvas API using a combination of the python 
CanvasAPIv1 package and direct HTTPS connections.  

References:
 - UNL's Canvas API instance is at:
   https://canvas.unl.edu/api/v1/
 - UNL's Live instance:
   https://canvas.unl.edu/doc/api/live
 - CanvasAPIv1 (canvas-api-client) documentation:
   https://wgwz.github.io/canvas-lms-tools/canvas_api_client.html#module-canvas_api_client.v1_client
   
"""

canvasHost = "canvas.unl.edu"
api = CanvasAPIv1(config.canvasUrl, config.canvasApiKey)

def getGroupCategoryId(groupSetName):
  """
  Retrieves the Canvas "Group Set" ID (internally this is 
  designated as a Group Category) given the name of the 
  group such as "Assignment Pairs".  If no match is found, 
  None is returned.
  """
  path = ("/api/v1/courses/" + 
          config.canvasCourseId +
          "/group_categories/?access_token=" +
          config.canvasApiKey)
  connection = http.client.HTTPSConnection(canvasHost)
  connection.request("GET", path)
  response = connection.getresponse()
  #print("Status: {} and reason: {}".format(response.status, response.reason))
  data = response.read().decode()
  connection.close();
  categories = json.loads(data)
  for category in categories:
    if category['name'] == groupSetName:
      return category['id']
  return None

def getMembers(groupId):
  """
  Retrieves the canvas user IDs of the members of the given
  canvas group.
  """
  path = ("/api/v1/groups/" + 
          str(groupId) + 
          "/memberships/?access_token="+config.canvasApiKey)      
  connection = http.client.HTTPSConnection(canvasHost)
  connection.request("GET", path)
  response = connection.getresponse()
  data = response.read().decode()
  connection.close();
  members = json.loads(data)
  result = []
  for member in members:
    userId = member['user_id']
    result.append(userId)
  return result
  
def getGroupTuples(groupSetName=None):
  """
  Retrieves groups and members from Canvas based on the
  given Group Set (group category).  If none is provided,
  every group is retrieved.  Only groups with more than
  one member are included though.
  
  Returns an array of 3-tuples consisting of:
    (groupId,"groupName",[membersCanvasIds])
    
  """
  groupCategoryId = None
  if groupSetName is not None:
    groupCategoryId = getGroupCategoryId(groupSetName)
  path = ("/api/v1/courses/" + 
          config.canvasCourseId + 
          "/groups/?per_page=100&access_token="+config.canvasApiKey)      
  connection = http.client.HTTPSConnection(canvasHost)
  connection.request("GET", path)
  response = connection.getresponse()
  data = response.read().decode()
  connection.close();

  result = []
  groups = json.loads(data)
  for group in groups:
    if group['members_count'] > 1 and (groupCategoryId is None or group['group_category_id'] == groupCategoryId):
      groupId = group['id']
      name = group['name']
      members = getMembers(groupId)
      result.append( (groupId,name,members) )
  return result

def getRoster():
  """
  Retrieves the complete roster of the course from Canvas
  including all students, instructors, TAs, etc.
  
  Returns a mapping of {NUID => Person objects}
  """
  roster = {}
  pages = api.get_course_users(config.canvasCourseId)
  # the API lazy loads elements and uses pagination, 
  # so a double iteration is necessary.
  for page in pages:
    for u in page:
      try: 
        canvasLogin = None
        canvasEmail = None
        if 'login_id' in u:
          canvasLogin = u['login_id']
        else:
          print("ERROR: no login_id for user")
          print(u)
        if 'email' in u:
          canvasEmail = u['email']
        else:
          print("ERROR: no email for user")
          print(u)
          sys.exit(1)
        p = Person(
          nuid        = u['sis_user_id'],
          canvasId    = u['id'],
          name        = u['sortable_name'], #format: "last, first"
          canvasLogin = canvasLogin,
          canvasEmail = canvasEmail
        )
        roster[p.nuid] = p
      except:
        print("Problem with record:")
        print(u)
        e = sys.exc_info()[0]
        write_to_page( "<p>Error: %s</p>" % e )
  return roster

def getGroups(roster):
  """  
  Returns a list of Group objects from Canvas based on 
  the Group Set name in the configuration file.  If no such
  group set exists or if an individual is not part of a group, 
  they are placed in a group of one.
  
  In addition, each Person object in the given roster is 
  associated with its group.
  """
  groups = []
  #if config.gradingGroupName is None:
  #  return groups
  groupData = getGroupTuples(config.gradingGroupName)
  for gd in groupData:
    #(groupId,"groupName",[membersCanvasIds])
    g = Group(gd[0],gd[1])
    members = []
    for memberCanvasId in gd[2]:
      for nuid,p in roster.items():
        if p.canvasId == memberCanvasId:
          members.append(p)
          p.group = g;
          break
    g.addMembers(members)
    groups.append(g)
    
  # iterate through roster and create groups of one:
  for nuid,p in roster.items():
    if p.group is None:
      g = Group()
      g.addMembers([p])
      p.group = g 
      groups.append(g)
  return groups

# {NUID => Person}
roster = getRoster()
# [Group]
groups = getGroups(roster)

