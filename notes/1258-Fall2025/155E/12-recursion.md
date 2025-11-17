
# CSCE 155E - Computer Science I
## Recursion
### Fall 2025

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

$$1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, \ldots$$

## Designing Recursive functions

* Every recursive function needs one or more *base cases* in which no further recursion is performed
  * Basically a stopping/termination condition
  * Some base cases may be for error handling
  * Generally, base cases are the *first* thing you do
* You make one or more recursive calls that *must* make progress toward the base conditions
* You get the recursion started by calling the function on an *initial value*

## Recursion: The Good

* Recursion *can* be useful or "good"
  * Many divide-and-conquer algorithms are presented recursively
  * Sorting: I don't know how to sort $n = 100$ elements
  * It is a good way to think "inductively" (math-oriented thought)
  * Many functional programming languages encourage or primarily use recursion (Haskell, Scheme, Lisp)
  * Recursion can also lead to "simple" or "clean" or "beautiful" code that is easily understood

## Recursion: The Bad

* Even with simple recursion, you risk stack overflow
  * You are abusing the call stack to do a simple loop
  * Even if it is not a "runaway" recursion (infinite loop) you are still abusing the call stack, which is limited!
* Most/all recursion can be rewritten as a regular loop or you *simulate* the recursion
* You risk a naive *exponential* approach to a problem

* A blind recursive version of this makes *trillions* of function calls
* An *exponential* amount of work! $1.6^n$
* *most* of the work is *repeated*: the same values are computed over and over and over

## Eliminating Recursion

* You can *always* use a regular old loop and data structures to "simulate" recursion
* Another technique: tail recursion (eliminates multiple stack frames): the compiler can optimize your recursive code away and use only one stack frame
* You can use *memoization*
  * Go ahead and use recursion, but...
  * You *don't* recompute previously computed values
  * You *cache* or store the results so they can be *resused*

* Basic Steps:
  * Maintain a table full of values
  * Initialize the table with the base cases
  * We'll call a recursion function passing in the table
  * If the table contains a value, we use it, otherwise...
  * We pay for the recursion and compute the value, but then
  * *store* the value for future use

```c
/**
 * Chris Bourke
 *
 * Demo Code
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int fibonacciIterative(int n) {

  if(n < 1) {
    return 0;
  }
  int prev = 1;
  int curr = 1;
  int next = 1;

  for(int i=0; i<n-2; i++) {
    next = prev + curr;
    //set yourself up for the next loop:
    prev = curr;
    curr = next;
  }
  return next;
}

int fibonacciRec(int n) {

  if(n < 1) {
    return 0;
  } else if(n == 1 || n == 2) {
    return 1;
  } else {
    int a = fibonacciRec(n-1);
    int b = fibonacciRec(n-2);
    return a + b;
  }
}

int fibonacciMem(int n, int *table) {

  if(n < 1) {
    return 0;
  } else if(n == 1 || n == 2) {
    return 1;
  } else {
    int a, b;
    if(table[n-1] != 0) {
      a = table[n-1];
    } else {
      a = fibonacciMem(n-1, table);
    }
    if(table[n-2] != 0) {
      b = table[n-2];
    } else {
      b = fibonacciMem(n-2, table);
    }
    int result = a + b;
    table[n] = result;
    return result;
  }
}


int main(int argc, char **argv) {

  if(argc != 2) {
    printf("include an n please\n");
    exit(1);
  }

  //table[0] = not define
  //table[i] = fib(i)
  //table[1] = 1 = fib(1)
  //table[2] = 1 = fib(2)

  //table[n] = fib(n)

  int n = atoi(argv[1]);
  int *table = (int *) malloc( sizeof(int) * (n + 1) );

  for(int i=0; i<=n; i++) {
    table[i] = 0; //flag value to indicate not yet computed
  }
  table[1] = 1;
  table[2] = 1;
  int result = fibonacciMem(n, table);
  printf("fibonacci(%d)= %d\n", n, result);

  return 0;
}


```

```text














```
