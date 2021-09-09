
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


```text





```
