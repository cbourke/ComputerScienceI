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
  * `double` floating point numbers that can represent any fractional value with *about* 16-17 digits of accuracy (formatting similar to scientific notation)
  $$3.1415 \times 10^{12}$$
  * `char` a single character value from the ASCII text table: https://www.asciitable.com/

#### Naming Conventions

* In general, you should use `lowerCamelCasing` for variable names
* Example: `numberOfStudents`
* Rules: you can include any lower or upper case letter, numbers, underscore `_` but may *NOT* begin with a number
* Bad variable names: `myVar`, `myVariable001`, `myVariable002`
* Use descriptive names
* Other conventions: `UpperCamelCasing`, `lower_underscore_casing` (old school), `UPPER_UNDERSCORE_CASING`

### Operators

* Algebraic Operators: `+, -, *, /`
* Assignment Operator: a single equals sign, `=`
  * It takes the value, variable or expression on the *right hand side* and places it into the variable on the *left hand side*
* Is `a + b * c` the same as `(a + b) * c`?
* PEMDAS = Parentheses, Exponents, Multiplication, Division, Addition, Subtraction

```c

    int a = 10, b = 20;
    int c;

    //C does not define a default value for variables
    // often, the compiler will provide zero, but no guarantees!
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    //you can set a variable later
    c = 42;
    //you can also set a variable to be equal to another's value:
    c = a;
    a = 101;
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    double r = (b - sqrt( b*b - 4*a*c)) / (2*a);
    printf("%f\n", r);

    r = log(0);
    printf("%f\n", r);

    a = 10;
    b = 0;
    //division by zero is undefined; on this system, kills the program
    //r = a / b;
    printf("%f\n", r);


    a = 10;
    b = 20;
    //when dealing with division and integers, truncation loses the
    //  fractional part, result is zero
    r = a / b;
    printf("%f\n", r);

    //to fix it, you need to *type cast* at least one of the variables:
    r = a / (double) b;
    printf("%f\n", r);
```

## Other Operators

* You can use the division-remainder operator (modulus): `%`
  * Ex: `10 % 3` gives a remainder of 1
  * `10 % 2` results in 0
  * `11 % 2` results in 1
  * `10 % 3` results in 1
  * `11 % 3` results in 2
  * `12 % 3` results in 0

* Other math stuff
  * The math library `math.h` has several constants:
 `M_PI`, `M_E`
  * `sin()`, `cos()`, `tan()`, `sqrt()`, `pow()`, `log()` (base $e$ in other words it is $\ln(x)$)
  * Remember: you may need to use the `-lm` flag to compile using the math library (link into the math library)
  * What else?
  * `abs()` is for `int`s, `fabs()` is for `double`s

## Formatting

* Recall that you can print output in a *formatted* manner using `printf`
* Three placeholders: `%d, %f, %c` for `int`, `double`, `char` respectively
* You can also add *modifiers* to print more or fewer significant figures and to align output values

```c

    double x = 3.14159;
    printf("%f\n", x);  //defaults to 6 decimals of precision
    printf("%.10f\n", x); //10 decimals of precision
    printf("%.2f\n", x); //2 decimals of precision
    printf("%.3f\n", x); //3 decimals of precision, may end up rounding, but only in the formatting!
    printf("%.10f\n", x); //10 decimals of precision

    printf("\n\n\n");
    double balance = 123.265;
    printf("$%f\n", balance);
    double roundedBalance = round(balance * 100) / 100;
    printf("$%.2f\n", roundedBalance);
    double bigBalance = 120739415.45;
    printf("$%.2f\n", bigBalance);

    //you can add a second modifier to specify the minimum number of columns to
    // print:
    printf("$%15.2f\n", roundedBalance);
    printf("$%15.2f\n", bigBalance);
```

## Non-interactive input

* You can provide command line arguments (CLAs) instead of using interactive input
* The arguments are passed on the command line as : `./a.out a b c`
* The program has access to them through the  `argv` (argument vector)
  * The first one is at `argv[0]` and is *always* the executable file name (`a.out`)
  * The second (and first user provided) is at `argv[1]`
  * The third `argv[2]`
  * The fourth is `argv[3]`
  * `argc` tells you how many arguments were provided (argument *c*ount)


```text






```
