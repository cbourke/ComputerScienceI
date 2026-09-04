# CSCE 155H - Computer Science I
## Conditionals
### Fall 2026

* Normally programs have a linear flow of control
* Like English: top to bottom, left to right
* But more complex programs require *decisions*
* Both C and Java support basic `if`, `if-else` and `if-else-if` conditional statements
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

## Observations:

* In an `if` statement, if the statement is true, the block executes, if the statement is false, it *doesn't*
* In an `if-else` statement, **exactly** one of the blocks A or B will execute, NEVER both: mutual exclusivity
* In a multi-conditional `if-else-if` statement each condition is checked, the FIRST one that evaluates to true is the ONE and ONLY block of code that gets executed
* In all of them: the `else` block is always *optional*

```c

    int huskerScore = 10;
    int ohioScore = 10;

    if(huskerScore > ohioScore) {
        printf("Huskers win!\n");
    } else if(huskerScore < ohioScore) {
        printf("Somesort of cats win!\n");
    } else {
        printf("Going to OT\n");
    }
```

* CAREFUL: in NEITHER language can you use numerical comparison operators for strings, ONLY numbers; it only compares memory addresses!

## Numerical Comparison Operators

* You have the obvious: `>` (strictly greater than), `<` (strictly less than)
* You can use the less-than-equal: `<=` or greater-than-equal-to: `>=`
* Do not invert the order: `=>` nor `=<`
* In code, we already use the single equals sign for assigning values to variables
* To test equality: `==`, inequality: `!=`
* Generally you can use `!` to negate any statement
  * Ex: `!(a > b)`, it would be better as `a <= b`
  * In general: KISS = Keep It Simple, Simon

## Boolean Variables

* Often you have a need to create variables that hold the values "true" or "false"
* Ex: `isStudent, isDone, isFreshman`
* In C: there are no boolean variables!
  * Instead: you have to use a number
  * Generally you use an integer: `int isDone`
  * False is going to be associated with `0`
  * True is ANY non-zero value: `1, 42, 3.5, -10`
  * However: you can bring in the `stdbool.h` library
  * It defines a `bool` type variable and keywords `true`, `false`
* Java:
  * You DO have a built-in `boolean` variable type
  * It *cannot* take on integer values!
  * `true` and `false` are reserved words

```java
boolean isStudent = false;
if(isStudent) {
  System.out.println("You get a discount");
} else {
  System.out.println("Full price");
}

```

## Logical Operators

* You can combine multiple statements to form more complex statements using the logical "and" and "or"
* You can use the logical "and" operator:
  * `&&`
  * Ex: `a && b` where a, b are boolean statements
  * It evaluates to true if and only if *both* a and b are both true
  * It evaluates to false if `a` is false or `b` is false or *both* are false
* You can use the logical *or* operator which is true if at least ONE of its operands is true
  * `||`
  * Ex: `a || b` is true if `a` is true or if `b` is true or if *both* are true!
* Careful: again, you can use negation operator on any expression or variable
  * Ex: `!(a && b)` can be rewritten as `(!a || !b)`

### Order of Precedence

* Generally operators are evaluated left-to-right
* Order: `!, &&, ||`

```java
		boolean a = true;
		boolean b = false;
		boolean c = false;

		if (a || b && c) {
			System.out.println("True");
		} else {
			System.out.println("False");
		}

		if ( (a || b) && c) {
			System.out.println("True");
		} else {
			System.out.println("False");
		}
```

### Short Circuiting

* Consider the logical and: `a && b`
  * If `a` is false, does it matter what `b` is?
  * NO: the expression will evaluate to false
  * Consequently: `b` is not evaluated or looked at
  * Efficiency: you know the entire thing is false and so you skip some operations to save time!
  * Languages still support short-circuiting because everyone has come to expect it
  * It is useful in common programming *idioms*

```java
Integer x = null;
if(x != null && x == 20) {
  int y = x + 10;
}

```

* Consider: `a || b`
  * If `a` is true, does it matter what `b` is?
  * Nope, so short-circuit: `b` is not evaluated

## Pitfalls or Common Mistakes


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
if(0 <= a && a <= 10) {
    printf("bar\n");
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
* The semicolon means that the if-statement *binds* to an empty executable statement

## Very Nice Tool: linter

* You can avoid many programming errors by using `gcc` as a "linter"
* Linter: a static analysis tool (static means that it checks code before it compiles)
  * It can detect many code errors that can/should be addressed
  * To do this you can use the `-Wall` flag (**W**arnings: **all** of them, its not actually all of them :()
  * You can also use `-Wextra` to get even more warnings

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
 * Author:
 * Date:
 *
 * TODO: documentation
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stderr, "Provide a decibel level");
    exit(1);
  }

  int decibel = atoi(argv[1]);

  if (decibel < 0) {
    fprintf(stderr, "Invalid");
  } else if (decibel <= 60) {
    printf("Quiet");
  } else if (decibel <= 70) {
    printf("Conversational");
  } else if (decibel <= 110) {
    printf("Loud");
  } else if (decibel <= 194) {
    printf("Dangerous");
  } else if (decibel < 0) {
    printf("Invalid");
  } else {
    printf("Undefined");
  }

  return 0;
}

```

```text











```
