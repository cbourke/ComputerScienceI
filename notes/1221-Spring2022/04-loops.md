
# ECEN 1940 - Computer Science I
## Loops
### Spring 2022

* We need a way to repeatedly execute blocks of code
* There are four basic elements to a loop control structure:
  * An initialization statement: where the loop starts
  * A continuation condition (how long should the loop continue or when should it stop; or "termination condition")
  * An increment or "update" statement that makes *progress* toward the termination condition
  * Loop body: the code that executes for every *iteration* of the loop

```c
for(int i=1; i<=10; i++) {
  printf("%d\n", i);
}

int i=1;
while(i <= 10) {
  printf("%d\n", i);
  i++;
}

```

* Demo: https://pythontutor.com/c.html#mode=edit

## For Loops

* The three main parts: initialization, continuation, and increment are all on the same line
* The loop will continue to execute as long as the continuation condition evaluates to true
* When it evaluates to false (termination condition) the loop ends and normal control flow continues after
* Syntax:
  * Use the keyword `for`
  * Semicolons end the initialization and continuation, but NOT the increment statement
  * The body is surrounded by curly brackets and its contents are indented one level
* Declaring the *index* variable inside the `for`-loop *scopes* it to that loop only
  * Scope: the *scope* of a variable is the segment of code in which it "lives" or is valid
  * By limiting it, the index variable only exists *in* the for loop, not before nor after
  * In general, it is best to limit the scope of all variables as much as possible
* Observations:
  * New syntax: `i++` adds one to the variable `i`
  * called the increment operator
  * "equivalent" to `i = i + 1` (ie it has the same effect)
  * You can also use the decrement operator: `i--`
  * You can also use compound assignment operators to add/subtract/multiply/divide by a constant
  * `i = i + 5;` can be rewritten `i += 5;`
  * `i = i - 10;` can be rewritten `i -= 10;`
  * `i = i * 2;` can be rewritten as `i *= 2;`
  * Division too: `i /= 2;` (ie integer truncation is possible!)

## While Loops

* While loops use the keyword `while`

```c
int i = 1;
while(i <= 10) {
  printf("i = %d\n", i);
  i++;
}
```

* Initialization statement: before the loop!
* Continuation statement: tied to the `while` keyword
* Body: again surrounded by curly brackets
* Increment: done (typically) at the end of the loop
* Difference: you cannot scope an "index" variable to be limited to the while loop

### For vs While Loop

* Any for loop can be rewritten as an equivalent while loop and vice versa
* It is generally "natural" to use a for loop when you know up front (apriori) how many iterations you will execute
* It is more 'natural" to use a while loop when the number of iterations is not known up front

```c

    //given a number n, output how many digits are in it...
    int n = 0;
    int originalValue = n;
    n = abs(n);

    int numDigits = 0;
    if(originalValue == 0) {
        numDigits = 1;
    } else {
        while(n > 0) {
            n /= 10;
            numDigits++;
        }
    }

    printf("%d has %d digits\n", originalValue, numDigits);
```

### Nested Loops

* You can have a loop inside a loop
* We refer to them as the outer loop, inner loop
* You can do this as many times as you want, but avoid 3 or more nested loops

```c
int n = 10;

for(int i=0; i<n; i++) {
  for(int j=0; j<n; j++) {
    printf("i, j = (%d, %d)\n", i, j);
  }
}
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
  $$\sum_{i=1}^{n} \frac{1}{i}$$
3. Write a program to compute the arthmetic-geometric mean of two numbers
   See https://en.wikipedia.org/wiki/Arithmetic%E2%80%93geometric_mean
4. Compute a loan amortization table using a monthly payment formula:
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
```

```text










```
