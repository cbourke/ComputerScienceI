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
* The single equals sign is the *assignment operator*: take the thing/value on the RHS (right hand side) and place it into the single variable on the LHS (left hand side)
* You can assign a value at declaration or at any time after declaration 

### Default Values

* In Java, if you do not assign a value then the variable cannot be used (compiler error)
* In C, there is no default value for uninitialized variables, thus it *could* have garbage values

### Scoping

* The *scope* of a variable is the section(s) of code in which it is *visible*: after declaration, up until the end of a code block

### Naming

* Both languages have identifier naming rules: may consist of letters, numbers, underscores, etc.; it may NOT begin with a number
* In general: adopt a clear and consistent naming convention
* Example: `lowerCamelCasing`: no underscores, the first word is all lower case, each subsequent word has its first letter as a capital
* Example: old school `lower_underscore_casing`
* Java class names are always `UpperCamelCased`
* Always be consistent with whatever convention you adopt
* Avoid poor nondescriptive variable names `x`, `foo`, `myVariable`; name a variable after what it represents
* Avoid pluralizations 
* Avoid abbreviations/short forms/acronyms unless it is *absolutely* understood from the context

### More Operators

* Arithmetic operators: `+, -, *, /`
* Operators also follow PEMDAS rules (order of operations)
* `a + b * c` is not the same as `(a + b) * c`
* Integer division or *modulus* operator: `%` gives you the remainder of integer division
* Division by zero can lead to *consequences*: floating point exceptions, division by zero, INF, NaN

### Truncation

* an integer and a floating number are not the same thing
* When you operate on two integers, the result *must* be an integer: addition, subtraction, multiplication: no problem
* Division presents a problem: the result must be an integer
* When two integers are divided, the fractional part (floating point part) is cut off and thrown away
* This is *NOT* rounding or flooring
* Solution: use temporary *type casting*: you temporarily treat at least one of the operands as a `double` variable

## Basic Input/Output

* Both languages support output/input to the *standard output/input*
* standard input = keyboard
* standard output = terminal

* Standard Input: C

* You use the `scanf` function
* When invoked/called a program will *block* until the user enters an input and hits enter; at which point the program resumes operation and reads whatever the user entered
* When using `scanf` you can use one of several *placeholders* depending on the type of variable you want to read
  * `int`: `%d`
  * `double`: `%lf`
  * `char`: `%c`
* For now: just remember that you *have to* put an ampersand in front of the variable that you want the input stored in

* Standard Output: C

* For output you use the `printf` function
* F = formatted, you can use *similar* placeholders
  * `int`: `%d`
  * `double`: `%f`
  * `char`: `%c`
* You can provide multiple placeholders as long as you provide multiple variables or values to print; the order matters

* With `printf` you also have more fine-grained control on how things are printed: how many columns and how many digits of accuracy for `double` values

```c

  //default: 6 decimals of accuracy
  printf("pi = %f\n", M_PI);
  //print it out to 10 decimals of accuracy:
  printf("pi = %.10f\n", M_PI);
  //you can also print out leading columns or "padded" columns:  
  printf("pi = %10.3f\n", M_PI);

  //you can also do it for integers:
  int nuid = 1234;
  printf("nuid = %08d\n", nuid);

```

### Java I/O

* For standard output you can use `System.out.print` (no endline added), `System.out.println` (adds the endline for you), 
`System.out.printf` (copy paste all your knowledge about C into this!)

```java
int a = 10;
double x = 3.1415;
char initial = 'C';

System.out.println(
  "a has the value " +
  a + 
  " and x = " + 
  x + 
  " and my initial is " + 
  initial);
System.out.printf("a = %d, x = %f and 
  my initial is %c\n", a, x, initial);

```

* Standard input in Java: use a `Scanner`
* a `Scanner` can be initialized to read in from the standard input: `System.in`
* You can then use `.next()` (strings) or `.nextInt()`, `.nextDouble()` etc.

## non-interactive input

* Scanner/scanf essential prompt a human user for input and wait for standard input (from a human mashing their keyboard)
* You can read in input directly from the command line as *Command Line Arguments* (CLAs)

### C

* CLAs are provided using the `argc` (argument count, the number of arguments provided) and `argv` (argument vector: the list of arguments) arguments to the `main` function
* `argv[0]` is *always* the executable file name (example: `a.out`)
* `argv[1]` is the first actual argument provided by the user
* `argv[2]` is the second
* `argv[argc-1]` is the last one!
* All arguments are actually strings in both languages, so you may need to conver them:
  * convert to a `double`: use `atof()`
  * convert to an `int`: use `atoi()`

```text








```
