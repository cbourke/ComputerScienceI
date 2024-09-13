
# CSCE 155E - Computer Science I
## Loops
### Fall 2024

* We need a way to repeatedly execute blocks of code
* There are four basic elements to a loop control structure:
  * An initialization statement: where the loop starts
  * A continuation condition (how long should the loop continue or when should it stop; or "termination condition")
  * An increment or "update" statement that makes *progress* toward the termination condition
  * Loop body: the code that executes for every *iteration* of the loop

## `for` Loops

* It uses the keyword `for`
* All three of the main elements: initialization, continuation, increment are on the same line

```c
for(int i=1; i<=10; i++) {
  printf("i = %d\n", i);
}
```

* The initialization statement, `i=1` starts `i` at the value 1
* The continuation condition: `i<=10` is checked at the *start* of each iteration of the loop
  * IF it is true, the loop body executes
  * If it is false, we break out of the loop and continue with normal linear control flow
* The initialization statement is only ever executed ONCE before the loop starts
* THe increment is executed at the *end* of the loop
* New Syntax:
  * `i++` is short hand for `i = i + 1`
  * YOu can also use `++i` (prefix version)
  * `i--` decrements `i` by one (`i = i - 1`)
  * Others: compound assignment operators
  * `i += 2` is short hand for `i = i + 2`
  * `i -= 2` is short hand for `i = i - 2`
  * `i *= 2` short hand for `i = i * 2` (doubles the value)
  * `i /= 2` short hand for `i = i / 2` (careful with truncation)
* Observations:
  * Semicolons are at the end of the initialiation and continuation statements but NOT the increment statement!
  * In general, you should *limit* the scope of variables as much as possible to avoid unintended consequences or "side effects"
  * Note: we use `i` for **i**ncrement or **i**ndex

## While Loops

* While loops use the keyword `while`
* Main difference: the three elements (initialization, continuation, increment) are all on different lines

```c
int n = 10;
int i=0;
while(i < n) {
  printf("i = %d\n", i);
  i++;
}
```

* The initialization occurs *before* the loop
* The continuation is bound within parentheses on the while loop
* The increment (in this example) is placed at the end
* BUT: it doesn't have to be: you can place the increment statement anywhere in the loop
* Failure to have a correct increment statement may lead to an *infinite loop*
* To kill the program use control-C

## Which Loop?

* Observation: any `while` loop can be rewritten as a `for` loop and vice versa
* We like having options: it makes language more flexible and usable and readable
* Generally:
  * For loops are used when you know how many iterations you are going to execute
  * WHile loops are used when you *don't* know how many iterations you are going to execute
* There are also `do-while` loops that have their continuation condition checked at the *end* of the loop instead (omitted: brittle)
* Other languages have other types of loops: foreach loops or parallelized loops

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
* Control-C kills it
* Use the proper `-Wall` flag everytime and it will catch this kind of stuff

* Consider the following code:

```c
int i = 0;
while(i < 10) {
  printf("%d\n", i);
}
```

* We forgot the increment operation: `i++`
* THough while loops are more flexible: you still have to be careful

* Consider the following code:

```c
int i = 0;
while(i < 10)
  printf("%d\n", i);
  i++;
```

* Bad style: forgot the curly brackets
* This means the loop is only bound to the next executable statement, the increment never happens
* Infinite loop
* Best practice/style: ALWAYS write your curly brackets

## Zune

* On December 31st, 2008 every zune froze for 24 hours

```c
//zune bug
while (days > 365)
{
  if (IsLeapYear(year))
	{
		if (days > 366)
		{
			days -= 366;
			year += 1;
	  }
  }
  else
  {
    days -= 365;
    year += 1;
  }
}
```

* Lack of testing
* You need to test all possible edge-cases or corner-cases

## Misc

### Nested Loops

* A loop within a loop is a "nested loo"
* There is an *outer* loop and an *inner* loop

```c
int n = 1000000;
int counter = 1;
for(int i=0; i<n; i++) {
  for(int j=0; j<n; j++) {
    //printf("%d: i = %d, j = %d\n", counter, i, j);
    counter++;
  }
}
printf("counter: %d\n", counter);
```

* This can become extremely inefficient
* If you have a nested loop: either its necessary or rethink what you're doing
* Small inputs are probably okay

## Exercises

### FizzBuzz

* https://blog.codinghorror.com/why-cant-programmers-program/

```c

int i = 1;
int n = 100;
while(i <= n) {

  if( i % 15 == 0 ) {
    printf("FizzBuzz\n");
  } else if(i % 3 == 0) {
    //divisible by three
    printf("Fizz\n");
  } else if(i % 5 == 0) {
    //divisible by five
    printf("Buzz\n");
  } else {
    printf("%d\n", i);
  }
  i++;
}
```

### Car Loan Program

Compute a loan amortization table using a monthly payment formula:
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
```




```text








```
