
# CSCE 155E - Computer Science I
## Error Handling
### Fall 2022

* Errors can either be completely unexpected or anticipated but not normal
* Some errors, are, by nature *fatal*; the program, in general, *should* die in some cases
* Some errors you *can* recover from (you can anticipate them and not perform the dangerous operation and instead move on in some way)
* This is known as *error handling*: how you "handle" the errors when encountered

## In C:

* C uses *defensive programming*: "look before you leap"
* You write code to detect potentially bad/dangerous operations before they occur
* Example

```c
double a, b;
//TODO; read values in...

double x = a / b;

//instead:

if(b == 0) {
  //DONT DIVIDE, DO SOMETHING ELSE
} else {
  x = a / b;
}

```
* If an error condition is detected, you don't do the potentially dangerous code
* Instead, from a function, you:
  * Immediately return without doing the dangerous code
  * You return an error code to the calling function to communicate the type of error that occurred
  * You *DON'T* exit the program
  * YOu *DON'T* print anything
  * the calling function then has the responsibility (or option) to deal with the problem or error

* To do this, make all of your result values as pass-by-reference variables
* Use the return type to return an integer: `int` that indicates the *type* of error that occurred
  * convention: `0` indicates no error (false, no error)
  * non-zero indicates *yes* there was an error

## Solution: use enumerated types

* You *could* define macros using the `#define ERROR_TYPE 1`
* OR you can use an *enumerated type*
* An enumeration is a *list* of things: days of the week, months, etc; *error codes*
* In C, you can define an enumeration:

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

//later in the program, you can use your own type!

DayOfWeek today = WEDNESDAY;

```

* Style/Syntax observations:
  * You use `typedef enum` to define a enumeration
  * Within the opening/closing curly brackets you have the list
  * one item to a line, separated by commas
  * Values use an `UPPER_UNDERSCORE_NAMING_CONVENTION`
  * At the end you give your type a name followed by a semicolon
  * The name should be `UpperCamelCased`


```c
typedef enum {
  JANUARY,
  FEBRUARY,
  MARCH,
  APRIL,
  ...

} Month;
```

# Pitfalls

* Internally, an enumeration is just syntactic sugar
* enumeration types are still just regular old integers in C
* C will assign values to your enumeration starting at 0 (by default)
* You can, but shouldn't treat enumerations as integers

```c
//normal usage:
DayOfWeek today = FRIDAY;
DayOfWeek tomorrow = SATURDAY;

if(today == SATURDAY) {
  printf("Game time\n");
}

//you can do the following:
tomorrow = today + 1;
//but probably shouldn't:
tomorrow = today + 2;

//better, but still not great:
DayOfWeek foo = (today + 2) % 7;


//really don't do the following:
DayOfWeek bar = TUESDAY + THURSDAY;

```

## System-level error handling in C

* The POSIX standard actually defines 3 error codes:
  * `EDOM` - indicates an error in the *domain* (input) to a function: example: `sqrt(-1)`
  * `ERANGE` - indicates an error in the *range* (output) of a function: example `log(0)`
  * `EILSEQ` - Illegal Byte Sequence
  * All of these are defined in, `errno.h` (error number)
  * In the event of an error, a global variable `errno` is set to one of these error codes

## Tool Demo: valgrind

* recall that the `-Wall` flag can be used as a *linter*
* A linter is a *static analysis* tool: it looks at and analyzes your code *before* it gets compiled
* You can also use *dynamic analysis* tools: analyze your program as it is running
* Ex: `valgrind`
* Usage: be sure to compile with the `-g` flag to preserve line numbers and variables, etc.
* Run: `valgrind ./a.out`
* Which produces a report telling you what line(s) it failed on
* No tool replaces proper testing/unit testing

## Misc

Hack 5:
  * Use Lab 5.0 as a reference/model for your own testing!
  * For floating point numbers: *build in a tolerance*

```c
int a = 10, b = 20;
//perfectly fine:
if(a == b) {
  //do something
}

double x = 1.0 / 3.0;
double y = 1.0;
if(x * 3.0 == y) {
  //is this likely to be true?
  //no, that's not how floating point numbers work
}

//instead:
//if the absolute value of the difference of x and y is
// small, then its close enough
if( fabs(x - y) < 0.0000001) {
  printf("close enough\n");
}
```

Midterm Course Evaluations:
  * Open Monday

```text





```
