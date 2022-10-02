
# Computer Science I
## ECEN 194 - Fall 2022
### Error Handling

* Programs always have potential for errors
* Some errors can be unexpected
* Some can be anticipated and protected against
  * You can anticipate that bad things will happen and then *handle* those errors
  * Some errors are simply *fatal*: you want to let the program end/die at that point because it is *unrecoverable*
* In C our general strategy will be *defensive programming*
  * "Look before you leap"
  * IE error checking is the *FIRST* think you do in any function
  * Check for error conditions before you execute some potentially dangerous code and if such error would occur, you don't do it.
  * Ex: `double x = a / b;`: you check if `b == 0` before doing it
* What we ***don't*** do:
  * we don't print an error message
  * we don't exit the program!
* You don't do the dangerous operation, instead you `return` from the function with an error code (`int`) that indicates the type of error
  * Convention: `0` no error
  * Non-zero values indicate some *type* of error

## How C does system-level error handling

* POSIX compliant systems have some basic error codes
* The POSIX standard actually only defines 3 error codes
  * `EDOM`: indicates an error in the *domain* (the input) of a function call; Example: `sqrt(-1)`
  * `ERANGE`: indicates an error in the *range* (the output) of a function call; Example: `log(0)`
  * `EILSEQ`: illegal byte sequence (rarely seen)
  * Each one of these is defined in `errno.h` (error number)
  * In the event of one of these errors, a global variable, `errno` is set with one of those three possible values

## Enumerated Types

* An enumeration is just an ordered list of things
* Ex: days of the week, months of the year, error codes
* Syntax:

```c
typedef enum {
  SUNDAY,
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY
} DayOfWeek;
```
* Observations:
  * You use `typedef enum` at the top
  * Inside curly brackets you provide a list, one to a line, delimited by a comma
  * At the end you provide a *name* of the type: usually you use `UpperCamelCasing`
  * Actual values use an `UPPER_UNDERSCORE_CASING`

## Pitfall

* Internally, this is nothing more than syntactic sugar
* Internally, each value is represented using an integer, starting with zero!
* Ex: `SUNDAY` has a value of 0, `MONDAY` has a value of 1, `SATURDAY` has a value of 6

```c

//proper usage:
DayOfWeek today = THURSDAY;
DayOfWeek tomorrow = FRIDAY;

if(day == SATURDAY) {
  printf("Mavs kick off preseason play!\n");
}


//improper usage: don't do this!
today = today + 10;

//maybe okay:
today++;

//maybe not:
today = SATURDAY;
today++; //invalid

//very okay:
today = (today + 1) % 7;

```

* Demo: using this with error codes.

## Tool Demo: valgrind

* Gcc's `-Wall` flag is a *static analysis* tool: it examines your code *before* it is compiled for potential issues
* If a segfault occurs *during the run* that the linter was not able to detect, how can we tell what line or line(s) the error occurred on?
* You need a *dynamic analysis* tool: a tool that examines a *running program* *after* it has been compiled
* You can compile with the `-g` flag in order to preserve metadata about the code: in particular, variable names, function names, *line numbers*


```text









```
