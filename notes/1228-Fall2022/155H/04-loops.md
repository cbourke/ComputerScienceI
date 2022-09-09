
# CSCE 155H - Computer Science I
## Loops
### Fall 2022


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
for(int i=0; i<10; i++) {
  printf("i = %d\n", i);
}
```

* Semicolons are at the end of the initialization, continuation, but ***NOT*** the increment
* Observation: the increment statement is executed at the *end* of the loop
* Observation: the continuation condition is checked at the *start* of the loop
* Observation: the above syntax limits the scope of the iterator variable `i` to the loop itself!  It doesn't exist before or after the loop (this is a Very Good Thing)
* New Syntax:
  * `i++` adds one to the variable `i`
  * `i--` subtracts one from the variable `i`
  * `i += 10` adds 10 to the variable `i` ("equivalent" to `i = i + 10`)
  * `i -= 5` subtracts 5 from the variable `i`
  * `i *= 2` (doubles the value of i)
  * `i /= 2` divides by 2: *careful!*
  * You can use doubles: `i += 1.5`
* In general, you should avoid `double` variables as your increment variables

## While Loop

* The while loop uses the keyword `while`
* Main difference: all 3 parts are NOT on the same line:
  * The initialization happens before the loop
  * The continuation is associated with the `while` keyword
  * You have some flexibility on where the increment happens: you can place it at the start or the end or somewhere in the middle of the loop body
  * The continuation condition is still checked at the start of the loop
  * You *cannot* limit the scope a variable to the loop itself
* Infinite loops: kill it with control-C (C/VSCode), the stop button in eclipse

## Which Loop is Best?

* Observation: any for loop can be rewritten as an equivalent while loop and vice versa
* In general: you use a `for` loop when the number if iterations is known up front (it could be fixed 10 or variable, `n`)
* In general: you use a while loop when you *don't* know how many iterations are going to execute
* Example: write a loop to determine how many digits an integer has

```c
int n = atoi(argv[1]);
int numDigits = 0;
if(n == 0) {
  printf("Number of digits is 1\n");
  exit(0);
}
n = abs(n);
//divide by 10 until you hit zero
while(n > 0) {
  n /= 10;
  numDigits++;
}


printf("Number of digits is %d\n", numDigits);
```

## Nested Loops

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


## Enhanced For-Loops (Java)

* In Java if you have a collection (array or list) you can iterate over it using a for loop or you can use an "enhanced for loop" () (for each loop)

```java

		List<Integer> numbers = Arrays.asList(1, 2, 8, 4, 6, 3, 2);

		for(int i=0; i<args.length; i++) {
			//get the i-th element from args:
			String s = args[i];
			System.out.println(s);
		}

		for(String s : args) {
			System.out.println(s);
		}

		for(int i=0; i<numbers.size(); i++) {
			//get the i-th element from numbers:
			Integer x = numbers.get(i);
			System.out.println(x);
		}

		for(Integer x : numbers) {
			System.out.println(x);
		}
```

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

## Zune Bug


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
  $$\sum_{i=1}^{n} \frac{1}{i} = \frac{1}{1} + \frac{1}{2} + \frac{1}{3} + \cdots + \frac{1}{n}$$
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
