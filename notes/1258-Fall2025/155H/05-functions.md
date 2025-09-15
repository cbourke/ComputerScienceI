
# CSCE 155H - Computer Science I Honors
## Functions & Methods
### Fall 2025

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
  * How does `sqrt()` work?
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
  * The type of variable it `return`s (output)
  * Any *parameters* or *inputs* or *arguments* to the function: the arity (number of arguments) and the types (`int, bool, double`, etc.)
* In general, the *documentation* of a function goes with the prototype:
  * You *should* use doc-style comments
  * DRY: you should not *repeat* documentation later on
  * Provide a description of what the function does and any expectations on its inputs
* Later on in the program, you provide a function *definition*:
  * Has no semicolon, instead...
  * It has a *repeated* signature
  * and a function *body* that is inside `{...}` and specifies the code that is run when the function is called
* once a function is defined you can use it anywhere in the program
  * You "invoke" or "call" a function
  * **Optionally**: you can capture the return value
  * Convention: use `lowerCamelCasing` for function names, and in general we use *verbs* (functions do things)
  * Control flow is "handed over" to the function and it computes until it gets to a `return` statement...
  * At which point control is given *back* to the "calling function"
  * Any variables declared inside a function are *local* to that function and they have *local scope* to that function

## "Functions" in Java

* In java; technically: we have "methods" not "functions"
* In Java: everything is a class or belongs to a class (OOP = Object Oriented Programming): functions are inside a class and therefore are "methods"
* For now: we'll restrict our attention to `static` methods
* `static` in this context means that the method belongs to the class, not to *instances* of the class
  * Simply: just use the class name + function name to invoke it
  * Ex: `Math.sin()`
* Java doe snot have prototypes: you include the documentation, signature and function body all in one spot
* Generally function are placed *above* the `main` if there is a `main`
* `public` simply means that all piece of code can "see" your function and use it

## Other Issues/Items


```text
















```
