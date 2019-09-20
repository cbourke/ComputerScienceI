from config import config
from canvas_api_client.v1_client import CanvasAPIv1
from person import Person
import sys

# create an instance of the canvas API
# using the configuration in config.py
# 
# for reference:
#  - UNL's Canvas API instance is at:
#    https://canvas.unl.edu/api/v1/
#  - UNL's Live instance:
#    https://canvas.unl.edu/doc/api/live
#  - The CanvasAPIv1 (canvas-api-client) documentation:
#    https://wgwz.github.io/canvas-lms-tools/canvas_api_client.html#module-canvas_api_client.v1_client
#
#  The python API wrapper seems very limited.  In particular
#  there is no apparent way to get the role of a user.  The
#  typical response (ex: 
#   https://canvas.unl.edu/api/v1/courses/COURSEID/enrollments?access_token=TOKEN&per_page=100
#  includes all this important information, but the get_course_users 
#  does not; we'll have to manually handle the roles (grader, instructor, etc.)
#  which might be better anyway
api = CanvasAPIv1(config.canvasUrl, config.canvasApiKey)

pages = api.get_course_users(config.canvasCourseId)
# the API lazy loads elements and uses pagination, 
# so a double iteration is necessary.
roster = []
for page in pages:
    for u in page:
        try: 
            # these two may not exist if the user
            # has not consented 
            canvasLogin = None
            canvasEmail = None
            if 'login_id' in u:
                canvasLogin = u['login_id']
            else:
                print("ERROR: no login_id for user")
                print(u)
                sys.exit(1)
            if 'email' in u:
                canvasEmail = u['email']
            else:
                print("ERROR: no email for user")
                print(u)
                sys.exit(1)
            p = Person(
              nuid        = u['sis_user_id'],
              canvasId    = u['id'],
              name        = u['sortable_name'], #last, first
              canvasLogin = canvasLogin,
              canvasEmail = canvasEmail
            )
            roster.append(p)
        except:
            print("Problem with record:")
            print(u)
            e = sys.exc_info()[0]
            write_to_page( "<p>Error: %s</p>" % e )


#ex:    
#{
#	'id': 19617,
#	'name': 'Christopher Bourke',
#	'created_at': '2015-08-19T13:47:56-05:00',
#	'sortable_name': 'Bourke, Christopher',
#	'short_name': 'Christopher Bourke',
#	'sis_user_id': '35140602',
#	'integration_id': None,
#	'login_id': 'cbourke3',
#	'email': 'cbourke@cse.unl.edu'
#}
