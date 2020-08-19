"""
This script interfaces with canvas, CSE's User Database and 
codepost to assign graders to student submissions for a particular
assignment including pushing all submission files to codepost.

Usage: python3 codepostAssignGraders.py cse_handin_assignment_name codepost_assignment_id

where 
  - cse_handin_assignment_name is the "name" of the handin assignment 
    (corresponds to the handin directory created)
  - codepost_assignment_id is the codepost assignment (database) ID.
    You can retrieve this by first running codepostListCourseInfo.py

In detail this script:

 1. It pulls the current roster from Canvas (and separates
    instructors/graders/students using the config.py params)
 2. It attempts to map NUIDs to CSE logins to grab submissions
    (failures will be excluded or "orphaned")
 3. It randomizes grading assignments (evenly distributing
    them among graders) and outputs an assignment report to
    the standard output
 4. It scans the handin directory for files whose extensions
    match those in the config.py file and pushes them to 
    codepost.io associated them with the assigned grader.
    
This script assumes that the course and assignments have 
already been setup and that no files have been submitted 
to codepost already.  Preexisting submissions will result 
in a fatal error (so it is best to do this cleanly and/or 
wipe the assignment on codepost.io and restart)
"""
import sys

if(len(sys.argv) != 3):
  print("usage: cse_handin_assignment_name codepost_assignment_id")  
  exit(1)

import os
import codepost
from config import config
from course import course
from fileUtils import getFiles 

assignmentDir = config.handinDirectory + sys.argv[1]+"/"
if not os.path.exists(assignmentDir):
    print("assignment directory: " + assignmentDir + " does not seem to exist")
    print("perhaps you need more practice operating your computer machine")
    exit(1)

assignmentId = int(sys.argv[2])

codepost.configure_api_key(config.codePostApiKey)

gradingAssignment = course.getGradingAssignment()
s = course.assignmentToString(gradingAssignment)
print(s)

# TODO: port over Hundter's CSV dump

def pushAssignments(gradingAssignment):
  for grader,groups in gradingAssignment.items():
    for g in groups:
      s = g.members[0]
      path = assignmentDir+s.cseLogin+"/"
      print("Pushing files in " + path + "...")
      try:
        files = getFiles(path)
      except:
        e = sys.exc_info()[0]
        print("Error: %s" % e )
        files = {}
      if files:
        submission = codepost.submission.create(
          assignment=assignmentId,
          students=[m.canvasEmail for m in g.members],
          grader=grader.canvasEmail)
        for (fullPath,name,ext),contents in files.items():
          print("pushing " + name)
          codepost.file.create(
            name=name,
            code=contents,
            extension=ext,
            submission=submission.id
          )

pushAssignments(gradingAssignment)
