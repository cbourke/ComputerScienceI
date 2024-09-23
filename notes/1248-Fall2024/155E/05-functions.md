
# CSCE 155E - Computer Science I
## Functions
### Fall 2024

An introduction to functions in C.

* A *function* is a reusable unit of code that may take *input(s)* and *may* produce an *output*
* Similar to math functions:
  $$y = f(x) = x^2$$
  * $x$ is the input
  * $y$ is the output
  * The *name* of the function is $f$
  * Input: $x$ (there is only one), $f(x, y)$, $f(x, y, z), f()$
  * A function can only ever return at most one thing
* Already seen a lot of functions: `sin(), sqrt(), pow(), printf(), main()`
* Functions facilitate *code reuse*: you don't have to copy-pasta code (cut and paste code), instead you can put that code into a function, and simply use and reuse the function
* DRY Principle = Don't Repeat Yourself
* Procedural abstraction:
  * How does the `sqrt()` function work?
  * Who cares?  You simply want to utilize the functionality!
  * It abstracts the details away so we don't have to worry about them!
  * It reduces *our* cognitive load
  * The details are *encapsulated* inside the function and we don't have to worry about it!
* Feeds into an overall approach to problem solving:
  * When faced with a problem: what is the first quesiton you should ask?
  * Is it already solved? Does a function already exist for me to use
  * Or: can I *adapt* a function in order to solve this problem
* Standard libraries and *external* libraries provide useful functions that have a lot of testing, debugging, and optimization behind them: USE IT!

## Functions in C

* As with variables, functions in C have to be *declared* before they can be used
* In C you "declare" a function by writing a *prototype*
* A prototype is a function signature followed by a semicolon
  * The name or identifier of the function
  * The return type of the function (the type of variable it returns)
  * The inputs: *parameters*, *arguments*, *inputs*
* After you have a prototype, you can *use* the function
* BUT the prototype does *not* define what the function actually does
* Later you provide a function *definition*: what the function does
  * You repeat the signature
  * Instead of a semicolon, you provide a function *body* within `{}`
* Everytime you "call" or "invoke" that function, the code inside that body executes
  * The function body computes a result and `return`s it to the calling function (ie you use the `return` keyword to return a value)
* Observations:
  * You should always use doc-style comments on the function *prototype*,
  * DRY: documentation should not be duplicated on the function *definitions*
  * Observation: any variable declared inside of a function has a *local scope*: it only exists inside that function, not outside nor in other functions

## Creating a Library: Modularity

* YOu want to separate utility functions into their own files
  * Prototypes + documentation will be placed in a *header* file `.h`
  * The definitions are placed in a source file with the same base name + `.c`
* Demonstration:
  * separate our "financial utility functions" into a separate library
  * `financial_utils.h`
  * `financial_utils.c`
    * Add an `#include "financial_utils.h"` to include the prototypes (use double quotes for user defined libraries)
  * In our "main" source file: `loan.c`
    * You `#include "financial_utils.h"` file
  * To compile:  
    `gcc -c financial_utils.c`  
    which compiles the library into an object file: `financial_utils.o`
    Then compile all together:  
    `gcc financial_utils.o loan.c -lm`
* With many different source/header files, this can get very complex
  * Solution: use a build system like `make`

## Unit Testing

* A *unit* is a piece of code (usually a function) that can be tested
* A unit is an indivisible piece of code that is treated as a "black box": you want to test things in isolation
* A unit test is an input-output pair that is known to be correct
  * It is determined to be correct *before* you write your code
* We unit test by feeding the input into our unit (function) and comparing the result to the *known correct* output: actual vs the expected
  * It passes if they "match"
  * It fails if they do not match
* Grouping multiple unit tests into one collection gives you a *test suite*
* Matching criteria:
  * For integers, an *exact* match is needed (`==`)
  * For `double`s: it may be okay to be "close enough": within `0.00001`
* If a future bug is reported: you have a new test case!
* Tests should be repeatable Ie *automated*, not manually checked/tested
* You need to *write* code to run your test cases!
* The more tests you have the higher certainty you have that your code is correct
* No amount of unit testing will give you a 100% guarantee that your code is correct!
* One Goal: provide 100% "code coverage"
  * You want *at least* one test case for each possible "computational path"
  * You want to test *edge* cases or "corner" cases
  * Fuzzing: generate random values in an attempt to break your code
* Problems:
  * Lack of code coverage
  * A *false positive* is when a test case is wrong but the code is correct
  * A *false negative* is when there is a bug in your program but your test case(s) do not catch it: they both agree but they are both *wrong*
  * TDD = Test Driven Development
* Ad-hoc testing: testing as we went using manual input/output
* Informal unit testing: writing your own tests and boilerplate reporting code
* Formal unit testing: you bring in a library to do all of the boilerplate stuff for you

## Misc

* Another advanced topic: `makefile`s
  * for larger projects building code can get very complicated
  * You may have dozens of rules and *dependencies* (one file depends on another, that depends on another, etc.)
  * Another language, a *build* system is necessary
  * Build Engineers or "DevOps" (Development Operations)
  * Related: CI = Continuous Integration

## How Functions Work


```text













```
