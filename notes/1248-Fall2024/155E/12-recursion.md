
# CSCE 155E - Computer Science I
## Recursion
### Fall 2024

* Challenge: print a count down without a loop!
* Demo
* In general, *recursion* is something that references itself
* In coding, a function is recursive if it makes one or more calls to itself
* Mathematics: fractals are self-similar objects
* Fibonacci Sequence

$$\begin{equation*}
    f(n) = \begin{cases}
               1               & n = 1\\
               1               & n = 2\\
               f(n-1) + f(n-2) & \text{otherwise}
           \end{cases}
\end{equation*}$$

$$1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, \ldots $$

## Designing Recursive functions

* Every recursive function needs one or more *base cases* in which no further recursion is performed
  * Some base cases may be for error handling
* You make one or more recursive calls that *must* make progress toward the base conditions
* You get the recursion started by calling the function on an *initial value*

* You've seen this before!  Loops!
* Base Case ~= continuation/termination condition
* Progress toward a base case ~= making progress toward a terminating condition in a loop
* Initial value ~= loop staring point

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

Number of calls:
* `fib(5)` = 1
* `fib(4)` = 1
* `fib(3)` = 2
* `fib(2)` = 3
* `fib(1)` = 5

* A blind recursive version of this makes *trillions* of function calls
* An *exponential* amount of work! $1.6^n$
* *most* of the work is *repeated*: the same values are computed over and over and over

## Eliminating Recursion

* You can *always* use a regular old loop and data structures to "simulate" recursion
* Another technique: tail recursion (eliminates multiple stack frames): the compiler can optimize your recursive code away and use only one stack frame
* You can use *memoization*
  * Go ahead and use recursion, but...
  * You *don't* recompute previously computed values
  * You *cache* (store) results so you can reuse them
* You can use *memoization*
  * Maintain a *table* or *cache* of results (*tableau*)
  * Initially: it will hold dummy values indicating "not yet computed"
  * IF not computed: use recursion to compute and then *store* it back into the table
  * Look it up: if computed already, the value will be used: pay for the recursion when we have to, but we don't pay when we don't have to


```c
/**
 * Demonstration code.
 *
 */
#include <stdio.h>
#include <stdlib.h>

long fibonacci(int n, long *values) {

    if(n < 0) {
        return -1;
    } else if(n == 1 || n == 2) {
        return 1;
    } else {
        //1.check to see if the value has already been computed
        if(values[n] != -1) {
            return values[n];
        } else {
            // if no: then
            //.   a. compute it
            long x = fibonacci(n-1, values) + fibonacci(n-2, values);
            //.   b. store it, then return it
            values[n] = x;
            return x;
        }
    }
}

int main(int argc, char **argv) {

    int n = atoi(argv[1]);
    //table of values:
    long *values = (long *) malloc( sizeof(long) * (n+1) );
    //initialize my table:
    for(int i=0; i<n+1; i++) {
        values[i] = -1;
    }
    //base cases:
    values[1] = 1;
    values[2] = 1;

    long result = fibonacci(n, values);
    printf("fib(%d) = %ld\n", n, result);

    return 0;
}

```
```text











```
