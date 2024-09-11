
# CSCE 155H - Computer Science I
## Loops
### Fall 2023

* We need a way to repeatedly execute blocks of code
* There are four basic elements to a loop control structure:
  * An initialization statement: where the loop starts
  * A continuation condition (how long should the loop continue or when should it stop; or "termination condition")
  * An increment or "update" statement that makes *progress* toward the termination condition
  * Loop body: the code that executes for every *iteration* of the loop

## `for` Loops

* It uses the keyword `for`
* All three of the main elements are on the same line: initialization, continuation, increment

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
  * You *can* use: `++i` but really shouldn't (prefix version)
  * `i--` subtracts one from `i`
  * `i += 2` to add 2 to the variable `i`
  * `i -= 3` subtracts 3 from `i`
  * `i *= 2` multiplies `i` by 2 (doubles it)
  * `i /= 3` divides by 3, BUT: it is *integer* division!

## While Loops

* A while loop uses the keyword `while`
* Main difference: the three elements are separated, giving you a big more "control"
* It is a little bit more flexible: you can place the increment anywhere in the loop
* If you don't though: infinite loop; kill it with control-C
* You cannot scope a counter/increment variable to restrict it to a while loop because it is declared *before* the while loop
* The *scope* of a variable is the section of code in which it lives or is valid or is visible
* In general it is best practice to limit the scope of a variable *as much as possible*

## Which Loop?

* Observation: any `while` loop can be rewritten as a `for` loop and vice versa
* Why two?
* In general: while loops are used when you *don't* know how many iterations (up front) it will run for (it depends on some variable or expression)
* Example: write a loop to compute the number of digits in an `int`: `12345` has 5 digits, `0` has one digit, `-123` has 3 digits

```java

		int n = 0;
		int original = n;
		int numDigits = 0;
		if(n == 0) {
			System.out.printf("%d has 1 digit(s)", original);
		} else {
			while(n != 0) {
				n /= 10;
				numDigits++;
			}
			System.out.printf("%d has %d digits", original, numDigits);
		}
```

* A `for` loop is good if you know how many iterations you're going for, `10` or even a variable: `n`

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

* No increment operation: infinite loop always prints 1


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

## Misc

### "Enhanced" For Loops (Java)

* a "for each" loop that allows you to iterate automatically over a collection (array, list, etc.)

```java
int primes[] = {2, 3, 5, 7, 11, 13, 17};
for(int x : primes) {
  System.out.println(x);
}
```

### Nested Loops

* You can "nest" a loop within another loop
* Inner loop and outer loop

```java
		int n = 1000;
		BigInteger counter = BigInteger.ZERO;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				//System.out.printf("%d, %d\n", i, j);
				counter = counter.add(BigInteger.ONE);
			}			
		}
		System.out.println("counter = " + counter);
```

* Be careful: generally nested loops are *inefficient*
* Sometimes they are necessary, but 3 or certainly more loops: *rehthink* what you are doing

## Exercises

1. Write a program to compute the arthmetic-geometric mean of two numbers

```c

    double x = 432.0;
    double y = 3892.0;

    double aCurrent, gCurrent, aPrevious, gPrevious;
    aCurrent = x;
    gCurrent = y;
    double epsilon = 0.0000000001;

    while( fabs(aCurrent - gCurrent) >= epsilon ) {
        aPrevious = aCurrent;
        gPrevious = gCurrent;
        aCurrent = .5 * (aPrevious + gPrevious);
        gCurrent = sqrt(aPrevious * gPrevious);
    }

    printf("agm(%f,%f) = %f\n", x, y, aCurrent);
```

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

```text









```
