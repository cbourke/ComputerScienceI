
# CSCE 155E - Computer Science I
## Searching & Sorting
### Fall 2024

# Introduction & Demonstration

* Huge part of Computer Science: data processing
* Fundamental operations: *searching*, *sorting*
* Form the basis or preprocessing step of many algorithms
* Large variety of algorithms have been developed

## Demonstration

* Demo: write a function to search a collection for a particular element

## Efficiency so far

* "Work" = comparisons
* linear search: $\approx n$
* binary search: $\approx \log{n}$
* selection sort: $n^2$
* quick sort: $n\log{n}$ (quasilinear, on average and in the best case)

## Searching and Sorting in Practice

* In general you do not write your own searching/sorting algorithms
* You use one built-in generic sorting/searching algorithm/function/method
* However, the built-in functionality is *generic* so it doesn't know what the elements are or how to compare them.
* Basic strategy:
  * Write generic algorithms/functions that can take *any* type of array
  * You have to pass in a another component to the function that is responsible for *comparing* elements: a *comparator*

### Comparators in C

* In C, a *comparator function* is a function that compares two  generic elements $a, b$ and returns:
  * it returns *something* negative if $a < b$
  * it returns zero if $a = b$
  * it returns *something* positive if $a > b$ ($b < a$)
* In C the signature of a comparator function *MUST* Be:

`int cmp(const void *a, const void *b)`

* It returns an integer as per the pattern above: negative, positive, zero
* Do NOT assume anything about the actual value: `-42, -1, -101`
* It takes two *generic void pointers*
  * It allows you to compare *any* type of values
* Inside the function you follow the following pattern:
  1. You cast the generic `void *` pointers as the type that you expect (`int`, `double`, `Book`)
  2. You use the state/value of the type to determine the ordering and return: something postiive, negative or zero

### Searching in C: use the built-in search library

* There is a search library: `#include <search.h>`
* There is a function called: `lfind`

```c
void * lfind(const void *key,
             const void *base,
             size_t *nel,
             size_t width,
             int (*compar)(const void *, const void *));
```
* `key` is a pointer to the key value you are searching for!
* `base` is the array you want to search
* `nel` is the number of elements (size of the array)
* **Take care**: this is a pass-by-reference variable (a pointer)
* `width` is the number of bytes each element takes (use `sizeof()`)
* `compar` is the comparator function you want to use to compare: pass in the name of the comparator function you want to use
* If successful: a valid pointer is returned
* If unsuccessful: a `NULL` pointer is returned

## `qsort`

```
void qsort(void *base,
           size_t nmemb,
           size_t size,
           int (*compar)(const void *, const void *));
```

* `base` is the array to be sorted`
* `nmemb` is the size of the array
* `size` is the number of bytes each element takes (use `sizeof()`)
* `compar` is the comparator to use

### Demonstration

* Let's write more comparators for our Book demonstration

### Demo Code

```c
/**
 * Demonstration code.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <search.h>

void printArray(const int *arr, int n) {
  if(arr == NULL) {
    printf("[null]\n");
    return;
  }
  printf("[ ");
  for(int i=0; i<n-1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("%d ]\n", arr[n-1]);
  return;
}

int * generateRandomArray(int size) {
  if(size < 0) {
    return NULL;
  }
  int *randomArr = (int *) malloc(sizeof(int)*size);
  for(int i=0; i<size; i++) {
    randomArr[i] = rand() % 100;
  }
  return randomArr;
}



/**
 * Sorts the given array using selection sort
 */
void selectionSort(int *arr, int n) {

  for(int i=0; i<n-1; i++) {

    //find the minimum among elements i thru n-1
    int minIndex = i;
    for(int j=i+1; j<n; j++) {
      if(arr[j] < arr[minIndex]) {
        //a[j] is smaller, update....
        minIndex = j;
      }
    }
    //swap a[i] and a[minIndex]
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }
  return;

}

/**
 * searches the given array `arr` for the given `key`
 * element and returns the index at which it finds it.
 *
 * Returns -1 if no such element is found.
 */
int linearSearch(const int *arr, int n, int key) {

    for(int i=0; i<n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

/**
 * Performs a binary search on the given array of size n
 * for the given key element.  Returns *an* index upon success,
 * -1 if no such element.
 */
int binarySearch(const int *arr, int n, int key) {

  int leftIndex = 0;
  int rightIndex = n-1;
  while(leftIndex <= rightIndex) {
    int middleIndex = (leftIndex + rightIndex) / 2; //careful: this risks overflow
    if( arr[middleIndex] == key ) {
      return middleIndex;
    } else if( arr[middleIndex] < key ) {
      //search on the right half...
      leftIndex = middleIndex + 1;
    } else if( key < arr[middleIndex]) {
      //search on the left half
      rightIndex = middleIndex - 1;
    }
  }
  return -1;
}

/**
 * Orders integers in ascending (non-decreasing) order
 */
int cmpInt(const void *a, const void *b) {
    const int *x = (const int *)a;
    const int *y = (const int *)b;

    if(*x < *y) {
        return -1;
    } else if(*x > *y) {
        return 1;
    } else {
        return 0;
    }
}

int cmpIntDesc(const void *a, const void *b) {

    const int *x = (const int *)a;
    const int *y = (const int *)b;

    if(*x > *y) {
        return -1;
    } else if(*x < *y) {
        return 1;
    } else {
        return 0;
    }

}


int main(int argc, char **argv) {

    srand(time(NULL));

    // int n = 10;
    // int arr[] = {54, 87, 68, 65, 45, 46, 7, 55, 91, 75 };
    // int key = 42;


    // selectionSort(arr, n);
    // //printArray(arr, n);

    // int index = binarySearch(arr,n,key);

    // if(index >= 0) {
    //     printf("SUCCESS: found at index %d\n", index);
    // } else {
    //     printf("FAILURE: %d not found\n", key);
    // }

    int n = 10;
    int *brr = generateRandomArray(n);
    brr[9] = 42;
    printArray(brr, n);
    qsort(brr, n, sizeof(int), cmpIntDesc);
    printArray(brr, n);
    int key = 42;
    int *ptr = (int *) bsearch(&key, brr, n, sizeof(int), cmpIntDesc);
    //3rd argument is a pointer to the size because REASONS
    //int *ptr = (int *) lfind(&key, brr, &n, sizeof(int), cmpInt);
    printf("found %d at memory location %p\n", key, ptr);
    printf("location => index: %d\n", (ptr - brr) );


    return 0;
}
```

## Book Demo

* `book.h`:

```c

/**
 * Comparator that orders books by their rating: highest to lowest
 */
int cmpBookByRating(const void *a, const void *b);

/**
 * Comparator that orders books by their author: last name, first name
 * then by year (oldest to newest)
 */
int cmpBookByAuthorYear(const void *a, const void *b);

/**
 * Comparator that orders books by their author: last name, first name
 */
int cmpBookByAuthor(const void *a, const void *b);
```

* `book.c`

```c


int cmpBookByRating(const void *a, const void *b) {
  const Book *x = (const Book *)a;
  const Book *y = (const Book *)b;

  if(x->rating > y->rating) {
    return -1;
  } else if(x->rating < y->rating) {
    return 1;
  } else {
    return 0;
  }
}

int cmpBookByAuthorYear(const void *a, const void *b) {
  const Book *x = (const Book *)a;
  const Book *y = (const Book *)b;

  int result = strcmp(x->author.lastName, y->author.lastName);
  if(result == 0) {
    result = strcmp(x->author.firstName, y->author.firstName);
  }
  if(result == 0) {
    //CAREFUL: this only works because years are *SMALL*
    result = x->publishDate.year - y->publishDate.year;
  }
  return result;
}


int cmpBookByAuthor(const void *a, const void *b) {
  const Book *x = (const Book *)a;
  const Book *y = (const Book *)b;

  int result = strcmp(x->author.lastName, y->author.lastName);
  if(result == 0) {
    result = strcmp(x->author.firstName, y->author.firstName);
  }
  return result;
}
```

* `bookDemo.c`

```c
/**
 * Demonstration code template.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "book.h"

int main(int argc, char **argv) {

    // Book *scythe = createBook("2983479238", "Scythe", "Neal", "Shusterman");
    // Book *dispossessed = createBook("23423532", "The Dispossessed", "Ursula", "le Guin");

    // printBook(scythe);
    // printBook(dispossessed);

    // freeBook(scythe);
    // freeBook(dispossessed);

    // Book goodOmens;
    // initBook(&goodOmens, "987423987", "Good Omens", "Neil", "Gaiman");
    // printBook(&goodOmens);

    int numBooks;
    Book *books = loadBookData("./goodreads-abridged.csv", &numBooks);

    //Find the best/worst books (by rating) using searching/sorting
    qsort(books, numBooks, sizeof(Book), cmpBookByRating);
    Book bestBook = books[0];
    printf("Best book is:\n");
    printBook(&bestBook);
    Book worstBook = books[numBooks-1];
    printf("Worst book is:\n");
    printBook(&worstBook);

    //3. Goal C: find a book/all books by Neil Gaiman
    // sort by author: last, then first
    qsort(books, numBooks, sizeof(Book), cmpBookByAuthor);
    for(int i=0; i<numBooks; i++) {
        printBook(&books[i]);
    }
    //search for "Gaiman, Neil"
    Book key;
    initBook(&key, "", "", 0.0, "Neil", "Gaiman", 0);
    Book *result = (Book *) bsearch(&key, books, numBooks, sizeof(Book), cmpBookByAuthor);

    //OR:
    //Book *key createBook("", "", "Neil", "Gaiman");
    //bsearch(key, books, numBooks, sizeof(Book), cmpBookByAuthorYear);

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
    if(result == NULL) {
        printf("Did not find any such books...\n");
    } else {
        printBook(result);
    }

    return 0;
}
```

```text








```
