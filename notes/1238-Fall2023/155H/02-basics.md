# Computer Science I
## CSCE 155H Fall 2023
### C & Java Basics

An overview of basics of C and Java including variables, input and output.

## Programming, Compile, Run a Program

* A source file is a *plain text* file containing computer code in a particular language
* A source file is then compiled into an *executable program* (in binary)

  $$source \rightarrow assembly \rightarrow machine\,\, code$$

### Java

  * Java is not a purely compiled language
  * You compile Java code into Java Bytecode: a "machine like" language that is runnable on the Java Virtual Machine JVM
  * Bytecode is then interpreted by the JVM


## Program Anatomy

Consider a basic *input/output* program to convert miles
to kilometers...
  * Basic program framework
  * Prompt the user for some input
  * Read the input
  * Store the input
  * Convert the values (math)
  * Output the results

Observations:

* Comments are human-readable messages embedded in code
  * Purpose: communicate to other humans what the purpose or intent of the code was
  * Comments/documentation tell the *what* and the *why*, not necessarily the *how*
  * Code should be *self documenting*: it should be written clearly enough that an experienced user could understand the *how*
  * Single line comments begin with `//`, multiline: `/*` and end with `*/`
  * Doc-style comments: begin with `/**` and have a vertical line of stars, get in the habit of using them!

* Preprocessor directives begin with a hash `#`
    * You can include external libraries: `#include` and providing the "name" of the library (`.h` is for the "header" of that library)
    * Example: `#include <math.h>`; `sin(), cos(), sqrt()`
    * `#define` is a macro: it essentially is a cut-and-replace operation by the preprocessor (something that runs before the compiler)
    * Macros also allow you to represent a single value in a single place (constants)
    * Macros make your code more readable and maintainable (dont' use Magic Numbers)
    * every program has to have some *beginning* for both C and Java that's the `main` function or method
    * Linear control flow: a program executes top to bottom, left to right
    * Other syntax and punctuation:
      * semicolons end executable statements
      * curly brackets (opening and closing) denote *code blocks*
      * Parentheses denote function calls or "groupings" of things
      * commas delimit lists of similar things
      * double quotes denote *strings* which are sequences of characters
      * whitespace helps to make your code more readable: in general statements at the same "level" should have the same indentation
      * whitespace helps to make your code more readable: in general statements at the same "level" should have the same indentation
      * Style above all should be *consistent*
      * Unless you have a Very Good Reason
      * Example: blocks of code should all be indented at the same level
      * Reserved words: `int`, `double`, `return`

## Variables

* Both C and Java are *statically typed* langauges
  * Before you can use any variable you need to *declare it*
  * You need to define its name (identifier) and its *type*: `int, double, char`
  * Where ever you declare a variable, is its *scope*: the area of the code that the variable can be "seen" and is therefore valid
* Basic Types:
  * `int` is a 32-bit 2-s complement integer
  * you can represent 0, negative and positive numbers in the range: -2,147,483,648 to 2,147,483,647
  $$-2^{31} \ldots 2^{31}-1$$
  * `double` is a 64-bit IEEE 754 floating point number
  * Limitation: you can represent any number, very large magnitude, but with only 16-17 digits of accuracy
  * `char`: is a single character; in C: it is an ASCII text value, in Java: it is a full Unicode value

## Input/Output (I/O)

### C

* Output in C is done with `printf` (f = formatted)
* You can provide any "formatted" string and it will print to the standard output
* Input in C is done with `scanf` using the *standard input* (your keyboard)
* For both language: you can use *placeholders*: they indicate the type of variable to be formatted
  * `%d` is for integers (`int`)
  * `%f` is for floating point numbers (`double`)
  * `%c` is for `char`
* For `scanf` in C, you need to use `%lf` instead of `%f`!!!
* For now: remember that `scanf` needs an ampersand `&` in front of the variable you want to read the value into
* By default: all `double`s are printed out to 6 decimals of accuracy
* You can specify *modifiers* to placeholders to change their default formatting
  * Format: `%X.Yf` where X and Y are numbers
  * `X`: minimum number of "columns" to print
  * `Y`: exact number of decimal places to print

```c
    //pi is defined in math.h: M_PI
    printf("pi is %f\n", M_PI);  //printf rounds BUT ONLY FOR PRINTING
    printf("pi is %.10f\n", M_PI);
    printf("pi is %.20f\n", M_PI); //you only have 17 digits of accuracy
    printf("pi is %.100f\n", M_PI);

    printf("pi is %20.10f\n", M_PI);
    printf("pi is %-20.10f yay!\n", M_PI);

    int nuid = 123456;
    printf("my nuid is %d\n", nuid);
    printf("my nuid is %8d\n", nuid);
    printf("my nuid is %08d\n", nuid);
```

```java
System.out.println("Hello World!");
int x = 42;
double y = 10.125;
System.out.println("Hello WOrld x is " + x + " and y is " + y);
int nuid = 123456;

System.out.print(x + "\n");

  //pi is defined in math.h: Math.PI
  System.out.printf("pi is %f\n", Math.PI);  //printf rounds BUT ONLY FOR PRINTING
  System.out.printf("pi is %.10f\n", Math.PI);
  System.out.printf("pi is %.20f\n", Math.PI); //you only have 17 digits of accuracy
  System.out.printf("pi is %.100f\n", Math.PI);
  System.out.printf("pi is %20.10f\n", Math.PI);
  System.out.printf("pi is %-20.10f yay!\n", Math.PI);
  System.out.printf("my nuid is %d\n", nuid);
  System.out.printf("my nuid is %8d\n", nuid);
  System.out.printf("my nuid is %08d\n", nuid);
```

## Best Practices

* Follow a consistent naming convention
* Suggestion: `lowerCamelCasing` for all variables (in Java: standard, C: more modern)
* Alternative: `UpperCamelCasing` (usually for class names in Java)
* Alternative: `lower_underscore_casing`
* Constants: usually `UPPER_UNDERSCORE_CASING`
* Use descriptive variable names: `numberOfStudents, miles, kilometers`
* Avoid: abbreviations `kms`, `ssn`, `nuid`
* definitely do not use `var1, variable2, var3`, `x, y, z, a, b, c`, `foo, bar, baz`

## Operators

* The assignment operator or the single equals sign assigns values to variables
* Arithmetic operators: `+, -, *, /` (addition, subtraction, multiplication, division)
* Follows the PEMDAS rules: left to right
  * `a * b + c` is not the same as `a * (b + c)`
* Example:
  $$x = \frac{-b \pm \sqrt{b^2-4ac}}{2a}$$
* Invalid opeartions: $\sqrt{-1} = i$ but in code, it is Not a Number, nan
* Invalid: `1 / 0` (`inf`, `-inf`)
* Remainder: you can get the remainder after integer division using `%` (read it as: mod or modulo)
  * `10 % 3` results in 1 (remainder)
  * `10 % 2` results in 0
  * `10 % 4` results in 2
* Trick: how can you tell if a number is even or odd?  Take the mod-2: `a % 2`

### Default Values

* In Java, if you do not assign a value then the variable cannot be used (compiler error)
* In C, there is no default value for uninitialized variables, thus it *could* have garbage values: `0xDEADBEEF`

### Pitfall: Truncation

* an integer and a floating number are not the same thing
* When you operate on two integers, the result *must* be an integer: addition, subtraction, multiplication: no problem
* Division presents a problem: the result must be an integer
* When two integers are divided, the fractional part (floating point part) is cut off and thrown away
* This is *NOT* rounding or flooring
* Solution: use temporary *type casting*: you temporarily treat at least one of the operands as a `double` variable

```c
int a = 10;
int b = 20;
double c = (double) a / b;

printf("%f\n", c);

```

# Non-interactive Input

* Interactive input (using `scanf`) makes the program pause and wait for the user to enter in their input
* Most programs especially command line programs are *not* interactive
* From the command line, you can provide input *non-interactively* by using *command line arguments*
* CLAs are provided when you start the program: `./a.out hello 10 3.5`
  * `argc` is the *count* (number of arguments)
  * `argv` is a "vector" (an array) of arguments
  *  `argv[0]` is always the executable file name (`a.out`)
  * `argv[1]` is the "first" user supplied argument
  * `argv[2]`, `argv[3]`, etc.
  * These are all *STRINGS*
* Conversion functions:
  * To convert from a string to an integer: `atoi()`
  * To convert from a string to a double: `atof()`

```c
//C version:

    double a, b, c;

    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);

    // printf("Please enter a: ");
    // scanf("%lf", &a);

    // printf("Please enter b: ");
    // scanf("%lf", &b);

    // printf("Please enter c: ");
    // scanf("%lf", &c);

    double root1 = ( -b + sqrt(b*b - 4*a*c) ) / (2*a);
    double root2 = ( -b - sqrt(b*b - 4*a*c) ) / (2*a);

    printf("roots are %f and %f\n", root1, root2);
```

Java:

```java

	    double a, b, c;

	    a = Double.parseDouble(args[0]);
	    b = Double.parseDouble(args[1]);
	    c = Double.parseDouble(args[2]);
	    //or : Integer.parseInt()

	    double root1 = ( -b + Math.sqrt(b*b - 4*a*c) ) / (2*a);
	    double root2 = ( -b - Math.sqrt(b*b - 4*a*c) ) / (2*a);

	    System.out.printf("roots are %f and %f\n", root1, root2);
```

```text












```
