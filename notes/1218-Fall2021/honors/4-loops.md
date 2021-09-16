
# CSCE 155H - Computer Science I
## Loops
### Fall 2021

* We need a way to repeatedly execute blocks of code
* There are four basic elements to a loop control structure:
  * An initialization statement: where the loop starts
  * A continuation condition (how long should the loop continue or when should it stop; or "termination condition")
  * An increment or "update" statement that makes *progress* toward the termination condition
  * Loop body: the code that executes for every *iteration* of the loop

## For Loops

* It uses the keyword `for`
* All three elements are on the same line: initialization, continuation, increment

```c
for(int i=1; i<=10; i++) {
  printf("i = %d\n", i);
}
```

* The initialization statement, `i=1` starts `i` at the value 1
* THe continuation condition is always checked at the start of a loop, if true, the loop executes one more time
* The increment condition is executed at the *end* of the loop
* New syntax:
  * `i++` adds one to the variable `i`
  * `++i` (prefix version)
  * `i--` subtracts one from the variable `i`
  * `i += 2` adds two to the variable `i` (compound assignment operator)
  * `i -= 10` (subtracts 10 from `i`)
  * `i *= 2` (doubles the value of `i`)
  * `i /= 10` (divides `i` by 10, beware of integer truncation!)
  * You can use doubles: `i += 1.5`
* In general, you should avoid `double` variables as your increment variables

## While Loop

* While loops use the `while` keyword
* Main difference: the three elements are separated into different lines
* A while loop is a little bit more flexible: you can place the increment operation anywhere inside the loop
* If you don't though: infinite loop; kill it with control-C
* You cannot scope a counter/increment variable to restrict it to a while loop because it is declared *before* the while loop
* THe *scope* of a variable is the section of code in which it lives or is valid or is visible
* In general it is best practice to limit the scope of a variable *as much as possible*

## Which Loop?

* Observation: any while loop can be rewritten as a for loop and vice versa
* Why two?
* In general: for loops are used when you know how many iterations it runs for: 10 or 20 or `n` iterations
* In general: while loops are used when you *don't* know how many iterations it goes for (it depends on some variable or value or expression!)
* Example: write a loop to compute the number of digits in an integer

```c
int x = -2349;
int numDigits = 0;

if(x == 0) {
    printf("number of digits is 1\n");
} else {
  while(x != 0) {
    x /= 10;
    numDigits++;
  }

  printf("number of digits is %d\n", numDigits);
}
```

* Syntactic Sugar: `i++`, you could always just use `i = i + 1`

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

1. Write a program to compute the arthmetic-geometric mean of two numbers
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
 ```

```c
/**
 * Author: Chris Bourke
 * Date: 2021/09/14
 *
 * This program takes in loan data and produces
 * a loan amortization table
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "utils.h"

int main(int argc, char **argv) {

    if(argc != 4) {
        printf("Usage: provide the principle, annualRate and years as command line arguments!\n");
        exit(1);
    }

    double principle = atof(argv[1]);
    double annualRate = atof(argv[2]);
    int years = atoi(argv[3]);

    double monthlyPayment = getMontlyPayment(annualRate, principle, years);
    monthlyPayment = roundToCents(monthlyPayment);
    printf("Monthly Payment: $%.2f\n", monthlyPayment);
    printf("Month    Balance    Interest    To Principle    New Balance\n");

    double balance = principle;
    for(int month=1; month < 12 * years; month++) {
      double toInterest = roundToCents( (annualRate / 12) * balance);
      double toPrinciple = roundToCents( monthlyPayment - toInterest);
      double newBalance = roundToCents( balance - toPrinciple );
      printf("%5d $%10.2f   $%10.2f  $%10.2f  $%10.2f\n", month, balance, toInterest, toPrinciple, newBalance);
      balance = newBalance;
    }
    //TODO: handle the last month separately

    return 0;
}
```

```text





```
