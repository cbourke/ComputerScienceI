
# CSCE 155H - Computer Science I Honors
## Functions & Methods
### Fall 2020

* A *function* is a reusable unit of code that may take input(s) and may produce an output
* Already familiar with functions: `main(), printf(), sqrt()`, etc.
* Familiar with functions from math: $f(x) = x^2$
  * Input: $x$
  * Output: $y = x^2$
  * You can also have multivariate functions: $f(x, y)$, $f(x, y, z)$, $f()$
* Functions facilitate code reuse: you don't have to copy-pasta chunks of code; instead you put them into a function and then *call* or *invoke* the function
* DRY Principle: Don't Repeat Yourself!
* Procedural Abstraction:
  * How does the `sqrt()` function work?
  * A: Who cares? We simply want to use the functionality
* By *encapsulating* functionality into a function then it relieves us of the need to think about these small details
* Standard libraries and functions (and external libraries) come with a LOT of testing, debugging, optimization, etc. already "built in" to them
* In general you don't want to "reinvent the wheel" or "roll your own solution"
* Problem solving: when asked to solve a problem, what is the *first* question you should ask?  Has someone already solve this problem?
* Often you need to adapt those "off the shelf solutions"

## Functions in C

* As with variables, functions must be declared before you can use them
* In C, you "declare" a function by using a *prototype*
* A prototype declares a function's *signature*
  * You define the *return type*: the type of variable that the function returns (`double`, `int`, if none, then it is a `void` function)
  * The function's name or *identifier*
  * The number (arity) and type of the function's inputs called "parameters" or "arguments"
* In general every function should be documented and its documentation should be attached to the prototype

```c
/**
 * This function rounds the given value (assumed
 * to be a dollar value) and rounds it to the
 * nearest cent
 */
double roundToCents(double amount);
```

Observations:
* The prototype has no "body": we are *not* defining what the function does YET
* The prototype ends with a semicolon
* Convention: use `lowerCamelCasing` for function names, and in general we use *verbs*
* Later on in your program, you *then* define what the function does by providing a function *definition*: repeat the prototype but instead of a semicolon you provide a function *body*
* The code in the function body is what is executed when the function is called or invoked

```c

double roundToCents(double amount) {
  double result = round(amount * 100.0) / 100.0;
  return result;
}
```

Observations:
* You "return" a value to the calling function by using a `return` statement
* Any variables declared inside a function are *local variables* and only exist inside that function; they have a *local scope*
* a function definition does not have a semicolon

## "Functions" in Java

* TECHNICALLY: functions in Java are called "methods"
* In Java everything is a class or belongs to a class; therefore "functions" that belong to a class are (fancily called) methods
* For now: we'll only use `static` methods; that is, methods that belong to the class rather than instances of the class (don't worry about this for now, this is an OOP thing)
* For now the important thing is how to invoke a method in Java:
  * You use the class name + dot + the name of the function
  * `Math.sqrt()`

```java

public class RoundUtils {

	/**
	 * This function rounds the given value (assumed to be a dollar value) and
	 * rounds it to the nearest cent
	 */
	public static double roundToCents(double amount) {
		double result = Math.round(amount * 100.0) / 100.0;
		return result;
	}

}
```

* Elsewhere in the code, you *invoke* or call your function using the classname: `RoundUtils.roundToCents()`
* The `public` keyword means that any other piece of code can "see" and therefore use your method
* Alternatives:
  * `private`: only the class can "see" it
  * `protected`: only the class and subclasses can "see" it
  * the abscence of a keyword is "package protected": only other classes in the same package can "see" it

## Other Issues

* A method or function that doesn't return anything is a `void` function
  * You can make the return type `void` indicating that it does not return anything
  * You should *still* use a `return;` statement in a void function
  * A function that takes no input: you can also use the `void` keyword but probably should not:
    * `int foo(void)`
    * `int foo()` (preferred)  

### Function Overloading

* In C, to compute the absolute value you can use `abs(), fabs(), labs(), llabs(),` etc.
* Those function each take a different type and return a different type
* In C you can only have one function with a particular name; C has no "function overloading"
* "Function Overloading": you can have more than one function with the same name (identifier) as long as it take different arguments    
* Java supports this: there are 3 absolute value functions in the math library, but they all have the same name: `abs()`
* In Java: the compiler is "smart" enough to figure out at compile time which function you meant to call (this mechanism is called "static dispatch")
* C does not support function overloading, thus it needs different names for each function: you cannot have two functions with the same name
* In C You end up either *polluting the namespace* or appending a common "tag"

## Modularity

* Java organizes code into classes and packages
* You should do the same: use package names, use sensible descriptive method names
* You group or collect similar methods into a class such as a "utility" class
* You group similar or related classes into the same package
* A package is a "module" in Java

### Modularity in C

* In C, you generally separate prototypes into *header* files and function definitions in to *source* files
* Header files are usually placed into file names that end with `.h`
* Source files usually have the same root file name but end with `.c`
* Example:
  * Separate the round functions into several files
  * Prototypes: `roundUtils.h`
  * Definitions: `roundUtils.c`
  * You "include" any necessary libraries plus the header file in the source file
  * By convention, when you include a user-defined header file, you use double quotes instead of `<>`
  * To compile the `roundUtils.c` "library" use `gcc -c roundUtils.c` which produces a `roundUtils.o` object file
  * To compile and link your full program:
  `gcc roundUtils.o demo.c`
  * For C (and many other languages) use a build system: `make`
  * For Java: Ant, Maven, JenkinsCI, etc.


### How do functions actually work?

* Programs have a *program stack* (or *call stack*)
* Stack: LIFO Data Structure
  * LIFO = Last In First Out
  * push: insert an element at the "top" of the stack
  * pop: retrieve/remove an element at the top of the stack
  * A stack can be used to keep track of *breadcrumbs*
* Each time a function is called, a new *stack frame* is created/pushed on top of the call stack
* Each time a function returns, the stack frame is popped off the top
* Each stack frame keeps track of:
  * Local variables
  * Parmeter variables
  * Return values

```c
#include <stdlib.h>
#include <stdio.h>

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

* Consequence: every stack frame's variables are separate (this is how function scoping works!)
* Every function gets its own scope and its own stack frame, its own variables
* In most programming languages, variables are *passed by value*
  * The value of the variables are copied into the parameter variables
  * The original variables are completely different
  * Only *copies of the values* are passed to the function
* Sometimes you *do* want to pass the variables instead of their values
* This is known as *passing by reference*

## C: Pointers

* Every piece of data in a computer is stored in memory
* Memory consists of both an *address* (location) and contents (the data actually stored)
* In C you can create a *pointer* variable that represents not the data, but the *memory address* where the data is stored
* TO create create a pointer variable, you use the `*` symbol

```c
//regular old variable:
int a = 42;
//pointer variable declaration:
int *ptrToA;
```

* `ptrToA` is a pointer variable that can point to *any* memory location that holds an integer (4 bytes, usually)
* In general, it is best practice to initialize your pointer to point to *something*
* If you know what you want it to point to, do it; if not then at least point it to `NULL`
* If you don't, you have an *uninitialized pointer*: it could point to anything
  * It could point to an invalid or non-existant memory location
  * It could point to a memory location that exists, but doesn't belong to you
  * It could point to your own memory location; BUT you risk corrupting your own memory!

```c
//initialize our pointer to NULL:
ptrToA = NULL;
```

* If you want it to point to a valid memory location, you need to get the variable's address
* `int a;` is a regular old variable, to get its memory location you use the `&` operator (referencing operator):

```c
//make ptrToA point to a's memory location:
ptrToA = &a;
```

* Putting an ampersand in front of a regular old variable, gives you the memory address of that variable
* Further: you can now manipulate the contents of a variable through its pointer

```c
int a = 42;
//reset a:
a = 17;

//make ptrToA point to a:
int *ptrToA = &a;
//change the contents of a via its pointer:
*ptrToA = 30;
```

* The star operator, `*` is the *dereferencing* operator

## Java

* Java has no pointers, you do not (generally) directly manipulate memory contents
* By default, all primitive types in Java are passed by value: `int, double, char`
* All *reference* values `String, Integer, Double`, etc. are passed by reference, BUT...
* Generally built-in types are *immutable*
* Immutability is a Very Good Thing

## Misc

* In C, a pointer type must match the type it points to: the following is wrong

```c
double pi = 3.14;
//you should not have an integer pointer
//point to a double
int *ptrToPi = &pi;
//if you want a double pointer, just create it:
double *correctPointerToPi = &pi;
```

* Recall: when we used `scanf`, we used the ampersand: why?
* `scanf("%d", &a)`

* Summary:
  * To change a regular variable into a pointer (memory address) use the `&`
  * To change a pointer variable into a regular old variable, use the `*`

* You can also check for `NULL`:

```c
if(pointerToA == NULL) {
  printf("invalid memory!\n");
}
```

## Demonstration

* Write a function that "returns" multiple values: write a function
to convert a given number of `totalSeconds` into `hours`, `minutes`, `seconds`
So 12282 seconds $\rightarrow$ 3:24:42

* Write a function to compute the inflation-adjusted rate of return and
deal with potential input errors

$$\frac{1 + \textrm{rate of return}}{1+\textrm{inflation rate}} - 1$$

* Write unit tests for each

* Java?

```text







```
