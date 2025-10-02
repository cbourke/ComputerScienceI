
# CSCE 155H - Computer Science I Honors
## Functions & Methods
### Fall 2025

* A *function* is a reusable unit of code that may take input(s) and may produce an output
* Often referred to as a "unit" when doing unit testing
* Math:
  * $y = f(x) = x^2$
  * $f(x,y) = x + 2y$
  * There is only ever at most ONE output to a function
  * You can also have multivariate functions: $f(x, y)$, $f(x, y, z)$, $f()$
* Functions facilitate code reuse: you don't have to copy-pasta chunks of code; instead you put them into a function and then *call* or *invoke* the function
* DRY Principle: Don't Repeat Yourself!
* Procedural Abstraction:
  * How does `sqrt()` work?
  * Who cares?  we just want to use it
* By *encapsulating* functionality into functions, then we don't have to think about the details
* Standard libraries and external libraries come with a LOT of testing, debugging and optimization that you *cannot* hope to replicate!
* IE: "don't reinvent the wheel", "don't roll your own"
* Problem solving: when asked to solve a problem, what is the first question you should ask?
  * Does a solution already exist?
  * OR: does an "off the shelf" solution exist that can be *adapted*

## Functions in C

* As with variables, functions must be declared before you can use them
* In C you "declare" a function using a *prototype*
* A prototype is a function's *signature*:
  * Its identifier: the name of the function
  * The type of variable it `return`s (output)
  * Any *parameters* or *inputs* or *arguments* to the function: the arity (number of arguments) and the types (`int, bool, double`, etc.)
* In general, the *documentation* of a function goes with the prototype:
  * You *should* use doc-style comments
  * DRY: you should not *repeat* documentation later on
  * Provide a description of what the function does and any expectations on its inputs
* Later on in the program, you provide a function *definition*:
  * Has no semicolon, instead...
  * It has a *repeated* signature
  * and a function *body* that is inside `{...}` and specifies the code that is run when the function is called
* once a function is defined you can use it anywhere in the program
  * You "invoke" or "call" a function
  * **Optionally**: you can capture the return value
  * Convention: use `lowerCamelCasing` for function names, and in general we use *verbs* (functions do things)
  * Control flow is "handed over" to the function and it computes until it gets to a `return` statement...
  * At which point control is given *back* to the "calling function"
  * Any variables declared inside a function are *local* to that function and they have *local scope* to that function

## "Functions" in Java

* In java; technically: we have "methods" not "functions"
* In Java: everything is a class or belongs to a class (OOP = Object Oriented Programming): functions are inside a class and therefore are "methods"
* For now: we'll restrict our attention to `static` methods
* `static` in this context means that the method belongs to the class, not to *instances* of the class
  * Simply: just use the class name + function name to invoke it
  * Ex: `Math.sin()`
* Java doe snot have prototypes: you include the documentation, signature and function body all in one spot
* Generally function are placed *above* the `main` if there is a `main`
* `public` simply means that all piece of code can "see" your function and use it

## Other Issues/Items

* A method or function that doesn't return anything is a `void` function
  * YOu still *should* have a `return` statement, but you don't return anything: `return;`
  * You can also use the return type `void` to indicate that a function doesn't return anything
  * You can create functions with no input: you just don't use the `void` keyword, you use empty parentheses:
    * `int foo(void)` instead prefer
    * `int foo()`
* Recall: that functions can only ever return ONE thing (otherwise they are not functions)

## Modularity

### In C

* In general, similar functions are organized into *modules* or "libraries"
* Why?  Organization, you only need to bring in particular libraries when you need them
* Libraries or "headers" (in C) should be *small*
* Code reuse: you can publish your library code so that other people, programs, etc. can use them!
* Demonstration:
  * Separate protoypes into header files: `.h` (files)
  * separate definitions into source files: `.c`
  * Compile them together: `gcc -c library.c`
  * You can include them in a source file using `#include "library.h"`
  * Compile all togheter to create an executable file: `gcc library.o main.c -lm -Wall`

### Java

* Collections of methods are separated into "utility" classes
* Classes are organized into packages: `unl.soc`

## Unit Testing

* A *unit* is a piece of code (usually a function) that can be tested
* A unit is an indivisible piece of code that is treated as a "black box": you want to test things in isolation
* A unit test is an input-output pair that is known to be correct
* We unit test by feeding the input into our unit (function) and comparing the result to the *known correct* output: actual vs the expected
  * If they "match" then it "passes"
  * If they do not match then it "fails"
* Grouping multiple unit tests into one collection gives you a *test suite*
* If a future bug is reported: you have a new test case!
* And so we can integrate it into our test suite and start *debugging*
* Having automated test suites allows us to fix the code and test for *regressions*
* Tests should be repeatable
* The more tests you have the higher *certainty* you have that your code is correct
* No amount of tests will ever give you a 100% *proof* that your code is correct
* The more test cases you have the better *code coverage* you have
  * Good code coverage should be a goal (100%)
  * You want to test corner cases
  * Edge cases, extremal cases
  * Randomized Test (chaos testing) or "fuzzing"
* Problems:
  * Lack of code coverage
  * A *false positive*: when the test case is wrong but hte code is correct
  * A *false negative* is when there is a bug in your program, but your tests do not indicate it
* TDD = Test Driven Development
  * You write all tests before you write any code
* Testing and design, and writing code are all part of a process (cyclical)

### Function Overloading

* In C, to compute the absolute value you can use: `abs(), fabs(), labs(), llabs()`, etc.
* Those function each take a different type and return a different type
* IN C you can only have one function with one particular name
* Names of functions in C are *unique*
* In some langauges (Java) you can have multiple functions/methods with the same name that take different types: `Math.abs()` (3 versions all with the same name: `abs`)
* A language that allows this allows "function overloading"
* Java allows/supports *method overloading*: the ability to have multiple functions with the same name
* How this works (Java):
  * At compile time the compiler detects what type of parameter you are passing
  * Then it uses *static dispatch* to invoke the correct function/method
  * "static" in this context refers to *compile time*
* C does not support function overloading, thus it needs different names for each function: you cannot have two functions with the same name
* In C You end up either *polluting the namespace* or appending a common "tag"
  * Once you create an `init()` function, no other function can be call that
  * If you have multiple libraries that all define `init()` it is *very* difficult to resolve them
  * Convention: library name + function name; ex: `gmp_init()`, `gtk_init()`

## How Functions Actually Work

* Programs have a *program stack* (or *call stack*)
* Stack:  LIFO data structure
  * LIFO: Last In First Out
  * Push: you add something to the "top" of the stack
  * Pop: you remove the top most thing from the stack
* Each time a function is called, a new *stack frame* is created/pushed on top of the call stack
  * Each stack frame keeps track of local variables and parameters
  * Each time you return from a function, the stack frame is popped off the top
  * Consequence: each stack frame's variables are separate (this gives us *scoping*) and cannot be accessed by other stack frames
* In most programming languages (C, Java), variables are *passed by *value*
  * When a function is called, *copies* of the values of the variables at the point that the function is called are passed to the function, NOT the original variables themselves
  * Changes to the original variables are NOT effected in the calling function (original function)
* C however, has *pass by reference* (after the exam)

## Review

* Functions are reusable units of code
* THey have a *signature*: the return type, name, parameters (inputs)
* Java: for now, all methods will be `public static`
* In C: you organize functions into *modules*
  * Prototypes + documentation go in header files `.h`
  * Definitions go in source files `.c`
  * Compile the library using `-c` flag: `gcc -c utils.c` (produces `utils.o`)
* In Java you can further organize code into packages

### Formal Unit Testing

* You use a library to do most of the boilerplate code for you
* In C: many libraries, but we'll use **cmocka**
* In Java: JUnit (5.0)

## Pointers

* Memory in a computer has both an *address* and *contents*
* An address is a numerical designation of where the data is stored
* The contents are the actual data being stored
* Pointers in C allow you to access and manipulate memory locations and contents

### Demo
```c

    //regular old variable:
    int x = 42;

    //create a *pointer variable*
    int *p;
    //what is p pointing to?  Could be ANYTHING
    // - a valid memory location that doesn't belong to you
    // - an invalid memory location
    // - a valid memory location that *does* belong to you but you'd end up screwing up your own program

    //lets make it point to a "valid" memory location:
    // its a placeholder for an uninitialized pointer
    p = NULL;

    //null pointer checks:
    if(p == NULL) {
        printf("cannot access the memory location for p\n");
    }

    //lets make it point to an *acutal* memory location
    p = &x;
    // & in front of a regular old variable gives you the memory address of that variable
    //LHS: a pointer = a reference = memory location = memory address
    //RSH: & makes it into a reference

    //manipulate the contents through the pointer:
    x = 43;
    //* in front of a pointer variable *dereferences* it and makes it into a
    // regular old variable so you can assign it a value
    *p = 44;

    printf("x is a regular old variable with value %d\n", x);
    printf("p is a pointer variable at memory location %p with value %d\n", p, *p);
    printf("x is a regular old variable still, that is stored at memory location %p\n", &x);

    //gotchas
    //make it point to "memory address 42"
    p = 42;
    //segmentation fault:
    //printf("p is a pointer variable at memory location %p with value %d\n", p, *p);

    //very weird: make the pointer point to the memory location that stores teh main function
    p = main;
    printf("p is a pointer variable at memory location %p with value %d\n", p, *p);

    p = 123;
    printf("p is a pointer variable at memory location %p with value %d\n", p, *p);


```

### Review of Pointers

* A pointer is a *memory address* or "reference"
* A pointer can be declared using the star syntax: `int *p;`
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
* You can now "return" multiple values from a function
* Simply "returning" a value by using a pass-by-reference variable means you don't have to explicitly return a value, this frees up the return type/variable
* With that return variable, we can now do *error handling*

### Java

* In Java, objects `Integer, Double, String`, etc. are *technically* references
* However, in Java, all of these types are *immutable*

```java
//in memory, two integers are created
// the reference a is being changed
Integer a = 10;
a = 20;
```

```text
















```
