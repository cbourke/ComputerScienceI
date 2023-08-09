"""
Pulls all data from codepost.io and canvas and gives a
summary report (on codepost.io course info) and reports
any inconsitencies in the roster
"""
import codepost
from course import course
from config import config

codepost.configure_api_key(config.codepost_api_key)

codepost_course = codepost.course.retrieve(id=config.codepost_course_id)

print("Codepost.io Course: ")
print("Id     = " + str(codepost_course.id))
print("Name   = " + codepost_course.name)
print("Period = " + codepost_course.period)

print("Assignments (" + str(len(codepost_course.assignments)) + "): ")
for a in codepost_course.assignments:
  print("%-20s (id=%d)"%(a.name,a.id))

roster = codepost.roster.retrieve(id=config.codepost_course_id)
graders = list()
students = list()

print("Admins (",len(roster.courseAdmins),")")
for a in roster.courseAdmins:
  print("  %s"%a)
  graders.append(a);
print("Graders (",len(roster.graders),")")
for g in roster.graders:
  print("  %s"%g)
  graders.append(g);
graders = list(set(graders))
print("Students (",len(roster.students),")")
for s in roster.students:
  print("  %s"%s)
  students.append(s);

# check that codepost graders are in canvas class
print("Checking Instructors...")
for nuid,instructor in course.instructors.items():
  if instructor.canvasEmail not in graders:
    print("Instructor %s not in codepost"%instructor)
  else:
    graders.remove(instructor.canvasEmail)
if graders:
  print("Instructors in codepost missing in canvas:")
  for g in graders:
    print("  %s"%g)

# check that codepost students are in canvas class
print("Checking Students...")
for nuid,student in course.students.items():
  if student.canvasEmail not in students:
    print("Student %s not in codepost"%student)
  else:
    students.remove(student.canvasEmail)
if student:
  print("Students in codepost missing in canvas:")
  for s in students:
    print("  %s"%s)
