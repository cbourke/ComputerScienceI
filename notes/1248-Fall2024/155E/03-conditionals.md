# CSCE 155E - Computer Science I
## Conditionals
### Fall 2024

* Normally programs have a linear flow of control
* Like English: top to bottom, left to right
* However, more complex problems require *decisions*
* Conditionals are how you can specify that code executes under one condition or does not execute at all or
* You can specify that under some condition one piece of code executes otherwise a different piece of code executes
* `if`-statements, `if-else` statements and `if-else-if` statements
* Conditionals rely on some *logical condition*
* Boolean logic: a statement is either *true* or *false*


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
* If the condition is false, then the code block does NOT execute
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
* These are *mutually exclusive*: excactly ONE of them happens

```c
if(<conditionA>) {
  //block A
} else if (<conditionB>){
  //block B
} else if (<conditionC>){
  //block C
} else {
  //block D
}
```

* A full `if-else-if` statement may have as many conditions and blocks as you need
* The *order matters*: the first conditon that evaluates to true is the block that gets executed
* ALL blocks of code are *mutually exclusive*: exactly ONE and ONLY one code block will ever be executed

```c

    int huskerScore = 38;
    int coloradoScore = 30;

    if(huskerScore > coloradoScore) {
        printf("Huskers won!\n");
    } else if(huskerScore < coloradoScore) {
        printf("Colorado won!\n");
    } else {
        printf("overtime!\n");
    }
```

* Generally you write `if-else-if` conditions so that the *most specific* condition comes first
* THen you order them: most specific to most general
* `else` block: most general of all

## Style

* The opening curly bracket is on the same line as the `if` statement
* Note the whitespace: just be consistent about it
* Conditions are placed inside of parentheses: `()`
* All blocks of code are indented inside the curly brackets
* Also: the `else` block is *always optional*

## Numeric Comprisons

* You have the basic strictly less than: `<` and strictly greater than: `>`
* Less than or equal to: `<=`
* Greater than or equal to: `>=`
* Strict equality: `==`
* Inequality: `!=`
* All operators operate on TWO operands
* Operands (left hand side, right hand side) may be values (numbers or "literals") or expressions or variables or combinations of them


### Examples

```c

    int a, b, c;

    //will we have imaginary roots
    // b^2 - 4ac < 0
    if(b*b - 4*a*c < 0) {
        printf("You have imaginary roots, cannot handle that!\n");
    }

    //better style:
    if(a == 0) {
        printf("cannot handle a = zero\n");
    }

    //correct, but bad style:
    if(0 == a) {
        printf("cannot handle a = zero\n");
    }

    //the following are *always* true and therefore should not be written
    if(a == a) {
        printf("wow! cool math!\n");
    }

    if(0 < 10) {
        printf("wow! cool math!\n");
    }

    //these are always FALSE, therefore they will NEVER execute!
    if(a != a) {
        printf("huh?\n");
    }

    if(0 > 10) {
        printf("how?\n");
    }
```

## Pitfalls

* You *cannot* use numerical comparison operators for strings
* Basically you would be comparing memory addresses in the computer!

## General Negation Operator

* Any statement can be negated (true becomes false, false becomes true) using the negation operator: `!`
* Ex: `!(a < b)`, `!(a == b)`
* Better: `(a >= b)`, `(a != b)`
* KISS = Keep It Stupid Simple
* Simpler code is, in general, better code

## Boolean Variables

* C does not have built-in boolean variables nor does it have the keywords "true" or "false"
* Instead we use numbers:
  * 0 = false
  * ANYTHING ELSE is true: `1`, `1.5`, `-42` are all true

```c

    int isStudent = 0; //sets it false

    isStudent = -42; //sets it to true

    if(isStudent) {
        printf("discounted husker tickets\n");
    } else {
        printf("full price!\n");
    }

    //bad practice to check on the numerical value:
    if(isStudent == 1) {
        printf("super discount applied!\n");
    }
```

* However, C does have a `stdbool.h` library (standard boolean library)
* You can create `bool` variable types
* You can use the keywords `true` and `false`
* This doesn't *add* boolean variables, it just makes it look like there are boolean variables:

```c

    bool isStudent = false;

    // isStudent = true;

    if(isStudent) {
        printf("discounted husker tickets\n");
    } else {
        printf("full price!\n");
    }
  ```

## Complex Logical Expressions

* You can combine booleans and statements into more complex "connectives"
* The logical "and" and logical "or"
* In C the logical "and" operator is true if and only if both of its operands are true, false otherwise
  * Syntax: `&&` (two ampersands)
  * Example: `(isStudent && isFreshman)`
  * It is false if one or the other operand is false
  * It is false if the first operand is false, the second operand is false or *both* are false!
* The logical "or" is true if *at least* one of its operands is true
  * Syntax: `||` ("pipes")
  * Example: `(isStudent || isFreshman)` is true if `isStudent` is true or if `isFreshman` is true or if BOTH are true
  * It is only false when *both* of the operands is false

### Precedence Rules

* Similar to PEMDAS, logical operators have an *order of precedence*
* IN general the order is: `!, &&, ||`
* You can always change this by adding parentheses

```c

    bool a = true;
    bool b = false;
    bool c = false;

    if(a || b && c) {
        printf("True\n"); //this one
    } else {
        printf("False\n");
    }

    if( (a || b) && c) {
        printf("True\n");
    } else {
        printf("False\n"); //thisone
    }
```

### Short-Ciruiting

* Consider the following expression: `a && b`
  * Suppose that `a` is false, does it matter what `b` is?
  * Regardless of the value of `b`, the expression will be false
  * Consequently a computer will completely ignore `b` (it won't be executed or evaluated at all)
* Consider the following: `a || b`
  * Suppose that `a` is true: does it matter what `b` is?
  * No, because the expression will be true regardless of the value of `b`
* It was/is more efficient o skip operations if they are not necessary
* This has become a programming *idiom*: this is an expected behavior/pattern to any programming language

## Pitfalls

* Consdier the folling:

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
* Lint are piece of code that may look suspicious and may lead to errors but are not syntax errors.  
* Linters are *static analysis* tools that look for such *potential* errors in your code and report them (usually as warnings)
* Static analysis: a program that analyzes the *source code* of another program pre-compilation
* When you run `gcc` always use the `-Wall` flag (**W**arnings **all** of them)

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
 * Chris Bourke
 * 2024-09-09
 *
 * Reads in a decibel level from the user and gives an English
 * characterization of it.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char **argv) {

    if(argc != 2) {
      printf("ERROR: enter decibels please\n");
      exit(1);
    }

    int decibels = atoi(argv[1]);

    // printf("Please enter a decibel level: ");
    // scanf("%d", &decibels);

    printf("%d decibels is ", decibels);

    if(decibels < 0) {
      printf("ERROR: cannot have negative values!\n");
    } else if(decibels <= 60) {
      printf("quiet\n");
    } else if(decibels <= 70) {
      printf("conversational\n");
    } else if(decibels <= 110) {
      printf("loud\n");
    } else if(decibels <= 194) {
      printf("dangerous\n");
    } else {
      printf("UNDEFINED\n");
    }

    return 0;
}
```

```text











```
