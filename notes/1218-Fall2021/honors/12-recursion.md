
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
