
# CSCE 155H - Computer Science I Honors
## Recursion
### Fall 2020

* Motivating Demonstration: sum the elements of an array without using a loop!
* What is recursion? Anything that makes reference to itself!
* In coding, a recursive function is a function that makes one or more calls to itself
* Mathematics: fractals
* The classic "bad" example: Fibonacci sequence


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

## Recursion; Bad

* Recursive function essentially abuse the stack: you're always risking a stack overflow
* You risk recomputing values over and over
* You risk naively doing an exponential amount of work

## eliminating recursion

* In general recursion is not necessary
* You can, in general, take any computable recursive function and  create an equivalent non-recursive computation/algorithm
* You can "simulate" recursion using an in-memory stack
* you can use *memoization*
  * If you need to compute a value, go ahead and "pay" for the recursion
  * BUT, once computed, *store* the result into a table or *cache*
  * When you need to compute a value, look in the cache first: if it is already computed, use it!  Otherwise again pay for the recursion

## java


```text







```
