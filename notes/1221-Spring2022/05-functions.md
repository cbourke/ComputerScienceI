
# ECEN 1940 - Computer Science I
## Functions
### Spring 2022

Introduction to functions in C

* A *function* is a reusable unit of code that may take *input(s)* and *may* produce an *output*
* Similar
  $$f(x) = x^2 + 4$$
* The input is $x$, the "name" is $r$ and the output is
$y = x^2 + 4$
* $f(x,y)$, $f(x,y,z)$
* How many outputs can a "function" have?
* Some functions in C: `main()`, `sqrt()`, `printf()`
* Functions facilitate *code reuse*: you don't copy-pasta pieces of code (cut and paste), instead, you can put that code into a reusable function and then simply "call" or "invoke" the function
* Procedural Abstraction
  * How does `sin()` work?
  * Emperical measures, Taylor Series, interpolation methods, etc. etc.
  * Real answer: who cares?
  * We just want to use the function!
  * Abstraction = don't have to worry about those details
  * The details are *encapsulated* inside the function and we don't have to worry about it
* Standard library functions:
  * Don't reinvent the wheel
  * They are well tested, highly efficient, well designed, etc.
* Feeds into an overall engineering strategy: you ask whether or not the problem has already been solved or if you can adapt an existing solution to solve it

## Functions in C

* As with variables, functions in C have to be *declared* before you can use them
* You *declare* a function by defining a prototype
* A prototype in C is a function's *signature*
  * The name of the function *identifier*
  * A list of the function's inputs or *parameters* or *arguments*
  * You also define the function's *return type*
  * You use the `return` keyword to end the function and return control flow back to the *calling function*
* Examples: agm
  * We create a prototype and
  * Document it (all documentation belongs on the prototype): DRY = Don't Repeat Yourself; documentation belongs in one place and one place only
  * After you ahve defined the prototype, you need to specify what the function does
  * You repeat the signature and provide a *function body* within curly brackets

  ### Observations

  * Any variable(s) declared inside a function are *local* to that function
  * The variables only exist inside that function: their scope is limited

## Creating a Library: Modularity

* Not all functions should be in one source file
* instead, you separate them:
  * Prototypes + documentation go in a *header* file with a `.h` extension
  * Definitions are put into a separate *source* file with a `.c` extension but the same base name
  * Ex: `utils.h` and `utils.c`
* How do you build a custom library?
  1. separate the prototypes and definitions into header and source files
  2. `#include` your own header file using double quotes: `#include "utils.h"`
  3. Compile: you compile (but not link) your own library file:

  `gcc -c utils.c`

  which produces an *object* file
  4. Compile your utility library and your main program:

  `gcc agm.c utils.o -lm`

* Advanced solution: build system such as `make`
* You can define functions that do not return a value, they are called "void" functions and the return type should be indicated as `void`
* You should still use `return;`
* You can have functions that take no input: `int foo()`
* Combination: `void printMenu()`

### How Do Functions Work?

* Programs have a *program stack*: its a LIFO = Last In First Out data structure
* IN a stack you can add something to the "top" (pushing) or remove something from the "top" (popping), but not inbetween; you only interact with a stack at the "top"
* Everytime a function is called, a new *stack frame* is created and placed on top of the "call stack"
  * All local variables inside a function as well as parameter variables exist only in their *stack frame*
  * When a function is done executing and control is returned back to the *calling function*, it is a simple matter of popping off the stack frame
  * All variables in the stack frame are "destroyed"
  * Consequence: you cannot make changes to variables in the calling function because variables are *passed by value*
  * Copies of the values of the variables are given to the function!

* Demonstration

```c
double sum(double a, double b) {
  double x = a + b;
  return x;
}

double average(double a, double b) {
  double y = sum(a, b) / 2.0;
  return y;
}

int main(int argc, char **argv) {
  double n = 10.0;
  double m = 16.0;
  double ave = average(n, m);
  printf("average = %f\n", ave);
  return 0;
}
```

### Passing By Reference

* Suppose we *really really* want to write a functioning `swap()` function
* To do so, we need to pass actual variables, not copies of their values to a function
* To do that, we need a *reference* or *pointer* to a variable
* A *pointer* in C is a memory address

### Pointers In C

```c
//create a regular old variable:
int a = 42;
double b = 3.14;

//create a pointer variable: a variable
// that doesn't hold a value but instead holds a
// memory address:
int *pointerToA;

//pointerToA is a pointer variable that can
//point to an integer variable

//if you want a pointer to a double:
double *pointerToB;

//at this point, neither pointer points to
// anything in particular; it could point to
// invalid memory or memory that doesn't belong
// to your program

// it is generally best to initialize your
// pointers:
pointerToA = NULL;

//you can check for null pointers:
if(pointerToA == NULL) {
  printf("something happened!\n");
}

//to make a pointer point to a *valid* memory
// location you need the referencing operator
pointerToA = &a;

//the referencing operator, & gets the memory
// address of a variable
printf("pointer points to memory location %p\n", ptrA);
printf("the value stored there is %d\n", a);

//you can also manipulate a variable through
// a pointer to it

//will this work?
// No: it makes the pointer point to memory location
//    101, which likely does not belong to you!
pointerToA = 101;

// instead, you can *dereference* a pointer:
*pointerToA = 101;
// the star makes a pointer variable into a
// regular old variable!


```

* Observations:
  * When we used `scanf("%d", &x)` we used the ampersand to pass in `x` by reference: so that scanf could read the input and place the value into the original variable `x`
  * When a pointer gets passed to a function, the memory address is passed
  * Consequently: the function can access that memory and can thus make changes to teh contents of that memory!
  * It also allows us to "return" multiple values from a function
  * passing by reference essentially means you are passing a shared "bucket" that the function can fill with a value
  * Manipulating uninitialized variables or even `NULL` or invalid pointers will lead to a segmentation fault
  * Always remember what Bret Hart said


### Summary of Pointers

  * A pointer is a memory address or a *reference* to a memory address
  * A pointer variable can be declared using the star operator: `int *ptrToA`
  * It is best to initialize pointers or at least make them point to `NULL`
  * To make a pointer variable into a regular old variable use the `*` (*DE* reference it)
  * To make a regular variable into a pointer (memory address) use the `&` (*REF*erence it)
  * Don't make pointers point to things they shouldn't point to




```text











```
