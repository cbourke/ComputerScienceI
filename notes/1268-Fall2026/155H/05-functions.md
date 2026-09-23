
# CSCE 155H - Computer Science I Honors
## Functions & Methods
### Fall 2026

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
  * Its identifier: the *name* of the function
  * The type of variable that it `return`s (output)
  * Any *parameters* or *inputs* (or *arguments*) the function has: both the arity (number of parameters) and their *type* (`int`, `double`, etc.)
* Later on in the program, you provide a function *definition*:
  * Has no semicolon, instead...
  * It has a *repeated* signature
  * and a function *body* that is inside `{...}` and specifies the code that is run when the function is called
* once a function is defined you can use it anywhere in the program
  * We say you "invoke" or "call" the function
  * **Optionally** you can capture the return value
  * Convention: use `lowerCamelCasing` for function names, and in general we use *verbs* (functions do things)
  * Control flow is "handed over" to the function and it computes until it gets to a `return` statement...
  * At which point control is given *back* to the "calling function"
  * Any variables declared inside a function are *local* to that function and they have *local scope* to that function

## "Functions" in Java

* In Java: technically you have "methods" not "functions"
* In Java: everything is a class or belongs in a class (OOP)
* For now: we'll restrict our attention to `static` methods
* `static` in this context means that the method belongs to the class not to *instances* of the class
  * To invoke you generally use the `ClassName` + `.` + `functionName()`
  * Ex: `Math.sin()`
* Java does not have prototypes: you include the documentation, signature and function body all in one spot
* Generally function are placed *above* the `main` if there is a `main`
* `public` simply means that all piece of code can "see" your function and use it

## Other Issues/Items

* A method or function that doesn't return anything is a `void` function
  * Ex: `void foo(int a);`
  * You *should* still have a return statement, it will just be empty: `return;`
* You can create functions with no input: you just don't use the `void` keyword, you use empty parentheses:
  * `int foo(void);`, but you should not
  * `int foo();`
* Recall: that functions can only ever return ONE thing (otherwise they are not functions)

# Modularity

## C

* In general, similar functions are organized into *modules* or "libraries"
* Why?  Organization, you only need to bring in particular libraries when you need them
* Libraries or "headers" (in C) should be *small*
* Code reuse: you can publish your library code so that other people, programs, etc. can use them!
* Demonstration:
  * Separate prototypes (and documentation) into header files: files that end with `.h`
  * Separate definitions into source files: same name end with `.c`
  * You use `#include "library.h"` in any file that needs the prototypes (the `library.c` file and the `main.c`)
  * Compile the library: `gcc -c library.c`
    * It produces an *object* file: `library.o`
  * Compile everything together:
    `gcc library.o main.c -lm -Wall -Wextra`

### Pitfalls

* You *never* `#include` source files: you do *not* do: `#include "finance.c"`
* Generally you only use the `-c` flag with "library" files
* Not using the `-c` flag with libraries will fail because there is no `main`
* This can get very complicated with many files; solution is to use a `makefile` (more on that later)

### Java

* Collections of methods are separated into "utility" classes
* Classes are organized into packages: `unl.soc`

## Unit Testing

* A *unit* is a piece of code (usually a function/method) that can be (easily) tested
* A unit is an indivisible piece of code that is treated as a "black box": you want to test things in isolation
* A unit test is an input-output pair that is known to be correct
  * Example: for `isPrime`: input `9`, output: `false`
  * Example: `isPrime`: input: `41`, output: `true`
* We unit test by feeding the input into our unit (function) and comparing the result to the *known correct* output: actual vs the expected
  * If they match: the test case *passes*
  * If they do not match: the test case *fails*
* Grouping multiple unit tests together into one collection gives you a *test suite*
* If a future bug is reported: you have a new test case!
* Having automated test suites allows us to fix the code and test for *regressions*
* Tests should be repeatable
* The more tests you have the higher *certainty* you have that your code is correct
* No amount of tests will ever give you a 100% *proof* that your code is correct
* The more test cases you have the better *code coverage* you have
  * Good code coverage should be a goal (100%)
  * You want to test corner or "edge" or "extremal" cases
  * Randomized Test (chaos testing) or "fuzzing"
  * System testing: "load" testing
* Problems:
  * Lack of code coverage
  * *false positives*: when a test case is wrong but the code is correct; ex: `isPrime(5)` and we expect `false`
  * A *false negative* is when there is a bug in your program, but your tests do not indicate it
* TDD = Test Driven Development
  * Strict TDD: you write all of your tests before you even write a line of code
* Testing and design, and writing code are all part of a process (cyclical)


```text









```
