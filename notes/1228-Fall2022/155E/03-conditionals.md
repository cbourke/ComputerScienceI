
# CSCE 155E - Computer Science I
## Conditionals
### Fall 2022

* Normally programs have a *sequential control flow*: each
  instruction is executed top to bottom, one after the other
* However, more complex problems require *decisions*
* Conditionals are how you can specify that code executes
  under one condition or does not execute at all or
* You can specify that undre some condition one piece of code executes otherwise a different piece of code executes
* `if`-statements, `if-else` statements, `if-else-if` statements
* Conditionals rely on some *logical condition*
* Boolean logic: a staticment that is either true or false

# Basic Syntax

```c
if(<condition>) {
  // if the condition evaluates to true
  // everything in this block of code
  // will execute
  // otherwise, none of this code will
  // execute and normal control flow
  // continues after it
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
* If it evaluates to false, statementB executes
* These are *mutually exclusive*: exactly one will execute

* YOu can extend to an `if-else-if` statement

```c
if(<condition01>) {
  statementA;
} else if(<condition02>) {
  statementB;
} else {
  statementC;
}
```
* You can have as many `else if` statements as you like along with as many conditions
* All conditions are *mutually exclusive*: exactly one and only one will execute
* *Order Matters*: the first one that is true is the one that will get executed
* The most specific conditions need to go first, the most general last

* Style:
  * opening curly brackets are on the same line as the condition
  * Each closing curly bracket is at the same indentation level as the `if` statement
  * Each block is indented

## Conditions: numerical comparisons

* You can compare two numerical values (they can be variables, literals or expressions) or a mixture
  * `<` (strictly less than)
  * `<=` (less than or equal to)
  * `>`, `>=`
  * `==`, `!=` (equality, inequality)
  * All comparisons operate on *two* operands: a left hand side and a right hand size
  * Either one could be a variable, a literal (hardcoded value) or an expression
  * BUT: both *must* be numerical

```c

    int huskerScore, northDakotaScore;

    if(huskerScore < northDakotaScore) {
        printf("Huksers Lose\n");
    } else if(northDakotaScore < huskerScore) {
        printf("Huskers Win\n");
    } else {
        printf("Tie, go overtime\n");
    }

    double a, b, c;

    if(b*b - 4*a*c < 0) {
        printf("Cannot compute a root...\n");
    }
```

* Style tip: You can, but probably shouldn't:

```c
int a = ...;

if(10 == a) {
  printf("a is ten\n");
}
```

* You can, but should never do:

```c
int a;

if(a == a) {
  printf("a is a!\n");
}

if(10 == 20) {
  printf("something is wrong\n");
}
```
## General Negation Operator

* Any statement can be negated (true to false, false to true) using the general negation operator: `!`
  * Is $-a + b$ the same as $-(a + b)$
  * Ex: `!(a < b)`
  * What is a better way of writing this?
  * `a >= b` is a better way to write it
  * KISS = Keep It Stupid Simple

## Boolean Variable

* By default, C does not have boolean variables
* A boolean variable isa  variable that holds the value "true" or "false"
* In C, numbers are used:
  * `0` is false
  * ANYTHING else is true: `1, 42, 10.4, -5`
* However, you can use a library: `stdbool.h`
  * It defines a `bool` variable type
  * It defines the keywords `true`, `false`

```c

    bool isStudent = true;

    if(isStudent) {
        printf("Free football tickets\n");
    }

```

### Complex Logic Expressions

* You can combine logical statements using "connectives" such as the logical "and" and logical "or"
* The logical "and" operator is true only if both sides (operands) are true
  * Syntax: `&&`
  * Example: `(a > 10) && (b < 5)`
  * Demo
  * If either the first or the second or both end up being false, the entire exprssion is false
  * ONLY if both sides are true is the expression true
* The logical "or" operator is true if *at least* one of its sides is true
  * Syntax: `||`
  * Example:  `(a > 10) || (b < 5)`
  * It is true if the first is true
  * It is true if the second is true
  * It is true if *both* are true
  * It is only false when *both* are false

# Pitfalls

* You ***Cannot*** use numerical comparison operators on anything other than numbers: it will end up comparing memory addresses instead of the *contents* of strings (more later)


## Bad ranges:


* Consider the following:

```c
if(0 <= a <= 10) {
  printf("Hello\n");
}
```

* The above always evaluates to true (reasons given)
* instead use:

```c
if(0 <= a && a <= 10) {
  printf("True\n"):
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

* The `if` statement executes an empty exeuctable statement because of the extra semicolon

## Linters

* Code may be syntactically correct (it will compile) but still may have errors




```text







```
