
# CSCE 155E - Computer Science I
## Recursion
### Fall 2026

* Challenge: print a count down without a loop!
* In general, *recursion* is something that references itself
* Mathematics: fractals are self-similar objects
* Fibonacci Sequence

$$\begin{equation*}
    f(n) = \begin{cases}
               1               & n = 1\\
               1               & n = 2\\
               f(n-1) + f(n-2) & \text{otherwise}
           \end{cases}
\end{equation*}$$

$$1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, \ldots$$

* In coding, a function is recursive if it makes one or more calls to itself

## Designing Recursive functions

* Every recursive function needs one or more *base cases* in which no further recursion is performed
  * Basically a stopping/termination condition
  * Some base cases may be for error handling
  * Generally, base cases are the *first* thing you do
* You make one or more recursive calls that *must* make progress toward the base conditions
* You get the recursion started by calling the function on an *initial value*

## Recursion: The Good


```text














```
