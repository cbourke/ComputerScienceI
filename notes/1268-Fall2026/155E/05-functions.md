
# CSCE 155E - Computer Science I
## Functions & Methods
### Fall 2026

* A *function* is a reusable unit of code that may take input(s) and may produce an output
* Often referred to as a "unit" when doing unit testing
* Math:
  * $y = f(x) = x^2$
  * $f(x,y) = x + 2y$
  * There is only ever at most ONE output to a function
  * You can also have multivariate functions: $f(x, y)$, $f(x, y, z)$, $f()$, $f() = 4$
* Already seen a lot of functions: `sin(), sqrt(), pow(), printf(), main()`
* WHy functions?
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

* As with variable, functions in C have to be *declared* before you can use them
* In C, you "declare" a function by writing a *prototype*
* A prototype is a function **signature** followed by a semicolon
  * The name or identifier of the function
  * The return type of the function: what type of variable does it `return`
  * The inputs: *parameters* or "arguments" (the number and type)
* After you have a prototype you can use the function
* Later in the program you *define* what the function does:
  * You repeat the signature without a semicolon
  * You provide a function body surrounded by `{...}`
* Documentation:
  * For every prototype, you are required (for this course) to have non-trivial documentation
  * You should use doc-style comments
  * Always put them with the prototype, never repeat them with the definition
  * Describes what the function does (not the how)
* Misc:
  * Generally function names should be `lowerCamelCase` and
  * Should be *verbs*: action words or terms, NOT nouns.  Ex: `computeMonthlyPayment` or `getMonthlyPayment` NOT `monthlyPayment`
  * We "call" or "invoke" a function at which point it takes over control: its an interruption of the normal sequential control flow
  * Once a function is done computing, it `return`s control back to the "calling function"

## Misc

* A function that does not return anything is a `void` function
  * Syntax: `void foo();`
  * You should *still* have a return statement: `return;`
* You can also have functions with no input:
  * Syntax: `int bar();`

## Creating a Library: Modularity

* You want to separate utility functions into their own files
  * Prototypes + documentation will go in a *header* file that ends with `.h`
  * The definitions will be placed in a *source* file of the same name but ending in `.c`
* Demonstration:
  * Place our prototypes into a file named `finance_utils.h`
  * Place the definitions into a file `finance_utils.c`
  * Compile a library using the `-c` flag with `gcc` which produces an *object*: `gcc -c finance_utils.c`, produces `finance_utils.o` file (an object file, machine code)
  * In any file that you use or define the functions, include your own header file: `#include "finance_utils.h"`
  * To compile everything together:
  `gcc finance_utils.o loan.c -lm -Wall -Wextra`
* Obervations:
  * In your source file be sure to include your *header* file NOT your *source* file: otherwise there will be an infinite loop
* More:
  * We use the double quotes instead of `<>` to specify to the compiler that it is a *nonstandard* library (user defined)
  * With many different source/header files, this can get very complex: solution use a "build system" (`make`, more on this later)

## Unit Testing

* A *unit* is a piece of code (usually a function) that can be tested
* A unit is an indivisible piece of code that is treated as a "black box" (something that you cannot look inside of)
* You feed inputs into the box and it produces outputs
* This means we can test the box/unit in *isolation*
* A unit test is an input-output pair that is known to be correct
  * It is determined to be correct *before* you write code!
  * We unit test by feeding the input into our unit (function) and comparing the result to the *known correct* output: actual vs the expected
  * If they match: the unit test *passes*
  * If they do not match: the unit test *fails*
* Grouping multiple unit tests into one collection gives you a *test suite*
* If a future bug is reported: you have a new test case!
* Tests should be repeatable Ie *automated*, not manually checked/tested
* You need to *write* code to run your test cases!
* The more test cases you have the higher certainty or *assurance* you have that your code is correct, however...
* No amount of test cases will ever *prove* your code is correct
* Our goal:
  * 100% code *coverage*: all of your code should be tested by at least one (if not more than one) test case
  * You should test for "edge" or "corner" cases or "extremal" cases
* Problems to look out for:
  * A *false positive*: when a test case is wrong but the code is correct
  * A *false negative* is when there is a bug in your program but your test case(s) do not catch it: they both agree but they are both *wrong*
* TDD = Test Driven Development
  * Design approach: all tests should be written before any code is written
  * This is a bit inflexible
* No testing = bad coding
* ad-hoc testing: testing manually as we go, manually entering input/output recompile, fix, etc.

### Informal Unit Testing

* Informal Unit Testing: writing your own tests and boilerplate code to execute the tests and produce a summary
* Demonstration

### Formal Unit Testing

* Formal unit testing: you are using a library to do most of the boilerplate stuff for you
* Example: `cmocka`
  * Instructions for installation and use are provided in Lab 6/Hack 6
  * It requires pointers and function pointers (later)
  * Instead: you'll be using our examples and extending them

## How Functions Work

* Programs have a *program stack* or *call stack*
* Stack: LIFO Data Structure
  * LIFO = Last in First out
  * Pop: you remove the element from the "top" of the stack
  * Push: you add an element to the top of the stack
* Programs also have stacks
* Everytime a function is called a new *stack frame* is created and placed on the top of the "call stack" or "program stack"
  * All local variables and parameters in a function are stored in that function's stack frame
  * Each function can only "see" its own stack frame (*scoping*)
  * This is how scoping actually works: you can have multiple variables of the same name but they exist in different stack frames
  * Once the function is done executing and returns, its stack frame is "popped" off the top and destroyed (any variables that were inside it are GONE)
* DEMO: Can a function "swap" to values?
  * Normally in C, variables are *passed by value*
  * Means: **copies** of the values are passed to the function, NOT the variables themselves
  * When we swap, we swapped the *copies* and *not* the originals
  * Swapping inside the function has no effect on the original variables in the calling function
  * BUT: can we modify our program so that *can* successfully swap?  Yes, but... we need pointers first

## Pointers

* Memory in a computer has both and *address* and *contents*
  * Regular old variables such as `int` refer to the *contents* of memory
  * A *pointer* variable can be created to refer to the *address* of memory

```c


    // int a = 10;
    // int b = 20;
    // printf("start of main: a = %d, b = %d\n", a, b);
    // swap(a, b);
    // printf("end of main: a = %d, b = %d\n", a, b);

    //a regular old integer variable:
    int a = 42;

    //create a pointer variable that can point to the memory location of an int:
    //* = star or asterisk
    int *p;

    //as of right now, what does p point to?
    //. what does p point to?
    //. Who knows?!? its undefined;
    //. it could point to an invalid memory location, one that does not exist
    //. it could point to a *valid* memory location that does not belong to your program!
    //. it coudl point to a valid memory lcoation that does belong to us, but that we *should* screw with

    //its best practice to make it point to NULL:
    // NULL is a special memory location that will always exist and means "invalid"
    p = NULL;

    if(p == NULL) {
        printf("ERROR: cannot access pointer p\n");
    }

    //make p point to a:
    //& = memory access operator; it gives the memory location of a regular old variable
    p = &a;
    printf("a is a regular old variable that is stored at memory location %p and holds the value %d\n", &a, a);

    *p = 101;

    printf("a is a regular old variable that is stored at memory location %p and holds the value %d\n", &a, a);
    printf("p is a pointer variable that points to memory location %p which holds the value %d\n", p, *p);

```

## Summary

* A pointer is a *memory address* or "reference"
* A pointer can be declared using the star syntax: `int *p;`
* It is best practice to initialize them to `NULL` unless you know what you are going to point it to...
* To make a regular variable into a pointer variable: `&a`, the *referencing* operator
* To make a pointer variable into a regular old variable: use the *dereference* operator: `*p`
* Don't make pointers point to things they shouldn't point to
* Regular old variable $\rightarrow$ pointer: `&`
* Pointer variable $\rightarrow$ Regular old variable: `*`

```c

    //Don’t make pointers point to things they shouldn’t point to
    double x = 3.5;
    //pointer variable to point to x:
    //CORRECT:
    double *ptrToX = &x;

    //INCORRECT: this would end up losing have the data, giving garbage results
    //int *ptrToX = &x;

    int y = 42;
    //INCORRECT: it ends up pointing to 8 bytes when there are only 4: garbage results
    //double *ptrToY = &y;

    int *p = NULL;
    //dereferencing a null pointer: segmentation fault
    //*p = 42;

    //VALID:
    //makes p point to y:
    p = &y;
    //dereference p to set y's value to 101
    *p = 101;
    //INVALID: sets p to point to memory location 101!
    p = 101;
    printf("p is now point to memory location %p\n", p);
    //trying to access memory location 101 will lead to... Segmentation fault (core dumped)
    *p = 4024;

    //unfortunately code like this is not possible:
    // if(p is a valid memory location that belongs to my program) {
    //     //proceed.
    // }
```

## Passing By Reference

* Recall that passing by value means that *copies* of the variables are passed to the function.
* Pass by reference means that *memory addresses* (ie pointers) of variables are passed to the function instead of copies
* Now you can manipulate the *original* values because you have access to their memory locations
* You can now "return" multiple values from a function
  * It then frees up the return for other uses...
  * We'll use the return value as an *error code*


```text
















```
