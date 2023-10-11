
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
* Commands:
  * Start GDB: `gdb a.out`
  * Display the source as you go along: `display src`
  * Sometimes it gets messed up, so `refresh`
  * to start the program: `run`
  * Set breakpoints:
    * By line: `break 14` (line 14)
    * By function: `break sum` (or any other function name)
    * By a line in a specific source file: `break file.c:12` (line 12 in the file `file.c`)
    * Remove a break point using `clear`; ex: `clear 14`
  * You go to the next line using: `next` or simply `n`
  * You can go *into* a function by either setting a break point or using `step`
  * You can continue operations until the next break point using `continue`
  * You can print hte value of variables:
    * `print i` or `print n`
    * Print an array: `print *arr@7` or `print*arr@n`
  * YOu can keep an eye on a variable by setting a "watch" and it will be printed whenever it gets updated
  * You can use control-C to stop a runaway program and examine where you are
  * Command line arguments:
    * You invoke your program *through* gdb so there is no way to set command line arguments
    * Instead, you do *in* gdb:  
    `set args a b 10 20`
  * You can call basic C commands in gdb:
    * `print atoi(argv[1])`
    * `print a * b`
    * `print a * 10`
  * You can print an entire *stack trace* using `backtrace full`
  * You can also set *conditional breakpoints*
    * `break 14 if x == 23`
    * `break 13 if(x == 23 && y < 0)`
  * You *must* recompile if changes are made; gdb does support some "hotfixes" but there is little reason to use them
  * lots more you can do...

```text














```
