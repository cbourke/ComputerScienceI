
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
* Best practice: limit the scope of variables as much as possible
* Observations:
  * The increment (`i++`) automatically is executed at the *end* of the loop
  * The `i++` adds one to the variable `i`
  * You *may* see `++i` which has the same effect but a different "value" (forget about it for now)
  * `i--` subtracts one from the variable `i`
  * `i += 2` equivalent to `i = i + 2` (adds 2 to the variable `i`)
  * `i -= 3` subtracts 3 from `i`
  * `i *= 2` doubles (times two) the value in `i`
  * `i /= 3` divides `i` by 3 using *integer division*
  * Ex: `i = 10`

## While Loops

* While loops use the keyword `while`

```c

  int n = 10;

  int i=0;
  while(i<n) {
    printf("i = %d\n", i);
    i++;
  }
```
Differences:
* all three elements are separated
* In general, a while loop is a bit more flexible
* You have a bit more control over where the increment is placed
* With a `for`-loop you can limit the scope of your iterator/increment variable but with a `while` loop you can't
* Generally the initialization occurs *before* the loop
* The continuation is still "bound" to the `while` keyword
* As long as the continuation condition is true, the while loop will execute at least one more time
* Syntax:
  * There is no semicolon at the end of the continuation condition
  * The loop body is still denoted with curly brackets
  * REmember: to kill a program you use control-C

### For vs While Loops

* Observation: any while loop can be rewritten as an equivalent for loop and vice versa
* In general:
  * Use a `for` loop when you know (up front) how many iterations (either say 10 iterations or `n` iterations) you will execute the loop for
  * Use a `while` loop when you *don't* know how many iterations it will go (it depends on a value or variable or some other condition)
* Write a program to compute the number of digits in an integer

```c

    if(argc != 2) {
        printf("ERROR: You need to provide an integer\n");
        exit(1);
    }

    int n = atoi(argv[1]);
    int originalValue = n;
    int numDigits = 0;

    if(n == 0) {
        printf("0 has 1 digit\n");
    } else {

        while(abs(n) > 0) {
            n /= 10;
            numDigits++;
        }
        printf("%d has %d digits\n", originalValue, numDigits);
    }
```

### Nested Loops

* You can have a loop inside a loop
* we refer to them as the outer loop and the inner loop

```c
    int n = 10;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("i, j = %d, %d\n", i, j);
            counter++;
        }
    }
```

* But: avoid this at all costs; certainly 3 or more nested loops: really rethink what you are doing

## Common Pitfalls

```text








```
