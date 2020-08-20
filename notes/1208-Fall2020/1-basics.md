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
* Note: there is no "native" exponentiation in C; you have to use `pow(x, y)` for $x^y$ (you cannot use the carret: `x^y`)


```text








```