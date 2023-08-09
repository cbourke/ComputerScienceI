"""
This script interfaces with canvas and codepost.io to
  1. Consolidate assignment pairs based on pairings in canvas
     -to reduce grading burden and improve consistency
     -we use canvas pairs instead of codepost "partners" as
      codepost's mechanism is clunky (must be done on
      every assignment via sending a URL/hash to partner).
      Codepost also only allows groups of arbitrary size;
      canvas can be limited to groups of 2 (and they can
      join/leave at will)
  2. Assign graders in codepost to the individuals/pairs
     for grading
     -It randomizes grading assignments (evenly distributing
      them among graders) and outputs an assignment report to
      the standard output and produces a CSV file (for QC)

TODO: nearly complete; needs troubleshooting and decision on secondary submissions
"""
import argparse
import codepost
import sys
import pprint
from config import config
from course import course
from codepostUtils import get_assignment_id

parser = argparse.ArgumentParser()
parser.add_argument("--commit", action='store_true', help=
  """Commit the pair consolidation and grader assignments
  to codepost. By default, no action is taken, only a report
  is made.
  """)
parser.add_argument("codepost_assignment_name", help=
  """The codepost.io assignment name (the ID is retrieved
  using this name)
  """)
args = parser.parse_args()

codepost_assignment_name = args.codepost_assignment_name
codepost_assignment_id = get_assignment_id(codepost_assignment_name)
commit_to_codepost = args.commit

if codepost_assignment_id is None:
    print(f"Codepost assignment for '{codepost_assignment_name}' not found", file=sys.stderr)
    exit(1)

def consolidateAndAssign(gradingAssignment):
    """
    Consolidates partners/pairs in codepost based on the
    `grading_group_name` in Canvas (see `config.py`)
    """
    # get all submissions for an assignment directly
    print(f"Consolidating pairs and assigning graders...")
    assignment_submissions = codepost.assignment.list_submissions(id=codepost_assignment_id)
    print(f"    {len(assignment_submissions)} submissions...")
    for grader,groups in gradingAssignment.items():
        for group in groups:
            # get submission associated with first member:
            submission = next( (s for s in assignment_submissions if group.members[0].canvasEmail in s.students), None)
            graderEmail = grader.canvasEmail
            print(f"Processing group:")
            print(f"{group}")
            if submission is None:
                print(f"    No submission!")
            else:
                print(f"    Assigning {graderEmail} to group {group.canvasGroupName}...")
                if len(group) > 1:
                    print(f"    Consolidating {group.members[1].canvasEmail} to {group.members[0].canvasEmail}...")
                if commit_to_codepost:
                    codepost.submission.update(id=submission.id, grader=graderEmail)
                    if len(group) > 1:
                        #TODO: if both have submitted, the second's primary submission
                        #      is switched over but it breaks the admin/grader UI and (at least)
                        #      prevents finalization; we need to delete it to be safe but this
                        #      has HUGE consequences for those who can't follow instructions
                        # delete_submission_id= get second partern's submission id
                        # codepost.submission.delete(id=delete_submission_id)

                        studentGroup = [group.members[0].canvasEmail, group.members[1].canvasEmail]
                        codepost.submission.update(id=submission.id, students=studentGroup)

print(f"Processing codepost assignment '{codepost_assignment_name}' (id={codepost_assignment_id})...")
if not commit_to_codepost:
    print(f"    Coward Mode...");

# Formulate a grading assignment, load from canvas/groups
gradingAssignment = course.getGradingAssignment()
s = course.assignmentToString(gradingAssignment)
print(s)

# dump to CSV for
csv = course.assignmentToCSV(gradingAssignment)
csvFile = f"./{codepost_assignment_name.replace(' ', '_')}_{codepost_assignment_id}.csv"
f = open(csvFile, "w")
f.write(csv)
f.close()

consolidateAndAssign(gradingAssignment)

if not commit_to_codepost:
    print("Cowardly refusing to commit any changes to codepost.io; rerun with --commit when you are braver.")
