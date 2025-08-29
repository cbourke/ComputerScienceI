# Computer Science I
## CSCE 155E Fall 2025
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
  * You can include external libraries using `#include` and provide the name of the library (generally they end with a `.h` - a *header* file)
  * Ex: `stdlib.h`, `stdio.h` (standard input/output)
  * Ex: `math.h`: `sin(), cos(), sqrt(), log()`
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
  * Parentheses define function inputs (arguments, parameters)
  * Opening/closing curly brackets `{...}` denote *code blocks* similar to "paragraphs" in English
  * Commas denote items in a list
  * Semicolons end each executable statement (like a period)
  * Square brackets: `[]` denote arrays (more on that later)
  * Double quotes denote *strings*: sequences of characters
  * Single quotes can be used for *single characters* `'C'`, `'c'`
  * White space is used to make your code more readable
    * Indentation: code at the same level in the same block should be indented and indented to the *same level*
    * Vertical space can be used to "chunk" pieces of code together in the same code block
* Style should be *consistent*

### Variables

* C is a *statically typed* language
* It simply means that you have to declare a variable before you can use it:
  * You have to specify the *type* (`int, double, char`)
  * You have to specify the *name* (identifier)
* Types:
  * `int` - integer, a whole number, negative and positive, zero
  * `int` is a 32-bit signed 2-s complement integer it can represent whole values (integers) in the range:
  $$-2147483648 \leq x \leq 2147483647$$

  $$-2^{31} \leq x \leq 2^{31}-1$$
  * `double` - IEEE754 formatted floating point number: a decimal number: `3.5, 10.0, -3.1415, 0.0`
  * a "double" because it is 64 bits
  * Limitations: you can represent any fractional number but only with at most 17 digits of accuracy
  * `char` - a single ASCII character: see <https://www.asciitable.com/>

#### Naming Variables

* Names cannot have spaces, should not have other "weird" characters (no unicode, no hyphens, etc)
* Cannot begin with a number and *should not* have any numbers
* Terrible variable names: `x, y, a, b, variable1, variable2, foo, bar, baz`
* Best practice: be *descriptive*
* Ex: `numberOfStudents`, *sometimes* `x` and `a` may be okay variable names
* Is `kms` a "good" variable name?  Its probably "good enough"
* Avoid ambiguous abbreviations: `ssn` (likely "good enough"); `eidr` (probably not unless there is context)
* Use a *consistent* naming convention!
  * Recommendation: `lowerCamelCasing` for all variables (modern convention)
  * Old School C: `lower_underscore_casing`
  * `UpperCamelCasing` (in other languages, Java, etc.), later on: enumerations and structures
  * `UPPER_UNDERSCORE_CASING`: `M_PI` (this is used for constants or macros)
* BE CONSISTENT
* variable names should be *nouns*

### Operators

* Arithmetic operators: `+` (addition), `-` (subtraction), `*` (multiplication, not $\times$, not $\cdot$ nor $\div$), `/` (division)
* variables hold values, you need a way to get values into those variables
  * Syntax: To do this, you use the assignment operator: `=`
  * A *single equals sign*! This is not algebra!
  * Instead it means: take the value of the thing on the right hand side (RHS) and place it into the variable on the left hand side (LHS)
  * The RHS can be a variable, a value, an expression, etc.

```c
int a = 10;
...
a = 120;

int b = a;
int c = b + 10;

```
* PEMDAS rules apply
* PEMDAS = (Parentheses Exponents, Multiplication, Division, Addition, Subtraction)
* The following are *not* equivalent: `a * b + c` is not the same as `a * (b + c)`
* Example:
  $$x = \frac{-b\pm \sqrt{b^2-4ac}}{2a}$$

```c
double root1 = (-b + sqrt( b * b - 4 * a * c)) / (2 * a);
double root2 = (-b - sqrt( b * b - 4 * a * c)) / (2 * a);
```

#### Pitfalls

* When you add/subtract/multiply two integers the result is *always* an integer
* Also: when you divide an integer by an integer, the result is *still an integer*
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
  * `1 / 0`: Maybe `infty` or `NaN` (Not a number!)
  * `sqrt(-1)` (`NaN`)
  * `pow(0,0)` equals 1 for some reason in C
  * `1.0 / 3.0 = 0.3333333333333??2 or 4`
* When using the math library you may need to provide `gcc` with some additional flags:
  * `gcc foo.c -lm`
  * `l` means link in and `m` means the math library

## Input/Output

* `printf` can be used to **print** a **f**ormatted output
* There are several *placeholders* that you can use in a format string:
  * `%f` formats a `double`: defaults to 6 decimals of accuracy (f is for floating point numbers)
  * `%d` formats an `int`
  * `%c` formats a single `char`
* You can provide as many placeholders in a string as you want but the *order matters*

```c
int a = 2;
double b = 3.5;
char initial = 'C';

printf("Hello \t a = %d, b = %f, my initial is %c\n", a, b, initial);
```

* You can also use *modifiers* to specify more digits of accuracy
* You can change the default formatting using *modifiers*
* General form: `%X.Yf`
  * `X` - minimum number of columns to print
  * `Y` - number of decimals of accuracy

```c

    printf("pi = %f\n", M_PI);
    printf("pi = %.7f\n", M_PI);
    printf("pi = %.16f\n", M_PI);
    printf("pi = %.25f\n", M_PI);

    printf("pi = %20.7f\n", M_PI);
    printf("pi = %15.3f\n", M_PI);

    int x = 1234567;
    printf("x = %08d\n", x);
```

## Standard Input

* Standard input is used with *interactive* programs
* You use `scanf` to scan the standard input (keyboard) for user-provided input
* Very limited, very brittle
* WIth `scanf` you use the same placeholders except for `double` values: you use `%lf`instead of `%f`
* WHen using `scanf` always remember the ampersand `&` in front of the variable (magic for now)


```text














```
