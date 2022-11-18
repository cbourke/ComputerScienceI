
# CSCE 155E - Computer Science I
## Recursion
### Fall 2022

* Motivating Demonstration: print a count down without a loop!
* What is recursion?
* In general, *recursion* is something that references itself
* In math: fractals and fractal art
* Code: a function is recursive if it makes one or more calls to itself
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

* Every recursive function needs at least one or more *base cases*
* A base case is a single return statement such that no additional recursive calls are made
* Otherwise, you make one or more recursive calls to the same function
* However, each recursive call *must* make some *progress* toward the base case
* The initial call to your recursive function is your initialization statement

## Recursion: Good?  Bad?  Ugly?

* Recursion *can* be a good or useful thing
  * Often many divide and conquer style algorithms/problem solving approaches can be recursive
  * It is a good way to think "inductively"
  * Many functional programming languages discourage or don't even have loop control structures!
  * Recursion can be "simple" or "clean" or "mathematical" or "beautiful" that is easily understood

* Recursion can be bad (or very bad):
  * Deep recursion risks stack overflow
  * You risk recomputing the same values over and over
  * Ultimately, you are abusing the stack space: there is a non-trivial overhead in recursion that is not present with regular loops
  * You risk an *exponential* amount of work which may not be feasible
  * These are all *objective* measures

## Eliminate Recursion

* In general, any computable recursive function can be rewritten as an iterative algorithm
* You don't really *need* recursion in order to compute anything
* You can always *simulate* recursion using an in-memory stack
* Tail recursion can eliminate the inefficient stack frame usage
* You can use *memoization* to reduce the amount of recomputation
  * If you need to compute a value, go ahead and "pay" for the recursion
  * BUT: you store the result into a table or "cache"
  * If you ever need to recompute the result: you first check the cache; if it has already been computed, reuse it!
  * After you have computed it, be sure to store it in the cache!

```text










```
