from zipfile import ZipFile 
from config import config
import base64
import os

def getFiles(path):
  """
  Returns a map of 
  
    { (fullPath,fileName,extension) => fileContents }

  of all files in the given path according to config.fileExtensions
  If the configuration includes jar or zip files, it extracts
  files within the archive files but only one level deep (it does
  not recursively extract archives within archives).  
  
  The key consists of a triple: the fullPath is included to ensure 
  that duplicate files are not excluded from the map; the fileName
  and extension (c, md, java for example, sans period) are included
  for convienience.  The value in the map is the contents of the file
  with any non-decodable characters excluded.
  
  path -- the path in which to retrieve files
  """
  files = {}
  if not os.path.exists(path):
    return files
  else:
    (_, _, filenames) = next(os.walk(path))
  if config.fileExtensions:
    filenames = [ f for f in filenames if f.endswith(tuple(config.fileExtensions)) ]
  if filenames:
    for fileName in filenames:
      (_,extension) = os.path.splitext(fileName)
      if extension[0] == '.':
        extension = extension[1:] #chomp period: .c -> c
      if extension == 'jar' or extension == 'zip':        
        extracted = extractArchiveFiles(path + fileName)
        files = {**files, **extracted}
      elif extension == 'pdf': 
        encoded = base64.b64encode(open(path+fileName, "rb").read())
        contents = "data:application/pdf;base64," + encoded.decode('utf-8')
        files[(path+fileName,fileName,extension)] = contents
      else:
        contents = open(path+fileName, errors='ignore').read()
        #if the file is empty, add content to accommodate codepost's API
        if not contents:
          contents = "EMPTY FILE"
        # If the file contains a null byte, likely it is binary, 
        # we ignore its contents.  In order to support binary files
        # additional support along with an appropriate media (MIME) 
        # type prefix tag; see https://www.iana.org/assignments/media-types/media-types.xhtml
        elif '\0' in contents:
          contents = "BINARY"
        files[(path+fileName,fileName,extension)] = contents
  return files

def extractArchiveFiles(fileName):
  """
  Extracts files from the given archive file (.tar, .zip), returning a map:
    
    { (fullPath,fileName,extension) => fileContents }
  
  of all of them according to the config.fileExtensions similar to 
  getFiles(path)
  
  fileName -- the path/file of the archive file to extract from
  """
  files = {}
  with ZipFile(fileName, 'r') as zip: 
    for z in zip.infolist():
      if not config.fileExtensions or (z.filename.endswith(tuple(config.fileExtensions)) and not z.filename.endswith(tuple(['.jar', '.zip'])) ):
          (path,basename) = os.path.split(z.filename)
          (_,extension) = os.path.splitext(basename)
          contents = zip.read(z).decode(errors='ignore')
          if not contents:
            contents = "EMPTY FILE"
          elif '\0' in contents:
            contents = "BINARY"
          files[(z.filename,basename,extension)] = contents
  return files
