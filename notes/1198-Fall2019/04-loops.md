
# CSCE 155E - Computer Science I
## Loops
### Fall 2019

An introduction to loop control structures.

* We need a way to repeatedly execute blocks of code
* There are three basic elements to a loop control structure:
	* An initialization (where the loop starts)
	* A continuation condition (how long should the loop continue or when should it stop)
	* An increment or "update" (how you make progress toward that ending condition)
  * Another aspect: loop body (what you actually do on each *iterations*)
	
## For Loops

* A for loop uses the keyword `for`
* All three elements (initialization, continuation, increment) are all located on the same line

```c
for(int i=1; i<=10; i++) {
	printf("i = %d\n", i);
}
```

* `int i=1;` The initialization statement creates and initializes a variable `i` to 1
* `i<=10` is the continuation statement: while this statement evaluates to true, the loop will execute again (one more iteration)
* `i++` is the increment statement (the statement that makes progress toward the termination condition)
  * The increment is automatically executed *at the end of the loop*
	* The increment uses the "increment" operator: `i++`
	* Syntactic sugar: provides an easier, shorter way to simply "add one" to a variable
	* "Equivalently": `i = i + 1`
	* Others:
	  * `i--` (subtracts one from `i`)
		* `i += 2` ("equivalent to" `i = i + 2`)
		* `i -= 5` (subtract 5 from `i`, `i = i - 5`)
		* `i *= 2` (multiplies by two)
		* `i /= 10` (divides by 10)
  * Scope: 
    * The *scope* of a variable is the section of code in which it exists (visible)
		* In general it is best to limit the scope of a variable as much as possible.
		* With respect to loops, declaring (creating) an index/increment variable inside the loop will limit its scope *to that loop* and not beyond 
		* NOTE (caveat emptor): for old-school C, you CANNOT declare a loop variable (inside the loop).
    * To compile under a more modern standard on CSE, use the std flag:
		`gcc -std=gnu99 -Wall foo.c`
		* Better yet: you can define an alias so you don't have to type it all the time (see Piazza)
		
Example:

```
//write a loop to print out numbers 10 to 100, but one per line
for()


// and
//by increments of 10
```

## While Loop

* While loops have a slightly different syntax: they use the keyword `while`
* Main difference: all three elements (initialization, continuation, increment) are separated

```c
int i = 1;
while(i <= 10) {
	printf("i = %d\n", i);
	i++;
}
```

* The initialization comes before the beginning of the loop
* The continuation condition is placed next to the `while` keyword
* The increment is done *somewhere* inside the loop

## Common Pitfalls

* Misplacing a semicolon: consider the following code

```c
int i = 0;
while(i < 10); {
  printf("%d\n", i);
	i++;
}
```

* To stop a program from the command line type control-C

* Consider the following code:

```c
int i = 0;
while(i < 10) {
  printf("%d\n", i);
}
```

* This leads to an infinite loop, so be careful

* Consider the following code:

```c
int i = 0;
while(i < 10)
  printf("%d\n", i);
  i++;
```

* The above does not have curly brackets: so only the `printf` statement is *bound* to the while loop
* It is best practice to *always* include the curly brackets even if you don't need to.

* Consider the following code:
* On December 31st, 2008 every zune froze for 24 hours
* This was a classic off-by-one error

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

## Other Issues

### Nested Loops

* Often you may need to have more than one iteration
* You may need to have a loop within a loop

```c
for(int i=0; i<10; i++) {
	for(int j=0; j<10; j++) {
  	printf("i = %d, j = %d\n", i, j);	
	}
}
```

### For loops vs while loops

* Fact: any for loop can be rewritten as a while loop and vice versa
* In general you use a for loop when you know how many (even a variable number of) iterations you are going to execute
* In general you use a while loop when you don't know (up front) how many iterations you'll execute
* Example: write a loop to compute how many digits are in a given number

```c
int x = 0;

int numberOfDigits = 0;
if(x == 0) {
	printf("number of digits is one\n");
} else {
	while(x != 0) {
		x /= 10;
		numberOfDigits++;
	}

	printf("digits = %d\n", numberOfDigits);
}
```

* A for loop's iteration is *always* done at the end of the loop iteration
* You cannot scope (declare) an index variable that is limited to a while loop


1. Do the following
	* A list of even integers 0 to n, one to a line
	* The same list, but delimited by commas
	* A list of integers divisible by 3 between 10 and 100 (print a total as well)
	* Prints all positive powers of two, 1, 2, 4, 8, …, up to 2^30
	* Prints all even integers 2 thru 200 on 10 different lines (10 numbers per line)

```c
#include <stdio.h>
#include <math.h>

int main(void) {

  int n = 20;
  //A list of even integers 0 to n, one to a line
  for(int i=0; i<=n; i+=2) {
    printf("%d\n", i);
  }

  //The same list, but delimited by commas	
  int i = 0;
  for(i=0; i<=n-2; i+=2) {
    printf("%d, ", i);    
  }
  printf("%d\n", i);

  //* A list of integers divisible by 3 between 10 and 100 (print a total as well)
  int total;
	for(int i=12; i<=99; i+=3) {
    printf("%d, ", i);
    total += i;
  }
  printf("total = %d\n", total);
  
  //* Prints all positive powers of two, 1, 2, 4, 8, …, up to 2^30
  int x = 1;
	for(int i=0; i<=30; i++) {
    printf("x = %d\n", x);
    //multiply x by 2:
    x *= 2;
  }

  // Prints all even integers 2 thru 200 on 10 different lines (10 numbers per line)
  for(i=2; i<=200; i+=2) {
    printf("%d, ", i);
    if(i % 20 == 0) {
      printf("\n");
    }
  }


  return 0;
}
```

2. Write a FizzBuzz solution

```c
for(int i=1; i<=100; i++) {

    if(i % 15 == 0) {
      printf("FizzBuzz\n");
    } else if(i % 3 == 0) {
      printf("Fizz\n");
    } else if(i % 5 == 0) {
      printf("Buzz\n");
    } else {
      printf("%d\n", i);
    }

  }
```

3. Write a program to project the total earnings in a savings account with a fixed APR, initial balance, and monthly deposit over a specified number of years.

```c

double currentBalance = 1000.00;
double apr = 0.05;
double monthlyInterestRate = (apr / 12);
double monthlyDeposit = 100.00;
int numYears = 10;
int months = numYears * 12;

for(int i=1; i<=months; i++) {
	double monthlyInterest = round(currentBalance * monthlyInterestRate * 100.0) / 100.0;
	double oldBalance = currentBalance;
	currentBalance += (monthlyInterest + monthlyDeposit);
	printf("%d $%.2f $%.2f $%.2f\n", i, oldBalance, monthlyInterest, currentBalance);
}
```







