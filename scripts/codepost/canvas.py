"""
This is the module loads basic data on the course from canvas including
a full roster (including students, TAs, instructors) and assignment
groups.

"""

from canvasUtils import getRoster
from canvasUtils import getGroups

# {"NUID" => Person}
roster = getRoster()
# [Group]
groups = getGroups(roster)

if __name__ == "__main__":
    for nuid,p in roster.items():
        print(p)
