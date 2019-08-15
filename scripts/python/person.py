
class Person:
    nuid = None
    name = None
    canvasId = None
    canvasLogin = None
    canvasEmail = None      
    cseLogin = None
    cseEmail = None
    
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
        self.cseEmail    = None
    def __str__(self):
        return "%-30s (%s) %-15s"%(self.name,self.nuid,self.cseLogin)
    def __hash__(self):
        return hash(self.nuid)
        
    def __eq__(self,other):
        return self.nuid == other.nuid
        
    def __lt__(self,other):
        return (self.nuid < self.nuid)
