
# Computer Science I
## ECEN 194 - Fall 2022
### Review: functions, pointers, pass-by-reference, error handling

* Pointers:
  * `int x;` a regular old variable
  * `int *a;` is a pointer variable
  * If you have a regular variable and you want to make it into a pointer: use the referencing operator: `&x`
  * If you have a pointer variable and you want to make it into a regular variable: *de*referencing operator: `*a`
* Passing-by-value:
  * *COPIES* of the variable's values are passed to the function
  * Any changes to those parameters *do not affect* the original variables
* Pass-by-reference:
  * *pointers* or memory locations are passed to the function
  * Any changes via the pointers *do affect* the original variables
  * Use cases:
    * You can "return" multiple values
    * It frees up the return value for error handling
* Error Handling:
  * Look before you leap
  * Error handling in a function is the ***absolute first thing you***
  * Null pointer checks come first: they are the first of the first
  * You do NOT:
    * print anything
    * Exit the program
  * YOu return an error code:
    * an integer
    * zero for no error
    * non-zero for some type of error
  * You can use an enumerated type to use human-readable words for error codes
* Tips:
  * You NEVER EVER include source files!
  * Generally you should avoid dereferencing too much: if you want to set a value, dereference it ONCE at the end of the function; use temporary variables instead!
