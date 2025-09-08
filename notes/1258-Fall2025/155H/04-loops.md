
# CSCE 155H - Computer Science I
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
* All three of the loop elements are on the same line: initialization, continuation, increment

```c
for(int i=0; i<10; i++) {
  printf("i = %d\n", i);
}
```

* Style:
  * opening bracket is on the same line
  * closing bracket is aligned with the `f` in `for`
  * loop body is indented
  * Spacing: no space between `for` and `(`
* Syntax:
  * both the initialization and continuation are ended with semicolons!
  * The increment statement does not have a semicolon
* Other items:
  * `i++` is the increment operator, it *adds* one to the variable `i`, "kinda like": `i = i + 1`
  * `i, j, k` are typically used as increment variables (short, `i`ndex, `i`ncremenet)
* Behavior:
  * The initialization is only executed once *before* the loop
  * The continuation check is evaluated at the *start* of each loop
    * If it is true, the loop executes at least one more time
    * If it is false, then the loop terminates and normal linear control flow continues
  * The increment is done at the *end* of the loop

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
int i = 0;
while(i < n) {
  printf("i = %d\n", i);
  i++;
}
```

* It is a little bit more flexible: you can place the increment anywhere in the loop
* If you don't though: infinite loop; kill it with control-C
 (or the stop button in Eclipse)
* You cannot scope a counter/increment variable to restrict it to the while loop because it must be declared *before* the while loop
* In general it is best practice to limit the scope of a variable *as much as possible*

## Which Loop?

* Observation: any `while` loop can be rewritten as a `for` loop and vice versa
* Why multiple loops?
* We like flexibility in languages: we like them to be expressive, in code this is "syntactic sugar"



```text













```
