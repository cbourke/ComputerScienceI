
# CSCE 155H - Computer Science I
## Recursion
### Fall 2026

* Challenge: print a count down without a loop!
* Print 10, 9, 8, 7, ..., 1, Blast Off!
* no loops
* no hardcoding!
* In general, *recursion* is something that references itself
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


```text











```
