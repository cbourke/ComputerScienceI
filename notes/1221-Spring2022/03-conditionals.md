
# ECEN 1940 - Computer Science I
## Conditionals
### Spring 2022

* Normally programs have a *sequential control flow*: each
  instruction is executed top to bottom, one after the other
* However, more complex problems require *decisions*
* Conditionals are how you can specify that code executes
  under one condition or does not execute at all or
* You can specify that under some condition one piece of code
  executes otherwise a different piece of code executes
* `if`-statements, `if-else` statements and `if-else-if` statements
* Conditionals rely on some *logical condition*
* Boolean logic: a statement is either *true* or *false*

# Basic Syntax

```c
if(<condition>) {
  //if the condition above evaluates to *true* then
  this statement will execute; otherwise it will
  not execute
}
```

* You can also write an `if-else` statement:

```c
if(<condition>) {
  statementA;
} else {
  statementB;
}
```

* If the condition above evaluates to true, then statementA is executed otherwise
* if it evaluates to false, then statementB is executed
* These are *mutually exclusive* One or the other statement is executed but it is NOT the case that both NOR neither are executed

* You can extend this to a series of `if-else-if` statements

```c
if(<condition01>) {
  statementA;
} else if(<condition02>) {
  statementB;
} else {
  statementC;
}
```

* The first condition in an `if-else-if` statement that is true is the only one that executes
* All conditions are mutually exclusive: exactly ONE of them will execute, therefore
* Order *matters*
* Generally: the most specific conditions are placed first, then you generalize
* You can generalize to any number of conditions:

```c
if(<condition01>) {
  statementA;
} else if(<condition02>) {
  statementB;
} else if(<condition03>) {
  statementC;
} else if(<condition04>) {
  statementD;
} else {
  statementE;
}
```

* Style tips: opening curly bracket is placed on the same line as the condition or keyword (`if, else if, else`)
* Each closing bracket is on the same indentation level as the `if` keyword
* Generally whitespace:
  * indent each statement codeblock and all at the same level

## Conditions: Numerical Comparisons

* You can compare two numerical values (they can be variables, literals or expressions) or a mixture
  * `<` (strictly less than)
  * `<=` (less than or equal to)
  * `>` (strictly greater than)
  * `>=` (greater than or equal to)
  * `==` (equality)
  * `!=` (inequality)
  * All operators operate on TWO operands only: a left hand side and a right hand side
  * All values *must* be numerical values!
  * Operands can be variables literals (actual numbers) or expressions

### Demo

```c

    int a = 10;
    int b = 20;
    int c = 30;

    if(a > 5) {
        printf("a is greater than 5\n");
    }

    if(a > 10) {
        printf("a is greater than 10\n");
    } else {
        printf("a is not STRICTLY greater than 10\n");
    }

    if(a > b) {
        printf("a is greater than b\n");
    } else {
        printf("b is greater than a\n");
    }

    if(a == c - b) {
        printf("a is equal to c minus b\n");
    }

    if(a == b - c) {
        printf("a is equal to b minus c\n");
    }

    int homeScore = 4;
    int awayScore = 4;
    if(homeScore > awayScore) {
        printf("Mavericks Win!\n");
    } else if(homeScore < awayScore) {
        printf("Mavs lost\n");
    } else {
        printf("tie, go to OT\n");
    }

    //you can, but shouldn't:
    if(10 == a) {
        printf("a is ten\n");
    }

    //you can also evaluate expressions:
    if(b * b - 4 * a * c < 0) {
        printf("cannot handle imaginary numbers at this time!\n");
    }

    //check if a number is even or odd:
    if(a % 2 == 0) {
        printf("even!\n");
    } else {
        printf("odd\n");
    }

    //you can but should never:
    if(10 == 20) {
        printf("crash!\n");
    }
    //10 == 20 is always false it is a "contradiction"
    // thus the above is "dead code"

    //you can but should never:
    if(10 == 10) {
        printf("yup\n");
    }
    //the above condition is always true, it is a "tautology"
    // don't write the if condition, just write the statement!
```

## Pitfalls

* You cannot use numerical comparisons for strings
* You CANNOT: `if("Hello" < "Goodbye")`
* It ends up comparing memory addresses!

## General Negation Operator

* Any statement can be negated using `!`
* Example: `!(a > b)`, but would you want to?
* Equivalent: `(a <= b)` (better)
* KISS = Keep It Simple Stupid
* Simpler code is easier to read, easier to understand and thus easier to maintain
* "grok" = to intuitively understand something


### Boolean Variables

* By default, C does not have boolean variables that you can store "true" or "false" in
* Also: `true` and `false` are NOT keywords in C!
* You can bring in a library: `stdbool.h` to support true and false (and maybe variables)
* In C, zero is associated with false and any NON-ZERO VALUE is true: 1, 1.4, 3.14159, -42 are all true!
* ONLY zero is false `0`

```c

    //sets isStudent to false
    int isStudent = 0;

    // sets isStudent to true (but any non-zero value would do)
    isStudent = 42;

    if(isStudent == 1) {
        printf("you get a discount\n");
    }

    //much better:
    if(isStudent) {
        printf("you get a discount\n");
    }

    if(!isStudent) {
        printf("you pay $40\n");
    }
```

* You can also bring the standard boolean library

```c

    bool isStudent = false;

    // sets isStudent to true (but any non-zero value would do)
    isStudent = true;


    //much better:
    if(isStudent) {
        printf("you get a discount\n");
    }

    if(!isStudent) {
        printf("you pay $40\n");
    }
```

### Complex Logic Expressions

* You can use logical connectives such as "and" and "or"
* The logical "and" operator is true if and only if both of its operands are true
  * Syntax: `&&`
  * Example: `a > 10 && b < 5`
  * If either the first or the second or BOTH conditions evaluates to false, the entire expression is false
  * ONLY if both sides are true is the expression true!
* The logical "or" operator is true if and only if *at least one* of its operands is true
  * Syntax: `||`
  * Example: `a > 10 || b < 5`
  * It is true if the first is true
  * It is true if the second is true
  * It is true if BOTH are true
  * It is false ONLY if both are false!

## Comparisons with Characters

* You cannot use the `==` operator fors trings
* You *can* use them for single characters

```c
char input = 'Y';

if(input == 'Y') {
  executeCommand();
}

if(input == 'Y' || input == 'y') {
  executeCommand();
}

```

* WHy can you do this?  
* `char` types are just ASCII text values in a big table associated with numbers!

### Pitfalls

* Consider the following:

```c
if(0 <= a <= 10) {
  printf("Hello\n");
}
```

* The above always evaluates to true (reasons given)
* instead use:

```c

    //instead:
    if(0 <= a && a <=10) {
        printf("GoodBye\n");
    }
```

## Pitfall 2
* Consider the following code:

```c
//C:
int a = 5;

if(a = 10) { ... }
```

* the mistake is using a single equals sign (assignment operator) instead of the `==` equality operator

### Pitfall 3
* Consider the following code:

```c
if(a == 10); {
  printf("a is 10!\n");
}

```

## Short Circuiting

* Consider the following logical statement: `a && b`
  * Suppose that `a` evaluates to false, does it matter what `b` is?
  * No, the first one being false makes the entire statement false regardless of the second operand
  * Something called "short-circuiting": the code will skip the second statement entirely
* Consider: `a || b`
  * If `a` is true, does it matter what `b` is?
  * No, the first one being true makes the entire statement tru
* This is a common programming *idiom*   

## Linters

* Code may be syntactically correct (it will compile) but still may have errors
* Lint are piece of code that may look suspicious and may lead to errors but are not syntax errors.  
* Linters are *static analysis* tools that look for such *potential* errors in your code and report them (usually as warnings)
* Static analysis: a program that analyzes the *source code* of another program pre-compilation
* `gcc` can be used as a rudimentary linter using the flag `-Wall`
* Its best practice to always compile with this flag, *take care of all your compiler warnings!*

## Exercises

* Write a program to compute quadratic roots and deal with any "bad" inputs

* Write a program to describe the effects of an electric shock (on males, DC current) based on the milliampere (mA) current (Charles Dalziel):

  * 0 - 1 no effect
  * 1 - 5.2 mA slight sensation
  * 5.2 - 62 Pain, voluntary muscle control
  * 62 - 76 Pain, loss of control
  * 76 - 90 Severe pain
  * 90 - 500 Heart fibrillation

```c
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/**
 * This program reads in 3 coefficients (a, b, c) of a
 * quadratic formula as command line arguments
 * and computes and outputs the roots
 *
 * Chris Bourke
 * 2022/02/07
 */
int main(int argc, char **argv) {

    if(argc != 4) {
        printf("Error: provide 3 numerical coefficients\n");
        exit(1);
    }

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);

    if( b*b < 4*a*c ) {
        printf("ERROR: cannot handle imaginary roots\n");
        exit(1);
    } else if(a == 0) {
        // printf("ERROR: cannot divide by zero! (a cannot be zero)\n");
        // exit(1);
        // or:
        double root1 = -c / b;
        printf("You gave a linear equation which has a solution at x = %f\n", root1);
    } else {

        double root1 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
        double root2 = (-b - sqrt(b*b - 4*a*c)) / (2*a);

        printf("The roots of %fx^2 + %fx + %f are \n", a, b, c);
        printf(" root 1 = %f\n", root1);
        printf(" root 1 = %f\n", root2);
    }
    return 0;
}
```


```c
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/**
 * This program reads a milliamp value from the user and
 * outputs a danger level for direct current on male subjects
 * using the Charles Dalziel chart.
 *
 * See <a href="https://hubbellcdn.com/literature/07-0801-02_BodyEffects_PGrounding.pdf">here</a>
 */
int main(int argc, char **argv) {

    if(argc != 2) {
        printf("Error: provide a mA value (numeric)\n");
        exit(1);
    }

    double mAmps = atof(argv[1]);

    mAmps = fabs(mAmps);

    printf("%f mAmps is...\n", mAmps);

    if(0 <= mAmps && mAmps < 1) {
        printf("No effect\n");
    } else if(mAmps < 5.2) {
        printf("Slight Senation\n");
    } else if(mAmps < 62) {
        printf("Pain, voluntary muscle control\n");
    } else if(mAmps < 76) {
        printf("Pain, loss of control\n");
    } else if(mAmps < 90) {
        printf("Severe pain\n");
    } else if(mAmps < 500) {
        printf("Heart fibrillation\n");
    } else {
        printf("Undefined\n");
    }


    return 0;
}
```

```text




```
