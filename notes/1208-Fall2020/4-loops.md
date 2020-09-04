
# CSCE 155E - Computer Science I
## Loops
### Fall 2020

* We need a way to repeatedly execute blocks of code
* There are four basic elements to a loop control structure:
  * An initialization statement: where the loop starts
  * A continuation condition (how long should the loop continue or when should it stop; or "termination condition")
  * An increment or "update" statement that makes *progress* toward the termination condition 
  * Loop body: the code that executes for every *iteration* of the loop

## For Loops

* A for loop uses the keyword `for`
* All three elements (intialization, continuation, increment) are all located on the same line

```c
for(int i=1; i<=10; i++) {
  printf("i = %d\n", i);
}
```

* `int i=1` is the initialization statement: it creates (declares) a variable `i` (sometimes called an increment variable) and initializes its value to 1 (we start the loop at 1)
* NOTE: there is a semicolon at the end of the initialization statement!
* `i<=10` is the continuation condition: if it is true, the loop executes at least once more; if false, then we "break" out of the loop
* NOTE: there is a semicolon at the end of the continuation condition
* `i++` is an increment statement: it adds one to the variable `i`
* NOTE: there is NO semicolon at the end of the increment statement
* The loop body begins/ends with opening/closing curly brackets
* Observations:
  * The increment (`i++`) automatically is executed at the *end* of the loop
  * By declaring the variable `i` within the loop control structure, its *scope* (the area of code in which it lives or is "visible") is limited to the loop itself
  * Technical detail: older versions of C did not allow you to use this syntax, so you *may* need to compile with special flags:
  (CSE): `gcc -std=gnu99 -Wall foo.c`

## Incrementing operators

* `i++` simply adds one to the variable `i`
* `i--` subtracts one from the variable `i`
* Both are "equivalent" to using the assignment operator and plus/minus: `i = i + 1`
* You can also increment/decrement by values other than one:
  * `i += 4` adds 4 to the variable `i` "equivalent" to `i = i + 4`
  * `i -= 3` subtracts 3 from the variable `i`
  * `i *= 2` multiplies `i` by 2 (double the value stored in `i`)
  * `i /= 3` divides the value in `i` by 3 (beware truncation!)

## While Loops

* While loops have a slightly different syntax: they use the keyword `while`
* Main difference: all three elements are separated into different lines

```c
int i = 1;
while(i <= 10) {
  printf("i = %d\n", i);
  i++;
}
```

* The initialization occurs before the `while` loop statement
* The continuation condition is placed in parentheses next to the while loop
* The increment is done inside the while loop
* The increment occurs wherever *you* put it instead of at the end of the loop
* You have more control over when the increment occurs with a while loop
* The continuation is checked at the beginning of the while loop (same as for loops)

* Observation: any while loop can be rewritten as an equivalent for loop and vice versa

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

## Other Issues

### Nested Loops

* Often you can have loops within loops
* This is known as "nesting"

```c
int counter = 1;
for(int i=1; i<=10; i++) {
  for(int j=1; j<=10; j++) {
    printf("%3d : i = %d, j = %d\n", counter, i, j);
    counter++;
  }
}
```

### For loops vs while loops

* Fact: any for loop can be rewritten as a while loop and vice versa
* In general, use a `for` loop when you know  up front how many iterations you are going to go (10 iterations, 20 iterations or `n` iterations)
* In general, use a `while` loop when the number of iterations is *not* known up front (instead it depends on some value(s) that are changed in the loop)
* Example: write a loop to compute how many digits are in a number

```text






```