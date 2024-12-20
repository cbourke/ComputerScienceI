# Computer Science I
## CSCE 155H Fall 2024
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
* For now: all of your programs should have an author header
* Code should be *self-documenting*: it should be written clearly enough that an experienced user could understand the *how*
  * Single line comments begin with `//`, multiline: `/*` and end with `*/`
  * Doc-style comments: begin with `/**` and have a vertical line of stars, get in the habit of using them!

### Preprocessor

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

* Punctuation:
  * Semicolons end executable statements (like sentences and periods)
  * Commas are used to separate things in lists
  * Quotation marks (double quotes) denote *strings* `"this is a string"`
  * Brackets: `{}` curly brackets create *code blocks*: chunks of code that are in one "piece" (like paragraphs)
  * Parentheses denote function parameters (inputs)
  * Square brackets (later) are used in arrays: `[]`
  * Single quotes (both C and Java): are used for single *characters*: `'C'`
  * Whitespace makes code more readable: vertical whitespace separates lines, horizontal whitespaces indents *blocks* of code
  * whitespace helps to make your code more readable: in general statements at the same "level" should have the same indentation
      * Style above all should be *consistent*
      * Unless you have a Very Good Reason (VGR)
  * Reserved words: `int, double, char`

## Variables

* Both C and Java are *statically typed* langauges
  * Before you can use any variable you need to *declare it*
  * You need to define its name (identifier) and its *type*: `int, double, char`
  * Where ever you declare a variable, is its *scope*: the area of the code that the variable can be "seen" and is therefore valid
* Basic Types:
  * `int` is a 32-bit 2-s complement integer
  * you can represent 0, negative and positive numbers in the range: -2,147,483,648 to 2,147,483,647
  $$-2^{31} \ldots 2^{31}-1$$
  * `double` is a 64-bit IEEE 754 floating point number
  * You can represent decimal numbers with about 17 digits of accuracy
  * `char`: is a single character; in C: it is an ASCII text value, in Java: it is a full Unicode value

### Best Practices

* Follow a consistent naming convention
* Recommendation: `lowerCamelCasing` for all variables (both languages)
* Others:
  * `lower_underscore_casing` (old-school C)
  * `UPPER_UNDERSCORE_CASING` (constants)
  * `UpperCamelCasing` (Java class names)
* Be *descriptive*:
  * Bad variable names: `foo, bar, baz, a, b, c, x, y, variable1, variable2, var1, etc`
  * Good variable names: `numberOfStudents, miles, kilometers`
  * Generally avoid abbreviations unless the context means that the variable name is well-understood

## Operators

* Assignment operator: you can assign a value or value of an *expression* to a variable
  * Syntax: `=` (single equals sign)
  * Examples

```c
int a = 10;
a = 20;

double y = a * b + c;
double z = a + b * c;
double t = (a + b) * c;

```

* Arithmetic operators: `+, -, *, /` (addition, subtraction, multiplication, division)
* PEMDAS = Parentheses, Exponent, Multiplication Division, Addition Subtraction
* Example:
  $$x = \frac{-b \pm \sqrt{b^2-4ac}}{2a}$$

```c
double x1 = (-b + sqrt( pow(b, 2) - 4*a*c ) ) / (2*a);
double x2 = (-b - sqrt( pow(b, 2) - 4*a*c ) ) / (2*a);
```
* Invalid opeartions: $\sqrt{-1} = i$ but in code... it is "not a number" or `NaN`
* `1 / 0` infinity or negative infinity
* Remainder you can get the remainder after integer division using `%` (read it as: mod or modulo)
  * `10 % 3` results in 1
  * `10 % 2` results in 0
  * `10 % 4` results in 2
* Trick: how can you tell if a number is even?  `a % 2` would be zero (odd would be one)

### Default Values

```c
int a;
```

* C has NO DEFAULT VALUES!  It could be anything!
* It is best practice to *initialize* your variables

```c
int a = 0;
```

* In C, there is no default value for uninitialized variables, thus it *could* have garbage values: `0xDEADBEEF`
* In Java: uninitialized values are *not allowed*
* In Java: class values may have a `null` default value in the context of a class (but NOT local variables)

### Pitfall: Truncation

```c
int x = 10;
int y = 20;
double z = x / y;
```

* The result of integer `* + - /` must be an integer, so the fractional part is chopped off and thrown away
* Sometimes you DO want to preserve the fractional part
* Solution: typcast!

```c
int x = 10;
int y = 20;
double z = x / (double) y;
```

## Input/Output (I/O)

### C

* Output in C is done with `printf` (f = formatted)
* You can provide a "formatted" string and it will print to the standard output
* For both language: you can use *placeholders*: they indicate the type of variable to be formatted
  * `%f` is for floating point numbers (`double`)
  * `%d` is for integers (`int`)
  * `%c` for `char` values
* THe default for floating point numbers is to print 6 decimals of accuracy
* Alternatively: you can use *modifiers* to print more/less
  * Format: `%X.Yf` where
  * `X` is the minimum number of columns (including the decimal)
  * `Y` is the number of digits of accuracy
  * Both are optional

### Java

* Supports `System.out.print` (no endline), `System.out.println` (adds an endline), `System.out.printf`

```java
System.out.printf("pi = %f\n", Math.PI);
System.out.printf("pi = %.2f\n", Math.PI);
System.out.printf("pi = %.4f\n", Math.PI);
System.out.printf("pi = %.10f\n", Math.PI);
System.out.printf("pi = %.100f\n", Math.PI);
System.out.printf("pi = %10.2f\n", Math.PI);
System.out.printf("pi = %10.4f\n", Math.PI);
System.out.printf("pi = %10.10f\n", Math.PI);

int x = 1234;
System.out.printf("%8d\n", x);
System.out.printf("%08d\n", x);

int a = 10;
int b = 20;
System.out.println("a is " + a + " and b is " + b);
```

```c

    printf("pi = %f\n", M_PI);
    printf("pi = %.2f\n", M_PI);
    printf("pi = %.4f\n", M_PI);
    printf("pi = %.10f\n", M_PI);
    printf("pi = %.100f\n", M_PI);

    printf("pi = %10.2f\n", M_PI);
    printf("pi = %10.4f\n", M_PI);
    printf("pi = %10.10f\n", M_PI);

    int x = 1234;
    printf("%8d\n", x);
    printf("%08d\n", x);

```

## Standard Input

* The standard input is your keyboard: interactive input

### C

* You can use `scanf` to scan the standard input
* For `scanf`, you need to use the placeholder `%lf` for `double` values
* You need to put an ampersand `&` in front of the variable using scanf

```c
int x;
printf("Please enter an integer: ");
scanf("%d", &x);
printf("I read %d\n", x);

double y;
printf("Please enter a number: ");
scanf("%lf", &y);
printf("I read %f\n", y);
```

### Java

* In Java you can create a `Scanner` to scan the standard input

```java
Scanner s = new Scanner(System.in);
System.out.print("Please enter an integer:");
int x = s.nextInt();

System.out.print("Please enter a number:");
double y = s.nextDouble();

System.out.printf("x is %d and y is %f\n", x, y);
```

## Non-interactive input

* Interactive input (using `scanf`) makes the program pause and wait for the user to enter in their input
* Most programs especially command line programs are *not* interactive
* From the command line, you can provide input *non-interactively* by using *command line arguments*
* CLAs are provided when you start the program: `./a.out hello 10 3.5`
  * Each is separated by spaces
  * IN C: the first argument is always the executable file name, but in Java: the first argument is the first *user* provided argument
  * You can access them:
    * THe first: `argv[0]`
    * Second: `argv[1]`
    * Third: `argv[2]`
    * `argc` standard for argument **c**ount
  * THe inputs are all strings, so you need to convert them if they are numbers:
    * `atoi` (for `int`s)
    * `atof` (for `double`s)

```c
int x;
double y;

x = atoi(argv[1]);
y = atof(argv[2]);


printf("I read %d\n", x);
printf("I read %f\n", y);

```

```java

int x;
double y;

x = Integer.parseInt(args[0]);
y = Double.parseDouble(args[1]);


System.out.printf("I read %d\n", x);
System.out.printf("I read %f\n", y);
```

* Bad input in Java results in an exception (error)


## Exercise

```c
/**
 * Author
 * Date
 *
 * This program reads in 3 coefficients of a quadratic polynomial:
 *
 * ax^2 + bx + c
 *
 * and computes and outputs its two roots.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

    double a, b, c;

    if(argc != 4) {
        printf("ERROR: you did not provide the correct number of command line arguments\n");
        exit(1);
    }

    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);

    if(a == 0) {
        printf("ERROR: a cannot be zero, you have a linear equation, just solve it!\n");
        exit(2);
    }

    double x1 = (-b + sqrt( pow(b, 2) - 4*a*c ) ) / (2*a);
    double x2 = (-b - sqrt( pow(b, 2) - 4*a*c ) ) / (2*a);

    printf("%fx^2 + %fx + %f has roots %f and %f\n", a, b, c, x1, x2);

    return 0;
}


```

```text









```
