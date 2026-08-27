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
    * Beware of overflow!

```text














```
