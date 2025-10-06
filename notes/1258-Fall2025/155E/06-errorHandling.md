
# CSCE 155E - Computer Science I
## Error Handling
### Fall 2025

* Programs always have potential for errors
* Some errors can be unexpected
* You may be able to anticipate errors and *protect* your program against them
  * You write code to test for error conditions and deal them or "handle" them
  * Sometimes errors can be *fatal*: they can kill the program
* For C our general strategy will be *defensive programming*
  * "Look before you leap"
  * You check for bad conditions and *don't* do the potentially dangerous operations
  * If you are about to do something potentially dangerous you check for any "bad" or "error" conditions
* Inside a function: you check for conditions
  * If there are error conditions, you *immediately* return to the calling function
  * But also: you communicate to the calling function that an error occurred
  * The way you do this: the return value (integer to indicate a type of error)
  * By convention: 0 = no error
  * 1, 2, 3, etc. indicate errors of various types
* **Bad** error handling:
  * You do *not* print anything in the function
  * You do *not* quit/exit the program (this takes any design decisions away from the programmer using your functions/library)
  * (the only time you would ever `exit()` is in the `main`)
* Observations
  * `NULL` pointer checks are *always* done first
  * Failure to check for `NULL` pointers may result in a seg fault (*dereferencing a null pointer*!!!  Remember Bret Hart)
  * Again: do not print anything, do not exit, only communicate the error type/condition to the calling function

## C Enumerated Types

* Many pieces of data have a fixed number of limited possible values
* Ex: days of the week, months in the year, error codes
* In C you can define an enumerated type with human-readable "terms" as your possible values


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

...

DayOfWeek today = FRIDAY;
DayOfWeek tomorrow = SATURDAY;
if(today == SATURDAY) {
  printf("football!\n");
}

...
//careful:
today = SATURDAY;
today += 1; //7, invalid!
```

* Careful: these are not actual types
* C is simply using integer placeholders automatically assigned to each value (starting at 0)
* `SUNDAY = 0`, `MONDAY = 1`, etc. `SATURDAY = 6`
* Consequence: you can **mis**treat them as integers
* but don't do this
* Best practice: if you are going to use enumerated types, use them properly
* Observations: style
  * Use `UPPER_UNDERSCORE_CASING` for values
  * Use `UpperCamelCasing` for name types (`DayOfWeek, ErrorCode`, etc)
  * One item per line, separated by commas inside curly brackets
  * At the end: you provide the name and a semicolon
  * Generally you declare `enum`s in a header file

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
