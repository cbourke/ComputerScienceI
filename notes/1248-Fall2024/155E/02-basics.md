# Computer Science I
## CSCE 155E Fall 2024
### C Basics

An overview of basics of C and Java including variables, input and output.

## Program, Compile, Run a Program

* A source file is a *plain text* file containing computer code in a particular language
* A source file is then compiled into an *executable program* (in binary)

  $$source \rightarrow assembly \rightarrow machine\,\, code$$


## Program Anatomy

### Comments

* Comments are human-readable messages embedded in code
* Syntax:
  * Single line comment: `//`
  * Multiline comments: begin with `/*` and end with `*/`
  * All comments are ignored by the compiler, system, etc.
* Doc-style comments: are multiline comments but with a `/**` and a vertical line of stars to offset them
* Purpose: communicate to other humans what the purpose or intent of the code was
* Comments/documentation tell the *what* and the *why*, not necessarily the *how*
* For now: all of your programs should have an author header: name or names, date, email, *purpose of the program*
* Careful: comments should not be CRUFT = unneeded clutter in your code
* Instead: code should be self-documenting: code itself should tell you the HOW

### Preprocessor

* Preprocessor directives begin with a hash `#`
  * You can include external libraries using `#include` and providing the name of the library (generally they end with a `.h` - a *header* file)
  * Ex: `stdlib.h`, `stdio.h` (standard input/output)
  * Ex: `math.h` contains `sin()`, `cos()`, `sqrt()`
  * Constants: `M_PI`, `M_E`
* `#define` is a macro: it essentially is a cut-and-replace operation by the preprocessor (something that runs before the compiler)
* Macros also allow you to represent a single value in a single place (constants)
* Macros make your code more readable and maintainable (don't use Magic Numbers)

### The Main

* Every program has to have a starting point
* Generally programs start in the `main()` function
* Linear control flow: a program executes top to bottom, left to right

### Other Stuff

* Punctuation:
  * Semicolons end executable statements (like sentences and periods)
  * Commas are used to separate things in lists
  * Quotation marks (double quotes) denote *strings* `"this is a string"`
  * Parentheses denote function parameters (inputs)
  * Curly brackets denote *code blocks*: chunks of related code (kind of like a paragraph)
  * Square brackets: `[]` denote arrays (more on that later)
  * Single quotes can be used for *single characters* `'C'`, `'c'`
  * White space is used to make your code more readable
    * Indentation: code at the same level in the same block should be indented and indented to the *same level*
    * Vertical space can be used to "chunk" pieces of code together in the same code block
* Style should be *consistent*

### Variables

* C is a *statically typed* language
* Types:
  * `int` - integer, a whole number, negative and positive, zero
  * `double` - IEEE754 formatted floating point number: a decimal number: `3.5, 10.0, -3.1415, 0.0`
  * `char` - a single ASCII character: see <https://www.asciitable.com/>
* Statically typed means that before you can use any variable you **MUST** declare it: you provide the *type* and a legal name
* The *scope* of a variable is the section of code in which it can be "seen" (exists)

* Limitations
  * `int` is a 32-bit signed 2-s complement integer it can represent whole values (integers) in the range:

  $$-2147483648 \leq x \leq 2147483647$$

  $$-2^{31} \leq x \leq 2^{31}-1$$
  * Exceeding the max/min values leads to *overflow/underflow*
  * `double` - a floating point number (IEEE 754 floating point number): it is a decimal number that has about 16-17 *digits* of accuracy

#### Naming Variables

* Names cannot have spaces, should not have other "weird" characters (no unicode, no hyphens, etc)
* Cannot begin with a number and *should not* have any numbers
* Terrible variable names: `x, y, a, b, variable1, variable2, foo, bar, baz`
* Best practice: be *descriptive*
* Ex: `numberOfStudents`, *sometimes* `x` and `a` may be okay variable names
* Avoid ambiguous abbreviations `ssn` *may* be okay, but `eidr` is not
* Use a *consistent* naming convention!
  * Recommendation: `lowerCamelCasing` for variables (modern convention)
  * Old school C: `lower_underscore_casing`
  * `UpperCamelCasing` (in other languages, Java, etc.), later on: enumerations and structures
  * `UPPER_UNDERSCORE_CASING` usually used for constants or macros
* BE CONSISTENT
* variable names should be *nouns*

### Operators


* variables hold values, you need a way to get values into those variables
  * Syntax: To do this, you use the assignment operator: `=`
  * A *single equals sign*!
  * It is not an "equals" as in algebra
  * Instead it means: take the value of the thing on the left hand side (LHS) and place it into the variable on the right hand side (RHS)
  * LHS *has* to be a single variable that you assign
  * RHS can be a:
    * Scalar: a single hard-coded value `a = 5;`
    * An expression: `a = 5 * b;`
* Arithmetic operators: `+` (addition), `-` (subtraction), `*` (multiplication, not $\times$, not $\cdot$), `/` (division, not $\div$ nor $\frac{a}{b}$)
* PEMDAS rules apply
* PEMDAS = (Parentheses Exponents, Multiplication, Division, Addition, Subtraction)
* The following are NOT equivalent: `a * b + c` versus `a * (b + c)`
* Example:
  $$x = \frac{-b\pm \sqrt{b^2-4ac}}{2a}$$

```c
double x1 = ( -b + sqrt( pow(b, 2) - 4*a*c ) ) / (2*a);
double x2 = ( -b - sqrt( pow(b, 2) - 4*a*c ) ) / (2*a);
```

#### Pitfalls

* When you add/subtract/multiply two integers the result is *always* an integer
* In code, division of two integers is ALSO *always* an integer
* When two integers are divided the factional part is thrown away (*truncation*)
* `10/20` should be `0.5` but it ends up as `0.0`
* To solve this you can use *typecasting*

```c
int a = 10;
int b = 20;
double c = a / (double) b;

printf("c = %f\n", c);
```

* Sometimes you do invalid operations:
  * `1 / 0` - NaN = Not a Number
  * `sqrt(-1)` = inf (infinity)
  * `pow(0,0)` = 1 for some reason(s)
* Sometimes when you use the math library you have to help the compiler find out where it is
* Compile using `gcc foo.c -lm`
  * `-lm` means **l**ink in the **m**ath library   

## Input/Output

* `printf` can be used to **print** **f**ormatted data
* There are several *placeholders* that you can use in a format string:
  * `%f` formats a `double`: defaults to 6 decimals of accuracy
  * `%d` (d for digit) prints an `int`
  * `%c` formats a `char` variable
* You can provide as many placeholders in a string as you want but the *order matters*
* You can change the default formatting using *modifiers*
* General form: `%X.Yf`
  * `X` - minimum number of columns to print
  * `Y` - number of decimals of accuracy
* Examples:

```c

    printf("pi = %f\n", M_PI);
    printf("pi = %.2f\n", M_PI);
    printf("pi = %.4f\n", M_PI);
    printf("pi = %.10f\n", M_PI);

    printf("pi = %10.2f\n", M_PI);
    printf("pi = %10.4f\n", M_PI);
    printf("pi = %10.10f\n", M_PI);

    int x = 1234;
    printf("%8d\n", x)
    printf("%08d\n", x);

```

## Standard Input

* Standard input is used with *interactive* programs
* YOu use `scanf` to scan the standard input (keyboard) for user-provided input
* Very limited, very brittle
* WIth `scanf` you use the same placeholders except for `double` values: you use `%lf`instead of `%f`
* WHen using `scanf` always remember the ampersand `&` in front of the variable

```c

    int x;
    printf("please enter an integer:");
    scanf("%d", &x);
    printf("x = %d\n", x);

    double y;
    printf("please enter a number:");
    scanf("%lf", &y);
    printf("y = %f\n", y);
```

### Non-interactive Input

* Interactive input (using `scanf`) makes the program pause ("block") and wait for a *human* user to enter their input
* Most programs especially command line programs are *not* interactive
* From the command line, you can provide input *non-interactively* by using *command line arguments* (CLAs)
* CLAs are provided when you start the program: `./a.out hello 10 3.5`
  * THere are actually 4 arguments: the first argument is always the executable file name `./a.out`
  * `argc` is the number (**c**ount of) **arg**uments
  * `argv` is (an array) of the arguments (v = vector)
  * The first argument (executable file name) is always `argv[0]`
  * The second argument (first proivded by the user) is `argv[1]`
  * `argv[2], argv[3]`, etc.
* Processing CLAs
  * CLAs themselves are *strings* (more on that later), things like `"Hello"`
  * To convert an argument to an integer: `atoi`
  * To convert an argument to a `double`: `atof`
* Example:

```c
int x;
double y;

x = atoi(argv[1]);
y = atof(argv[2]);

printf("x = %d\n", x);
printf("y = %f\n", y);
```

# Exercise

* Write a complete program from scratch to compute the roots of a quadratic polynomial

$$ax^2 + bx + c$$

```text














```
