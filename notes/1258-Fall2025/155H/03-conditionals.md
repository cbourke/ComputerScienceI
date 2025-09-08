# CSCE 155H - Computer Science I
## Conditionals
### Fall 2025

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
* The `else` block is always optional

```c
int huskers = 40;
int akron = 40;

if(huskers > akron) {
    printf("Huskers Win!\n");
} else if(huskers < akron) {
    printf("Akron Wins!\n");
} else {
    printf("Go to overtime!\n");
}

printf("Done\n");
```

* CAREFUL: in NEITHER language can you use numerical comparison operators for strings, ONLY numbers; it only compares memory addresses!

## Numerical Comparison Operators

* You have the obvious `>` (strictly greater than), `<` (strictly less than)
* You have to use a combination: `>=`, `<=`
* You have a strict equality: `==`, inequality: `!=`
* Generally you can use `!` to negate any statement
  * Ex: `!(a > b)`, equivalently: `(a <= b)`
  * In general: KISS = Keep It Simple, Simon

## Boolean Variables

* Often you have a need to create variables that hold values "true" or "false"
* Ex: `isStudent, isDone, isFreshman`
* C: you cannot do this
  * Instead: you use an `int` as a placeholder
  * A value of `0` is "false"
  * A value OTHER than `0` is "true": `1, 1.5, -10, 20`
  * KISS: use the `stdbool.h` library

```c
int isFreshman = true;

if(isFreshman) {
    printf("You get free tickets!\n");
} else {
    printf("pay full price\n");
}
```

* In Java you have a true `boolean` variable that can only every be `true` or `false`

```java
boolean isFreshman = true;

if(isFreshman) {
  System.out.printf("You get free tickets!\n");
} else {
  System.out.printf("pay full price\n");
}
```

## Logical Operators

* You can combine multiple statements to form more complex statements using "and" and "or"
* You can use the logical "and" operator:
  * `&&`
  * Ex: `a && b` where a, b are boolean statements
  * It evaluates to true if and only if *both* a and b are both true
  * It evaluates to false if `a` is false, or if `b` is false or if they are *both* false
* You can use the logical *or* operator which is true if at least ONE of its operands is true
  * `||`
  * Ex: `a || b` is true if `a` is true or if `b` is true or if *both* are true!
* Careful: again, you can use negation operator on any expression or variable
  * Ex: `!(a && b)` can be rewritten as `(!a || !b)`
  * `!(isStudent && isFreshman)` or: `(!isStudent || !isFreshman)`

### Order of Precedence

* Generally the operators are evaluated left-to-right
* Order: `!, &&, ||`

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
  * No, the expression is always going to be false
  * Consequently, `b` is not evaluated or looked at
  * Efficiency: you know the entire thing is false and so you skip some operations to save time!
* Common idiom is used in "every" programming language

```java
Integer x = null;
if(x != null && x == 20) {
  int y = x + 10;
}

```

* Consider the logical or: `a || b`
  * If `a` is true, does it matter what `b` is?
  * Consequently: `b` does not get evaluated

## Pitfalls or Common Mistakes

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
#include <stdlib.h>
#include <stdio.h>

#include <stdbool.h>

#include <math.h>


/**
 * Chris Bourke
 * 2025-09-25
 *
 * Prints out hello world to the standard output.
 */
int main(int argc, char **argv) {

    double decibel;

    if(argc != 2) {
        printf("ERROR: provide a decibel level\n");
        exit(1);
    }

    // printf("Enter a decibel level:\n");
    // scanf("%lf", &decibel);

    decibel = atof(argv[1]);

    decibel = round(decibel);

    printf("A decibel level of %.2f is... ", decibel);

    if(decibel < 0) {
        printf("ERROR, decibels cannot be negative\n");
    } else if(decibel <= 60) {
        printf("Quiet\n");
    } else if(decibel <= 70) {
        printf("Conversational\n");
    } else if(decibel <= 110) {
        printf("Loud\n");
    } else if(decibel <= 194){
        printf("Dangerous\n");
    } else {
        printf("not defined\n");
    }
}
```

```java
package unl.soc;

/**
 * Chris Bourke
 * 2025-09-25
 *
 * Prints out hello world to the standard output.
 */
public class Decibel {

	public static void main(String args[]) {

	    double decibel;

	    if(args.length != 1) {
	    	System.out.printf("ERROR: provide a decibel level\n");
	        System.exit(1);
	    }


	    decibel = Double.parseDouble(args[0]);

	    decibel = Math.round(decibel);

	    System.out.printf("A decibel level of %.2f is... ", decibel);

	    if(decibel < 0) {
	        System.out.printf("ERROR, decibels cannot be negative\n");
	    } else if(decibel <= 60) {
	        System.out.printf("Quiet\n");
	    } else if(decibel <= 70) {
	        System.out.printf("Conversational\n");
	    } else if(decibel <= 110) {
	        System.out.printf("Loud\n");
	    } else if(decibel <= 194){
	        System.out.printf("Dangerous\n");
	    } else {
	        System.out.printf("not defined\n");
	    }
	}

}
```


```text











```
