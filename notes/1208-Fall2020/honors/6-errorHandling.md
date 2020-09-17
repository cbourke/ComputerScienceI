
# CSCE 155H - Computer Science I - Honors
## Error Handling
### Fall 2020

* Errors can either be completely unexpected or anticipated but not normal
* Some errors, are, by nature *fatal*; the program, in general, *should* die in some cases
* Some errors you *can* recover from (you can anticipate them and not perform the dangerous operation and instead move on in some way)
* This is known as *error handling*: how you "handle" the errors when encountered

1. Defensive Programming: "look before you leap"
  * You write code to detect potentially bad/dangerous operations before they occur
  * If they would occur, you don't do them
  * Instead, you return an *error code* from the function and let the calling function *handle* the error (it decides what to do)
  * It is the calling function's responsibility to decide what happens
  * By convention 0 is associated with "no error"
  * Non-zero values indicate a particular type of error
2. Exceptions
  * "Modern" programming language support exceptions
  * Go ahead and leap before you look; if you fall, we'll `catch` you and let you recover
  * You can write exceptions using a `try` keyword (you "try" the dangerous operation), and the code may `catch` an exception
  
## Defensive Programming in C


* In C, you design functions such that the actual return values are communicated using pass-by-reference variables
* This frees up the return value to be an error code: an integer that indicates the *type* of error encountered
* In general: zero indicates no error
* In general: don't use magic numbers (mysterious numbers that have no apparent meaning): it makes your code unreadable and unmaintainable 

### Solution to Magic Numbers: Enumerated Types

* Many pieces of data have small or limited number of possible values
* Example: days of the week, months, error codes
* In C, you can define an *enumerated type* and give predefined, human-readable names to them

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

* Style:
  * `CAPITAL_UNDERSCORE_CASING` for elements
  * `UpperCamelCasing` for the name
  * Generally whitespace doesn't matter, but it is good to put one to a line
* Syntax: 
  * Use `typedef enum`
  * Comma delimited list inside curly brackets
  * Name of the type at the end with a semicolon
  * Generally they are declared in header files
* Later in the program...

```c
DayOfWeek today = THURSDAY;
DayOfWeek tomorrow = THURSDAY + 1;
DayOfWeek foo = MONDAY + 500;//has the value 501
```

* In C, all enumerated types are actually integers
* The first item in the list gets the value 0 by default, each one after is incremented by 1 (`SUNDAY = 0, MONDAY = 1, SATURDAY = 6`)
* BE CAREFUL, do not use enumerated types in numerical expressions, only for setting/conditionals

```text






```