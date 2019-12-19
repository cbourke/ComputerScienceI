import codepost
from config import config
from course import course

codepost.configure_api_key(config.codePostApiKey)

numHacks = 14
pointsPerHack = 25
#points per category must be integers
hackRubricCategories = [('Style', 2), ('Documentation', 2), ('Design', 5), ('Correctness', 16)]
assignRubricCategories = [('Style', 4), ('Documentation', 4), ('Design', 10), ('Correctness', 32)]
hackRubricCategoriesComments = {
  'Style': [
            ('Significant improper or inconsistent use of whitespace', 1),
            ('Significant improper identifier naming or inconsistent naming conventions', 1)
            ],
  'Documentation': [
            ('Missing header documentation', 1),
            ('Substantial blocks (functions, complex code) are not properly documented', 1),
            ('Overly verbose or useless comments', 1)
            ],
  'Design': [
            ('Compiler warnings have not been addressed', 1),
            ('Dead or extraneous code remains', 1),
            ('Insufficient error handling regardless of webgrader behavior', 1),
            ('Extraneous or unnecessary output (debugging or error statements)', 1),
            ('Redundant code', 1),
            ('Improper or incorrect patterns, variable types, etc.', 1),
            ('Contains obvious memory leaks or misuse of data types', 1)            
            ],
  'Correctness': [
            ('Output is not reasonably readable', 1),
            ('Output does not report as much information as expected', 1)
            ],
}


numAssignments = 5
pointsPerAssignment = 50

def addRubric(assignmentId, categories, categoryComments):
    for i,(name,points) in enumerate(categories):
        my_rubric_category = codepost.rubric_category.create(
          assignment=assignmentId,
          name=name,
          pointLimit=points,
          sortKey=i)
        for j,(text,pointDelta) in enumerate(categoryComments[name]):
            my_rubric_comment = codepost.rubric_comment.create(
              text=text,
              pointDelta=pointDelta,
              category=my_rubric_category.id,
              sortKey=j)

def initHacks():
  for i in range(1, numHacks+1):
    name = "Hack %.1f"%(i)
    h = codepost.assignment.create(
      name=name,
      points=pointsPerHack,
      course=config.codePostCourseId,
      sortKey=(i+100))
    addRubric(h.id, hackRubricCategories, hackRubricCategoriesComments)
    print("%s created with ID = %d"%(name,h.id))

def initAssign():  
  for i in range(1, numAssignments+1):
    name = "Assignment %.1f"%(i)
    h = codepost.assignment.create(
      name=name,
      points=pointsPerAssignment,
      course=config.codePostCourseId,
      sortKey=i)
    addRubric(h.id, assignRubricCategories, hackRubricCategoriesComments)
    print("%s created with ID = %d"%(name,h.id))

def initAssignments():
  initHacks()
  initAssign()
  h = codepost.assignment.create(
    name="Midterm",
    points=100,
    course=config.codePostCourseId)
  addRubric(h.id, hackRubricCategories, hackRubricCategoriesComments)
  print("%s created with ID = %d"%(h.name,h.id))
  h = codepost.assignment.create(
    name="Final",
    points=150,
    course=config.codePostCourseId)
  addRubric(h.id, hackRubricCategories, hackRubricCategoriesComments)
  print("%s created with ID = %d"%(h.name,h.id))
  
# graders and students are only valid if they have cse logins
# alternatively, we could use the email address from Canvas but
# students may have opted out of sharing this and it would not
# be available from the API.  

def updateRoster():
    graderEmails = []
    studentEmails = []
    instructorEmails = []

    for nuid,instructor in course.instructors.items():
        if instructor.canvasEmail:
            instructorEmails.append(instructor.canvasEmail)
        else:
            print("WARNING, instructor %s has no cse login/email"%instructor)

    for nuid,grader in course.graders.items():
        if grader.canvasEmail:
            graderEmails.append(grader.canvasEmail)
        else:
            print("WARNING, grader %s has no cse login/email"%grader)

    for nuid,student in course.students.items():
        if student.canvasEmail:
            studentEmails.append(student.canvasEmail)
        else:
            print("WARNING, student %s has no cse login/email"%student)

    codepost.roster.update(
      id=config.codePostCourseId,
      students=studentEmails,
      graders=graderEmails,
      superGraders=graderEmails,
      courseAdmins=instructorEmails)

#initAssignments()
updateRoster()
