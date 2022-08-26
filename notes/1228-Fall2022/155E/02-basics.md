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
    * $\times$, $\div$

```text






```
