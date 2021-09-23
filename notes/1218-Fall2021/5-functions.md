
# CSCE 155E - Computer Science I
## Functions
### Fall 2021

An introduction to functions in C.

* A *function* is a reusable unit of code that may take *input(s)* and *may* produce an *output*
* Similar to math functions:
  $$f(x) = x^2$$
* The input is $x$, the output is $y = x^2$
* $f(x,y)$, $f(x, y, z), f()$
* Already seen a lot of functions: `sin(), sqrt(), pow(), printf(), main()`
* Functions facilitate *code reuse*: you don't have to copy-pasta code (cut and paste code), instead you can put that code into a function, and simply use and reuse the function
* Procedural abstraction:
  * How does `sin()` compute the square root?
  * Taylor Series?  Numerical Interpolation, something else?
  * Who cares?  You simply want to use the functionality
  * The functionality is *encapsulated* inside the function and we don't have to worry about the details
  * Using and defining functions allows you to reduce your *cognative load*
* Standard libraries and *external* libraries provide useful functions that have a lot of testing, debugging, and optimization behind them: USE IT!
* Feeds into an overall problem solving strategy: Don't reinvent the wheel, use an *existing* off-the-shelf solution or *adapt* an existing solution

## Functions in C

* As with variables, functions in C have to be *declared* before they can be used
* In C you "declare" a function by creating a *prototype*
* A prototype in C is a function's *signature*
  * The name of the function called an *identifier*
  * A list of inputs called parameters or "arguments": includes both the number of arguments and their *type*
  * The return variable *type* (we use the keyword `return`)
* Example: design a function to round a number to the nearest cent
* After you have a prototype, you can *use* the function
* BUT the prototype does *not* define what the function actually does
* You now need to provide a function *definition*
* Definition: repeats the signature and then provides a function *body* surrounded by curly brackets!
* Documentation is *required* and belongs on the prototype, NOT the definition: DRY
* DRY = Don't Repeat Yourself
* Prototypes end with a semicolon
* Observation: any variable declared inside of a function has a *local scope*: it only exists inside that function, not outside nor in other functions
* You use the keyword `return` to return a value or expression
* Not only does our function provide new functionality, it illustrates code reuse itself: a function can call a function (`roundToCents` calls `round`)

## Creating a Library: Modularity

* Demonstration:
  * separate my "utility" functions into different files
  * prototypes will go into a *header* file with the extension `.h`
  * Definitions will go into *source* files with extensions `.c` (but generally the same base file name)
  * You compile the *library* file into an object file using:

  `gcc -c utils.c`
  * This produces an *object* file, `utils.o`
  * You compile the entire program into an executable using:
  `gcc loan.c utils.o -lm`
  * The `-lm` at the end for ubuntu/CS50 IDE

## Misc

* Advanced topic: `makefile`s
* Misc: the `void` keyword can be used to specify that a function does return any values
* Generally in a `void` function you still have a `return;` statement but with no value returned
* You can also define functions that don't take any input at all: `int foo() { ... }`

### How are parameters passed to functions?

* Programs have a *program stack*: it is a LIFO= Last-In First-Out data structure
* IN a stack you can add something to the "top" (pushing) or remove something from the "top" (popping), but not inbetween; you only interact with a stack at the "top"
* Everytime a function is called a new *stack frame* is created and placed on the top of the "call stack" or "program stack"
  * All local variables and all parameter variables are allocated and exist only inside the function's stack frame
  * When a function is done executing, its stack frame is "popped" off the top and control is returned to the calling function
  * All variables in the stack frame are "destroyed"
* Can a function "swap" values passed to it?
  * No, because the variables are *passed by value*

### How are parameters passed to functions?

* By default, variables are *passed by value*
* When a function is called, the value(s) stored in a variable are copied and passed to the function
* The parameter variables are *completely different* variables, they receive *copies* of the values of the original variables
* Any changes to the variables *inside* the function are not seen by the calling function
* If you *really really* want to write a function that changes the values of the variables in another function, you need to pass them differently
* Instead of passing by value, we *pass by reference*
* Pass by reference: we'll pass memory addresses of the variables instead of the variable's values
* To do this, we need to talk about *pointers*

## Pointers In C

```c

  //regular old variable declaration:
  int x = 42;

  //create a *pointer* variable: a variable
  // that can point directly to a memory location
  int *pointerToX;

  //the above variable, poitnerToX is a pointer
  // variable that *can* point to any integer value

  //At this point, what does pointerToX point to?
  //  we have no idea; it could be:
  //  NULL (the pointer that points to "nothing")
  //  random memory location that belongs to us (we could corrupt our own memory
  //  random memory location that *doesn't* belong to us (segfault)
  // pointerToX is an *uninitialized pointer* and working with it
  //  will result in "undefined behavior"

  // you can make pointerToX point to NULL using:
  pointerToX = NULL;
  //you can also check for NULL:
  if(pointerToX == NULL) {
    printf("Safety issue: cannot do anything with a null pointer!\n");
  }

  //you can make pointerToX point to x as follows:
  //  the ampersand in front of a variable is the
  //  *referencing operator*: it gives you the memory
  //  location of that variable
  pointerToX = &x;

  printf("pointerToX points to memory location %p\n", pointerToX);
  printf(" the value stored at x is %d\n", x);

  //the following makes pointerToX point to memory location
  // 42 (the value stored in x):
  pointerToX = x;
  printf("pointerToX points to memory location %p\n", pointerToX);
  printf(" the value stored at x is %d\n", x);

  //you can change the value in x using:
  x = 101;
  printf("pointerToX points to memory location %p\n", pointerToX);
  printf(" the value stored at x is %d\n", x);

  //you can change the value of x through its pointer:
  // *pointerToX is a *dereferencing* operator: it changes
  //  a pointer variable into a regular-old-variable
  *pointerToX = 17;
  printf("pointerToX points to memory location %p\n", pointerToX);
  printf(" the value stored at x is %d\n", x);

  //Why would you ever want a pointer when you can
  // directly change the value of an variable using
  // the regular old assignment operator
  x = 17;

```

* Observations:
  * When we used `scanf("%d", &x)` we used the ampersand to pass in `x` by reference: so that scanf could read the input and place the value into the original variable `x`
  * Passing by reference essentially passes a "bucket" to the function: with the bucket, the function can put stuff in, take stuff out, etc.
  * Manipulating uninitialized variables or even `NULL` or invalid pointers will lead to a segmentation fault
  * Remember what Bret Hart said


### Summary of Pointers

  * A pointer is a memory address or a *reference* to a memory address
  * A pointer variable can be declared using the star operator: `int *ptrToA`
  * It is best to initialize pointers or at least make them point to `NULL`
  * To make a pointer variable into a regular old variable use the `*` (*DE* reference it)
  * To make a regular variable into a pointer (memory address) use the `&` (*REF*erence it)
  * Don't make pointers point to things they shouldn't point to

```c
//regular old variables:
double y = 3.14;
//pointer variable:
int *p = &y;
printf("p points to memory location %p\n", p);
printf(" what is stored there?  %d or %f\n", *p, *p);

//make a valid pointer to y:
double *q = &y;
printf("q points to memory location %p\n", q);
printf(" what is stored there?  %f\n", *q);
```





```text








```
