
class Assignment:
    """
    A class that models an assignment in Canvas with a
    minimum of data
    """

    id = None
    name = None
    points = None

    def __init__(self, id,
                       name = None,
                       points = None):
        self.id     = id
        self.name   = name
        self.points = points

    def __str__(self):
        return f"{self.name} ({self.id}) {self.points:.1f} pts"

    def __repr__(self):
        return f"{self.name} ({self.id}) {self.points:.1f} pts"

    def __hash__(self):
        return hash(self.id)

    def __eq__(self,other):
        """
        Equality and ordering is determined based only on (canvas) id
        """
        return self.id == other.id

    def __lt__(self,other):
        """
        Equality and ordering is determined based only on (canvas) id
        """
        return (self.id < other.id)
