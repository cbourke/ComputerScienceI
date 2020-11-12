
# CSCE 155H - Computer Science I
## Searching & Sorting
### Fall 2020

# Introduction

* Processing data is a fundamental operation in Computer Science
* Two fundamental operations in processing data are *searching* and *sorting*
* Form the basis or preprocessing step of many algorithms
* Large variety of algorithms have been developed

## Linear Search

* Basic idea: given a collection of elements and a key element *k*, search through the collection to find any element that matches *k*
* WHAT are you searching? An array, a list, set, etc?  
* What is it a collection of?  Integers, doubles, strings, films, etc.
* How are you searching: by what criteria can you determine that you've found a match
* Searching for a particular element or the first or the last, max or the min, or all elements that match your search criteria
* More general, algorithmic perspective: we want to keep this general
* Pseudocode: algorithms (in general) are usually presented using *psuedocode*: code that describes a process at a high level
  * Makes use of plain old English and mathematical symbols
  * It generally does not use language-specific constructs
* Exhaustively search the collection until you find an element that matches your key

```c

/**
 * Searches the given array of integers for a value
 * matching the given key value.  If such a value is
 * found, this function returns the index at which it
 * finds it (first found).  Upon an unsuccessful search
 * this function returns -1.
 */
int linearSearch(const int *arr, int n, int key) {

  for(int i=0; i<n; i++) {
      if(arr[i] == key) {
          return i;
      }
  }
  return -1;
}
```

* The above is only good for arrays of integers
* What if we now wanted an implementation for `double` values

```c
/**
 * Searches the given array of films for a value
 * matching the given key value.  If such a value is
 * found, this function returns the index at which it
 * finds it (first found).  Upon an unsuccessful search
 * this function returns -1.
 */
int linearSearchForFilm(const Film *arr, int n, Film key) {

  for(int i=0; i<n; i++) {
      if( strcmp(arr[i].title, key.title) == 0 ) {
          return i;
      }
  }
  return -1;
}


/**
 * Searches the given array of doubles for a value
 * matching the given key value.  If such a value is
 * found, this function returns the index at which it
 * finds it (first found).  Upon an unsuccessful search
 * this function returns -1.
 */
int linearSearchForDoubles(const double *arr, int n, double key) {

  for(int i=0; i<n; i++) {
      if(arr[i] == key) {
          return i;
      }
  }
  return -1;
}
```

* Problem: violating the DRY = Don't Repeat Yourself
* Eventual goal: create ONE implementation of a search algorithm that can be used for *any* type of variable
* Problem: you still need to specify a search criteria
* In order to determine if an element is equal (or more generally the relative order of elements) we'll use *comparators* 

### Analysis

* How much "work" or "resources" or computation time does linear search take?
* For searching, the number of comparisons is a good measure of resources
* How many comparisons does linear search make to find an element?
  * Best case scenario: 1 (you get lucky and find the element at the first index)
  * Worst case scenario: $n$ (assuming there are *n* elements in the array)
  * Average case scenario: on average, how many comparisons would linear search make?  $\approx \frac{n}{2}$
* Both the worst and average case are linear functions
* Linear search makes a linear number of comparisons with respect to the input size ($n$ number of elements in the array)
* Suppose that linear search takes $t$ time to search an array of size $n$
  * Suppose you *double* the input size: $n \rightarrow 2n$
  * It now takes $2t$ time to search
  * Doubling the input size doubles the time
* Can we do better?

## Binary Search

* Suppose that the input array is sorted
* Being sorted gives the array *structure*; structure can be exploited
* Search for the key $k$ in a sorted array
* Look at the middle element: $m$
  * If it is equal to your key, you are done: success
  * If the key is less than the middle element $k < m$: search in the lower/left half
  * If the key is greater than the middle element: $m < k$: search in the upper (right) half
  * until you either find it or you have an array of size 0 (unsuccessful search)
* This is a divide and conquer style algorithm that *may* be implemented recursively 

```c
//TODO: documentation
int binarySearch(const int *arr, int n, int key) {
    int left = 0;
    int right = n - 1;

    while(left <= right) {
        int m = (left + right) / 2;  //CAREFUL: this risks overflow!
        if(key == arr[m]) {
            //succesful search
            return m;
        } else if(key < arr[m]) {
            //search in the left (lower) half
            //update the right index:
            right = m - 1;
        } else if(arr[m] < key) {
            //search in the right (upper) half
            //update the left index:
            left = m + 1;
        }
    }
    return -1;
}
```

### Analysis

* Binary search only makes $\approx \log_2{n}$ comparisons in the worst and average case for arrays with $n$ elements
* Suppose you have an array of 1 trillion elements
  * linear search will end up making 1 trillion (or 500 billion in the average) comparisons
  * binary search will end up making $\log_2{(10^{12})} \leq 40$ comparisons
* Suppose it takes $t$ time to perform binary search on an array of size $n$
* Doubling the input size: $n \rightarrow 2n$ means you now have $\log_2{(2n)} = \log_2{(n)} + \log_2{(2)} = \log_2{(n)} + 1$ comparisons;
* In other words, doubling the input size means you only need 1 more comparison!
* Binary search is *exponentially* faster than linear search
* BUT: binary search requires that the input be sorted
* Sorting may be expensive but it also may be an investment

## Sorting

* Huge variety of sorting algorithms with different algorithmic strategies and different performances

### Selection Sort

* Basic Idea:
  * iterates through the array and finds a minimal element
  * it swaps it with the first element
  * repeat:
  * iterates through the remaining elements and finds the next minimal (2nd smallest)
  * swapping it with the second element
  * on the ith iteration:
    * the first i-1 items have already been sorted
    * among items i thru n-1, we find the minimum and
    * swap it with the ith element
  * we repeat this until all items have been sorted (for n-1 iterations)

#### Analysis

* What "work" does this algorithm make?
* Comparisons: how many comparisons are made to sort an array of n elements?
* It makes about $n^2$ comparisons 
* Selection sort is a *quadratic sorting* algorithm
* How bad is this?
* Suppose you want to sort an array of 1 trillion = $10^{12}$
* It would end up making $(10^{12})^2 = 10^{24}$ (1 septillion) comparisons/operations
* At 7TFLOPS (roughly) that would take 4500+ years to actually sort!
* Suppose you want to double the input size: $n \rightarrow 2n$; how many more comparisons will you need to make?
* $(2n)^2 = 4n^2$ (four times as many operations, four times slower)

### Quick Sort

* Basic Idea:
  * Select a *pivot* element (usually the first element)
  * We then *partition* all elements to the left (lesser) or right (greater) and place the pivot between them
  * recursively sort the left partition and the right partition
  * For code and pseudocode, see the book

#### Analysis

* In the worst case quick sort can "devolve" into selection sort
* BUT in the average and best case, quick sort makes only $n\log_2{(n)}$ comparisons
* This known as a quasilinear sorting algorithm
* Suppose you want to sort 1 trillion elements, only take
$10^{12}\log_2{(10^{12})}$ comparisons
* It only takes 6 seconds to sort using a 7TFLOP computer

## Searching & Sorting in Practice

* In practice: you don't roll your own: you shouldn't have to write your own implementations unless there is a Very Good Reason to do so.
* In practice: use the built-in searching & sorting implementations provide by the language or standard library
* To avoid multiple implementations, most will use some sort of *generic programming*
* General sorting algorithms know how to "sort"
* But they don't know how to "order"
* sorting is arranging a collection of elements, ordering is simply ordering 2 elements, $a, b$

### Comparators in C

* In C, a *comparator function* is used to order elements
* A comparator function has the following signature:

`int cmp(const void *a, const void *b)`

* It returns an integer that has the following "contract":
  * it returns *something* negative if a < b
  * it returns zero if a is equal to b
  * it returns *something* positive if a > b (b < a)
* Both `a` and `b` have the `const` modifier: the comparator will not make changes to them, it only looks them to determine the relative order
* `void *` is a generic void pointer, it is a pure memory address that can point to any memory location containing any type
* Inside the function, you cast the inputs `a, b` as the *expected* types
* then you apply the logic for comparing the two elements and return an integer value

* Once you have a comparator, you can provide to a standard library sorting function:

```c
void qsort(void *base,
           size_t nel,
           size_t size,
           int (*compar)(const void *, const void *));
```

* `void *base` is the array you want to sort
* `nel` is the number of elements in the array
* `size` is the number of bytes each element takes
* `compar` is a *function pointer* that points to a comparator that  `qsort` will use to order elements

## Recap - Comparators and `qsort` with structures

## Deeper Look: Function Pointers

* How can we "pass" a function to another function as a parameter so that that function can "use" or call the passed function
* Doing so is generally referred to as using a "callback" (the passed function is the callback and the function that uses it "calls it back")
* GUI = Graphical User Interface programming: when a button is clicked, a function must be called to "handle" that event: you register a callback to do this
* Example: `qsort` needs a way to order elements so you "pass in" a comparator as a *function pointer*
* But: a function is simply code that is stored in memory
* Ie the function is stored at some memory address which can be *pointed* to by a function pointer!

demoPtr.c:
```c

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void runMath(double x, double (*ptrToMath)(double)) {

  double y = ptrToMath(x);
  printf("2 of some function is is %f\n", y);

}


int main() {

  //create a function pointer that can point to a
  // a function that returns an integer and takes 3
  // parameters: (int, char, double)
  int (*ptrToFunc)(int, char, double);
  ptrToFunc = NULL;

  //create a function pointer that can point to
  // the square root function
  double (*ptrToMath)(double);
  //make it "point" to sqrt:
  ptrToMath = sqrt;

  double y = sqrt(2.0);
  printf("sqrt of 2 is %f\n", y);

  y = ptrToMath(2.0);
  printf("sqrt of 2 is %f\n", y);

  ptrToMath = cos;
  y = ptrToMath(2.0);
  printf("cos of 2 is %f\n", y);

  // ptrToMath = pow;
  // y = ptrToMath(2.0);
  // printf("cos of 2 is %f\n", y);

  runMath(2, sqrt);
  runMath(2, sin);
  runMath(-2, fabs);

}

```

account.h:
```c

//TODO: define a structure for bank accounts
typedef struct {
    int number;
    char *firstName;
    char *lastName;
    double balance;
} BankAccount;

void printAccounts(const BankAccount *accounts, int n);

//TODO
int cmpAccountsByName(const void *a, const void *b);

int linearSearch(const void *arr, int n, size_t size, const void *key, int (*cmp)(const void *, const void *));
```

account.c:
```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "account.h"


void printAccounts(const BankAccount *accounts, int n) {

  printf("Accounts\n");
  printf("=========================\n");
  for(int i=0; i<n; i++) {
      printf("%-8d $%10.2f %s, %s\n",
        accounts[i].number,
        accounts[i].balance,
        accounts[i].lastName,
        accounts[i].firstName
        );

  }

}


int cmpAccountsByName(const void *a, const void *b) {
  //step 1: force the generic void pointers to
  // become the type  that you expect
  const BankAccount *x = (const BankAccount *)a;
  const BankAccount *y = (const BankAccount *)b;

  int result = strcmp(x->lastName, y->lastName);
  if(result == 0) {
    result = strcmp(x->firstName, y->firstName);
  }
  return result;
}

int linearSearch(const void *arr, int n, size_t size, const void *key, int (*cmp)(const void *, const void *)) {

  //arr is the memory address of the beginning of the array
  //arr[0] is the first element
  //arr[1] is the second element
  // BUT this only works if the compiler *knows* what
  // these are
  // int: 0 is zero bytes away from the beginning
  // int: 4 bytes away from the beginning
  // int: 8 bytes away from the beginning
  // double: 0 is zero bytes away from the beginning
  // double: 8 bytes away from the beginning
  // double: 16 bytes away from the beginning
  // void/?: first is 0 bytes away
  //         second is size bytes away
  //         third is 2 * size bytes away
  // ith element is at (arr + i * size) bytes away

  for(int i=0; i<n; i++) {
      if( cmp( arr + i * size, key) == 0 ) {
          return i;
      }
  }
  return -1;
}
```
demo.c:
```c
#include <stdlib.h>
#include <stdio.h>

#include "account.h"

int main() {

  int n = 5;
  BankAccount accounts[] = {
    { 1234, "Chris", "Bourke", 42.42 },
    { 4567, "Joe", "Smith", 1000.01 },
    { 8282, "Zelda", "Smith", 324324.00 },
    { 3213, "Alan", "Turing", 1000.05 },
    { 32145, "Grace", "Hopper", 100432.99 }
  };

  printAccounts(accounts, n);
  qsort(accounts, n, sizeof(BankAccount), cmpAccountsByName);
  printAccounts(accounts, n);

  //create a dummy bank account with the values you are
  // searching for
  BankAccount key = { 0, "Grace", "Hoopper", 0 };
  int index = linearSearch(accounts, n, sizeof(BankAccount), &key, cmpAccountsByName);
  printf("found account at index %d\n", index);
}
```

BankAccount.java:
```java
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class BankAccount {

    private int number;
    private String firstName;
	private String lastName;
    private double balance;

	public BankAccount(int number, String firstName, String lastName, double balance) {
		super();
		this.number = number;
		this.firstName = firstName;
		this.lastName = lastName;
		this.balance = balance;
	}

    public int getNumber() {
		return number;
	}


	public String getFirstName() {
		return firstName;
	}


	public String getLastName() {
		return lastName;
	}


	public double getBalance() {
		return balance;
	}
	
		@Override
	public String toString() {
		return "BankAccount [number=" + number + ", firstName=" + firstName + ", lastName=" + lastName + ", balance="
				+ balance + "]";
	}

	public static void main(String[] args) {
		List<BankAccount> accounts = Arrays.asList(
			    new BankAccount(1234, "Chris", "Bourke", 42.42 ),
			    new BankAccount(4567, "Joe", "Smith", 1000.01 ),
			    new BankAccount(8282, "Zelda", "Smith", 324324.00 ),
			    new BankAccount(3213, "Alan", "Turing", 1000.05 ),
			    new BankAccount(32145, "Grace", "Hopper", 100432.99)
				);
		for(BankAccount a : accounts) {
			System.out.println(a);
		}
		
		Comparator<BankAccount> c = new Comparator<>() {

			@Override
			public int compare(BankAccount o1, BankAccount o2) {
				int result = o1.lastName.compareTo(o2.lastName);
				if(result == 0) { 
					result = o1.firstName.compareTo(o2.firstName);
				}
				return result;
			}
			
		};
		
		Collections.sort(accounts, c);
		for(BankAccount a : accounts) {
			System.out.println(a);
		}

		Comparator<BankAccount> c2 = Comparator.comparing(BankAccount::getNumber)
				.thenComparing(BankAccount::getLastName)
				.thenComparing(BankAccount::getFirstName)
				.reversed();
		BankAccount key = new BankAccount(0, "Grace", "Hoopper", 0);
		int index = linearSearch(accounts, c, key);
		
		index = Collections.binarySearch(accounts, key, c);

		System.out.println("Found it at index " + index);

		
	}
	
	public static <T> int linearSearch(List<T> items, Comparator<T> cmp, T key) {
		for(int i=0; i<items.size(); i++) {
			if( cmp.compare(items.get(i), key) == 0) {
				return i;
			}
		}
		return -1;
	}

}

```

## Misc

### Arrays of Structure Pointers

* Code: TODO

### Sorting Stability

* Consider the following values:   
  3A, 7, 3B, 1  
  1, 3B, 3A, 7 
* The above is an unstable sorting
* A sorting algorithm is *stable* if it never puts two otherwise equal elements out of their original order
* Why is this important?
* It is often necessary or at least preferable to preserve the original ordering (ex: sorting by GPA then by year)
* Is selection sort stable? No
* Is quicksort stable?  It can be

## Natural vs Artificial Ordering

* Example: generalliy Freshmen, Sophomore, Junior Senior is the order expected
* BUT, the "natural" ordering (when represented as strings) is 

`"Freshman", "Junior", "Senior", "Sophomore"`

account.h:
```c

typedef enum {
  GOLD,
  SILVER,
  BRONZE,
} Type;

//TODO: define a structure for bank accounts
typedef struct {
    int number;
    char *firstName;
    char *lastName;
    double balance;
    Type type;
    //char *type; //Gold, Silver, Bronze

} BankAccount;

void printAccounts(BankAccount **accounts, int n);

//TODO
int cmpBankAccountByNumber(const void *a, const void *b);
```

account.c:
```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "account.h"

const char *typeToString[] = {
  "Gold", "Silver", "Bronze"
};

void printAccounts(BankAccount **accounts, int n) {

  printf("Accounts\n");
  printf("=========================\n");
  for(int i=0; i<n; i++) {
      printf("%-8d $%10.2f %s, %s %s\n",
        accounts[i]->number,
        accounts[i]->balance,
        accounts[i]->lastName,
        accounts[i]->firstName,
        typeToString[accounts[i]->type]
        );

  }

}

int cmpBankAccountByNumber(const void *a, const void *b) {
  //step 1: cast these as the proper type
  const BankAccount **x = (const BankAccount **)a;
  const BankAccount **y = (const BankAccount **)b;

  const BankAccount *A = *x;
  const BankAccount *B = *y;

  if( A->number < B->number ) {
    return -1;
  } else if( A->number > B->number ) {
    return 1;
  } else {
    return 0;
  }
}

demo.c:
```c
#include <stdlib.h>
#include <stdio.h>

#include "account.h"

int main() {

  int n = 5;
  BankAccount accounts[] = {
    { 1234, "Chris", "Bourke", 42.42, GOLD },
    { 4567, "Joe", "Smith", 1000.01, SILVER },
    { 8282, "Zelda", "Smith", 324324.00, BRONZE },
    { 3213, "Alan", "Turing", 1000.05, BRONZE },
    { 32145, "Grace", "Hopper", 100432.99, GOLD }
  };

  BankAccount **pAccounts = (BankAccount **) malloc(n * sizeof(BankAccount *));
  for(int i=0; i<n; i++) {
    pAccounts[i] = &accounts[i];
  }
  printAccounts(pAccounts,n);

  //sort by number
  qsort(pAccounts, n, sizeof(BankAccount *), cmpBankAccountByNumber);
  printAccounts(pAccounts,n);

  BankAccount key = { 32145, NULL, NULL, 0 };
  BankAccount *pKey = &key;
  BankAccount **needle = bsearch(&pKey, pAccounts, n, sizeof(BankAccount *), cmpBankAccountByNumber);
  if(needle == NULL) {
    printf("didn't find it\n");
  } else {
    printf("found %s's account!\n", (*needle)->firstName);
  }

}
```

```

BankAccount.java:
```java
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class BankAccount extends Object {
	
	public static enum Type {
		GOLD,
		SILVER,
		BRONZE;
		
		private static final Map<Type, String> typeToString = new HashMap<>();
		static {
			typeToString.put(GOLD, "Gold");
			typeToString.put(SILVER, "Silver");
			typeToString.put(BRONZE, "Bronze");
		}
		public String toString() {
			return typeToString.get(this);
		}
	}

    private int number;
    private String firstName;
	private String lastName;
    private double balance;
    private Type type;

	public BankAccount(int number, String firstName, String lastName, double balance, Type type) {
		super();
		this.number = number;
		this.firstName = firstName;
		this.lastName = lastName;
		this.balance = balance;
		this.type = type;
	}

    public int getNumber() {
		return number;
	}


	public String getFirstName() {
		return firstName;
	}


	public String getLastName() {
		return lastName;
	}


	public double getBalance() {
		return balance;
	}
	
		@Override
	public String toString() {
		return "BankAccount [number=" + number + ", firstName=" + firstName + ", lastName=" + lastName + ", balance="
				+ balance + "]" + this.type.toString();
	}

	public static void main(String[] args) {
		List<BankAccount> accounts = Arrays.asList(
			    new BankAccount(1234, "Chris", "Bourke", 42.42, Type.GOLD ),
			    new BankAccount(4567, "Joe", "Smith", 1000.01, Type.SILVER ),
			    new BankAccount(8282, "Zelda", "Smith", 324324.00, Type.BRONZE ),
			    new BankAccount(3213, "Alan", "Turing", 1000.05, Type.GOLD ),
			    new BankAccount(32145, "Grace", "Hopper", 100432.99, Type.SILVER)
				);
		for(BankAccount a : accounts) {
			System.out.println(a);
		}
		
		Comparator<BankAccount> byType = new Comparator<>() {

			@Override
			public int compare(BankAccount o1, BankAccount o2) {
				return o1.type.compareTo(o2.type);
			}
			
		};
		Collections.sort(accounts, byType);
		System.out.println("BY TYpe");
		for(BankAccount a : accounts) {
			System.out.println(a);
		}

		
		
		Comparator<BankAccount> c = new Comparator<>() {

			@Override
			public int compare(BankAccount o1, BankAccount o2) {
				int result = o1.lastName.compareTo(o2.lastName);
				if(result == 0) { 
					result = o1.firstName.compareTo(o2.firstName);
				}
				return result;
			}
			
		};
		
		Collections.sort(accounts, c);
		for(BankAccount a : accounts) {
			System.out.println(a);
		}

		Comparator<BankAccount> c2 = 
				(a, b) -> a.getLastName().compareTo(b.getLastName()); 
		c2 = c2.thenComparing( (a, b) -> a.getFirstName().compareTo(b.getFirstName()) );
		c2 = c2.reversed();
		BankAccount key = new BankAccount(0, "Grace", "Hoopper", 0, Type.GOLD);
		int index = linearSearch(accounts, c, key);
		
		index = Collections.binarySearch(accounts, key, c);

		System.out.println("Found it at index " + index);

		
	}
	
	public static <T> int linearSearch(List<T> items, Comparator<T> cmp, T key) {
		for(int i=0; i<items.size(); i++) {
			if( cmp.compare(items.get(i), key) == 0) {
				return i;
			}
		}
		return -1;
	}

}
```

```text










```