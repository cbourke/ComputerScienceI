
# CSCE 155E - Computer Science I
## Debugging & Tooling
### Fall 2024


# Debugging

* Using `printf` messages is "poor man's debugging"
  * Using standard output is error prone and brittle
  * Standard output is a *buffer* and it may not give the correct impression on where a bug is
  * You could print out "okay to line 42" but the error actually occurs on line 52
  * Brittle: you constantly have to introduced and erase and rewrite messages!
* You'll want to use a proper *debugger*
  * A debugger is a program that runs another program (or simulates it) allowing you to pause the program and examine its contents (variable values, state, etc.)
  * You can also "step" through a program line by line
  * Debugger that we'll use: `gdb` (GNU's DeBugger)
  * Tutorial: https://ftp.gnu.org/old-gnu/Manuals/gdb/html_chapter/gdb_19.html
* Usage:
  * Always compile with the `-g` flag to preserve variable and function names and line numbers
  * ITs a TUI interface: Text-User Interface
  * To run it: `gdb ./a.out` will start GDB using your program
* Commands:
  * To start: `gdb ./a.out`
  * To display your source code: `layout src`
  * Sometimes the display glitches: `refresh`
  * To start/restart a program: `run`
  * Set breakpoints:
    * By line number: `break 14` (line 14)
    * Break at a function: `break sum`
    * Break in a line in another file: `break file.c:12` (break at line 12 in the file `file.c`)
    * Remove a breakpoint: `clear` (clears all break points) `clear 14` (clears the break point at line 14)
  * You can go to the next executable line of code using `next` or `n` for short
  * You can "step" *into* a function using `step` (otherwise the function line is skipped)
  * If execution is paused (at a breakpoint) you can `continue` it
  * You can print variable values: `print i` or `print n`
  * You can print entire arrays: `print *arr@7` or `print *arr@n`
  * You can "watch" a variable and when its values change it is reported: `watch i`
  * If you are trying to debug an infinite loop: run GDB and then use control-C (doesn't kill it, it pauses it!): careful it could "pause" in lower-level machine/library code (just keep hitting `next` until you get back to your code)
  * Command line arguments:
    * You invoke your program *through* gdb so there is no way to set command line arguments
    * Instead, you do *in* gdb:  
    `set args a b 10 20`
  * You can call basic C commands in gdb:
    * `print atoi(argv[1])`
    * `print a * b`
    * `print a * 10`
  * You can print an entire *stack trace* using `backtrace full`
  * You can set *conditional* breakpoints
    * `break 14 if x == 23`
    * `break 13 if(x == 23 && y < 0)`
  * You *must* recompile if changes are made; gdb does support some "hotfixes" but there is little reason to use them
  * lots more you can do...

## Tooling

```text







```
