# CSCE 155H - Computer Science I
## Conditionals
### Fall 2023

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

Examples

```c

    if(huskerScore > minnScore) {
        printf("Huskers Win!\n");
    } else if(minnScore > huskerScore) {
        printf("Minnesota Won!\n");
    } else {
        printf("We go to overtime\n");
    }


    int a = 0;

    if( a % 2 == 0 ) {
        printf("a is even\n");
    } else {
        printf("a is odd\n");
    }
```

## Numerical Comparisons

* You have the obvious `<, >`
* You also have `>=, <=`
* You also have equality testing: `==`, `!=`
* THe `!` is a general negation operator, you can negate any statement
  * Example: `!(a < b)`, but it is much better/clearer to write: `(a >= b)`
  * Generally: KISS = Keep It Simple, Sarah!

## Observations

* if-else statements are *mutually exclusive*
* Observe: the `else` block is "optional"
* YOu can also generalize it to and `if-else-if` condition where you can provide as many conditions as you wish with as many blocks as you wish
* careful: the first TRUE statement is the one that gets executed and the ONLY one that gets executed
* Best approach: you specify the most specific conditions first then the most general, in fact the `else` statement is the most general: ORDER MATTERS
* CAREFUL: in NEITHER language can you use numerical comparison operators for strings, ONLY numbers; it only compares memory addresses!

## Boolean Variables

* Often you have a need to create variables that can hold values "true" and "false"
* Examples: `isStudent, isDone, isFreshman`
* In C: there are no boolean variables!
  * Instead: you use numbers (typically integers)
  * 0 is false
  * ANYTHING ELSE is true: `1, 10, 42, -5, -3.14`
  * BUT you can bring in a library: `stdbool.h`
* In Java: you have actual `boolean` variables that you can use

## Logical Operators

* You can combine statements to form more complex statements
* You can use the logical *and* operator which is true if and only if *BOTH* its operands are true:
  * Syntax: `&&`
  * Example: `a && b` is true if and only if both `a` is true and `b` is true
  * False when `a` is false, `b` is false or *both* are false
* You can use the logical *or* operator which is true if at least ONE of its operands is true
  * Syntax: `||`
  * Example: `a || b` is true if `a` is true or if `b` is true or if *both* are true
* Careful: again, you can use negation operator on any expression or variable
  * Ex: `!(a && b)` can be rewritten as `(!a || !b)`
  * `!(isStudent && isFreshman)` or: `(!isStudent || !isFreshman)`

```c
//without the library:
int isStudent = 42;
if(isStudent) {
    printf("You get discounted tickets!\n");
}
//DON't DO:
// if(isStudent == 1) {
//     printf("You get discounted tickets!\n");
// }

//with the library:
bool isFreshman = true;
if(isFreshman) {
    printf("Even more discounts?\n");
}

bool isImaginary = (b*b < 4 * a * c);
```

## Exercise:

Write a program that reads a decibel level from the user
and gives the user a description of the sound level.

* 0 - 60 Quiet
* 61 - 70 Conversational
* 71 - 110 Loud
* 111 - 194 Dangerous
* < 0 or 195+

```text








```
