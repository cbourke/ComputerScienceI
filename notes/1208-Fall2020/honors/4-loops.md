
# CSCE 155H - Computer Science I Honors
## Loops
### Fall 2020

* We need a way to repeatedly execute blocks of code
* There are four basic elements to a loop control structure:
  * An initialization statement: where the loop starts
  * A continuation condition (how long should the loop continue or when should it stop; or "termination condition")
  * An increment or "update" statement that makes *progress* toward the termination condition 
  * Loop body: the code that executes for every *iteration* of the loop

## For Loops

* It uses the keyword `for`
* All three elements (initialization, continuation, increment) are located on the same line

```c
for(int i=1; i<=10; i++) {
  printf("i = %d\n", i);
}
```

* The initialization statement is `int i=1;`
  * This starts the "index" or "increment" variable `i` at the value 1
  * Note: that the init statement ends with a semicolon
  * This syntax declares the variable `i` ONLY for the for loop; the variable's *scope* is limited to the for loop (it does not exist after the loop)
  * In general it is best design to limit the scope of variables as much as possible
  * Gotcha: certain versions of C do not allow the loop-scoped declaration (<=C89): solution: compile with a better (more current) standard:
  `gcc -std=gnu99 demo.c`
* Continuation condition: `i<=10`
  * As long as the continuation condition is true, the loop will execute at least once more iteration
  * Only when the condition is false, do we break out of the loop and continue with the remainder of the program
  * The continuation condition is checked *at the start* of the loop
* Iteration statement: `i++`
  * This is simply shorthand for adding one to the value stored in `i`
  * You also have: `i--` which subtracts one from the variable `i`
  * You also have "pre" increment operators: `++i`, `--i` (my advice: avoid)
  * You can also increment/decrement by values other than zero
  * Ex: `i += 10` adds 10 to the variable `i` ("equivalent" to `i = i + 10`)
  * Ex: `i -= 5` subtracts 5 from the variable `i`
  * Ex: `i *= 3` multiplies the value in `i` by three
  * Ex: `i /= 2` divides `i` by 2 (beware: integer truncation!)
* The loop body is surrounded by opening and closing curly brackets: ALWAYS do this  

## While Loops

* While loops have a slightly different syntax: they use the keyword `while`
* Main difference: all three elements are separated onto separate lines  
  * You cannot scope a counter/increment variable to restrict it to a while loop
  * The continuation condition is still checked at the beginning of the loop
  * But: you have more control on when/where the increment statement occurs

  ```c
  int i = 1;
  while(i <= 10) {
    printf("i = %d\n", i);
    i++;
  }
  ```

## Which type?

* Observation: any while loop can be rewritten as a for loop and vice versa
* So: why two types?  Because it makes the language more expressive
* In general, use a `for` loop when you know  up front how many iterations you are going to go (10 iterations, 20 iterations or `n` iterations)
* In general, use a `while` loop when the number of iterations is *not* known up front (instead it depends on some value(s) that are changed in the loop)
* Example: write a loop to compute how many digits are in a number

```c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv) {

  if(argc != 2) {
  	printf("ERROR: provide an input\n");
  	exit(1);
  }

  int n = atoi(argv[1]);
  int original = n;

  n = abs(n);

  if(n == 0) {
	printf("there is 1 digit in 0\n");
	exit(0);
  }

  int count = 0;
  while(n > 0) {
  	n /= 10;
  	count++;
  }

  printf("there are %d digits in %d\n", count, original);


  return 0;
}
```

## Common Pitfalls

* Consider the following:

```c
int i = 0;
while(i < 10); {
  printf("%d\n", i);
	i++;
}
```

* The semicolon is misplaced; it makes the loop body empty and we get caught in an infinite loop
* Control-C kills the current running program
* Eclipse/Java: You have a stop button
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

1. Write a program that constructs a multiplication table for all values 1 up to $n$ where $n$ is read in as a command line argument
2. Write a program to compute the arthmetic-geometric mean of two numbers
3. Compute a loan amortization table using a monthly payment formula:
  $$P = \frac{rate \times principle}{1-(1+rate)^{-n}}$$
where 
 * rate is the rate per period (.05/12 for monthly payments)
 * $n$ is the number of periods (months) in the loan 
 * Ex: A $10,000 5 year loan at 5% interest (60 payments):
 $$\frac{\frac{.05}{12} \times 10,000}{1-(1+\frac{.05}{12})^{-60}} = 188.71$$
  

## Example

* AGM of 1, 4 ?
* arithmetic mean: $\frac{1+4}{2} = 2.5$
* geometric mean: $\sqrt{1\cdot 4} = 2$
* repeat: now our two numbers are 2, 2.5
* arithmetic mean: $\frac{2+2.5}{2} = 2.25$
* geometric mean: $\sqrt{2\cdot 2.5} = 2.236$
```text







```