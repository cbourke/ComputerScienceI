
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

```text




```
