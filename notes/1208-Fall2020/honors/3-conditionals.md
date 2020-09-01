# Conditionals
## CSCE 155H Fall 2020

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

* Cruft: dead or useless that should not be kept in your codebase
* KISS = Keep It Simple Super! 
* Simpler code is easier to read, easier to understand and easier to maintain

* if-else statements are *mutually exclusive*
* Observe: the `else` block is "optional"
* YOu can also generalize it to and `if-else-if` condition where you can provide as many conditions as you wish with as many blocks as you wish

```c
if(<condition1>) {
  //block A
} else if (<condition2>){
  //block B
} else {
  //block C
}
```

* THe order is important: the first condition that evaluates to true is the ONLY one that gets executed
* All of the blocks in an `if-else-if` statement are each mutually exclusive
* Like before, the `else` block is optional (it essentially allows you to have "default" behavior)
* In general: you start with more specific conditions, then you list more general conditions

## Numeric Comparison Operators

* `<, >, <=, >=` less-than or equal to, etc.
* Equality testing: `a == b`
* Inequality testing: `a != b`
* The exclamation point is a general negation operator: you can place it in front of any expression to Negate it (true turns to false, false turns to true)
  * `a < b` is true if and only if the value stored in `a` is strictly less than the value stored in `b`
  * `a < 10` (variable compared to a literal), is true if and only if the value stored in `a` is strictly less than 10
  * Generally you do NOT write: `10 > a`, instead write `a < 10` since that is how you generally read it
  * NEVER do the following: `10 < 20`: this is a *tautology* something that is always true
  * NEVER do the following: `10 > 20`: this is a *contradiction* (something that is never true)
  * You can also compare expressions:
  `b * b - 4 * a * c < 0`
  * You can also do: `!(a < b)` or `!(a == b)`
  * SIMPLIFY: `(a >= b)` or `(a != b)`

## Pitfall (Java)

* Consider the following code:

```java
String s = "hello";
String t = "hello";
if(s == t) {
  System.out.println("same!");
}
```

* In neither language can you use `==`  for string comparisons, you end up comparing memory addresses which are not the same thing as checking for string *contents*
* In both languages you need to use a function: C: `strcmp()`, Java: `s.compareTo(t)` or `s.equals(t)`
* However, in both languages you *can* use `==` (or in fact all numerical comparison operators) with single characters!

```c
char answer = 'Y'

if(answer == 'Y') {
  printf("okay, deleting everything...\n");
} else {
  printf("Cancelling operation\n");
}
```

* You can compare single characters because every character has a numerical value (ASCII or Unicode) 

## Boolean Variables

* Often you have need to use variables that contain true or false
* Ex: sometimes you want a "flag" variable: `isStudent`, `done`, `isFreshman`
* In C: there are no boolean variables! there is no keyword `true` nor `false`
* In C: you generally use integer variables
  * 0 is associated with false
  * ANY other value is associated with true: `1` is true, `42` is true, `3.5` is true, `-10` is true
* In Java: you *do* have `boolean` variables and the keywords `true` and `false`

```c
//in c:
int isStudent = 0;

if(isStudent) {
  printf("You get some free stuff from github!\n");
}
```

```java
boolean isStudent = false;

if(isStudent) {
  System.out.printf("You get some free stuff from github!\n");
}
```

## Logical Operators

* You can combine statements to form more complex statements
* You can use the logical *and* operator which is true if and only if both of its operands are true
  * Syntax: `&&` (NOT a single ampersand!)
  * Ex: `a && b` (where a and b are expressions or variables)
  * BOTH operands have to evaluate to true for the expression to evaluate to true
  * If one or the other or BOTH evaluate to false, then the expression is false
* You can use the logical *or* operator which is true if *at least one* of its operands is true
  * True if one or the other or *both* operands is true
  * False only when *both* its operands are *false*
  * Syntax: `||` (not the same as `|` which is a bit-wise or)
* Fact: `!(a && b)` is equivalent to `(!a || !b)` (DeMorgan's Law)
* Fact: `!(isStudent && isFreshman)` is equivalent to `(!isStudent || !isFreshman)` (DeMorgan's Law)

### Pitfalls
 
* Consider the following C code:

```c
if(0 <= a <= 10) {
  ...
}
```

* In C: valid, but will not give what you intend
* In Java: it is a syntax error

```c
if(0 <= a && a <= 10) {
  ...
}
```

* Consider the following code:

```c
//C:
int a = 5;

if(a = 10) { ... }
```
  

```text






```