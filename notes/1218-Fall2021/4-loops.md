
# CSCE 155E - Computer Science I
## Loops
### Fall 2021

* We need a way to repeatedly execute blocks of code
* There are four basic elements to a loop control structure:
  * An initialization statement: where the loop starts
  * A continuation condition (how long should the loop continue or when should it stop; or "termination condition")
  * An increment or "update" statement that makes *progress* toward the termination condition
  * Loop body: the code that executes for every *iteration* of the loop

## For Loops

* The three main parts (intialization, the  continuationa and the increment) are all located on the same line:
* Semicolons are necessary on the first two, but NOT used on the third
* THe body is surrounded by opening/closing curly brackets

```c
for(int i=1; i<=10; i++) {
  printf("i = %d\n", i);
}

printf("done\n");
```

* In the above example, the *scope* of the increment variable `i` is *limited* to the loop itself.  It exists in the loop and for each *iteration* of the loop, but NOT after the loop
* THe `i=1` is the initialization, it only executes *once* before the loop executes
* THe continuation condition `i<=10` and is checked *before* the execution of each iteration (if false, the loop ends or terminates)
* The increment statement is executed at the *end* of the loop
* Observations:
  * The increment (`i++`) automatically is executed at the *end* of the loop
  * `i++` syntax adds one to the variable `i`
  * `i--` subtracts one from the variable `i`
  * Alternatively: `i = i + 1`
  * Alternatively: `i = i + 2` OR yoou can use a *compound* assignment operator: `i += 2`
  * Ex:
    * `i += 10;`
    * `i += a;` (adds whatever is stored in the variable `a` to `i`; "equivalent" to `i = i + a;`)
    * it works with `+, -, *, /`
    * `i *= 2` *mulitplies* `i` by 2
    * `i /= 2` *divides* `i` by 2 (take care with truncation)
  * By declaring `i` within the loop control structure, we *limit* its *scope* (the area of the code in which the variable exists or is "visible")

## While Loops

* While loops have a slightly different syntax: they use the keyword `while`

```c
int i = 1;
while(i <= 10) {
  printf("i = %d\n", i);
  i++;
}
```

Differences:
* all three elements are separated
* In general, a while loop is a bit more flexible
* Truth: any `for` loop can be rewritten as an equivalent `while` loop and vice versa
* The increment may be placed anywhere inside the loop body (so you are not restricted to it executing at the *end* of the loop)
* Generally the initialization occurs *before* the loop
* The continuation is still "bound" to the `while` keyword
* As long as the continuation condition is true, the while loop will execute at least one more time
* NO semicolon in the continuation condition
* The loop body is still denoted with curly brackets
* With a while loop, you *cannot* scope the iterator variable to the loop itself
* To kill a runaway program: control-C

```text








```
