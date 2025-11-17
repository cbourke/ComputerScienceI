
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

* You can *always* use a regular old loop and data structures to "simulate" recursion
* Another technique: tail recursion (eliminates multiple stack frames): the compiler can optimize your recursive code away and use only one stack frame
* You can use *memoization*
  * Go ahead and use recursion, but...
  * You *don't* recompute previously computed values
  * You *cache* (store) results so you can reuse them
  * Maintain a *table* or *cache* of results (*tableau*)
  * Initially: it will hold dummy values indicating "not yet computed"
  * IF not computed: use recursion to compute and then *store* it back into the table
  * Look it up: if computed already, the value will be used: pay for the recursion when we have to, but we don't pay when we don't have to

```java
package unl.soc;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.time.LocalDate;

public class Demo {

	public static Map<Integer, BigInteger> fibMap = new HashMap<>();

	static {
		fibMap.put(1, BigInteger.ONE);
		fibMap.put(2, BigInteger.ONE);
	}

	public static BigInteger fibonacci(int n) {
		if(n < 1) {
			throw new RuntimeException("Fibonacci is not defined for n < 1");
		} else if(n == 1 || n == 2) {
			return BigInteger.ONE;			
		} else {
			if(fibMap.containsKey(n)) {
				return fibMap.get(n);
			} else {
				BigInteger a = fibonacci(n-1);
				BigInteger b = fibonacci(n-2);
				BigInteger result = a.add(b);
				fibMap.put(n, result);
				return result;
			}
		}
	}

	public static void main(String[] args) {

		int n = 1000;
		BigInteger fib = fibonacci(n);
		System.out.printf("fib(%d) = %s\n", n, fib);

	}

}
```

```text











```
