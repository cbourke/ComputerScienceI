
# CSCE 155E - Computer Science I
## Functions
### Fall 2025

An introduction to functions in C.

* A *function* is a reusable unit of code that may take *input(s)* and *may* produce an *output*
* Similar to math functions:
  * $y = f(x) = x^2$
  * $x$ is the input, $y$ is the output, $f$ is the name of the function
  * Input: $x$ (there is only one), $f(x, y)$, $f(x, y, z), f() = 5$
  * A function can only ever return at most one thing
* Already seen a lot of functions: `sin(), sqrt(), pow(), printf(), main()`
* Functions facilitate *code reuse*: you don't have to copy-pasta code (cut and paste code), instead you can put that code into a function, and simply use and reuse the function
* DRY Principle = Don't Repeat Yourself
* Procedural abstraction:
  * How does `sqrt()` function work?
  * Who cares?  You simply want to utilize the functionality!
  * It abstracts the details away so we don't have to worry about them!
  * It reduces *our* cognitive load
  * The details are *encapsulated* inside the function and we don't have to worry about it!
* Feeds into an overall approach to problem solving:
  * When faced with a problem: what is the first question you should ask?
  * Has this problem already been solved?
  * Is there a function that already provides this functionality?
  * Don't "reinvent the wheel", use what is already available
  * An "off the shelf" solution will often be better, well-tested, optimized, etc.
  * Or: can I *adapt* a function in order to solve this problem

## Functions in C

* As with variables, functions in C have to be *declared* before you can use them
* In C, you "declare" a function by writing a *prototype*
* A prototype is a function signature followed by a semicolon
* Signature:
  * The name or identifier of the function
  * The return type of the function (the type of variable that it returns)
  * The inputs: *parameters*, *arguments*, *inputs*
* After you have a prototype you can use the function
  * You can "call" or "invoke" the function and
  * capture its return value
* Documentation:
  * For every prototype, you are required (for this course) to have non-trivial documentation
  * Describes what the function does (not the how)
  * YOu always place the documentation with the prototype and *should* use doc-style comments to do so.
* Later you provide a function *definition*: what the function does
  * You repeat the signature, WITHOUT the semicolon
  * Instead, you have opening/closing curly brackets `{}` inside of which you have the function *body*: the code that executes when you call this function
  *  You do not repeat the documentation: DRY Principle

## Creating a Library: Modularity

* You wan to separate utility functions into their own files
  * Prototypes and their documentation will be placed in a *header* file: extension: `.h`
  * The definitions are placed in a source file with the same base name + `.c`
* Demonstration:
  * Place our prototypes into a header file: `utils.h`
  * Place definitions into `utils.c`
  * Compile a library using the `-c` flag with `gcc` which produces an *object*: `gcc -c utils.c`, produces `utils.o` file
* Observations:
  * In your source file (`.c`) be sure to include your header file:  
  `#include "utils.h"`
  * Do *NOT* use this include in your header file
  * Do *NOT* nearly ever include source files:  
  `#include "utils.c"`
* To compile everything thing together:
  * You need to `#include` your header file in the "main" file (whatever file contains your `main()` function)
  * To compile you use `gcc utils.o demo.c`
* More:
  * We use the double quotes instead of `<>` to specify to the compiler that it is a *nonstandard* library (user defined)
  * With many different source/header files, this can get very complex: solution use a "build system" (`make`, more on this later)

## Unit Testing

* A *unit* is a piece of code (usually a function) that can be tested
* A unit is an indivisible piece of code that is treated as a "black box" (something that you cannot look inside of)
* You feed inputs into the box and it produces outputs
* This means we test the box/unit in *isolation*
* A unit test is an input-output pair that is known to be correct
  * It is determined to be correct *before* you write your code/test
* We unit test by feeding the input into our unit (function) and comparing the result to the *known correct* output: actual vs the expected
  * If they "match" the unit test *passes*
  * If they do not match then the unit test *fails*
* Grouping multiple unit tests into one collection gives you a *test suite*

```text


















```
