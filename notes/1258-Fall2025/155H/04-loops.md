
# CSCE 155H - Computer Science I
## Loops
### Fall 2025

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
  * `i++` is the increment operator, it *adds* one to the variable `i`, "kinda like": `i = i + 1`
  * `i, j, k` are typically used as increment variables (short, `i`ndex, `i`ncremenet)
* Behavior:
  * The initialization is only executed once *before* the loop
  * The continuation check is evaluated at the *start* of each loop
    * If it is true, the loop executes at least one more time
    * If it is false, then the loop terminates and normal linear control flow continues
  * The increment is done at the *end* of the loop

### New Syntax

* `i++` adds one to the variable `i`
* You can use `++i` but why?  (prefix version)
* `i--` subtracts one from `i`
* `i += 2` this adds 2 to `i`
* `i -= 2` this subtracts 2 from `i`
* `i *= 2` this multiplies by 2 (doubles the value of `i`)
* `i /= 2` divides (truncation) by 2 (halves)

## While Loops

* A while loop uses the keyword `while`
* Main difference: the three elements (initialization, continuation, increment) are on separate lines

```c
int n = 10;
int i = 0;
while(i < n) {
  printf("i = %d\n", i);
  i++;
}
```

* It is a little bit more flexible: you can place the increment anywhere in the loop
* If you don't though: infinite loop; kill it with control-C
 (or the stop button in Eclipse)
* You cannot scope a counter/increment variable to restrict it to the while loop because it must be declared *before* the while loop
* In general it is best practice to limit the scope of a variable *as much as possible*

## Which Loop?

* Observation: any `while` loop can be rewritten as a `for` loop and vice versa
* Why multiple loops?
* We like flexibility in languages: we like them to be expressive, in code this is "syntactic sugar"

```c

    int originalN = 12345;
    int exepctedNumDigits = 4;
    int n = originalN;

    if(n == 0) {
        printf("There is 1 digit in zero\n");
        exit(0);
    }

    //write code to determine how many digits are in n...
    int count = 0;

    //while n > 0...
    //.   divide by 10
    //.   increment the counter
    while(n != 0) {
        n /= 10;
        count++;
    }
    printf("there are %d digits in %d\n", count, originalN);

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

* THere are missing brackets so the `while` statement only binds to the `printf` statement: infinite loop
* Solution: always (even if you don't need to) use brackets!

## Misc

### "Enhanced" For Loops (Java)

* These are actuall "for each" loops (without the keyword `foreach`)
* It is used to iterate over collections of data (arrays, lists, etc.)

```java
int primes[] = {2, 3, 5, 7, 11, 13, 17};

for(int i=0; i<primes.length; i++) {
  System.out.println(primes[i]);
}

//"for each integer x in the collection primes...
for(int x : primes) {
  System.out.println(x);
}
```

* There is no enhanced for loop in C!

### Nested Loops

```c
int n = 10;
int count = 0;
for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
        //printf("i, j = %d, %d\n", i, j);
        count++;
    }
}
printf("count = %d\n", count);
```

* Be careful: generally nested loops are *inefficient*
* Sometimes they are necessary, but 3 or certainly more loops: *rehthink* what you are doing

## Exercises

1. Write a program to compute the arithmetic-geometric mean of two numbers

2. Compute a loan amortization table using a monthly payment formula:
  $$P = \frac{rate \times principle}{1-(1+rate)^{-n}}$$
where
 * rate is the rate per period (.05/12 for monthly payments)
 * $n$ is the number of periods (months) in the loan
 * Ex: A $10,000 5 year loan at 5% interest (60 payments):
 $$\frac{\frac{.05}{12} \times 10,000}{1-(1+\frac{.05}{12})^{-60}} = 188.71$$

 ```text
 Month Balance Interest New Balance
     1   $10000.00   $   41.67   $  147.04  $ 9852.96
     2   $ 9852.96   $   41.05   $  147.66  $ 9705.30
     3   $ 9705.30   $   40.44   $  148.27  $ 9557.03
     4   $ 9557.03   $   39.82   $  148.89  $ 9408.14
     5   $ 9408.14   $   39.20   $  149.51  $ 9258.63
     6   $ 9258.63   $   38.58   $  150.13  $ 9108.50
     ...
 ```

 3. Write a program that given an integer $n$ calculates the number of
 primes $[2, n]$

```text













```
