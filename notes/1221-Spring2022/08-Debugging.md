
# ECEN 1940 - Computer Science I
## Debugging & Tooling
### Fall 2022

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

  * Usage:
    * always compile with the `-g` flag: it preserves variable and function names as well as line numbers
    * To run GDB use: `gdb a.out`
    * To run your program: `run`
    * To view your source code you can use `layout next` or `layout src`
    * Sometimes it screws up, just type: `refresh`  
    * You can set a function breakpoint: `break main`
    * You can set a line breakpoint: `break 12`
    * You can set a line breakpoint in another file: `break file.c:26`
    * You can clear a breakpoint by using `clear main` or `clear 12`
    * You can resume the program with `continue`
    * You can view the value stored in a variable using `print variableName`
    * Halt: control-C
    * Continue:
    `continue`
    * Watch a variable:
    `watch total`
    * Redraw:   
    `refresh`
    * set arguments:
    `set args a b c`
    * Conditional break:
    `break 10 if x == 21`

```text







```
