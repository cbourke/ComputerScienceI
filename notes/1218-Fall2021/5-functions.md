
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
  *

```text





```
