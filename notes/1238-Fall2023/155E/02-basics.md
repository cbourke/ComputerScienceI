# Computer Science I
## CSCE 155E Fall 2023
### C Basics

An overview of basics of C including variables, input and output.

## Programming, Compile, Run a Program

* A source file is a *plain text* file containing computer code in a particular language
* A source file is then compiled into an *executable program* (in binary)

  $$source \rightarrow preprocessor \rightarrow assembly \rightarrow machine\,\, code$$

* Demonstration

## Program Anatomy

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
  * Ignored by the compiler, no effect on the end program
  * Single line comments: `//`: everything after this on the same line is ignored
  * Multiline comments begin with `/*` and end with `*/`
  * Doc-style comments: these are multiline comments but formatted with a vertical line of stars
  * Comments, especially documentation is intended to tell the user (other programmers and the future you) the *why* and the *how* of the code, NOT the *what*
  * Code should be *self-documenting*: code should tell you the what

### Preprocessor Directives

* Commands or directives or "macros" that are executed  before the compiler compiles your code
  * `#include` brings in external or standard libraries so that you don't have to code from scratch
  * `#define` defines an "alias" that can be used in place of magic numbers
    * You can replace magic numbers with human-readable text
    * Only one change is necessary instead of multiple changes

### Main Function

* The `main` function is always the starting point for any executable program
  * For now: `argc`, `argv` are "magic" (ignore for now)
  * Programs are executed in order, top to bottom, left-to-right, just like we read (in English)

### Other Observations/Punctuation

* Semicolons act like sentences: they end each executable statement
* Curly brackets denote *code blocks* (kinda like paragraphs)
* Commas delimit lists of items or things
* In general whitespace does not matter to a computer, but it *DOES* to humans
  * Indentation gives an indication of code blocks
  * Other whitespace makes code more readable and therefore easier to maintain

# Output

* Output in C is done using `printf` (the `f` stands for "formatted")
  * Formatted output can use *placeholders*: `%d, %f, %c, %s`
  * `%d` is for "integers" (`int`), whole numbers including zero and negative: $\ldots, -2, -1, 0, 1, 2, \ldots$
  * `%f` is for floating point numbers, fractional numbers, 3.14159, 10.0, 2.5
  * `%c` is for **single** characters
* `scanf` is used for input
  * FOr now: all the placeholders are the same, *except*...
  * For floats (fractional numbers), you use `%lf`
  * For now: the `&` is just "magic"

### Variables

* C is a *statically typed* language
  * `int` is an integer
  * `double` is a floating point number (fractional value)
  * `char` is a **single** character!
  * Statically typed means that before you can use any variable you **MUST** delcare it: you provide the *type* and a legal name


```text













```
