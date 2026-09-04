# CSCE 155E - Computer Science I
## Conditionals
### Fall 2026

* Normally programs have a linear flow of control
* Like English: top to bottom, left to right
* But more complex programs require *decisions*
* C supports basic `if`, `if-else` and `if-else-if` conditional statements
* Each one relies on some logical conditional statement
* Or "boolean statements": statements or values that are either *true* or *false*

# Basic Examples

```c
if(<condition>) {
  //if the <condition> is true (or evaluates to true),
  //then anything inside this code block will
  //get executed.  If the condition is false,
  // this code block will not be executed at all
}
```

* If the condition is true, then the code block executes
* If the condition is false, then the code block *does not* execute
* Regardless, linear control flow continues after code block

```c
if(<condition>) {
  //statement A
} else {
  //statement B
}

```

* If the condition is true then `statementA` executes
* If the condition is false then `statementB` executes
* Exactly ONE and ONLY one of these statements is executed: they are *mutually exclusive*

```c
if(<conditionA>) {
  //block A
} else if(<conditionB>) {
  //block B
} else if(<conditionC>) {
  //block C
} else {
  //block D
}
```

* A full `if-else-if` statement may have as many conditions and blocks as you need
* The *order matters*: the first condition that evaluates to true is the one and ONLY one block that gets executed
* ALL blocks of code are *mutually exclusive*: exactly ONE and ONLY one code block will ever be executed

```c
int huskerScore = 40;
int ohioScore = 10;

if(huskerScore < ohioScore) {
    printf("Ohio won!\n");
} else if(huskerScore > ohioScore) {
    printf("Huskers win!\n");
} else {
    printf("We're going to overtime\n");
}
```

* Generally you write `if-else-if` conditions so that the *most specific* condition comes first
* `else` block: most general of all
* Then you order them: most specific to most general

## Style & Observations

* The opening curly bracket is on the same line as the `if` statement
* The closing curly bracket is aligned with the `i` in `if`
* Note the whitespace: just be consistent about it
* Conditions are placed inside of parentheses: `()` (required)
* All blocks of code are indented inside the curly brackets
* Also: the `else` block is *always optional*

## Numeric Comparisons

* You can compare numeric values using numerical comparison operators
* Strictly less than: `<` and strictly greater than: `>`
* Less-than-equal-to: `<=`
* Greater-than-equal-to: `>=`
* Do NOT use `=<` or `=>`
* Equality: You cannot use `=` (already means assignment), `==`
* Inequality: `!=`
* Negate any statement using `!`
  * Example: `!(a < b)`
  * You should write: `a >= b`
  * KISS = Keep It Simple, Simon
* All of these operators operate on TWO operands: left hand side, right hand side
* Operands may be variables, literals (actual numbers) or expressions
  * variables: `a, huskerScore`
  * literal: `5`, `3.5`, etc.
  * expression: `b * b - 4 * a * c`

## Pitfalls

* You *cannot* use numerical comparison operators for strings
* Basically you would be comparing memory addresses in the computer!

```c

    double a = 10.0;
    double b = 20;
    double c = 30;

    if(a < b) {
        printf("a is less than b\n");
    }

    //don't write code like this:
    // this is a "tautology" - something that is *always* true
    if(a == a) {
        printf("a is equal to itself!\n");
    }

    //don't do this either:
    if(10 == 10) {
        printf("10 is 10!\n");
    }

    //don't do this either:
    //the following is a *contradiction* - something that is always false
    if(0 == 10) {
        //this is dead code
        printf("Hello!\n");
        //this will never get executed
    }

    //if you compare a variable, put it first:
    if(a == 10) {
        printf("a is 10\n");
    }
    //don't invert them:
    if(10 == a) {
        printf("a is 10\n");
    }
```

## General Negation Operator

* Any statement can be negated (true becomes false, false becomes true) using the negation operator: `!`
  * Ex: `!(a < b)`, `!(a == b)`
  * Better: `a >= b`, `a != b`
  * Simpler code is more readable code, which is more maintainable, and thus better

## Boolean Variables

* C does not have built-in boolean variables nor does it have the keywords "true" or "false"
* Instead:
  * `0` (or `0.0`) is false
  * *anything* else is true: `1`, `1.5`, `-42` is true
  * Example: `isStudent`
* Even better: bring in a library: `stdbool.h`
  * It defines a boolean variable type: `bool`
  * Defines macros `true` and `false`

```c

    bool isStudent = false;

    if(isStudent) {
        printf("You get a discount!\n");
    } else {
        printf("You pay full price\n");
    }

    //do not use equality with boolean variables:
    if(isStudent == 1) {
        printf("You get a discount!\n");
    } else {
        printf("You pay full price\n");
    }
```

## Complex Logical Expressions

* You can combine booleans, statements, expression, etc. to make more complex statements
* You can use the logical "and" and the logical "or"
* In C the logical "and" operator uses the `&&`
  * Example: `(isStudent && isFreshman)`
  * It evaluates to false if one or the other (or both) operands are *false*
  * It evaluates to true ONLY if both of the operands are *true*
* The logical "or" is true if *at least* one of its operands is true
  * Syntax: `||` (pipes or vertical lines, "Sheffer Strokes"?)
  * Example: `(isStudent || isFreshman)` is true if `isStudent`
is true or if `isFreshman` is true or if BOTH
  * It is only false when *both* are false

### Precedence Rules

* Similar to PEMDAS, logical operators have an *order of precedence*
* IN general the order is: `!, &&, ||`
* You can always change this by adding parentheses

```c
bool a = true;
bool b = false;
bool c = false;

//these will be different
if(a || b && c) {
    printf("True\n");
} else {
    printf("False\n");
}

if( (a || b) && c) {
    printf("True\n");
} else {
    printf("False\n");
}
```

## Pitfalls

* Consider the following code:

```c
int a = 15;
if(0 <= a <= 10) {
    printf("Hello!\n");
}
```

* It evaluates left-to-right: `0 <= a` evaluates to true which is `1` and so `1 <= 10` evaluates to true giving incorrect/unintended answers
* Solution: break it up into two conditions and combine them with a logical and: `&&`

```c
if(0 <= a && a <= 10) {
    printf("Hello!\n");
}
```

## Pitfall 2
* Consider the following code:

```c
//C:
int a = 5;

if(a = 10) { ... }
```

* This is (incorrectly) using the assignment operator `=` and not the equality operator: `==`
* `a` is reassigned a value that is also used as the true value (10 = true)

* Corrected:

```c
if(a == 10) {
    printf("Hello!\n");
}
```

### Pitfall 3
* Consider the following code:

```c
if(a == 10); {
  printf("a is 10!\n");
}

```

* You have an extra semicolon that should not be there
* The `if` statement ends up *binding* to an empty executable statement and nothing happens; then the actual intended code block is executed regardless of `a`

## Linter

* Code may be syntactically correct (it will compile) but still may have errors
* Code smell = something that is kinda fishy/stinky that MAY or may not be correct (likey is not)
* Lint are piece of code that may look suspicious and may lead to errors but are not syntax errors.  
* Linters are *static analysis* tools that look for such *potential* errors in your code and report them (usually as warnings)
* Static analysis: a program that analyzes the *source code* of another program pre-compilation
* When you run `gcc` always use the `-Wall` flag (**W**arnings **all** of them)
  * You can also use `-Wextra` (for even more warnings!)
  * The grader will grade on this!  (1 point for design ) so make sure you take care of all warnings!

## Exercise:

Write a program that reads a decibel level from the user
and gives the user a description of the sound level.

* 0 - 60 Quiet
* 61 - 70 Conversational
* 71 - 110 Loud
* 111 - 194 Dangerous
* < 0 or 195+

```c
/**
 * Author: Chris + CSCE155E class
 * Date: 2026-09-04
 *
 * This program reads in a decibel level from the user and outputs
 * its characterization.
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

    //check for the correct number of CLAs = command line arguments
    if(argc != 2) {
        printf("ERROR: provide a decibel level\n");
        exit(1);
    }

    //read in the input
    int decibel = atoi(argv[1]);

    if(decibel < 0) {
        printf("Invalid!\n");
    } else if(0 <= decibel && decibel <= 60) {
        printf("Quiet\n");
    } else if(decibel <= 70) {
        printf("Conversational\n");
    } else if(decibel <= 110) {
        printf("Loud\n");
    } else if(decibel <= 194) {
        printf("Dangerous\n");
    } else {
        printf("Undefined\n");
    }


    return 0;
}
```

## Exercise

```
/**
 * Author: Chris + CSCE155E class
 * Date: 2026-09-04
 *
 * This program reads in an (x,y) coordinate and outputs where it lies.
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

    double x, y;

    //prompt the user for input...
    printf("Please enter in x: ");
    scanf("%lf", &x);

    printf("Please enter in y: ");
    scanf("%lf", &y);

    printf("(%f, %f) lies...\n", x, y);

    if(x == 0.0 && y == 0.0) {
        printf("on the origin\n");
    } else if(x == 0.0) {
        printf("on the y-axis\n");
    } else if(y == 0.0) {
        printf("on the x-axis\n");
    } else if(x > 0.0 && y > 0.0) {
        printf("Quadrant I\n");
    } else if(x < 0.0 && y > 0.0) {
        printf("Quadrant II\n");
    } else if(x < 0.0 && y < 0.0) {
        printf("Quadrant III\n");
    } else if(x > 0.0 && y < 0.0) {
        printf("Quadrant IV\n");
    } else {
        printf("Something REALLY went wrong there!\n");
    }

    return 0;
}
```

```text
















```
