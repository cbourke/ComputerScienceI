
# CSCE 155E - Computer Science I
## Debugging & Tooling
### Fall 2021

## Tooling

Tools to write code are just as important (if not more important) than writing the code!

* Source control systems: git (distributed version control system)
* Build Systems: make, cmake (ant, maven)
  * DevOps = Development Operations
  * Deployment Scripts
  * Dependency Management
  * Testing Scripts
  * Continuous Integration
* Testing: Unit Testing
  * ad-hoc testing
  * informal automated testing
  * Formal unit testing: cmocka, JUnit
  * TDD = Test Driven Development
* Tools: Static Analysis Tools
  * gcc as a linter: `gcc -Wall`
  * Another `gcc -Wextra`
  * Another compiler + linter: `clang --analyze foo.c`
  * Facebook's Infer:  
  `infer capture -- gcc foo.c`  
  `infer analyze`
  * More: https://github.com/cbourke/ComputerScienceI/blob/master/documents/troubleShooting.pdf
* Dynamic Analysis Tools
  * Valgrind:  `valgrind --leak-check=full --show-leak-kinds=all ./a.out`
  * memory leaks
  * bounds checks (compile with `-g`!)
* Perf Testing
  * Performance Testing
  * Profilers
  * `gprof` (later)

* Debuggers  

# Debugging

* Identify the bug
* Identify the input that causes the bug
* You need to make the bug *reproducible*
* Using `printf` statements to view value(s) or variables is a "poor man's debugger"
* Using a proper debugger is better
* C: GDB
* Java: Eclipse Debugger
* A debugger is a program that simulates/runs another program and allows you to:
    * pause the execution
    * View variable values
    * "step" through the program line by line
    * set break points in a program and continue execution up to that point
    * Start GDB with your program:
    `gdb a.out`
    * Run your program:
    `run`
    * Set a break point:
    `break main`
    * See your code:
    `layout next`, `layout src`
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
