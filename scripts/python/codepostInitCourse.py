import codepost
from config import config
from course import course

codepost.configure_api_key(config.codePostApiKey)

initAssignments = False
numHacks = 14
pointsPerHack = 25
numAssignments = 5
pointsPerAssignment = 50

def initHacks():
  for i in range(1, numHacks+1):
    name = "Hack %.1f"%(i)
    h = codepost.assignment.create(
      name=name,
      points=pointsPerHack,
      course=config.codePostCourseId)
    print("%s created with ID = %d"%(name,h.id))

def initAssign():  
  for i in range(1, numAssignments+1):
    name = "Assignment %.1f"%(i)
    h = codepost.assignment.create(
      name=name,
      points=pointsPerAssignment,
      course=config.codePostCourseId)
    print("%s created with ID = %d"%(name,h.id))

if initAssignments:
  initHacks()
  initAssign()
  h = codepost.assignment.create(
    name="Midterm",
    points=100,
    course=config.codePostCourseId)
  print("%s created with ID = %d"%(h.name,h.id))
  h = codepost.assignment.create(
    name="Final",
    points=150,
    course=config.codePostCourseId)
  print("%s created with ID = %d"%(h.name,h.id))
  
# graders and students are only valid if they have cse logins
# alternatively, we could use the email address from Canvas but
# students may have opted out of sharing this and it would not
# be available from the API.  

graderCSEEmails = []
studentCSEEmails = []

for nuid,grader in course.graders.items():
    if grader.cseEmail:
        graderCSEEmails.append(grader.cseEmail)
    else:
        print("WARNING, grader %s has no cse login/email"%grader)

for nuid,student in course.students.items():
    if student.cseEmail:
        studentCSEEmails.append(student.cseEmail)
    else:
        print("WARNING, student %s has no cse login/email"%student)

codepost.roster.update(
  id=config.codePostCourseId,
  students=studentCSEEmails,
  graders=graderCSEEmails)

