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

```text











```
