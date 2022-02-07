
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
while(i<=10) {
  printf("%d\n", i);
  i++;
}



```
