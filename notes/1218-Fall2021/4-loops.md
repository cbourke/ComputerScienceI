
# CSCE 155E - Computer Science I
## Loops
### Fall 2021

* We need a way to repeatedly execute blocks of code
* There are four basic elements to a loop control structure:
  * An initialization statement: where the loop starts
  * A continuation condition (how long should the loop continue or when should it stop; or "termination condition")
  * An increment or "update" statement that makes *progress* toward the termination condition
  * Loop body: the code that executes for every *iteration* of the loop

## For Loops

* The three main parts (intialization, the  continuationa and the increment) are all located on the same line:
* Semicolons are necessary on the first two, but NOT used on the third
* THe body is surrounded by opening/closing curly brackets

```c
for(int i=1; i<=10; i++) {
  printf("i = %d\n", i);
}

printf("done\n");
```

* In the above example, the *scope* of the increment variable `i` is *limited* to the loop itself.  It exists in the loop and for each *iteration* of the loop, but NOT after the loop
* THe `i=1` is the initialization, it only executes *once* before the loop executes
* THe continuation condition `i<=10` and is checked *before* the execution of each iteration (if false, the loop ends or terminates)
* The increment statement is executed at the *end* of the loop
* Observations:
  * The increment (`i++`) automatically is executed at the *end* of the loop
  * `i++` syntax adds one to the variable `i`
  * `i--` subtracts one from the variable `i`
  * Alternatively: `i = i + 1`
  * Alternatively: `i = i + 2` OR yoou can use a *compound* assignment operator: `i += 2`
  * Ex:
    * `i += 10;`
    * `i += a;` (adds whatever is stored in the variable `a` to `i`; "equivalent" to `i = i + a;`)
    * it works with `+, -, *, /`
    * `i *= 2` *mulitplies* `i` by 2
    * `i /= 2` *divides* `i` by 2 (take care with truncation)
  * By declaring `i` within the loop control structure, we *limit* its *scope* (the area of the code in which the variable exists or is "visible")

## While Loops

* While loops have a slightly different syntax: they use the keyword `while`

```c
int i = 1;
while(i <= 10) {
  printf("i = %d\n", i);
  i++;
}
```

Differences:
* all three elements are separated
* In general, a while loop is a bit more flexible
* Truth: any `for` loop can be rewritten as an equivalent `while` loop and vice versa
* The increment may be placed anywhere inside the loop body (so you are not restricted to it executing at the *end* of the loop)
* Generally the initialization occurs *before* the loop
* The continuation is still "bound" to the `while` keyword
* As long as the continuation condition is true, the while loop will execute at least one more time
* NO semicolon in the continuation condition
* The loop body is still denoted with curly brackets
* With a while loop, you *cannot* scope the iterator variable to the loop itself
* To kill a runaway program: control-C

### For vs While Loops

* Observation: any while loop can be rewritten as an equivalent for loop and vice versa
* In general, use a `for` loop when you know  up front how many iterations you are going to go (10 iterations, 20 iterations or `n` iterations)
* In general, use a `while` loop when the number of iterations is *not* known up front (instead it depends on some value(s) that are changed in the loop)
* Example: write a loop to compute how many digits are in a number

```c

  int n = 12345;
  int value = abs(n);

  if(value == 0) {
    printf("zero has 1 digit\n");
  } else {
    int numDigits = 0;
    while(value > 0) {
      numDigits++;
      value /= 10;
    }
    printf("%d has %d digits\n", n, numDigits);
  }
```

### Nested Loops

* You can have a loop inside a loop
* we refer to them as the outer loop and the inner loop
* You can do this as many times as you want, but avoid 3 or more nested loops

```c
int n = 10;

for(int i=0; i<n; i++) {
  for(int j=0; j<n; j++) {
    printf("i, j = (%d, %d)\n", i, j);
  }
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


* The missing curly brackets mean that the loop only prints and never increments
* Best practice/style: ALWAYS write your curly brackets

## Zune

* On December 31st, 2008 every zune froze for 24 hours
* classic off-by-one error
* It is common for the first or last iteration of a loop to be wrong
* It is common to handle the first or last iteration separately from the loop itself (edge cases or corner cases)


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

Compute a loan amortization table using a monthly payment formula:
  $$P = \frac{rate \times principle}{1-(1+rate)^{-n}}$$
where
 * rate is the rate per period (.05/12 for monthly payments)
 * $n$ is the number of periods (months) in the loan
 * Ex: Ex: A $10,000 5 year loan at 5% interest (60 payments):
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
 * Date: 2021/09/13
 *
 * This program takes in loan data and produces
 * a loan amortization table
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

    if(argc != 4) {
        printf("Usage: provide the principle, annualRate and years as command line arguments!\n");
        exit(1);
    }

    double principle = atof(argv[1]);
    double annualRate = atof(argv[2]);
    int years = atoi(argv[3]);

    double balance = principle;

    double monthlyPayment = (annualRate/12 * principle) / (1- pow(1+annualRate/12, -(years*12)));
    monthlyPayment = round(monthlyPayment * 100) / 100;
    printf("Monthly Payment: $%.10f\n", monthlyPayment);
    printf("Month Balance Interest Principle   New Balance\n");

    for(int month=1; month<years*12; month++) {
      double monthsInterest = round(annualRate / 12 * balance * 100) / 100;
      double toPrinciple = monthlyPayment - monthsInterest;
      double newBalance = balance - toPrinciple;
      printf("%d  $%.2f  $%.2f  $%.2f  $%.2f  \n", month, balance, monthsInterest, toPrinciple, newBalance);
      balance = newBalance;
    }
    //TODO: handle the last month here:

    return 0;
}
```

```text








```
