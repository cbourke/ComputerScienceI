# Computer Science I
## CSCE 155H - Fall 2022
### Intro to C/Java: Basics

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

## Input/Output

### C

* Output in C is done with `printf`
* You can provide any "formatted" string and it will print to the *standard output*
* Input in C is done with `scanf`
* For both: you use *placeholders* to indicate the type of variable that should be input/output
  * `%d` for integers (whole numbers, `int`)
  * `%f` is for floating point numbers (`double`s) for printing
  * `%lf` is for `double`s when using `scanf`
  * `%c` is for single characters `char`
* GOTCHA: when using `scanf` to read in a variable, always use the ampersand: `&`

## Variables

* Types of variables (in both languages):
  * `int` are integers (whole numbers, negative, positive, zero)
  * BUT: integers are only 32-bit signed, 2s complement integers
  * integers are 32-bit signed, 2s-complement integer: it can represent whole numbers negative, zero and positive in the range: -2147483648 to 2147483647 $-2^{31}$ up to $2^{31}-1$
  * `double`: 64 bit IEEE 754 floating point number: you can represent decimal numbers with about 16-17 digits of accuracy
  * Computers essentially use scientific notation for representing floating point numbers:
    $$3.14159 \times 10^{5}$$
  * `char`: C: a single ASCII character, Java: a single unicode character
* Variables *must* be *declared* before they can be used
* Variables *must* be *in scope* to be visible.  "scope" is the section of code in which a variable exists (before and after it is not visible)

### Java Items

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

## Operators

* The *assignment* operator is the single equals sign: `=`

```c
int x;

//what value is stored in x?
//C: undefined
//Java: undefined, but you are prevented from using it!

//set the value to 10...
x = 15;
//reset its value:
x = 20;

//gotcha:
int y = 30;
x = y;
y = 40;
//x now has value 30, y has value 40

//you can declare and set multiple variables at the same time
int a = 10, b = 20, c = 30;

double r = (b*b - sqrt(4*a*c)) / (2*a)

```

* Code follows PEMDAS rules
* Arithmetic operators: `+, -, *, /`
* `a + b * c` is not the same as `(a + b) * c`
* Integer division: `%`: it provides the *remainder* after dividing by an intger
  * `10 % 3` results in a remainder of 1
  * `11 % 3` results in 2
  * `11 % 2` results in 1
  * `10 % 2` results in 0

### Gotcha: mixing types

* Dividing two integers results in an integer: resulting in *truncation*: the floating point (fractional) part is cut off and thrown away
* To solve this, you can use *type casting*: treat at least one of the variables as a `(double)` for the purposes of evaluating the expression

```c
int x = 10;
int y = 20;
double z = x / (double) y;
printf("%f\n", z);
```

### Variable naming

* Both languages have identifier naming *rules*: may consist of letters (upper/lower case), numbers, underscores, etc.  But may NOT begin with a number
* In general: you should use clear and consistent naming conventions and names that are *descriptive*
* Good convention: `lowerCamelCasing`: ex: `numberOfStudents`
* Bad variable names: `myVariable`, `someVariable`, `myVariable002`
* It depends: `a, b, c, x, y`
* You should generally avoid abbreviations, acyronyms, etc. unless it is *absolutely clear*
* Avoid pluralizations unless it is modeling a collection (array) of things

## Basic I/O

* Both languages support standard input and output:
  * Standard input = keyboard
  * Standard output = terminal
* Input in C: `scanf` is used for input
* In Java you use a `Scanner` to read the standard input `System.in`
* In both languages you can use `printf`-style printing/formatting
* Details:
  * Placeholders: `%d, %f, %c` for `int, double, char` respectively
  * YOu can add *modifiers*: you can specify a certain number of decimal places of accuracy
  * `%20.10f` : print a minimum of 20 columns with 10 decimals of precision

```java
double pi = 3.14159;
System.out.printf("%.3f\n", pi);
System.out.printf("%.10f\n", pi);
double balance = 123.545;
double y = Math.round(balance * 100) / 100;
double percent = 0.035;
System.out.printf("%f %%\n", percent * 100);
System.out.printf("$%.2f\n", y);
```

# Non-interactive Input

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

### Java

* In Java, the arguments are provided in the array `args`
* There is no `argc` instead use `args.length`
* The first argument is the actual first user argument, not the class name!
* To convert use:
  * `Double.parseDouble(...)`
  * `Integer.parseInt(...)`

```text






```
