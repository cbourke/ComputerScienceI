
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

### In C


```text










```
