# Computer Science I
## CSCE 155H - Fall 2020
### Intro to C/Java: Basics

An overview of basics of C and Java including variables, input and output.

## Programming, Compile, Run a Program

* A source file is a *plain text* file containing computer code in a particular language
* A source file is then compiled into an *executable program* (in binary)

  $$source \rightarrow assembly \rightarrow machine\,\, code$$

### C

  * Edit a source file, `hello.c`
  * Assemble: `gcc -S hello.c`
  * Compile: `gcc -c hello.c`
    * Produces an object file, `hello.o`
    * View: `hexdump -C hello.o`
  * All in one shot: `gcc hello.c`
    * Run: `./a.out`
    
### Java

* Java is not a purely compiled language
* You compile Java code in to Java Bytecode: "machine like" language the the Java Virtual Machine (JVM) understands
* Bytecode is then interpreted by the JVM

## Program Basics

* Comments are human readable messages embedded in code
  * Purpose: communicate to another human what the purpose of the code is
  * Comments/documentation tell the what and the why, but not necessarily the "how"
  * Code itself should be *self-documenting*: any reasonably competent person (who knows the language) should be able to understand how the code works by simply reading the code
  * Single line comments begin with a `//`: everything after them is ignored by the compiler
  * Multiline comments begin with a `/*` and end with a `*/`, anything in between is ignored
  * Doc-style comments are multiline comments with an additional vertical line of stars

* Preprocessor directives begin with a hash: `#`
  * you can include external libraries with `#include`
  * Example: `#include <math.h>` (you provide the library name inside langle/rangle)
  * You can define *macros* using `#define`
  * Macros eliminate the need for "magic numbers": numbers whose purpose/value is not immediately apparent
  * Macros also allow you to represent a single value in a single place (constants)
  * Macros make your code more readable and maintainable
  
* Every executable program has a main entry point: usually a `main` function or in Java, a `main` method
* Linear control flow: a program begins executing starting that main and goes top to bottom
* Other syntax and punctuation:
  * Commas delimit lists of arguments
  * Semicolons end each executable statement
  * Curly brackets denote the beginning/end of a *code block*
  * In general, whitespace does not matter for the language itself
  * Whitespace *definitely* matters to humans: makes your code more readable and thus maintainable
  * Style above all should be *consistent*
  * Example: blocks of code should all be indented at the same level
  * Reserved words: `int`, `double`, `return`

### Java

# Java Basics

* Java organizes code/classes in *packages*
* It is a tree-organized structure (hierarchy): packages and subpackages
* Each is separated by a period and each corresponds to actual directories (folders) on the file system
* This allows you to organize your code into different directories
* All source files *must* have the same file root name as the class name:
`MilesToKilometers` *must* be in a source file named `MilesToKilometers.java` (which compiles to a class file named `MilesToKilometers.class`)
* To bring in external classes you use the `import` keyword and specify the package and class name to bring in
* Example: `import java.lang.Math` (but this is unnecessary)
* `double x = Math.sqrt(2.0);` (dot operator)
* The main entry point in Java is the `main` method (any class can have a `main` method and therefore any class can be runnable)
* Comments are exactly the same
* Variables are extremely similar

## Variables

* Java and C are *statically typed* languages
* Variables and their types must be *declared* before they can be used
* When you declare a variable you specify its:
  * name or "identifier"
  * its *type* (the type of value it can hold)
  * optionally: you can also assign a value to the variable when you declare it
* Basic types (both C and Java):
  * `int`: 32-bit signed, 2s-complement integer: it can represent whole numbers negative, zero and positive in the range: -2147483648 to 2147483647 $-2^{31}$ up to $2^{31}-1$
  * `double`: 64 bit floating point number: it has ~16 digits of accuracy 
  * `char`: a single character variable 
    * In C: a character is a single ASCII text character
    * In Java: it is a full Unicode character supporting CJK (Chinese, Japanese, Korean) fonts, emojis, etc.

## Operators

* Assignment operator: the single equals sign allows you to assign and reassign values to variables

```text






```
