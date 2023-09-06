# CSCE 155H - Computer Science I
## Conditionals
### Fall 2023

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

Examples

```c

    if(huskerScore > minnScore) {
        printf("Huskers Win!\n");
    } else if(minnScore > huskerScore) {
        printf("Minnesota Won!\n");
    } else {
        printf("We go to overtime\n");
    }


    int a = 0;

    if( a % 2 == 0 ) {
        printf("a is even\n");
    } else {
        printf("a is odd\n");
    }
```

## Numerical Comparisons

* You have the obvious `<, >`
* You also have `>=, <=`
* You also have equality testing: `==`, `!=`
* THe `!` is a general negation operator, you can negate any statement
  * Example: `!(a < b)`, but it is much better/clearer to write: `(a >= b)`
  * Generally: KISS = Keep It Simple, Sarah!

## Observations

* if-else statements are *mutually exclusive*
* Observe: the `else` block is "optional"
* YOu can also generalize it to and `if-else-if` condition where you can provide as many conditions as you wish with as many blocks as you wish
* careful: the first TRUE statement is the one that gets executed and the ONLY one that gets executed
* Best approach: you specify the most specific conditions first then the most general, in fact the `else` statement is the most general: ORDER MATTERS
* CAREFUL: in NEITHER language can you use numerical comparison operators for strings, ONLY numbers; it only compares memory addresses!

## Boolean Variables

* Often you have a need to create variables that can hold values "true" and "false"
* Examples: `isStudent, isDone, isFreshman`
* In C: there are no boolean variables!
  * Instead: you use numbers (typically integers)
  * 0 is false
  * ANYTHING ELSE is true: `1, 10, 42, -5, -3.14`
  * BUT you can bring in a library: `stdbool.h`
* In Java: you have actual `boolean` variables that you can use

## Logical Operators

* You can combine statements to form more complex statements
* You can use the logical *and* operator which is true if and only if *BOTH* its operands are true:
  * Syntax: `&&`
  * Example: `a && b` is true if and only if both `a` is true and `b` is true
  * False when `a` is false, `b` is false or *both* are false
* You can use the logical *or* operator which is true if at least ONE of its operands is true
  * Syntax: `||`
  * Example: `a || b` is true if `a` is true or if `b` is true or if *both* are true
* Careful: again, you can use negation operator on any expression or variable
  * Ex: `!(a && b)` can be rewritten as `(!a || !b)`
  * `!(isStudent && isFreshman)` or: `(!isStudent || !isFreshman)`

```c
//without the library:
int isStudent = 42;
if(isStudent) {
    printf("You get discounted tickets!\n");
}
//DON't DO:
// if(isStudent == 1) {
//     printf("You get discounted tickets!\n");
// }

//with the library:
bool isFreshman = true;
if(isFreshman) {
    printf("Even more discounts?\n");
}

bool isImaginary = (b*b < 4 * a * c);
```

```java

		//in Java, boolean variables exist and you CAN'T use numbers:
//	    int isStudent = 42;
//	    if(isStudent) {
//	        printf("You get discounted tickets!\n");
//	    }

		boolean isFreshman = true;
	    if(isFreshman) {
	        System.out.printf("Even more discounts?\n");
	    }

	    int a = 10, b = 20, c = 30;
	    //you can set a boolean variable to the result
	    // of a logical expression:
	    boolean isImaginary = (b*b < 4 * a * c);
```

## Exercise:

Write a program that reads a decibel level from the user
and gives the user a description of the sound level.

* 0 - 60 Quiet
* 61 - 70 Conversational
* 71 - 110 Loud
* 111 - 194 Dangerous
* < 0 or 195+

## Pitfalls

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
* Mistake is misusing the *assignment operator*
```c
//C:
int a = 5;

if(a == 10) { ... }
```


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
  * A linter will run a "static analysis" on your code *before* it compiles and raise warnings or issues it sees
  * Best practice: always use the `-Wall` flag when compiling!

## Misc

### Short Circuiting

* Consider a logical and: `a && b`
  * If `a` is false, does it matter what the truth value of `b` is?
  * No, so the entire expression is false and the evaluation of `b` is ignored!
  * Often used in patterns to avoid errors; ex:
```java
Integer x = null;
if(x != null && x == 10) {
  System.out.println("x is ten!");
}
```

* Consider the logical expression: `a || b`
  * if `a` is true then does it matter what `b` is?
  * No, the expression is true and `b` is ignored
* Programmers expect this behavior and program toward it: they often use *programming idioms* to exploit it

### Non-numeric comparisons

* In both languages you can use a numerical comparison operator for `char` variables:

```c
char answer = 'Y';

if(answer == 'y' || answer == 'Y') {
  //...
}
```

* Both languages allow you to do this because characters are numbers (ASCII)
* In neither language can you use the numerical comparison operators for full strings
* Instead: use a function or method

```c

  char name[] = "Chris";

  if(name == "Chris") {
    printf("Hello, Chris\n");
  }

  //instead: use a function
  if( strcmp(name, "Chris") == 0 ) {
    printf("Hello, Chris\n");
  }
```


```java

		  String name = new String("Chris");

		  if(name == "Chris") {
			  System.out.printf("Hello, Chris\n");
		  }

		  //instead: use a function
		  if( name.compareTo("Chris") == 0 ) {
			  System.out.printf("Hello, Chris\n");
		  }
```








```text











```
