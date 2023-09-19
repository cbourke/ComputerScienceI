
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

## Unit Testing

* A *unit* is a piece of code (usually a function) that can be tested
* A unit is an indivisible piece of code that is treated as a "black box": you want to test things in isolation
* A unit test is an input-output pair that is known to be correct
* We unit test by feeding the input into our unit (function) and comparing the result to the *known correct* output: actual vs the expected
  * If they match: PASSES!
  * If they do not match: FAILS!
* Grouping multiple unit tests into one collection gives you a *test suite*
* If a future bug is reported: you have a new test case!
* Tests should be repeatable
* A future change or fix that breaks other unit tests is known as a *regression*
* The more tests you have the higher certainty you have that your code is correct
* No amount of unit testing will give you a 100% guarantee that your code is correct!
* One Goal: provide 100% "code coverage"
  * Example: tax program (lab 3)
  * YOu want *at least* one test case for each possible "computational path"
  * You also want to test: corner cases, edge cases, error cases, etc.
  * Fuzzing: generate random values in an attempt to break your code
* Problems:
  * Lack of code coverage
  * A *false positive* is when a test case is wrong but the code is correct
  * A *false negative* is when there is a bug in your program but your test case(s) do not catch it: they both agree but they are both *wrong*
  * TDD? = Test Driven Development
* Ad-hoc testing: testing as we went using manual input/output
* Informal unit testing: writing your own tests and boilerplate reporting code
* Formal unit testing: you bring in a library to do all of the boilerplate stuff for you

## Misc

* Another advanced topic: `makefile`s
  * For larger projects, building all the code can get *very* complicated
  * You may have dozens of rules and *dependencies* (one file depends on another, that depends on another, etc.)
  * Another language, a *build* system is necessary
  * Build Engineers or "DevOps" (Development Operations)
  * Related: CI = Continuous Integration
* THe `void` keyword
  * You can write functions that take no input
  * You can write functions that give no output: `void`
  * Ex: `void printMenu();`
* Function overloading
  * When you write a function and give it a name, `foo()`
  * That is the ONLY function that can ever have that name!
  * Writing functions *pollutes* the namespace: once you write a function with a given name, you will *conflict* with ANY library you want to use that also defines a fucntion with that name!
  * A lot of libraries will name their functions with a prefix: `gtk_` + function name; ex: `gtk_create_menu()`
  * SOME languages *do* allow you to define multiple functions with the same name (but possibly different parameters/inputs): this is known as "function overloading"
  * C does NOT support function overloading: `abs(), fabs(), labs(), llabs(), fabsf()`
* How do functions actually work?

```text













```
