
# CSCE 155H - Computer Science I Honors
## Functions & Methods
### Fall 2023

* A *function* is a reusable unit of code that may take input(s) and may produce an output
* Often referred to as a "unit" when doing unit testing
* In Java: they are called "methods"
* Already familiar with functions: `main(), printf(), sqrt()`, etc.
* Familiar with functions from math: $f(x) = x^2$
  * Input: $x$
  * Output: $y = x^2$
  * You can also have multivariate functions: $f(x, y)$, $f(x, y, z)$, $f()$
* Functions facilitate code reuse: you don't have to copy-pasta chunks of code; instead you put them into a function and then *call* or *invoke* the function
* DRY Principle: Don't Repeat Yourself!
* Procedural Abstraction:
  * How does `sin()` work?
  * Taylor series, numerical interpolation methods,
  * Who cares?  We simply want to *use* that functionality and not have to worry or think about how it gets done
* By *encapsulating* functionality into functions, then we don't have to think about the details
* Standard libraries and external libraries come with a LOT of testing, debugging and optimization that you *cannot* hope to replicate!
* IE: "don't reinvent the wheel", "don't roll your own"
* Problem solving: when asked to solve a problem, what is the first question you should ask?
  * Does a solution already exist?
  * OR: does an "off the shelf" solution exist that can be *adapted*

## Functions in C

* As with variables, functions must be declared before you can use them
* In C you "declare" a function using a *prototype*
* A prototype declares a function's *signature*
  * Its identifier: its name
  * The type of variable it returns and
  * Any parameter types (inputs or arguments) it takes
* In general, every function should have doc-style documentation which is associated with the prototype
* DRY Principle = Don't Repeat Yourself

Observations:
* The prototype has no function "body": it ends with a semicolon
* Convention: use `lowerCamelCasing` for function names, and in general we use *verbs*
* Later on in your program, you *then* define what the function does by providing a function *definition*: repeat the prototype but instead of a semicolon you provide a function *body*
* The code in the function body is what is executed when you *call* or *invoke* the function
* Control flow is "handed over" to the function and it computes until it gets to a `return` statement...
* At which point control is given *back* to the calling function
* Any variables declared inside a function are *local* to that function and they have *local scope* to that function

## "Functions" in Java

* *Technically*: functions in Java are called "methods"
* In Java everything is a class or belongs to a class; therefore "functions" that belong to a class are (fancily called) methods
* For now: we'll restrict our attention to `static` methods: methods that "belong" to the class
  * To invoke a method you need the class name + dot + the name of the function
  * Example: `Math.sqrt()`
* `public` methods can be "seen" and used by any code in your project
* Alternatives:
  * `private`: only the class can "see" it
  * `protected`: only the class and subclasses can "see" it
  * the abscence of a keyword is "package protected": only other classes in the same package can "see" it

## Other Issues/Items

* A method or function that doesn't return anything is a `void` function
  * You can make the return type `void` to indicate that it returns nothing
  * Best practice: you should *still* have a return statement: `return;`
  * You can create functions with no input: you just don't use the `void` keyword, you use empty parentheses:
    * `int foo(void)`

## Modularity

### In C

* In general, similar functions are organized into *modules* or "libraries"
* Why?  Organization, you only need to bring in particular libraries when you need them
* Code reuse: you can publish your library code so that other people, programs, etc. can use them!
* Demonstration: let's separate our "math code"
  * Separated the prototypes + documentation into a *header* file, with the extension `.h`
  * Placed the function definitions into a *source* file with the same base file name but a `.c` extension
  * We used `#include "my_math.h"` anywhere we need to bring in the prototypes
  * We then compiled in phases:
    * WE compiled (but didn't link) the library: `gcc -c my_math.c`
    * That produces an *object* file, `my_math.o`
    * Then we compiled everything together: `gcc my_math.o -lm demo.c`

### Java

* Collections of methods are separated into "utility" classes
* Classes are organized into packages; ex: `unl.soc` which are simply directories (`unl`) and subdirectories (`soc`)

## Unit Testing

* A *unit* is a piece of code (usually a function) that can be tested
* A unit is an indivisible piece of code that is treated as a "black box": you want to test things in isolation
* A unit test is an input-output pair that is known to be correct
* We unit test by feeding the input into our unit (function) and comparing the result to the *known correct* output: actual vs the expected
  * If they match: PASSES!
  * If they do not match: FAILS!
* Grouping multiple unit tests into one collection gives you a *test suite*
* If a future bug is reported: you have a new test case!
* A future change or fix that breaks other unit tests is known as a *regression*
* Tests should be repeatable
* The more tests you have the higher certainty you have that your code is correct
* No amount of tests will ever give you a 100% *proof* that your code is correct
* The more test cases you have the better *code coverage* you have
  * You want to test corner cases
  * Edge cases, extremal cases
  * Randomized Test (chaos testing) or "fuzzing"
* Problems:
  * Lack of code coverage
  * A *false positive* is when a test case is wrong but the code is correct
  * A *false negative* is when there is a bug in your program, but your tests do not indicate it
* TDD = Test Driven Development
  * You write tests before you even write the code
* Demo:
  * *informal* unit testing in C
  * *formal* unit testing in Java: JUnit (version 5)


### Function Overloading

* In C, to compute the absolute value you can use `abs(), fabs(), labs(), llabs(),` etc.
* Those function each take a different type and return a different type
* In C you can only have one function with one particular name
* In *some* language (Java) you can have multiple functions with the same name but with different parameter types
* Example: in Java, the `Math` library contains 4 *different* `abs()` methods all with the same name
* Java allows/supports *method overloading*: the ability to have multiple functions with the same name
* At compile time, the Java compiler is able to deduce *which* function you intended to call based on what you pass it (this mechanism is called *static dispatch* )
* C does not support function overloading, thus it needs different names for each function: you cannot have two functions with the same name
* In C You end up either *polluting the namespace* or appending a common "tag"

## How Functions Actually Work

* Programs have a *program stack* (or *call stack*)
* Stack: LIFO data structure
  * LIFO = Last In First out
  * Push: you add something to the "top" of the stack
  * Pop: you remove the top most thing
* Each time a function is called, a new *stack frame* is created/pushed on top of the call stack
* Each stack frame keeps track of local variables and parameters
* Each time you return from a function, the stack frame is popped off the top
* Consequence: each stack frame's variables are separate (this gives us *scoping*) and cannot be accessed by other stack frames
* Every function gets its own scope and own variables
* In most programming languages (C, Java), variables are *passed by *value*
  * When a function is called, *copies* of the values of the variables at that point in the program are passed to the function
  * The actual variables are NOT passed!
  * no changes can be made from one stack frame to another!
* However, in C we *do* have a bit more control: we can pass by *reference* instead

## C: Pointers

* Every piece of data in a computer is stored in memory
* Memory consists of an address (location) and its contents (the actual data stored in memory)
* In C you can access memory directly using *pointers*: a variable type that "points" to a *memory address* instead of the contents of memory
* To create a pointer variable you use the `*`

```c

    //a regular old variable declaration:
    int x = 42;

    printf("x holds the value %d\n", x);
    printf("x is stored at memory address %p\n", &x);

    //create a *pointer* variable:
    int *ptrToX;
    //at this point in the program, what does ptrToX point to?
    // who knows: it coudl point to anything, including:
    //  memory that doesn't exist
    //  memory that exists but does not belong to your program
    //  memory that belongs to your program but you shouldn't be messing with it
    // It is best to initialize pointers to NULL:
    ptrToX = NULL;

    //you can test for NULL:
    if(ptrToX == NULL) {
        printf("ERROR: Do not try to access this  memory!\n");
    }

    // now let's make ptrToX actually point to the variable x:
    // the ampersand gives you the memory address of a regular old variable
    ptrToX = &x;

    printf("x holds the value %d\n", x);
    printf("x is stored at memory address %p\n", &x);
    printf("ptrToX has the value %p\n", ptrToX);

    ptrToX = x;

    printf("x holds the value %d\n", x);
    printf("x is stored at memory address %p\n", &x);
    printf("ptrToX has the value %p\n", ptrToX);

    //let's get the *contents* pointed to by ptrToX:
    printf("ptrToX is poitning to memory location %p which holds the value %d\n", ptrToX, *ptrToX);

    //you cannot point to arbitrary memory locations:
    ptrToX = -101;
```

* You can create a pointer variable by using the `*`
* When you create a pointer variable, the pointer *type* must match what you want it to point to:

```c
int a = 42;
double *p = &a;


```

* Putting an ampersand in front of a regular old variable, gives you the memory address of that variable
* Further: you can now manipulate the contents of a variable through its pointer

### Summary of Pointers

* A pointer is a *memory address* or "reference"
* A pointer can be declared using the star syntax: `int *p;`
* It is best practice to initialize them to `NULL`
* To make a pointer variable into a regular old variable: use the *dereference* operator: `*p`
* To make a regular variable into a pointer variable: `&a`, the *referencing* operator
* DOn't make pointers point to things they shouldn't point to
* Java: doesn't have pointers!

## Passing By Reference

* Now you can "return" multiple values from a function: specifying more than one pass-by-reference variable
* Simply "returning" a value by using a pass-by-reference variable means you don't have to explicitly return a value, this frees up the return type/variable
* With that return variable, we can now do *error handling*


```text










```
