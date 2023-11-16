
# CSCE 155H - Computer Science I
## Recursion
### Fall 2023

* Challenge: print a count down without a loop!
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
* Most/all recursion can be rewritten as a regular loop or you *simulate* the recursion
* You risk a naive *exponential* approach to a problem

## Eliminating Recursion

* YOU can always use regular old loops and data structures to "simulate" recursion
* Another technique: tail recursion
* You can use *memoization*
  * Go ahead and use recursion, but...
  * Don't *recompute* previously computed values: store them or *cache* them
  * Basic Steps:
    * Maintain a *table* or *cache* of values
    * Iniitally: it will hold dummy values to indicate "not yet computed"
    * Look it up: if computed already, use it; else: pay for the recursion, BUT cache the result!

## Java Memoization using a Map

```java

	// n => f(n)
	public static final Map<Integer, BigInteger> values = new HashMap<>();

	public static BigInteger fibonacci(int n) {

		if (n == 1 || n == 2) {
			return BigInteger.ONE;
		} else {
			// 1. check if already computed; if so , use it (return it)
			if (values.containsKey(n)) {
				return values.get(n);
			} else {
				BigInteger a = fibonacci(n - 1);
				BigInteger b = fibonacci(n - 2);
				BigInteger result = a.add(b);
				values.put(n, result);
				return result;
			}
		}
	}

	public static void main(String args[]) {

		int n = 10000;

		BigInteger result = fibonacci(n);
		System.out.println(result);
	}
```

```text








```
