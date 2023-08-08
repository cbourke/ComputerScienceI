"""
This script is intended for use in CSCE 155E to facilitate its differential
lab/hack attendance policy.  Students are required to attend and if they do
they earn attendance points (which are manually entered into the canvas
gradebook).  However, high-performing students that do not attend can still
earn the points provided they meet a certain threshold of points for the
rest of the module.

This script interfaces with UNL' Canvas instance to update the attendance
points according to this policy.

TODO:
 -troubleshoot with actual course
 -Reorganize assignments into modules:
  Module x.0
   Reading
   Lab
   Hack
   Hack Attendance
   Lab Attendance
 NOTE: Gradebook view: OK; you can add "Filter" by assignment group
 -Assign attendance only to in-person
 -QUESTION: what happens via API when they are in the online section?

 NOTE: only run this for modules with all 5 items since 55 points are hard-coded
"""

from config import config
from course import course
from assignment import Assignment
from canvasUtils import getAssignmentGroupId
from canvasUtils import getAssignmentsInGroup
from canvasUtils import getGrade
from canvasUtils import setGrade

import argparse
import requests
from types import SimpleNamespace

parser = argparse.ArgumentParser()
parser.add_argument("moduleNumber", help=
  """The module number in canvas to update attendance
  scores for.)
  """, type=int)
parser.add_argument("--commit", action='store_true', help=
  """Commmits the changes to the gradebook.  If this is not
  provided, the script will run in coward mode and not make
  any modifications, only reporting what would have been done.
  """)
args = parser.parse_args()

moduleNumber = args.moduleNumber
commitToCanvas = args.commit

def getModule(moduleName):
  """
  Returns a "module" representation of a CS1 module in canvas (reading, lab,
  hack and attendance) for the module with the given moduleName
  """
  assignmentGroupId = getAssignmentGroupId(moduleName)
  assignments = getAssignmentsInGroup(assignmentGroupId)

  result = SimpleNamespace()
  result.reading = next(filter(lambda x: 'Reading' in x.name, assignments), None)
  result.lab = next(filter(lambda x: 'Lab' in x.name and 'Attendance' not in x.name, assignments), None)
  result.labAttendance = next(filter(lambda x: 'Lab Attendance' in x.name, assignments), None)
  result.hack = next(filter(lambda x: 'Hack' in x.name and 'Attendance' not in x.name, assignments), None)
  result.hackAttendance = next(filter(lambda x: 'Hack Attendance' in x.name, assignments), None)

  return result

def updateAttendance(module, student):
    """
    Updates the "differential attendance" score in the canvas gradebook for the
    given module and student.

    * If the attendance score for both a lab and hack are already awarded,
      no action is taken
    * If the score(s) necessary to determine if attendance should be awarded,
      a warning is printed and no action is taken
    * If the scores on the reading/lab/hack meet the threshold (>=75%), the
      attendance scores are updated along with a comment
    * Otherwise, the scores are not modified, but a comment is added
    """
    print(f"Processing student: {student}...")
    readingScore = getGrade(module.reading.id, student.canvasId)
    labScore = getGrade(module.lab.id, student.canvasId)
    labAttScore = getGrade(module.labAttendance.id, student.canvasId)
    hackScore = getGrade(module.hack.id, student.canvasId)
    hackAttScore = getGrade(module.hackAttendance.id, student.canvasId)

    r = [readingScore, labScore, labAttScore, hackScore, hackAttScore]
    if None in r:
        print(f"\tNot updating attendance due to missing score")
        return

    attTotal = labAttScore + hackAttScore
    if attTotal < 10:
      subTotal = readingScore + labScore + hackScore
      perc = subTotal / 55.0
      if perc >= .75:
          comment = f"({labAttScore} + {hackAttScore}) / 10 original attendance; threshold met ({subTotal} / 55.0 = {perc*100:.2f}%) full score"
          if commitToCanvas:
              setGrade(module.labAttendance.id, student.canvasId, 5, comment)
              setGrade(module.hackAttendance.id, student.canvasId, 5, comment)
      else:
          comment = f"({labAttScore} + {hackAttScore}) / 10 original attendance; threshold not met ({subTotal} / 55.0 = {perc*100:.2f}%)"
          print(labAttScore)
          print(hackAttScore)
          if commitToCanvas:
              setGrade(module.labAttendance.id, student.canvasId, labAttScore, comment)
              setGrade(module.hackAttendance.id, student.canvasId, hackAttScore, comment)
      print("\t",comment)
    else:
      print(f"\tNo update, score already assigned")

moduleName = f"Module {moduleNumber:.1f}"
module = getModule(moduleName)
print(f"Processing Attendance for {moduleName}...")
print("Assignments:")
print(f"\t{module.reading}")
print(f"\t{module.lab}")
print(f"\t{module.labAttendance}")
print(f"\t{module.hack}")
print(f"\t{module.hackAttendance}")

for (nuid,s) in course.students.items():
    updateAttendance(module, s)
if not commitToCanvas:
    print("Cowardly refused to commit changes to canvas, run with --commit jabroni.")
