
# ECEN 194 - Computer Science I
## Conditionals
### Fall 2022

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
  //this code block will execute only if the
  // condition is true; if the condition is
  // false, NONE of the code block executes
  // and the program continues after the block
}
```

* You can also use an `if-else` statement:

```c
if(<condition>) {
  //block A
} else {
  //block B
}
```

* If the condition is true, block A is executed and block B is NOT executed
* If the condition is false, block B is executed and block A is NOT executed
* One or the other will always be executed, never neither nor both: "mutually exclusive"

## If-else-if Statements

* You can also add addition conditions: as many as you want by adding more `else if` statements

```c
if(<condition01>) {
  statementA;
} else if(<condition02>) {
  statementB;
} else {
  statementC;
}
```

* THe control flow operates as follows:
  * Each condition is checked *in order* (top to bottom)
  * The *first* condition that evaluates to true will execute its code block
  * ALL OTHER code blocks will not execute, it will return control to the end of the `if-else-if` block
  * All conditions are *mutually exclusive*: exactly one and only one will execute
* You can generalize this to any number of conditions:

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

* Note that the `else` block is *always* optional
* Style tips: opening curly bracket is placed on the same line as the condition or keyword (`if, else if, else`)
* Each closing bracket is on the same indentation level as the `if` keyword
* Generally whitespace:
  * indent each statement codeblock and all at the same level

## Numerical Comparison Operators

* You can compare two numerical values (variables, literals or entire expressions) or a mixture of them using:
  * `<` (*strictly* less than)
  * `<=` less than or equal to
  * `>` (strictly greater than)
  * `>=` greater than or equal to
  * `==` equality testing
  * `!=` not equal to (inequality)
  * All operators operate on TWO operands (things): the left hand side, right hand side
  * All values *must* be numerical
  * Literals: actual numbers, variables or expressions

```c

    int a = 10;
    int b = 20;
    int c = 30;

    //compare a variable to a literal (value):
    if(a == 10) {
        printf("a is ten\n");
    }

    //compare a variable to a variable:
    if(a == b) {
        printf("a and b are equal\n");
    } else {
        printf("a and b are NOT equal\n");
    }

    //you can compare an expression and a variable
    if(a + b == c) {
        printf("Hello!\n");
    }

    if(a + b - c == 103) {
        //....
    }

    //what you should NEVER do:
    //because it is always true
    if(a == a) {
        printf("a is indeed a\n");
    }
    //also:
    if(10 == 10) {
        //do not do this
    }
    //also:
    if(10 == 20) {
        //will this ever execute?
        //DEAD CODE
    }

    //you can, but probably should NOT:
    //this seems unnatrual; it is bad style
    if(10 == a) {
        printf("a is ten!\n");
    }

    //check for even/odd:
    if(a % 2 == 0) {
        printf("a is even\n");
    } else {
        printf("a is odd\n");
    }

    //also, you cannot (or should not):
    if("apple" < "banana") {
        printf("apple comes before banana\n");
        //seems like it works, but...
    }

    if("orange" < "lemon") {
        printf("orange comes before lemon\n");
        //seems like it works, but...
    }

    //you cannot use the numerical operators for strings
```

## Pitfalls

* You cannot use the numerical operators to compare strings

* Consider the following:

```c
if(0 <= a <= 10) {
  printf("Hello\n");
}
```

* The above always evaluates to true (reasons given: it evaluates the first inequality and then defaults to either 0 or 1)
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

* The mistake is using one equal sign (assignment operator) instead of `==`
* Using the `-Wall` will help you to see these mistakes!

### Pitfall 3
* Consider the following code:

```c
if(a == 10); {
  printf("a is 10!\n");
}

```

## Other Operators

### General Negation Operator

* Any statement can be negated using the `!`
* Example: `!(a > b)` this will be "flipped", it is equivalent to `a <= b` (better)
* Write your conditions as readable and as simple as possible; easier to understand easier to maintain

### Boolean Variables

* By default C does not have "boolean" variables: variables that hold the values *true* or *false*
* instead, you use numbers:
  * 0 is false and ONLY zero is false
  * anything else: 1, 2, 42, -3, 2.5, -2.1 are all true
* when writing statements with boolean variables: keep it simple, *use the variable* not comparisons

```c
int isStudent = 0;

if(isStudent) {
    printf("you get a 10%% discount\n");
}
```

* You can also alternatively, bring in a library: `stdbool.h`
* ex:

```c
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(int argc, char **argv) {

    bool isStudent = false;

    if(isStudent) {
        printf("you get a 10%% discount\n");
    }

    return 0;
}
```

### Complex Logical Expressions

* You can use connectives to form more complex logical statements such as "and" and "or"
* The logical "and" operator is true if and only if both its operands are true:
  * Syntax: `&&`
  * Example: `a > 10 && b < 5`
  * It is true if the first is true and the second is true
  * It is false if the first is false
  * it is false if the second is false
  * it is false if *both* are false
* The logical "or" operator is true if at least one of its operands is true
  * Syntax: `||`
  * Example: `a > 10 || b < 5`
  * It is true if the first is true
  * It is true if the second is true
  * It is true if *both* are true
  * It is only false when *both* are false

### Comparison with Characters

* You cannot use `==` with strings, but you *can* with single characters
* Why?  Because they are all numbers in the ASCII text table

```c
char input = 'Y';

if(input == 'Y' || input == 'y') {
  printf("You answered yes\n");
} else {
  printf("you answered something else\n");
}
```

## Short Circuiting

* Consider the following logical statement: `a && b`
  * If `a` is false, does it matter what `b` is?
  * In vast majority of programming languages, `b` is not examined or evaluated
  * It is "short circuited"
  * No longer the case that it is necessary for efficiency but programmers have come to *expect* this behavior
* Consider the following: `a || b`
  * If `a` is true, does it matter what `b` is?
  * likewise, `b` is not examined or evaluated, it is short circuited

```c
if(a != NULL && a > 10) {
  //...
}
```

## Linters

* Code may be *syntactically* correct (it will compile) but may still contain bugs or errors
* Lint are pieces of code that may be okay or they may look "suspicious" and may lead to errors
* Linters are *static analysis* tools that can detect *potential* errors in your code before you compile it
* gcc can be used as a linter using the `-Wall` flag (Warnings, report ALL of them )
* Its best practice to always compile with this flag, *take care of all your compiler warnings!*

# Exercise

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

int main(int argc, char **argv) {

    double milliamps;
    printf("Please enter the mA:\n");
    int numTokens = scanf("%lf", &milliamps);

    //TODO: maybe replace this with a loop that *re*prompts them for valid input...
    if(numTokens != 1) {
        printf("ERROR: please try again\n");
        exit(1);
    }

    milliamps = fabs(milliamps);

    printf("%f mA is... ", milliamps);

    if( milliamps < 1 ) {
        printf("No Effect\n");
    } else if( milliamps < 5.2 ) {
        printf("Slight Sensation\n");
    } else if( milliamps < 62 ) {
        printf("Pain, voluntary muscle control\n");
    } else if( milliamps < 76 ) {
        printf("Pain, loss of control\n");
    } else if( milliamps < 90 ) {
        printf("Severe Pain\n");
    } else if( milliamps < 500 ) {
        printf("Heart fibrillation\n");
    } else {
        printf("something bad happened...\n");
    }


    return 0;
}
```


```text







```
