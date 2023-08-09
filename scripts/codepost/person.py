
class Person:
    """
    A class that models a person which includes students,
    graders, instructors, etc.

    Each person is uniquely identified by their NUID and
    is expected to have credentials Canvas.

    For students, their email is usually their huskers email.

    Separate name elements (first, last) may not be available in
    Canvas and instead only a 'display' name may be available due
    to students being able to set a 'preferred name' in the
    registration system.  Generally this should be sufficient
    for lexicographic ordering.
    """

    nuid = None
    name = None
    canvasId = None
    canvasLogin = None
    canvasEmail = None
    group = None

    def __init__(self, nuid,
                       name = None,
                       canvasId = None,
                       canvasLogin = None,
                       canvasEmail = None):
        self.nuid        = nuid
        self.name        = name
        self.canvasId    = canvasId
        self.canvasLogin = canvasLogin
        self.canvasEmail = canvasEmail

    def __str__(self):
        return "%-30s (%s) %s"%(self.name,self.nuid,self.canvasEmail)

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
        return "%s,%s,%s,%s,%s\n"%(self.nuid,self.name.replace(", ", ","),self.canvasId,self.canvasEmail,self.canvasLogin)
