# CSCE 155H - Computer Science I
## Conditionals
### Fall 2024

* Normally programs have a linear flow of control
* Like English: top to bottom, left to right
* But more complex programs require *decisions*
* Both C and Java support basic `if`, `else-if` and `if-else-if` conditional statements
* Each one relies on some logical conditional statement
* Or "boolean statements": statements or values that are either *true* or *false*


## Basic If/else-if/if-else-if statements

```c
if(<condition>) {
  //the code inside this block will execute if and only
  //if the <condition> evaluates to true
}

if(<condition>) {
  //block A
} else {
  //block B
}

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

## Observations

* if-else statements are *mutually exclusive*: exactly ONE and ONLY one option is executed
* The first condition that evaluates to true is the one (and only one) that gets executed
* Observe: the `else` block is "optional"
* You can also generalize it to `if-else-if` conditions where you can provide as many conditions as you want/need and as many blocks as you need
* Best approach: write the most *specific* condition *first*, then generalize
* The last `else` statement: is the most general
* CAREFUL: in NEITHER language can you use numerical comparison operators for strings, ONLY numbers; it only compares memory addresses!

## Numerical Comparison Operators

* You have the obvious `>` (strictly greater than), `<` (strictly less than)
* You have: `>=`, `<=` greater-than-or-equal-to, less than or equal to
* You also have strict equality: `==` and inequality: `!=`
* The `!` is a general negation operator, you can negate any statement
  * Ex: `!(a > b)` is equivalent to `(a >= b)`
  * In general: KISS = Keep It Simple Stupid

## Examples

```c

    int huskerScore = 28;
    int coloradoScore = 28;

    if(huskerScore > coloradoScore) {
        printf("Huskers win!\n");
    } else if(huskerScore < coloradoScore) {
        printf("Colorado Wins!\n");
    } else {
        printf("Going to overtime!\n");
    }

int x = ?;

if(x % 2 == 0) {
  printf("x is even\n");
} else {
  printf("x is odd\n");
}

```

## Boolean Variables

* Often you have a need to crate variables that hold values "true" or "false"
* Ex: `isStudent`, `isDone`, `isFreshman`
* IN C: there are no built-in boolean variables!!!
  * Instead: numbers are used
  * 0 = false
  * ANYTHING else is true: `0.1`, `1`, `-42` are all true!
  * Library: `stdbool.h` that you can then use `true` and `false` as "keywords"
```c
int isStudent = false;

if(isStudent) {
    printf("free student section tickets!\n");
} else {
    printf("full price\n");
}
```

### Java

* Java has built-in boolean types: `boolean`
* You *cannot* use numbers as booleans in Java

```java
boolean isStudent = true;

if(isStudent) {
    System.out.printf("free student section tickets!\n");
} else {
  System.out.printf("full price\n");
}

```

## Logical Operators

* You can combine statements to form more complex statements
* You can use the logical "and" operator or the logical "or" operator
* The "and" operator is `&&`
  * Ex: `a && b` where a, b are boolean statements
  * It evaluates to true if and only if *both* a and b are true
  * It evaluates to false if a is false, b is false or both are false
* You can use the logical *or* operator which is true if at least ONE of its operands is true
  * Syntax: `||`
  * Ex: `a || b` is true if `a` is true or if `b` is true or if *both* are true!
* Careful: again, you can use negation operator on any expression or variable
  * Ex: `!(a && b)` can be rewritten as `(!a || !b)`
  * `!(isStudent && isFreshman)` or: `(!isStudent || !isFreshman)`

### Order of Precedence

* Generally the operators are evaluated left-to-right
* Order: `!, &&, ||`
* So you may need to add parentheses for correct logic

```java
boolean a = true;
boolean b = false;
boolean c = false;

if(a || b && c) {
  System.out.println("True");
} else {
  System.out.println("False");
}

if( (a || b) && c) {
  System.out.println("True");
} else {
  System.out.println("False");
}
```

### Short Circuiting

* Consider the logical and: `a && b`
  * If `a` is false, does it matter what `b` is?
  * Consequently: `b` does not get evaluated
  * Efficiency: you know the entire thing is false and so you skip some operations to save time!
* Common idiom is used in many applications:

```java
Integer x = null;
if(x != null && x == 20) {
  int y = x + 10;
}

```

* Consider the logical or: `a || b`
  * If `a` is true, does it matter what `b` is?
  * Consequently: `b` does not get evaluated

## Pitfalls

* Consider the following C code:

```c
int a = 5;
if(0 <= a <= 10) {
  printf("foo\n");
}
```

* The above code (in C) compiles and runs but does not give you the *intended* results
* In Java: does not compile!
* Solution:

```c

//you should not in general:
if(10 == a) { ... }
//instead prefer variables on the LHS:
if(a == 10) { ... }

//but this is probably okay:
if(0 <= a && a <= 10) {
  printf("foo\n");
}

```

* Consider the following code:

```c
//C:
int a = 5;

if(a = 10) { ... }
```

* Don't confuse the assignment operator `=` with the equality operator: `==`
* In Java: compiler error!

* Consider the following code:

```c
if(a == 10); {
  printf("a is 10!\n");
}
```

* The above will compile and run in *both* langauges! but not give correct results
* THe semicolon means that the if-statement *binds* to an empty executable statement

## Very Nice Tool: linter

* You can avoid many programming errors by using `gcc` as a "linter"
* Linter: a static analysis tool (static means that it checks code before it compiles)
  * It can detect many code errors that can/should be addressed
  * To do this you can use the `-Wall` flag (**W**arnings: **all** of them)
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
 * This program reads in a decibel level and outputs an
 * English characterization of it.
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    printf("Please enter a decibel level:");
    int decibel;
    int matches = scanf("%d", &decibel);
    if(matches == 0) {
        printf("decibel = %d\n", decibel);
        printf("ERROR, you should enter an integer\n");
        exit(1);
    }

    printf("Decibel level of %d is ", decibel);

    if(decibel < 0) {
        printf("ERROR: cannot be negative!\n");
    } else if(decibel <= 60) {
        printf("quiet\n");
    } else if(decibel <= 70) {
        printf("conversational\n");
    } else if(decibel <= 110) {
        printf("loud\n");
    } else if(decibel <= 194) {
        printf("dangerous\n");
    } else {
        printf("UNDEFINED\n");
    }

    return 0;
}
```

```text











```
