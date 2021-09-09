
# CSCE 155E - Computer Science I
## Conditionals
### CSCE 155E, Fall 2021

* Normally programs have a *sequential control flow*: each instruction is executed top to bottom, one after the other
* However, more complex problems require *decisions*
* Conditionals are how you can specify that code executes under one condition or does not execute at all or
* You can specify that under some condition one piece of code executes otherwise a different piece of code executes
* `if`-statements, `if-else` statements and `if-else-if` statements
* Conditionals rely on some *logical condition*
* Boolean logic: a statement is either *true* or *false*

# Basic Syntax

```c
if(<condition>) {
  //if the <condition> is true (or evaluates to true),
  //then anything inside this code block will
  //get executed.  If the condition is false,
  // this code block will not be executed at all
}
```

An `if-else` statement:
* if the conditiono evaluates to true, then `statementA` is executed
* If the condition evaluates to false, `statementB` is executed
* The two statements are *mutually exclusive*

```c
if(<condition>) {
  //statement A
} else {
  //statement B
}


```

An `if-else-if` statement:
* THe first condition to evaluate to true is the ONLY one whose code will execute
* All conditions are mutually exclusive and
* THe `else` block is optional
* Style tip: do not leave blank code blocks, rethink your logic
* Order is important: you generally put the most specific conditions first, then the most general last

```c
if(<condition1>) {
  //statement A
} else if(<condition2>) {
  //statement B
} else {
  //statement C
}

```

## Conditions: Numerical Comparisons

* You can compare two **numerical** values (they can be both variables or literal values or a mixture of them or even expressions!)
  * `<` (strictly less than)
  * `<=` (less than or equal to)
  * `>` (strictly greater than)
  * `>=` (greater than or equal to)
  * `==` (equals)
  * `!=` (not equals)
  * All of these operators only operate on *two* operands
  * All values *must* be numerical
  * Operands can be variables, literals (actual numbers) or expressions


```c

    int a = 5;
    int b = 10;
    int c = 15;

    // the first operand is a variable
    // the second operand is a literal
    if(a == 0) {
        printf("a is zero, don't divide by it!\n");
    }

    //you can, but shouldn't do:
    //bad style
    if(0 == a) {
        printf("a is zero, don't divide by it!\n");
    }

    //you can compare two variables:
    if(a == b) {
        printf(" both are equal!\n");
    } else {
        printf("a and b are not equal\n");
    }

    //you can also use expressions:
    if(b*b - 4*a*c < 0) {
        printf("no real roots!\n");
    }

    //check to see if a is even or odd:
    if(a % 2 == 0) {
        printf("a is even\n");
    } else {
        printf("a is odd\n");
    }

    //you can but shouldn't:
    //this is a contradiction (something that is always false)
    if(10 == 20) {
        printf("yay!\n");
    }

    //this is a tautology: it is always true
    if(a == a) {
        printf("yup!\n");
    }

```

## Pitfalls

* You cannot use numerical comparisons for strings
* This would end up comparing memory addresses!

## General Negation Operator

* Any statement can be negated (true becomes false and false becomes true) using the negation operator: `!`
* Example: `!(a < b)` is equivalent to `(a >= b)` (the second is better style)
* KISS = Keep It Simple Stupid
* Simpler code is easier to read and thus easier to understand

## Boolean Variables

* C does not actually have the keywords "true" nor "false" nor actual boolean variables
* A boolean variable is a type of variable that *would* hold the values true or false
* Instead C achieves this by using a simple `int` variable
  * `0` is false
  * Generally you can use `1` as a placeholder for "true", but really *ANY* non-zero values is true, `1, 2, 42, -5, 3.14` are all true in C!
* Make no assumptions about what value is "actually" true, ANY non-zero value is true!
* you can also bring in a library: `#include <stdbool.h>`

```c
int isStudent;

//set it to true:
isStudent = 1;

//set it to false:
isStudent = 0;

//use it in a statement:
if(isStudent) {
  printf("You get free Hukser tickets\n");
}

//negation:
if(!isStudent) {
  printf("Pay full price tickets\n");
}

```

## Complex Logical Expressions

* You can combine one or more boolean expressions using "connectives"
* Logical "and" and logical "or" statements
* In C the logical *and* operator is true if and only if both its operands are true
  * For syntax, use the `&&`
  * Example: `isStudent && isFreshman` is true if and only if a person is *BOTH* a student and a freshman
  * False when at least one of the conditions is false
* The logical or operator is true if *at least one* of its operands is true
  * IN C we use `||`
  * Example: `isStudent || isFreshman` is true if either of the conditions is true (or both)
  * It is false **only** when *both* of the conditions are false

## Comparisons with characters

  * Recall: you *cannot* use the `==` for strings
  * Why?  Because it will compare the *memory addresses* of the strings, not their contents
  * BUT you *can* use them for single characters, `char`
  * Why can you do this? Because all characters are ASCII text characters: they are all numbers

```c

    printf("You are about to delete the entire hard drive, are you sure (Y/N):");
    char answer;
    scanf("%c", &answer);
    if(answer == 'Y' || answer == 'y') {
        printf("deleting everything...\n");
    } else {
        printf("ookay, your data is safe\n");
    }
```

### Pitfalls

* Consider the following code:

```c
if(0 <= a <= 10) {
  ...
}
```

* THe above code will compile, it will run but it will not be correct
* The correct way would be:

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

* the mistake is using a single equals sign (assignment operator) instead of the `==` equality operator

### Pitfall 3
* Consider the following code:

```c
if(a == 10); {
  printf("a is 10!\n");
}

```

## Linters

* Code may be syntactically correct (it will compile) but still may have errors
* Lint are piece of code that may look suspicious and may lead to errors but are not syntax errors.  
* Linters are *static analysis* tools that look for such *potential* errors in your code and report them (usually as warnings)
* Static analysis: a program that analyzes the *source code* of another program pre-compilation
* `gcc` can be used as a rudimentary linter using the flag `-Wall`
* Its best practice to always compile with this flag, *take care of all your compiler warnings!*

## Short Circuiting

* Consider the following logical statement: `a && b`
  * SUppose that `a` evaluates to false, does it matter what the value of `b` is?
  * No matter the value of `b`, the statement is false
  * Consequently: C and the vast majority of languages do not even look at `b` or evaluate it
* Consider: `a || b`
  * if `a` is true does it matter what `b` is?
  * No, again it is short-circuited and not evaluated/looked at
* This is a common programming *idiom*   

## Exercise:

Write a program that reads a decibel level from the user
and gives the user a description of the sound level.

* 0 - 60 Quiet
* 61 - 70 Conversational
* 71 - 110 Loud
* 111 - 194 Dangerous
* < 0 or 195+

```c


  if(argc != 2) {
    printf("Error: give me your decibel level\n");
    exit(1);
  }

  double decibel = atof(argv[1]);

  printf("Decibel level: %f\n", decibel);

  if(decibel < 0) {
    printf("invalid decibel level\n");
  } else if(decibel <= 60) {
    printf("Its quiet\n");
  } else if(decibel <= 70) {
    printf("It is conversational\n");
  } else if(decibel <= 110) {
    printf("Loud\n");
  } else if(decibel <= 194) {
    printf("Danger\n");
  } else {
    printf("Unknown level\n");
  }

```
```text





```
