
# CSCE 155H - Computer Science I
## Debugging & Tooling
### Fall 2023

## Tooling

* Source Control & Software Versioning
  * git != github
  * Distributed VCS = Version Control System
  * It allows you to store copies of the code and its history on any computer (including servers/clouds/etc)
  * Convenience: you always have a backup!
  * Perfect for team development
  * Don't transfer via dropbox/google doc/one drive etc.  You are engineers not office drones!
* Build Systems
  * `make`, cmake, (Java: ant)
  * DevOps = Development Operations
  * entire teams can write scripts to do CI = Continuous Integration
* Dependency Management Tools
  * apt, brew, (Python: pip)
  * LIbrary management tools
  * Java: maven
  * Package Managers
* Unit testing
  * ad-hoc
  * informal unit testing (you write your own boiler plate)
  * formal unit testing (cmocka, JUnit, testng)
* Static Analysis Tools
  * Static analysis occurs *before* you compile: it looks at your code (which is a *static*, unchanging artifact)
  * Example: `gcc -Wall -Wextra` (gcc as a linter!)
  * Another: `clang --analyze foo.c`
  * Another (but not installed): Facebook's Infer
* Dynamic Analysis Tools
  * Dynamic analyzers analyze code when it is being run
  * Example: `valgrind`
  * Always use the `-g` flag to preserve line numbers and variable names
  * Other examples:  
  `valgrind --leak-check=full --show-leak-kinds=all ./a.out`
  * Detects memory leaks, invalid read/writes (index out of bounds)
* Perf testing
    * Performance Testing
    * Profiler
    * `gprof` (later)

# Debugging

* Do not do poor man's debugging: `printf`'s everywhere
  * It is brittle: you constantly have to write and erase a bunch of lines
  * Printf approach doesn't even work
* Use a proper debugger: `gdb`
  * GNU's DeBugger
  * Command-line TUI = Text-based User Interface debugger
* A debugger is a program that simulates/runs another program and allows you to:
  * pause execution
  * view variable values
  * evaluate expressions
  * "step" through the program line by line
* Usage:
  * Compile with the `-g` flag!
  * To run GDB use: `gdb a.out`
  * Display the source as you go along: `display src`
  * Sometimes it gets messed up, so `refresh`
  * to start the program: `run`
* Breakpoints:
  * Set it by line: `break 14` (set a breakpoint at line 14)
  * Remove a breakpoint using `clear 14`
  * You can set a breakpoint at a function: `break sum`
  * When working with multiple files: `break file.c:14`
* You can go through a program:
  * Line by line: `next` or `n`
  * You can *step* **into** a function using `step`
  * Resume execution: `continue`
* YOu can print stuff:
  * Print a variable value: `print n`
  * You can print an entire array `print *primes@7` or `print *primes@n`
  * You can print expressions: `print 10 * primes[0] - n`
* You can watch variables for changes
  * `watch n` (it will print changes to the variable `n`)
* You can use your debugger to find where stuff goes wrong...
  * `backtrace full` gives a full stacktrace report
  * IFninite loops: control-C
  * Conditional breakpoints: `break 14 if i == 42`, `break 14 if i == 42 && j < 0`
* MIsc:
  * You can set command line arguments in GDB using `set args 10 20 30`
  * Manually set variable values: `set var n = 8`
  * call functions: `print atoi(argv[1])` or `print sum({1, 2, 3}, 3)`
  * You *must* recompile if changes are made; gdb does support some "hotfixes" but there is little reason to use them

```text








```
