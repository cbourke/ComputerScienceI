
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


```text











```



