
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







