
# CSCE 155E - Computer Science I
## Functions
### Fall 2023

An introduction to functions in C.

* A *function* is a reusable unit of code that may take *input(s)* and *may* produce an *output*
* Similar to math functions:
  $$f(x) = x^2$$
  * Function name: $f$
  * Input: $x$ (there is only one), $f(x, y)$, $f(x, y, z)$
  * The function "returns" the value $y = x^2$, $y = f(x)$
* Already seen a lot of functions: `sin(), sqrt(), pow(), printf(), main()`
* Functions facilitate *code reuse*: you don't have to copy-pasta code (cut and paste code), instead you can put that code into a function, and simply use and reuse the function
* DRY Principle = Don't Repeat Yourself
* Procedural abstraction:
  * How does the `sqrt()` function work?
  * Who cares?  You simply want to utilize the functionality!
  * It abstracts the details away so we don't have to worry about them!
  * It reduces *our* cognitive load
  * The details are *encapsulated* inside the function and we don't have to worry about them!
* Feeds into an overall approach to problem solving:
  * Is it already solved?  Is there a function that does it for me already?
  * Don't reinvent the wheel, "don't roll your own"
  * Can an "off the shelf" solution be *adapted* to solve our problem
* Standard libraries and *external* libraries provide useful functions that have a lot of testing, debugging, and optimization behind them: USE IT!

## Functions in C

* As with variables, functions in C have to be *declared* before they can be used
* In C you "declare" a function by creating a *prototype*
* A function prototype defines a function's *signature*
  * The name of the function (its identifier)
  * The input(s) to the function and their types
  * The return *type*: the type of value it returns (`int`, `double`, etc.)
* After you have a prototype, you can *use* the function
* BUT the prototype does *not* define what the function actually does
* A function's *definition* is provided later
  * The prototype has a semicolon at the end, but a definition doesn't
  * Instead, you have opening/closing curly brackets and a *function body* in which you place the code that gets executed when you "call" the function (or: "invoke" the function)
  * The function body computes a result and `return`s it to the calling function (ie you use the `return` keyword to return a value)
* Observations:
  * You should have doc-style comments (documentation) for *every* prototypes (NOT definition)
  * Observation: any variable declared inside of a function has a *local scope*: it only exists inside that function, not outside nor in other functions
  * Not only does our function provide new functionality, it illustrates code reuse itself: a function can call a function (`roundToCents` calls `round`)

## Creating a Library: Modularity

* Demonstration: let's separate our "financial" related functions into a separate "finance" library of "utilities"
* You separate code out into multiple files to avoid one "god" file with thousands or millions of LoC = Lines of Code
* It allows you to *organize* code: finance stuff goes in the finance library, custom math stuff goes in a custom math library, etc.
  * Prototypes and documentation goes into a *header* file with a `.h` extension
  * Definitions go into a *source* file with the same *base name* but with a `.c` extension
  * You then use `#include "my_library.h"` wherever you want to use the functions in that library
  * To compile: you compile in phases
    * To compile the library: use `-c` flag; `gcc -c finance_utils.c` (which produces an *object* file `finance_utils.o`)
    * To compile everything together you include the object file:
    `gcc finance_utils.o loan.c -lm`

```text









```
