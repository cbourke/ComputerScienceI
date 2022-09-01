# Computer Science I
## CSCE 155E Fall 2022
### C Basics

Consider a basic *input/output* program to convert miles
to kilometers...
  * Basic program framework
  * Prompt the user for some input
  * Read the input
  * Store the input
  * Convert the values (math)
  * Output the results

## Programming, Compiling, Running

  * Source files are *plain text* files containing computer code in a highlevel programming language
  * Source files have to be compiled into an *executable program* (binary code)
    * *source → assembly → machine code*

## Basics

### Comments

* Comments are human-readable messages embedded in code
  * Ignored by the compiler
  * You can have single line comments: `//`
  * YOu can have multiple line comments: begin with a `/*` end with a `*/`
  * You can have doc-style comments: just a regular multiline comment with an extra star and vertical formatting starts: you use it for each major program or major function you write
  * Comments, especially documentation is intended to tell the user (other programmers and the future you) the *why* and the *how* of the code, NOT the *what*
  * Code should be *self-documenting*: code should tell you the what

### Preprocessor Directives

* Commands or directives or "macros" that are executed before the compiler compiles your code
  * `#include` brings in external or standard libraries so that you don't have to code from scratch
  * `#define` defines "alias" that can be used to replace "magic numbers"
    * You can replace magic numbers with human-readable text
    * Only one change is necessary instead of multiple changes

### Main Function

* The `main` function is always the starting point for any executable program
  * For now: `argc, argv` are "magic" (they are command line arguments)
  * Commas delimit lists of things
  * Semicolons terminate the end of any executable statement
  * Blocks of code are denoted using opening and closing curly brackets `{...}`
  * In general whitespace doesn't matter

### Input/Output

* Output in C can be done using `printf`
* Stands for print *f* ormatted in which you can print variable values using *placeholders*
  * Use `%f` for floating point numbers (fractional numbers 10.5, 3.14, -10.2, 10.0)
  * Use `%d` for integer (whole numbers)
  * Use `%c` for single characters
* Input in C can be done using `scanf`
  * When using `scanf`, use the same placeholders *except* when reading in a `double` value: then use `%lf`
  * GOTCHA: when using `scanf` to specify the variable you want to read *into*, you place an ampersand `&` in front of it (reasons)

### Variables

* C is a *statically typed* language
  * Basically you need to *declare* a variable before you can use it
  * Declaring a variable means specifying its *type* and its *name*
  * A variable only exists within the block of code in which you declare it; this is known as the variable's *scope*
* Types:
  * `int` - a whole number, positive, negative, zero BUT with a limited range
  $$-2147483648 \leq x \leq 2147483647$$
  * `double` - floating point numbers that can represent any fractional value with *about* 16-17 digits of accuracy
  * `char` - a single character value from the ASCII text table
  * Others: look them up
* Variable Naming
  * Generally you should use `lowerCamelCasing` convention for your variables
  * Other conventions:
    * `UPPER_UNDERSCORE_CASING` - generally used for macros and constants: ex: `M_PI`
    * `lower_underscore_casing`
  * No whitespace is allowed in variable names
  * Variable names MUST begin with letter
  * MAY contain numbers and letters
  * Good variable names are *descriptive*: they describe what the variable is modeling: `numberOfStudents`, `miles`
  * Hmmm: `kms`, `apr`, `ssn`, `nuid`
  * BAD: `myvariable`, `var001`, `a, b, c`
  `x, y` (in general), `xx`, `yy`, `i, j, k`

### Operators

* Algebraic Operators:
  * Addition: `+`
  * Subtraction: `-`
  * Multiplication: `*`
  * Division: `/`
* Assignment Operator
  * It is a single equals sign: `=`
  * It is *NOT* the algebraic left hand side is equal to the right hand side
  * It takes the value, expression or other variable from the *right hand side* and places it into the variable on the *left hand side*
* PEMDAS = Parentheses, Exponents, Multiplication, Division, Addition, Subtraction
  * `a + b * c` is not the same thing as `(a + b) * c`

#### Truncation

* WHen you divide an integer by an integer, the result is always an integer
* The fractional part (floating point part) is truncated: it is cut off and thrown away
* To avoid this, you can use *type casting*:

```c
a = 10;
b = 20;
r =  a / (double) b;
printf("r = %f\n", r);
```

#### Integer Division

* You can use the integer division operator: `%`
  * Ex: `10 % 3` the result is 1 (remainder!)
  * `10 % 2` results in 0
  * `11 % 2` results in 1
  * `11 % 3` results in 2
  * `11 % 11` results in 0
  * `20 % 11` results in 9

#### More math stuff

* The math library `math.h` has several constants:
 `M_PI`, `M_E`
* `sin(), cos(), tan(), sqrt(), pow()`
* `log()` (natural, base-$e$ log), `exp()`
* Remember that you may need to compile with the `-lm` flag at the end in order to *link* in the *math* library
* What else is there?
* RTM = Read The Manual!

#### Formatting Output

* Recall that you can use `printf` to print to the standard output
* Placeholders: `%d, %f, %c`
* Modifiers: you can specify the *precision* (number of significant figures) to print
* By default: for `double` values, 6 digits of precision are printed
* You can modify it to specify the number of digits to print: `%.20f`
* You can modify to print a *minimum* number of columns: `%10.2f`

```c

    double pi = 3.14159;
    printf("pi = %f\n", pi);
    printf("pi = %.10f\n", pi);
    printf("pi = %.15f\n", pi);
    printf("pi = %.20f\n", pi);
    printf("pi = %.3f\n", pi);
    printf("pi = %f\n", pi);

    double balance = 123.545;
    double newBalance = round(balance * 100.0) / 100.0;
    printf("balance = $%.2f\n", balance);
    printf("newBalance = $%.2f\n", newBalance);

    double anotherBalance = 1793432.12;
    printf("$%.2f\n", balance);
    printf("$%.2f\n", anotherBalance);
    printf("\n\n\n");
    printf("$%10.2f\n", balance);
    printf("$%10.2f\n", anotherBalance);
```

```c

    int a = 10, b = 20, c = 0;

    printf("a, b, c = %d, %d, %d\n", a, b, c);

    //reset a value:
    c = 30;
    a = c;
    c = 42;

    printf("a, b, c = %d, %d, %d\n", a, b, c);

    double r = (-b + sqrt(b*b - 4*a*c))  / (2 * a);

    printf("r = %f\n", r);

    a = 10;
    b = 0;

    //division by zero is illegal/undefined
    // c = a / b;

    // printf("c = %d\n", c);

    a = 10;
    b = 20;
    r =  a / (double) b;
    printf("r = %f\n", r);

```

## Non-interactive Input

* Some programs expect a human user:
* Using `scanf` we *prompted* the user for input
* Most programs are not "interactive"
* Programs can be written to take input *non-interactively* through the use of Command Line Arguments (CLAs)
* CLAs are provided to a program when you invoke that program from the command line: `./a.out a b c 10 20 30`
  * The example above has 7 command line arguments
  * The number of command line arguments are available in `argc` (argument count)
  * The first argument is always the executable file name: `argv[0]`
  * `argv[1]` is the first user provided argument
  * `argv[2]` is the second *user* provided argument
  * all arguments are strings
  * If you need to convert from a string (alphanumeric) to an integer or double you need to use a function
  * `atoi`: converts to an integer
  * `atof`: converts to a float (`double`)

## Exercise

Write a program to compute the roots of
a quadratic polynomial:
  $$ax^2 + bx + c = 0$$

```c
/**
 * Chris Bourke
 * 2022/08/31
 *
 * This program reads in three coefficients to a quadratic polynomial
 * and outputs the roots of it
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

    double a, b, c;

    if(argc != 4) {
        printf("ERROR: you must provide 3 numbers...\n");
        exit(1);
    }

    // printf("Please enter a: ");
    // scanf("%lf", &a);

    // printf("Please enter b: ");
    // scanf("%lf", &b);

    // printf("Please enter c: ");
    // scanf("%lf", &c);

    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);

    double root1 = (-b + sqrt( b*b - 4*a*c)) / (2*a);
    double root2 = (-b - sqrt( b*b - 4*a*c)) / (2*a);

    printf("the roots of %fx^2 + %fx + %f are %f and %f \n", a, b, c, root1, root2);

    return 0;
}
```

```text






```
