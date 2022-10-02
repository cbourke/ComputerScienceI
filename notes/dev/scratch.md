
- Finish with enums
- POSIX error handling

## How C does system-level error handling

* The POSIX standard actually only defines 3 error codes:
  * `EDOM`: indicates an error in the *domain* (the input) of a function call; Example: `sqrt(-1)`
  * `ERANGE`: indicates an error in the *range* (the output) of a function call; Example: `log(0)`
  * `EILSEQ`: illegal byte sequence (rarely seen)
  * Each one of these is defined in `errno.h` (error number)
  * In the event of one of these errors, a global variable, `errno` is set with one of those three possible values
  * Demo

## Tool Demo: valgrind

- valgrind demo

x ** make demo file


MISC:

Hack 5:
- use lab 5 as a reference/model
- build in a tolerance!

Course Midterm Evaluation
