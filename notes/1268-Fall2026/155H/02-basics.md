# Computer Science I
## CSCE 155H Fall 2026
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

### Comments

* Comments are human-readable messages embedded in code
* Purpose: communicate to other humans what the purpose or intent of the code was
* Comments/documentation tell the *what* and the *why*, not necessarily the *how*
* DRY = Don't Repeat Yourself!
* For now: all of your programs should have an author header
* code should be *self-documenting*: it should be written clearly enough that an experienced user could understand the *how*
* Cruft: useless or verbose code
* Syntax in both languages:
  * Single line comments use `//`: only ignores everything to the end of the line
  * Multiline comments begin with `/*` and end with `*/`
  * Doc-style comments: begin with `/**` and have a vertical line of stars, get in the habit of using them!

### Preprocessor

* C has a preprocesor that processes your code before it compiles it...
* Preprocessor directives begin with a hash `#`
  * You can include external libraries using `#include` and providing the name of the library (generally they end with a `.h` - a *header* file)
  * Example: `#include <math.h>`; `sin(), cos(), sqrt()`
  * "Constants": `M_PI, M_E`
* `#define` is a macro: it essentially is a cut-and-replace operation by the preprocessor (something that runs before the compiler)
* Macros also allow you to represent a single value in a single place (constants)
* Macros make your code more readable and maintainable (don't use Magic Numbers)

### The Main

* Every program has to have a starting point
* Generally programs start in the `main` function or method
* Linear control flow: a program executes top to bottom, left to right

### Other Stuff

* Punctuation
  * Semicolons end executable statements (like sentences and periods)
  * Curly brackets define *code blocks* (akin to paragraphs)
  * Commas delimit lists of things
  * Quotation marks: `"..."` define strings (sequences of single characters)
  * Parentheses denote inputs to functions (just like math!)
  * Square brackets (later) are used in arrays: `[]`
  * Single quotes (both C and Java): are used for single *characters*: `'C'`
  * Whitespace makes code more readable: vertical whitespace separates lines, horizontal whitespaces indents *blocks* of code
  * whitespace helps to make your code more readable: in general statements at the same "level" should have the same indentation
    * Style above all should be *consistent*
    * Unless you have a Very Good Reason (VGR)

## Variables

* Both C and Java are *statically typed* langauges
  * Before you can use a variable you need to *declare* it
  * To declare: you define its *type* and its *name* (or identifier)
  * Where ever you declare a variable, is its *scope*: the area of the code that the variable can be "seen" and is therefore valid
* Basic Types:
  * `int` short for integer
    * 32-bit signed 2-s complement integer
    * you can represent 0, negative and positive integers in the range: -2,147,483,648 to 2,147,483,647
    $$-2^{31} \cdots 2^{31}-1$$
  * `double` is a 64-bit IEEE 754 floating point number
    * You can represent decimal numbers with about 17 digits of accuracy



```text















```
