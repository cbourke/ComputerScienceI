
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


```text








```
