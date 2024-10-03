
# CSCE 155H - Computer Science I - Honors
## Error Handling
### Fall 2024

* Errors can either be completely unexpected or anticipated but not normal
* Some errors, are, by nature *fatal*; the program, in general, *should* die in some cases
* Some errors you *can* recover from (you can anticipate them and not perform the dangerous operation and instead move on in some way)
* This is known as *error handling*: how you "handle" the errors when encountered

1. C: Defensive Programming: "looking before you leap"
  * You write code to detect potentially dangerous or bad operations before they occur
  * Instead of executing that code (dangerous operation) you stop and if in a function:
    * YOU return an *error code*: an integer indicating a *type* of error
    * YOU do NOT:
      * print any error message
      * You do NOT exit
    * Convention: 0 = no error, non-zero: some kind of error (1, 2, 3, etc.)
2. Java: exceptions, it is okay to leap before you look because if something bad happens, we will `catch` you and `throw` you back up

## Defensive Programming in C

* In C, you design functions such that the actual return values are communicated using pass-by-reference variables
* This frees up the return value to be an error code: an integer that indicates the *type* of error encountered

### Standard Libraries: `errno.h` library

* errno = error number

### Solution to Magic Numbers: Enumerated Types

* Many pieces of data have small or limited number of possible values
* Example: days of the week, months, error codes
* In C you can use an *enumerated type* and give a predefined list of valid, human-readable values to them

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

DayOfWeek today = WEDNESDAY;
if(today == FRIDAY) {
  printf("get ready for the weekend!\n");
}
```

* Careful: the way C does this is by associating the values with integer types (starting at zero)
* `SUNDAY = 0`, `MONDAY = 1`, ... `SATURDAY = 6`
* Consequences:

```c
DayOfWeek today = WEDNESDAY;
today += 1; //okay, now it is Thursday
today = SATURDAY;
today += 1;

```

* Style:
  * `CAPITAL_UNDERSCORE_CASING` for elements
  * `UpperCamelCasing` for the name
  * Generally whitespace doesn't matter, but it is good to put one to a line
* Syntax:
  * Use `typedef enum`
  * Comma delimited list inside curly brackets
  * The name of the type was at the end + semicolon
  * Generally you declare these things in a header file
  * Note: the coding oxford comma!

* Java also has enumerated types
  * Key difference: they are *NOT* integers


```text









```
