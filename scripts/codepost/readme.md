
This is a collection of python scripts used to pull data from
Canvas and interact with codepost.io to assign graders, transfer
grades, etc.

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

## Running

Each script can be run using `python3`; example: `python3 course.py`.
However, only 4 scripts are intended to be run directly:

- `course.py` will load all data from Canvas and UDB and print a
  roster.  It will also print a raw list of email addresses if you
  need them for (say) Piazza or other communication tools.
- `codepostInitRoster.py` - Initializes (or updates) the roster
  in codepost using canvas (enrolled students and TAs) and the
  roles defined in `config.py`
- `codepostValidateCourseInfo.py` - this will list relevant data including
  necessary assignment IDs and roster from codepost and canvas.
- `codepostAssignGraders.py` - a script that (randomly) assigns
  students' assignments to graders...
