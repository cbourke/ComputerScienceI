
# CSCE 155H - Computer Science I
## Loops
### Fall 2024

* We need a way to repeatedly execute blocks of code
* There are four basic elements to a loop control structure:
  * An initialization statement: where the loop starts
  * A continuation condition (how long should the loop continue or when should it stop; or "termination condition")
  * An increment or "update" statement that makes *progress* toward the termination condition
  * Loop body: the code that executes for every *iteration* of the loop

## `for` Loops


* It uses the keyword `for`
* All three of the loop elements are on the same line: initialization, continuation, incremenet

```c
for(int i=0; i<10; i++) {
  printf("i = %d\n", i);
}
```

* Style:
  * opening bracket is on the same line
  * losing bracket is aligned with the `f` in `for`
  * Loop body is indented
  * Spacing: no space between `for` and `(`
* Syntax:
  * both the initializatoin and continuation are ended with semicolons!
  * The increment statement does not have a semicolon
* Other items:
  * `i++` is the increment operator, it *adds* one to the variable `i`
  * `i, j, k` are typically used as incremenet variables (short, `i`ndex, `i`ncremenet)
* Behavior:
  * The initialization is only executed once *before* the loop
  * THe update (increment) happens at the *end* of the loop
  * The continuation check is evaluated at the *start* of each loop
    * If it is true, the loop executes at least one more time
    * If it is false, then the loop terminates and normal linear control flow continues

### New Syntax

* `i++` adds one to the variable `i`
* You can use `++i` but why?  (prefix version)
* `i--` subtracts one from `i`
* `i += 2` this adds 2 to `i`
* `i -= 2` this subtracts 2 from `i`
* `i *= 2` this multiplies by 2 (doubles the value of `i`)
* `i /= 2` divides (truncation) by 2 (halves)

## While Loops

* A while loop uses the keyword `while`
* Main difference: the three elements (initialization, continuation, increment) are on separate lines

```c
int n = 10;
int i=0;
while(i < n) {
  printf("i = %d\n", i);
  i++;
}

```

* It is a little bit more flexible: you can place the increment anywhere in the loop
* If you don't though: infinite loop; kill it with control-C
* You cannot scope a counter/increment variable to restrict it to the while loop because it must be declared *before* the while loop
* In general it is best practice to limit the scope of a variable *as much as possible*

## Which Loop?

* Observation: any `while` loop can be rewritten as a `for` loop and vice versa
* Why multiple loops?
* We like flexibility in languages: we like them to be expressive, in code this is "syntactic sugar"

```c

    //compute the number of digits in the integer x
    int original = 123;
    if(original == 0) {
        printf("zero has 1 digit\n");
    } else {
        int x = original;
        int numDigits = 0;
        while(x != 0) {
            x /= 10;
            numDigits++;
        }
        printf("%d has %d digits\n", original, numDigits);
    }
```

* While loops are generally used when you dont' know how many iterations you are going to execute
* For loops are when you do know (up front) how many iterations you're going to execute

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
* Use proper `-Wall` flags to catch these things!

* Consider the following code:

```c
int i = 0;
while(i < 10) {
  printf("%d\n", i);
}
```

* No increment operation: infinite loop always prints 0



* Consider the following code:

```c
int i = 0;
while(i < 10)
  printf("%d\n", i);
  i++;
```



```text








```
