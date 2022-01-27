# Computer Science I
## CSCE 155E - Fall 2021
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

```c
/**
 * Author: Chris Bourke
 * Date: 2021/08/25
 *
 * This program converts miles to kilometers
 */
#include <stdlib.h>
#include <stdio.h>

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

* Comments are human-readable messages embedded in code
  * Single line comments begin with a `//` and anything following on the same line is ignored by the compiler
  * Multi-line comments: begin with a `/*` and end with a `*/` anything in between is ignored
  * Doc-style comments are multiline comments that have a `/**` and a vertical line of stars: they are intended to provide full doocumentation on a program or function, etc.
  * Comments, especially documentation is intended to tell the user (you, other developers) the *why* and the *how* not the "what"
  * Code should be self-documenting in that regard: code should tell you the *what*

* Preprocessor directives: are directives to the comipler to do something *before* it compiles
  * You can use `#include` to bring in an external library that provides a bunch of useful functions that you can use
  * Ex: `#include <math.h>`
  * You can also use *macros*: using the `#define` directive
  * Macros are a basic cut-and-paste/replace operation
  * They allow you to give a human-readable term to "magic numbers"
  * They allow you to only have to make one single change to change all instances of that value

* The `main` function is always the starting point for any executable program
  * For now: `argc, argv` are "magic" (they are command line arguments)
  * Semicolons ends every *executable* statement
  * Blocks of code are denoate using opening and closing curly brackets
  * Commas delimit lists of similar things
  * Double quotes denote *strings*: sequences of characters
  * Whitespace in general does not matter
  * Good Styling:
    * Use horizontal whitespace when appropriate
    * Use vertical whitespace when appropriate
    * Use indentation to indicate blocks of code!
    * Variation on style are OK as long as they are used *consistently*
    * You can use style/formatters/prettifier to format your code; ex: `astyle`
  * Certain words are reserved by the language itself: `double, int, return`, etc. and have a very well defined meaning to the language and you cannot change their meaning

## Variables

* C is a *statically typed* language
* Basics: you have to *declare* a variable, both its name and its type *before* you can use it
  * The name of a variable is its identifier
  * The type is the type of value it holds
* Variable types:
  * `int` - an integer (32 bit signed 2s complement integer)
  it can represent whole values (integers) in the range:

  $$-2147483648 \leq x \leq 2147483647$$

  * `double` - a floating point number (IEEE 754 floating point number): it is a decimal number that has about 16-17 *digits* of accuracy

  * `char` - a single ASCII text character value
* You declare a variable by specifying its type and its name
* It name (identifier) has to follow rules:
  * You cannot begin a variable name with a number
  * You can have numbers, but you shouldn't
  * You should name variables after what they represent
  * Avoid abbreviations (in general) and acryonyms unless they are absolutely clear from the context
  * Your variables may contain characters `a-z, A-Z, 0-9` and a few more, but you should keep them simple
  * Use a convention: `lowerCamelCasing`, `UpperCamelCasing` is used but in different contexts: structures

### Assignment Operator

* variables hold values, you need a way to get values into variables, so you use the "assignment operator": a single equals sign
  * The left hand side must always be a variable
  * The right hand side can be a variable, a *literal* or an expression

```c
int x;
//note: not assigning a value means the variable could have *any* value including "garbage"

x = 10;

//reset x to 20:
x = 20;

//you can assign the value of a variable to another variable:
int a = 10;
int b;

//you can assign the value stored in a to the variable b:
b = a;
a = 20;
//b still has the value 10!

//you can also use entire expressions:
int c = 30;

int r = (-b + sqrt(b*b - 4*a*c) / (2*a));

```

* PEMDAS
* Note: in C there is no "native" exponentiation, you *cannot* write `x^y` or `x**y` instead you would need to use the math library: `pow(x, y)`

### More variable naming tips

* In general avoid abbreviations, acronyms, etc. unless it is *absolutley* clear from the context
* In general we suggest you use `lowerCamelCasing` (or, `lower_underscore_casing`)
* Don't use "placeholder" names: `foo, bar, baz` or `myVariable` or `variable1, variable2, variable3`
* use descriptive and clear variable names!
* In general be *consistent* with your program style

### Operators

* Arithmetic operators: `*, /, +, -`
* Consider: `a + b * c` is that the same as `(a + b) * c` (these are different!)
* Another common operator: integer division operator, `%`
  * It is also known as the "Modulus" or "modulo" operator
  * Its result is the *remainder* of integer division
  * Example:
    * 10 / 3 has a remainder of 1 in integer divisiono
    * `10 % 3` results in the value `1`
    * `11 % 3` results in the value `2`
    * `10 % 2` results in zero: no remainder
    * `11 % 2` results in one

#### Pitfall: Truncation

```c
int a = 10;
int b = 20;
int c = a / b;

```

* When you have two integers in your arithmetic operations, the result is *always* an integer
* if you divide an integer by an integer,the result will be an integer, but only the whole number part
* The fractional part is thrown out entirely
* This is known as *truncation*
* You can solve this problem using a casting operation

```c
int a = 10;
int b = 20;
double c = a / (double) b; //c is now 0.5
```

* This *temporarily* makes one of the variables into a floating point `double` for the purposes of the operation
* It does not change the type of `b`, `b` is still an integer

#### Other Math stuff
  * The math library contains functions for `sin(), cos(), tan(), sqrt()`
  * You also have constants: `M_PI, M_E`
  * Note: you *may* on some systems need to use the `-lm` flag when compiling:
  `gcc myProgram.c -lm`
  * Alternatively:
  `gcc -lm myProgram.c`
  * The math library has a LOT of other functions; how do you know what you can do?
  * RTM = Read The Manual

## Basic I/O

* I = input, O = output


### Interactive Input

* With interactive input, a program prompts the user to enter a value (usually one value at a time)
* The computer will *block* the execution of the program until the user has entered their input and hit the enter key
* To perform interactive *input* in C, we'll use the `scanf` function (it *scans* for *formatted* input)
* The formatting is determined by one of several *placeholders*:
  * for `int` types use `%d`
  * for `double` types use `%lf`
  * for `char` types use `%c`
* In general, only try to read one input in at a type
* For now, it is magic, but later we'll understand why you need to use an ampersand for all variables using `scanf`

```c
double a;
printf("please enter a fractional number:");
scanf("%lf", &a);
printf("%f\n", a);
```

### Basic Output

* You can print stuff to the *standard output* using `printf`
* You can use the same formats *except* for   `double` values:
  * for `int` types use `%d`
  * for `double` types use `%f`
  * for `char` types use `%c`
* WHen printing numbers or columns, the placeholders are replaced with formatted values of the variables you give to `printf`

```c
int a = 10;
double b = 42.5;
char c = 'X';
printf("The values are %d, %f, %c, yay!\n", a, b, c);
```

* You can further format output using *modifiers*
* Generally you can use `%n.m` to format floating point numbers (fractional numbers)
  * The `n` specifies the minimum number of columns to print including the decimal point
  * The `m` specifies the number of decimal numbers (to the right) of the decimal point to print
  * By default, six decimals are printed

```c
printf("pi is %f\n", M_PI);  //3.141593
printf("pi is %4.3f\n", M_PI);  //3.142
printf("pi is %4.4f\n", M_PI);  //3.1416
printf("pi is %4.40f\n", M_PI);  //16 digits of pi, with garbage after
printf("pi is %10.4f\n", M_PI);  //4 leading spaces, then 3.1416

int nuid = 1234567;
printf("hello student %08d\n", nuid);
```

### Non-interactive Input

* Interactive input (using `scanf`) makes the program pause and wait for the user to enter in their input
* Most programs especially command line programs are *not* interactive
* From the command line, you can provide input *non-interactively* by using *command line arguments*
* CLAs are provided when you start the program: `./a.out hello 10 3.5`
  * This example has *4* command line arguments
  * The first one is always the executable file name, `./a.out`
* Inside of your program, yoou have access to these *arguments* using `main`'s `argc` and `argv`
  * `argc` is the *count* of the number of arguments provided
  * `argv` is the "vector" or simply just a list or array of arguments
  * `argv[0]` is the first argument which is *always* the executable file name
  * `argv[1]` is the first user-provided argument
  * `argv[2]` is the second
  * `argv[3]` is the third
  * etc.
* CLAs are all *strings* not numbers
* To convert arguments into numbers, you can use:
  * `atoi()` converts the argument into an integer
  * `atof()` converts the argument into a `double`

```c
//convert the first user argument to an integer:
int x = atoi(argv[1]);
//convert hte second user argument to a double:
double y = atof(argv[2]);

```

```text








```
