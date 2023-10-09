
# CSCE 155E - Computer Science I
## Debugging & Tooling
### Fall 2023

## Tooling

* Source Control Software & Versioning:
  * git, distributed VCS = Version Control System
  * github != git
  * storing code, artifacts and the history of those artifacts
* Build Systems
  * `make`, `cmake`
  * Dependency management tools: `apt`, `brew`, windows
  * Package management
  * DevOps = Development Operations
  * CI = Continuous Integration
* Unit Testing
  * ad-hoc
  * informal
  * formal: `cmocka`
* Static Analysis Tools
  * You've seen basic examples: `-Wall` turns on all warnings
  * `-Wextra` a few extra ones (ie "all" doesn't mean all)
  * We have used the *compiler* has a static analysis tool to detect *lint*
  * Static analyzer: analysis done on the code *prior* to compilation to detect *potential* issues/errors
  * Code Smells: things that smell kinda funky and should be addressed but are not necessarily bugs
* Other tools
  * Alternative compiler: `clang`
  * `clang --analyze foo.c`
  * Facebook's Infer:
    `infer capture -- gcc foo.c`
    later: `infer analyze`
* Dynamic Analysis Tools
  * In contrast, *dynamic* analysis tools analyze your program *after* it has been compiled while it is *running*
  * `valgrind` is a dynamic analysis tool that can:
    * detect memory leaks
    * detect illegal memory accesses
    * more
  * Use:
    * You *must* compile using the `-g` flag (preserves function, variable names, line numbers)
    * You can run it using: `valgrind ./a.out`
    * Dynamic analysis occurs when you actually run the program  
    `valgrind --leak-check=full --show-leak-kinds=all ./a.out`
* Perf testing
    * Performance Testing
    * Profiler
    * `gprof` (later)

# Debugging

* Using `printf` messages is "poor man's debugging"
  * Using standard output is error prone and brittle
  * Standard output is a *buffer* and it may not give the correct impression on where a bug is
  * You could print out "okay to line 42" but the error actually occurs on line 52
  * Brittle: you constantly have to introduced and erase and rewrite messages!
* You'll want to use a proper *debugger*
  * A debugger is a program that runs another program (or simulates it) allowing you to pause the program and examine its contents (variable values, state, etc.)
  * You can also "walk" through a program line by line
  * Debugger that we'll use: `gdb` (GNU's DeBugger)
  * Tutorial: * https://ftp.gnu.org/old-gnu/Manuals/gdb/html_chapter/gdb_19.html
* Usage:
  * Always compile with the `-g` flag to preserve variable and function names and line numbers
  * ITs a TUI interface: Text-User Interface
  * To run it: `gdb a.out` will start GDB using your program



```text














```
