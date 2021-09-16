
# CSCE 155H - Computer Science I Honors
## Functions & Methods
### Fall 2021

* A *function* is a reusable unit of code that may take input(s) and may produce an output
* Already familiar with functions: `main(), printf(), sqrt()`, etc.
* Familiar with functions from math: $f(x) = x^2$
  * Input: $x$
  * Output: $y = x^2$
  * You can also have multivariate functions: $f(x, y)$, $f(x, y, z)$, $f()$
* Functions facilitate code reuse: you don't have to copy-pasta chunks of code; instead you put them into a function and then *call* or *invoke* the function
* DRY Principle: Don't Repeat Yourself!
* Procedural Abstraction:
  * How does `sin()` work?
  * Taylor Series, Numerical Interpolation
  * A: who cares?  We simply want to use that functionality and NOT have to worry about the details
* By *encapsulating* functionality into functions, then we don't have to think about the details
* Standard libraries and external libraries come with a LOT of testing, debugging and optimization that you *cannot* hope to replicate!
* Generally you don't want to "roll your own" functionality unless you have to
* You don't want to reinvent the wheel
* Problem solving: when asked to solve a problem, what is the first question you should ask?
* A: is it already solved (or at least mostly solved)
* Always look for "off the shelf" solutions

## Functions in C

* As with variables, functions must be declared before you can use them
* In C you "declare" a function using a *prototype*
* A prototype declares a function's *signature*
  * Its identifier: its name
  * The type of variable it returns and
  * Any parameter types (inputs) it takes
* In general, every function should have doc-style documentation which is associated with the prototype
* DRY Principle = Don't Repeat Yourself

Observations:
* The prototype has no function "body": it ends with a semicolon
* Convention: use `lowerCamelCasing` for function names, and in general we use *verbs*
* Later on in your program, you *then* define what the function does by providing a function *definition*: repeat the prototype but instead of a semicolon you provide a function *body*
* The code in the function body is what is executed when you *call* or *invoke* the function
* Control flow is "handed over" to the function and it computes until it gets to a `return` statement...
* At which point control is given *back* to the calling function
* Any variables declared inside a function are *local* to that function and they have *local scope* to that function

## "Functions" in Java

* TECHNICALLY: functions in Java are called "methods"
* In Java everything is a class or belongs to a class; therefore "functions" that belong to a class are (fancily called) methods
* For now: we'll restrict our attention to `static` methods: methods that "belong" to the class
  * To invoke a method you need the class name + dot + the name of the function
  * Example: `Math.sqrt()`
* `public` methods can be "seen" and used by any code in your project
* Alternatives:
  * `private`: only the class can "see" it
  * `protected`: only the class and subclasses can "see" it
  * the abscence of a keyword is "package protected": only other classes in the same package can "see" it

## Other Issues/Items

* A method or function that doesn't return anything is a `void` function
  * You can make the return type `void` to indicate that it returns nothing
  * Best practice: you should *still* have a return statement: `return;`
  * You can create functions with no input: you just don't use the `void` keyword, you use empty parentheses:
    * `int foo(void)`

### Function Overloading

* In C, to compute the absolute value you can use `abs(), fabs(), labs(), llabs(),` etc.
* Those function each take a different type and return a different type
* In C you can only have one function with one particular name
* In *some* language (Java) you can have multiple functions with the same name but with different parameter types
* Example: in Java, the `Math` library contains 4 *different* `abs()` methods all with the same name
* Java allows/supports *method overloading*: the ability to have multiple functions with the same name
* At compile time, the Java compiler is able to deduce *which* function you intended to call based on what you pass it (this mechanism is called *static dispatch* )
* C does not support function overloading, thus it needs different names for each function: you cannot have two functions with the same name
* In C You end up either *polluting the namespace* or appending a common "tag"

## Modularity

### In C

* In general, similar functions are separated into different *modules*
* Why?  Organization, you only need to bring in particular libraries when you need them
* Code reuse: you can then publish your code as a library so that other people (or other programs) can use them
* Demonstration: create our own financial utilities library
* Separated the prototypes + documentation into a *header* file, with the extension `.h`
* Placed the function definitions into a *source* file with the same base file name but a `.c` extension
* We used `include "utils."` anywhere we need to bring in the prototypes
* We compiled (but did not produce an executable program) using:

`gcc -c utils.c`
which produced a (machine code) object file `utils.o`
* We compiled everything together using:

`gcc utils.o loan.c -lm`


```text




```
