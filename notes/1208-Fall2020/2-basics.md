# Computer Science I
## CSCE 155E - Fall 2020
### C Basics

An overview of basics including variables, input and output in C.

## Programming, Compiling, Running

* Source files are *plain text* files containing computer code in a highlevel programming language
* Source files have to be compiled into an *executable program* (binary code)
  * *source → assembly → machine code*
  
### Demonstration

1. Edit a source file `hello.c`
2. Assemble: `gcc -S hello.c`
3. Compile: `gcc -c hello.c`
  * Produces an object file, `hello.o`
  * View: `hexdump -C hello.o`
4. You need to also *link* in any external libraries

* All at once: `gcc hello.c`

## Program Basics

```c
/**
 * Author: Chris Bourke
 * Date: August 28th, 2019
 *
 * This program converts miles to kilometers
 */
#include <stdio.h>
#include <stdlib.h>

#define KMS_PER_MILE 1.60934

int main(int argc, char **argv) {

  double miles, kms;

  //prompt the user for the input
  printf("Please enter miles: ");

  //read in the input
  scanf("%lf", &miles);

  kms = KMS_PER_MILE * miles;

  printf("%f miles is equal to %f kilometers\n", miles, kms);

  return 0;
}
```

* Comments are human-readable message embedded in code
  * Single comments begin with a `//`, anything following them on the same line is ignored
  * Multiline comments begin with a `/*` and end with a `*/` anything between them even if they are on multiple lines is ignored
  * Doc-style comments are multiline comments with a particular formatting: they have a vertical line of stars and are intended to be used for *documentation* 
  * Comments, especially documentation is intended to tell the user (you, other developers) the *why* and the *how* not the "what"
  * Code should be self-documenting in that regard: code should tell you the *what*
  
* Preprocessor directives: are directives to the compiler to do something *before* it starts compiling
  * You can bring or "include" external libraries using the `#include` along with the library name surrounded by langle rangle
  * Example: `#include <math.h>`
  * You an also define "macros": `#define`
  * A macro usign `#define` is essentially a cut-and-paste
  * Why?  It allows us to use identifiers for constant values; using macros avoids "magic numbers": values whose purpose is not immediately clear
  * It keeps such values in ONE place, changing them means only one value gets replaced instead of many

* The `main` function is always the starting point for any executable program
  * For now, ignore the `argc`, `argv`: these are command line arguments
  * Semicolons end every *executable* line of code: they are like periods at the end of a sentence
  * Commas delimit lists
  * Whitespace in general does not matter, but you should include it to make your code more readable!
  * Double quotation marks delimit *strings*: sequences of characters
  * You have *blocks* of code which begin and end with curly brackets
  * Good Styling: 
    * Use horizontal whitespace when appropriate
    * Use vertical whitespace when appropriate
    * Use indentation to indicate blocks of code!
    * Variation on style are OK as long as they are used *consistently*
    * Several reserved or keywords: `double`, `int`, `printf`, etc.

## Variables

* C is a *statically typed* language
* Basically: you have to declare a variable before you use it!
  * You declare a variable's *name* or "identifier"
  * You also indicate its *type* (which cannot change in the program after declaration)
* Variable types:
  * `int` - an integer (32 bit signed 2s complement integer) that can represent a limited set of values: 
  
  $$-2147483648 \leq x \leq 2147483647$$
  * `double` - a floating point number (IEEE 754 floating point number): it is a decimal number that has about 16-17 *digits* of accuracy
  
  * `char` - a single ASCII text character value

```c
//declare an integer variable:
int x;
//you can set a value later on using the assignment operator:
x = 10;


```

### Assignment Operator

* The assignment operator means: put the value on the right hand side into the variable on the left hand side
* The left hand side must always be a variable
* The right hand side can be a variable, a *literal* or an expression

```c
int x;
//set x to a *literal* value; ie a "hardcoded" value:
x = 10;
//set x to the value of another variable:
int b = 20;
x = b;
//NOTE: this only places the value *at the time 
//of the assignment; it does not "marry" the two variables
b = 42;
//x is not changed, it is still 20

//the right hand side can be an expression:
int a = 10; b = 1, c = 4;
int r = (-b + sqrt(b*b - 4*a*c)) / (2*a)

```

* Programming expressions follow PEMDAS
* Note: there is no "native" exponentiation in C; you have to use `pow(x, y)` for $x^y$ (you cannot use the caret: `x^y`)

### Variable Naming

* A variable's *name* (*identifier*) must follow several rules
  * A variable's name may consist of letters, a-z, A-Z, underscores _ and numbers 0-9
  * It may NOT begin with a number
* Good style:
  * Variables should be named after the things they model
  * Use descriptive variables: `x` (if it is a point), `numberOfStudents`, `miles`, `kilometers`
  * In general, avoid abbreviations, acronyms, etc. unless the context is absolutely clear
  * Don't use placeholder names in real code: `foo, bar, baz`, `myVariable`, `var1, var2`
  * In general you should be *consistent* with your naming conventions
  * `lowerCamelCasing` is a good one to follow, another: `lower_underscore_casing`

### Operators

* Arithmetic Operators: `+, -, *, /` 
* Consider: `a + b * c` is that the same as `(a + b) * c`
* PEMDAS
* Another operator: integer division operator `%`
* It results in the *remainder* of a division
* also known as the modulus or simply "mod operation"
* Examples:
  * `10 % 3` results in 1 (a remainder of 1)
  * `11 % 3` results in 2
  * `10 % 2` results in 0

### Pitfall: Truncation

```c
int a = 10;
int b = 20;
int c = a / b; //result zero
```

* When you have two integers in your arithmetic operations, the result is *always* an integer
* If you divide an integer by an integer, the result must be an integer: the fractional part gets cut off and thrown away
* This is known as truncation
* It is not rounding, it is not flooring 
* You can solve this problem by "temporarily" making one or both of your operands compatible with a `double` using *type casting*

```c
int a = 10;
int b = 20;
double c = (double) a / b; //result 0.5
```

* Math library functions
  * `#include <math.h>` has a bunch of nice mathematical functions: `sin(), cos(), tan(), sqrt()`
  * It also has nice constants: `M_PI`, `M_E`
  * IF YOU WORK ON CSE: you *may* need to use the `-lm` flag to compile with the math library
  `gcc -lm myProgram.c`
  * What other functions may there be?  RTM = Read The Manual

## Basic I/O

* I = input, O = output
* With *interactive input* a program prompts the user to enter a value, then reads the value from the user 
* The computer will *block* execution and waits for the user to mash their keyboard and then hit enter
* Input: for interactive input you use `scanf` (scan the standard input in a *f*ormatted manner)
* The format means you can use one of several placeholders depending on the variable type you want to read in:
  * `int`: `%d`
  * `double`: `%lf`
  * `char`: `%c`
* In general you only read one value at a time
* Never forget the ampersand in front of the variable you want to store the value in (for now: its magic)

### Basic Output

* You can print to the standard output using `printf`
* Same formats: you provide any number of placeholders and a comma delimited list of variables whose value you want to print
  * `int`: `%d` 
  * `double`: `%f`
  * `char`: `%c`
* When printing numbers, you have more fine-grained control over how many "columns" to print and how many digits of accuracy you want to print using placeholder modifiers
  * `%n.mf`

```c

  printf("pi = %f\n", M_PI);
  //10 decimals of accuracy:
  printf("pi = %.10f\n", M_PI);
  printf("pi = %.15f\n", M_PI);
  printf("pi = %2.10f\n", M_PI);

  int x = 1234;
  printf("x = %10d\n", x);
  printf("x = %010d\n", x);
  //left justification:
  printf("x = %-10d hello\n", x);

```

### Non-interactive input

* Arguments are provided to the program from the command line as "Command Line Arguments" or CLAs
* No interaction with the user: no prompting, no reading, the program reads them when the program starts
* Command line arguments are provided by the 
  * `argc` - number of arguments (argument count)
  * `argv` - the vector of arguments
  * `argv[0]` is always the executable program name! (ex: `a.out`)
  * `argv[1]` is the actual first argument provided by the user
  * `argv[2]` is the second, etc.
* You can convert arguments using 
  * `atof()` to convert to a floating point number (`double`)
  * `atoi()` to convert to an integer (`int`)


### Exercise

* Write a program that reads in 3 coefficients of a quadratic polynomial and outputs its roots
  $$ax^2 + bx + c = 0$$


### Misc

* Take care that some operations are "invalid": `sqrt(-1)` results in nan (not a number); division by zero results in `inf` etc.
* On some systems to compile with the math library you may need to use the `-lm` flag
  * CS50: `gcc foo.c -lm`
  * CSE: `gcc -lm foo.c`
* C has no default variable values!
  * Uninitialized variables may not have a default value
  * If a default value of zero is observed that is entirely due to the compiler and/or operating system

```text








```