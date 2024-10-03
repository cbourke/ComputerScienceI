
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

### Java

* Collections of methods are separated into "utility" classes
* Classes are organized into packages; ex: `unl.soc` which are simply directories (`unl`) and subdirectories (`soc`)

## Unit Testing

* A *unit* is a piece of code (usually a function) that can be tested
* A unit is an indivisible piece of code that is treated as a "black box": you want to test things in isolation
* A unit test is an input-output pair that is known to be correct
* We unit test by feeding the input into our unit (function) and comparing the result to the *known correct* output: actual vs the expected
  * If they match (or are close): it "passes"
  * If they do no match: they "fail"
* Grouping multiple unit tests into one collection gives you a *test suite*
* If a future bug is reported: you have a new test case!
* And so we can integrate it into our test suite and start *debugging*
* Having automated test suites allows us to fix the code and test for *regressions*
* Tests should be repeatable
* The more tests you have the higher certainty you have that your code is correct
* No amount of tests will ever give you a 100% *proof* that your code is correct
* The more test cases you have the better *code coverage* you have
  * You want to test corner cases
  * Edge cases, extremal cases
  * Randomized Test (chaos testing) or "fuzzing"
* Problems:
  * Lack of code coverage
  * A *false positive* is when a test case is wrong but the code is correct
  * A *false negative* is when there is a bug in your program, but your tests do not indicate it
* TDD = Test Driven Development
  * You write tests before you even write the code
* Demo:
  * *informal* unit testing in C
  * *formal* unit testing in Java: JUnit (version 5)

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

## How Functions Actually Work

* Programs have a *program stack* (or *call stack*)
* Stack: LIFO data structure
  * LIFO = Last In First out
  * Push: you add something to the "top" of the stack
  * Pop: you remove the top most thing
* Each time a function is called, a new *stack frame* is created/pushed on top of the call stack
  * Each stack frame keeps track of local variables and parameters
  * Each time you return from a function, the stack frame is popped off the top
  * Consequence: each stack frame's variables are separate (this gives us *scoping*) and cannot be accessed by other stack frames
* Every function gets its own scope and own variables
* In most programming languages (C, Java), variables are *passed by *value*
  * WHen a function is called, *copies* of the values of the variables at that point are passed to the function, *NOT* the variables themselves
  * No changes to the variables can be seen by the original function
* However, in C we *do* have a bit more control: we can pass by *reference* instead

## C: Pointers

* Every piece of data in a computer is stored in memory
* Pointer variables are declared using the star (astrisk): `int *p`
  * Referencing operator: `&` which gives you the memory location of a regular variable
  * Dereferencing operator: `*` which turns a pointer variable into a regular variable
  * Regular variable to pointer: `&`
  * Pointer variable to regular variable: `*`

```c

    //regular old variable:
    int x = 42;

    //pointer variable that can point to an integer
    int *ptrToX;

    //pointer variable that can point to a double
    double *ptrToDbl;

    //make ptrToX point to x:
    ptrToX = &x;

    //INVALID:
    // makes it point to memory location 42
    //ptrToX = x;

    //set the value in x:
    x = 101;
    //set it using its pointer:
    // dereference: * in front of a pointer to "make it into" a regular old variable
    //segmentation fault: *ptrToX = 101;

    //valid way to set the variable:
    *ptrToX = 103;
    printf("x is now %d\n", x);

    //Initially a pointer variable is not  pointing to anything:
    double *p;
    //It could point to "null", some random variable address, etc.
    // Best practice: initialize it to
    p = NULL;
    //you can also check for null:
    if(p == NULL) {
        //dont do that dangerous operation
        //remember Bret Hart: *p = 103;
        //don't dereference a NULL pointer
    }

    double y = 4.5;
    p = &y;
    printf("p is pointing to memory location %p and holds the value %f\n", p, y);

    //also avoid pointing to the wrong things
    x = 42;
    double *ptrWrong = &x;
    *ptrWrong = 150;
    printf("x = %d\n", x);
```

Swap Demo:

```c

void swap(int a, int b) {

    printf("In Swap before: a = %d, b = %d\n", a, b);

    int temp = a;
    a = b;
    b = temp;

    printf("In Swap after: a = %d, b = %d\n", a, b);

    return;
}

void swapByReference(int *a, int *b) {

    printf("In Swap before: a = %d, b = %d\n", *a, *b);

    int temp = *a;
    *a = *b;
    *b = temp;

    printf("In Swap after: a = %d, b = %d\n", *a, *b);

    return;
}

int main(int argc, char **argv) {

    int a = 10;
    int b = 20;

    printf("Before: a = %d, b = %d\n", a, b);
    swap(a, b);
    printf("After: a = %d, b = %d\n", a, b);

    printf("Before: a = %d, b = %d\n", a, b);
    swapByReference(&a, &b);
    printf("After: a = %d, b = %d\n", a, b);


    return 0;
}
```

### Summary of Pointers

* A pointer is a *memory address* or "reference"
* A pointer can be declared using the star syntax: `int *p;`
* It is best practice to initialize them to `NULL`
* To make a pointer variable into a regular old variable: use the *dereference* operator: `*p`
* To make a regular variable into a pointer variable: `&a`, the *referencing* operator
* DOn't make pointers point to things they shouldn't point to
* Java: doesn't have pointers!

## Passing By Reference

* Now you can "return" multiple values from a function: specifying more than one pass-by-reference variable
* Simply "returning" a value by using a pass-by-reference variable means you don't have to explicitly return a value, this frees up the return type/variable
* With that return variable, we can now do *error handling*



```text
















```
