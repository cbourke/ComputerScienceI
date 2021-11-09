
# CSCE 155E - Computer Science I
## Algorithms, Searching & Sorting
### CSCE 155E, Fall 2020

# Introduction & Demonstration

* Algorithm: a finite sequence of operations that defines a computational process for solving a problem
* All algorithms must be *correct*
* Algorithms != Problems
* Algorithms *solve* problems
* There may be more than 1 algorithm solving the same problem
* But: not all algorithms are created equally
* Ex: The Maliciously Compliant Painter

## Searching

* Given a collection of elements and a key element *k* you want to search the collection to see if anything exists in it that "matches" *k*
* In the context of C:
  * A collection is an array
  * elements are items in the array
  * a key is an element of the same type
  * matches means ?
* Suppose, more specifically: given an array of integers and a key element `int k` you want to search the array to see if `k` is in it
  * what should you return?

### Design Considerations

* *What* are you searching: an array, or other data structure?  Strings?  Integers?  Airports?  etc.
* *How* are you searching:
  * Do you find the first one, the last one, all of them?
  * If you have a structure, `Airport`: how do you know the airport matches your search criteria
  * Criteria:
    * You could find the first, last, (max or min)
    * You can search based on a structure's state: partially or wholly, etc.
  * What do you do for an unsuccessful search?

## Linear Search

* A linear search algorithm searches through a collection to find an element that matches a key
* The complexity of an algorithm is captured in the amount of "work" or resources it uses to execute
* Linear search: the idea of "work" can be captured by the number of operations, specifically the number of comparisons it makes
* Best case scenario: Linear could get lucky and find the needle at the first element: just 1 comparison needed
* Worst case scenario: if the array has *n* elements, you make *n* comparisons
* Average case scenario: on average you would make n/2 comparisons
* Linear search makes a linear number of comparisons
* If you increase the input size (the size of the input array) then the amount of work increases by a linear amount
* Size: n -> 10n; suppose an input of n took 10 seconds, an input of 10n takes 100 seconds!
* For comparison: our demonstration is a quadratic algorithm, it makes $n^2$ operations
  * n -> 10n
  * 10 seconds becomes...
  * $n \rightarrow 10n$
  * $n^2 \rightarrow (10n)^2 = 100n^2$
  * Now it takes 10 seconds * 100 or 1000 seconds = 17 minutes
* As the input size grows, the amount of work grows linearly with it
* Is there a better solution?  Is there a better algorithm?

Code:
```c

/**
 * searches the given array (which is of size n)
 * of doubles for any value that equals the
 * given key, returns the index at which it finds
 * it upon a successful search, otherwise returns
 * -1 if no such element exists.
 */
int searchDoubles(const double *arr, int n, double key) {
  for(int i=0; i<n; i++) {
    if(arr[i] == key) {
      return i;
    }
  }
  return -1;
}

/**
 * searches the given array (which is of size n)
 * of integers for any value that equals the
 * given key, returns the index at which it finds
 * it upon a successful search, otherwise returns
 * -1 if no such element exists.
 */
int searchIntegers(const int *arr, int n, int key) {
  for(int i=0; i<n; i++) {
    if(arr[i] == key) {
      return i;
    }
  }
  return -1;
}

int searchStrings(...);
int searchAirports();
int searchTransactions();
```

* The above implementations are naive: you would require a function for every type and every criteria you would ever want
* Is there a better way?  
  * Can we write *ONE* linear search function that will search ANY array of ANY time
  * Yes, BUT you still need a "component" that tells you when you've found what you're looking for

## Binary Search

* Consider an array that is already sorted
* Sorted array have *structure* you may be able to *exploit* that structure to improve efficiency
* Idea:
  * Examine the middle element, if it matches the key, stop (you found what you're looking for)
  * If the middle element is greater than the element you are search for, repeat your search in the lower half (left half)
  * If the middle elements is less than the element you are searching for, repeat your search in the upper half (right half)
  * repeat until you found what you are looking for OR you don't find it and the array "partition" is now empty
* In either case, you have cut the input in half each time
* this is a divide and conquer style algorithm
* We *could* implement this recursively, BUT we'll do the better iterative version
```c
#include <stdlib.h>
#include <stdio.h>

//TODO: documentation
int binarySearch(const int *arr, int n, int key) {
    int left = 0;
    int right = n - 1;

    while(left <= right) {
        //careful: aside: this is BAD in practice because it is susceptible to overflow
        int middle = (left + right) / 2;
        if(key == arr[middle]) {
            //successful search!
            //stop, return...
            return middle;
        } else if(key < arr[middle]) {
            //search in the lower/left half
            right = middle - 1;
        } else if(arr[middle] < key) {
            //search in the upper/right half:
            left = middle + 1;
        }
    }
    return -1;

}

int main() {

    int n = 9;
    int arr[] = {1, 2, 3, 4, 5, 5, 6, 7, 8};
    int key = 42;
    int index = binarySearch(arr, n, key);
    printf("Found %d at index %d\n", key, index);


}
```

### Efficiency

* Is binary search actually better?
* Binary search only makes $\log_2{(n)}$ comparisons in the worst and average case
* Linear search: an input of size 10 million elements, would make 10 million comparisons (worst case) or 5 million comparisons in the average case
* Binary search: for an input of 10 million elements, it would only make $\log_2{(10^7)} \leq 24$ comparisons
* No contest: binary search is *exponentially* faster than linear search
* BUT: binary search requires the array to be sorted
* It may be worth it to "invest" some computation time to sort OR maintain the order of an array so that you can use binary search to search fast

## Sorting

* Huge variety of sorting algorithms with different strategies and approaches

### Selection Sort

* Basic idea: search through an array and find the minimal element, swap it with the first element
  * Repeat: find the second smallest, place it at the second location
  * Find the 3rd smallest, place it at the third location
  * Find the ith smallest and place it at the ith position
  * The last one will be by definition, be sorted

```c
#include <stdlib.h>
#include <stdio.h>

void selectionSort(int *arr, int n) {

    for(int i=0; i<n-1; i++) {
        //find the minimum among the elements...
        //at the ith iteration, I know that elements
        //arr[0] thru arr[i-1] are sorted!
        //find the minimum among elements arr[i]...arr[n-1]
        int minIndex = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        //the minimum is at minIndex, swap it
        //with the ith element
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {

    int n = 9;
    int arr[] = {2, 7, 5, 4, 3, 6, 1, 8, 5};
    selectionSort(arr, n);
    for(int i=0; i<n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

```

### Analysis

* Our notion of "work": the number of comparisons
* How many comparisons does selection sort make on an array of size *n*?
* Selection sort requires *about* n^2 operations; it is a "quadratic" sorting algorithm
* How "bad" is this?
* In practice, you do not use even quadratic algorithms because they are too slow (unless there is a Very Good Engineering Reason to do so)
* Even for a moderately large data set, quadratic is not practical
* Example: suppose you need to sort 1 trillion elements (10^12)
  * Number of comparisons: (10^12)^2 = 10^24
  * With a 7TFLOP computer: 4526 years!
  * This is not really all that big of data
* Example: suppose you sort a moderately large data set of size *n*
  * Suppose it takes you *t* time
  * Suppose you go and *double* the input size: *n* to *2n*
  * How much slower is it now?
  * Twice as big means it takes (2n)^2 operations!
  * (2n)^2 = 4n^2, it now takes 4 times as much time! *4t* time

## Quick Sort

* Basic Idea:
  * Choose a *pivot* element (usually just the first element)
  * Partition all other elements around it: all elements *less* than the pivot are placed to its left; all elements *greater* than the pivot are placed to its right
  * "recursively" sort the left and the right partitions
  * UNTIL: you get down to an array of size 1
* Analysis:
  * A full analysis is omitted, but...
  * You get the best performance if the partitioning *most of the time* divides the array into two roughly equally sized halves
  * In the average case and the best case, quick sort makes $n \log(n)$ comparisons
  * IN the worst case, quick sort can "devolve" into selection sort (if your choice of pivot is always the minimum): $n^2$ operations
  * $n \log(n)$ is usually called "quasilinear"
  * Examples: sorting 1 trillion elements now only requires
  $10^{12} \log(10^{12})$ comparisons; with the same 7TFLOP computer, it now only takes 7 seconds!
  * Example: going from $n$ to $2n$ sized arrays only requires how many more comparisons?
  * $2n \log(2n) = 2n\log{2} + 2n\log{n}$ (essentially a little more than twice as many operations)

## Searching & Sorting in Practice

* In practice: you don't want to roll your own sorting functions unless you have a Very Good Reason to do so
* In practice: use the built-in functionality or a library of searching and sorting implementations
* To avoid multiple implementions, use *generics*
* You want ONE implementation that "sorts"
* HOWEVER, that implementation still needs to know how to "order"
* Ordering: given two elements, which one comes first (or are they equal)?
* Sorting: given a whole bunch of elements, arrange them *according to an ordering*
* In C, to order things, you use a *comparator function*

### Comparators in C

* In C a *comparator function* has the following signature:

`int cmp(const void *a, const void *b)`

* It returns an integer value with the following contract:
  * it returns *something* negative if a < b
  * it returns zero if a is equal to b
  * it returns *something* positive if a > b (b < a)
* Note: each element is labeled `const`: no changes will be made to the passed elements
* `void *` is a generic void pointer; void in this context means anything
  * a generic void pointer is a "raw" pointer that simply points to a memory location
  * That memory location could hold any type of variable
* inside the function, you *do* need some information on what `a` and `b` are in order to make your comparison
* inside the comparator: you do the following pattern
  * You type cast the generic pointers into the type of data you *expect*
  * Then you apply whatever logic you need to compare them
  * You return a value that fully specifies their ordering
* Once you have a comparator you can use it in the standard searching and sorting function...

### Sorting in C

* C provides a standard "quick sort" implementation

```c
void qsort(void *base,
           size_t nel,
           size_t size,
           int (*compar)(const void *, const void *));
```

* `void *base` is the array you want sorted
* `nel` is the number of elements in the array (size of the array)
* `size` is the size in bytes of each element in the array
* `compar` is a *function pointer*; a reference to the comparator you want to use!  

### Demonstration

```c
int cmpInt(const void *a, const void *b) {
  //step 1: convert the inputs to the expected type
  const int *x = (const int *) a;
  const int *y = (const int *) b;
  if( *x < *y ) {
    return -1;
  } else if( *x > *y ) {
    return 1;
  } else {
    return 0;
  }

}


int cmpIntDesc(const void *a, const void *b) {
  return cmpInt(b, a);
}

int main() {

    int n = 9;
    int arr[] = {2, 7, 5, 4, 3, 6, 1, 8, 5};
    qsort(arr, n, sizeof(int), cmpIntDesc);
    for(int i=0; i<n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}
```
## Recap - Comparators and `qsort` with structures

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
  qsort(accounts, n, sizeof(BankAccount), cmpBankAccountByBalance);
  printAccounts(accounts, n);
  qsort(accounts, n, sizeof(BankAccount), cmpBankAccountByName);
  printAccounts(accounts, n);

}

-------

typedef struct {
    int accountNumber;
    char *ownerFirstName;
    char *ownerLastName;
    double balance;
} BankAccount;

-----



#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "account.h"


void printAccounts(const BankAccount *accounts, int n) {

  printf("Accounts\n");
  printf("=========================\n");
  for(int i=0; i<n; i++) {
      printf("%-8d $%10.2f %s, %s\n",
        accounts[i].accountNumber,
        accounts[i].balance,
        accounts[i].ownerLastName,
        accounts[i].ownerFirstName
        );

  }

}

int cmpBankAccountByBalance(const void *a, const void *b) {
  //step 1: cast them as bank accounts
  const BankAccount *x = (const BankAccount *) a;
  const BankAccount *y = (const BankAccount *) b;

  if( x->balance < y->balance ) {
    return -1;
  } else if( x->balance > y->balance ) {
    return 1;
  } else {
    return 0;
  }


}

int cmpBankAccountByName(const void *a, const void *b) {
  const BankAccount *x = (const BankAccount *) a;
  const BankAccount *y = (const BankAccount *) b;
  int result = strcmp(x->ownerLastName, y->ownerLastName);
  if(result == 0) {
    result = strcmp(x->ownerFirstName, y->ownerFirstName);
  }
  return result;
}
```

## Deeper Look: Function Pointers

* HOw can we "pass" a function to another functions as a parameter so that that function can "use" (call) the passed function
* Doing so is generally referred to as a "callback" (a function passed to another function is the "callback" and the function invoking it "calls it back")
* GUI = Graphical User Interfaces: you define a button.
* What function gets invoked when a user clicks the button?
* Example: `qsort` needs a way to order elements, so you "pass in" a comparator as a function pointer
* But: a function is simply code that is stored in memory
* Ie the function is stored at a particular memory address (in the stack)
* you can create a pointer that "points" to the code of a function!
* This is known as a function pointer

demoPtr.c:
```c
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "account.h"

double runMath(double x, double (*func)(double) ) {
  double y = func(x);
  return y;
}

int main() {

  //create a function pointer called "ptrToFunc" that
  //can point to any function that 1. returns an integer
  // 2. takes three inputs: (int, double, char)
  int (*ptrToFunc)(int, double, char);
  //make the pointer point to NULL:
  ptrToFunc = NULL;

  double (*ptrToSqrt)(double);
  ptrToSqrt = sqrt;

  double y = sqrt(2.0);
  printf("sqrt of 2 is %f\n", y);

  y = ptrToSqrt(2.0);
  printf("sqrt of 2 is %f\n", y);

  y = runMath(2.0, sqrt);
  printf("sqrt of 2 is %f\n", y);

  y = runMath(2.0, sin);
  printf("sin of 2 is %f\n", y);

  y = runMath(-2.0, fabs);
  printf("fabs of -2 is %f\n", y);

}
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
        accounts[i].accountNumber,
        accounts[i].balance,
        accounts[i].ownerLastName,
        accounts[i].ownerFirstName
        );

  }

}

int cmpBankAccountByBalance(const void *a, const void *b) {
  //step 1: cast them as bank accounts
  const BankAccount *x = (const BankAccount *) a;
  const BankAccount *y = (const BankAccount *) b;

  if( x->balance < y->balance ) {
    return -1;
  } else if( x->balance > y->balance ) {
    return 1;
  } else {
    return 0;
  }


}

int cmpBankAccountByName(const void *a, const void *b) {
  const BankAccount *x = (const BankAccount *) a;
  const BankAccount *y = (const BankAccount *) b;
  int result = strcmp(x->ownerLastName, y->ownerLastName);
  if(result == 0) {
    result = strcmp(x->ownerFirstName, y->ownerFirstName);
  }
  return result;
}

int cmpBankAccountByNumber(const void *a, const void *b) {
  const BankAccount *x = (const BankAccount *) a;
  const BankAccount *y = (const BankAccount *) b;
  if( x->accountNumber < y->accountNumber) {
    return -1;
  } else if(x->accountNumber > y->accountNumber) {
    return 1;
  } else {
    return 0;
  }
}

int linearSearch(const void *arr, int n, size_t size, const void *key, int (*cmp)(const void *a, const void *b)) {

  //arr is the memory address of the start of the array
  //arr[i] is the ith element in the array IF the compiler
  //   knew how many bytes each one took
  //since it is a void * pointer, the compiler doesn't know
  // what they are and so does not know how many bytes each
  // one takes, BUt
  // we DO!
  //
  // The first elements is at arr (memory address) arr[0]
  // the second element is size bytes away from arr:
  //    arr + size
  // the third element is size * 2 bytes away:
  //    arr + 2 * size
  // ..
  //  the ith element is size * i bytes away:
  //    arr + i * size

  for(int i=0; i<n; i++) {
    if(cmp(arr + i * size, key) == 0) {
      return i;
    }
  }
  return -1;
}
```

account.h:
```c

typedef struct {
    int accountNumber;
    char *ownerFirstName;
    char *ownerLastName;
    double balance;
} BankAccount;

void printAccounts(const BankAccount *accounts, int n);

int cmpBankAccountByBalance(const void *a, const void *b);

int cmpBankAccountByName(const void *a, const void *b);

int cmpBankAccountByNumber(const void *a, const void *b);

int linearSearch(const void *arr, int n, size_t size, const void *key, int (*cmp)(const void *a, const void *b));
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

  BankAccount key = { 3218282, NULL, NULL, 0.0 };
  int index = linearSearch(accounts, n, sizeof(BankAccount), &key, cmpBankAccountByNumber);
  printf("found my account at index %d\n", index);
}
```

## Searching & Sorting Arrays of *Pointers* to Structures

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
/*
  printAccounts(accounts, n);
  qsort(accounts, n, sizeof(BankAccount), cmpAccountsByName);
  printAccounts(accounts, n);

  //create a dummy bank account with the values you are
  // searching for
  BankAccount key = { 0, "Grace", "Hopper", 0 };
  BankAccount *needle = (BankAccount *) bsearch(&key, accounts, n, sizeof(BankAccount), cmpAccountsByName);
  if(needle == NULL) {
    printf("unsuccessful search!\n");
  } else {
    printf("Found account #%d\n", needle->number);
  }
*/
  BankAccount **pAccounts = (BankAccount **) malloc(sizeof(BankAccount*) * n);
  for(int i=0; i<n; i++) {
    pAccounts[i] = &accounts[i];
  }
  printAccountsPtr(pAccounts, n);
  qsort(pAccounts, n, sizeof(BankAccount*), cmpAccountsByNamePtr);
  printAccountsPtr(pAccounts, n);

  BankAccount key = { 0, "Grace", "Hopper", 0 };
  BankAccount *ptrKey = &key;
  BankAccount **needle = (BankAccount **) bsearch(&ptrKey, pAccounts, n, sizeof(BankAccount*), cmpAccountsByNamePtr);
  if(needle == NULL) {
    printf("unsuccessful search!\n");
  } else {
    printf("Found account #%d\n", (*needle)->number);
  }


}

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

void printAccountsPtr(BankAccount **accounts, int n) {

  printf("Accounts\n");
  printf("=========================\n");
  for(int i=0; i<n; i++) {
      printf("%-8d $%10.2f %s, %s\n",
        accounts[i]->number,
        accounts[i]->balance,
        accounts[i]->lastName,
        accounts[i]->firstName
        );

  }

}

int cmpAccountsByNumber(const void *a, const void *b) {
  const BankAccount *x = (const BankAccount *)a;
  const BankAccount *y = (const BankAccount *)b;
  if( x->number < y->number ) {
    return -1;
  } else if ( x->number > y->number ) {
    return 1;
  } else {
    return 0;
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

/**
 * This comparator is used to order an array of pointers
 * to BankAccount structures by the owner's last name/first name
 */
int cmpAccountsByNamePtr(const void *a, const void *b) {
  const BankAccount **x = (const BankAccount **)a;
  const BankAccount **y = (const BankAccount **)b;

  const BankAccount *A = *x;
  const BankAccount *B = *y;

  int result = strcmp(A->lastName, B->lastName);
  if(result == 0) {
    result = strcmp(A->firstName, B->firstName);
  }
  return result;
}
```

## Sorting Stability

* Consider the following values:   
  3A, 7, 3B, 1  
  1, 3B, 3A, 7
* Consider the following values:   
    3A, 7, 3B, 1  
    1, 3A, 3B, 7
* A sorting algorithm is *stable* if it never puts two otherwise equal elements out of the original order
* Why is this important?  It is often necessary or at least preferable to preserve the original ordering (GPA then by year)
* Is selection sort stable?  No
* Is quicksort stable?  It can be.

## Natural vs Artificial Ordering

* Example: we would expect (generally) Freshmen, Sophomore, Junior, Senior
* BUT a natural ordering would be:
Freshmen, Junior, Senior, Sophomore (lexicographic)
* How do we best achieve an "artificial" ordering of small "lists" of values?
* Use an enumerated type!
* Then your comparators can use the "difference trick": you simply compute the difference of the enumerate type's values and return the difference: 5 - 10 is negative, 10 - 5 is positive, 5 - 5 is 0
* BUT you cannot use the difference trick in general 2 billion - (-2 billion) leads to over overflow (or underflow) and wrong values



```text














```
