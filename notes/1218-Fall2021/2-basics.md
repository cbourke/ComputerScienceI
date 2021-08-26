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

```c
int x;

x = 10;

```

```text







```
