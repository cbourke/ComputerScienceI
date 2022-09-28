
# ECEN 194 - Computer Science I
## Functions
### Fall 2022

Introduction to functions in C

* A *function* is a reusable ***unit*** of code that may take *input(s)* and *may* produce an *output*
* Similar
  $$f(x) = x^2 + 4$$
* The input is $x$ the "name" of the function is $f$ and the output is... $f(x) = y$
* Function with multiple inputs (multivariate functions):
  $$f(x,y), g(x,y,z)$$
* How many outputs can a "function" have?
* Likewise in code, you can have any number of inputs (including zero) but ONLY every 1 output (at most)
* In code the output value is `return`ed from the function
* Some functions in C: `main(), sqrt(), printf()`
* Functions facilitate *code reuse*: you don't copy-pasta pieces of code (cut and paste), instead, you can put that code into a reusable function and then simply "call" or "invoke" the function
* Procedural Abstraction:
  * How does `sin()` work in C or on your calculator: who cares?  It Just Works
  * We want to use the function and its functionality and not have to worry about the details
  * IF we have to *implement* a function, THEN we worry about the details, but once written, we're done worrying about the details
  * The details are *encapsulated* inside the function and we don't have to worry about it
* Standard Library Functions:
  * Don't have to reinvent the wheel
  * They are very well tested, optimized, efficient, well designed etc.
* The best engineering: when faced with a problem, what is the first question you should ask?  Did someone else already solve it?

## Functions in C

* As with variables, functions in C have to be *declared* before you can use them
* You *declare* a function by defining its *prototype*
* A prototype in C is the *signature* of the function
  * It is the name of the function
  * It is a list of parameters or inputs the function takes
  * It is a return value *type*: the type of variable the function returns (if any)
* Terminology:
  * When you "call" a function you *invoke* it (the code jumps into the function and executes code inside that function)
  * The function that "calls" a function is the *calling function*
  * When code in the function is done executing it *returns* to the calling function
* Example: write a function prototype for a function that computes the monthly payment of a loan
* Observations:
  * For now, we'll put our prototypes before the `main()` function (later we'll *modularize* our code into separate files)
  * The prototype ends with a semicolon `;`
  * You should *always* provide doc-style comments as documentation for every function
* After you have defined a prototype, you need to provide a *definition*: what the function actually does (what code is executed with the function is called)

* Observation:
  * C does not support "function overloading": no two functions may have the same name
  * This is why the math library has `abs, fabs, labs, llabs`, etc.
  * Consequently: you need to be very careful about the naming of your functions
  * Example: suppose you wanted to use two libraries, $A, B$, suppose both had named a function `init()`
  * Creating functions with "common" names *pollutes the namespace*: once you have a function `init()`, no other library or you may redefine the function `init()`
  * It is common for libraries to prepend their functions with a unique name: `gtk_init()`

## Create a Library: Modular Organization

* Collect common functionality (functions, variables, etc.) into a "module": a collection that is distinct and separate from other collections
* Simple organization
* How:
  * Prototypes and their documentation are separated into a *header* file with an extension of `.h`
  * Definitions are placed into a *source file* usually with the same name but an extension of `.c`
  * You should use the `#include "financial.h"` syntax to "include" a header file anywhere you intend to use the function declared in that file: note the diffrence, double quotes, not lange/rangle
  * To compile:
    1. To compile without linking, you use the `-c` flag;
    `gcc -c financial.c`
    2. This produces an object file, `financial.o` (machine language language file, binary)
    3. To compile all together: use
    `gcc loan.c financial.o -lm`
* If you want to, you can explore full *build systems*: `make`

## Misc

* A function that doesn't return anything is a `void` function: its return type is `void` and its return statement is `return;`
* You can have functions that do not take any input: `void printMenu()`

# Pointers

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

* WHen parameters are passed to a function, *copies* of the variable's values are passed dto the function, NOT the actual variables
* Any change to the copies is not seen or reflected in the calling function
* This is called *pass by value*: copies of the variable values are passed to the function
* I *really* want to solve this problem

## Pointers

* Everything (in particular data) in a computer is stored in memory
* Memory has two parts: and address and contents
* REgular old variables refer to the *contents* `double pi = 3.14;` will set the contents in *some* memory address
* Pointer variables can hold an *address* or a memory location or a "reference"

```c

    //these are regular old variable declarations
    int x = 42;
    double pi = 3.1415;

    //create pointer variables that can "point" to our other variables:
    int *ptrToX;
    double *ptrToPi;

    //at this point what do these pointers "point" to?
    //you can make a pointer point to somthing by using the assignment operator:
    ptrToX = NULL;

    //you can check for NULL using:
    if(ptrToX == NULL) {
        printf("Error: invalid memory!\n");
    }

    //now lets make it point to something *valid*:
    // the ampersand in front of a variable gives you the variable's memory addres
    ptrToX = &x;

    //you need to make sure that you use the right kind of pointers:
    // a pointer to an integer should point to an integer
    // a pointer to a double should only point to a double...
    ptrToX = &pi;

    //demo:
    // print the memory location of ptrToX and its contents...
    printf("ptrToX points to memory location %p and its contents are... %d\n", ptrToX, *ptrToX);

    //to get the value stored in the contents of a memory location
    // using its pointer, you use the dereferencing operator: *
    // ex: change the value of x using its pointer:
    ptrToX = &x;
    // dereferencing operator temporarily makes the pointer in to a
    // regular old variable so you can assign or access its value
    *ptrToX = 101;
```

* Observe:
  * You can take a regular old variable and gets its memory address (pointer) using the referencing operator: `&`
  * You can take a pointer variable and change it to a regular variable using the dereferencing operator `*`

## Pitfalls

* You should always initialize a pointer (to `NULL` if nothing else)
* Otherwise uninitialized pointers can point to anything!
* You do not assign literal values to a pointer: `int *ptr = 101;`
this makes it point to memory location 101 which likely does not belong to you, resulting in a seg fault
* Make pointers point to the correct type: `double *` to `double` values and `int *` to `int` values

### Summary of Pointers

  * A pointer is a memory address or a *reference* to a memory address
  * A pointer variable can be declared using the star operator: `int *ptrToA`
  * It is best to initialize pointers or at least make them point to `NULL`
  * To make a pointer variable into a regular old variable use the `*` (*DE* reference it)
  * To make a regular variable into a pointer (memory address) use the `&` (*REF*erence it)
  * Don't make pointers point to things they shouldn't point to

## Passing By Reference

* YOu can define functions that take pointer variables instead of regular old variables
* WHen you pass a variable to a funcition using a pointer, it is called *pass by reference*
* One use case: `scanf()`
* Another use case: you can now "return" multiple values!


```c

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void computeCircleStats(double radius, double *area, double *circumference) {

    *area = M_PI * radius * radius;
    *circumference = radius * 2 * M_PI;

    return;
}

int main(int argc, char **argv) {

    //goal: compute the circumference AND area of a circle given its radius
    double radius = 12.0;

    double area;
    double circumference;

    computeCircleStats(radius, &area, &circumference);
    printf("the area and circumference of a circle of radius %f are %f and %f\n", radius, area, circumference);

    return 0;
}
```

```text












```
