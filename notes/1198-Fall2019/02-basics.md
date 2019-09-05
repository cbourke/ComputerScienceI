# Introduction

CSCE 155E, Fall 2019

An overview of basics including variables, input and output in C.

## Programming, Compiling & Running 

* Source file is a *plain text* file containing computer code in a high-level language
* Source file have to be compiled into an *executable program*
  * *source → assembly → machine code*

### Demonstration

1. Edit a source code file, `hello.c`
2. Assemble: `gcc -S hello.c`
3. Compile: `gcc -c hello.c`
  * Produces an object file, `hello.o`
  * View: `hexdump -C hello.o`
4. You need to also *link* in any external libraries

* All at once:
`gcc hello.c`

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

* Comments are human readable messages embedded in code
  * Single line comments begin with a `//` anything following that on the same line is ignored by the compiler
  * Multiline comments begin with a `/*` and end with a `*/`, anything in between is ignored
  * "Doc-style" comments (see the headers of the example programs)
  * Comments are designed to tell the *why* and the *how*, not the "what"
  * Code should be self-documenting!: the code itself tells you the *what*
  
* Preprocessor directives: are directives to the compiler to do something and are executed *before* it starts compiling:
  * You can include (bring in) external libraries using `#include` along with the library name
  * Example: `#include <math.h>` 
  * You can define "macros" using `#define`
  * A macro is essentially a cut-and-paste operation
* The `main` function is always the staring point for any executable program
  * For now, ignore the `int argc, char **argv` (command line arguments)
* Other syntax and punctuation:
  * Semicolons end every executable line
  * Placeholders in `printf` and `scanf` using `%`
  * Commas delimit *arguments*
  * Double quotation marks indicate a *string*: a sequence of characters, you have an *opening* double quote and a *closing* double quote
  * Curly brackets denote *code blocks*
  * In general whitespace does not matter except for styling
  * Several reserved or "keywords": `double`, `int`, `printf`

## Variables

* C is a *statically typed* language
* Basically: you have to *declare* a variable and its type before you can use it
* A variable's *type* cannot be changed once declared
* The *scope* of a variable is the section of code (code block) in which it exists or is valid
* There are a few built-in variable types:
  * `int` - an integer that can represent values whole values in the range
  -2147483648 ≤ x ≤ 2147483647
  * `double` - a floating point number giving you about 16-17 *decimals* of accuracy
  * Essentially scientific notation but in binary  
    3.14 * 10<sup>24</sup>
  * `char` - a single character value
  * ASCII text value: ASCII 

```c
//declare an integer variable and set it equal to 10:
int x = 10;
int y;  //don't know what is stored in y
//0xDEADBEEF

//later on you can always reset a variable's value:
x = 20;

//declare and set a double variable:
double pi = 3.14;

//declare a character variable:
char firstInitial = 'C';

```

* A variable's *name* (*identifier*) must follow several rules
  * It may consist of letters, a-z, A-Z, 0-9, _
  * It may NOT begin with a number
* Style: use proper names
  * Variables should be named after the things they represent
  * Don't use non-descriptive variable names: `x`, `foo`, `bar`, `myVariable`, `myVariable02`
  * Good examples: `numberOfStudents`, `annualPercentageRate`
  * In general you should avoid abbreviations, acronyms, short version
  * Follow consistent styling: `lowerCamelCasing` or `lower_underscore_casing`

### Operators

* Arithmetic: `+, -, *, /` (addition, subtraction, multiplication, division)
* Consider the following: `a + b * c` is not the same 
  as `(a + b) * c`
* PEMDAS: Parentheses, Exponent, Multiplication, Division, Addition, Subtraction
* Example: $\frac{-b \pm \sqrt{b^2 - 4ac)}}{2a}$
* Some results result in errors

```c
double x = sqrt(-10); //results in NaN

int y = 10 / 0; //result in INF
```

* A integer division operator: `%` (read: as mod or modulo)
  * It results in the *remainder* of a division
  * Examples:
    * `10 % 3` results in 1 (a remainder of 1)
    * `11 % 3` results in 2
    * `10 % 2` results in 0

### Pitfall: Truncation

```c
int a = 10;
int b = 20;
double c = a / b; //result zero

```

* When you have two integers in your arithmetic operation, the result is always an integer
* If you have an integer divided by an integer, the result is an integer: the fractional part is thrown away or "truncated"
* You can solve this by "temporarily" making one or both of the variables into a compatible `double` type by *type casting*

```c
int a = 10;
int b = 20;
double c = (double) a / b; //result 0.5
```

* Math library
  * it has a bunch of nice mathematical functions: `sin(), cos(), tan(), sqrt()`
  * it also has a bunch of nice constants, `M_PI`, `M_E`
  * you can use it by using `#include <math.h>`
  * On CSE you *may* need to manually link it in:
  `gcc -lm myProgram.c`
  * What other functions are in the math library?
  * RTM: Read The Manual
  `man sqrt`

## Basic I/O

* I = input, O = output
* Consider *interactive input*: where you prompt the user to enter a value then read from them
* INteractive input is achieved using the `scanf` (scan formatted)
  * You provide a placeholder:
    * `int`: `%d`
    * `double`: `%lf`
    * `char`: `%c`
  * In general, read one value at a time
  * Never forget your ampersand on the variable: `&a` otherwise you'll get weird results
  
* You can print to the standard output (screen) using `printf`
  * Same format: you provide a format and any number of variables
    * `int`: `%d`
    * `double`: `%f`
    * `char`: `%c`
  * You can print multiple values in one statement using multiple placeholders, but the number and types *should* match!
* You can also have more fine-grained control over what is printed

```c
#include <stdio.h>
#include <math.h>

int main(void) {

  int x = 1234;
  double pi = 3.14159;

  printf("%f\n", pi); //3.141590
  printf("%.20f\n", pi);
  printf("%.15f\n", pi);
  printf("%.2f\n", pi); //3.14
  printf("%.3f\n", pi); //3.142
  printf("%.6f\n", pi); //default

  printf("%20.4f\n", pi); //prints 14 leading spaces
  printf("%-20.4f!\n", pi);
  //prints 14 trailing spaces

  printf("%20d\n", x);

  printf("%020d\n", x);  //prints 16 leading zeros

  return 0;
}
```

Exercise

```c
#include <stdio.h>
#include <math.h>

int main(void) {

  double a, b, c;

  printf("Enter a: ");
  scanf("%lf", &a);

  printf("Enter b: ");
  scanf("%lf", &b);

  printf("Enter c: ");
  scanf("%lf", &c);

  double root = (-b + sqrt(b*b - 4*a*c)) / (2*a);

  printf("one of the roots is %f\n", root);

  return 0;
}
```
