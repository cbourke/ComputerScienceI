# CSCE 155E - Computer Science I
#### Recursion

* What is recursion?
* In general, *recursion* is something that references itself
* Example: fractals
* Fibonacci sequence:

$$\begin{equation*}
    f(n) = \begin{cases}
               1               & n = 0\\
               1               & n = 1\\
               f(n-1) + f(n-2) & \text{otherwise}
           \end{cases}
\end{equation*}$$

$$1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, \ldots$$


```c
void countDown(int n) {

  if(n == 0) {
    printf("blastoff!\n");
    return;
  } else if(n > 0) {
    printf("%d\n", n);
    countDown(n-1);
  }

}

countDown(10);
```

* IN the context of coding, recursion simply means when a function makes one or more calls to itself!

## Parts of Recursion

* Every recursive function needs at least one *base case*: a case in which no recursive calls are made: infinite recursion
* Each recursive function call should make progress towards the base case
* Corner cases may need to be handled separately (error handling)

## Recursion: Good?

* Recursion *can* be a "useful" and "good" tool:
  * Many divide and conquer algorithms are usually presented as recursive
  * Many functional programming languages require recursion or highly discourage the use of loops
  * Recursion can lead to "simple", "clean", "beautiful" code that is easily understood
  
## Recursion: Bad?

* Recursive function essentially abuse the stack space
* Risks stack overflow for "deep recursions"
* In general recursion is not needed: any recursive function can be rewritten as a non-recursive function using a loop or a stack, etc.
* Recursion can often be *simulated* using an in-memory stack
* Some organizations even BAN recursion (NASA)
* Recursion also risks needlessly recomputing values over and over and over

## Eliminating Recursion

* In general, you can always rewrite a recursive function
* You can also use *memoization*:
  * If you need to compute a value, you "pay" for the recursion
  * But, each value you compute: you save it (in table): ie you *cache* previously computed values
  * Demonstration: recompute the fibonacci sequence using memoization

## Hack 12

* You'll compute how long it would take to compute binomial coefficients recursively
* You'll replace recursive code with *memoization* code
* Given n elements, {a, b, c, d, ...} how many ways are there of choosing k of them?  (how many subsets of size k are there?)
* 



