
# CSCE 155H - Computer Science I
## Debugging & Tooling
### Fall 2024

## Tooling

* Source Control & Software Versioning
  * git != github
  * Distributed VCS = Version Control System
  * It allows you to store copies of the code and its history on any computer (including servers/clouds/etc)
  * Convenience: you always have a backup!
  * Perfect for team development
  * Don't transfer via dropbox/google doc/one drive etc.  You are engineers not office drones!
* Build Systems
  * `make` (or cmake), Java: `ant`
  * DevOps = Development Operations
  * entire teams can write scripts to do CI = Continuous Integration
* Dependency Management Tools
  * `apt-get` (package manager)
  * Java: `maven`
  * Python: `pip`
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
    * Another (but not installed): Facebook's Infer
* Dynamic Analysis Tools
  * Dynamic in this case means "as its running"
  * Example: `valgrind`
  * To use valgrind, compile with the `-g` flag
  * Run valgrind on your program: `valgrind ./a.out`
  * Common issues:
    * Memory leaks
    * invalid read/writes
    * Seg fault isolation (what line did it happen on?)
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
* Cheat sheet: https://ftp.gnu.org/old-gnu/Manuals/gdb/html_chapter/gdb_19.html
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
* Misc:
  * You can set command line arguments in GDB using `set args 10 20 30`
  * Manually set variable values: `set var n = 8`
  * call functions: `print atoi(argv[1])` or `print sum({1, 2, 3}, 3)`
  * You *must* recompile if changes are made; gdb does support some "hotfixes" but there is little reason to use them
* Eclipse: the small little bug icon

```text








```
