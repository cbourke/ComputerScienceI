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


```text
















```
