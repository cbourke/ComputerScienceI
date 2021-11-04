
# CSCE 155E - Computer Science I
## Recursion
### Fall 2021

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

* Every recursive function needs one or more *base cases* in which no further recursion is performed
* Some base cases may be for error handling
* You make one or more recursive calls that *must* make progress toward the base conditions

## Recursion: Good?

* Recursion *can* be useful or "good"
  * Many divide and conquer style algorithms will be presented recursively
  * It is a good way to think "inductively"
  * Many functional programming lanaguages encourage or primarily use recursion (Haskell, Scheme, Lisp)
  * Recursion can also lead to "simple" or "clean" or "beautiful" code that is easily understood

## Recursion: Bad

* Recursive function are essentially abusing the call stack and risking stack overflow
* You risk recomputing values over and over
* You risk a naive *exponential* approach to a problem

## Eliminating Recursion

* In general any computable recursive function can be replaced with a iterative solution
* You can use various tricks to eliminate the additional functions including:
  * Using a stack
  * Using "tail recursion"
* You can use *memoization*
  * If you need to compute a value, go ahead and do so recursively, "paying" for the recursion
  * BUT: once you compute one value, STORE it (*cache* it) and save it for later
  * Before you do a subsequent recursive call, check your cache: if the value has already been computed and stored, use it, avoiding the recursive call!

## Hack 12

  * You'll compute how long it would take to compute binomial coefficients recursively
  $${n \choose k} = \frac{n!}{(n-k)!k!} = {n-1\choose k } + {n-1 \choose k-1}$$
  * read: n choose k
  * it is the number of ways to choose k elements from a set of size n without consideration on the order
```text




```
