# Computer Science I
## ECEN 1940 - Spring 2022
### C Basics

Write a program to convert kilograms to lbs
  * 1kg = 2.204623lbs
  * Need a basic program framework
  * Basic I/O:
  * Prompt the user for some input
  * Read the input
  * Store the input
  * Convert the values (math)
  * Output the results


## Basics

### Comments

* Comments are human-readable messages embedded in code
  * They are ignored by the compiler
  * You can have single line comments: `//`: everything after on the same line is ignored
  * You have multiline comments:
  ```c
  /* you can write whatever you want
     everything in between the slash-star
     and the closing star-slash is ignored
   */
  ```
  * Doc-style comments: just a regular multiline comment with an extra star and vertical formatting starts: you use it for each major program or major function you write
  * Comments, especially documentation is intended to tell the user (other programmers and YOU) the *why* and the *how* not the "what"
  * Code should be *self-documenting*: code should tell you the what

### Preprocessor Directives

* Commands or directives or "macros" that are executed before the compiler compiles your code
  * `#include` brings in external or standard libraries (it actually includes the header file: it does a copy-paste)
  * `#define` defines an "alias" that can be used to replace "magic numbers"
    * You can use plain aliases (English) as placeholders for "magic numbers"
    * Only change affects all instances!

### Main Function

* The `main` function is always the starting point for any executable program
  * For now: `argc, argv` are "magic" (they are command line arguments)
  * Every executable statement in C is ended with semicolon: `;`
  * Blocks of code are denoted using opening and closing curly brackets `{...}`
  * In general whitespace is ignored by the language but is essential for good style:
    * You should indent each code block
    * You should have good vertical and horizontal space

### Input/Output

* Output is done by a function called `printf`
* Input is done by a function called `scanf`
* Both of these are "standard" output and input
* Standard output: console
* Standard input: keyboard
* Placeholders are used for different variables

### Variables

* C is a *statically typed* language
  * Basically you must *declare* a variable and its type before you can use it
  * To delcare a variable you provide a keyword of its type and then its name or "identifier"
* Types:
  * `int` integers (whole numbers) but with a restriction: you can only represent integers in the range
  $$-2147483648 \leq x \leq 2147483647$$
  * `double` floating point numbers that can represent any fractional value with *about* 16-17 digits of accuracy
  * `char` a single character value from the ASCII text table
  * Others: look them up
* Names:
  * generally you should use the `lowerCamelCasing` convention
  * You cannot use whitespace in variable names
  * You can use digits `0-9` but shouldn't and cannot *begin* a variable name with a digit
  * YOu can use underscores if you like, but shouldn't
  * If a single word, use all lower case
  * If multiple words: first one is all lower case and the first letter of each subsequent word is capitalized
  * For `#define` macros or constants use `UPPER_UNDERSCORE_CASING`
  * In general name variables for what they stand for not mysterious names
  * Bad variable names: `x`, `foo`, `variable`, `variable1`, `variable2`
  * Good: `numberOfStudents`, `pounds`, `kilograms`
* Placeholders in `printf` and `scanf`
  * To read or print an `int` use `%d`
  * To read a `double` use `%lf`
  * To print a `double` use `%f`
  * To read or print a `char` use `%c`

### Operators

* Algebraic Operators:
  * Addition: `+`
  * Subtraction: `-`
  * Multiplication: `*`
  * Division: `/`
* Assignment operator
  * It is a single equals sign: `=`
  * It is *NOT* the algebraic left hand side is equal to the right hand side
  * It takes the value, expression or other variable from the *right hand side* and places it into the variable on the *left hand side*
* Coding follows PEMDAS rules = Parentheses, Exponents, Multilication, Division, Addition, Subtraction

$$a + b \times c = (a + b) \times c$$

```text



```
