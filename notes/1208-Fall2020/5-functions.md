
# CSCE 155E - Computer Science I
## Functions
### Fall 2020

An introduction to functions in C.

* A *function* is a reusable unit of code that may take *input(s)* and *may* produce an *output*
* Similar to math functions:
  $$f(x) = x^2$$
* The input is $x$, the output is $y = x^2$
* $f(x,y)$, $f(x, y, z), f()$
* Already seen a lot of functions: `sin(), sqrt(), pow(), printf(), main()`
* Functions facilitate *code reuse*: you don't have to copy-pasta code (cut and paste code), instead you can put that code into a function, and simply use and reuse the function
* Procedural abstraction: 
  * How does `sqrt()` compute the square root?
  * Who cares?  You simply want to use the functionality
  * Using functions allows you to ignore implementation details of how certain blocks of work, you just *use it*
* Functions *encapsulate* functionality into reusable *abstract* units of code
* Standard libraries and *external* libraries provide useful functions that have a lot of testing, debugging, and optimization behind them: USE IT!
* Feeds into an overall problem solving strategy: Don't reinvent the wheel, use an *existing* off-the-shelf solution or *adapt* an existing solution

## Functions in C

* As with variables, functions have to be "declared" before you can use them
* In in C you "declare" a function by creating a *prototype* 
* A prototype is a declaration that defines the functions *signature* 
  * The name or *identifier* of the function
  * The list of its inputs called "parameters" or "arguments" (the number or "arity" of the inputs and their *type*)
  * The variable *return type* that the function `return`s
* Example:

```c
/**
 * This function rounds the given amount to the
 * nearest cent (nearest hundredth).
 */
double roundToCents(double amount);
```

* Prototypes end with a semicolon
* Documentation is provided for *every* function right above the prototype (we highly suggest you use doc-style comments)
* DRY: don't repeat yourself: don't repeat documentation (there should only be one copy and it should be associated with prototypes)
* Later on in the program you need to actually define what the function does
* Syntax: you repeat the function signature and instead of a semicolon you provide a function *body* (surrounded by curly brackets)

```c
double roundToCents(double amount) {
  double result = round(amount * 100.0) / 100.0;
  return result;
  result += 10;
}
```

* Observation: any variable declared inside of a function has a *local scope* 
* In this case, the variable `result` only exists inside the function `roundToCents`
* You can use the keyword `return` to return a value to the calling function
* A `return` statement does *NOT* return the variable, it only returns the *value* stored in the variable at the point of return
* Not only does our function provide new functionality, it illustrates code reuse itself: a function can call a function (`roundToCents` calls `round`)
* The function specifies the output value or "return" value using the keyword `return`

## Creating a Library: Modularity

* Demonstration: create another more general round function; a function that can round to the nearest tenth, hundredth or even in reverse (nearest tens place, hundreds place, etc.)

```c
/**
 * This function rounds the given value to a decimal
 * place specified by the given digit.  
 * 
 * For example:
 *  value = 123.456 and digit = 2, it would 
 *  round to 10^2 -> 100
 *  value = 123.456 and digit = 0, it would 
 *  round to 10^0 -> 123
 *  value = 123.456 and digit = -2, it would
 *  round to 10^-2 -> 123.46
 */
double roundToDigit(double value, int digit);
```

* Later on...

```c
double roundToDigit(double value, int digit) {
  int power = pow(10, digit);
  double result = round(value / power) * power;
  return result;
}
```

## Next Step: Modularization

* In general, you don't want huge source files or "god" files
* You want to organize your code into separate files so that similar functionality is grouped together and organized
* Each unit or "module" of code is defined with a *header* file and a *source* file
* Header files:
  * Contain the prototypes and documentation
  * They are still C source files but they end with `.h`
* Source files:
  * Contain the function definitions (bodies)
  * They `#include` the header file
  * They are named with the same root file name but end with `.c`
* Example: reorganize our "round" library functions
  * Move the prototypes into a file called `round.h`
  * Move the definitions into a file named `round.c`
  * In `round.c` we used `#include "round.h"` (to include the prototypes)
  * How did we compile everything
    * Compiled our library using `gcc -c round.c` (which produced a `round.o` object file)
    * Compiled into an executable using `gcc round.o demo.c -lm`
* Advanced topic: `makefile`s
* Misc: the `void` keyword can be used to specify that a function does return any values
* Generally in a `void` function you still have a `return` statement but with no value returned
  
## How do functions actually work?

* Programs have a *program stack*: it is a LIFO = Last-In First-Out data structure
* You interact with items on a stack at the *top* of the stack
  * You put things on top of the stack by "pushing" them onto the top of the stack
  * You retrieve things from the top of the stack by "popping" them off the top of the stack
  * There is no "middle" retrieval or insertion allowed
* Everytime a function is called, a new *stack frame* is created and placed on top of the "call stack" or "program stack"
  * All local variables and all parameter variables are allocated and exist inside each stack frame
  * When a function is done executing, its stack frame is "popped" off the top, returning to the last called function

### How are parameters passed to functions?

* By default, variable values are *passed by value* to functions in C
* When a function is called, the value(s) stored in a variable are passed to the function
* The variables themselves are *not* passed to the function
* When a function is called, *copies* of the variable's value(s) are passed to the function
* Any changes to variables in a function are not apparent or seen by the calling function
* Suppose I *really* wanted to write a function to change the values of the original variables
* We need to create functions that pass the *variables* (or *references* to the variables) so they can be manipulated
* We need to create functions that are *pass-by-reference*
* To do this, we need to talk about *pointers*

## Pointers in C

```c
//regular old variable declaration:
int x = 42;
//create a pointer variable that
//can point to a memory location that
// contains an int value:
int *pointerToX;
```

* A tthis point, `pointerToX` does not necessarily point to anything; it *could* point to:
  * an invalid memory location
  * point to a valid memory location that doesn't belong to you
  * point to a valid memory location that *does* belong to you but you still shouldn't do anything with it (its okay as far as the OS is concerned to screw up your own memory)
* The above is what is known as an *uninitialized pointer*; you don't want this
* It is best practice to make pointers point to something or, failing that at least point to `NULL`

```c
//you can create/initialize it to NULL:
int *pointerToX = NULL;

//later on you can make it point to an actual variable
// to do so, you use the referencing 
// operator: &
// make pointerToX point to x:
pointerToX = &x;
```

* The ampersand is the *referencing operator* it gives you the memory location (address) of the variable you attach it to
* `x` is the regular old variable, `&x` is the memory address of `x`
* YOu need to make sure you are not illegally accessing memory or accessing invalid memory
* If you do, then it could lead to a `segmentation fault`
* You can check for `NULL` pointers:

```c
int *pointerToX = NULL;

if(pointerToX == NULL) {
  printf("invalid null pointer!\n");
}
```

* Once you have a pointer variable you may need to access or modify the contents of the memory that it points to
* You may need to change a pointer variable into regular variable 
* To change a pointer into a regular old variable, use the *dereferencing operator*: use the `*` operator
* Using pointers you can now create a function that passes variables *by reference*: we'll pass the memory locations of variables so that the function can directly manipulate the contents of memory!

### Summary of Pointers

* A pointer is a memory address or a *reference* to a memory address
* A pointer variable can be declared using the star operator: `int *ptrToA`
* It is best to initialize pointers or at least make them point to `NULL`
* To make a pointer variable into a regular old variable use the `*` (*DE* reference it)
* To make a regular variable into a pointer (memory address) use the `&` (*REF*erence it)

## Overall Summary

* Recall: we had to use `scanf("%lf", &b)`: we had to use the ampersand
* `scanf` is a pass-by-reference function; we pass in teh memory location(s) of the variables we want the value stored in
* Pointers can be used now with respect to arrays, strings, and dynamic memory
* We can now also write functions that "return" multiple values: we pass in multiple variables by-reference and multiple values could be stored in those variables (same effect as returning multiple values)
* This also frees up the return value: we no longer have to design functions to return values, instead we can now use the return type to indicate any potential errors encountered

* Motivation:

* Suppose you wanted to write a function to compute the roots of a quadratic equation: without pointers you have to write two functions (one for each root)

## Demonstration

* Write a function that "returns" multiple values: write a function
to convert a given number of `totalSeconds` into `hours`, `minutes`, `seconds`
So 12282 seconds $\rightarrow$ 3:24:42

* Write a function to compute the inflation-adjusted rate of return and
deal with potential input errors 

$$\frac{1 + \textrm{rate of return}}{1+\textrm{inflation rate}} - 1$$



```text






```