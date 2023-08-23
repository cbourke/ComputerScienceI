# Computer Science I
## CSCE 155H Fall 2023
### C & Java Basics

An overview of basics of C and Java including variables, input and output.

## Programming, Compile, Run a Program

* A source file is a *plain text* file containing computer code in a particular language
* A source file is then compiled into an *executable program* (in binary)

  $$source \rightarrow assembly \rightarrow machine\,\, code$$

### Java

  * Java is not a purely compiled language
  * You compile Java code into Java Bytecode: a "machine like" language that is runnable on the Java Virtual Machine JVM
  * Bytecode is then interpreted by the JVM


## Program Anatomy

Consider a basic *input/output* program to convert miles
to kilometers...
  * Basic program framework
  * Prompt the user for some input
  * Read the input
  * Store the input
  * Convert the values (math)
  * Output the results

Observations:

* Comments are human-readable messages embedded in code
  * Purpose: communicate to other humans what the purpose or intent of the code was
  * Comments/documentation tell the *what* and the *why*, not necessarily the *how*
  * Code should be *self documenting*: it should be written clearly enough that an experienced user could understand the *how*
  * Single line comments begin with `//`, multiline: `/*` and end with `*/`
  * Doc-style comments: begin with `/**` and have a vertical line of stars, get in the habit of using them!

* Preprocessor directives begin with a hash `#`
    * You can include external libraries: `#include` and providing the "name" of the library (`.h` is for the "header" of that library)
    * Example: `#include <math.h>`; `sin(), cos(), sqrt()`
    * `#define` is a macro: it essentially is a cut-and-replace operation by the preprocessor (something that runs before the compiler)
    * Macros also allow you to represent a single value in a single place (constants)
    * Macros make your code more readable and maintainable (dont' use Magic Numbers)
    * every program has to have some *beginning* for both C and Java that's the `main` function or method
    * Linear control flow: a program executes top to bottom, left to right
    * Other syntax and punctuation:
      * semicolons end executable statements
      * curly brackets (opening and closing) denote *code blocks*
      * Parentheses denote function calls or "groupings" of things
      * commas delimit lists of similar things
      * double quotes denote *strings* which are sequences of characters
      * whitespace helps to make your code more readable: in general statements at the same "level" should have the same indentation
      * whitespace helps to make your code more readable: in general statements at the same "level" should have the same indentation
      * Style above all should be *consistent*
      * Unless you have a Very Good Reason
      * Example: blocks of code should all be indented at the same level
      * Reserved words: `int`, `double`, `return`

```text












```
