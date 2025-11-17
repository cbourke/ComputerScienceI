
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

```text














```
