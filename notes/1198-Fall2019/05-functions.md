
# CSCE 155E - Computer Science I
## Functions
### Fall 2019

An introduction to functions in C.

* A *function* is a reusable unit of code that may take *input(s)* and *may* produce an *output*
* Similar to math functions:
  $$f(x), f(x, y), f()$$
* Already familiar with several functions: `sin(), round(), printf(), scanf(), main()`, etc.
* Functions facilitate *code reuse*: you don't copy-paste (cut and paste), you don't want to reinvent the wheel
* Procedural Abstraction: functions allow you to ignore implementation details of how a certain block of code works, you can *just use it*
* Functions *encapsulate* functionality into reusable *abstract* units of code
* Standard libraries and external libraries provide useful functions that have a lot of testing, debugging and optimization behind them, don't throw those resources away!
* Feeds into an overall problem solving strategy: is there a function that does this task for me already?  Or, failing that, is there a function that can help me partially solve this task?

## Functions in C

* As with variables, functions have to be "declared" before you can use them
* In C you "declare" a function by creating a *prototype*
* A prototype is a declaration that defines a functions *signature*
  * The name of the function (identifier)
  * The list of its inputs called "parameters" or "arguments"
  * The type of variable that the function outputs or `return`s
* Example:

```c
/**
 * This function rounds the given amount to the 
 * nearest hundredth (ie the nearest cent) and
 * returns the value.
 *
 */
double roundToCents(double amount);
```

* Prototypes end with a semicolon
* Documentation is usually written *above* a prototype
* DRY: don't repeat yourself: documentation should only be located in one place, and the most appropriate place in C is with the prototype
* Later on in the program you actually define what the function does
* Example: you repeat the function signature and provide a function *body*

```c
double roundToCents(double amount) {
  double result = round(amount * 100) / 100;
  return result;
  //return round(amount * 100) / 100;
}
```

* Observe: not only does our function provide new functionality, but it illustrates code reuse itself: it uses the math library's `round` function!
* The function specifies the output value or "return value" using the keyword `return` and then the value you want to return.
* The `result` variable is a *local variable*: the *scope* of the variable is limited to the function itself
* In general you can create as many local variables as you want or none at all!
* In addition, the parameter variable itself (in this case `amount`) is *local to the function*

## Creating a Library: Modularity

* Demonstration: create another more general round function

```c
/**
 * This function rounds the given value to a decimal
 * places defined by the given digit.
 * For example for 
 *   value = 123.456 and digit = 2 it would round to 100
 *   value = 123.456 and digit = 0 it would round to 123
 *   value = 123.456 and digit = -2 it would round to 123.46
 */
double roundToDigit(double value, int digit);
```

```c
double roundToDigit(double value, int digit) {
  int power = pow(10, digit);
  return round(value / power) * power;
}
```

* In general, prototypes (along with their documentation) are placed in *header* files, files ending in `.h`
* Function definitions are placed in separate source files with the same base name but with a `.c` extension
* You can compile (without linking) the library using the `-c` flag which produces an object file, `roundUtils.o`
* In general you should use `#include "userLibrary.h"` in your code using the double quotes for user-defined libraries
* To compile into an actual executable program: use
`gcc roundUtils.o roundDemo.c` (ie include all object files in the command)
* In general you want to perform good, rigorous and *automated* testing of your functions called "unit testing"
* In general you want to use a formal unit testing framework (ex: cmocka)
* Design Tip: functions should be reused as much as possible, functions should call other functions when appropriate (DRY)
* More specific functions can call more general functions

## Other Issues

### Function Overloading

* In C, when you create a function, that function is "globally scoped": the function exists everywhere
* Consequently: you cannot name two functions with the same name
* Polluting the namespace: once you have reserved a name for a function, that name cannot be used by any other function
* Some languages allow you to not have to do this: they support "Function Overloading"
* Ex: in the math library there are several absolute value functions: `abs(int), fabs(double), labs(long)`
* Without function overloading you are forced to name your functions with different prefixes or suffixes
* In practice: you resolve pollution of the name space by using prefixes or suffices, `gtk_create_window`

### The `void` keyword

* Functions that return no value are called `void` functions
* When you declare such a function, use the keyword `void` as the return type
* You *still* *should* have a return statement: `return;`
* Functions with no input parameters can also use the `void` keyword:
```c
void foo(void);
//in general it is better to OMIT the void keyword for parameters:
void foo();
```

## How do functions actually work?

* Programs have a *program stack*: it is a LIFO = Last in First Out data structure
* The only operations allowed are: push (placing something on top of the stack); pop: removing something from the top of the stack
* No access to "middle" elements is allowed
* Each time a function is called, a new *stack frame* is created and placed on top of the program stack
* Each time a function returns (to the calling function) the top most stack frame is popped



