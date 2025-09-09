
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

```text












```
