import sys
import os
from os import walk
import codepost
from config import config
from course import course

# this script interfaces with codepost and brings everything
# together:
# 1. It pulls the current roster from Canvas (and separates
#    instructors/graders/students using the config.py params)
# 2. It attempts to map NUIDs to CSE logins to grab submissions
#    (failures will be excluded or "orphaned")
# 3. It then randomizes grading assignments (tries to evenly
#    distribute among the graders) and produces a hardcopy report
# 4. It then scans the handin directory for specific files and
#    submits them to codepost.io with the assigning the grader to
#    each.
#
# This script assumes that the course and assignments have 
# already been setup and that no submissions have been made.
# Preexisting submissions will result in a fatal error (so it
# is best to do this cleanly and/or wipe the assignment on
# codepost.io and restart)

if(len(sys.argv) != 3):
  print("usage: cse_handin_assignment_name codepost_assignment_id")  
  exit(1)

# this may need to be changed relative to where this script is used
# TODO: consider moving this to config.py
assignmentDir = "../handin/"+sys.argv[1]+"/"
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
             students=[s.cseEmail],
             grader=grader.cseEmail)
          for fileName in filenames:
              print("pushing " + path+fileName)
              contents = open(path+fileName).read()
              (_,extension) = os.path.splitext(fileName)
              extension = extension[1:] #chomp period: .c -> c
              codepost.file.create(
                 name=fileName,
                 code=contents,
                 extension=extension,
                 submission=submission.id
              )

            # codepost.file.create(
            #   name="Hello.go",
            #   code='fmt.Println("hello world")',
            #   extension="go",
            #   submission=submission.id
            # )