
# CSCE 155H - Computer Science I
## Recursion
### Fall 2022

* Motivating Demonstration: print a count down without a loop!
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

$$1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, \ldots$$

## Recursion Good?  Bad?

### Disadvantages

* You end up abusing the call stack to do your work.  The call stack is small and defenseless, don't abuse it
* Even moderately deep recursion risks stack overflow
* You risk redundant work: `fibonacci(10)` makes the same calls over and over again, recomputing the same values over and over
* You risk exponential time and overhead to do the recursion

### Advantages

* Many problem solving techniques or approaches are recursive in nature
* Divide & Conquer Techniques: adding up numbers, search & sorting, etc.
* It is a good way to think "inductively"
* Many functional programming languages use recursion as their basic structure
* Recursion can be "simple" or "clean" or "mathematical" or "beautiful" that is easily understood

## Designing Recursive functions

* Every recursive function needs one or more *base cases* (termination conditions in which no futher recursion is performed)
* Some base cases may perform basic error handling or corner cases
* Otherwise, you make one or more recursive calls to the same function
* Making sure to make *progress* toward one or more of your base cases
* The initial call to your recursive function is your initialization statement

## Eliminate Recursion

* Recursion can be bad/inefficient
* Some programming guides either discourage or prohibit recursion
* In general, any recursive function can be rewritten as an iterative solution!
* you can simulate recursion using an in-memory stack
* You can eliminate redundant work by using *memoization*
  * Instead of recomputing the same values over and over, you store them or *cache* them in memory in a table
  * Before you execute the recursion, you check the table: has this value been computed before?
  * If so: you don't make the recursive call
  * If not: pay for the recursion, BUT you then store it once computed


## Hack 12

  * You'll compute how long it would take to compute binomial coefficients recursively
      $${n \choose k} = \frac{n!}{(n-k)!k!} = {n-1\choose k } + {n-1 \choose k-1}$$
  * read: n choose k
  * $C(n,k) = C^n_k$
  * $C(n,k) = C(n-1,k) + C(n-1, k-1)$
  * it is the number of ways to choose k elements from a set of size n without consideration on the order
```text








```
