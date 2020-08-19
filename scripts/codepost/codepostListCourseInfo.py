# This script simply lists some relevant information
# associated with your codepost.io course
import codepost
from config import config
 
codepost.configure_api_key(config.codePostApiKey)

course = codepost.course.retrieve(id=config.codePostCourseId)

print("Retrieved course: ")
print("Id     = " + str(course.id))
print("Name   = " + course.name)
print("Period = " + course.period)

print("Assignments (" + str(len(course.assignments)) + "): ")
for a in course.assignments:
  print("%s (id=%d)"%(a.name,a.id))

roster = codepost.roster.retrieve(id=config.codePostCourseId)
print("Graders")
for g in roster.graders:
  print("  %s"%g)
print("Students")
for s in roster.students:
  print("  %s"%s)
