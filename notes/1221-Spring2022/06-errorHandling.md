
# Computer Science I
## ECEN 1940 - Spring 2022
### Error Handling & Unit Testing


* Programs always have potential for errors
* Some errors can be unexpected
* Some can be anticipated and protected against
  * We can anticipate bad situations and *handle* those errors
  * Some errors may be *fatal*: we want the program to die in such an event
* In C our general strategy will be *defensive programming*
  * Look before you leap
  * Check for error conditions before we execute some potentially "dangerous" code
  * If you are about to perform some invalid or dangerous operation, then you don't do it; instead you communicate some sort of error back to the calling function
* Other modern programming languages use full exception handling
* What we *don't* do:
  * We don't quit!  Don't use `exit(1)` in any function other than `main()`
  * You don't echo error messages `printf("ERROR")`
* You don't do the dangerous operation, instead you return an integer error code indicating the *type* of error
  * Generally, zero is "no error"
  * Also: you *may* want to avoid magic numbers!

## Enumerated Types

* An enumeration is an ordered list of things
* In C, you can define an *enumerated type*

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

* We use `typedef enum` to define an enumerated type
* Provide a name for the type at the end and end it with a semicolon
* Style: use `UpperCamelCasing` for the type name; use `UPPER_UNDERSCORE_CASING` for the values
* Each value has (internally) an integer value, which starts at zero
* The list is delimited by commas, generally one item per line
* Be careful: because these are integers, you can treat them like integers

```c
DayOfWeek today = WEDNESDAY;
if(today == FRIDAY) {
  printf("lab!\n");
}

//you can, but don't:
today = today + 10;

```

## Unit Tests

* A *unit* is a piece of code (usually a function) that can be tested
* A unit test is an input-output pair that is known to be correct
* We unit test by feeding the input into our unit (function) and comparing the result to the *known correct* output
* If they match, that unit test passes
* If they do not match, that unit test fails
* a collection of unit tests is known as a test suite
* IF a future bug is reported, then you have a new unit test to debug and test with!
* A future change or fix that breaks other unit tests is known as a regression
* The more tests you have the higher certainty you have that your code is correct
* NO amount of tests will ever guarantee that your code is 100% correct!
* Make sure that you have good "code coverage":
  * You want to test corner cases
  * Edge cases, extreme cases, etc.
  * Randomized tests
* A *false positive* is when a test case is wrong but the code is correct
* A *false negative* there is a bug but your tests do not indicate it: most likely because you didn't write your test case correctly
  * You come up with the expected input/output BEFORE you code
  * TDD = Test Driven Development

```text



```
