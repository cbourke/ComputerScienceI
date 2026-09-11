
# CSCE 155E - Computer Science I
## Loops
### Fall 2026

* We need a way to repeatedly execute blocks of code
* There are four basic elements to a loop control structure:
  * An initialization statement: where the loop starts
  * A continuation condition (how long should the loop continue or when should it stop; or "termination condition")
  * An increment or "update" statement that makes *progress* toward the termination condition
  * Loop body: the code that executes for every *iteration* of the loop

# `for` loops

* It uses the keyword `for`
* All three conditions are on the same line: initialization, continuation, increment

```c
for(int i=1; i<=10; i++) {
    printf("i = %d\n", i);
}
```

* The initialization statement, `i=1` starts `i` at the value 1
* The continuation condition: `i<=10` and is checked at the *start* of the loop
  * if it evaluates to true: the loop body will execute
  * if it evaluates to false: the loop is done and normal control flow resumes after the loop
* The initialization statement is only ever executed ONCE before the loop starts
* The increment statement: `i++` is executed at the *end* of each loop
* New Syntax:
  * `i++` is the iterator operator and is short for `i = i + 1` (it just adds one to the variable `i`)
  * Having multiple ways of doing the same thing: syntactic sugar
  * Decrement operator: `i--` (subtracts 1 from the variable `i`)
  * Others are "compound assignment operators"
  * `i += 2` adds 2 to the variable i
  * `i -= 3` subtracts 3 from the variable `i`
  * `i *= 4` multiplies `i` by 4
  * `i /= 2` divides by 2 (careful: this results in integer division with integers)
* Observations:
  * Semicolons are at the end of the initialiation and continuation statements but NOT the increment statement!
  * In general, you should *limit* the scope of variables as much as possible to avoid unintended consequences or "side effects"
  * Is `i` a good variable name? In this case, it stands for **i**ndex or **i**ncrement; its an acceptable variable name: others `i, j, k`
* Style suggestions:
  * First, just be consistent!
  * No space between `for` and `(`
  * Space after `) {`
  * Closing curly bracket: aligned with the `f` in `for`
  * Use the same indentation for all levels: the loop body is indented

```c

    //prints: 0, 1, 2, ..., 9
    for(int i=0; i<10; i++) {
        printf("i = %d\n", i);
    }

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    //prints: 0, 2, 4, 6, 8
    for(int i=0; i<10; i+=2) {
        printf("i = %d\n", i);
    }

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    //prints: 3, 6, 9, 12, 15
    for(int i=3; i<=15; i+=3) {
        printf("i = %d\n", i);
    }

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    //prints: 10, 9, 8, 7, ..., 3, 2, 1
    for(int i=10; i>0; i--) {
        printf("i = %d\n", i);
    }

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-\n");

```

## While Loops

* While loops use the keyword `while`
* Main difference: the three elements (initialization, continuation, increment) are all on different lines

```c

    //prints 0, 1, ... 9
    int i = 0;
    while(i < 10) {
        printf("i = %d\n", i);
        i++;
    }

    //prints 1, ... 10
    int i = 0;
    while(i < 10) {
        i++;
        printf("i = %d\n", i);
    }
```

* The initialization occurs before the loop
* You CANNOT scope the index variable `i` to the loop itself, it MUST be declared before the loop
* The increment can be placed anywhere inside the `while` loop (it does not have to be the last thing like it is in a for loop)
* Failure to have a correct increment statement may lead to an *infinite loop*
* To kill the program use control-C

## Which Loop and when?

* Observation: any `while` loop can be rewritten as a `for` loop and vice versa
* We like having options: it makes language more flexible and usable and readable
* Generally:
  * For loops are *generally* used when you know how many iterations you want to execute for (fixed, `10` or variable `n`)
  * While loops are used when you *don't* know how many iterations you're going run

```c

  int n = 1234;
  int originalN = n;
  int numberOfDigits = 0;

  if(n == 0) {
    printf("Zero has 1 digit\n");
  } else {

    while(n != 0) {
      // divide the number by 10
      n /= 10;
      // increment a counter each time
      numberOfDigits++;
    }
    printf("n = %d has %d digits\n", originalN, numberOfDigits);
  }
```

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
* Control-C kills it
* Use the proper `-Wall` flag every time and it will catch this kind of stuff


* Consider the following code:

```c
int i = 0;
while(i < 10) {
  printf("%d\n", i);
}
```

* We forgot the increment operation: `i++`
* Result: infinite loop, no progress is made (always prints `0`)

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

### Nested Loops

* A loop within a loop is a "nested loop"
* There is an "outer" loop and an "inner" loop

```c

    int n = 10;
    int count = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("i, j = %d, %d\n", i, j);
            count++;
        }
    }
    printf("count = %d\n", count);
```

* This can be extremely inefficient
* If you have a nested loop: think is it *really* necessary (many times yes), but otherwise rethink what you are doing
* Small inputs may be okay but "large" inputs can take a LONG time.

### Do-While loops

* C supports `do-while` loops but you can safely ignore them

## Exercises

* Implement the classic FizzBuzz Problem
* YAGNI = You Ain't Gonna Need It

```text












```
