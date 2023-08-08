"""
This script interfaces with canvas and codepost.io
to transfer grades of any assignment from codepost.io
into the canvas gradebook.

TODO:
 -load roster/course
 -define CLAs: IDs or names?
 -stage, require --commit (TODO: one time use or differentiate between commit and override?)
 -persist to canvas

Usage: python3 codepostToCanvas.py codepost_assignment_id canvas_assignment_id
"""
