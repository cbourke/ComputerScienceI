"""
This script interfaces with canvas and codepost.io
to transfer grades of any assignment from codepost.io
into the canvas gradebook.

This is intended to be run once after the conclusion of
the grading of an assignment.  It will only ever update
grades in Canvas if the canvas grade is missing (*and*
the --commit option has been provided; otherwise a
report of potential actions will be produced).  If
grades need to be changed after this run, it should be
done manually.

TODO: this script is complete, but needs troubleshooting

"""
from config import config
from course import course
from codepostUtils import get_assignment_id
from canvasUtils import getAssignments
from canvasUtils import getGrade
from canvasUtils import setGrade
import argparse
import codepost
import pprint
import sys

parser = argparse.ArgumentParser()
parser.add_argument("assignment_name", help=
  """The codePost assignment id to pull scores FROM
  """)
parser.add_argument("--commit", action='store_true', help=
  """Commmits the changes to the gradebook.  If this is not
  provided, the script will run in coward mode and not make
  any modifications, only reporting what would have been done.
  """)
args = parser.parse_args()

codepost.configure_api_key(config.codepost_api_key)

# alternative:
# codepost_assignment_id = codepostUtils.get_assignment_id(assignment_name)
assignment_name = args.assignment_name
codepost_assignment_id = get_assignment_id(assignment_name)
if codepost_assignment_id is None:
    print(f"Codepost assignment for '{assignment_name}' not found", file=sys.stderr)
    exit(1)
canvas_assignments = getAssignments(name=assignment_name)
if not canvas_assignments:
    print(f"Canvas assignment for '{assignment_name}' not found", file=sys.stderr)
    exit(1)
elif len(canvas_assignments) > 1:
    print(f"Multiple Canvas assignments for '{assignment_name}' found!", file=sys.stderr)
    exit(1)
canvas_assignment = canvas_assignments[0]
canvas_assignment_id = canvas_assignment.id
commit_to_canvas = args.commit

print(f"Processing assignment '{assignment_name}' (codepost id={codepost_assignment_id}) to (canvas id={canvas_assignment_id})...")
if not commit_to_canvas:
    print(f"\t(Coward mode)")

# 1. Request the submissions for an assignment directly
assignment_submissions = codepost.assignment.list_submissions(id=codepost_assignment_id)

# email (codepost) -> (codepostScore)
# non-finalized submissions will have a None value
# no submits will not have a key
codepost_grades = {}

for submission in assignment_submissions:
    submission_id = submission.id
    students = submission.students
    # only the actual submission contains the grade
    the_submission = codepost.submission.retrieve(id=submission_id)
    #grade is only defined if it is finalized, otherwise it is None
    #despite the API docs, it is a float!!
    if not the_submission.isFinalized:
        print(f"WARNING Submission {students} not finalized!")
    grade = the_submission.grade
    for student in students:
        codepost_grades[student] = grade

# for each student in roster:
#   retrieve canvas grade
#   report
for nuid,p in course.students.items():
    codepost_grade = None if p.canvasEmail not in codepost_grades else codepost_grades[p.canvasEmail]
    canvas_grade = getGrade(canvas_assignment_id, p.canvasId)
    print(f"{p}:")
    print(f"    codepost: {codepost_grade}")
    print(f"    canvas:   {canvas_grade}")
    message = None
    if canvas_grade is not None:
        print(f"    Skipping, Canvas grade exists...")
    else:
        # change canvas grade...
        if codepost_grade is None:
            log = f"    Updating Canvas grade to 0, No Submission..."
            score = 0
            comment = "No Submission"
        else:
            log = f"    Updating Canvas grade to {codepost_grade}..."
            score = codepost_grade;
            comment = None
        print(log)
        if commit_to_canvas:
            setGrade(canvas_assignment_id, p.canvasId, score, comment)

#pprint.pprint(codepost_grades)
if not commit_to_canvas:
  print("Cowardly refusing to commit grades to canvas; rerun with --commit if you wanna.")
