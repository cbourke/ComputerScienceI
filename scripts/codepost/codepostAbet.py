"""
This script interfaces with the codepost.io API to produce exemplar reports
for ABET accreditation.


For a particular assignment, a report includes an assignment summary
(basic info and stats) as well as the full assessment of 3 student
examples of an A, B, and C submission.  The report includes all line-by-line
grader comments (and point deductions) as well as source files.  Source files
are formatted in markdown.  In the codepost.io web client the comments would
be embedded directly in the source files but for this report they are collected
in the summary.

By default, A, B, and C examples are automatically chosen from all graded submissions.
The top submission is chosen for the A example while the B/C are chosen
to be the closest to a 85%/75% score based on the total number of points of
the assignment.  You can specify which A-B-C student samples to pull by
providing a list of emails.

The report is written to both a markdown-formatted output file as well as
a PDF version (which is produced from the markdown using pandoc/latex via
a system call so these are expected to be installed and available).

You can run this script in one of two modes: you can provide either a single
assignment ID which will produce a single report for that assignment only, or
you can provide a course ID which will produce (separate) reports for all
assignments in the course.  In either case, the IDs must be valid codepost.io
IDs.  Optionally, you can provide your own codepost API key via the command
line, otherwise it must be specified in the config.py file.

"""

import argparse
import os
import codepost
from config import config

parser = argparse.ArgumentParser(description=__doc__,
  formatter_class=argparse.RawDescriptionHelpFormatter)
parser.add_argument('--codePostApiKey',
                    type=str,
                    default=config.codePostApiKey,
                    help='Optionally provide a codepost API key to use. By default the API key in the config.py file is used.')
parser.add_argument('--emails',
                    nargs=3,
                    metavar=('email (A) email (B) email (C)'),
                    default=None,
                    help='Optionally provide three student emails that should be used as A, B, C samples respectively.')

group = parser.add_mutually_exclusive_group(required=True)
group.add_argument('--codePostCourseId',
                   type=int,
                   help='Generates ABET reports for *every* assignment in the provided codepost course.')
group.add_argument('--codePostAssignmentId',
                   type=int,
                   help='Generates a single ABET report for the provided codepost assignment.')

args = parser.parse_args()

def submissionToMarkdown(submission,title,assignmentPts):
  """
  Returns both a summary and source files of the provided submission as
  markdown-formatted strings.
  """
  if not submission:
      return "INVALID"
  details = ""
  result = f"""
## {title} Example
  * Student(s): {submission.students}
  * Score: {submission.grade:.1f} / {assignmentPts:.1f} = {(100*submission.grade/assignmentPts):.2f}%
"""
  for fileId in submission.files:
    f = codepost.file.retrieve(id=fileId.id)
    fileName = f.name
    # fools be puttin unicode shite in their source, so...
    fileContents = f.code.encode('utf-8').decode('ascii','ignore')
    fileExtension = f.extension
    fileGraderCommentIds = [x.id for x in f.comments]
    result += f"  * Source File: `{fileName}`\n"
    details += f"## {title} Example - `{fileName}`\n"
    details += f"```{{.{fileExtension} .numberLines}}\n{fileContents}\n```\n"
    for commentId in fileGraderCommentIds:
      c = codepost.comment.retrieve(id=commentId)
      cleanText = c.text.replace("\n\n", "\n")
      if c.pointDelta:
        result += f"    * Lines {c.startLine:d} - {c.endLine:d} ({c.pointDelta:.1f}): {cleanText:s}\n"
      else:
        result += f"    * Lines {c.startLine:d} - {c.endLine:d}: {cleanText:s}\n"
  return result, details

def getAssignmentReport(assignment, abcEmails = None):
  """
  Produces an ABET assignment report (as a markdown-formatted string)
  for the given assignment (which is expected to be a codepost API
  object) by pulling all relevant data as well as source
  code files (and grader comments) for randomly selected A, B and C samples
  """
  courseId = assignment.course
  course = codepost.course.retrieve(id=courseId)
  courseName = course.name
  coursePeriod = course.period

  assignmentName = assignment.name
  assignmentPts = assignment.points
  assignmentMean = assignment.mean
  assignmentMedian = assignment.median

  summary = f"""
# {courseName} - {coursePeriod}
## {assignmentName}
  * Points: {assignmentPts}
  * Mean: {assignmentMean}
  * Median: {assignmentMedian}\n\n"""

  submissions = assignment.list_submissions()
  aSubmission = None
  bSubmission = None
  cSubmission = None
  if abcEmails:
      # User provided specific student emails of samples they wanted, so use them
      aSubmission = next( (s for s in submissions if abcEmails[0] in s.students), None)
      bSubmission = next( (s for s in submissions if abcEmails[1] in s.students), None)
      cSubmission = next( (s for s in submissions if abcEmails[2] in s.students), None)
  else:
      # find ideal A, B, C samples based on closest to A=max%, B = 85%, C = 75%
      aSubmission = submissions[0]
      bSubmission = submissions[0]
      cSubmission = submissions[0]
      # we only expect 1 submission per student since submissions are via our
      # scripts, but in any case, find the 3 closest to A=max%, B = 85%, C = 75%
      for submission in submissions:
        if submission.grade > aSubmission.grade:
          aSubmission = submission
        if abs(submission.grade / assignmentPts - .85) < abs(bSubmission.grade / assignmentPts - .85):
          bSubmission = submission
        if abs(submission.grade / assignmentPts - .75) < abs(cSubmission.grade / assignmentPts - .75):
          cSubmission = submission
  aSummary, aDetail = submissionToMarkdown(aSubmission,"A",assignmentPts)
  bSummary, bDetail = submissionToMarkdown(bSubmission,"B",assignmentPts)
  cSummary, cDetail = submissionToMarkdown(cSubmission,"C",assignmentPts)

  return summary + aSummary + bSummary + cSummary + "\n\n" + aDetail + bDetail + cDetail

def produceCourseReports(courseId):
  """
  Produces ABET reports (as both md and pdf files) for all assignments in
  the specified course
  """
  course = codepost.course.retrieve(id=courseId)
  for a in course.assignments:
    assignmentId = a.id
    produceAssignmentReport(assignmentId)

def produceAssignmentReport(assignmentId,abcEmails):
  """
  Produces a single report (as an md and pdf file) for the specified assignment
  """
  a = codepost.assignment.retrieve(id=assignmentId)
  assignmentName = a.name
  baseFileName = assignmentName.replace(" ", "_")
  assignmentId = a.id
  report = getAssignmentReport(a,abcEmails)
  fileNameMd = baseFileName + ".md"
  fileNamePdf = baseFileName + ".pdf"
  f = open(fileNameMd, "w")
  f.write(report)
  f.close()
  os.system("pandoc -s -V geometry:margin=1in -o "+fileNamePdf+" "+fileNameMd)

  return None


codePostApiKey = args.codePostApiKey
codepost.configure_api_key(codePostApiKey)
abcEmails = args.emails
if args.codePostCourseId:
  produceCourseReports(args.codePostCourseId)
elif args.codePostAssignmentId:
  produceAssignmentReport(args.codePostAssignmentId, abcEmails)
else:
  print("ERROR: neither course ID nor assignment ID specified")
