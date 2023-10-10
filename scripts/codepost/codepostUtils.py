
from config import config
import codepost

codepost.configure_api_key(config.codepost_api_key)

def get_assignment_id(assignment_name):
    """
    Retrieves the codepost id (int) of the given assignment (string)
    """
    codepost_course = codepost.course.retrieve(id=config.codepost_course_id)
    #generator comprehension
    return next( (a.id for a in codepost_course.assignments if a.name == assignment_name), None)

def save_file(path, name, contents):
    file_path = path + "/" + name
    f = open(file_path, "w")
    f.write(contents)
    f.close()
