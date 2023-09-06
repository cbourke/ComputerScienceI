
# CSCE 155E - Computer Science I
## Loops
### Fall 2023

* We need a way to repeatedly execute blocks of code
* There are four basic elements to a loop control structure:
  * An initialization statement: where the loop starts
  * A continuation condition (how long should the loop continue or when should it stop; or "termination condition")
  * An increment or "update" statement that makes *progress* toward the termination condition
  * Loop body: the code that executes for every *iteration* of the loop

## `for` Loops

* The three main parts: initialization, continuation and increment are all on the same line
* Semicolons are necessary on the first two, but NOT used on the third
* THe body is surrounded by opening/closing curly brackets

```c
for(int i=1; i<=10; i++) {
  printf("i = %d\n", i);
}

printf("done\n");
```

* The *scope* of a variable is the area of code in which it exists or is visible or is valid
