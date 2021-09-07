
# CSCE 155H - Computer Science I
## Loops
### Fall 2021

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
for(int i=1; i<=10; i++) {
  printf("i = %d\n", i);
}
```
