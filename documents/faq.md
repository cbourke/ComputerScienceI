# Frequently Asked Questions
**[School of Computing](https://computing.unl.edu/)**  
**[College of Engineering](https://engineering.unl.edu/)**  
**[University of Nebraska-Lincoln](https://unl.edu)**  
**[University of Nebraska-Omaha](https://http://unomaha.edu/)**  

This is a collection of *frequently asked questions* (FAQ) for
Computer Science I offered through the School of Computing and
the College of Engineering at the University of Nebraska--Lincoln
and Omaha.

# Partner Policy

## What is the partner policy?

For all labs and hacks you may work with one other person as a pair.
No larger groups are allowed because it dilutes the learning experience
too much.  However, having another person to provide new and different
perspectives and to bounce ideas off of is an invaluable learning
experience.

You do have the option of working alone or changing partners throughout
the semester.  No partners are allowed for exams.

## How do I submit with a partner?

In Gradescope, when you submit an assignment there is a **Group Members*
button at the bottom of the page.  Click it and add your partner.

# Canvas Support Management

## Where do I go for help with Canvas?

Canvas is UNL's Learning Management System (LMS).  For more information
see <https://nebraska.edu/services/canvas/student-resources/>

# zyBooks

zyBooks is an online, interactive textbook used for this course.

## How do I get access?

Do ***NOT*** go directly to the zyBooks website.  Instead,
***be sure to go through Canvas***.  Click on **Assignments** and
select the relevant **Module Reading** (or click directly on the assignment
from the main page).  

## How long do readings take?

You can expect each weekly reading to take an *average* of 1 hour.  Early
readings are a bit longer (90 minutes) to get you up-to-speed with the
material while later readings are shorter (30 minutes); keep in mind this
is an *average* and your experience may vary.  Though the lengths vary,
each reading is worth the same number of points.

## I got a zero, what do I do?

Completing the readings through canvas will automatically update your grade.  
You do not need to complete a reading all in one sitting.  Your progress is
saved and you can come back to a reading as many times as you wish.  You
just need to be sure to complete the reading by the due date.  

## Where do I get more info about zyBooks?

For more information involving zyBooks:

* you can read their [Getting Started](https://zybooks.zendesk.com/hc/en-us/articles/360008562913-Students-Getting-started) page
* refer to their [FAQ](https://zybooks.zendesk.com/hc/en-us/categories/360004050694-Students)
* for any other questions, please email [support@zybooks.com](support@zybooks.com)

If you accessed zyBooks directly through the website and not through
canvas, you may need to *merge* the multiple accounts you created.
To do so see this [help page](https://zybooks.zendesk.com/hc/en-us/articles/360007536553-I-already-paid-so-why-am-I-being-asked-to-subscribe-again)

# Gradescope

## What is Gradescope

Gradescope is the autograding system we use for this course.  It is fully
integrated with Canvas.  You submit your source files and automated tests
will run to determine if your code is correct or not.  You can submit and
resubmit as many times as you need up until the due date.

## I'm having trouble

* Mac/Safari, you may need to disable the option to
prevent cross-site tracking: Settings > Uncheck the "Prevent cross-site tracking"
box.

# Campuswire

## What is Campuswire?

Campuswire (https://campuswire.com) is our online forum where you can get help.
You should have received an invite from your instructor, typically to your
`@huskers.unl.edu` email.  All communication including regular announcements
will be posted through this online forum.  Using campuswire you can ask questions
that all students will see or you can post anonymously or privately.  You can
even help your fellow students by answering questions!

## I logged in but I can't get into the class, it is asking for a "class code"

Likely you signed up with the wrong email.  You should have been sent an invite
email, typically through your `@huskers.unl.edu` email address.  Be sure to
use whatever email your invite was sent to.

# Grading

## How and when are readings graded?

See the section on zyBooks.  Readings are automatically graded and your
grade in Canvas is automatically updated as you work through the reading.
After the due date, you still have access to the reading and can complete
any section that is not yet completed, but the grade will no longer update
or sync to Canvas.

## How and when are labs graded?

Labs are due at midnight on Tuesdays.  We run batch scripts to grade them
as soon as possible on Wednesdays.  When we are done, grades
are posted to Canvas and a brief retrospective is posted to the course
message board.

## How and when are hacks graded?

Hacks are due (generally) Mondays at midnight. Learning Assistants have
48 business hours to grade them and then Course Leaders take another 48
hours to check the grading process to ensure consistency.  Grades are
released in Canvas with our feedback (generally) on Friday
afternoons.  A retrospective is then posted to the course message board.

## How and when is attendance graded?

Learning Assistants take attendance in lab/hack.  Attendance scores in
Canvas are updated at the end of the week.  If you did not attend lab
and/or hack you may see a 0 or other grade.  This grade may be updated
when the rest of the module points have been graded as per the attendance
policy in the syllabus.

# CS 50 IDE

This course uses the CS50 IDE available at <https://cs50.dev/>.  This is
a [codespaces](https://github.com/features/codespaces) instance provided and supported
by Harvard's CS50 program.  If you encounter problems, the easy things to
try first are:

* Rebooting
* Doing a hard refresh of your browser
* Logging out/in or using a different browser (temporarily) or using
  privacy mode to ensure a fresh login

## The Rubber Duck Debugger is not working

If the integrated Rubber Duck Debugger is not working, you can access it directly
at <https://cs50.ai>

## I'm getting a Bad Gateway message

* Try accessing your IDE through this link: http://github.com/codespaces

##  My workspace is in recovery mode. What should I do?

In the terminal, type

`touch /workspaces/$RepositoryName/.devcontainer.json`

This will trigger a container rebuild and usually that will fix the issue.

If the issue persists, you can try the following (see full details
[here](https://github.com/orgs/community/discussions/45718)):

  1. Press Cmd + Shift + P (Mac) or Ctrl + Shift + P (Windows) to open
     the Command Palette.  You can also find this in the Settings menu
     (click on the Settings icon in the lower left of your window).
  2. Type "rebuild" in the search bar.
  3. Click on "Codespaces: Rebuild Container"

## I'm having a different problem

You can:

* Check to see if CS50 is experiencing system-wide issues which are reported at https://cs50.statuspage.io/
* Try going to <https://cs50.dev/restart> to restart your codespaces instance
* Emailing their system administration support at sysadmins@cs50.harvard.edu
* Try asking your question on the CS50 discord: https://discord.gg/cs50

## Nothing Seems to Work

1. Try clearing your browser cache/cookies; instructions for most major browsers: https://its.uiowa.edu/support/article/719
2. Try a different browser entirely.
3. Try the alternatives below.

## Alternatives

If you are still having problems with the IDE or would like to consider backups/alternatives:

* You can download the docker instance and work offline (see https://cs50.readthedocs.io/code/
  and then https://cs50.readthedocs.io/code/#using-vs-code-locally ); the CS50
  folks have posted videos:
  * Windows: https://www.youtube.com/watch?v=9yzQCgIdL-Y
  * Mac: https://www.youtube.com/watch?v=TZ6c7y8N64k

* You can install VS Code on your own computer: https://code.visualstudio.com/download
  * Windows users will require MinGW, here's a full tutorial: https://code.visualstudio.com/docs/cpp/config-mingw
