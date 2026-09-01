# Computer Science I
## CSCE 155E Fall 2026
### C Basics

An overview of basics of C including variables, input and output.

## Program, Compile, Run a Program

* A source file is a *plain text* file containing computer code in a particular language
* A source file is then compiled into an *executable program* (in binary)

$$source \rightarrow assembly \rightarrow machine\,\, code$$

## Program Anatomy

### Comments

* Comments are human-readable messages embedded in code
* Syntax:
  * Single line comments: begin with `//`, anything after that is ignored (until the next line)
  * Multiline comments: begin with `/*` and end with `*/`
* Doc-style comments: are multiline comments but with a `/**` and a vertical line of stars to offset them
* All comments are ignored by the compiler, system, etc.
* Purpose: communicate to other humans what the purpose or intent of the code was
* Comments/documentation tell the *what* and the *why*, not necessarily the *how*
* For now: all of your programs should have an author header: name or names, date, email, *purpose of the program*
* Careful: comments should not be Cruft = unneeded clutter in your code
* Instead: code should be self-documenting: code itself should tell you the HOW

### Preprocessor

* Preprocessor directives begin with a hash `#`
  * You can include external libraries using `#include` and provide the name of the library (generally they end with a `.h` - a *header* file)
  * Ex: `stdlib.h`, `stdio.h` (standard input/output)
  * Ex: `math.h` allows you access to functions such as `sin()`, `cos()`, `sqrt()`
  * Constants: `M_PI`, `M_E`
* `#define` is a macro: it essentially is a cut-and-replace operation by the preprocessor (something that runs before the compiler)
  * Macros also allow you to represent a single value in a single place (constants)
  * Macros make your code more readable and maintainable (don't use Magic Numbers)

### The Main

* Every program has to have a starting point
* Generally this is done in a `main()` function
* Linear control flow: a program executes top to bottom, left to right

### Other Stuff

* Punctuation:
  * Executable statements end with a semicolon: `;`
  * Opening/closing curly brackets `{...}` denote *code blocks* similar to "paragraphs" in English
  * Parentheses are used with functions and function calls (just like math: $f(x) = x^2$)
  * Double quotes: `"..."` are used to define *strings*: sequences of characters (plain English but also numbers, punctuation, etc. )
  * Commas denote items in a list
  * Square brackets: `[]` denote arrays (more on that later)
  * Single quotes: `'C'` are for single characters
* White space is used to make your code more readable
  * Indentation: code at the same level in the same block should be indented and indented to the *same level*
  * Vertical space can be used to "chunk" pieces of code together in the same code block
* Style should be *consistent*
* You can use `astyle` to reformat your code, but you should write it correctly to begin with

### Variables

* Variable values can change in a program, they can *vary*
* C is a *statically typed* language
* It simply means that you have to declare a variable before you can use it:
  * You have to specify the *type* (`int, double, char`)
  * You have to specify the *name* (identifier)
  * Types:
    * `int` - integer, a whole number, negative and positive, zero
    * `int` is a 32-bit signed 2-s complement integer it can represent whole values (integers) in the range:
    $$-2,147,483,648 \leq x \leq 2,147,483,647$$

    $$-2^{31} \leq x \leq 2^{31}-1$$
    * Beware of overflow!  If numbers get too big, they wrap around to the negative side
    * Underflow: numbers get too small and wrap around positively
    * A `double` value is an IEEE754 64 bit formatted floating point number: limitation: you can represent at most ~17 digits of accuracy/precision: "floating" point numbers
    * `char` is a single ASCII text character <https://www.asciitable.com/>

#### Naming Variables

* Names cannot have spaces, should not have other "weird" characters (no unicode, no hyphens, etc)
* Cannot begin with a number and *should not* have any numbers
* Terrible variable names: `x, y, a, b, variable1, variable2, foo, bar, baz`
* Best practice: be *descriptive*
* Examples: `numberOfStudents`, `kilometers`, `miles`
* In general: avoid ambiguous abbreviations: `ssn`, `nuid`, `apr`
* Is `kms` a "good" variable name?  Its probably "good enough"
* Ex: `eidr`, `isbn`
* Use a *consistent* naming convention!
  * Recommendation: `lowerCamelCasing` for all variables (modern convention)
  * Old School C (python): `lower_underscore_casing`
  * `UpperCamelCasing` (in other languages, Java, etc.), later on: enumerations and structures
  * `UPPER_UNDERSCORE_CASING`: `M_PI` (this is used for constants or macros)
* BE CONSISTENT
* Variables should *nouns* and should *generally* be singular

### Operators

* Arithemetic operators: `+` (addition), `-` subtraction,
  * Multiplication: can't use $\times, \cdot, ab$; instead: `*` (asterisk)
  * Division: can't use $\frac{a}{b}$, instead: `a / b`
* variables hold values, you need a way to get values into those variables
  * Syntax: To do this, you use the assignment operator: `=`
  * A *single equals sign*! This is not algebra!
  * Instead it means: take the value of the thing on the right hand side (RHS) and place it into the variable on the left hand side (LHS)
  * The RHS can be a variable, a value, an expression, etc.
* PEMDAS rules apply
* PEMDAS = (Parentheses Exponents, Multiplication, Division, Addition, Subtraction)
* The following are *not* equivalent: `a * b + c` is not the same as `a * (b + c)`
* Example: `a + b * c`: `b * c` is evaluated FIRST and then `a` is added
* Example:
  $$x = \frac{-b\pm \sqrt{b^2-4ac}}{2a}$$

```c
double a = 10, b = 20, c = 4;

double root1 = (-b + sqrt( b * b - 4 * a * c )) / ( 2 * a );
double root2 = (-b - sqrt( b * b - 4 * a * c )) / ( 2 * a );

printf("roots are %f, %f\n", root1, root2);

```

#### Pitfalls

* Some math functions are invalid:
  * `1 / 0` resutls in `-inf` or `inf`
  * `sqrt(-1)` should be $i$, but in C it is `nan` = Not A Number
* When you add/subtract/multiply two **integers** the result is *always* an integer
* When two integers are divided the factional part is thrown away (*truncation*)
* To solve this, you can use *typecasting*

```c

    int a = 10;
    int b = 20;
    double c = a / (double) b;

    printf("c = %f\n", c);
```

* `double` values are impresise, use `int` for whole numbers, because they are *exact*
* When using the math library you may need to provide `gcc` with some additional flags:
  * `gcc foo.c -lm`
  * `l` means link in and `m` means the math library

## Input/Output

* `printf` can be used to **print** in a **f**ormatted manner to the *standard output*
* There are several *placeholders* that you can use in a format string:
  * `%f` used for `double` values, defaults to 6 decimals of accuracy
  * `%d` used for `int` values
  * `%c` formats a single `char`
* You can provide as many placeholders in a string as you want but the *order matters*

```c

    int a = 42;
    double b = 3.5;
    char initial = 'C';

    printf("a = %d, b = %f, initial = %c\n", b, a, initial);

    printf("a = %d\n", a);
    printf("b = %f\n", b);
    printf("initial = %c\n", initial);

```

### Formatting

* You can use *modifiers* to specify more digits of accuracy for floating point numbers
* General form: `%X.Yf`
  * `X` - minimum number of columns to print
  * `Y` - number of decimals of accuracy

```c

    double pi = 3.14159;

    printf("%f\n", pi);
    printf("%.10f\n", pi);
    printf("%.2f\n", pi);
    printf("%.4f\n", pi);
    printf("%f\n", pi);

    printf("%10.4f\n", pi); //pads to the left 4 spaces
    printf("%-10.4f\n", pi); //justifies left

    //integers too:
    int nuid = 123456;
    printf("%d\n", nuid);
    printf("%8d\n", nuid);
    printf("%08d\n", nuid);
```

## Standard Input

* Standard input is used with *interactive* programs
* You use `scanf` to scan the standard input (keyboard) for user-provided input
* Very limited, very brittle
* With `scanf` you use the same placeholders except for `double` values: you use `%lf`instead of `%f`
* When using `scanf` always remember the ampersand `&` in front of the variable (magic for now)
* ex: `scanf("%lf", &miles);`

### Non-interactive Input

* Most programs especially command line programs are *not* interactive
* From the command line, you can provide input *non-interactively* by using *command line arguments* (CLAs)
* CLAs are provided when you start the program: `./a.out hello 10 3.5`
  * There are actually 4 arguments: the first argument is always the executable file name `./a.out`
  * `argc`: the number or **c**ount of the arguments
  * `argv`: is a **v**ector (array) of the acutal arguments
    * `argv[0]` is the first argument, `./a.out`
    * `argv[1]` is the second argument (first user provided argument)
    * `argv[2]` is the third, etc.
  * Processing:
    * CLAs themselves are *strings* (sequences of `char` values)
    * `atoi` converts the argument to an `int`
    * `atof` converts the argument to a `double`

```c
    printf("You provided %d CLAs\n", argc);

    //assume the first user provided (the second argument)
    // argument is an integer and convert it...
    int x = atoi(argv[1]);
    printf("You gave me a value of %d\n", x);

    //second user provided: assume it is a double
    double y = atof(argv[2]);
    printf("You gave me a value of %f\n", y);
```

## Exercises

1. Convert the `miles_to_kms` program to non-interactive input

```c
/**
 * Author: Chris Bourke
 * Date: 2025/08/27
 *
 * This program converts miles to kilometers
 */
#include <stdlib.h>
#include <stdio.h>

#define KMS_PER_MILE 1.60934

int main(int argc, char **argv) {

    if(argc != 2) {
        printf("ERROR:  you must provide the number of miles\n");
        exit(1);
    }

    double miles, kms;

    // printf("Please enter miles: ");
    // scanf("%lf", &miles);

    miles = atof(argv[1]);

    kms = KMS_PER_MILE * miles;

    printf("%f miles is equal to %f kilometers\n", miles, kms);

    return 0;
}
```

2. Write a program to compute the roots of a quadratic equation:
  $$ax^2 + bx + c = 0$$
  $$x = \frac{-b\pm \sqrt{b^2-4ac}}{2a}$$

```c
/**
 * Author: Chris Bourke
 * Date: 2026/08/31
 *
 * This program computes the roots of a quadratic equation:
 *   ax^2 + bx + c = 0
 *
 * See more at https://en.wikipedia.org/wiki/Quadratic_formula
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

    if(argc != 4) {
        printf("ERROR: please provide coefficients a b c\n");
        exit(1);
    }

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);

    if(a == 0) {
        printf("ERROR: you have a linear equation, not a quadratic!\n");
        exit(2);
    } else if(b * b - 4 * a * c < 0) {
        printf("ERROR: I cannot handle complex numbers!\n");
        exit(3);
    }

    double root1 = (-b + sqrt( b * b - 4 * a * c )) / ( 2 * a );
    double root2 = (-b - sqrt( b * b - 4 * a * c )) / ( 2 * a );

    printf("%fx^2 + %fx + %f has roots %f and %f\n", a, b, c, root1, root2);


    return 0;
}


```

```text














```
