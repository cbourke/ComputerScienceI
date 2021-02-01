
class Person:
    """
    A class that models a person which includes students, 
    graders, instructors, etc.
    
    Each person is uniquely identified by their NUID and
    is expected to have credentials in both Canvas as well
    as CSE.
    
    As of fall 2019, the Canvas API generally supports email
    addresses for all validily enrolled individuals regardless
    of their 'opt out' status with respect to personal information.
    If an individual has not 'accepted' an enrollment in Canvas,
    this information may not be available through the API.

    For students, their email is usually their huskers email.
    In general, cse emails should not be used for students.
    
    Separate name elements (first, last) may not be available in
    Canvas and instead only a 'display' name may be available due
    to students being able to set a 'preferred name' in the 
    registration system.  Separate name elements may be available
    in the CSE UDB but are not currently used.
    
    A person's cseLogin must be pulled from the CSE User DataBase 
    (see udb.py) via their NUID.
    """
    
    nuid = None
    name = None
    canvasId = None
    canvasLogin = None
    canvasEmail = None      
    cseLogin = None
    group = None
    
    def __init__(self, nuid,
                       name = None,
                       canvasId = None,
                       canvasLogin = None,
                       canvasEmail = None,
                       cseLogin = None):
        self.nuid        = nuid
        self.name        = name
        self.canvasId    = canvasId
        self.canvasLogin = canvasLogin
        self.canvasEmail = canvasEmail      
        self.cseLogin    = cseLogin

    def __str__(self):
        return "%-40s (%s) %-15s %s"%(self.name,self.nuid,self.cseLogin,self.canvasEmail)

    def __hash__(self):
        return hash(self.nuid)
        
    def __eq__(self,other):
        """
        Equality and ordering is determined based only on NUID
        """
        return self.nuid == other.nuid
        
    def __lt__(self,other):
        """
        Equality and ordering is determined based only on NUID
        """
        return (self.nuid < other.nuid)

    def toCsv(self):
        return "%s,%s,%s,%s,%s,%s\n"%(self.nuid,self.name,self.canvasId,self.canvasEmail,self.canvasLogin,self.cseLogin)
