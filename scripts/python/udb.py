import pickle
import os.path
import pyodbc
from config import config

# For pyodbc you can find your odbc ini file using:
# 
#   odbcinst -j
# Which will list the ODBC drivers on the system.
# Alternatively, you can use pyodbc directly to list
# all known drivers:
#
#  for x in pyodbc.drivers():
#    print(x)


"""
Maps NUIDs to CSE login IDs.  Given the map of NUIDs
(some of which may already be mapped) it updates the
map by querying the udb (User Database) on the cse-apps
server, including any missing logins in the returned 
map.

If the specified pickleFileName is provided, the method
first tries to load (but does not overwrite) any missing
logins from the serialized pickle file to avoid going
to the database (a database query is still made for any
remaining missing records).  Further, the resulting
map is persisted back to the pickle file (overwriting 
the original) before it is returned.

@param nuidToCseLogin: the given map of (possibly incomplete) NUIDs-to-CSE Logins
@param pickleFileName: the name of the pickle file to persist from/to
@return: an updated NUID-to-CSE Login map
"""
def mapNuidsToCseLogins(nuidToCseLogin, pickleFileName = None):

  if pickleFileName is not None:
    if os.path.isfile(pickleFileName):
      print('loading from data file '+pickleFileName+'...')
      f = open(pickleFileName, "rb")
      nuidToCseLoginPickle = pickle.load(f)
      f.close()
      for nuid,login in nuidToCseLoginPickle.items():
        if nuid in nuidToCseLogin and  nuidToCseLogin[nuid] is None:
          nuidToCseLogin[nuid] = login

  # generate a list of missing NUIDs
  missingLogins = []
  for nuid,login in nuidToCseLogin.items():
    if login is None:
      missingLogins.append(nuid)
    
  # if missing logins, try to get them from the DB:
  if missingLogins:
    try:
      print("loading missing logins from db...")
      print(missingLogins)
      nuidParam = "'" + '\', \''.join(missingLogins) + "'"
      query = 'SELECT login,nuid FROM view_login_nuid where nuid in ('+nuidParam+')'

      connStr = ("Driver=%s;"
                 "Server = %s;"
                 "Database = %s;"
                 "uid = %s;"
                 "password = %s;"
                 "Trusted_Connection = yes;")%(
                 config.udb.driver,
                 config.udb.host,
                 config.udb.database,
                 config.udb.username,
                 config.udb.password
                 )

      conn = pyodbc.connect(connStr)
      cursor = conn.cursor()
      cursor.execute(query)
      for row in cursor:
        (login,nuid) = row
        nuidToCseLogin[nuid] = login
    except pyodbc.Error as e:
      print("unable to connect to db")
      print(e)

  if pickleFileName is not None:
    outFile = open(pickleFileName, 'wb')
    pickle.dump(nuidToCseLogin, outFile)
    outFile.close()

  return nuidToCseLogin

#nuids = ['35140602', '12345678', '49883755', '61910486']
#b = dict(zip(nuids, [None for x in nuids]))
#for nuid,login in b.items():
#  print(nuid + " -> " + str(login))

#b = mapNuidsToCseLogins(b, config.nuidToCseLoginPickle)
#for nuid,login in b.items():
#  print(nuid + " -> " + str(login))
