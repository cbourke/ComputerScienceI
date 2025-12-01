
# CSCE 155E - Computer Science I
## Searching & Sorting
### Fall 2025

# Introduction & Demonstration

* Huge part of Computer Science: data processing
* Fundamental operations: *searching*, *sorting*
* Form the basis or preprocessing step of many algorithms
* Large variety of algorithms have been developed

##

* Demo: write a function to search a collection for a particular element
  * What are elements?  `int`?  `double`?  `char *`, `Earthquake`
  * What is a collection? C: arrays, other languages: list, set, map, or other data structures
  * What criteria?  Books: by author, by title, by isbn, etc.
  * What matching criteria: minimum/maximum, equality

## Intuitive Notions

* Larger inputs will take longer time to compute
* But: by how much?
* And: how can we quantify that?
* Before: let's improve the code

### Improving Efficiency

* If the array were *sorted*, how could you exploit that?

```c
int key = 8;
int unsorted[] = {5, 3, 8, 4, 1, 2, 8, 4, 5};
...
int sorted[]   = {1, 2, 3, 4, 4, 5, 5, 8, 8};
                  ^           ^           ^
                  left        middle      right

```

#### Binary Search

* Basic Idea: if the array is sorted, you can exploit that for efficient searching
* Compare your key to the "middle" element $m$
  * If $k = m$: done, you found what you are looking for
  * If $k < m$: search the left half of the array
  * If $m < k$: search the right half of the array
  * Each time you "recurse" you update your left/right index, you effectively cut the array in half each and every time

#### Analysis

* Linear search requires about $n$ comparisons/operations in the worst case for arrays
* Binary search only requires $\approx\log{(n)}$
* Note: all our logs are base-2 unless otherwise stated (we are self respecting computer scientists)
* Binary search is *exponentially* faster than linear search!
* HOWEVER: it requires that the array be *sorted* first!

## Sorting

* How do we sort?

### Selection Sort

* Idea: you search the array for the minimum element then swap it with the first
* Repeat: this idea
  * $i$-th iteration: find the minimum among $i, \ldots, n-1$
  * Swap $i$ and the minimum element
  * Stop when $0, \ldots, n-2$ are sorted, the last element $n-1$ is automatically where it needs to be

### Quick Sort

* It is quick!
* Idea: choose a pivot element (say the first element)
* Divide and conquer algorithm: you partition around the pivot and recursively sort each sub array on each side until you reach an subarray of size of size 1 (or 0), stop
* Partition around that element: lesser elements to the left, greater to the right
* Analysis: omitted (beyond the scope of this course)
* End result: quick sort makes about $n\log{n}$ comparisons

## Sorting in Practice

* In general, you do not need or want to write your own searching/sorting algorithms!
  * Lots of copy-pasta for different types
  * Lots of testing
  * Lots of debugging, etc.
  * Don't roll your own!
* You use one built-in generic sorting/searching algorithm/function/method
* However, the built-in functionality is *generic* so it doesn't know what the elements are or how to compare them.
* You also need to define a *comparator function*

### In C: Comparator Functions

* A comparator function is a function that compares two ***things***, $a, b$ and returns:
  * it returns *something* negative if a < b
  * it returns zero if a is equal to b
  * it returns *something* positive if a > b (b < a)
* In C, the signature of a comparator *MUST* be:  
  `int cmp(const void *a, const void *b)`
* It returns an integer (following the pattern above)
* It takes two arguments: generic void pointers
* The `const` keyword ensures that no changes are made by the comparator function
* Inside the function, you follow a general pattern:
  * You cast the generic void pointers as the actual types that you are comparing
  * You setup a if-else statement to return something negative, zero, or something positive depending on the relative ordering of your arguments

### Sorting with `qsort`

* Once you have a comparator function, you can use it in a call to the standard library's `qsort` function
```c
void qsort(void *base,
           size_t nel,
           size_t size,
           int (*compar)(const void *, const void *));
```

* `base` is the array of elements you are sorting
* `nel` number of elements: size of the array
* `size` is the number of bytes that *each* element in the array takes; ie: `sizeof()`
* `compar` is a function pointer to your comparator (more later); for now just know that you use the function's name

### Searching with `bsearch`

* Binary Search implementation
* Signature:

```c
void *bsearch(const void *key,
              const void *base,
              size_t nel,
              size_t size,
              int (*compar)(const void *, const void *));
```

* `base` is the array you are searching: it is now `const` (ie searching does not change the array!)
* New first parameter: a "key" that you are searching for
* The return type is different:
  * It returns a pointer to **an** element that matches your key
  * If no such element exists, it returns `NULL`

### Linear Searches

* `lfind` - similar to `bsearch` but performs a linear search (does not require the array to be sorted)
* `lsearch` - if the element is not found, it will *try* to insert it at the end

### Misc

#### Stability

* A sorting algorithm is *stable* if it never transposes (swaps) two elements that are equal from the original ordering
* Ex:
  $$10, 3_a, 4, 3_b$$
* A stable sorting algorithm would result in:
  $$3_a, 3_b, 4, 10$$
* An unstable sorting algorithm may produce:
  $$3_b, 3_a, 4, 10$$
* Generally any unstable sorting algorithm can be made stable: by doing more work
* Alternatively: you always use some *universally unique* tie breaker
  * People: NUID, SSN,
  * Books: ISBN
  * Surrogate: UUID
* Quick Sort: unstable
* Selection: unstable

#### Natural vs Artificial orderings

* Consider sorting students by "year": `"Freshman", "Sophomore", "Junior", "Senior"` (artificial ordering)
* But if you sorted them as strings: `"Freshman", "Junior", "Senior", "Sophomore"` ("natural" ordering due
to lexicographic ordering)
* Solution:

```c
typedef enum {
  FRESHMAN,
  SOPHOMORE,
  JUNIOR,
  SENIOR
} Year;

```

# Demo Code

```c

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "array_utils.h"
#include "book.h"

/**
 * Comparator function for integers that orders them in ascending order
 */
int cmpIntAsc(const void *a, const void *b);

/**
 * Comparator function for integers that orders them in descending order
 */
int cmpIntDesc(const void *a, const void *b);

/**
 * Comparator function for doubles that orders them in ascending order
 */
int cmpDoubleDesc(const void *a, const void *b);

/**
 * Comparator function for Books that orders them by title
 */
int cmpBookByTitle(const void *a, const void *b);

/**
 * Comparator function for Books that orders them by year
 */
int cmpBookByYear(const void *a, const void *b);

/**
 * Comparator function for Books that orders them by author then by title
 */
int cmpBookByAuthorTitle(const void *a, const void *b);

/**
 * TODO: document this
 */
void selectionSort(int *arr, int n);

/**
 * Performs an iterative binary search on the array of size n
 * for the given key element.  Returns *an* index at which it
 * finds a matching element, or -1 if no such element exists.
 */
int binarySearchIterative(const int *arr, int n, int key);

/**
 * Performs a binary search on the given array, returns an
 * index at which it finds the key or -1 if no such element exists.
 */
int binarySearchRecursive(const int *arr, int left, int right, int key);

/**
 * Searches the given array of size n for the given key
 * and returns the first index that equals the given key.
 *
 */
int arraySearchInt(const int *arr, int n, int key);

// int main(int argc, char **argv) {

//   //seed the random number generator with the current time
//   time_t start, end;
//   srand(time(NULL));

//   int n = 100000000;
//   int *arr = generateRandomArray(n);
//   //printArray(arr, n);

//   printf("Sorting...\n");
//   start = time(NULL);

//   //TODO
//   //selectionSort(arr, n);
//   qsort(arr, n, sizeof(int), cmpIntAsc);

//   end = time(NULL);

//   int time = (end - start);
//   //printArray(arr, n);
//   printf("Total Computation Time: %d seconds\n", time);

//   return 0;
// }


int main(int argc, char **argv) {

  //TODO: move this to a function
  //Exercise: process a full CSV file
  FILE *f = fopen("./my_goodreads_data.csv", "r");

  char buffer[1000];

  //reads the first line, ignore it...
  char *line = fgets(buffer, 1000, f);
  line = fgets(buffer, 1000, f);
  int numBooks = 0;
  //count up the number of remaining lines
  while(line != NULL) {
    numBooks++;
    //get the next line
    line = fgets(buffer, 1000, f);
  }
  rewind(f);
  //burn the first line
  line = fgets(buffer, 1000, f);
  line = fgets(buffer, 1000, f);

  printf("read %d book records\n", numBooks);

  Book *library = (Book *) malloc( sizeof(Book) * numBooks );

  int i = 0;
  while(line != NULL) {
    //process the current line...
    char *idStr = strtok(buffer, ",");
    int id = atoi(idStr);
    char *title = strtok(NULL, ",");
    char *lastName = strtok(NULL, ",");
    char *firstName = strtok(NULL, ",");
    char *isbn = strtok(NULL, ",");
    char *averageRatingStr = strtok(NULL, ",");
    double averageRating = atof(averageRatingStr);
    char *publisher = strtok(NULL, ",");
    char *yearStr = strtok(NULL, ",");
    int year = atoi(yearStr);
    char *dateRead = strtok(NULL, ",");

    initBook(&library[i], id, title, lastName, firstName, isbn, averageRating, publisher, year, dateRead);
    i++;

    //get the next line
    line = fgets(buffer, 1000, f);
  }
  fclose(f);


  for(int i=0; i<numBooks; i++) {
    char *bookStr = bookToString(&library[i]);
    printf("%s\n", bookStr);
    free(bookStr);
  }

  qsort(library, numBooks, sizeof(Book), cmpBookByYear);

  printf("-=-=-=-=-=-=-=-=-=- BY YEAR -=-=-=-=-=-=-=-=-=- \n");
    for(int i=0; i<numBooks; i++) {
    char *bookStr = bookToString(&library[i]);
    printf("%s\n", bookStr);
    free(bookStr);
  }

  //what is the oldest book?
  Book oldestBook = library[0];
  printf("Oldest book: ");
  printBook(&oldestBook);

  //what is the newest book?
  Book newestBook = library[numBooks-1];
  printf("Newest book: ");
  printBook(&newestBook);

  qsort(library, numBooks, sizeof(Book), cmpBookByAuthorTitle);
  printf("-=-=-=-=-=-=-=-=-=- BY Author/TItle -=-=-=-=-=-=-=-=-=- \n");
  for(int i=0; i<numBooks; i++) {
    char *bookStr = bookToString(&library[i]);
    printf("%s\n", bookStr);
    free(bookStr);
  }

  printf("\n\n\n Searching: \n");

  int arr[] = {9, 5, 8, 3, 4, 0, 1};
  int n = 7;
  int key = 9;
  qsort(arr, n, sizeof(int), cmpIntDesc);
  int *result = (int *) bsearch(&key, arr, n, sizeof(int), cmpIntDesc);
  if(result == NULL) {
    printf("Could not find %d\n", key);
  } else {
    printf("Found %d at memory location %p\n", key, result);
  }

  char title[] = "The Fellowship of the Ring";
  qsort(library, numBooks, sizeof(Book), cmpBookByTitle);
  //want a key that is a Book with its title set to "The Fellowship of the Ring"
  Book *bookKey = createBook(0, title, "", "", "", 0.0, "", 0, "");
  Book *fellowship = bsearch(bookKey, library, numBooks, sizeof(Book), cmpBookByTitle);
  if(fellowship == NULL) {
    printf("Did not find it\n");
  } else {
    printBook(fellowship);
  }


  //clean up
  for(int i=0; i<numBooks; i++) {
    freeBook(&library[i]);
  }
  free(library);


  return 0;
}

int binarySearchRecursive(const int *arr, int left, int right, int key) {

  if(left > right) {
    return -1;
  }

  int middle = (left + right) / 2;
  if(arr[middle] == key) {
    return middle;
  } else if(key < arr[middle]) {
    return binarySearchRecursive(arr, left, middle - 1, key);
  } else if(arr[middle] < key) {
    return binarySearchRecursive(arr, middle + 1, right, key);
  }

}

int arraySearchInt(const int *arr, int n, int key) {
  for(int i=0; i<n; i++) {
    if(arr[i] == key) {
      return i;
    }
  }
  return -1;
}

int binarySearchIterative(const int *arr, int n, int key) {

  int left = 0;
  int right = n-1;

  while( left <= right ) {
    int middle = (left + right) / 2;
    if(arr[middle] == key) {
      return middle;
    } else if(key < arr[middle]) {
      right = middle - 1;
    } else if(arr[middle] < key) {
      left = middle + 1;
    }

  }
  return -1;
}

void selectionSort(int *arr, int n) {

  for(int i=0; i<n-1; i++) {

    int minIndex = i;
    for(int j=i+1; j<n; j++) {
      if(arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }
  return;

}

int cmpIntAsc(const void *a, const void *b) {

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


int cmpDoubleAsc(const void *a, const void *b) {

  const double *x = (const double *)a;
  const double *y = (const double *)b;

  if(*x < *y) {
    return -1;
  } else if(*x > *y) {
    return 1;
  } else {
    return 0;
  }

}


int cmpIntDesc(const void *a, const void *b) {
  return cmpIntAsc(b, a);
}

int cmpBookByTitle(const void *a, const void *b) {

  const Book *x = (const Book *)a;
  const Book *y = (const Book *)b;

  return strcmp(x->title, y->title);

}

int cmpBookByAuthorTitle(const void *a, const void *b) {

  const Book *x = (const Book *)a;
  const Book *y = (const Book *)b;

  int result = strcmp(x->author.lastName, y->author.lastName);
  if(result == 0) {
    result = strcmp(x->author.firstName, y->author.firstName);
  }
  if(result == 0) {
      result = strcmp(x->title, y->title);
  }
  return result;
}

int cmpBookByYear(const void *a, const void *b) {

  const Book *x = (const Book *)a;
  const Book *y = (const Book *)b;

  //THis is the "difference trick" avoid it
  //it is susceptible to overflow/underflow
  return (x->year - y->year);

}

```

```text














```
