
# CSCE 155H - Computer Science I
## Recursion
### Fall 2024

* Challenge: print a count down without a loop!
* Print 10, 9, 8, 7, ..., 1, Blast Off!
* no loops
* no hardcoding!

* In general, *recursion* is something that references itself
* Mathematics: fractals are self-similar objects
* Fibonacci Sequence

$$\begin{equation*}
    f(n) = \begin{cases}
               1               & n = 1\\
               1               & n = 2\\
               f(n-1) + f(n-2) & \text{otherwise}
           \end{cases}
\end{equation*}$$

$$1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, \ldots$$


* In coding, a function is recursive if it makes one or more calls to itself

## Designing Recursive functions

* Every recursive function needs one or more *base cases* in which no further recursion is performed
  * Some base cases may be for error handling
* You make one or more recursive calls that *must* make progress toward the base conditions
* Initialization: you have to make the initial call to a recursive function

## Recursion: The Good

* Recursion *can* be useful or "good"
  * Many divide-and-conquer algorithms are presented recursively
  * It is a good way to think "inductively"
  * Many functional programming languages encourage or primarily use recursion (Haskell, Scheme, Lisp)
  * Recursion can also lead to "simple" or "clean" or "beautiful" code that is easily understood

## Recursion: The Bad

* You risk overflowing your stack with runaway recursion
* Even if it isn't runaway (infinite) then you are still abusing the call stack!  Which is *limited*
* Most/all recursion can be rewritten as a regular loop or you *simulate* the recursion
* You risk a naive *exponential* approach to a problem

## Eliminating Recursion

* You can always rewrite a recursive function using a regular old loop:
* You can always "simulate" recursion using an in-memory stack
* Another technique: tail recursion
* You can use *memoization*
  * also called "caching"
  * Go ahead and use recursion, but...
  * Once a value is computed, *store* it in a table/tableau and the next time you need it, don't recompute it, instead use the value stored in the table
* Basic Steps:
  * Maintain a table full of values
  * Initialize the table with the base cases
  * We'll call a recursion function passing in the table
  * If the table contains a value, we use it, otherwise...
  * We pay for the recursion and compute the value, but then
  * *store* the value for future use

```c
/**
 * Demonstration code template.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

long fibonacci(int n, long *values) {
    if(n < 1) {
        return -1;
    } else if(n == 1 || n == 2) {
        return 1;
    } else {
        if(values[n] != -1) {
            //already computed, just use it:
            return values[n];
        } else {
            //not yet computed, pay for it...
            long x = fibonacci(n-1, values) + fibonacci(n-2, values);
            //cache it:
            values[n] = x;
            //return it:
            return x;
        }
    }
}


int main(int argc, char **argv) {

    int n = atoi(argv[1]);

    long *values = (long *) malloc( sizeof(long) * (n + 1) );
    //initialize all the values with a flag value to indicate "not computed"
    for(int i=0; i<n+1; i++) {
        values[i] = -1;
    }
    //initialize the base cases:
    values[1] = 1;
    values[2] = 1;

    long result = fibonacci(n, values);
    printf("fib(%d) = %ld\n", n, result);

    char foo[10];
    int x = snprintf(foo, 10, "Hello World how are you?");
    printf("%d\n", x);

    return 0;
}

```

```text






```
