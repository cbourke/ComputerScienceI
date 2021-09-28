
# CSCE 155E - Computer Science I
## Error Handling
### Fall 2021

* Programs always have potential for errors
* Some errors can be unexpected
* Many errors *can* be anticipated and protected against
  * We can anticipate and write code to *handle* those errors
  * Or sometimes we let errors be *fatal* errors
* In C our general strategy will be *defensive programming*
  * "Look before we leap"
  * If we are about to perform a potentially dangerous or invalid operation, we check and if so, then we don't do it, we do something else
  * Generally if an error occurs in a function you:
    * DON'T QUIT out of the program
    * Instead, you report the error back to the calling function
    * It is the calling function's responsibility to determine *how* the error gets handled
* Generally, errors are reported back to the calling function using *error codes*
  * Error codes are integers
  * 0 generally indicates *no error*
  * non-zero error codes indicate *some kind of* error
  * The actual value can be used to determine what *kind* of error occurred
  * Each different kind can be handled differently
  * So what about actual outputs to functions?  
  * You can use a pass-by-reference variable to return any actual result!
* Common mistakes:
  * You do NOT echo/print an error message inside a function!
  * You do *not* generally make errors inside a function fatal (you don't call `exit()`)
* Demonstration: modify our loan function(s) to do some basic error handling

$$P = \frac{rate \times principle}{1-(1+rate)^{-n}}$$

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
DayOfWeek today = WEDNESDAY;
DayOfWeek nextLecture = MONDAY;
```

* You use `typedef enum` to define it, you provide a comma-delimited list of items inside curly brackets
* A semicolon is necessary at the end of the name of the enumerated type
* You generally declare enumerated types in a header file.

## How does this actually work

* Internally, C assigns an `int` value to each element starting with zero (default)
* `SUNDAY` has a value of zero
* `MONDAY` has a value of 1
* `SATURDAY` has a value of 6
* Consequently you *can* but really shouldn't do:

```c
DayOfWeek when = MONDAY + TUESDAY;
when = MONDAY + 50;
```

* Take away: understand that enumerated types are integers, but DO NOT TREAT THEM like integers
* But you CAN use them in expressions:

```c
if(today == SATURDAY) {
  printf("We can watch football!\n");
}
```

## Exercises

* Design (and rigorously test) a function to compute the amount of change: given a dollar amount in the range 0 thru .99 and "outputs" the number of quarters, dimes, nickels and pennies to make change.
* Rigorous testing = automated, unit testing
  * A *unit* in coding is simply some indivisible piece of code: it could be a snippet, it could be an entire module or library
  * USUALLY: our unit is a function
  * A unit test is a triple: input, expected output and an actual output
  * Your code *passes* the unit test if the expected output "matches" the actual output
  * Generally the expected output is computed using *some other means*: your calculator, an online resource,
  * You can have *false positives*: your test passes but your code is actually wrong
  * You can have *false negatives*: your test fails but your code is actually correct (your test may be wrong)
  * Unit testing never provides 100% assurance that your code is correct, only a high-degree of certainty
  * The more tests you have, the more certainty you have
  * Tests should also *cover* your code well: 

```c


```
