
# CSCE 155H - Computer Science I
## Loops
### Fall 2023

* We need a way to repeatedly execute blocks of code
* There are four basic elements to a loop control structure:
  * An initialization statement: where the loop starts
  * A continuation condition (how long should the loop continue or when should it stop; or "termination condition")
  * An increment or "update" statement that makes *progress* toward the termination condition
  * Loop body: the code that executes for every *iteration* of the loop

## `for` Loops

* It uses the keyword `for`
* All three of the main elements are on the same line: intitialization, continuation, increment

```c
for(int i=1; i<=10; i++) {
  printf("i = %d\n", i);
}
```

* The initialization statement, `i=1` starts `i` at the value 1
* THe continuation condition is always checked at the start of a loop, if true, the loop executes one more time
* The increment condition is executed at the *end* of the loop
* New syntax:
  * `i++` adds one to the variable `i`
  * You *can* use: `++i` but really shouldn't (prefix version)
  * `i--` subtracts one from `i`
  * `i += 2` to add 2 to the variable `i`
  * `i -= 3` subtracts 3 from `i`
  * `i *= 2` multiplies `i` by 2 (doubles it)
  * `i /= 3` divides by 3, BUT: 
