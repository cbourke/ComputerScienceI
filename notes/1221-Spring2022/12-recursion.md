
# ECEN 1940 - Computer Science I
## Recursion
### Spring 2022

* Motivating Demonstration: print a count down without a loop!
* What is recursion?
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

$$1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...$$

## Designing Recursive functions

* Every recursive function needs one or more *base cases* (termination conditions in which no futher recursion is performed)
* Some base cases may perform basic error handling or corner cases
* Otherwise, you make one or more recursive calls to the same function
* Making sure to make *progress* toward one or more of your base cases
* The initial call to your recursive function is your initialization statement

## Recursion: Good?

* Recursion *can* be useful or "good"
  * Many divide and conquer style algorithms are presented as "recursive"
  * It is a good way to think "inductively"
  * Many functional programming languages discourage or don't even have loop control structures!
  * Recursion can be "simple" or "clean" or "mathematical" or "beautiful" that is easily understood

## Recursion: Bad

* Recursive functions are essentially abusing the call stack and risk stack overflow
* You risk recomputing values over and over
* You risk an *exponential* amount of work which may not be feasible
* All of these considerations are *objective* measures of why recursion is "bad"

## Eliminate Recursion

* In general any computable recursive function can be rewritten with an iterative solution
* You can also use various techniques that you can take to eliminate recursion or to reduce its risks
  * You can use an in-memory stack
  * You can use "tail recursion": it allows a compiler to compile away the recursion and to "reuse" a stack frame
* You can use *memoization*
  * If you need to compute a value, go ahead and "pay" for the recursion
  * After computing the value, *store* it in a cache
  * The next time you need that value, you check the cache: if it has been computed before, you use it, otherwise, pay for the recursion

## Hack 12

* You'll compute how long it would take to compute binomial coefficients recursively
    $${n \choose k} = \frac{n!}{(n-k)!k!} = {n-1\choose k } + {n-1 \choose k-1}$$
* read: n choose k
* it is the number of ways to choose k elements from a set of size n without consideration on the order

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long fibonacciIterative(int n) {

  if(n <= 0) {
    return -1;
  } else if(n == 1 || n == 2) {
    return 1;
  } else {
    long prev = 1;
    long curr = 1;
    long next;
    for(int i=3; i<=n; i++) {
      next = curr + prev;
      prev = curr;
      curr = next;
    }
    return next;
  }

}

long fibonacciRecursive(int n) {

  if(n <= 0) {
    return -1;
  } else if(n == 1 || n == 2) {
    return 1;
  } else {
    return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
  }

}

//NOTE to self: fill the cache with "invalid" values, 0s initially
long fibonacci(int n, long *cache) {

  if(n <= 0) {
    return -1;
  } else if(cache[n] == 0) { //check the cache
    //if it is an invalid value (0), then :
    //1. pay for the recursion and compute it, but then
    long prev1 = fibonacci(n-1, cache);
    long prev2 = fibonacci(n-2, cache);
    long value = prev1 + prev2;
    //2. store it in the cache for future function calls...
    cache[n] = value;
    return value;
  } else {
    return cache[n];
  }
}

int main(int argc, char **argv) {

  int n = atoi(argv[1]);
  long *cache = (long *) malloc(sizeof(long) * (n+1));
  //fill the cache with "invalid" values...
  for(int i=0; i<=n; i++) {
    cache[i] = 0;
  }
  //set the base cases...
  cache[1] = 1;
  cache[2] = 1;
  long value = fibonacci(n, cache);
  printf("fib(%d) = %ld\n", n, value);

  return 0;

}
```


```text












```
