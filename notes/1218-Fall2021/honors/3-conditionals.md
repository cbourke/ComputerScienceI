
# CSCE 155H - Computer Science I
## Conditionals
### Fall 2021

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

    //you can but shouldn't:
    //bad style
    if(0 == a) {
        printf("do not divide by a!\n");
    }

    //you can compare two variables:
    if(a == b) {
        printf("both are the same\n");
    } else {
        printf("a and b are different\n");
    }

    //you can use full mathematical expressions:
    if( b * b - 4 * a * c < 0 ) {
        printf("no real roots!\n");
    }

    //test if a is odd or even:
    if(a % 2 == 0) {
        printf("even\n");
    } else {
        printf("odd\n");
    }

    //you can but shouldn't:
    //this is a contradiction, this is dead code
    if(10 == 20) {
        printf("what a world!\n");
    }

    //bad style:
    if(a == 0) {
        printf("yay!\n");
    } else {
    }

    //this is a tautology:
    //bad style
    if(a == a) {
        printf("foo\n");
    }
```


* if-else statements are *mutually exclusive*
* Observe: the `else` block is "optional"
* YOu can also generalize it to and `if-else-if` condition where you can provide as many conditions as you wish with as many blocks as you wish

```c
if(<conditionA>) {
  //block a
} else if(conditionB>) {
  //block b
} else {
  //block c
}

```

* THe order is important: the first condition that evaluates to true is the ONLY one that gets executed
* All of the blocks in an `if-else-if` statement are each mutually exclusive
* Like before, the `else` block is optional (it essentially allows you to have "default" behavior)
* In general: you start with more specific conditions, then you list more general conditions

## Numeric Comparison Operators

* `<, >, <=, >=` less-than or equal to, etc.
* Equality: `==`
* Inequality: `!=`
* The exclamation point is a general negation operator: you can place it in front of any expression to Negate it (true turns to false, false turns to true)
  * `a < b` is true if and only if `a` is strictly less than `b`
  * Negation: `!(a < b)`, but equivalently: `(a >= b)`
  * KISS = Keep It Simple Stupid
* In ***neither*** language can you use the `==` nor the `!=` for strings!
* Instead, using these with strings, compares the *memory address* of the stored strings in both languages!

## Boolean Variables

* OFten you will have need for variables that hold the values "true" or "false"
* Example: you can "flag" variables, `isStudent, done, isFreshman`
* In C: there are no boolean variables!
* In C: you *can* bring in a library, `stdbool.h` which has placeholders for `true` and `false`
* In C:
  * boolean variables are numbers (reuse `int` variables)
  * false is associated with 0
  * true is associated with (usually with 1) but *any* non-zero values is true: `1, 42, -5, 3.14` are all true!
  * Don't assume the value of true!

```c  
    int isStudent = true;

    //bad style and incorrect:
    if(isStudent == true) {
        printf("You get a discount!\n");
    }

    //better style and correct in all instance:
    if(isStudent) {
        printf("You get a discount!\n");
    }
```

* Java has actual `boolean` type variables that you *need* to use

```java


		int isFreshman = 0;
		  boolean isStudent = true;

		  //bad style and incorrect:
		  if(isStudent == true) {
		      System.out.printf("You get a discount!\n");
		  }

		  //better style and correct in all instance:
		  if(isStudent) {
			  System.out.printf("You get a discount!\n");
		  }
		  //not even possible:
		  if(isFreshman) {
			  System.out.printf("You get a bigger discount!\n");
		  }

```

## Logical Operators

* You can combine statements to form more complex statements
* You can use the logical *and* operator which is true if and only if both of its operands are true
  * Syntax: `&&` (NOT a single ampersand!)
  * Ex: `a && b` is true if and only if *both* `a` and `b` are true!
  * It is false when `a` is false or `b` is false or both are false
* THe logical *or* operator is true if *at least* one of its operands is true:
  * Syntax: `||`
  * `a || b` is true if `a` is true or if `b` is true of if both are true
  * false when *both* are false
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
  * A linter will run "static analysis" on your code: looks at the code *before* it compiles and finds "suspicious" looking code
  * Best practice: always use the `-Wall` flag when compiling!

## Misc

### Short Circuiting

* Consider a logical and: `a && b`
  * If `a` evaluates to false, does it matter what the truth value of `b` is?
  * No, the value of `b` will not even be looked at by the program
  * The program will "skip" or short-circuit the evaluation of `b`
* Consider the logical or operator: `a || b`
  * If `a` evaluates to true, does it matter what the value of `b` is?
  * No, so it too is short circuited and not evaluated
* Programmers expect this behavior and program toward it: they often use *programming idioms* to exploit it


### Non-numeric comparisons

* IN both languages you can use the numerical comparison operators to compare single characters

```c
char initial = 'C';

if(initial == 'c' || initial == 'C') {
  //...
}
```

* Both languages allow you to do this because characters are numbers (ASCII)
* In neither language can you use the numerical comparison operators for full strings

## Exercise:

Write a program that reads a decibel level from the user
and gives the user a description of the sound level.

* 0 - 60 Quiet
* 61 - 70 Conversational
* 71 - 110 Loud
* 111 - 194 Dangerous
* < 0 or 195+

```c


    printf("Please enter a decibel level: ");
    double decibel;
    scanf("%lf", &decibel);

    if(decibel < 0) {
      printf("You cannot have negative sound!\n");
    } else if(decibel <= 60) {
      printf("quiet\n");
    } else if(decibel <= 70) {
      printf("conversational\n");
    } else if(decibel <= 110) {
      printf("loud\n");
    } else if(decibel <= 194) {
      printf("dangerous\n");
    } else {
      printf("unknown volume level!\n");
    }
```

```java
//java v ersion


		System.out.printf("Please enter a decibel level: ");
	    double decibel;
	    Scanner s = new Scanner(System.in);
	    decibel = s.nextDouble();

	    if(decibel < 0) {
	      System.out.printf("You cannot have negative sound!\n");
	    } else if(decibel <= 60) {
	      System.out.printf("quiet\n");
	    } else if(decibel <= 70) {
	      System.out.printf("conversational\n");
	    } else if(decibel <= 110) {
	      System.out.printf("loud\n");
	    } else if(decibel <= 194) {
	      System.out.printf("dangerous\n");
	    } else {
	      System.out.printf("unknown volume level!\n");
	    }
```

```text


```
