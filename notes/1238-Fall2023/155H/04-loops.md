
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
* All three of the main elements are on the same line: intitialization, continuation, increment

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

```text









```
