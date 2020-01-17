
This is a collection of python scripts used to pull data from
Canvas, CSE's User Database (UDB) and interact with codepost.io
to assign graders and push submissions to codepost.

# Setup

## Edit the `config.py` file

1. Enter your Canvas API key and course ID:
  - Click your account in the left navigation, then settings
  - Click "New Access Token"
  - Copy that to the `canvasApiKey` variable
  - Copy your Canvas course ID into the `canvasCourseId` variable
    This can be found from the URL for your course, for example
    if your course's URL is https://canvas.unl.edu/courses/12345
    then your course ID is 12345
    
2. Enter your codepost.io API key and course ID:
  - Click on user settings (gear icon, top right)
  - Copy your API token to the `codePostApiKey` variable
  - Copy the relevant Course ID to the `codePostCourseId` variable

3. Enter your CSE UDB credentials
  - Request access from the system administrators for the
    udb database on cse-apps
  - Update the `username` and `password` variables
  
4. Update the `handinDirectory` and `fileExtensions` variables 
appropriately for your course if necessary

5. Update the `instructorNuids` and `graderNuids` lists to
include all relevant NUIDs (as strings).  

## Running

Each script can be run using `python3`; example: `python3 course.py`.
However, only 4 scripts are intended to be run directly:

- `course.py` will load all data from Canvas and UDB and print a 
  roster.  It will also print a raw list of email addresses if you 
  need them for (say) Piazza or other communication tools.
- `codepostInitCourse.py` - a collection of functions to setup 
  assignments, rubrics and roster.  Take care to not run the
  assignment setup more than once or it may result in duplicates.
  The roster can be updated using this same script (RTM).
- `codepostListCourseInfo.py` - this will list relevant data including
  necessary assignment IDs and roster from codepost.
- `codepostAssignGraders.py` - a script that (randomly) assigns 
  students' assignments to graders and pushes files (and the
  assignment) to codepost.  The assignment handin directory name and
  codepost assignment ID are required and provided as command line
  arguments.
  




