
# CSCE 155E - Computer Science I
## Functions
### Fall 2022

Introduction to functions in C

* A *function* is a reusable ***unit*** of code that may take *input(s)* and *may* produce an *output*
* Similar
  $$f(x) = x^2 + 4$$
* Observe:
  * Name? $f$
  * Input? $x$
  * $f(x,y)$, $f(x,y,z)$
  * Output?  $y = f(x)$
* How many outputs can a "function" have?
* Some functions in C: `main()`, `sqrt()`, `printf()`
* Why use functions in C?
  * Functions facilitate *code reuse*: you don't copy-pasta pieces of code (cut and paste), instead, you can put that code into a reusable function and then simply "call" or "invoke" the function
  * Procedural Abstraction
    * How does `sqrt()` work?
    * Who cares?  It just works
    * The details are hidden away (abstracted) into the function and we don't have to to worry about it
    * The details are *encapsulated* inside the function
  * Standard and external libraries have a *lot* of functionality that is well-tested, optimized, correct, etc.
    * Don't reinvent the wheel
  * Feeds into an overall engineering strategy: when faced with a problem what is the first question you ask: Is it already solved?

## Functions in C

* As with variables, functions in C have to be *declared* before you can use them
* To declare a function you define a *prototype*
  * A prototype in C is a function's *signature*
  * The function's name
  * The function's inputs (types of variables it takes)
  * The function's output type (the type of variable it computes and *returns*)
* Observations:
  * The prototype is ended with a semicolon
  * For now: your prototypes go above the `main()` (fix this later)
  * You should always document using doc-style comments every function you write
* Once you have created a prototype, you need to provide a function *definition*: the actual code that the function consists of
* Observations:
  * The names of functions should be (generally) verbs: because functions *do things*
  * Good naming convention: `lowerCamelCasing()`
  * The inputs to a function are called *parameters*
  * When you call a function, the function that calls it is the "calling function" and the function called is the "called function"
  * The function executes the code in its body until it reaches the end at which point it `return`s to the calling function
  * IDE Tip: you can hold down command (mac) or control (windows) and click on a function to jump to its code
  * Any variables declared inside a function only exist *in that function*: they are *local* to that function and are not available outside of it (they die at the end of the function)

## Modularity

* Not all function should be in the same source file: bad organization
* Instead they are separated into different files:
  * The prototype + documentation goes into a *header* file with a `.h` extension
  * The definition/implementation goes into a *source* file with a `.c` extension with the same base name
* Demonstration:
  * Included the header file using `#include "finance.h"` anywhere we  needed to (loan.c and finance.c files)
  * We included other headers as needed (math.h)
  * Compiled the "finance" library using the `-c` flag:
  `gcc -c finance.c` which produce an object file containing the actual machine code of our library
  * Compiled everything together using:
  `gcc loan.c finance.o -lm`
* Pitfalls
  * YOU NEVER NEVER NEVER include a source file: `#include "finance.c"` only include header file
* Advanced solution: if you have many source files and a more complex program, it can get very inconvenient to have to recompile *every single time*
* Most languages have some sort of "build system": a second system that:
  * Manages dependencies
  * Track changes so that only changed files get recompiled
  * Provides multiple ways of compiling for different systems, etc.
* For C: the `make` utility or the modern `cmake` utilty are standard (read more about it on your own)

### How Do Functions Work?

* Programs have a *program stack*: its a LIFO = Last In First Out data structure
* In a stack you can add something to the "top" (pushing) or remove something from the "top" (popping), but not in between; you only interact with a stack at the "top"
* Every time a function is called, a new *stack frame* is created and placed on top of the "call stack"
  * All local variables inside a function as well as parameter variables exist only in their *stack frame*
  * When a function is done executing and control is returned back to the *calling function*, it is a simple matter of popping off the stack frame
  * All variables in the stack frame are "destroyed"
  * Consequence: you cannot make changes to variables in the calling function because variables are *passed by value*
  * Copies of the values of the variables are given to the function!

## Unit Testing

* A *unit* is a piece of code (usually a function) that can be tested
* In general: it is an indivisible piece of code so that you can test it in *isolation* of all other code
* A unit test is an input-output pair that is known to be correct
* We unit test by feeding the input into our unit (function) and comparing the result to the *known correct* output: actual vs the expected
  * If they match: PASSES!
  * If it doesn't: it FAILS!
* Grouping multiple unit test cases together gives you a *test suite*
* If a future bug is reported: we have a new test case!
* A future change to the code may cause unit tests that passed before to now fail: this is a *regression*
* Tests should be automated and repeatable
* The more tests you have the higher certainty you have that your code is correct
* No matter how many test you have you never have a *proof* that your code is correct
* The more test cases you have the better *code coverage* you have
  * We want to test corner cases
  * Edge cases, extremal cases
  * Randomized testing/fuzzing
* Problems:
  * a lack of code coverage
  * *false positives*: when a test case is wrong but the code is correct
  * A *false negative*: when there is a bug in your program but your test suite does not indicate it
* TDD = Test Driven Development
  * Generally: you write your tests before the code

* Demo:
  * *informal* unit testing in C
  * Later (Lab 6, Hack 6): you will use a more formal unit testing framework : cmocka

## C: Pointers

* Recall that our `swap()` function failed due to *how functions work* (demo)

```c

void swap(int a, int b) {
  printf("a, b = %d, %d\n", a, b);
  int temp = a;
  a = b;
  b = temp;
  printf("a, b = %d, %d\n", a, b);
}

int main(int argc, char **argv) {

  int a = 10;
  int b = 20;

  printf("a, b = %d, %d\n", a, b);
  swap(a, b);
  printf("a, b = %d, %d\n", a, b);

  return 0;
}
```

* The values of the variables `a, b` are passed to the function: *copies* of the variable values are passed, not the variables themselves
* Inside the function: the swap only applies to the *copies* not the originals
* This is known as "passing by value": values of the variables are copied onto the call stack and passed to the function
* Changes to the copies have no effect on the original variables in `main()`!
* BUT: I *REALLY* want to swap variables

### Pointers

* Everything (in particular data) in a computer is stored in memory
* Memory has two parts: an address and contents
* Regular old variables correspond to the contents
* Pointer variables can hold an *address* or memory location or "reference"

* OBserve:
  * You can take a regular old variable and gets its memory address (pointer) using the referencing operator: `&`
  * You can take a pointer variable and change it to a regular variable using the dereferencing operator `*`

```c

  //you can create regular old variables:
  int a = 42;
  double pi = 3.1415;

  //create a pointer variable that can point to an integer:
  // pointerToA is a pointer to an integer, NOT an integer itself
  int *pointerToA;
  //by default, there is no value associated with uninitialilzed variables
  //you can make a pointer point to "nothing"
  pointerToA = NULL;

  if(pointerToA == NULL) {
    printf("ERROR: cannot access taht memory\n");
  }

  //we want to make pointerToA actually point to the variable a:
  //ampersand in front of a regular old variable gets the *memory address* of that
  // variable!
  pointerToA = &a;


  printf("a is regular old variable, it holds the value %d\n", a);
  printf("pointerToA is a pointer and has the value... %p\n", pointerToA);
  printf("the memory location %p holds the value %d...\n", pointerToA, a);

  //once you have a pointer to a memory location you can manipulate
  // the contents of memory through the pointer
  //you can take a pointer variable and turn it into a regular old variable
  // *temporarily* so you can set or modify its contents (or access them):
  // to dereference: use the star operator
  *pointerToA = 10;
```

* Observations:
  * Using pointers allows us to *pass by reference* to functions
  * Instead of copies of values, we can pass in memory locations/addresses and a function can manipulated the original variables
  * Now our `swap()` function works!
  * Remember: `scanf()` required that you use the ampersand to pass in a variable: why?
  * Passing by reference means that you can give a function a "bucket" in which to put a result (like `scanf`) rather than a copy of a value that is not useful

## Pitfalls

* You should always initialize a pointer (to `NULL` if nothing else)
* otherwise, uninitialized pointers may point to anything!
* You do not assign a literal value to a pointer: `int *ptr = 101;` this makes it point to memory location 101 which likely does not belong to you, resulting in a seg fault
* Integer pointers should point to integers, `double` pointers should point to `double`s or you get weird undefined behavior

### Summary of Pointers

  * A pointer is a memory address or a *reference* to a memory address
  * A pointer variable can be declared using the star operator: `int *ptrToA`
  * It is best to initialize pointers or at least make them point to `NULL`
  * To make a pointer variable into a regular old variable use the `*` (*DE* reference it)
  * To make a regular variable into a pointer (memory address) use the `&` (*REF*erence it)
  * Don't make pointers point to things they shouldn't point to

## Using Pointers: Passing By Reference

* `scanf()`: you use the ampersand, `&` to pass a variable by reference so that the function can manipulate it
* With pass by reference you can "return" multiple values
* Even if you only have one result, it still is *might* be a good idea to use pass-by-reference...
* Freeing up the return value means that you can do proper *error handling* in C


```text






```
