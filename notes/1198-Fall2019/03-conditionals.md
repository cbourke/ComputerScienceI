
# CSCE 155E - Computer Science I
## Conditionals
### CSCE 155E, Fall 2019

* Normally, programs have sequential control flow
* However, more complex problems require *decisions*
* Conditionals are how we can make some code execute under some condition(s) and/or other, different code to execute under other conditions
* `if`-statements, `if-else` statements, `if-else-if` statements
* Conditionals rely on some logical *condition*

# Basic Syntax

```c

if(<condition>) {
  //if the condition evaluates to true, then
  // the code inside this *block* will execute
  // otherwise, the code in this block will NOT execute
} 


if(<condition>) {
  //if condition is true, then this block gets executed
} else {
  //if the condition is false, then this block gets executed
}

```

* An if-else statement is *mutually exclusive*: exactly one of the blocks will be executed (never both and never neither)

* You can also create more complex statements using an `if-else-if` statement

```c
if(<conditionA>) {
  //if conditionA is true, then this block gets executed
} else if (<conditionB>){
  //if the conditionB is true, then this block gets executed
} else {
  //otherwise, if neither is true, then this block gets executed
}
```

* Order is important: the *first* condition that evaluates to true, will cause its block to execute: thus it excludes all the other blocks
* All conditions are *mutually exclusive* 
* In general you can define as many conditions as you want, with as many `else if` statements as you want
* In general, the `else` block is always optional
* Cruft: dead or useless or unused code in your code base, don't leave cruft in your code!
* Example:

```c

  int huskerScore = 27;
  int coloradoScore = 30;

  if(huskerScore > coloradoScore) {
    printf("Yay, we won!\n");
  } else if(huskerScore == coloradoScore) {
    printf("tie!\n");
  } else {
    printf("we lost\n");
  }
```

## Conditions: Numerical Comparisons

* You can compare two values (either variable values or *literal* values ie hard coded numbers)
  * `<` (strictly less than)
  * `<=` (less than or equal to)
  * `>` (strictly greater than)
  * `>=` (greater than or equal to)
  * NOT: `=<` or `=>` (neither is supported in C)
  * `==` (equals)
  * `!=`  (inequality comparison)
  * All of these operators operate on two *operands* (left side and a right side).  
  * Each side can be a literal value, variable or an *expression*
  * grok: to immediately and intuitively understand something

```c
int a;
double b, c;

//compare a variable to a literal:
if(a == 0) {
  printf("a is zero!\n");
}

//compare a variable to a variable:
if(a == b) {
  printf("a equals b!\n");
} else {
  printf("b is actually %f\n", b);
}

//you can, but shouldn't compare a literal to a variable:
if(0 == a) {
  printf("zero is equal to a\n");
}
//stylistically the above is wrong

//you can also compare a value to an expression
if(b * b - 4 * a * c < 0) {
  printf("complex root!\n");
}

//you can, but should NEVER:
if(10 > 20) {
  printf("nah\n");
}
```

## Pitfall:

* You CANNOT use numerical comparison operators for strings
* Because the numerical comparison operators are comparing *memory addresses* and not the contents of the strings

## General Negation Operator

* Any statement can be negated (true becomes false, false becomes true) using the single negation operator: `!`
* Example: `a != b` and `!(a == b)` are the same thing
* Example: `!(a < b)` could be better written as `a >= b` (the second is preferable)
* In general you can negate any statement

## Boolean "variables"

* C actually does not support the keywords "true" nor "false"
* Instead, C uses numerical values for true/false
* IN C, zero is false
* Any non-zero value (1, 10, 3.14, -4.5) are all treated as true
* When you assign a "true" value, yes, use 1, but you cannot assume that true is always 1
* Therefore, if you want a "boolean variable" (a variable that holds either true or false values) then use an `int`

```c

  //isStudent is set initially to "true"
  int isStudent = 1;

  //reset it to false:
  isStudent = 42;

  if(isStudent) {
    printf("You get a discount!\n");
  }

  if(!isStudent) {
    printf("you pay full price\n");
  }

  //you should never:

  //1. poor style
  //2. logically wrong, you cannot assume true is always 1
  if(isStudent == 1) {
    printf("You get another discount!\n");
  }
```

## Complex Logical Expressions

* You can combine one or more logical expression using logical "connectives"
* The logical AND operator is true if both of its operands is true
  * Syntax: `&&`
  * Example: `isStudent && isFreshman` is true if and only if the person is a student and is a freshmen.  
  * False when one or the other or BOTH operands is false
* The logical OR operator which is true if at least ONE of its operands is true
  * Syntax: `||`
  * Example: `isStudent || isFreshman` is true if EITHER of the conditions is true (or both)
  * It is false when BOTH the conditions are false

## Comparisons with characters

* You can also make a comparison using the numerical operators on SINGLE characters
* This is because single characters are NUMBERS!  (ASCII text table)
```c
char answer;

  printf("Are you a student y/n?\n");
  scanf("%c", &answer);

  if(answer == 'y' || answer == 'Y') {
    printf("You entered yes");
  } else {
    printf("pay full price!\n");
  }
```

### Pitfall 

* Consider the following code:

```c
if(0 <= a <= 10) {
  ...
}
```
* The above will compile, execute, and work for certain values, but...
* What happens when `a = -10`?
    * The first comparison evaluates to true `0 <= -10` but false, giving a value of 0
    * the second comparison evaluates to true since `0 <= 10`
    * even though we "wanted" it to evaluate to false
* Solution: break it up into two conditions using `&&`
```c

  int a = 15;
  if(0 <= a && a <= 10) {
    printf("in range!\n");
  } else {
    printf("not in range\n");
  }
```

## Pitfall 2
* Consider the following code:

```c
//C:
int a = 5;

if(a = 10) { ... }
```

* The above code will compile, run but give incorrect results:
* `a = 10` is an *assignment*
* `a` is assigned the value 10 which is true in C, thus the condition evaluates to true even though we expected it to evaluate to false

### Pitfall 3
* Consider the following code:

```c
if(a == 10); {
  printf("a is 10!\n");
}

```

* The above is wrong because the if statement is bound to an empty block
* regardless of the value of `a`, the print statement will execute
* Place semicolons properly!

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

int main(int argc, char **argv) {

  int decibel;

  printf("Enter a decibel: ");
  scanf("%d", &decibel);

  if(decibel < 0) {
    printf("decibels cannot be negative\n");
  } else if(decibel <= 60) {
    printf("it is quiet\n");
  } else if(decibel <= 70) {
    printf("it is conversational\n");
  } else if(decibel <= 110) {
    printf("it is loud\n");
  } else if(decibel <= 194) {
    printf("it is dangerous\n");
  } else {
    printf("ERROR decibel exceeds the limit\n");
  }

  return 0;
}
```

### Short Circuiting

* Consider the following logical statement: `a && b`
  * Suppose that `a` evaluates to false, does it matter what the value of `b` is?
  * NO, the first being false, makes the entire expression false
  * Consequently: C (and the vast majority of programming languages) will *not* evaluate `b`, its evaluation is "skipped" or "short-circuited"
  * It was originally done to save on CPU cycles/time/efficiency
  * It is still used in languages because it is *familiar*
  * It has become a common programming *idiom*
* Consider the following logical statement: `a || b` 
  * Suppose that `a` evaluates to true, does it matter what the value of `b` is?
  * If the first is true, then the entire expression is true regardless of the value of `b`

## Linters

* Code may be syntactically correct (it will compile) but still may have errors
* Lint are piece of code that may look suspicious and may lead to errors but are not syntax errors.  
* Linters are *static analysis* tools that look for such *potential* errors in your code and report them (usually as warnings)
* Static analysis: a program that analyzes the *source code* of another program pre-compilation
* `gcc` can be used as a rudimentary linter using the flag `-Wall`
* Its best practice to always compile with this flag, *take care of all your compiler warnings!*

