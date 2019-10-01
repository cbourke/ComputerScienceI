
# CSCE 155E - Computer Science I
## Error Handling
### Fall 2019

* Reconsider a program to compute quadratic roots...
* Programs always have potential for errors
* Some errors can be unexpected
* Many errors can be *anticipated*
  * We can anticipate and write code to *handle* those errors
  * Or we can let those errors be *fatal*
* In C our general strategy will be *defensive programming*
  * Identify potential errors that could cause problems
  * Write code to *look before you leap*: code will check for those error conditions before it performs potentially dangerous operations
  * You (in some way) report an error back to the calling function
  * The way we'll do this is through *error codes*
  * Now that we have pass-by-reference functions, we don't need the return value!
  * We can now use the return value to indicate an error code (usually an integer) to indicate the *type* of error that was encountered
* In general:
  * You do *not* echo (print) an error message in a function
  * You do *not* make most errors fatal (you do not call `exit(1)` on everything!)
  
* Example: redesign the roots demo to use error handling

## How C does system-level error handling

* The POSIX standard actually only defines 3 error codes:
  * `EDOM`: indicates an error in the *domain* of a function; example: `sqrt(-1)` (ie an error in the input)
  * `ERANGE`: indicates an error in the *range* of a function (ie the output); example: `log(0)`
  * `EILSEQ`: illegal byte sequence
  * Each is defined in `errno.h` (error number)
  * In the event of one of these errors, a global variable named `errno` is set with one of the three possible values

## C Enumerated Types

* Many piece of data have a fixed and limited number of possible values
* Example: months, days of the week, etc.
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

//later on...
DayOfWeek today = MONDAY;
DayOfWeek tomorrow = TUESDAY;
```

Syntax and style notes:
* You use `typedef enum` (type definition, enumeration) and opening/closing curly brackets, placing the list of elements in a comma delimited list
* Name of the enumerated type uses `UpperCamelCasing`, each element uses `UPPER_UNDERSCORE_CASING`
* Generally whitespaces doesn't matter, but all the commas are necessary (except the last, which is suggested)
* List is one element per line
* You end the declaration with the name of the enumerated type and a semicolon

## How this works

* Internally, C assigns integer values to each element in the list starting (default) with 0
* Ie in the example, `SUNDAY` has a value of 0, `MONDAY` has a value of 1, etc.  `SATURDAY` has a value of 6
* Consequently, you can screw up enumerated variables

* Example:

```c
//when will have a value of...WEDNESDAY
DayOfWeek when = MONDAY + TUESDAY;
when = MONDAY + 50; //invalid
when = -10; //invalid

//you CAN test against valid values:
if(today == SATURDAY) {
  printf("Yet another game day?\n");
}
```

* Understand that the actual representation is an integer, but don't treat it like an integer
* You *can* do some basic arithmetic
```c
day = MONDAY + 1; //would be TUESDAY
day = SATURDAY + 1; //invalid
day = (SATURDAY + 1) % 7; //SUNDAY
```

* Demonstration: incorporate enumerated types in our root demo
* In general, enumerated types are defined in header files!


