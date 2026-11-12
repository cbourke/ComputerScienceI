
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

## Recursion: The Good

* Recursion can be useful or "good"
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
  * You *don't* repeat previously computed values
  * You *cache* or store them in a (array, list, map)
  * Maintain a table or "tableau" or cache of computed values
  * Initially: these will all hold dummy values: not yet computed
  * You make a function call: if the value has already been computed (in the cache) then you use it
  * Otherwise: You "pay" for the recursion and compute it recursively, BUT you then cache the result
  * Look it up: if computed already, the value will be used: pay for the recursion when we have to, but we don't pay when we don't have to

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "book.h"

void countDown(int n) {

    if(n < 0) {
        printf("ERROR\n");
    } else if(n == 0) {
        //base case
        //termination/continuation condition
        printf("Blast Off!\n");
    } else {
        printf("%d\n", n);
        //progress toward terminating condition:
        //iteration
        countDown(n-1);
    }
}

int fibonacci(int n) {

    if(n < 1) {
        return -1;
    } else if(n == 1 || n == 2) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

long fibonacciMemoization(int n, long *values) {

    if(n < 1) {
        return -1;
    } else {
        if(values[n] != 0) {
          return values[n];
        } else {
            long a = fibonacciMemoization(n-1, values);
            long b = fibonacciMemoization(n-2, values);
            long c = a + b;
            values[n] = c;
            return c;
        }
    }
}

int main(int argc, char **argv) {

    int n = 45;
    long *values = (long *) malloc( sizeof(long) * (n+1) );
    for(int i=0; i<=n; i++) {
        values[i] = 0;
    }
    values[1] = 1;
    values[2] = 1;
    int fib = fibonacciMemoization(n, values);
    printf("fib(%d) = %d\n", n, fib);
    printf("longs are %d\n", sizeof(long));
    return 0;
}

```

```java
package unl.soc;

import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;

public class Demo {

	public static BigInteger fibonacci(int n, Map<Integer, BigInteger> values) {

		if (n < 1) {
			return BigInteger.ZERO;
		} else {
			if (values.containsKey(n)) {
				return values.get(n);
			} else {
				BigInteger a = fibonacci(n - 1, values);
				BigInteger b = fibonacci(n - 2, values);
				BigInteger c = a.add(b);
				values.put(n, c);
				return c;
			}
		}
	}

	public static void main(String[] args) {

		Map<Integer, BigInteger> values = new HashMap<>();
		values.put(1, BigInteger.ONE);
		values.put(2, BigInteger.ONE);
		int n = 10000;
		BigInteger result = Demo.fibonacci(n, values);
		System.out.printf("fib(%d) = %s\n", n, result);

	}

}
```

$${n \choose k} = \frac{n!}{(n-k)!k!}$$

$n = 5$: 5 people
$k = 2$: the number of ways of choosing 2 of the five to form pair

```text











```
