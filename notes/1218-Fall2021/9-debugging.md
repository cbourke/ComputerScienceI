
# CSCE 155E - Computer Science I
## Debugging & Tooling
### Fall 2021

## Tooling

* Source Control & Software Versioning:
  * git: distributed VCS
* Build Systems
  * make, cmake
  * Dependency management of external libraries
  * Package management
  * Dev Ops = Development Operations
* Unit Testing
  * ad-hoc
  * informal
  * formal: cmocka
* Static Analysis Tools
  * Static analysis is an analysis of your code *before* it compiles
  * Example: `gcc` can be used as a linter: `-Wall`
  * Another flag: `gcc -Wextra`
  * Clang: `clang --analyze foo.c`
  * Facebook's Infer:
    `infer capture -- gcc foo.c`
    later: `infer analyze`
* Dynamic Analysis Tools
  * Dynamic analysis occurs when you actually run the program
  `valgrind --leak-check=full --show-leak-kinds=all ./a.out`
  * memory leaks
  * bounds checks (compile with `-g`!)
* Perf testing
    * Performance Testing
    * Profiler
    * `gprof` (later)

# Debugging

* "poor man's debugger": `printf`
* You'll want to use a proper debugger: `gdb`
* https://ftp.gnu.org/old-gnu/Manuals/gdb/html_chapter/gdb_19.html
* A debugger is a program that simulates/runs another program and allows you to:
  * pause the execution
  * view variable values
  * "step" through a program line by line
  * set break points to pause the execution at a particular function, line, or under some condition!
* GDB is GNU's Debugger is a command line or "TUI" debugger
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
