
# CSCE 155H - Computer Science I
## Loops
### Fall 2026

* We need a way to repeatedly execute blocks of code
* There are four basic elements to a loop control structure:
  * An initialization statement: where the loop starts
  * A continuation condition (how long should the loop continue or when should it stop; or "termination condition")
  * An increment or "update" statement that makes *progress* toward the termination condition
  * Loop body: the code that executes for every *iteration* of the loop

## `for` Loops

* It uses the keyword `for`
* All three of the loop elements are on the same line: initialization, continuation, increment

```c
for(int i=0; i<10; i++) {
  printf("i = %d\n", i);
}
```

* Style:
  * opening bracket is on the same line
  * closing bracket is aligned with the `f` in `for`
  * loop body is indented
  * Spacing: no space between `for` and `(`
* Syntax:
  * both the initialization and continuation are ended with semicolons!
  * The increment statement does not have a semicolon
* Other items:
  * `i++` is the increment operator: it *adds* one to the variable `i`, kind of like: `i = i + 1` (short hand)
  * This is known as "syntactic sugar"
  * `i, j, k` are typically used as increment variables (short, `i`ndex, `i`ncremenet)
* Behavior:
  * The initialization is only executed once *before* the loop
  * The continuation check is evaluated at the *start* of each loop
    * If it is true, the loop executes at least one more time
    * If false, the loop ends and normal linear control flow continues
    * The increment is done at the *end* of the loop

### New Syntax

* `i++` adds one to the variable `i`
* You can also use `++i` but why?
* `i--` subtracts one from `i`
* `i += 2` is short hand for `i = i + 2`
* `i -= 10` subtracts two
* `i *= 5` multiplies by two
* `i /= 3` division, but integer!

## While Loops

* A while loop uses the keyword `while`
* Main difference: the three elements (initialization, continuation, increment) are on separate lines
  * Beware: infinite loops
  * Kill a program: control-C in CS50, or the stop button in Eclipse

```c

    int i = 0;
    while(i<10) {
        printf("i = %d\n", i);
        i++;
    }

```
* It is a little bit more flexible: you can place the increment anywhere in the loop
* You cannot scope a counter/increment variable to restrict it to the while loop because it must be declared *before* the while loop
* In general it is best practice to limit the scope of a variable *as much as possible*

## Which Loop?

* Observation: any `while` loop can be rewritten as a `for` loop and vice versa
* We like flexibility in languages: we like them to be expressive, in code this is "syntactic sugar"

```c

    //given a number n, determine how many digits it has
    //ex: n = 123, 3 digits
    //ex: n = 12345678, 8 digits

    int n = 1234;
    int originalN = n;

    if(n == 0) {
        printf("0 has 1 digit\n");
    } else {
        int numberOfDigits = 0;
        while(n != 0) {
            n /= 10;
            numberOfDigits++;
        }
        printf("%d has %d digits\n", originalN, numberOfDigits);
    }
```

* While loops are generally used when you don't know how many iterations you are going to execute
* For loops are when you do know (up front) how many iterations you're going to execute

## Common Pitfalls

* Consider the following:

```c
int i = 1;
while(i <= 10); {
  printf("%d\n", i);
	i++;
}
```

* The semicolon is misplaced; it makes the loop body empty and we get caught in an infinite loop
* Control-C kills the current running program
* Use proper `-Wall` flags to catch these things!

* Consider the following code:

```c
int i = 0;
while(i < 10) {
  printf("%d\n", i);
}
```
* No increment operation: infinite loop always prints 0

* Consider the following code:

```c
int i = 0;
while(i < 10)
  printf("%d\n", i);
  i++;
```

* There are missing brackets so the `while` statement only binds to the `printf` statement: infinite loop
* Solution: always (even if you don't need to) use brackets!

## Misc

### "Enhanced" For Loops (Java)

* These are actually "for each" loops (without the keyword `foreach`)
* It is used to iterate over collections of data (arrays, lists, etc.)

```java
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};

for(int i=0; i<primes.length; i++) {
  System.out.println(primes[i]);
}

//enhanced for loop:
for(int x : primes) {
  System.out.println(x);
}
```

### Nested Loops

* You can write a loop within a loop!

```c
int n = 10;
int counter = 0;

for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
        //printf("i, j = %d, %d\n", i, j);
        counter++;
    }
}
printf("counter = %d\n", counter);
```

* Be careful: generally nested loops are *inefficient*
* Sometimes they are necessary, but 3 or certainly more loops: *rehthink* what you are doing

## Exercises

1. Write a program to compute the arithmetic-geometric mean of two numbers
2. Write a program that given an integer $n$ calculates the number of
primes $[2, n]$


```text













```
