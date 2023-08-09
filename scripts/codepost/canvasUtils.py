"""
This module provides a collection of functions that give a
thin wrapper interface to the Canvas API.

References:
 - UNL's Canvas API instance is at:
   https://canvas.unl.edu/api/v1/
 - UNL's Live instance:
   https://canvas.unl.edu/doc/api/live

"""

from config import config

from assignment import Assignment
from person import Person
from group import Group

import copy
import http.client
import json
import pprint
import re
import requests
from urllib.parse import urlencode

canvasHost = "canvas.unl.edu"
canvasBaseApiPath = "/api/v1"
defaultParams = {
  "access_token": config.canvas_api_key,
  "per_page": 100
}

def get_canvas_data(path, userParameters = {}):
    """A general canvas API interface that will retrieve data (using
    HTTP GET) from the provided `path` (ex: `"courses/{course_id}/assignments").
    This function uses pagination to ensure all data is retrieved.

    The raw response data is automatically deserialized (assumed to
    be JSON) and returned; generally this is a list of JSON objects.

    Parameters can be provided in the optional `userParameters` field,
    any user-provided parameters will supercede the defaults.
    """

    moreData = True
    data = []
    params = urlencode( {**defaultParams, **userParameters} )
    path = f"{canvasBaseApiPath}/{path}?{params}"
    connection = http.client.HTTPSConnection(canvasHost)
    while moreData:
        connection.request("GET", path)
        response = connection.getresponse()
        raw_data = response.read().decode()
        new_data = json.loads(raw_data)
        if isinstance(new_data, dict):
            # API has returned a single json object instead of a list of objects
            # immediately close and return
            connection.close()
            return new_data
        data += new_data
        headers = response.info()
        linkHeader = headers['Link']
        links = parse_header_links(linkHeader)
        if 'next' in links:
          #python 3.9+: path = links['next'].removeprefix("https://canvas.unl.edu") + "&access_token=" + config.canvasApiKey
          path = links['next'][22:] + f"&{params}"
        else:
          moreData = False
    connection.close()
    return data

def parse_header_links(value):
    """Return a dict of parsed link headers proxies.
    This function is stolen from the requests package with
    moderate modifications so that it returns an actual
    dicionary mapping `rel` values to `url`s
    """

    if value is None:
        return {}

    links = []

    replace_chars = " '\""

    for val in re.split(", *<", value):
        try:
            url, params = val.split(";", 1)
        except ValueError:
            url, params = val, ''

        link = {}

        link["url"] = url.strip("<> '\"")

        for param in params.split(";"):
            try:
                key, value = param.split("=")
            except ValueError:
                break

            link[key.strip(replace_chars)] = value.strip(replace_chars)

        links.append(link)
    result = {}
    for foo in links:
        result[foo['rel']] = foo['url']

    return result

def getGroupCategoryId(groupSetName):
  """
  Retrieves the Canvas "Group Set" ID (internally this is
  designated as a Group Category) given the name of the
  group such as "Assignment Pairs".  If no match is found,
  None is returned.
  """
  path = f"/courses/{config.canvas_course_id}/group_categories"
  resultData = get_canvas_data(path)
  for category in resultData:
    if category['name'] == groupSetName:
      return category['id']
  return None

def getMembers(groupId):
  """
  Retrieves the canvas user IDs of the members of the given
  canvas group.
  """
  path = f"/groups/{groupId}/memberships"
  resultData = get_canvas_data(path)
  result = []
  for member in resultData:
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
  path = f"/courses/{config.canvas_course_id}/groups"
  resultData = get_canvas_data(path)
  result = []
  for group in resultData:
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

  We use `courses/{config.canvas_course_id}/users` instead
  of `/courses/{course_id}/enrollments` (which has a role
  field) since we still need to specify graders/non-graders
  among instructors/TAs/etc. manually in `config.py`

  Returns a mapping of {NUID => Person objects}
  """
  roster = {}
  path = f"courses/{config.canvas_course_id}/users"
  users = get_canvas_data(path)

  for user in users:
    canvasId = user['id']
    if 'login_id' in user:
        canvasLogin = user['login_id']
    else:
        canvasLogin = None
    nuid = user['sis_user_id']
    name = user['sortable_name'] #format: "last, first"
    if 'email' in user:
        email = user['email']
    else:
        email = None
    p = Person(
      nuid,
      name,
      canvasId,
      canvasLogin,
      email
    )
    roster[p.nuid] = p
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
  if config.grading_group_name is not None:
    groupData = getGroupTuples(config.grading_group_name)
    for gd in groupData:
      #(groupId,"groupName",[membersCanvasIds])
      g = Group(gd[0],gd[1])
      members = []
      for memberCanvasId in gd[2]:
        for nuid,p in roster.items():
          if p.canvasId == memberCanvasId:
            members.append(p)
            p.group = g
            break
      g.addMembers(members)
      groups.append(g)

  # iterate through roster and create groups of one:
  for nuid,p in roster.items():
    # but only if they have not already been assigned to a group
    if p.group is None:
      g = Group()
      g.addMembers([p])
      p.group = g
      groups.append(g)
  return groups

def getSections():
  """
  Retrieves all sections from the canvas course.  You can futher use

  https://canvas.unl.edu/api/v1/sections/{sectionId}/enrollments

  to get enrollments only for that section (which will include
  teachers, TAs, etc. but will have a `role` field to determine what
  it is.
  """
  path = f"/courses/{config.canvas_course_id}/sections"
  resultData = get_canvas_data(path)
  return resultData

def getGrade(assignmentId, userId):
  """
  Returns the grade (generally a float) from the canvas gradebook
  for the given assignment and user.  If no grade has been assigned,
  the result will be None.
  """
  path = f"/courses/{config.canvas_course_id}/assignments/{assignmentId}/submissions/{userId}"
  resultData = get_canvas_data(path)
  if 'score' in resultData:
      return resultData['score']
  else:
      return None


def setGrade(assignmentId, userId, score = None, comment = None):
   """
   Sets/updates the grade in the canvas gradebook for the given
   assignment (`assignmentId`) for the given user (`userId`).
   If the comment is specified, canvas *adds* the comment and
   does not modify or delete any old one(s).  If the
   score/comment are `None`, they are ignored which allows you
   to change the score with no comment, add a comment without
   changing the score, or doing both.  If both are `None` this
   function does nothing.
   """
   if score is None and comment is None:
       return
   url = f"https://canvas.unl.edu/api/v1/courses/{config.canvas_course_id}/assignments/{assignmentId}/submissions/{userId}"

   data = {}
   if score is not None:
       data['submission'] = { "posted_grade": score }
   if comment is not None:
       data['comment'] = { "text_comment": comment }
   response = requests.put(url, params=defaultParams, json=data)
   return

def getAssignmentGroupId(assignmentGroupName):
     """
     Retrieves the canvas assignment group ID for the assignment group with the
     given name.  Returns None if no such assignment group exists.

     """
     groups = getAssignmentGroups()
     groups = {i for i in groups if groups[i] == assignmentGroupName}
     return next(iter(groups), None)

def getAssignmentGroups():
   """
   Retrieves all assignment groups from canvas.  Returns a map of IDs
   to group names:

     {id -> name}

   """
   path = f"/courses/{config.canvas_course_id}/assignment_groups"
   data = get_canvas_data(path)
   aGroups = {}
   for r in data:
       id, name = r['id'], r['name']
       aGroups[id] = name
   return aGroups

def getAssignmentsInGroup(groupId):
   """
   Retrieves all assignments from an assignment group (for the given groupId)
   from canvas.  Returns a list of assignments.

   """
   path = f"/courses/{config.canvas_course_id}/assignment_groups/{groupId}/assignments"
   resultData = get_canvas_data(path)
   assignments = []
   for r in resultData:
       id = r['id']
       a = Assignment(r['id'], r['name'], r['points_possible'])
       assignments.append(a)
   return assignments

def getAssignments(name = ''):
   """
   Retrieves assignments from the canvas course.  By default, retrieves
   all assignments.  If the `name` parameter is provided, only assignments
   matching the name (even partially) will be included.

   Always returns a list regardless of the number of matched assignments.
   """
   path = f"/courses/{config.canvas_course_id}/assignments"
   params = {
     'search_term': name
   }
   resultData = get_canvas_data(path, params)
   assignments = []
   for r in resultData:
       id = r['id']
       a = Assignment(r['id'], r['name'], r['points_possible'])
       assignments.append(a)
   return assignments
