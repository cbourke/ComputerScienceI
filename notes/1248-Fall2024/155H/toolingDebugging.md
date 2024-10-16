
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


```text








```
