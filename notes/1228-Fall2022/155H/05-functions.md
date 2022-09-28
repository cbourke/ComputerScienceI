
# CSCE 155H - Computer Science I Honors
## Functions & Methods
### Fall 2022

* A *function* is a reusable ***unit*** of code that may take input(s) and may produce an output
* Already familiar with functions: `main(), printf(), sqrt()`, etc.
* Familiar with functions from math: $f(x) = x^2$
  * Name: $f$
  * Input: $x$
  * Output of the function?  $y = f(x)$
  * You can also have multivariate functions: $f(x, y)$, $f(x, y, z)$, $f()$
* Functions facilitate code reuse: you don't have to copy-pasta chunks of code; instead you put them into a function and then *call* or *invoke* the function
* DRY Principle: Don't Repeat Yourself!
* Procedural Abstraction:
  * How does `sin()` work?
  * Who cares?  It just works (Taylor Series, interpolation)
  * We just want to use the functionality without having to worry about the details
* By *encapsulating* functionality into a function, we don't have to think about the details
  * Standard libraries and external libraries come with a LOT of testing, debugging, optimization, etc.  That you cannot hope to replicate
  * Generally you don't want to "roll your own" functionality unless you have to
  * You don't reinvent the wheel
  * When faced with a problem: what is the first question you ask?
  * A: is it already solved (or at least mostly solved)
  * Always look for "off the shelf" solutions

## Functions in C

* As with variables, functions must be declared before you can use them
* Declaring in C means writing a prototype
  * A prototype in C is a *signature*
    * The function's name
    * The function's input and types
    * THe function's output type
  * WHen you create a function, always document it with doc-style comments
* Later on, you provide a function *definition*:
  * repeat the signature
  * No semicolon: instead you provide a function *body* using `{...}`
* Convention: use `lowerCamelCasing` for function names
* use the `return` keyword to return a value from the function to the *calling function*
* WHen the function returns a value, control is returned back to the calling function
* Any variables inside the function are *local* to the function (scoping)

## "Functions" in Java

* Technically in Java, functions are *methods*
* In Java everything is a class or belongs to a class; therefore "functions" that belong to a class are (fancily called) methods
* For now: we'll restrict our attention to `public static` methods: methods that "belong" to the class
* To invoke a method you use the class name + dot + name of the function
  * Ex: `Math.sqrt(), MyMath.agm()`

## Other Issues/Items

* A method or function that doesn't return anything is a `void` function
  * You can make the return type `void` to indicate that it returns nothing
  * Even if you don't need to, you should still have an emtpy return statement: `return;`
* You can have a function that has no input: the "parameters" (inputs) will not exist

### Function Overloading

* In C, to compute the absolute value, you can use `abs(), fabs(), labs(), llabs()`, etc.
* Each function operates on a different type: `int, double`, etc.
* In C, you have to use different function names because C does not support *function overloading*: being able to define multiple functions with the same name
* Java does support *function overloading*: it uses "static dispatch" at compile time to deduces which method actually gets called
* Because of this, you should be very careful in C about *polluting the namespace*

## Modularity

### In Java

* Similar methods are collected into classes
* Classes are organized/collected into packages
* Packages provide a hierarchical directory structure that allows you to origanize your code

### In C

* In general, similar functions are separated into different *modules*
* We organize user-code into separate files:
  * Prototypes + documentation go into *header files* with a `.h` extension
  * Place the definitions/implemenations into *source* files with a `.c` extension and the same base file name
  * We use `#include "myMath.h"` in any file that we want to bring the prototypes into
  * To compile the module: `gcc -c myMath.c` which produces an object file: `myMath.o`
  * To compile the program and link into our library you use:

  `gcc demo.c myMath.o -lm`

### How do functions actually work?

* Programs have a *program stack* (or *call stack*)
* IN a stack you can add something to the "top" (pushing) or remove something from the "top" (popping), but not inbetween; you only interact with a stack at the "top"
* Everytime a function is called, a new *stack frame* is created and placed on top of the "call stack"
  * All local variables inside a function as well as parameter variables exist only in their *stack frame*
  * When a function is done executing and control is returned back to the *calling function*, it is a simple matter of popping off the stack frame
  * All variables in the stack frame are "destroyed"
  * Consequence: you cannot make changes to variables in the calling function because variables are *passed by value*
  * Copies of the values of the variables are given to the function!

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
* tests should be repeatable
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
  * *formal* unit testing in Java

## C: Pointers

* Recall that our `swap()` function failed due to *how functions work* (demo)

```c

void swap(int a, int b) {
  printf("a, b = %d, %d\n", a, b);
  int temp = a;
  a = b;
  b = temp;
  printf("a, b = %d, %d\n", a, b);
}

int main(int argc, char **argv) {

  int a = 10;
  int b = 20;

  printf("a, b = %d, %d\n", a, b);
  swap(a, b);
  printf("a, b = %d, %d\n", a, b);

  return 0;
}
```

* Every piece of data in a computer is stored in memory
* Memory consists of an address (location) and its contents (the actual data stored)
* In C you can refer to an address using a *pointer* or a "reference variable"
* A pointer stores a memory location: an address rather than a value
* To create a pointer, use the `*` syntax

```c

  int x = 42;
  //creating an uninitialized pointer has undefined behavior:
  //  it can point to a memory location that doesn't belong to your program
  //  it can point to a memory location that doesn't exist, etc.
  int *ptrToX;
  //you can point a pointer to the NULL address:
  ptrToX = NULL;

  //you can test for nullity:
  if(ptrToX == NULL) {
    printf("invalid pointer\n");
  }

  //make the pointer point to the variable x:
  ptrToX = &x;
  // the ampersand gets the memory address of a regular variable

```

## Pitfalls

* Uninitialized pointers have undefined behavior: using invalid pointers can result in *segmentation faults*
* You should always make a pointer point to a valid memory location that *belongs to your program*

```c
int x = 42;
int *ptrToX;
ptrToX = x;

printf("x = %d\n", x);
printf("ptrToX = %p\n", ptrToX);
//you can get and manipulate the contents of what a poitner points to
// using the dereference operator: *
printf("the contents of memory location %p are %d\n", ptrToX, *ptrToX);

```

* Observe that you can convert a pointer back into a regular old variable (in order to assign a value or access its value) using the *dereferencing operator*: `*`
* Remember:
  * A regular variable can be changed to a pointer/reference using the `&`
  * A pointer variable can be changed to a regular old variable using the `*`
* So what: it allows you to pass variables *by reference* to a function; that function can then manipulate the original variables

* Another pitfall: make sure your pointer points to the correct type of variable
* An `int *` pointer can point to a memory location that stores an integer, but it *should not* point to any other type (`double, char`, etc.)
* A `double *` pointer can point to a memory location that contains a `double` but should not point to any other type

## Java

* Java has no pointers, you generally do NOT manipulate memory contents directly in Java
* BUT: by default all primitive types are passed by value
* IE: you *cannot* write a `swap()` method that works in Java!
* Also: all object types `String, Integer, Double` *ARE* passed by reference!
* You still cannot swap them!  Why?  Because *most* built-in types are *immutable*!

## Using Pointers: Passing By Reference

* Remember: `scanf()`
* With pass by reference you can "return" multiple values
* Even if you only have one result, it still is *might* be a good idea to use pass-by-reference...
* Freeing up the return value means that you can do proper *error handling* in C


```text










```
