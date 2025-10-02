
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

## Review

* Functions are reusable units of code
* They have a *signature*: the return type, name, parameters (inputs)
* In C: you organize functions into *modules*/libraries
  * Prototypes + documentation go in header files `.h`
  * Definitions go in source files `.c`
  * Compile the library using `-c` flag: `gcc -c utils.c` (produces `utils.o`)
* Functions are perfect "units" for *unit testing*
  * Formal unit testing (module 6): **cmocka**
  * Build systems/DevOps: makefiles
* Functions are *pass by value*
  * *copies* of the parameter variable values are passed to the function
  * Changes to the copies have no effect on the original variables

## Pointers

* Memory in a computer has both and *address* and *contents*
* An address is a numerical designation of where data is stored
* Address is also called a *reference* or *memory locations*
* The contents are the actual data that is being stored

### Demo

```c

    // int a = 10;
    // int b = 20;

    // printf("BEFORE: a = %d, b = %d\n", a, b);
    // swap(a, b);
    // printf("AFTER:  a = %d, b = %d\n", a, b);

    //a is a regular old variable
    int a = 10;

    //create a *pointer* variable
    // pointer variable is a variable represents a *memory address*
    int *ptrA;

    //at this point, however, what is ptrA pointing to!?!?!
    // Who knows?
    // -it could point to a valid memory location that doesn't belong to our program
    // -it could point to a valid memory location that *does* belong to our program
    // -it could point to an invalid memory location
    //it is best practice to initialize memory

    ptrA = NULL;

    //you can do null pointer checks:
    if(ptrA == NULL) {
        printf("the memory is not initialized!\n");
    }

    //let's make it point to a *valid* memory location
    // make the RHS into a pointer
    ptrA = &a;

    printf("a is regular old variable and it is stored in memory location %p and has the value %d\n", &a, a);
    printf("ptrA is a pointer variable and points to location %p\n", ptrA);

    //let's manipulate the contents of memory through a pointer
    //A * in front of a pointer variable makes it into a regular old variable so you
    // can set its value. * in this case is a *dereferencing* operator
    *ptrA = 20;
    printf("a is regular old variable and it is stored in memory location %p and has the value %d\n", &a, a);
    printf("ptrA is a pointer variable and points to location %p\n", ptrA);

    //bad things can and will happen...
    //ex1: set a pointer value to an arbitrary location
    //ptrA now points to: memory location 42
    ptrA = 42;
    //printf("ptrA is a pointer variable and now points to %p which store values %d\n", ptrA, *ptrA);

    //make ptrA point to a location that *you* own but it will cause problems
    ptrA = &a-10;
    //change the value of whatever is stored there to 42:
    *ptrA = 42;
    //no seg fault, but we likely screwed up our own memory

    ptrA = main;
    //*ptrA = 1234;
    printf("main is located at memory address %p\n", ptrA);

    //other bad things: dereferencing invalid pointers
    // results in a seg fault
    ptrA = NULL;
    *ptrA = 42;
```

### Review of Pointers

* A pointer is a *memory address* or "reference"
* A pointer can be declared using the star syntax: `int *p`
* It is best practice to initialize them to `NULL`
* To make a pointer variable into a regular old variable: use the *dereference* operator: `*p`
* To make a regular variable into a pointer variable: `&a`, the *referencing* operator
* Don't make pointers point to things they shouldn't point to


#### Remember

* Regular old variable $\rightarrow$ pointer: `&`
* Pointer variable $\rightarrow$ Regular old variable: `*`

## Passing By Reference

* Recall that passing by value means that *copies* of the variables are passed to the function.
* Pass by reference means that *memory addresses* (ie pointers) of variables are passed to the function instead of copies
* Now you can manipulate the *original* values because you have access to their memory locations
* You can now "return" multiple values from a function




```text


















```
