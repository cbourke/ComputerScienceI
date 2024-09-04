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

```c
/**
 * Author: Chris Bourke
 * Date: 2023/08/23
 *
 * This program converts miles to kilometers
 */
#include <stdlib.h>
#include <stdio.h>

#define KMS_PER_MILE 1.60934

int main(int argc, char **argv) {

  double miles, kms;

  //prompt the user for the input
  printf("Please enter miles: ");

  //read in the input
  scanf("%lf", &miles);

  kms = KMS_PER_MILE * miles;

  printf("%f miles is equal to %f kilometers\n", miles, kms);

  return 0;
}
```

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
  * For now: all the placeholders are the same, *except*...
  * For floats (fractional numbers), you use `%lf`
  * For now: the `&` is just "magic"

### Variables

* C is a *statically typed* language
  * `int` is an integer
  * `double` is a floating point number (fractional value)
  * `char` is a **single** character!
  * Statically typed means that before you can use any variable you **MUST** declare it: you provide the *type* and a legal name
* Limitations
  * `int` - an integer (32 bit signed 2s complement integer)
  it can represent whole values (integers) in the range:

  $$-2147483648 \leq x \leq 2147483647$$

  $$-2^{31} \leq x \leq 2^{31}-1$$

  * Exceeding the max/min values leads to *overflow/underflow*
  * `double` - a floating point number (IEEE 754 floating point number): it is a decimal number that has about 16-17 *digits* of accuracy
  * `char` - a single ASCII text character value

* Best practices for variable naming
  * Generally I recommend you follow a `lowerCamelCasing` convention for variables
  * Alternative: `lower_underscore_casing`
  * Constants: `UPPER_UNDERSCORE_CASING`
  * Examples of variables: `numberOfStudents, miles, kilometers`, etc.
  * Examples of constants (from `math.h` library): `M_PI, M_E`
  * variable names should be *descriptive*
  * variable names should be *nouns*
  * avoid "placeholder" names such as `foo, bar, baz`, or `x, y`
  * avoid abbreviations unless they are absolutely understood: `ssn`, `nuid`

## More Printing: Formatting

* Recall that you can format output using `printf` and placeholders
* You can change the default formatting using *modifiers*
* By default, `%f` prints out 6 decimals of accuracy
* You can control this using `%X.Yf` where `X` is going to be the minimum number of columns to be printed and `Y` is the number of decimal places to output

```c

    printf("pi = %f\n", M_PI);  //ends up rounding but ONLY for printing!!!
    printf("pi = %.7f\n", M_PI);
    printf("pi = %.20f\n", M_PI);
    printf("pi = %.100f\n", M_PI);

    //both placeholders:
    printf("pi = %12.7f\n", M_PI);
    printf("pi = %-12.7f foo!\n", M_PI);

    double bankBalance = 123.45;
    printf("I have $%.2f\n", bankBalance);
```

### Assignment Operator

* variables hold values, you need a way to get values into those variables
  * To do this, you use the assignment operator: `=`
  * It is not an "equals" as in algebra
  * Instead it means: take the value of the thing on the left hand side (LHS) and place it into the variable on the right hand side (RHS)
  * The LHS can ONLY EVER be a single variable in C
* Gotchas:
  * in C an *uninitialized variable has no default value*: it could be anything!
  * *likely* it will be zero
  * but it could be a trash value (random value)
  * it could be a value that was left over in memory
  * it could be `0xDEADBEEF`: an old placeholder value to indicate uninitialized memory

### Other operators

* Arithmetic operators: `+` (addition), `-` (subtraction), `*` (multiplication, not $\times$, not $\cdot$), `/` (division, not $\div$ nor $\frac{a}{b}$)

#### Truncation

* When you add, subtract or multiply two integers the result is *always* an integer
* When you divide two integers, the result is STILL an integer!!!
  * Ex: `20 / 30`: SHOULD be 0.666666
  * C will take the "factional" part and throw it away
  * You end up with just zero
  * This is called truncation!
  * You can solve this problem using a casting operation

  ```c
  int a = 10;
  int b = 20;
  double c = a / (double) b; //c is now 0.5
  ```

#### PEMDAS

* Operators follow a PEMDAS (Parentheses Exponents, Multiplication, Division, Addition, Subtraction) in a *left-to-right* order
  * The following are not equivalent: `a * b + c`
  * is not the same as `a * (b + c)`
* Example:
  $$x = \frac{-b\pm \sqrt{b^2-4ac}}{2a}$$

##### More Math

* Sometimes you may need to compile with the `-lm` flag to Link in the Math library
* Some math expressions are invalid: $\sqrt{-1}$ is *not a number* or `nan`
* `10 / 0` could be `inf` or it could cause a program crash
* Other math functions: `sqrt()`, `pow()` (power), `sin()`, `cos()`, `tan()`, etc.
* RTM = Read the Manual = modern translation: use google

### Non-interactive Input

* Interactive input (using `scanf`) makes the program pause and wait for a *human* user to enter their input
* Most programs especially command line programs are *not* interactive
* From the command line, you can provide input *non-interactively* by using *command line arguments* (CLAs)
* CLAs are provided when you start the program: `./a.out hello 10 3.5`
  * This example has *4* command line arguments
  * The first argument is *always* the exeuctable file name: `./a.out`
  * Inside your program, you have access to all of the arguments through the `argc` and `argv` "arguments"
  * `argc` is a **c**ount of the number of arguments
  * `argv` is an "array" of the arguments (v is for vector)
  * `argv[0]` is the executable file name
  * `argv[1]` is the first user-provided argument
  * `argv[2]` is the second user-provided argument
* All arguments are *strings*; you *may* need to convert them to numbers:
  * `atoi()` converts an argument to an integer
  * `atof()` converts an argument to a float (`double`)

```c
/**
 * Demo Code
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

    double a, b, c;

    if(argc != 4) {
        printf("ERROR: you must provide 3 numbers\n");
        exit(1);
    }

    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);

    // printf("Please enter a (a number): ");
    // scanf("%lf", &a);

    // printf("Please enter b: ");
    // scanf("%lf", &b);

    // printf("Please enter c: ");
    // scanf("%lf", &c);

    double root1 = ( -b + sqrt( pow(b, 2) - 4 * a * c) ) / ( 2 * a );
    double root2 = ( -b - sqrt( pow(b, 2) - 4 * a * c) ) / ( 2 * a );

    printf("the roots of %fx^2 + %fx + %f are %f and %f\n", a, b, c, root1, root2);

    return 0;
}
```

```text













```
