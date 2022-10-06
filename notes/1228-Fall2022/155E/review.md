
# Computer Science I
## CSCE 155E - Fall 2022
### Review: functions, pointers, pass-by-reference


* Pointers
  * `int x;` a regular old variable
  * `int *a` a pointer variable
  * If you have a regular variable and you want to transform it into a pointer: referencing operator `&x`
  * If you have a pointer variable and you want to transform it into a regular old variable: *de*reference: `*a`
* Pass-by-value
  * *copies* of the variables' values are passed to the function
  * Any changes to those parameter variables *do not affect* the original variables
* Pass-by-reference
  * *pointers* to the variables are passed to the function
  * Changes via the pointers *do affect* the original variables
  * You can use pass-by-reference variables to "return" multiple values
  * It frees up the return value to communicate error codes
* Error Handling
  * LOOK BEFORE YOU LEAP
  * Error handling is the ***FIRST*** thing you do
  * When error handling, `NULL` pointer checks are the first you do
  * Otherwise: Bret Hart will come and knock you upside the head
  * You do *not*:
    * Print anything
    * Exit the program
* Tip:
  * Only set pointer values once at the end of the function; use temporarily variables
  * This reduces the number of potential failure points
  * YOU NEVER NEVER NEVER include source files: THIS IS BAD: `#include "foo.c"`
