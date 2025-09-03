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


```text











```
