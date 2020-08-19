"""
Master configuration file for all scripts.  

This configuration file will contain sensitive information
(NUIDs, passwords) and should *not* be tracked or committed
to a remote repository (even a private one).  If changes
do need to be made, sensitive information should be removed
before hand.  

To help avoid committing sensitive information, you should
set this file to be untracked: 
   git update-index --assume-unchanged config.py
To track the file again you can use:
   git update-index --no-assume-unchanged config.py

"""
class Config:
    
    # Canvas API configuration
    canvasUrl      = "https://canvas.unl.edu/api/v1/"
    canvasApiKey   = ""
    canvasCourseId = ""

    # codepost.io configuration
    codePostApiKey = ""
    codePostCourseId = None
    
    # CSE User Database configuration (udb on cse-apps)
    # cse-apps.unl.edu is firewalled for 3306 except from 
    # cse/csce
    #  - The pickle file is used to locally store database information
    #    so that it doesn't have to requery for every script execution 
    #  - Credentials must be obtained from CSE System Administration
    nuidToCseLoginPickle = "nuidToCseLogin.pkl"
    class udb:
        driver   = "libmaodbc"
        host     = "cse-apps.unl.edu"
        database = "udb"
        username = ""
        password = ""

    # handin directory on the CSE file server 
    handinDirectory = "/home/grad/Classes/cse155e/handin/"
    # file extensions/types to include in codepost push
    # leave empty to include all files
    fileExtensions = [".c", ".h", ".md"]
    
    # To use canvas groups for assigning grading, set the name 
    # of the group here.  
    gradingGroupName = None
    
    # Course role configuration
    # All instructors' NUID should be listed even if 
    # they are not graders or they will be assumed to be students
    # Instructors who are not graders will not be assigned students
    # to grade.
    # 
    # NUIDs are strings as they can begin with leading zeros.
    instructorNuids = []
                       
    # All graders' NUIDs
    graderNuids = []
    
config = Config()
