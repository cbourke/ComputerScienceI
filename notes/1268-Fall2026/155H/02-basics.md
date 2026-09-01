# Computer Science I
## CSCE 155H Fall 2026
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

### Comments

* Comments are human-readable messages embedded in code
* Purpose: communicate to other humans what the purpose or intent of the code was
* Comments/documentation tell the *what* and the *why*, not necessarily the *how*
* DRY = Don't Repeat Yourself!
* For now: all of your programs should have an author header
* code should be *self-documenting*: it should be written clearly enough that an experienced user could understand the *how*
* Cruft: useless or verbose code
* Syntax in both languages:
  * Single line comments use `//`: only ignores everything to the end of the line
  * Multiline comments begin with `/*` and end with `*/`
  * Doc-style comments: begin with `/**` and have a vertical line of stars, get in the habit of using them!

### Preprocessor

* C has a preprocesor that processes your code before it compiles it...
* Preprocessor directives begin with a hash `#`
  * You can include external libraries using `#include` and providing the name of the library (generally they end with a `.h` - a *header* file)
  * Example: `#include <math.h>`; `sin(), cos(), sqrt()`
  * "Constants": `M_PI, M_E`
* `#define` is a macro: it essentially is a cut-and-replace operation by the preprocessor (something that runs before the compiler)
* Macros also allow you to represent a single value in a single place (constants)
* Macros make your code more readable and maintainable (don't use Magic Numbers)

### The Main

* Every program has to have a starting point
* Generally programs start in the `main` function or method
* Linear control flow: a program executes top to bottom, left to right

### Other Stuff

* Punctuation
  * Semicolons end executable statements (like sentences and periods)
  * Curly brackets define *code blocks* (akin to paragraphs)
  * Commas delimit lists of things
  * Quotation marks: `"..."` define strings (sequences of single characters)
  * Parentheses denote inputs to functions (just like math!)
  * Square brackets (later) are used in arrays: `[]`
  * Single quotes (both C and Java): are used for single *characters*: `'C'`
  * Whitespace makes code more readable: vertical whitespace separates lines, horizontal whitespaces indents *blocks* of code
  * whitespace helps to make your code more readable: in general statements at the same "level" should have the same indentation
    * Style above all should be *consistent*
    * Unless you have a Very Good Reason (VGR)

## Variables

* Both C and Java are *statically typed* langauges
  * Before you can use a variable you need to *declare* it
  * To declare: you define its *type* and its *name* (or identifier)
  * Where ever you declare a variable, is its *scope*: the area of the code that the variable can be "seen" and is therefore valid
* Basic Types:
  * `int` short for integer
    * 32-bit signed 2-s complement integer
    * you can represent 0, negative and positive integers in the range: -2,147,483,648 to 2,147,483,647
    $$-2^{31} \cdots 2^{31}-1$$
  * `double` is a 64-bit IEEE 754 floating point number
    * You can represent decimal numbers with about 17 digits of accuracy
  * `char` is a single character; in C: it is an ASCII text value, in Java: it is a full Unicode value

### Best Practices

* Follow a consistent naming convention
* Recommendation: `lowerCamelCasing` for all variables (both langauges)
* Others:
  * `lower_underscore_casing` (old school C, python)
  * `UPPER_UNDERSCORE_CASING` (generally for constants)
  * `UpperCamelCasing` (Java class names, C structures)
* Be *descriptive*:
  * Bad variable names: `foo`, `bar`, `baz`, `a, b, c, x, y, z` (UNLESS they represent math stuff), `variable1, variable2`
  * Good variable: `numberOfStudents`, `miles`, `kilometers`
  * Generally avoid abbreviations unless the context means that the variable name is well-understood
* Whitespace: use consistent whitespacing
  * use `astyle` to fix C programs
  * Eclipse: `shift + command + f` (mac)
  * Windows: `shift + alt + f`

## Operators

* Arithmetic operators: `+, -, *, /` (addition, subtraction, multiplication, division)
* PEMDAS = Parentheses, Exponent, Multiplication Division, Addition Subtraction
* Example:
  $$x = \frac{-b \pm \sqrt{b^2-4ac}}{2a}$$
* Math preview: `pow(x, y)`: $x^y$, Java: `Math.pow(x,y)`
* Translation:

```c
root1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
root2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
```

* INvalid operation: $\sqrt{-1} = i$, $\frac{a}{0}$
* In C/Java: `NaN` (not a number), `inf`, `-inf`
* Special operator: `%` (modulus)
  * `10 % 3` results in 1
  * `10 % 2` results in 0
  * `9 % 2` results in 1

* Division issue (both langauges)

```c
int x = 10;
int y = 20;
int z = x / y;
```

* When you divide an `int` by an `int`, the result *must* be an `int`
  * The fractional part is thrown away (**truncation**)
  * The fix: use explicit *type casting*

```c

int x = 10;
int y = 20;
double z = x / (double) y;
```

### Default Values

```c
int a;
```

* C standard: there are NO default values, it could be anything; likely zero, a random number, `0xDEADBEEF`
* It is best practice to *initialize* your variables

```c
int a = 0;
```

* In Java: uninitialized values are *not allowed*
* In Java: class values may have a `null` default value in the context of a class (but NOT local variables)

## Input/Output (I/O)

### C

* Output in C is done with `printf` (f = formatted)
* You can provide "formatting" placeholders and it will print to the *standard output*
* For both language: you can use *placeholders*: they indicate the type of variable to be formatted
  * `%f` is for floating point numbers (fractionals), `double`s
  * `%d` is for `int` values
  * `%c` is for `char` values
* The default for floating point numbers is to print 6 decimals of accuracy
* Alternatively: you can use *modifiers* to print more/less
  * Format: `%X.Yf` where
  * `X` is the minimum number of columns (including the decimal)
  * `Y` is the number of digits of accuracy
  * Both are optional


```c

    double pi = 3.14159;

    printf("pi = %f\n", pi);
    printf("pi = %.2f\n", pi);
    printf("pi = %.4f\n", pi);
    printf("pi = %f\n", pi);

    printf("pi = %10.2f\n", pi); //print a minimum of 10 columns, 2 digits of precision

    int nuid = 12345;

    printf("nuid = %8d\n", nuid);
    printf("nuid = %08d\n", nuid);
```

# Java

* `System.out.print` which prints the given string
* `System.out.println` which outputs the string + endline character `\n`
* You also have access to `System.out.printf`

## Interactive Input

* The standard input is your keyboard: interactive input

### C

* You can use `scanf` to scan the standard input
* Mostly the same placeholders:
  * `int`: `%d`
  * `char`: `%c`
  * Exception: `double`: `%lf`
* Generally only read one value at a time
* For now: remember that you need to use an ampersand with `scanf`: `scanf("%lf", &miles);`

```c

    int x;
    double y;
    char c;

    printf("enter an integer: ");
    scanf("%d", &x);

    printf("enter a fractional value: ");
    scanf("%lf", &y);

    scanf("%c", &c);
    printf("enter a letter: ");
    scanf("%c", &c);

    printf("I read: %d, %f, and %c\n", x, y, c);
```

### Java

* You have a `Scanner` class
* You can direct it to read in from the standard input: `System.in`

```java

		int x;
		double y;
		String name;

		Scanner s = new Scanner(System.in);

		System.out.println("Enter a integer:");
		x = s.nextInt();

		System.out.println("x = " + x);

		System.out.println("Enter a fraction:");
		y = s.nextDouble();
		System.out.println("y = " + y);

		System.out.println("Enter your name:");
		name = s.next();
		System.out.println("Hello, " + name);

```

## Non-interactive input

* Interactive input (using `scanf`) makes the program pause and wait for the user to enter in their input
* Most programs especially command line programs are *not* interactive
* From the command line, you can provide input *non-interactively* by using *command line arguments* (CLAs)
* CLAs are provided when you start the program: `./a.out hello 10 3.5`
  * Each is separated by spaces
  * In C: the first argument is always the executable file name, but
  * In Java: the first argument is the *user*'s argument
  * C: you can access them using `argv`
    * The first one: `argv[0]`
    * The second: `argv[1]`
    * The third: `argv[2]`
    * `argc` is teh number or **c**ount of the arguments
    * You might need to convert the argument to a number:
      * `atoi`: converts to an `int`
      * `atof`: converts to a `double`
* Java:
  * Again, the first argument is NOT the executable file because that's the class name!
  * To access values: `args[0], args[1], args[2]`
  * To convert:
    * `Integer.parseInt()`
    * `Double.parseDouble()`
  * To define CLAs, go to the play button drop down and then to the "arguments" tab to set them (in Eclipse)


```text















```
