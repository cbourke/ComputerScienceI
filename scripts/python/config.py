
class Config:
    
    # Canvas API configuration
    canvasUrl      = "https://canvas.unl.edu/api/v1/"
    canvasApiKey   = None
    canvasCourseId = None
    
    # codepost.io configuration
    codePostApiKey = None
    codePostCourseId = None
    
    # file extensions/types to include in codepost push
    # leave empty to include all files
    fileExtensions = []
        
    # CSE User Database configuration (udb on cse-apps)
    nuidToCseLoginPickle = "nuidToCseLogin.pkl"
    class udb:
        driver   = "libmaodbc"
        host     = "cse-apps.unl.edu"
        database = "udb"
        username = None
        password = None

    # Course-specific role configuration
    # Lists of instructor NUIDs and grader NUIDs (as strings)
    instructorNuids = []
    
    graderNuids = []

config = Config()
