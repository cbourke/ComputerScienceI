
# CSCE 155H - Computer Science I Honors
## Functions & Methods
### Fall 2024

* A *function* is a reusable unit of code that may take input(s) and may produce an output
* Often referred to as a "unit" when doing unit testing
* Math:
  * $y = f(x) = x^2$
  * $f(x,y) = x + 2y$
  * There is only ever at most ONE output to a function
  * You can also have multivariate functions: $f(x, y)$, $f(x, y, z)$, $f()$
* Functions facilitate code reuse: you don't have to copy-pasta chunks of code; instead you put them into a function and then *call* or *invoke* the function
* DRY Principle: Don't Repeat Yourself!
* Procedural Abstraction:
  * How does the `sqrt()` work?
  * Who cares?  we just want to use it
* By *encapsulating* functionality into functions, then we don't have to think about the details
* Standard libraries and external libraries come with a LOT of testing, debugging and optimization that you *cannot* hope to replicate!
* IE: "don't reinvent the wheel", "don't roll your own"
* Problem solving: when asked to solve a problem, what is the first question you should ask?
  * Does a solution already exist?
  * OR: does an "off the shelf" solution exist that can be *adapted*

## Functions in C

* As with variables, functions must be declared before you can use them
* In C you "declare" a function using a *prototype*
* A prototype is a function's *signature*:
  * Its identifier: the name of the function
  * The type of variable it `return`s
  * Any *parameters* or *arguments* or *inputs* to the function: the number (arity) and the types (`int, bool, double`, etc.)
* In general, the *documentation* of a function goes with the prototype:
  * You *should* use doc-style comments
  * DRY: you should not *repeat* documentation later on
  * Provide a description of what the function does and any expectations on its inputs
* Later on in the program, you provide a function *definition*:
  * Has no semicolon
  * Instead has a function *body*
  * The signature is *repeated*
* once a function is defined you can use it anywhere in the program
  * You "invoke" or "call" a function and
  * optionally: you can capture the return value
  * Convention: use `lowerCamelCasing` for function names, and in general we use *verbs* (functions do things)
  * Control flow is "handed over" to the function and it computes until it gets to a `return` statement...
  * At which point control is given *back* to the calling function
  * Any variables declared inside a function are *local* to that function and they have *local scope* to that function

## "Functions" in Java

* Technically: java has "methods" not "functions"
* In Java: everything is a class or belongs to a class (OOP = Object Oriented Programming): functions are inside a class and therefore are "methods"
* For now: we'll restrict our attention to `static` methods
* `static`: means that the method belongs to the class, not to *instances* of the class
  * To invoke a `static` method: you use the `ClassName.methodName()`
* Java doe snot have prototypes: you include the documentation, signature and function body all in one spot
* `public` simply means that all piece of code can "see" your function and use it

## Other Issues/Items
* A method or function that doesn't return anything is a `void` function
  * You can also use the return type `void` to indicate that a function doesn't return anything
  * Best practie:  you still should include an "empty" return statement: `return;`
  * You can create functions with no input: you just don't use the `void` keyword, you use empty parentheses:
    * `int foo(void)` instead prefer
    * `int foo()`
* Recall: that functions can only ever return ONE thing (otherwise they are not functions)

## Modularity

### In C

* In general, similar functions are organized into *modules* or "libraries"
* Why?  Organization, you only need to bring in particular libraries when you need them
* Libraries or "headers" (in C) should be *small*
* Code reuse: you can publish your library code so that other people, programs, etc. can use them!
* Demonstration:
  * Separate protoypes into header files: `.h` (files)
  * separate definitions into source files: `.c`
  * Compile them together: `gcc -c library.c`

```text













```
