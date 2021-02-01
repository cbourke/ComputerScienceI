"""
A class and module to support an entire course.  A
course is connected to both a Canvas course as well
as a CSE course account.

This module loads data from the Canvas course using 
its API (see canvas.py) and then interfaces with the
CSE User Database (see udb.py) to connect users with
their CSE logins.

Using the configuration module (see config.py), users
are separated according to instructors (non-graders),
graders, and students.  If a user cannot be connected
to a CSE login, they are separated into an "orphan"
group.

The Course class itself maintains these groups both
as lists of NUIDs (strings) and maps of NUID => Person (object).

When used as an executable file, all course data is 
loaded and printed to the standard output.  Otherwise, 
a global object (course) is made available.  

In addition to the course data, two functions provide
functionality to randomly create a grading assignment 
(see getAssignment() and assignmentToString()).
"""

from config import config
from canvas import roster
from canvas import groups
from group import Group
import udb
import copy
import math
import random

class Course:
    #all persons will be by NUID
    instructorNuids = []
    instructors = {}

    graderNuids = []
    graders = {}
    
    students = {}
    groups = []
    
    #students with no cse login for some reason
    orphans = {}
    
    def __init__(self, instructorNuids = [], graderNuids = []):
        self.instructorNuids = instructorNuids
        self.graderNuids = graderNuids
        # 1. load full roster from canvas
        # {NUID => Person}
        self.roster = roster
        # 2. get as many cse logins as possible
        # 2a. dump NUIDs to map
        nuids = self.roster.keys()
        nuidsToCseLogins = dict(zip(nuids, [None for x in nuids]))
        # 2b. update from UDB
        nuidsToCseLogins = udb.mapNuidsToCseLogins(nuidsToCseLogins,config.nuidToCseLoginPickle)
        # 2c. update cse logins for all roster instances
        for nuid,p in self.roster.items():
          if nuid in nuidsToCseLogins and nuidsToCseLogins[nuid] is not None:
            p.cseLogin = nuidsToCseLogins[nuid]
                
        #3. filter into the appropriate group
        #   This is done manually as the "role" is not available from canvas 
        #   using the canvas API and we want more fine-grained control anyway
        #   - If there is no cse login, they are "orphaned"
        #   - Otherwise, they are either a student XOR instructor/grader
        #     - instructors can be graders
        for nuid,p in self.roster.items():
            if p.cseLogin is None:
                self.orphans[nuid] = p
            else:
                if nuid in instructorNuids or nuid in graderNuids:
                    if nuid in instructorNuids: 
                        self.instructors[nuid] = p
                    if nuid in graderNuids: 
                        self.graders[nuid] = p
                else:
                    self.students[nuid] = p
        # update groups to exclude instructors and graders [Group]
        self.groups = []
        # for each group in canvas.groups:
        for g in groups:
          # if the group leader (first listed) is a student, then add them
          if g.members[0].nuid in self.students:
            self.groups.append(g)

    def __str__(self):
        r = "Instructors (%d): \n"%(len(self.instructors))
        for nuid,p in self.instructors.items():
            r += str(p) + "\n"
        r += "Graders (%d): \n"%(len(self.graders))
        for nuid,p in self.graders.items():
            r += str(p) + "\n"
        r += "Students (%d): \n"%(len(self.students))
        for nuid,p in self.students.items():
            r += str(p) + "\n"
        r += "Orphans (%d): \n"%(len(self.orphans))
        for nuid,p in self.orphans.items():
            r += str(p) + "\n"
        r += "Groups: \n"
        for g in self.groups:
            r += str(g)
        r += "CSV Data:\n"
        r += "nuid,name,canvasId,canvasEmail,canvasLogin,cseLogin\n"
        for nuid,p in self.students.items():
            r += p.toCsv()
        return r

    def getGradingAssignment(self):
        """
        Returns a randomized mapping of graders (Person objects) 
        to a list of students (Group objects) they are assigned 
        to grade.
        
        Assignments are made in a round-robin manner so that the 
        same grader(s) are not always assigned more (or fewer) to
        grade.
        """
        graderNuids = list(self.graders.keys())
        groups = copy.deepcopy(self.groups)
        random.shuffle(graderNuids)
        random.shuffle(groups)
        assignment = {}
        #initialize lists 
        for gNuid in graderNuids:
            assignment[self.graders[gNuid]] = []
        i = 0        
        n = len(graderNuids)
        for group in groups:
            g = self.graders[graderNuids[i]]
            assignment[g].append(group)
            i = (i+1)%n
        return assignment

    def assignmentToString(self,assignment):
        """
        Given an assignment (a mapping of Person objects to a
        list of Person objects) as generated by getAssignment(), 
        this function will create a human-readable string of the
        grading assignments.  For convenience, the printed string
        is in order of name for both graders and students
        """
        r  = "Assigned Grading\n"
        r += "================\n"
        min = math.floor(len(self.groups) / len(self.graders))
        max = math.ceil(len(self.groups) / len(self.graders))
        r += "Each grader will grade %d - %d groups\n"%(min,max)
        #dump graders to list of Person objects
        graders = list(assignment.keys())
        graders.sort(key=lambda x: x.name)
        for grader in graders:
          groups = assignment[grader]
          groups.sort(key=lambda x: x.members[0].name)
          n = len(groups)
          r += "%s (%d assigned)\n"%(grader.name,n)
          for g in groups:
            r += str(g)
        return r

    def assignmentToCSV(self,assignment):
        r = ""
        graders = list(assignment.keys())
        graders.sort(key=lambda x: x.name)
        for grader in graders:
            groups = assignment[grader]
            groups.sort(key=lambda x: x.members[0].name)
            nameTokens = grader.name.split(",")
            graderLast = nameTokens[0].strip()
            graderFirst = nameTokens[1].strip()
            for g in groups:
                nameTokens = g.members[0].name.split(",")
                studentLast = nameTokens[0].strip()
                studentFirst = nameTokens[1].strip()
                r += "%s,%s,%s,%s,%s,%s,%s,%s\n"%(grader.nuid,graderLast,graderFirst,g.members[0].nuid,studentLast,studentFirst,g.members[0].cseLogin,g.members[0].canvasEmail)
        return r

course = Course(instructorNuids=config.instructorNuids, 
                graderNuids=config.graderNuids)
"""
The course object for this module initialized with with
the course data defined in config.py
"""

def printCourse():
    print(course)

if __name__ == "__main__":
    printCourse()
