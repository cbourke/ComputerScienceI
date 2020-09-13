
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
  
  
```text






```