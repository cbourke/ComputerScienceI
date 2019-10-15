
# Debugging

* Using `printf` statements to view the value(s) of variables is referred to as "poor man's" debugging
* Using a proper *debugger* is better
* A debugger is a program that simulates/runs another program and allows you to:
    * pause the execution
    * View variable values
    * "step" through the program line by line
    * set break points in a program and continue execution up to that point
* GDB (Gnu's Debugger) is a command line debugger
* Usage:
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
    * Set anothe break point base on a line number:
    `break 25`
    * Continue:
    `continue`
    * Watch a variable:
    `watch total`




```text



















```
