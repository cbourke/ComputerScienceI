
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
* Matching criteria:
  * For integers, an *exact* match is needed (`==`)
  * For `double`s: it may be okay to be "close enough": within `0.00001`
* If a future bug is reported: you have a new test case!
* Tests should be repeatable Ie *automated*, not manually checked/tested
* You need to *write* code to run your test cases!
* The more test cases you have the more certainty or *assurance* you ahve that your code is correct, however...
* No matter HOW MANY test cases you have, you will never have a *proof* that your code is correct
* One Goal: provide 100% "code coverage"
  * Code coverage: how much of your code is tested by your *test suite*
  * The code that a unit test or test case tests is its *coverage*
  * You generally want to test *edge* or *corner* or *extremal* cases
  * Fuzzing: generate random values in an attempt to break your code
* Problems:
  * Lack of code coverage
  * A *false positive* is when a test case is wrong but the code is correct
  * A *false negative* is when there is a bug in your program but your test case(s) do not catch it: they both agree but they are both *wrong*
* TDD = Test Driven Development
  * Design approach: all tests are written before any code is written
  * No testing: also bad!
* ad-hoc testing: testing manually as we go, manually entering input/output recompile, fix, etc.
* Informal Unit Testing: writing your own tests and boilerplate code to execute the tests and produce a summary

## How Functions Work

* Programs have a *program stack* or *call stack*
* Stack: LIFO Data Structure
  * LIFO = Last In First Out
  * Pop: you remove the element from the "top" of the stack
  * Push: you add an element to the top of the stack
* Everytime a function is called a new *stack frame* is created and placed on the top of the "call stack" or "program stack"
  * All local variables and parameters in a function are stored in that function's stack frame
  * Each function can only "see" its own stack frame (*scoping*)
  * This is how scoping actually works: you can have multiple variables of the same name but they exist in different stack frames
  * Once the function is done executing and returns, its stack frame is "popped" off the top and destroyed (any variables that were inside it are GONE)
* DEMO: Can a function "swap" to values?
  * Normally in C, variables are *passed by value*
  * That means: copies of the values are passed to the function NOT the variables themselves!
  * When we swap, we are only swapping the *copies* NOT the originals
  * Swapping inside the function has no effect on the original variables!
  * BUT: can we modify our program so that *can* successfully swap?  Yes, but... we need pointers first

```text


















```
