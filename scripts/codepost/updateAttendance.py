"""
This script is intended for use in CSCE 155E to facilitate its differential
lab/hack attendance policy.  Students are required to attend and if they do
they earn attendance points (which are manually entered into the canvas
gradebook).  However, high-performing students that do not attend can still
earn the points provided they meet a certain threshold of points for the
rest of the module.

This script interfaces with UNL' Canvas instance to update the attendance
points according to this policy.

TODO: troubleshoot with actual course

 NOTE: only run this for modules with all 5 items since 55 points are hard-coded
"""

from config import config
from course import course
from assignment import Assignment
from canvasUtils import getAssignments
from canvasUtils import getGrade
from canvasUtils import setGrade

import argparse
import requests
from types import SimpleNamespace

import pprint

parser = argparse.ArgumentParser()
parser.add_argument("moduleName", help=
  """The (partial) module name in canvas to update attendance scores.
  Examples: " 1.0" or "12.0" or "Strings"
  """)
parser.add_argument("--commit", action='store_true', help=
  """Commmits the changes to the gradebook.  If this is not
  provided, the script will run in coward mode and not make
  any modifications, only reporting what would have been done.
  """)
args = parser.parse_args()

moduleName = args.moduleName
commitToCanvas = args.commit

def getModule(moduleName):
  """
  Returns a "module" representation of a CS1 module in canvas (reading, lab,
  hack and attendance) for the module with the given moduleName
  """

  assignments = getAssignments(moduleName)
  pprint.pprint(assignments)

  result = SimpleNamespace()
  result.reading = next(filter(lambda x: 'Reading' in x.name, assignments), None)
  result.lab = next(filter(lambda x: 'Lab' in x.name and 'Attendance' not in x.name, assignments), None)
  result.hack = next(filter(lambda x: 'Hack' in x.name and 'Attendance' not in x.name, assignments), None)
  result.attendance = next(filter(lambda x: 'Module' in x.name and 'Reading' not in x.name, assignments), None)

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
    hackScore = getGrade(module.hack.id, student.canvasId)
    attendScore = getGrade(module.attendance.id, student.canvasId)

    r = [readingScore, labScore, hackScore, attendScore]
    if None in r:
        print(f"\tNot updating attendance due to missing score")
        return

    comment = f"Original attendance score: {attendScore}/10.  "

    if attendScore < 10:
        subTotal = readingScore + labScore + hackScore
        percent = subTotal / 55.0
        if percent >= .75:
            comment += f"75% threshold met ({subTotal:.2f} / 55.0 = {percent*100:.2f}%).  Attenance points awarded."
            attendScore = 10
        else:
            comment += f"75% threshold NOT met ({subTotal:.2f} / 55.0 = {percent*100:.2f}%)."

    print("\t",comment)

    if commitToCanvas:
        setGrade(module.attendance.id, student.canvasId, attendScore, comment)

module = getModule(moduleName)
print(f"Processing Attendance for {moduleName}...")
print("Assignments:")
print(f"  Reading: {module.reading}")
print(f"  Lab:     {module.lab}")
print(f"  Hack:    {module.hack}")
print(f"  Attend:  {module.attendance}")

a = input("Proceed? Y/N")

if a != "Y":
    print("Cowardly exiting...")
    exit(1)

for (nuid,s) in course.students.items():
    updateAttendance(module, s)
if not commitToCanvas:
    print("Cowardly refused to commit changes to canvas, run with --commit jabroni.")
