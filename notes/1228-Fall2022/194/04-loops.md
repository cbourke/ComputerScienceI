
# ECEN 194 - Computer Science I
## Loops
### Fall 2022

* We need a way to repeatedly execute blocks of code
* There are four basic elements to a loop control structure:
  * An initialization statement: where the loop starts
  * A continuation condition (how long should the loop continue or when should it stop; or "termination condition")
  * An increment or "update" statement that makes *progress* toward the termination condition
  * Loop body: the code that executes for every *iteration* of the loop

```c
for(int i=0; i<10; i++) {
  printf("lap #%d\n", i);
}
printf("done\n");

int i=0;
while(i<10) {
  i++;
  printf("lap #%d\n", i);
}

printf("done\n");
```

* Demo: https://pythontutor.com/c.html#mode=edit

## For Loops

* The three main parts: initialization, continuation, and increment are all on the same line
  * The loop will continue to execute (another *iteration*) as long as the continuation condition evaluates to true
  * The continuation condition is evaluated at the *start* of an iteration
  * The increment is executed at the *end* of an iteration
  * The initialization is only ever executed once before the loop begins
* Syntax:
  * Use the keyword `for`
  * Semicolons end the initialization and continuation statements, but NOT the iteration
  * Note that the iteration variable, `i` is *declared within the loop structure*
  * The *scope* of `i` is limited to the for loop itself!
* New syntax: `i++` adds one to the variable `i`
  * `i--` subtracts 1 from the variable `i`
  * `i = i + 10;` can be rewritten as `i += 10;`
  * `i = i - 5;` can be rewritten as `i -= 5;`
  * `i = i * 2;` can be rewritten as `i *= 2;`
  * `i = i / 2;` can be rewritten as `i /= 2;`

## While loops

* While loops use the keyword `while`

```c
int i = 1;
while(i <= 10) {
  printf("i = %d\n", i);
  i++;
}
```

* Key differences:
  * The initialization happens *before* the loop
  * Consequence: you cannot have a loop-scoped variable
  * You have flexibility on where the increment occurs: *you* have to specify it in the loop body


## Zune

  * On December 31st, 2008 every zune froze for 24 hours
  * 2008 was a leap year
  * The following code was in a zune subsystem:

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

### For vs While Loop

* Any for loop can be rewritten as an equivalent while loop and vice versa
* It is generally "natural" to use a for loop when you know up front (apriori) how many iterations you will execute
* It is more 'natural" to use a while loop when the number of iterations is not known up front

### Nested Loops

* You can place a loop within a loop: a "nested" loop
* we refer to them as the inner loop/outer loop
```c
int n = 10;

for(int i=0; i<n; i++) {
  for(int j=0; j<n; j++) {
    printf("i, j = (%d, %d)\n", i, j);
  }
}
```

* More nested loops is likely a *code smell*: not necessarily bad, but probably stinks!

## Pitfalls

* Consider the following:

```c
int i = 0;
while(i < 10); {
  printf("%d\n", i);
	i++;
}
```

* The above results in an infinite loop because of the misplaced semicolon
* Using proper `-Wall` linter flags may catch these things!
* To kill a running program type control-C


* Consider the following code:

```c
int i = 0;
while(i < 10) {
  printf("%d\n", i);
}
```

* This leads to an infinite loop, so be careful
* You are not making progress toward your termination condition



* Consider the following code:

```c
int i = 0;
while(i < 10)
  printf("%d\n", i);
  i++;
```

1. Write a solution to FizzBuzz
2. Write a program to compute a sum of the (partial) harmonic series:
  $$\sum_{i=1}^{n} \frac{1}{i}$$
3. Compute a loan amortization table using a monthly payment formula:
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


```text





```
