
# CSCE 155E - Computer Science I
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
* All three of the main elements: initialization, continuation, increment are on the same line

```c
for(int i=1; i<=10; i++) {
  printf("i = %d\n", i);
}
```

* The initialization statement, `i=1` starts `i` at the value 1
* The continuation condition: `i<=10` is checked at the *start* of each iteration of the loop
  * IF it is true, the loop body executes
  * If it is false, we break out of the loop and continue with normal linear control flow
* The initialization statement is only ever executed ONCE before the loop starts
* THe increment is executed at the *end* of the loop
* New Syntax:
  * `i++` is short hand for `i = i + 1`
  * YOu can also use `++i` (prefix version)
  * `i--` decrements `i` by one (`i = i - 1`)
  * Others: compound assignment operators
  * `i += 2` is short hand for `i = i + 2`
  * `i -= 2` is short hand for `i = i - 2`
  * `i *= 2` short hand for `i = i * 2` (doubles the value)
  * `i /= 2` short hand for `i = i / 2` (careful with truncation)
* Observations:
  * Semicolons are at the end of the initialiation and continuation statements but NOT the increment statement!
  * In general, you should *limit* the scope of variables as much as possible to avoid unintended consequences or "side effects"
  * Note: we use `i` for **i**ncrement or **i**ndex

## While Loops

* While loops use the keyword `while`
* Main difference: the three elements (initialization, continuation, increment) are all on different lines

```c
int n = 10;
int i=0;
while(i < n) {
  printf("i = %d\n", i);
  i++;
}
```

* The initialization occurs *before* the loop
* The continuation is bound within parentheses on the while loop
* The increment (in this example) is placed at the end
* BUT: it doesn't have to be: you can place the increment statement anywhere in the loop
* Failure to have a correct increment statement may lead to an *infinite loop*
* To kill the program use control-C

## Which Loop?

* Observation: any `while` loop can be rewritten as a `for` loop and vice versa
* We like having options: it makes language more flexible and usable and readable
* Generally:
  * For loops are used when you know how many iterations you are going to execute
  * WHile loops are used when you *don't* know how many iterations you are going to execute
* There are also `do-while` loops that have their continuation condition checked at the *end* of the loop instead (omitted: brittle)
* Other languages have other types of loops: foreach loops or parallelized loops

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
* Use the proper `-Wall` flag everytime and it will catch this kind of stuff

* Consider the following code:

```c
int i = 0;
while(i < 10) {
  printf("%d\n", i);
}
```


```text








```
