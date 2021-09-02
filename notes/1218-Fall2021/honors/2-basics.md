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
* Variables *must* be *declared* before they can be used
* Variables *must* be *in scope* to be visible.  "scope" is the section of code in which a variable exists (before and after it is not visible)

## Operators

* The assignment operator or the single equals sign assigns values to variables

```c
int x;

//set the value of x to 10 (a literal)
x = 10;
//reset its value to another value:
x = 20;

//you can also set a variable's
//value to the value of another variable
int y = 30;
x = y; //x now has a value of 30
y = 40;
//what value does x have now?

//you can declare multiple variables with
// multiple assignments:
int a = 10, b = 20, c = 30;
//you can have full mathematical exprssions:
double r = (b*b - sqrt(4*a*c)) / (2*a);
```

* Arithmetic operators: `+, -, *, /`
* Arithmetic operators follow PEMDAS
* `a + b * c` is not the same as `(a + b) * c`
* Integer division operator: `%`: it provides the *remainder* after division
  * Ex: `10 % 3` has a remainder of 1
  * `11 % 3` has a value of 2
  * `12 % 3` has a remainder of 0
  * `11 % 2` has a remainder of 1
  * `12 % 2` has a remainder of 0

### Variable naming

* Both languges have identifier naming rules: may consist of letters (upper/lower case), numbers, underscores, etc. but may NOT begin with a number
* In general: adopt a clear and consistent naming convention
* Our *strong* suggestion is that you use `lowerCamelCasing`
* Ex: `annualPercentageRate`, `numberOfStudents`
* Alternatives: `lower_underscore_casing`
* In Java: `UpperCamelCasing` is reserved for class names
* You should generally avoid abbreviations, acyronyms, etc. unless it is *absolutely clear*
* You should avoid `x` or `foo, bar, baz`, `variableA, variable1, variable2, variable3` etc.
* Avoid pluralizations
* In general your variables should be immediately identifiable

### Default Values

* In Java, if you do not assign a value then the variable cannot be used (compiler error)
* In C, there is no default value for uninitialized variables, thus it *could* have garbage values

### Pitfall: Truncation

* an integer and a floating number are not the same thing
* When you operate on two integers, the result *must* be an integer: addition, subtraction, multiplication: no problem
* Division presents a problem: the result must be an integer
* When two integers are divided, the fractional part (floating point part) is cut off and thrown away
* This is *NOT* rounding or flooring
* Solution: use temporary *type casting*: you temporarily treat at least one of the operands as a `double` variable

```c
int a = 10;
int b = 20;
double c = (double) a / b;

printf("%f\n", c);

```

## Basic I/O

* Both languages support standard input and output:
  * Standard input = keyboard
  * Standard output = terminal

* Input in C: `scanf`
* When invoked, `scanf` blocks the execution of the program allowing the user to enter in whatever they want until they hit the enter key
* Then `scanf` scans the input for a formatted input
* Scanf uses one of several *placeholders*:
  * For `int` variables, it uses `%d`
  * For `double` variables it uses `%lf`
  * For a `char` variable it uses `%c`
* For now: just remember that you *have to* put an ampersand in front of the variable that you want the input stored in

* Standard Output: C

* For output you use the `printf` function
* F = formatted, you can use *similar* placeholders
  * `int`: `%d`
  * `double`: `%f`
  * `char`: `%c`
* You can provide multiple placeholders in the same print statement, each placeholder is matched to each variable in the order you specify

```c

int a = 10;
double b = 3.14;
char initial = 'C';

printf("the values are %d, %f, %c\n", b, a, initial);
```

* You can further modify the format using modifiers: `%n.mf`
  * `n` is the minimum number of columns to print
  * `m` is the number of decimal digits to print
  * By default it prints 6 decimals of precision

```c
double balance = 42.509;

    printf("Your balance is $%.2f\n", balance);

    printf("%f\n", M_PI); //prints 3.141593
    printf("%.10f\n", M_PI); //prints 3.1415026536
    printf("%.1f\n", M_PI); //prints 3.1

    printf("%20.10f\n", M_PI); //prints 8 leading spaces then 3.1415026536

    int nuid = 1234567;
    printf("your nuid is %08d\n", nuid);
```

* Java supports printf using `System.out.printf`

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
