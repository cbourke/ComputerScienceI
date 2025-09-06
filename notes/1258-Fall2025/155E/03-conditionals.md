# CSCE 155E - Computer Science I
## Conditionals
### Fall 2025

* Normally programs have a linear flow of control
* Like English: top to bottom, left to right
* But more complex programs require *decisions*
* C supports basic `if`, `if-else` and `if-else-if` conditional statements
* Each one relies on some logical conditional statement
* Or "boolean statements": statements or values that are either *true* or *false*


# Basic Examples

```c
if(<condition>) {
  //if the <condition> is true (or evaluates to true),
  //then anything inside this code block will
  //get executed.  If the condition is false,
  // this code block will not be executed at all
}
```

* If the condition is true, then the code block executes
* If the condition is true, then the code block executes
* Regardless, linear control flow continues after code block

```c
if(<condition>) {
  //statement A
} else {
  //statement B
}

```

* If the condition is true then `statementA` executes
* If the condition is false then `statementB` executes
* These are *mutually exclusive* conditions: exactly one and ONLY one of these will execute

```c
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

* A full `if-else-if` statement may have as many conditions and blocks as you need
* The *order matters*: the first condition that evaluates to true is the block that gets executed and the *ONLY* block that gets executed
* ALL blocks of code are *mutually exclusive*: exactly ONE and ONLY one code block will ever be executed

```c
int huskers = 25;
int wrightState = 4;

if(huskers > wrightState) {
    printf("huskers win that set!\n");
} else if(huskers < wrightState) {
    printf("Wright State win that set!\n");
} else {
    printf("Tied, need to get to match point\n");
}

printf("End of program\n");
```

* Generally you write `if-else-if` conditions so that the *most specific* condition comes first
* THen you order them: most specific to most general
* `else` block: most general of all

## Style

* The opening curly bracket is on the same line as the `if` statement
* Note the whitespace: just be consistent about it
* Conditions are placed inside of parentheses: `()` (required)
* All blocks of code are indented inside the curly brackets
* Also: the `else` block is *always optional*

## Numeric Comparisons

* You have the basic strictly less than: `<`, strictly greater than: `>`
* Less than or equal to: `<=`
* Greater than or equal to: `>=`
* You have strictly equal: `==` (two equals signs)
* Inequality: `!=`
* All operators operate on TWO operands (values)
* Operands LHS/RHS can be values (`5, 3.4`) or expressions or variables or a combination of all them

## Pitfalls

* You *cannot* use numerical comparison operators for strings
* Basically you would be comparing memory addresses in the computer!

```c

    double a = 10;
    double b = 200;
    double c = 30;

    if(b*b - 4*a*c < 0) {
        printf("I cannot handle complex (imaginary) roots!\n");
        exit(1);
    } else if(a == 0) {
        printf("I cannot handle linear equations, try again!\n");
        exit(1);
    }

    double root1 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
    double root2 = (-b - sqrt(b*b - 4*a*c)) / (2*a);

    printf("roots are %f and %f\n", root1, root2);

    //you can but shouldn't do the following:
    if(a == a) {
        //"tautology" = something that is always true
        //no matter what this block will execute
    }

    if(0 < 10) {
        //always true
    }

    if(0 == 10) {
        //this is dead code
        // 0 == 10 is a "contradiction", it is never true, always false
        printf("Hello!\n");
    }

    //if you compare a variable to a value, write:
    if(a == 10) {
        printf("a is ten\n");
    }

    //it is still *correct* but bad style to reverse it:
    if(10 == a) {
        printf("a is ten\n");
    }

    //these are always FALSE, therefore they will NEVER execute!
    if(a != a) {
        printf("huh?\n");
    }

    char name[] = "Chris";
    if(name <= "Chris") {
        printf("hello chris\n");
    } else {
        printf("Hello Bob\n");
    }
```

## General Negation Operator

* Any statement can be negated (true becomes false, false becomes true) using the negation operator: `!`
* Ex: `!(a < b)`, `!(a == b)`
* Better: `a >= b`, `a != b`
* KISS = Keep It Simple Simon
* Simpler code is better in general: more readable, more maintainable, etc.

## Boolean Variables

* C does not have built-in boolean variables nor does it have the keywords "true" or "false"
* A boolean can store true or false
* Instead:
  * `0` is false
  * ANYTHING else is true: `1`, `1.5`, `2`, `-42` are all TRUE
* Example: `isStudent`
* Even better: bring in a library: `stdbool.h`
  * defines a variable type `bool`
  * Which can be set to `true` or `false`
  * Careful: these are just "defines" (macros)

```c
bool isStudent = false;

if(isStudent) {
    printf("You get free tickets to continue the 'sell out'\n");
} else {
    printf("You pay full price\n");
}
```

* You should never compare a boolean variable to `true`, `false`, etc.

## Complex Logical Expressions

* You can combine booleans, statements, expression, etc. to make more complex statements
* You can use the logical "and" and the logical "or"
* In C the logical "and" operator uses the `&&`
  * Example: `(isStudent && isFreshman)`
  * It evaluates to false if one or the other (or both) operands are *false*
  * It only evaluates to true if *both* operands are true
* The logical "or" is true if *at least* one of its operands is true
  * Syntax: `||` ("pipes")
  * Example: `(isStudent || isFreshman)` is true if `isStudent` is true or if `isFreshman` is true or if BOTH
  * Only false when both are false!


### Precedence Rules

* Similar to PEMDAS, logical operators have an *order of precedence*
* IN general the order is: `!, &&, ||`
* You can always change this by adding parentheses

```c

    bool a = true;
    bool b = false;
    bool c = false;

    if(a || b && c) {
        printf("True\n"); //this one
    } else {
        printf("False\n");
    }

    if( (a || b) && c) {
        printf("True\n");
    } else {
        printf("False\n"); //thisone
    }
```

### Short-Circuiting

* Consider the following expression: `a && b`
  * Suppose that `a` is false does it matter what `b` is?
  * Regardless of the value of `b` the expression is false
  * Therefore the computation is short-circuited and `b` is not examined or evaluated
  * Consequently a computer will completely ignore `b` (it won't be executed or evaluated at all)
  * Old school: this was more efficient; we *still have this in every language!*
  * Why? because it is a familiar *coding idiom*
* Consider the following: `a || b`
  * Suppose that `a` is true: does it matter what `b` is?
  * No, because the expression will be true regardless of the value of `b`

## Pitfalls

* Consider the following code:

```c
int a = 15;
if(0 <= a <= 10) {
    printf("Hello!\n");
}
```

* It evaluates left-to-right: `0 <= a` evaluates to true which is `1` and so `1 <= 10` evaluates to true giving incorrect/unintended answers
* Solution: break it up into two conditions and combine them with a logical and: `&&`

```c
if(0 <= a && a <= 10) {
    printf("Hello!\n");
}
```

## Pitfall 2
* Consider the following code:

```c
//C:
int a = 5;

if(a = 10) { ... }
```

* This is (incorrectly) using the assignment operator `=` and not the equality operator: `==`
* `a` is reassigned a value that is also used as the true value (10 = true)
* Corrected:

```c
if(a == 10) {
    printf("Hello!\n");
}
```

### Pitfall 3
* Consider the following code:

```c
if(a == 10); {
  printf("a is 10!\n");
}

```

* You have an extra semicolon that should not be there
* The `if` statement ends up *binding* to an empty executable statement and nothing happens; then the actual intended code block is executed regardless of `a`

## Linter

* Code may be syntactically correct (it will compile) but still may have errors
* Lint are piece of code that may look suspicious and may lead to errors but are not syntax errors.  
* Linters are *static analysis* tools that look for such *potential* errors in your code and report them (usually as warnings)
* Static analysis: a program that analyzes the *source code* of another program pre-compilation
* When you run `gcc` always use the `-Wall` flag (**W**arnings **all** of them)

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
