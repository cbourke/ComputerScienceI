
# CSCE 155H - Computer Science I
## Conditionals
### Fall 2022


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

```

### Examples

```c

    int a = 0;
    int b = 10;
    int c = 15;

    if(a == 0) {
        printf("do not divide by a!\n");
    }

    if(a == b) {
      printf("both variables are equal\n");
    }

    //you can use full mathematical expressions:
    if( b * b - 4 * a * c < 0 ) {
        printf("no real roots!\n");
    }

```

* Stylistically, we do not do:

```c
if(0 == a) {
  printf("do not divide by a!\n");
}
```

* `if-else` statements are *mutually exclusive*
* Observe: the `else` block is "optional"
* YOu can also generalize it to and `if-else-if` condition where you can provide as many conditions as you wish with as many blocks as you wish

### If-else-if

```c
int huskerScore = 50, northDakotaScore = 50;

if(huskerScore > northDakotaScore) {
    printf("Huskers Win!!!\n");
} else if(northDakotaScore > huskerScore) {
    printf("Huskers Lose :(\n");
} else {
    printf("Tie, overtime\n");
}
```

* The order is important: the first condition that evaluates to true is the ONLY one that gets executed
* All of the blocks in an `if-else-if` statement are each mutually exclusive
* Like before, the `else` block is optional (it essentially allows you to have "default" behavior)
* In general: you start with more specific conditions, then you list more general conditions

## Numeric Comparison Operators

* `<, >, <=, >=` less-than or equal to, etc.
* Equality: `==`
* Inequality: `!=`
* The exclamation point is a general negation operator: you can place it in front of any expression to Negate it (true turns to false, false turns to true)
  * `a < b` is true if and only if a has a value strictly less than b
  * `!(a < b)` is true if and only if a has a value greater than or equal to b: `(a >= b)`
  * KISS: Keep It Stupid Simple
  * In ***NEITHER*** language can you use `==` nor `!=` for string comparisons
  * Instead, using these with strings, compares the *memory address* of the stored strings in both languages!

## Boolean Variables

* Often you want a variable to hold the value true or false
* These are "boolean" variables
* Example: `done`, `isStudent`, `isFreshman`
* In C: there are no boolean variables
  * Instead: numbers are used for booleans
  * False: `0`
  * True: any non-zero value, `1`, `42`, `3.5`, `-10`
  * Consequently, you usually use an `int` for a boolean
  * Except: you *can* bring in a library: `stdbool.h`

```c
//int isStudent = 42;
bool isStudent = true;

if(isStudent) {
    printf("You get a 10%% discount\n");
} else {
    printf("full price\n");
}
```

* Java: you have an actual built-in `boolean` variable type
* Use it! You can use the keywords `true`, `false`

## Logical Operators

* You can combine statements to form more complex statements
* You can use the "connectives": the logical *and*, *or*
* The logical *and* operator is true if and only if both its operands are true
  * Syntax: `&&`
  * Example: `(a > b) && (a == 10)`
  * It is false when the first is false, the second is false, or both are false
* The logical *or* operator is true if *either* its operands is true (or both)
  * Syntax: `||`
  * Exmaple: `(a > b) || (a == 10)`
  * Only false when *both* of its operands are false
* Fact: `!(a && b)` is equivalent to `(!a || !b)` (DeMorgan's Law)
* Fact: `!(isStudent && isFreshman)` is equivalent to `(!isStudent || !isFreshman)` (DeMorgan's Law)

### Pitfalls

* Consider the following C code:

```c
int a = 5;
if(0 <= a <= 10) {
  printf("foo\n");
}
```

* The above code (in C) compiles and runs but does not give you the *intended* results
* In Java: it won't even compile
* Solution: use logical and operator:

```c
int a = 15;
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

* In C the above compiles and runs but does not give expected results
* In Java: does not compile (you need to use proper boolean types)
* Mistake is misuing the *assignment operator*

* Consider the following code:

```c
if(a == 10); {
  printf("a is 10!\n");
}
```

* The above will compile and run in *both* langauges! but not give correct results
* THe semicolon means that the if-statement *binds* to an empty executable statement

## Very Nice Tool: linter

* In C: make your life easier by using proper gcc flags
  * Lint: not necessarily "dirt" (ie not really syntax errors) but likely stuff that will result in a bug or other error (stuff we don't want)
  * A linter will run "static analysis" on your code: looks at the code *before* it compiles and finds "suspicious" looking code
  * Best practice: always use the `-Wall` flag when compiling!

### Short Circuiting

* Consider a logical and: `a && b`
  * If `a` is false, does it matter what value `b` has?
  * No: regardless of whether `b` is true or false, the entire expression is false
  * Thus: the evaluation of the expression is "short-circuited" and `b` is never examined
  * Common "idiomatic" check for null:

  `if(a != NULL && a == 10)`

* Consider: `a || b`
  * If `a` is true, does it matter what hte value of b is?
  * No: the entire exprssion evaluates to true and so `b` is unevaluated
  

```text








```
