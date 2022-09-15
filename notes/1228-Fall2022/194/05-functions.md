
# ECEN 194 - Computer Science I
## Functions
### Fall 2022

Introduction to functions in C

* A *function* is a reusable ***unit*** of code that may take *input(s)* and *may* produce an *output*
* Similar
  $$f(x) = x^2 + 4$$
* The input is $x$ the "name" of the function is $f$ and the output is... $f(x) = y$
* Function with multiple inputs (multivariate functions):
  $$f(x,y), g(x,y,z)$$
* How many outputs can a "function" have?
* Likewise in code, you can have any number of inputs (including zero) but ONLY every 1 output (at most)
* In code the output value is `return`ed from the function
* Some functions in C: `main(), sqrt(), printf()`
* Functions facilitate *code reuse*: you don't copy-pasta pieces of code (cut and paste), instead, you can put that code into a reusable function and then simply "call" or "invoke" the function
* Procedural Abstraction:
  * How does `sin()` work in C or on your calculator: who cares?  It Just Works
  * We want to use the function and its functionality and not have to worry about the details
  * IF we have to *implement* a function, THEN we worry about the details, but once written, we're done worrying about the details
  * The details are *encapsulated* inside the function and we don't have to worry about it
* Standard Library Functions:
  * Don't have to reinvent the wheel
  * They are very well tested, optimized, efficient, well designed etc.
* The best engineering: when faced with a problem, what is the first question you should ask?  Did someone else already solve it?

## Functions in C

* As with variables, functions in C have to be *declared* before you can use them
* You *declare* a function by defining its *prototype*
* A prototype in C is the *signature* of the function
  * It is the name of the function
  * It is a list of parameters or inputs the function takes
  * It is a return value *type*: the type of variable the function returns (if any)
* Terminology:
  * When you "call" a function you *invoke* it (the code jumps into the function and executes code inside that function)
  * The function that "calls" a function is the *calling function*
  * When code in the function is done executing it *returns* to the calling function
* Example: write a function prototype for a function that computes the monthly payment of a loan
* Observations:
  * For now, we'll put our prototypes before the `main()` function (later we'll *modularize* our code into separate files)
  * The prototype ends with a semicolon `;`
  * You should *always* provide doc-style comments as documentation for every function
* After you have defined a prototype, you need to provide a *definition*: what the function actually does (what code is executed with the function is called)

* Observation:
  * C does not support "function overloading": no two functions may have the same name
  * This is why the math library has `abs, fabs, labs, llabs`, etc.
  * Consequently: you need to be very careful about the naming of your functions
  * Example: suppose you wanted to use two libraries, $A, B$, suppose both had named a function `init()`
  * Creating functions with "common" names *pollutes the namespace*: once you have a function `init()`, no other library or you may redefine the function `init()`
  * It is common for libraries to prepend their functions with a unique name: `gtk_init()`

## Create a Library: Modular Organization

* Collect common functionality (functions, variables, etc.) into a "module": a collection that is distinct and separate from other collections
* Simple organization
* How:
  * Prototypes and their documentation are separated into a *header* file with an extension of `.h`
  * Definitions are placed into a *source file* usually with the same name but an extension of `.c`
  * You should use the `#include "financial.h"` syntax to "include" a header file anywhere you intend to use the function declared in that file: note the diffrence, double quotes, not lange/rangle
  * To compile:
    1. To compile without linking, you use the `-c` flag;
    `gcc -c financial.c`
    2. This produces an object file, `financial.o` (machine language language file, binary)
    3. To compile all together: use
    `gcc loan.c financial.o -lm`
* If you want to, you can explore full *build systems*: `make`

## Misc

* A function that doesn't return anything is a `void` function: its return type is `void` and its return statement is `return;`
* You can have functions that do not take any input: `void printMenu()`

```text












```
