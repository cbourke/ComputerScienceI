# Computer Science I
## CSCE 1553 Fall 2024
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
    * INdentation: code at the same level in the same block should be indented and indented to the *same level*
    * Vertical space can be used to "chunk" pieces of code together in the same code block
* Style should be *consistent*

### Variables

* C is a *statically typed* language
* `int` - integer, a whole number, negative and positive, zero
* `double` - IEEE754 formatted floating point number: a decimal number: `3.5, 10.0, -3.1415, 0.0`
* `char` - a single ASCII character: 


```text









```
