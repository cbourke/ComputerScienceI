"""
A single class to model an assignment in Canvas
"""

class Assignment:
    """
    A class that models an assignment in Canvas with a
    minimum of data
    """

    assignment_id = None
    name          = None
    points        = None

    def __init__(self, assignment_id,
                       name = None,
                       points = None):
        self.assignment_id     = assignment_id
        self.name   = name
        self.points = points

    def __str__(self):
        return f"{self.name} ({self.assignment_id}) {self.points:.1f} pts"

    def __repr__(self):
        return f"{self.name} ({self.assignment_id}) {self.points:.1f} pts"

    def __hash__(self):
        return hash(self.assignment_id)

    def __eq__(self,other):
        """
        Equality and ordering is determined based only on (canvas) id
        """
        return self.assignment_id == other.assignment_id

    def __lt__(self,other):
        """
        Equality and ordering is determined based only on (canvas) id
        """
        return self.assignment_id < other.assignment_id
