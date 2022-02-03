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
* Coding follows PEMDAS rules = Parentheses, Exponents, Multiplication, Division, Addition, Subtraction

$$a + b \times c = (a + b) \times c$$

```c
/**
 * Author: Chris Bourke
 * Date: 2022/01/26
 *
 * This program converts kilograms to pounds
 */
#include <stdlib.h>
#include <stdio.h>

#define POUNDS_PER_KILOGRAM 2.204623

int main(int argc, char **argv) {

    //note that this kind of line-by-line
    //documentation is not best practice
    //it is just for demonstration purposes
    //prompt the user for some input
    printf("Please enter a number of kilograms: ");

    //declare your variables...
    int kilograms, pounds;

    //read the input from the user
    scanf("%d", &kilograms);

    //compute the conversion
    pounds = kilograms * POUNDS_PER_KILOGRAM;

    //output the result
    printf("That's %d pounds!\n", pounds);

    return 0;

}
```

## More

```c

    //C defines no default value, anything
    // could be in an "uninitialized" variable
    int x;

    //set x to the value 10:
    x = 10;

    int a = 5, b = 3, c = 10;
    x = (a + b) * c;
    //not the same as:
    x = a + b * c;

    //set the value of x to whatever is stored in c:
    x = c;

    // requires the math library:
    x = (-b - sqrt( b*b - 4*a*c) ) / (2*a);
    printf("x = %d\n", x);

    a = 10;
    b = 20;

    //the floating point part gets cut off and thrown away
    // this is known as "truncation"
    double y = a / b;
    //to get this to work, you need to "type cast" at least
    // one of the operands
    y = (double) a / b;
    printf("y = %f\n", y);
    //a and b are still integers at this point!

    //other pitfalls:
    //overflow and underflow:
    x = -2147483648;
    printf("x = %d\n", x);
    x = x - 1;
    printf("x = %d\n", x);

```

## Other Operators

* You can use the division-remainder operator: `%`
  * Ex: `10 % 3` results in 1 (ie the remainder)
  * `10 % 2` results in 0
  * `10 % 5` results in 0
  * `11 % 2` results in 1
  * `11 % 3` results in 2
  * `11 % 11` results in 0
  * `11 % 20` results in 11

## More Math Stuff

* The math library `math.h` has several constants:
 `M_PI`, `M_E`
* `sin(), cos(), tan(), sqrt(), pow()`
* `log()` (natural, base-$e$ log), `exp()`
* Remember that you may need to compile with the `-lm` flag at the end in order to *link* in the *math* library
* What else is there?
* RTM = Read The Manual!

## Formatting Demo

```c

    //by default, all floating points numbers are
    // printed with 6 decimals of accuracy
    // AND are rounded!
    printf("%f\n", M_PI);
    //specifies that 20 decimals of "accuracy" be printed
    printf("%.20f\n", M_PI);
    //if you want less:
    printf("%.2f\n", M_PI);
    //you can also "pad" out leading space:
    //prints at least 10 columns, 2 decimals of accuracy
    printf("%10.2f\n", M_PI);


    //you can use it for integers:
    int nuid = 1234;
    printf("nuid = %8d\n", nuid);
    //you can pad out with zeros instead:
    printf("nuid = %08d\n", nuid);

    //rounding manually:
    double x = 10.255;
    int rounded = round(x);
    printf("rounded = %d\n", rounded);
    //trick: round to the nearest 100th:
    //want 10.255 => 10.26
    double y = round(x * 100) / 100;
    printf("y = %f\n", y);

```

## Interactive Input

* Some programs expect a human user:
* Using `scanf` we *prompted* the user for input
* Most programs are not "interactive"
* Programs can be written to take input *non-interactively* through the use of Command Line Arguments (CLAs)
* CLAs are provided to a program when you invoke that program from the command line: `./a.out a b c 10 20 30`
* The above example has 7 command line arguments
  * `argv[0]` is the first and is always the executable file name
  * `argv[1]` is the first user provided argument (in this case, `a`)
  * `argv[2]` is `b`, etc
  * `argv[6]` is `30`
* All of these arguments are strings, not necessarily numbers
* To convert an argument to a string you can use:
  * `atoi` converts an *alphanumeric* string to an `int`
  * `atof` converts an *alphanumeric* string to a `double`
* Also: `argc` tells you how many arguments were provided

Non-interactive version:

```c
/**
 * Author: Chris Bourke
 * Date: 2022/01/26
 *
 * This program converts kilograms to pounds
 */
#include <stdlib.h>
#include <stdio.h>

#define POUNDS_PER_KILOGRAM 2.204623

//argc = argument count
//argv = argument vector
int main(int argc, char **argv) {

    if(argc != 2) {
        printf("ERROR: usage: provide a single numerical input!\n");
        exit(1);
    }

    double kilograms, pounds;

    //converting the first *user provided* argument to a double:
    kilograms = atof(argv[1]);

    if(kilograms < 0) {
        printf("ERROR: negative weight is not possible!\n");
        exit(1);

    }

    pounds=kilograms* POUNDS_PER_KILOGRAM;
    printf("That's %f pounds!\n", pounds);
    return 0;

}
```

```text



```
