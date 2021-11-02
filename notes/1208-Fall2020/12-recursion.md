
# CSCE 155E - Computer Science I
## Recursion
### Fall 2020

* Motivating Demonstration: sum the elements of an array without using a loop!
* What is recursion?
* In general, *recursion* is something that references itself
* In coding, a function is recursive if it makes one or more calls to *itself*
* Mathematics: fractals
* Fibonacci Sequence

$$\begin{equation*}
    f(n) = \begin{cases}
               1               & n = 0\\
               1               & n = 1\\
               f(n-1) + f(n-2) & \text{otherwise}
           \end{cases}
\end{equation*}$$

Ex:
$$1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...$$

## Designing Recursive functions

* Every recursive function needs one or more *base cases* in which no further recursion is performed
* Some base cases may be for error handling
* You make one or more recursive calls that *must* make progress toward the base conditions

## Recursion: Good?

* Recursion *can* be a useful and "good" tool:
  * Many divide and conquer style algorithms that are presented (initially) as recursive algorithms
  * Many functional programming languages (Haskell, Scheme) use recursion as the "default" way of computing things
  * Recursion can also lead to "simple" or "clean" or "beautiful" code that is easily understood

## Recursion: Bad

* Recursive functions essentially abuse the stack space
* Risks for stack overflow for "deep" recursions
* You risk recomputing values over and over
* You risk a naive amount of *exponential* work

## Eliminating Recursion

* In general, recursion is not necessary
* You can take any recursive function (computable) and write equivalent code that either uses a loop or "simulates" recursion
* You can also use *memoization*
  * If you need to compute a recursive value, go ahead
  * If the value has not already been computed, "pay" for the recursion
  * BUT once you have computed the value, *store* it in a *cache*
  * The next time you need to compute the value, you *don't* pay for the recursion: you look it up in the cache

```c
int fibonacciMemoization(int n, int *table) {
  if(n < 0) {
    return 0;
  } else if(n <= 1) {
    return 1;
  } else if(table[n] > 0) {
    return table[n];
  } else {
    int a = fibonacciMemoization(n-1, table);
    int b = fibonacciMemoization(n-2, table);
    int result = (a + b);
    table[n] = result;
    return result;
  }
}
```


## Hack 12

* You'll compute how long it would take to compute binomial coefficients recursively
$${n \choose k} = \frac{n!}{(n-k)!k!} = {n-1\choose k } + {n-1 \choose k-1}$$
* read: n choose k
* it is the number of ways to choose k elements from a set of size n without consideration on the order


```text







```
