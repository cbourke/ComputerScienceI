
# CSCE 155H - Computer Science I
## Debugging & Tooling
### Fall 2025

## Tooling

* Source Control & Software Versioning
  * git != github
  * Distributed VCS = Version Control System
  * It allows you to store copies of the code and its history on any computer (including servers/clouds/etc)
  * Convenience: you always have a backup!
  * Perfect for team development
  * Don't transfer via dropbox/google doc/one drive etc.  You are engineers not office drones!
* Build Systems
  * `make` (cmake)
  * DevOps = Development Operations
  * entire teams can write scripts to do CI = Continuous Integration
* Dependency Management Tools
  * `apt-get` (package manager)
  * Java: `maven`, Python: `pip`
* Unit testing
  * ad-hoc
  * informal unit testing (you write the boiler plate code)
  * Formal unit testing frameworks: `cmocka`, JUnit (5)
  * TDD = Test Driven Development
* Static Analysis Tools
  * "static" here means *before* compilation: it looks at your code for potential errors
  * Examples:
    * `gcc -Wall -Wextra` (these make gcc a linter): it can detect "code smells"
    * Another: `clang --analyze foo.c`
* Dynamic Analysis Tools
  * Dynamic means "as it is running"
  * Ex: `valgrind`
  * To use valgrind, compile with the `-g` flag
  * Run valgrind on your program: `valgrind ./a.out`
  * Common issues:
    * Memory leaks
    * invalid read/writes
    * Seg fault isolation (what line did it happen on?)

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
  * Cheat sheet: https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf
* Breakpoints:
  * Set it by line: `break 14` (set a breakpoint at line 14)
  * Remove a break point: `clear 14`
  * You can set a function breakpoint: `break sum`
  * When working with multiple files: `break file.c:14`
* You can go through a program:
  * Line by line: `next` or `n` for short
  * You can *step* INTO a function: `step`
  * Generally you cannot step into library functions
  * Resume execution: `continue`
* YOu can print stuff:
  * Print a variable value: `print n`
  * You can print an entire array: `print *primes@7` or `print *primes@n`
  * YOu can print expressions: `print 10 * primes[0] - 5`
* You can watch variables for changes
  * `watch n` (it will print changes to the variable `n`)
* You can use your debugger to find where stuff goes wrong...
  * `backtrace full` gives a full stacktrace report
  * If you have an infinite loop: `control-C` it won't kill hte program it will *pause* it!
  * Conditional breakpoints: `break 14 if i == 42`, `break 14 if i == 42 && j < 0`
* Misc:
  * You can set command line arguments in GDB using `set args 10 20 30`
  * Manually (re)set variable values: `set var n = 8`
  * call functions: `print atoi(argv[1])` or `print sum({1, 2, 3}, 3)`
  * You *must* recompile if changes are made; gdb does support some "hotfixes" but there is little reason to use them
```text








```
