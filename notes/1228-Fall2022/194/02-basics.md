# Computer Science I
## ECEN 194 Fall 2022
### C Basics


## Programming, Compiling, Running

  * Source files are *plain text* files containing computer code in a highlevel programming language
  * Source files have to be compiled into an *executable program* (binary code)
    * *source → assembly → machine code*

Consider a basic *input/output* program to convert miles
to kilometers...
  * Basic program framework
  * Prompt the user for some input
  * Read the input
  * Store the input
  * Convert the values (math)
  * Output the results

## Basics

### Comments

* Comments are human-readable messages embedded in code
  * They are ignored by the compiler
  * You can have multiline comments using `/*` and closing `*/`
  * You can use doc-style comments for header documentation (author) or for function documentation (later)
  * You can have single line comments: `//` everything after is ignored!
  * Comments, espeically documentation is intended to tell the user (other programmers and you) the *why* and the *how* NOT the *what*

### Preprocessor Directives

* Commands or directives or "macros" that are executed before the compiler compiles your code
  * `#include` brings in external libraries such as `<math.h>`
  * `#define` defines an "alias" that can be used to replace "magic numbers"

### Main Function

* The `main` function is always the starting point of any executable program
  * for now: `argc, argv` are magic (ignore them for now)
* Other observations:
  * semicolons end every **executable** line
  * Blocks of code are denoted using opening and closing curly brackets: `{ ... }`
  * In general whitespace is ignored by the language but is essential for good style:
    * You should indent each code block
    * You should have good vertical and horizontal space

### Variables

* Variables are things that allow you to store data
  * `double` - a floating point number, a fraction value: 10.5, 3.14, -10.2, 0.0, 10.0
  * `int` - a whole number (with limitations): -5, 0, 100, but not 10.5
  * `char` - a single ASCII text value

### Input/Output

* Output is done using `printf` (print formatted)
* Input is done using `scanf`
  * For now: the variable you want to read the value into needs an `&` in front of it (magic)
  * The type of variable is denoted using a *placeholder*
    * `double`: `%lf` (or `%f` when used with `printf`)
    * `int`: `%d`
    * `char`: `%c`
* Standard output: console/terminal
* Standard input: keyboard

### Variables

* C is a *statically typed* language
  * Basically you have to *declare* a variable and its type before you can use it
  * To declare a variable you provide its type and then its name
  * Multiple variables of the same type can be declared on the same line delimited by commas
* Types:
  * `int` holds integers (whole numbers, negative, zero, etc.) but with a restriction:
  $$-2147483648 \leq x \leq 2147483647$$
  * `double` floating point numbers that can represent any fractional value with *about* 16-17 digits of accuracy
  $$3.1415 \times 10^{12}$$
  * `char` a single character value from the ASCII text table: https://www.asciitable.com/




```text






```
