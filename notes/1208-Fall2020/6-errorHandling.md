
# CSCE 155E - Computer Science I
## Error Handling
### Fall 2020

* Programs always have potential for errors
* Some errors can be unexpected
* Many errors *can* be anticipated and protected against
  * We can anticipate and write code to *handle* those errors
  * Or we can let the errors be *fatal*
* In C our general strategy will be *defensive programming*
  * Identify potential errors that could cause problems
  * Write code to *look before you leap*: check for potential error conditions before you perform potentially dangerous operations
  * You then (in some way) report an error back to the calling function
  * We'll do this through integer values called *error codes*
  * By convention zero will be associated with no error
  * Non-zero (positive) values will be associated with various different types of errors
  * Now that we have pass-by-reference functions, we can use the return value to communicate error codes back to the calling function!
* Common mistakes:
  * You do NOT echo/print an error message inside a function!
  * You do *not* generally make errors inside a function fatal (you don't call `exit()`)
  
## How C does system-level error handling

* The POSIX standard actually only defines 3 error codes:
  * `EDOM`: indicates an error in the *domain* (the input) of a function call; Example: `sqrt(-1)`
  * `ERANGE`: indicates an error in the *range* (the output) of a function call; Example: `log(0)`
  * `EILSEQ`: illegal byte sequence (rarely seen)
  * Each one of these is defined in `errno.h` (error number)
  * In the event of one of these errors, a global variable, `errno` is set with one of those three possible values

## C Enumerated Types

* Many pieces of data have a fixed and limited number of possible values
* Example: Days of the week, months, error codes
* In C you can define an enumerated type to hold human-readable "terms" for your list of possible values
* Example:

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

* Observations:
  * Use `UPPER_UNDERSCORE_CASING` for list items
  * Use `UpperCamelCasing` for the names of the enumerated type
  * One per line
* Later on in your program...

```c
DayOfWeek today = MONDAY;
DayOfWeek nextLecture = WEDNESDAY;
```

* Other notes:
  * You use `typedef enum` to define it, the provide a comma-delimited list of items inside curly brackets
  * Semicolon at the end of a declaration.
  * Generally, you declare enumerated types inside a header file
  
## How does this actually work

* Internally, C assigns `int` values to each element in the list starting with (default) 0
* Example above: `SUNDAY` has a value 0, `MONDAY` has a value 1, etc.  `SATURDAY` has a value 6
* Consequently, you can really screw things up

```c
DayOfWeek when = MONDAY + TUESDAY;
when = when + 50;
```

* Take away: understand that enumerated types are integers, but DO NOT TREAT THEM like integers
* But you CAN use them in expressions:

```c
if(today == SATURDAY) {
  printf("We can watch football!\n");
}
```



```text





```