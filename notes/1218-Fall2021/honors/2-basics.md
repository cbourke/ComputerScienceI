# Computer Science I
## CSCE 155H - Fall 2021
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
* You compile Java code into Java Bytecode: a "machine like" language that is runnable on the Java Virtual Machine JVM
* Bytecode is then interpreted by the JVM

## Program Anatomy

* Comments are human-readable messages embedded in code
  * Purpose: communicate to another human what the purpose of your code is
  * Comments/documentation tell the *what* and the *why*, not necessarily the *how*
  * Generally, code should be *self-documenting*: any reasonable person who has programming experience should be able to read the code and understand how it works
  * Single line comments begin with `//`, multiline: `/*` and end with `*/`
  * Doc-style comments: begin with `/**` and have a vertical line of stars, get in the habit of using them!

* Preprocessor directives begin with a hash `#`
  * You can include external libraries: `#include` and providing the "name" of the library (`.h` is for the "header" of that library)
  * Example: `#include <math.h>`
  * `#define` is a macro: it essentially is a cut-and-replace operation by the preprocessor (something that runs before the compiler)
  * Macros also allow you to represent a single value in a single place (constants)
  * Macros make your code more readable and maintainable (dont' use Magic Numbers)

* Every executable program has a main entry point: usually a `main` function or in Java, a `main` method
* Linear control flow: a program executes top to bottom, left to right
* Other syntax and punctuation:
  * semicolons end executable statements
  * curly brackets (opening and closing) denote *code blocks*
  * parentheses denote function calls or "groups" of things
  * commas delimit lists of similar things
  * double quotes denote *strings* which are sequences of characters
  * whitespace helps to make your code more readable: in general statements at the same "level" should have the same indentation
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

* Types of variables (in both languages):
  * `int` are integer whole numbers, negatives, positives, zero
  * integers are 32-bit signed, 2s-complement integer: it can represent whole numbers negative, zero and positive in the range: -2147483648 to 2147483647 $-2^{31}$ up to $2^{31}-1$
  * `double`: 64 bit IEEE 754 floating point number: you can represent decimal numbers with about 16 digits of accuracy
  * `char`: a single ASCII text character (in C), a single *unicode* character in Java


```text









```
