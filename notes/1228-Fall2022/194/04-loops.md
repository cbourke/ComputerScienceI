
# ECEN 194 - Computer Science I
## Loops
### Fall 2022

* We need a way to repeatedly execute blocks of code
* There are four basic elements to a loop control structure:
  * An initialization statement: where the loop starts
  * A continuation condition (how long should the loop continue or when should it stop; or "termination condition")
  * An increment or "update" statement that makes *progress* toward the termination condition
  * Loop body: the code that executes for every *iteration* of the loop

```c
for(int i=0; i<10; i++) {
        printf("lap #%d\n", i);
    }

    printf("done\n");

    int i=0;
    while(i<10) {
        i++;
        printf("lap #%d\n", i);
    }

    printf("done\n");
```

* Demo: https://pythontutor.com/c.html#mode=edit

## For Loops

* The three main parts: initialization, continuation, and increment are all on the same line
  * The loop will continue to execute (another *iteration*) as long as the continuation condition evaluates to true
  * The continuation condition is evaluated at the *start* of an iteration
  * The increment is executed at the *end* of an iteration
  * The initialization is only ever executed once before the loop begins
* Syntax:
  * Use the keyword `for`
  * Semicolons end the initialization and continuation statements, but NOT the iteration
  * Note that the iteration variable, `i` is *declared within the loop structure*
  * The *scope* of `i` is limited to the for loop itself!
* New syntax: `i++` adds one to the variable `i`
  * `i--` subtracts 1 from the variable `i`
  * `i = i + 10;` can be rewritten as `i += 10;`
  * `i = i - 5;` can be rewritten as `i -= 5;`
  * `i = i * 2;` can be rewritten as `i *= 2;`
  * `i = i / 2;` can be rewritten as `i /= 2;`

## While loops

* While loops use the keyword `while`

```c
int i = 1;
while(i <= 10) {
  printf("i = %d\n", i);
  i++;
}
```

* Key differences:
  * The initialization happens *before* the loop
  * Consequence: you cannot have a loop-scoped variable
  * You have flexibility on where the increment occurs: *you* have to specify it in the loop body


## Zune

  * On December 31st, 2008 every zune froze for 24 hours
  * 2008 was a leap year
  * The following code was in a zune subsystem:

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
