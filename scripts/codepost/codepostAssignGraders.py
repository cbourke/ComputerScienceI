"""
This script interfaces with canvas and codepost.io to assign
graders to student submissions for a particular assignment.

TODO: this needs to be updated to
 -pull groupings from canvas
 -update assignment submissions in codepost; preferring
  the first group member's submission.
 -assign graders randomly based on graders.

Usage: python3 codepostAssignGraders.py codepost_assignment_id

where
  - cse_handin_assignment_name is the "name" of the handin assignment
    (corresponds to the handin directory created)
  - codepost_assignment_id is the codepost assignment (database) ID.
    You can retrieve this by first running codepostListCourseInfo.py

In detail:

 1. It loads the current roster from Canvas (and separates
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
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("cseHandinAssignmentNumber", help=
  """The CSE Handin Assignment number which is also the
  name of the directory in which files are stored.
  Example: A1 would be expected to be in ~/handin/A1)
  """
  )
parser.add_argument("codepostAssignmentId", help=
  """The codepost.io assignment ID number (a run of
  codepostListCourseInfo.py or codepostValidateCourse.py
  may be necessary to find this)
  """, type=int)
parser.add_argument("--push", action='store_true', help=
  """Push the assignment source files to codepost.io. The
  default is to not push files so a test run of assignments
  can be made.
  """)
args = parser.parse_args()

cseHandinAssignmentNumber = args.cseHandinAssignmentNumber
codepostAssignmentId = args.codepostAssignmentId
pushToCodePost = args.push

import sys
import os
import codepost
from config import config
from course import course
from fileUtils import getFiles

assignmentDir = config.handinDirectory + cseHandinAssignmentNumber + "/"
if not os.path.exists(assignmentDir):
    print("assignment directory: " + assignmentDir + " does not seem to exist")
    print("perhaps you need more practice operating your computer machine")
    exit(1)


codepost.configure_api_key(config.codePostApiKey)

gradingAssignment = course.getGradingAssignment()
s = course.assignmentToString(gradingAssignment)
print(s)

csv = course.assignmentToCSV(gradingAssignment)
f = open(cseHandinAssignmentNumber+".csv", "w")
f.write(csv)
f.close()

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
          assignment=codepostAssignmentId,
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

if pushToCodePost:
  pushAssignments(gradingAssignment)
else:
  print("Cowardly refusing to push source files to codepost.io; rerun with --push if you wanna.")
