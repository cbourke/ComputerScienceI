
# ECEN 194 - Computer Science I
## Debugging & Tooling
### Fall 2022

## Midterm

* Wed: Reading, Hack due
* Thursday, October 20th: 12:01AM - 11:59PM
* 100 points but not twice as long
* More recent material, but comprehensive
* NO collaboration
* Lecture: do your midterm or watch for a review
* Hack: still held (GDB debugging hack)

## Tooling

* Source Control & Software Versioning
  * git: distributed VCS = Version Control System
  * Why:
    * You can have one central copy and use it on multiple machines
    * Cloud-based backup
    * Convenience
    * Don't transfer via dropbox/google doc/one drive etc.  You are engineers not secretaries
* Build Systems
  * make, cmake
  * Dependency managers of external libraries
  * Package managers, etc.
  * Dev Ops = Development Operations
* Unit Testing
  * ad-hoc
  * informal unit testing: you write your own framework
  * formal testing framework: cmocka
* Static Analysis Tools
    * Static analysis is done before you compile: it is an analysis on  your code
    * Examples: `gcc -Wall`
    * Another: `gcc -Wextra -Wall`
    * Clang: `clang --analyze foo.c`
* Dynamic Analysis Tools
    * Dynamic analyzers analyze code when it is being run
    * Example: valgrind
    * First: compile with a `-g` flag
    `valgrind --leak-check=full --show-leak-kinds=all ./a.out`
    * memory leaks
    * bounds checks (compile with `-g`!)
* Perf testing
    * Performance Testing
    * Profiler
    * `gprof` (later)

# Debugging

* Do not do poor man's debugging: `printf`'s everywhere
* Use a proper debugger: `gdb`
* Command-line TUI = Text-based User Interface debugger
* A debugger is a program that simulates/runs another program and allows you to:
  * pause execution
  * view variable values
  * evaluate expressions
  * "step" through the program line by line
* Usage:
  * Compile with the `-g` flag!
  * To run GDB use: `gdb a.out`
  * To run your program: `run`
  * YOu can set command line arguments using `set args 5 10 20`
  * You can view your code using `layout src`
  * Sometimes the display screws up; you can fix it by typing `refresh`
  * You can set a break point:
    * `break 12` (for line 12)
    * `break main` (for a function)
    * `break file.c:26` (if you have multiple files)
    * You can remove a breakpoint using `clear`:
    * Ex: `clear 12`, `clear main`
  * You can print the value of variables: `print variableName`
  * You can print an entire array of values using `*arr@8`
  (dereference and provide a size)
  * quit: `quit`
  * Pause a running program (infinite loop): `control-C`
  * Watch a variable for changes: `watch variableName`
  * Continue to the next break point without pausing: `continue`
  * Go to the next line: `next` or `n` for short
  * You can *step* INTO a function using `step` instead of `next`
  * You can set a conditional breakpoint: `break 10 if x == 21` (break at line 10 if x == 21)

```text







```
