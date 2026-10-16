
# CSCE 155H - Computer Science I
## Debugging & Tooling
### Fall 2026

## Tooling

* Source Control & Software Versioning
  * git (!= GitHub)
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
  * Examples: `gcc -Wall -Wextra` (these make gcc into a linter)
  * Static analysis tools are run on code *before* compiling to find potential problems or "code smells"
  * Another: `clang --analyze demo.c`
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
  * "step" through a program line by line to view its execution
* Usage:
  * Compile with the `-g` flag!
  * To run GDB use: `gdb a.out`
  * Cheat sheet: https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf

## Commands

* Run your program:
  * `run`
  * You can always rerun from the beginning with this command
* Set command line arguments:
  * `set args 10 20 hello`
* Breakpoints:
  * Set it by line: `break 14` (set a breakpoint at line 14)
  * You can break at a function: `break sum`
  * When working with multiple files: `break file.c:14`
  * Remove a breakpoint: `clear 14` or `clear sum`
* As you go through a program:
  * `next` or `n` to go to the next line
  * `next` does NOT go *into* a function
  * Instead: `step` to step into a function
  * To continue the program (until the next breakpoint): `continue`
* You can print things:
  * Print a variable value: `print n`
  * Print an entire array: `print *a@10` or `print *a@n`
  * You can print expressions: `print n / 10 + 4.8 * a`
* You can watch variables for changes
  * `watch n` (it will print changes to the variable `n`)
* Misc
  * You can print out *everything* in the entire stack using   
  `backtrace full`
  * You can set command line arguments using `set args 10 hello 30`
  * You can manually (re)set variables: `set var n = 8`
  * You can call functions: `print atoi(argv[1])`, `print(sum{1, 2, 3}, 3)`
  * You *must* recompile if changes are made; gdb does support some "hotfixes" but there is little reason to use them
  
```text








```
