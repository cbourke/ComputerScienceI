from canvas import roster
from config import config
import udb
import math
import random

class Course:
    #all persons will be by NUID
    instructorNuids = []
    instructors = {}

    graderNuids = []
    graders = {}
    
    students = {}
    
    #students with no cse login for some reason
    orphans = {}
    
    def __init__(self, instructorNuids = [], graderNuids = []):
        self.instructorNuids = instructorNuids
        self.graderNuids = graderNuids
        # 1. load full roster from canvas
        self.roster = roster
        # 2. get as many cse logins as possible
        # 2a. dump NUIDs to map
        nuids = [p.nuid for p in self.roster]
        nuidsToCseLogins = dict(zip(nuids, [None for x in nuids]))
        # 2b. update
        nuidsToCseLogins = udb.mapNuidsToCseLogins(nuidsToCseLogins,config.nuidToCseLoginPickle)
        # 2c. update roster instances
        for p in self.roster:
            if p.nuid in nuidsToCseLogins and nuidsToCseLogins[p.nuid] is not None:
                p.cseLogin = nuidsToCseLogins[p.nuid]
                
        #3. filter into the appropriate group
        #   This is done manually as the "role" is not available from canvas 
        #   using the canvas API and we want more fine-grained control anyway
        #   - If there is no cse login, they are ignored
        #   - Otherwise, they are either a student XOR instructor/grader
        #     - instructors can be graders
        for p in self.roster:
            if p.cseLogin is None:
                self.orphans[p.nuid] = p
            else:
                if p.nuid in instructorNuids or p.nuid in graderNuids:
                    if p.nuid in instructorNuids: 
                        self.instructors[p.nuid] = p
                    if p.nuid in graderNuids: 
                        self.graders[p.nuid] = p
                else:
                    self.students[p.nuid] = p

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
        return r

    # returns a mapping of graders (Person objects) to
    #  a list of students (Person objects) they are assigned to
    def getAssignment(self):
        graderNuids = list(self.graders.keys())
        studentsNuids = list(self.students.keys())
        random.shuffle(graderNuids)
        random.shuffle(studentsNuids)
        assignment = {}
        #initialize lists 
        for gNuid in graderNuids:
            assignment[self.graders[gNuid]] = []
        i = 0
        for sNuid in studentsNuids:
            g = self.graders[graderNuids[i]]
            assignment[g].append(self.students[sNuid])
            i = (i+1)%len(graderNuids)
        return assignment
        
    def assignmentToString(self,assignment):
        r  = "Assigned Grading\n"
        r += "================\n"
        min = math.floor(len(self.students) / len(self.graders))
        max = math.ceil(len(self.students) / len(self.graders))
        r += "Each grader will grade %d - %d students\n"%(min,max)
        #dump graders to list of Person objects
        graders = list(assignment.keys())
        graders.sort(key=lambda x: x.name)
        for grader in graders:
          students = assignment[grader];
          students.sort(key=lambda x: x.name)
          n = len(students)
          r += "%s (%d assigned)\n"%(grader.name,n)
          for s in students:
            r += "\t"+str(s)+"\n"
        return r

course = Course(instructorNuids=config.instructorNuids, 
           graderNuids=config.graderNuids)

def printCourse():
    print(course)

if __name__ == "__main__":
    printCourse()

