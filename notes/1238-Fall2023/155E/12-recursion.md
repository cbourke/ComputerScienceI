
# CSCE 155E - Computer Science I
## Recursion
### Fall 2023

* Challenge: print a count down without a loop!
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

## Recursion: The Good

* Recursion *can* be useful or "good"
  * many divide-and-conquer style algorithms are presented as recursive
  * It is a good way to think "inductively"
  * Many functional programming languages encourage or primarily use recursion (Haskell, Scheme, Lisp)
  * Recursion can also lead to "simple" or "clean" or "beautiful" code that is easily understood

## Recursion: The Bad

* You risk overflowing your stack with runaway recursion
* Even if it isn't runaway (infinite) then you are still abusing the call stack!  Which is *limited*
* You risk a naive *exponential* approach to a problem

## Eliminating Recursion

* Any recursive (code-wise) function can be rewritten as a non-recursive function!
* YOU can always use regular old loops and data structures to "simulate" recursion
* Another technique: tail recursion
* You can use *memoization*
  * You can use recursion, but...
  * You store (cache) results so that they are not *recomputed*
  * YOu store results into a table (cache)
  * When you need to compute a value:
    * Check the table/cache, if already computed, use it, no recursion
    * If not, then yeah, okay pay for the recursion
    * After computing it, *store* it in your table
* Example: use memoization to compute the fibonaccci numbers

## More Exercises

* Sum up numbers in an array using recursion
  * Strategy A: Decrease & Conquer
  * Strategy B: Divide & Conquer


```c








```
