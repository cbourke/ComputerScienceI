
# CSCE 155E - Computer Science I
## Error Handling
### Fall 2026

* Programs always have potential for errors
* Some errors can be unexpected
* You may be able to anticipate errors and *protect* your program against them
  * You write code to test for error conditions and deal with them or "handle" them
  * Sometimes errors are *fatal*: they can kill the program
* For C our general strategy will be *defensive programming*
  * "Look before you leap"
  * You check for bad conditions and *don't* do the potentially dangerous operations
  * If we are about to do something "dangerous", we instead issue an error code
* Inside a function: you check for conditions
  * If there are error conditions, we *immediately* return to the calling function
  * But also: we return an error code
    * It is a non-negative integer
    * It indicates the *type* of error
    * Convention: 0 = no error, 1, 2, 3, etc. are different types of error
* **Bad** error handling:
  * You do **NOT** print anything!
  * You do *not* quit/exit the program (this takes any design decisions away from the programmer using your functions/library)
  * (the only time you would ever `exit()` is in the `main`)
* Observations
  * Error checking/handling is ALWAYS the first thing you do in a function
  * Generally `NULL` pointer checks are the first type of error you check for
  * Failure to check for `NULL` pointers may result in a seg fault (*dereferencing a null pointer*!!!  Remember Bret Hart)
  * Again: do not print anything, do not exit, only communicate the error type/condition to the calling function
  * REmember to return 0 for no error
  * Sometimes: you may have a `void` function; so you can still do error handling, just no error codes: you simply return without doing anything

## C Enumerated Types

* Many pieces of data have a fixed number of limited possible values
* Ex: days of the week, months of the year, error codes!
* In C you can define an enumerated type with human readable "terms" as your possible values

```c
typedef enum {
  SUNDAY,
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY,
} DayOfWeek;
```

* Later on you can use this defined type:

```c
DayOfWeek today = FRIDAY;
DayOfWeek tomorrow = SATURDAY;

if(today == SATURDAY) {
  printf("Game Day!\n");
}

```

* Be careful: internally, C assigns integer values for these items
* `SUNDAY = 0`, `MONDAY = 1`, etc.  `SATURDAY = 6`
* Ie they are all integers, BUT you should not treat them like integers

```c
DayOfWeek today = SATURDAY;
today += 1; //today = 7, which is invalid
today = (today + 1) % 7; //results in SUNDAY

```

* Observations: style
  * Use `UPPER_UNDERSCORE_CASING` for values
  * Use `UpperCamelCasing` for name types (`DayOfWeek, ErrorCode`, etc)
  * One item per line, separated by commas inside curly brackets
  * At the end of the `enum`: define the name of the `enum` + semicolon
  * Generally, enumerated types are declared in a header file

## How does C do error handling?

* Internally C defines only 3 types of errors
* It defines them in the `errno.h` library
  * `EDOM` - an error in the *domain* of a function (input)
  * `ERANGE` - an error in the *range* of a function (output)
  * `EILSEQ` - an illegal byte sequence
* Generally you will *not* use this library directly
* There are other standards that define *more* error codes:
  * POSIX = Portable Operating System Interface
  * Various other extensions
* In "user land" (our programs), you generally need to define your *own* error codes and enumerated, etc.

```text












```
