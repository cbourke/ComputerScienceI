
# CSCE 155E - Computer Science I
## Loops
### Fall 2025

* We need a way to repeatedly execute blocks of code
* There are four basic elements to a loop control structure:
  * An initialization statement: where the loop starts
  * A continuation condition (how long should the loop continue or when should it stop; or "termination condition")
  * An increment or "update" statement that makes *progress* toward the termination condition
  * Loop body: the code that executes for every *iteration* of the loop

## `for` Loops

* It uses the keyword `for`
* All three of the main elements: initialization, continuation, increment are on the same line

```c
int n = 10;
for(int i=0; i<n; i++) {
    printf("i = %d\n", i);
}
```

* The initialization statement, `i=0` starts `i` at the value 0
* The continuation condition: `i<n` is checked at the *start* of the loop
  * If it is *true*, the loop body executes
  * If it is *false*, the loop body does not execute and control flow continues *after* the loop
* The initialization statement is only ever executed ONCE before the loop starts
* The increment statement: `i++` is executed at the *end* of each loop
* New Syntax:
  * `i++` is short for `i = i + 1` (it just adds one to the variable `i`)
  * You can also use `++i` (prefix version, but avoid)
  * `i--` decrements `i` by one (`i = i - 1`)
  * Others: compound assignment operators
  * `i += 2` is shorthand for `i = i + 2`
  * `i -= 2` is short hand for `i = i - 2`
  * `i *= 2` short hand for `i = i * 2` (doubles it)
  * `i /= 2` short hand for `i = i / 2` (careful with truncation)
* Observations:
  * Semicolons are at the end of the initialiation and continuation statements but NOT the increment statement!
  * In general, you should *limit* the scope of variables as much as possible to avoid unintended consequences or "side effects"
  * Is `i` a good variable name? It is probably not great, but okay.  Others: `i, j, k`
  * Note: we use `i` for **i**ncrement or **i**ndex

## While Loops

* While loops use the keyword `while`
* Main difference: the three elements (initialization, continuation, increment) are all on different lines


```c
int i = 0;
while(i < n) {
    printf("i = %d\n", i);
    i++;
}
```

* The initialization occurs before the loop
* You CANNOT scope the index variable `i` to the loop itself, it MUST be declared before the loop
* The increment (in this example) is placed at the end
* However: it doesn't have to be!  You can place the increment anywhere you want, beginning, end, middle somewhere
* Failure to have a correct increment statement may lead to an *infinite loop*
* To kill the program use control-C

## Which Loop?

* Observation: any `while` loop can be rewritten as a `for` loop and vice versa
* We like having options: it makes language more flexible and usable and readable
* Generally:
  * For loops are used when you know how many iterations you are going to execute
  * While loops are used when you *don't* know how many iterations you are going to execute

```c
int number = atoi(argv[1]);
const int originalNumber = number;

if(number == 0) {
    printf("Zero has one digit in it!\n");
    exit(0);
}

int numDigits = 0;
while(number != 0) {
    number /= 10;
    numDigits++;
}

printf("%d has %d digits in it \n", originalNumber, numDigits);
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

* Lack of testing
* You need to test all possible edge-cases or corner-cases

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

### FizzBuzz

```c
int n = 100;
for(int i=1; i<=n; i++) {
    if(i % 15 == 0){
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

### Car Loan Program

Compute a loan amortization table using a monthly payment formula:
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
