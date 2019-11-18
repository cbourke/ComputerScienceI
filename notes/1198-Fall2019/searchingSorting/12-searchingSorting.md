
# CSCE 155E - Computer Science I
## Searching & Sorting
### CSCE 155E, Fall 2019

Searching & Sorting
====================

* Processing data is a fundamental operation in Computer Science
* Two fundamental operations in processing data are *searching* and *sorting*
* Form the basis or preprocessing step of many algorithms
* Large variety of algorithms have been developed

## Searching

* *What* are you searching: an array or another data structure?  Strings, integers, doubles or user defined types (Students, Airports, etc.)
* *How* are you searching: not algorithmically but by what *criteria* are you searching?
* You could search for a particular element: minimum, maximum, median, mode, etc.
* How do you determine a successful or unsuccessful search?
* There are many basic and advanced criteria that you can search for: you have to be specific when coding, but be GENERAL when talking about algorithms

## Linear Search

```c
/**
 * This function searches the given array of integers
 * which is of size n for the given key element.
 * 
 * This function returns an index value of the
 * element that first matches the key.
 * 
 * This function returns -1 in the event that 
 * no such value is found or an error is encountered.
 */
int linearSearch(const int *arr, int n, int key) {
  if(arr == NULL || n < 0) {
    return -1;
  }
  for(int i=0; i<n; i++) {
    if(arr[i] == key) {
      return i;
    }
  }
  return -1;
} 

int linearSearchForDoubles(const double *arr, int n, double key) {
 if(arr == NULL || n < 0) {
   return -1;
 }
 for(int i=0; i<n; i++) {
   if(arr[i] == key) {
     return i;
   }
 }
 return -1;
} 

int linearSearchForStrings();
int linearSearchForAirportsByGPSId();
int linearSearchForAirportsByState();
```

* Practical Problem: the above solution is only
good for searching: integers
* Our ultimate goal: write ONE function that searches
ANY type of data by ANY criteria


## Binary Search

* Linear search requires about n/2 comparisons/operations on average
* Can you do better?
* Consider: what if the array is already sorted?
* Consider the middle element m at index n/2:
  * if the key is equal to m: stop, you found your needle in the haystack
  * if key < m: proceed to search in the left half of the array (indices 0 thru n/2-1)
  * if m < key: proceed to search in the right half of the array (indices n/2+1 thru n-1)
* Why does this help?  Each comparison removes about half of the array each time!
* There is a clear "recursive" or "divide and conquer" strategy to this algorithm
* We'll develop an *iterative* version of binary search

```c
#include <stdio.h>

int binarySearch(const int *arr, int n, int key) {
  int left = 0;
  int right = n-1;

  while(left <= right) {
    //bad in practice: susceptible to overflow:
    //int m = (left + right) / 2;
    //better solution:
    int m = left + (right - left) / 2;
    if(arr[m] == key) {
      return m;
    } else if(arr[m] < key) {
      //search the right half:
      left = m + 1;
    } else if(key < arr[m]) {
      //search the left half:
      right = m - 1;
    }
  }
  return -1;
}

int linearSearch(const int *arr, int n, int key) {
  if(arr == NULL || n < 0) {
    return -1;
  }
  for(int i=0; i<n; i++) {
    if(arr[i] == key) {
      return i;
    }
  }
  return -1;
}  

int main(void) {

  int n = 9;
//unsorted requires linear search:
//  int arr[] = {5, 9, 3, 4, 0, 1, 4, 5, 2};
  int arr[] = {0, 1, 2, 3, 4, 4, 5, 5, 9};
  int key = 5;
  int indexOf = binarySearch(arr, n, key);
  printf("found %d at index %d\n", key, indexOf);


  return 0;
}
```


### Analysis

* Suppose you have an array of $n$ elements
* How many comparisons does linear search perform to search the given array?
  * Best case scenario: you find the key at the first element: one comparison!
  * Worst case scenario: you find the key at the end of the array (or you don't find it at all): $n$ comparisons
  * Average case scenario: naive analysis:
    $$\frac{n + 1}{2} \approx \frac{n}{2}$$
  * Both the average and worst cases are *linear*
* Binary Search?
  * Derivation: whitepaper and in the book
  * Only takes about $\log_2{(n)}$ comparisons

#### Perspective

* Suppose you have a database of $10^{12}$ (1 trillion) elements
  * If unsorted you would have to use linear search to find a particular element:
    $$500 \times 10^{11}$$
  500 billion comparisons
  * If sorted (indexed) then you can exploit the sort using binary search:
    $$\log_2{(10^{12})} < 40$$

* Another perspective: suppose you "double" the input size of an array
  $$n \rightarrow 2n$$
  * linear search: the number of comparisons goes from
  $$\frac{n}{2} \rightarrow n$$
  The number of comparisons doubles
  * binary search:
  $$\log_2{(n)} \rightarrow \log_2{(2n)} = \log_2{(n)} + \log_2{(2)} = \log_2{(n)} + 1$$

## Sorting

* Huge variety of sorting algorithms with different algorithmic strategies and different performances

### Selection Sort

* Basic idea: 



