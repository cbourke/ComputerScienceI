from config import config
import requests
from urllib.parse import urlencode

def updateGrade(assignmentId,userId,assignmentScore):
  header = {
    "Content-Type": "application/x-www-form-urlencoded"
  }
  payload = {
    "submission[posted_grade]": assignmentScore
  }
  theData = urlencode(payload)
  path = (config.canvasUrl +
          "courses/" +
          config.canvasCourseId +
          "/assignments/" + 
          assignmentId + 
          "/submissions/" +
          userId +
          "?access_token=" + 
          config.canvasApiKey)
  r = requests.put(path, headers=header, data=theData)

#updateGrade(assignmentId="645861",userId="90388",assignmentScore="2")







