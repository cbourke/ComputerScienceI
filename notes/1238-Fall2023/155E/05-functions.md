
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


## How Functions Work

* Programs have a *program stack*: it is a LIFO= Last-In First-Out data structure
* Operations:
  * Pop from the top of the stack (you remove the top-most element)
  * Push an element to the top of the stack
* Everytime a function is called a new *stack frame* is created and placed on the top of the "call stack" or "program stack"
  * All local variables and parameters in a function are stored in that function's stack frame
  * Each function can only "see" its own stack frame
  * This is how scoping actually works: you can have multiple variables of the same name but they exist in different stack frames
  * Once a function is done executing, its stack frame is popped off the top and control is returned to the calling function
* Can a function "swap" to values?
  * Not if you "pass by value"
  * When a function is called, *copies* of the values of any parameter/argument/input variables are passed to the function, NOT the actual variables
  * BUT: can we pass actual variables in order to have a *true*, working "swap" function?  Yes

## Pointers

* Memory in a computer has both an *address* and *contents*
* An address is a numerical designation of where data is stored
* The *contents* are the actual data
* Pointers in C allow you to actually access and manipulate the contents of memory through the memory address

```

    int a = 42;

    printf("the contents stored in variable a are %d\n", a);
    printf("the variable a is stored at memory locatoin %p\n", &a);

    //declare a pointer variable that can point to a:
    int *ptrToA;
    //what does ptrToA current point to?  Who knows
    //It COULD point to:
    //  - a memory location that doesn't exist
    //  - a memory location that exists but does not belong to you
    //  - a memory location that belongs to your program but that you should still not mess with

    // it is best practice to initialize a pointer to NULL:
    ptrToA = NULL;
    //you can check for NULL;
    if(ptrToA == NULL) {
        printf("ERROR: you cannot access this memory!\n");
    }

    // how do we actually make the pointer "point" to the variable a?
    // the ampersand in front of a regular old variable gives you the
    // memory address of that variable
    // It is the "referencing operator"
    ptrToA = &a;

    //careful: do not make a pointer point to an invalid memory address

    //this makes the pointer point to memory address 42
    ptrToA = a;

    //this would make the pointer point to memory address 101:
    ptrToA = 101;

    printf("the contents stored in variable a are %d\n", a);
    printf("the variable a is stored at memory location %p\n", ptrToA);

    // ampersand is the *referencing operator*:
    //  regular old variable -> memory address
    // the opposite operation is the *dereferencing operator*:
    //  memory address -> regular old variable
    // Syntax: use a *
    ptrToA = &a;
    printf("the contents at memory location %p are %d\n", ptrToA, *ptrToA);
    *ptrToA = 23;
    printf("the contents at memory location %p are %d\n", ptrToA, *ptrToA);

```

* Using pointers as function parameters allows us to *pass by reference*
  * Memory addresses of variables are passed to the function
  * Since the function has the memory addresses it can "jump" to those locations and directly manipulate the contents of that memory
  * This enables us to write a proper functioning "swap" function

* Observations:
  * When we used `scanf("%d", &x)` we used the ampersand to pass in `x` by reference: so that scanf could read the input and place the value into the original variable `x`
  * Passing by reference is essentially passing a shared "bucket": you give the function a bucket to fill with a value
  * Manipulating uninitialized variables or even `NULL` or invalid pointers will lead to a segmentation fault
  * ALways remember what Bret Hart said...

### Summary of Pointers

* A pointer is a memory address or *reference* to a memory address
* A pointer variable can be declared using the star symbol: `int *ptrToA`
* It is best practice to initialize a pointer directly to what you want it to point to or, if you *don't* know, then make it point to `NULL`
* To convert a regular old variable into a memory address/pointer/reference using the *referencing operator*: `&`
* To convert a pointer into a regular old variable (in order to access or change the value stored at its location) use the *DEreferencing operator*: `*`
* Don't make pointers point to things they shouldn't point to
* You can create any type of pointer: `int *` (integers), `double *` (doubles), `char *` for characters

```c
void swap(int *a, int *b) {

  int temp = *a;
  *a = *b;
  *b = temp;

}

int main() {

  int a = 10;
  int b = 20;
  printf("In main(): a, b = %d, %d\n", a, b);

  swap(&a, &b);

  printf("In main(): a, b = %d, %d\n", a, b);



  return 0;
}
```

## Pass By Reference

* Normally, passing variables by value means you cannot change the values in the *original* variables
* Passing variables by *reference* using pointers, you *can* change the values in the original variables
  * Ex: `swap()`
* You can now use pass-by-reference variables to "return" multiple values
  * Ex: computing multiple values such as red-green-blue
  * Demo: let's compute the tax, tip, and total for a diner bill
* Another useful thing: not returning a value from a function frees up the return value to be used for other purposes...

```text













```
