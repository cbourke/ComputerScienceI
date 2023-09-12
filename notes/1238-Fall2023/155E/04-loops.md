
# CSCE 155E - Computer Science I
## Loops
### Fall 2023

* We need a way to repeatedly execute blocks of code
* There are four basic elements to a loop control structure:
  * An initialization statement: where the loop starts
  * A continuation condition (how long should the loop continue or when should it stop; or "termination condition")
  * An increment or "update" statement that makes *progress* toward the termination condition
  * Loop body: the code that executes for every *iteration* of the loop

## `for` Loops

* The three main parts: initialization, continuation and increment are all on the same line
* Semicolons are necessary on the first two, but NOT used on the third
* THe body is surrounded by opening/closing curly brackets

```c
for(int i=1; i<=10; i++) {
  printf("i = %d\n", i);
}

printf("done\n");
```

* The *scope* of a variable is the area of code in which it exists or is visible or is valid
* Best practice: limit the scope of variables as much as possible
* Observations:
  * The increment (`i++`) automatically is executed at the *end* of the loop
  * The `i++` adds one to the variable `i`
  * You *may* see `++i` which has the same effect but a different "value" (forget about it for now)
  * `i--` subtracts one from the variable `i`
  * `i += 2` equivalent to `i = i + 2` (adds 2 to the variable `i`)
  * `i -= 3` subtracts 3 from `i`
  * `i *= 2` doubles (times two) the value in `i`
  * `i /= 3` divides `i` by 3 using *integer division*
  * Ex: `i = 10`

## While Loops

* While loops use the keyword `while`

```c

  int n = 10;

  int i=0;
  while(i<n) {
    printf("i = %d\n", i);
    i++;
  }
```
Differences:
* all three elements are separated
* In general, a while loop is a bit more flexible
* You have a bit more control over where the increment is placed
* With a `for`-loop you can limit the scope of your iterator/increment variable but with a `while` loop you can't
* Generally the initialization occurs *before* the loop
* The continuation is still "bound" to the `while` keyword
* As long as the continuation condition is true, the while loop will execute at least one more time
* Syntax:
  * There is no semicolon at the end of the continuation condition
  * The loop body is still denoted with curly brackets
  * REmember: to kill a program you use control-C

### For vs While Loops

* Observation: any while loop can be rewritten as an equivalent for loop and vice versa
* In general:
  * Use a `for` loop when you know (up front) how many iterations (either say 10 iterations or `n` iterations) you will execute the loop for
  * Use a `while` loop when you *don't* know how many iterations it will go (it depends on a value or variable or some other condition)
* Write a program to compute the number of digits in an integer

```c

    if(argc != 2) {
        printf("ERROR: You need to provide an integer\n");
        exit(1);
    }

    int n = atoi(argv[1]);
    int originalValue = n;
    int numDigits = 0;

    if(n == 0) {
        printf("0 has 1 digit\n");
    } else {

        while(abs(n) > 0) {
            n /= 10;
            numDigits++;
        }
        printf("%d has %d digits\n", originalValue, numDigits);
    }
```

### Nested Loops

* You can have a loop inside a loop
* we refer to them as the outer loop and the inner loop

```c
    int n = 10;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("i, j = %d, %d\n", i, j);
            counter++;
        }
    }
```

* But: avoid this at all costs; certainly 3 or more nested loops: really rethink what you are doing

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
* Using proper `-Wall` linter flags may catch these things!

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

## Exercises

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
     ...
 ```

```text








```
