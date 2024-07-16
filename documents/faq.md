
# Frequently Asked Questions
**[School of Computing](https://computing.unl.edu/)**  
**[College of Engineering](https://engineering.unl.edu/)**  
**[University of Nebraska-Lincoln](https://unl.edu)**  
**[University of Nebraska-Omaha](https://http://unomaha.edu/)**  

This is a collection of *frequently asked questions* (FAQ) for
Computer Science I offered through the School of Computing and
the College of Engineering at the University of Nebraska--Lincoln
and Omaha.

# Canvas Support Management

## Where do I go for help with Canvas?

Canvas is UNL's Learning Management System (LMS).  For more information
see <https://services.unl.edu/service/learning-management-system-lms-canvas-unl>

# zyBooks

zyBooks is an online, interactive textbook used for this course.

## How do I get access?

To get access, you should:

1. Visit your campus book store:
 * UNL: https://www.bkstr.com/Nebraska-lincolnstore/home
 * UNO: (see below)
2. Do ***NOT*** go directly to the zyBooks website.  Instead,
***be sure to go through Canvas***.  Click on **Assignments** and
select the relevant **Module Reading**

## I'm at UNO, how do I get zyBooks?

For those taking the UNO offering of this course, zyBooks should be included
through UNO's First Day Access Program which allows you to access the materials
directly through Canvas on the first day of class.  ***You do not need to purchase
any materials prior to starting class.***  The cost of the electronic textbook
will be billed to your student account approximately 3 weeks after the start
of classes. You will have the option to opt out of the First Day Access
Program and purchase the electronic text elsewhere, but doing so will likely
result in a greater cost.

The link below has term specific opt out dates listed, these will also be
listed in their email
https://www.unobookstore.com/first_day_access_faq.asp

You should receive an email through your UNO account with a code you
can use to get access.  To use the code, click on any reading assignment
in Canvas and when prompted, enter your code.

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
To do so see https://zybooks.zendesk.com/hc/en-us/articles/360007536553-I-already-paid-so-why-am-I-being-asked-to-subscribe-again-

# codePost.io

## What is codePost?

codePost is a website that you submit your code through for us to grade it.  Much
of the grading is automated.  When you submit your code several tests are
run and you are presented with the results.  Later, graders will take a look
at your code and grade aspects that are not automated.  Graders will also
provide additional detailed line-by-line feedback.  

## How do I get access?

You can access codePost at <https://codepost.io>.  Your instructor
will send you an invite email.  Be sure to check your spam
folder and respond ASAP; the links expire after a few days.

## I didn't get the invite or it expired, what do I do?

Try going to https://codepost.io/forgot-password and resetting your password
(even if you never initially set one).  Be sure to use your **huskers email**
(example: `jstudent42@huskers.unl.edu`) or whatever primary email is
associated with your canvas profile.

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
released in Canvas with comments posted to codePost (generally) on Friday
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
