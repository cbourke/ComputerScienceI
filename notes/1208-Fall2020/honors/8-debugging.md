
# CSCE 155E - Computer Science I
## Debugging & Tooling
### Fall 2020

## Tooling

* Source Control & Versioning: git
* Build Systems: make, cmake, ant (java)
  * Deployment scripts
  * Dependancy management (java: maven)
  * DevOps
* Unit Testing: ad-hoc, informal, formal testing: cmocka, Java: JUnit
* Static analysis tools:
  * Linter: `gcc -Wall`
  * Another: `gcc -Wall -Wextra`
  * Clang: `gcc --analyze foo.c`
  * Facebook's Infer:  
  `infer capture -- gcc foo.c`  
  `infer analyze` 
  * More: https://github.com/cbourke/ComputerScienceI/blob/master/documents/troubleShooting.pdf
* Dynamic Analysis Tools
  * Valgrind:
  `valgrind --leak-check=full --show-leak-kinds=all ./a.out`
  * memory leaks
  * bounds checks (compile with `-g`!)
* Perf Testing
  * Performance Testing
  * Profilers
  * `gprof` (later)
* Debuggers  
  
# Debugging

* Identify the bug
* Identify input that causes the bug
* You need to do this to make the bug *reproducible* 
* Using `printf` statements to view the value(s) of variables is referred to as "poor man's" debugging
* Using a proper *debugger* is better
* A debugger is a program that simulates/runs another program and allows you to:
    * pause the execution
    * View variable values
    * "step" through the program line by line
    * set break points in a program and continue execution up to that point
* GDB (Gnu's Debugger) is a command line debugger
* Compile with `-g` flag to preserve variable and function names
`gcc -g arrayProgram.c`
* Start GDB with your program:
`gdb a.out`
* Run your program:
`run`
* Set a break point:
`break main`
* See your code:
`layout next`
* Step:
`next` (shorthand: `n`)
* print a variable:
`print foo`
* print an array:
`print *arr@len`
* Set another break point base on a line number:
`break 25`
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
* Halt: control-C


