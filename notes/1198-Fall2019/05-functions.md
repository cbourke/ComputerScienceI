
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

* By default, variable values are *passed by value* to functions in C
* When a function a function is called, *copies* of the variables' values are passed to the function, NOT the variables themselves
* Any changes to the parameter variables inside the function are not "seen" or "realized" in the calling function
* Suppose I *really* want a function to make changes to the original variables (swap them, manipulate them, etc.)
* You need to create a function that passes variables *by reference*
* To do this, we first need the concept of *pointers* in C

## Pointers in C

* Every piece of data in a program or a computer is stored in *memory*
* Memory has both an *address* and *contents*
* You can access contents by using a regular old variable `int a = 42;`
* You can access the *address* of a memory location using a *pointer* variable
* To declare a pointer variable you use the star operator: `*`

```c
//regular old variable declaration:
int a = 42;
//this declares a pointer variable that can point
// to a memory location that contains an int
int *pointerToA;
```

* At this point, `pointerToA` does not necessarily point to anything, it could:
  * point to an invalid memory location
  * point to a memory location that doesn't belong to you
* It is best practice to initialize a pointer to a valid memory location or, failing that, to `NULL` 
* Example:

```c
int *pointerToA = NULL;

if(pointerToA == NULL) {
  printf("invalid pointer!\n");
}
```

* How do you make a pointer point to a valid memory location
* A variable's name is its "content"
* To get a variable's memory location use the referencing operator: `&`
* Example:

```c
//this makes pointerToA "point" to the variable a
pointerToA = &a;
```

* If you have a regular variable, to get its memory address you use the referencing operator: `&`
* If you have a pointer variable, to access its contents (change it in to a regular old variable): use the dereferencing operator: `*`
* Revisit: swapping demo
* You can have a pointer variable point to any other type of variable:

```c
int a = 42;
double b = 3.5;
int *ptrToA = &a;
double *ptrToB = &b;
```

### Pitfalls

* You cannot arbitrarily assign values to a pointer:
```c
int a = 42;
//unitialized, could point to garbage, or anything
int *ptrToA;
//points to an invalid memory location or a memory location
// that does not belong to us:
ptrToA = 1234;
//the following is also wrong:
ptrToA = a;
```

* all of the above will likely (hopefully) result in a segmentation fault
* Even if it doesn't result in a seg fault, you might be corrupting your own memory!

### Summary

* Recall that `scanf("%lf", &b);` used an ampersand: why?
* Scanf is passing a variable by reference
* Functions that take pointer variables can make changes to the original variable if needed
* Referencing operator: regular variable into a pointer variable (`&`)
* Dereferencing operator: pointer variable into a regular variable (`*`)
* Pointers allow you to free up the return value: instead of returning a result, you can set the values of a pointer or multiple pointers!
* You can write functions that "return" multiple values

```c
double firstRoot(int a, int b, int c) {

  return (-b + sqrt(b*b - 4*a*c)) / (2*a);
}

double secondRoot(int a, int b, int c) {

  return (-b - sqrt(b*b - 4*a*c)) / (2*a);
}

void computeRoots(int a, int b, int c, double *root1, double *root2) {
  *root1 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
  *root2 = (-b - sqrt(b*b - 4*a*c)) / (2*a);
  return;
}

int main() {
  int a = 0;
  int b = 1;
  int c = 30;
  double root1, root2;
  //root1 = firstRoot(a, b, c);                                                         
  //root2 = secondRoot(a, b, c);                                                        
  computeRoots(a, b, c, &root1, NULL);
  printf("roots: %f, %f\n", root1, root2);

  return 0;
}
```







