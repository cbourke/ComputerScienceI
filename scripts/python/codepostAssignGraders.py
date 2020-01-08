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

from config import config
from course import course
import os
import codepost

assignmentDir = config.handinDirectory + sys.argv[1]+"/"
if not os.path.exists(assignmentDir):
    print("assignment directory: " + assignmentDir + " does not seem to exist")
    print("perhaps you need more practice operating your computer machine")
    exit(1)

assignmentId = int(sys.argv[2])

codepost.configure_api_key(config.codePostApiKey)

gradingAssignment = course.getAssignment()
s = course.assignmentToString(gradingAssignment)
print(s)

for grader,students in gradingAssignment.items():
    for s in students:
        path = assignmentDir+s.cseLogin+"/"
        print("Looking in " + path)
        if not os.path.exists(path):
            print("no files...")
            filenames = []
        else:
            (_, _, filenames) = next(os.walk(assignmentDir+s.cseLogin))
        if config.fileExtensions:
            filenames = [ f for f in filenames if f.endswith(tuple(config.fileExtensions)) ]
        if filenames:
          submission = codepost.submission.create(
             assignment=assignmentId,
             students=[s.canvasEmail],
             grader=grader.canvasEmail)
          for fileName in filenames:
              print("pushing " + path+fileName)
              contents = open(path+fileName).read()
              #if the file is empty, add content to accommodate codepost's API
              if not contents:
                  contents = "EMPTY FILE"
              (_,extension) = os.path.splitext(fileName)
              extension = extension[1:] #chomp period: .c -> c
              codepost.file.create(
                 name=fileName,
                 code=contents,
                 extension=extension,
                 submission=submission.id
              )
