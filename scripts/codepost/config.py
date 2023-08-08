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

    # To use canvas groups for assigning grading, set the name
    # of the group here.
    gradingGroupName = "Hack Pairs"

    # codepost.io configuration
    codePostApiKey = ""
    codePostCourseId = None
    
    # Course-specific role configurations
    #  - Instructors are given codepost admin access, but not assigned to grade
    #  - Graders are given "super grader" access to codepost and assigned to
    #    grade.  An instructor must also be a grader if you want them to be
    #    assigned grading duties.
    instructorNuids = ["35140602", # Bourke
                      ]
    # All graders' NUIDs
    graderNuids = ["35140602", # Bourke
                  ]

config = Config()
