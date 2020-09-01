
# CSCE 155E - Computer Science I
## Conditionals
### CSCE 155E, Fall 2020

* Normally programs have a *sequential control flow*: each instruction is executed top to bottom, one after the other
* However, more complex problems require *decisions*
* Conditionals are how you can specify that code executes under one condition or does not execute at all or
* You can specify that under some condition one piece of code executes otherwise a different piece of code executes
* `if`-statements, `if-else` statements and `if-else-if` statements
* Conditionals rely on some sort of logical *condition*

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

* An `if-else` statement is *mutually exclusive*: exactly one and only one of the blocks will ever be executed (never will both or neither get executed)
* You can also have more conditions and more complex statements using an if-else-if statement

```c
if(<conditionA>) {
  //if conditionA is true, then this block gets executed
} else if (<conditionB>){
  //if the conditionB is true, then this block gets executed
} else {
  //otherwise, if neither is true, then this block gets executed
}
```

* Order is important: the conditions are evaluated in the order you write them
* The *first* condition that evaluates to true is the ONLY one whose block gets executed
* All conditions are mutually exclusive
* If no conditions are true, then the `else` block gets executed
* `else` blocks are always *optional*
* Cruft: dead or useless code in your code base that you should be there

```c
if(cubsScore > tigersScore) {
  printf("Cubs win!\n");
} else if(cubsScore < tigersScore) {
  printf("Tigers Win :(\n");
} else {
  printf("tie\n");
}
```

## Conditions: Numerical Comparisons

* You can compare two **numerical** values (either variables or *literal* values) using various comparison operators
  * `<` (strictly less than)
  * `>` (strictly greater than)
  * `<=` (less than or equal to)
  * `>=` (greater than or equal to)
  * `==` (equals)
  * `!=` (not equals)
  * all of these comparisons only operate on two operands
  * all values must be numerical
  * operands can be variables, literals or even expressions

```c

  int a = 5;
  int b = 10;
  int c = 15;

  if(a == 0) {
      printf("a is zero, don't divide by it!\n");
  }

  //you can, but shouldn't:
  if(0 == a) {
      printf("a is zero, don't divide by it!\n");
  }

  //you can compare two variable values:
  if(a == b) {
      printf("equal!\n");
  } else {
      printf("not equal!\n");
  }

  //you can use expressions:
  if(b*b - 4*a*c < 0) {
    printf("you have complex roots!\n");
  }

  //you can also test for even or odd:
  if(a % 2 == 0) {
      printf("even\n");
  } else {
      printf("odd\n");
  }

  //you can, but you shouldn't:
  if(10 == 20) {
      printf("uh, okay\n");
  }

  //tautology: something that is always true:
  if(10 == 10) {
      printf("yeah, okay\n");
  }
  printf("yeah, okay\n");
```

## Pitfalls

* You CANNOT use numerical comparison operators for strings
* Because the numerical comparison operators are comparing *memory addresses* and not the contents of the strings

## General Negation Operator

* Any statement can be negated (true becomes false, false becomes true)
* You do this using the single exclamation point: `!`
* Example: `!(a < b)` or `!(a == b)`
* Better to use:
  * `(a >= b)`
  * `(a != b)`
* In general, write the simplest form of an expression
* KISS = Keep It Simple, Stupid
* Simpler code is easier to "grok"

## Boolean "variables"

* C does not have the keywords "true" no "false"
* C also does not have boolean variables (variables that can hold a value of true or false)
* In C, false is zero and anything else (postive, negative, etc.) is "true"
* IN C, zero is false
* Any non-zero value (1, 10, 3.14, -4.5) are all treated as true
* When you assign a "true" value, yes, use 1, but you cannot assume that true is always 1
* Therefore, if you want a "boolean variable" (a variable that holds either true or false values) then use an `int`


```c

  int isStudent;
  //set it to false:
  isStudent = 0;
  //set it to true:
  isStudent = 42;

  if(isStudent) {
    printf("you get free github stuff!\n");
  } else {
    printf("you gotta pay for that!\n");
  }
  
  if(!isStudent) {
    ...
  }
  
```

## Complex Logical Expressions

* You can combine one more logical expressions using logical "connectives"
* Logical connectives are AND and OR
* In C the logical AND operator is true if and only if both its operands are true
  * We use the `&&`
  * Example: `isStudent && isFreshman` is true if and only if the person is BOTH a student and a freshman
  * False when one or the other or BOTH operands are false
* The logical OR operator is true if at least one of its operands is true
  * In C we use the `||`
  * Example: `isStudent || isFreshman` is true if either of the conditions is true (or both)
  * It is false only when BOTH of the conditions are false

## Comparisons with characters

* Recall: you *cannot* use the `==` for strings
* Why?  Because it will compare the *memory addresses* of the strings, not their contents
* BUT you *can* use them for single characters, `char`
* Why can you do this? Because all characters are ASCII text characters: they are all numbers

```c
printf("Are you a student? Y/N");
char answer;
scanf("%c", &answer);

if(answer == 'y' || answer == 'Y') {
  printf("You get a student discount!\n");
} else {
  printf("You pay full price!\n");
}

```

### Pitfalls

* Consider the following code:

```c
if(0 <= a <= 10) {
  ...
}
```

* The above will compile, execute and (not) work for certain values
* The correct way of doing this is:

```c
if(0 <= a && a <= 10) {
  ...
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
* `a = 10` is the assignment operator, when evaluated, the expression gets the value 10 and so is true
* Always use `==` for equality testing!

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
/**
 * Chris Bourke
 * 2020/08/31
 *
 * This program reads in a decibel level from the
 * user and gives a human-readable description of it.
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

  printf("Please enter your decibel level:");
  int decibel;
  scanf("%d", &decibel);

  if(decibel < 0) {
      printf("error: cannot have negative sounds\n");
  } else if(decibel <= 60) {
      printf("Quiet\n");
  } else if(decibel <= 70) {
      printf("Conversational\n");
  } else if(decibel <= 110) {
      printf("Loud\n");
  } else if(decibel <= 194) {
      printf("Dangerous\n");
  } else {
      printf("Unknown\n");
  }


  return 0;
}

```

### Short Circuiting

* Consider the following logical statement: `a && b`
  * Suppose `a` is evaluates to false, does it matter what the value of `b` is?
  * No, no matter what value `b` has, the expression is false
  * Consequently: C (and the vast majority of programming languages) will *not* evaluate `b`, it is "skipped" or "short-circuited"
* Consider the following:`a || b`
  * Suppose `a` is true, does it matter what `b` is?
  * No, the expression is true regardless of the value of `b`
* For the majority of cases, this does not play a big role.
* It *is* important if you are calling functions:

```c
if(a && writeToTheDatabase(b)) {
  //do something  
}
```

* Q: do you need the parentheses:

`if((0<=decibel) && (decibel <190))`

* A: no, it would be better to write

`if( 0 <= decibel && decibel < 190 )`

## Linters

* Code may be syntactically correct (it will compile) but still may have errors
* Lint are piece of code that may look suspicious and may lead to errors but are not syntax errors.  
* Linters are *static analysis* tools that look for such *potential* errors in your code and report them (usually as warnings)
* Static analysis: a program that analyzes the *source code* of another program pre-compilation
* `gcc` can be used as a rudimentary linter using the flag `-Wall`
* Its best practice to always compile with this flag, *take care of all your compiler warnings!*



```text






```
