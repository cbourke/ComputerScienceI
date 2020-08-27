
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
  * 


```text






```
