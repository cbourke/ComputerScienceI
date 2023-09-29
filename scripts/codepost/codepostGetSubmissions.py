"""
This script interfaces with codepost.io to pull and archive
all submissions (files) from a particular assignment.  It
stores the files in a directory (assignment name)/subdirectory
(student name(s)) structure.


TODO: push to repo
"""
import argparse
import codepost
import sys
import os
import pprint
from config import config
from codepostUtils import get_assignment_id

parser = argparse.ArgumentParser()

parser.add_argument("codepost_assignment_name", help=
  """The codepost.io assignment name (the ID is retrieved
  using this name; example: "Hack 1.0")
  """)
args = parser.parse_args()
codepost_assignment_name = args.codepost_assignment_name

codepost_assignment_id = get_assignment_id(codepost_assignment_name)
if codepost_assignment_id is None:
    print(f"No assignment \"{codepost_assignment_name}\" found.")
    exit(1)

assignment = codepost.assignment.retrieve(id=codepost_assignment_id)


print(f"Retrieving assignment \"{codepost_assignment_name}\" ({codepost_assignment_id})...")

base_dir_name = f"{codepost_assignment_name.replace(' ', '_')}_{codepost_assignment_id}"
print(f"  Creating {base_dir_name}...")
if not os.path.isdir(base_dir_name):
    os.makedirs(base_dir_name)

submissions = assignment.list_submissions()

for submission in submissions:
    stripped = [student[:student.find('@')] for student in submission.students]
    sub_dir_name = "_".join(stripped)
    #create subdir
    dir_name=base_dir_name+"/"+sub_dir_name
    print(f"  Creating {dir_name}...")
    if not os.path.isdir(dir_name):
        os.makedirs(dir_name)
    for file in submission.files:
        file_name = file.name
        file_contents = file.code.encode('utf-8').decode('ascii','ignore')
        file_path = dir_name + "/" + file_name
        f = open(file_path, "w")
        f.write(file_contents)
        f.close()
