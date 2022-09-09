
# CSCE 155E - Computer Science I
## Loops
### Fall 2022

* We need a way to repeatedly execute blocks of code
* There are four basic elements to a loop control structure:
  * An initialization statement: where the loop starts
  * A continuation condition (how long should the loop continue or when should it stop; or "termination condition")
  * An increment or "update" statement that makes *progress* toward the termination condition
  * Loop body: the code that executes for every *iteration* of the loop


## For Loops

```c
for(int i=1; i<=10; i++) {
    printf("Lap #%d\n", i);
}
```

* For loops have the three main parts: initialization, continuation, the increment on the same line
* The loop body follows the `for` line with an opening and closing curly bracket
* Anything inside that loop body will execute *once* for every iteration
* Observations:
  * The initialization statement is only ever executed once before the first iteration of the loop
  * The continuation condition is checked at the beginning of the loop: if it is true, it executes one more time; if false, it "breaks out of the loop" (normal sequential control flow resumes)
  * The increment statement is executed at the *end* of each loop
  * What is the "scope" of the iterator variable `i`? It only exists for the loop/inside the loop; it does not exist after the loop
  * In general: scope your variables to as small of a scope as possible
  * Globals Are Evil
* Syntax Notes:
  * Semicolons end the initialization and continuation condition but ***NOT*** the increment statement
  * The loop body has opening/closing curly brackets
  * Style: opening bracket on the same line as the `for` keyword; closing is on the same indentation level as the `f`; the loop body is *indented*
* New Syntax:
  * `i++` is shorthand for "add one to the variable `i`"
  * `i--` is shorthand for "subtract one from `i`"
  * both can be rewritten as `i = i + 1` or `i = i - 1`
  * This is "syntactic sugar"
  * You an also use compound assignment operators:
    * `i = i + 10` can be shorthanded as `i += 10`
    * `i = i - 5` can be shorthanded as `i -= 5`
    * `i = 2 * i` can be shorthanded as `i *= 2`
    * `i = i / 2` can be shorthanded as `i /= 2` (careful: integer division)

## While Loop

* While loops use the keyword `while`

```c
int i = 1;
while(i <= 10) {
    printf("Lap #%d\n", i);
    i++;
}

printf("Done\n");
printf("i is now %d\n", i);
```

* Initialization statement: before the loop
* The continuation: same, tied to the `while` keyword
* Body: same: opening/closing curly brackets, indentation, etc
* Continuation condition: checked at the start of the loop (same)
* Increment statement: can be located anywhere you want (start, end or middle of the loop)
* You cannot scope a iterator variable to the loop itself
* Note: if you get into an infinite loop, you can kill the program with control-C

## Which one is better, For loop or while loop?

* Any for loop can be rewritten as a while loop and vice versa
* Why do we need two?
* In general: if you know how many iterations up front you are going to execute the loop, then you use a `for` loop
* If you don't know how many iterations up front, then use a `while`
* The difference is "natural"

```c

    //given a number x, compute how many digits are in it
    // ex: 1234 has 4 digits
    //     12345678 has 8 digits
    //     0 has 1 digit

    int x = -777;
    int numDigits = 0;
    if(x == 0) {
      printf("number of digits: 1\n");
      exit(0);
    }
    // divide by 10 until... it is zero
    //   keep a count of how many times you divide, that's the answer
    x = abs(x);
    while(x > 0) {
        x = x / 10;
        numDigits = numDigits + 1;
    }
    printf("number of digits: %d\n", numDigits);
```

### Nested Loops

* You can have a loop inside a loop
* We refer to them as the *outer loop* and the *inner loop*
* You can do this as many times as you want, but avoid 3 or more nested loops

```c
int n = 10;
long count = 0;
for(int i=0; i<n; i++) {
  for(int j=0; j<n; j++) {
    //printf("i = %d, j = %d\n", i, j);
    count++;
  }
}

printf("count = %ld\n", count);
```

* More nested loops is likely a *code smell*: not necessarily bad, but probably stinks!

## Pitfalls


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

1. Write a solution to FizzBuzz
2. Write a program to compute a sum of the (partial) harmonic series:
  $$\sum_{i=1}^{n} \frac{1}{i} = \frac{1}{1} + \frac{1}{2} + \frac{1}{3} + \frac{1}{4} + \cdots + \frac{1}{n}$$


```text









```
