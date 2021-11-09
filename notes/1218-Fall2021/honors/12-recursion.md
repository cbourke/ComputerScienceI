
# CSCE 155H - Computer Science I
## Recursion
### Fall 2021

* Motivating Demonstration: do a count down without a loop
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

$$1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...$$


## Designing Recursive functions

* Every recursive function needs at least one or more *base cases*: a condition in which no further recursion is performed
* Some base cases may be for error handling
* You make one or more recursive calls to the same function, BUT you need to make sure your recursive calls are *making progress* toward a base case!

## Recursion: Good?

* Recursion *can* be a useful and "good" tool:
  * Many divide and conquer style algorithms initially use recursion to solve a problem
  * Many functional programming languages (Haskell) use recursion as the "default" way of computing things
  * Recursion can also lead to "clean" or "Beautiful" or "easily understood" code

## Recursion: Bad

* Recursive function essentially abuse the stack: you're always risking a stack overflow
* You risk recomputing values over and over
* You risk naively doing an exponential amount of work

## Eliminating Recursion

* In general recursion is not necessary
* You can "simulate" recursion using an in-memory stack
* You can (in general) take any recursive function and rewrite it to an equivalent non-recursive solution
* Tail recursion: the compiler can optimize away all your functions calls
* Memoization
  * If you need to make a computation, pay for the recursion
  * BUT, store it (*cache* it) so that if you need again, you resuse it
  * When you need a value, you first check the cache, if it has been computed, use it, otherwise (again) pay for the recursion

```text





```
