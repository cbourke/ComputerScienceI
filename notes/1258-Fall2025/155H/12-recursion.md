
# CSCE 155H - Computer Science I
## Recursion
### Fall 2025

* Challenge: print a count down without a loop!
* Print 10, 9, 8, 7, ..., 1, Blast Off!
* no loops
* no hardcoding!
* In general, *recursion* is something that references itself
* Mathematics: "fractals"
* Fibonacci Sequence

$$\begin{equation*}
    f(n) = \begin{cases}
               1               & n = 1\\
               1               & n = 2\\
               f(n-1) + f(n-2) & \text{otherwise}
           \end{cases}
\end{equation*}$$

$$1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, \ldots$$

* In coding, a function is recursive if it makes one or more calls to itself

## Designing Recursive functions

* Every recursive function needs one or more *base cases* in which no further recursion is performed
  * Some base cases may be used for error handling
  * Base cases generally come *first* in the function
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


```text











```
