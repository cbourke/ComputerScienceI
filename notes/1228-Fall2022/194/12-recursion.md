
# ECEN 194 - Computer Science I
## Recursion
### Fall 2023

* Motivating Demonstration: print a count down without a loop!
* In general, *recursion* is something that references itself
* Mathematics: fractals are self-similar objects
* In coding, a function is recursive if it makes one or more calls to itself
* WIth loops there are three parts:
  * Initialization: the first call to your recursive function
  * Continuation/termination: your "base case" in the recursive function (the condition by which you make no more function calls)
  * Increment: each recursive call must make progress toward the base case
* Fibonacci Sequence

  $$\begin{equation*}
      f(n) = \begin{cases}
                 1               & n = 1\\
                 1               & n = 2\\
                 f(n-1) + f(n-2) & \text{otherwise}
             \end{cases}
  \end{equation*}$$

$$1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, \ldots$$

## Recursion: Good?  Bad?

### Advantages

* Many problem solving techniques or approaches are recursive in nature
  * Divide and conquer style algorithms
* Recursion allows you to think "inductively" or more mathematical
* Many functional programming languages use recursion as their basic structure
* Recursion can be "simple" or "clean" or "mathematical" or "beautiful" that is easily understood

### Disadvantages

* You end up abusing the call stack to do your work.  This risks stack overflow
  * Many organizations (NASA) prohibit the use of blind recursion in their code
* You risk redundant work: `fibonacci(10)` makes the same calls over and over again, recomputing the same values over and over
* You risk exponential time and overhead to do the recursion

## Designing Recursive functions

* Every recursive function needs one or more *base cases* (termination conditions in which no futher recursion is performed)
* Some base cases may perform basic error handling or corner cases
* Otherwise, you make one or more recursive calls to the same function
* Making sure to make *progress* toward one or more of your base cases
* The initial call to your recursive function is your initialization statement

## Eliminate Recursion

* Any recursive function can be rewritten as a non-recursive iterative algorithm
* You can always "simulate" recursion using an in-memory stack
* You can eliminate redundant work using *memoization*
  * IF you need to compute a value that has not already been computed, you go ahead and pay for the recursion
  * Then once the value is computed, you *store* it or *cache* it in a table/array so that
  * The next time you need the value, you check: is it already computed, if so, use it and do not (re)pay for the recursion

## Hack 12

* You'll compute how long it would take to compute binomial coefficients recursively
  $${n \choose k} = \frac{n!}{(n-k)!k!} = {n-1\choose k } + {n-1 \choose k-1}$$
    * read: n choose k
    * $C(n,k) = C^n_k$
    * $C(n,k) = C(n-1,k) + C(n-1, k-1)$
    * it is the number of ways to choose k elements from a set of size n without consideration on the order

## Demo Code

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

long fibonacciMemoization(int n, long *cache) {

  //if fibonacci(n) has already been computed, then reuse and return
  // the value
  //  cache[0] = ??  (ignore)
  //  cache[1] = fibonacci(1) = 1
  //  cache[2] = fibonacci(2) = 1
  //  cache[3] = fibonacci(3) = 2
  //
  //  cache[n] = fibonacci(n)
  //  a value of -1 indicates that it has not yet been computed

  if( cache[n] != -1 ) {
    return cache[n];
  } else {
    //else if fibonacci(n) has not already been computed, then
    //  1. pay for the recursion: compute it recursively
    //  2. store that value into your table/cache so that the next time
    //     you need it, you can use it.
    long a = fibonacciMemoization(n-1, cache);
    long b = fibonacciMemoization(n-2, cache);
    long result = a + b;
    //store the result in the cache:
    cache[n] = result;
    return result;
  }

}


long fibonacci(int n) {

  if(n < 1) {
    return -1;
  }

  if(n == 1 || n == 2) {
    return 1;
  } else {
    return fibonacci(n-1) + fibonacci(n-2);
  }

}


void countDown(int n) {

  if(n == 0) {
    printf("Blast Off!\n");
  } else {
    printf("%d\n", n);
    countDown(n-1);
  }

}
int main(int argc, char **argv) {


  int n = 1000000;
  long *cache = (long *) malloc( sizeof(long) * (n+1) );
  for(int i=0; i<n+1; i++) {
    cache[i] = -1;
  }
  cache[1] = 1;
  cache[2] = 1;
  long result = fibonacciMemoization(n, cache);
  printf("fib(%d) = %ld\n", n, result);

  return 0;
}
```

```text












```
