
# CSCE 155E - Computer Science I
## Conditionals
### CSCE 155E, Fall 2023

* Normally programs have a *sequential control flow*: each instruction is executed top to bottom, one after the other
* However, more complex problems require *decisions*
* Conditionals are how you can specify that code executes under one condition or does not execute at all or
* You can specify that under some condition one piece of code executes otherwise a different piece of code executes
* `if`-statements, `if-else` statements and `if-else-if` statements
* Conditionals rely on some *logical condition*
* Boolean logic: a statement is either *true* or *false*

# Basic Examples

```c
if(<condition>) {
  //if the <condition> is true (or evaluates to true),
  //then anything inside this code block will
  //get executed.  If the condition is false,
  // this code block will not be executed at all
}

if(<condition>) {
  //statement A
} else {
  //statement B
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

```c
if(huskerScore > minnScore) {
    printf("Yay, the huskers won!\n");
} else if(minnScore > huskerScore) {
    printf("Oh no, we lost again\n");
} else {
    printf("we go to overtime\n");
}
```

## Observations

* NOte the style: we being the opening curly bracket on the same line as the keywords `if`, `else`, etc.
* The closing curly bracket is aligned with the keyword
* All blocks are indented at the same level
* In an `if-else-if` block: all blocks are *mutally exclusive*: one and exactly one block will executed, AND the block that gets executed is the one whose condition evaluates to true **first**: IE ORDER MATTERS
* Generally you place the most specific condition(s) first, then the most general later
* The most general condition: `else` block

## Numerical Comparisons

* You have the basic `<` and `>` *strict* comparisons
* You have equality versions: `<=`, `>=` (NOT `=<, =>`)
* For strict equality `==` `!=` (equals, not equals)
* Example

```c
int x = 42;

//% is the division-remainder operator
//  read it as: mod or "Modulo"
if( x % 2 == 0) {
    printf("x is even\n");
} else {
    printf("x is odd\n");
}

if( x % 2 != 0) {
    printf("x is odd\n");
} else {
    printf("x is even\n");
}
```

* All operators operate on TWO operands
* Operands (left hand side, right hand side) may be values (numbers or "literals") or expressions or variables or combinations of them

```c

    int a = 5;
    int b = 10;
    int c = 15;

    if(a == 0) {
        printf("You cannot divide by a!\n");
    }
    //alternative: you can, but do not do:
    if(0 == a) {
        printf("You cannot divide by a!\n");
    }

    //you can compare two variables:
    if(a == b) {
        printf("a and b are the same\n");
    } else {
        printf("They are not the same\n");
    }

    if(b*b - 4*a*c < 0) {
        printf("we do not support complex roots!\n");
    }

    //you can, but don't:
    if(10 == 20) {
        //dead code
        printf("huh?\n");
    }

    if(a != a) {
        //don't do this
    }
```

## Pitfalls

* You cannot use numerical comparisons for strings
* This would end up comparing memory addresses!

## General Negation Operator

* Any statement can be negated (true becomes false and false becomes true) using the negation operator: `!`
* Example: `!(a < b)` but equivalently: `(a >= b)`
* KISS = Keep It Stupid Simple
* Simpler code is, in general, better code

## Boolean Variables

* C does not actually have built-in boolean variables, "true" or "false"
* Instead, we use numbers:
  * `0` is false
  * ANYTHING else is true! `1`, `-2`, `42`, `3.5`, `-3.14`

```c

  int isStudent = 1; //they are a student
  isStudent = 0; //they are not a student

  if(isStudent) {
    printf("you get a discount\n");
  }

  //DO NOT write: does not work and it is terrible style!
  if(isStudent == 1) {
    printf("you get a discount\n");
  }

  //you can also use the stdbool.h library:
  bool isFreshman = true;
  isFreshman = false;
  if(isFreshman) {
    printf("a bigger discount!\n");
  }
```

## Complex Logical Expressions

* You can combine booleans and statements into more complex "connectives"
* The logical "and" and logical "or"
* In C the logical "and" operator is true if and only if both of its operands are true, false otherwise
  * Syntax: `&&`
  * Example: `isStudent && isFreshman` is true if and only if `isStudent` is true AND `isFreshman` is true
  * False when `isStudent` is false or `isFreshman` is false or BOTH are false
* The logical "or" is true if *at least* one of its operands is true
  * Syntax: `||`
  * Example: `isStudent || isFreshman` is true if `isStudent` is true or if `isFreshman` is true or if BOTH are true
  * it is only false when both `isStudent` is false and `isFreshman` is false

## Exercise:

Write a program that reads a decibel level from the user
and gives the user a description of the sound level.

* 0 - 60 Quiet
* 61 - 70 Conversational
* 71 - 110 Loud
* 111 - 194 Dangerous
* < 0 or 195+

```c

  int decibel = -10;

  if(decibel < 0) {
    printf("illegal input\n");
  } else if(decibel <= 60) {
    printf("Quiet :)\n");
  } else if(decibel <= 70) {
    printf("Conversational\n");
  } else if(decibel <= 110) {
    printf("Loud\n");
  } else if(decibel <= 195) {
    printf("Dangerous\n");
  } else {
    printf("undefined\n");
  }
```

## Pitfalls

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

## Short Circuiting

* Consider the following expression: `a && b`
  * Suppose `a` evaluates to false, does it matter what the value of `b` is?
  * Consequently, the program will ignore `b` and "short circuit" its evaluation
* Consider the following: `a || b`
  * Suppose `a` evaluates to true, does it matter what `b` is?
  * No: the entire expression is automatically true and `b` is ignored
* This is a common programming *idiom*

```c
int *a = NULL;
if(a != NULL && dangerousOperationHERE) {

}
```

## Misc

* You *can* use numeric comparison operators for individual `char` variables

```c
    printf("You are about to delete the entire hard drive, are you sure (Y/N):");
    char answer;
    scanf("%c", &answer);
    if(answer == 'Y' || answer == 'y') {
      printf("rm -Rf /");
    } else {
      printf("safe!");
    }


```

* Recall that you cannot use numerical comparisons with full *strings*: `"Chris"`

```c

	char name[] = "Chris";

	if(name == "Chris") {
		printf("hello, professor!\n");
	}

	if( strcmp(name, "Chris") == 0) {
		printf("hello, professor!\n");
	}
```



```text












```
