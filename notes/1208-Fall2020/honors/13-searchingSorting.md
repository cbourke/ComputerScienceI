
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

```text










```