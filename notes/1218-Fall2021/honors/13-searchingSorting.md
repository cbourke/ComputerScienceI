
# CSCE 155H - Computer Science I
## Algorithms, Searching & Sorting
### Fall 2021

# Introduction & Demonstration

* Huge part of Computer Science: data processing
* Fundamental operations: *searching*, *sorting*
* Form the basis or preprocessing step of many algorithms
* Large variety of algorithms have been developed

## Linear Search

* Basic Idea; given a collection of elements and a key element $k$, search through the collection to find any element that "matches" $k$
* What are you searching?  An array, a list, set
* What is it a collection of? Integers, doubles, strings, airports, etc.
* How are you searching?
* Searching for a particular element or the first or the last, max or the min, or all elements that match your search criteria
* More generally: you take an algorithm perspective and design *pseudocode*

### Analysis

* A linear algorithm performs a number of operations (for our purposes, we'll focus on comparisons)
* Best case scenario: it takes 1 comparison (finds it at index 0)
* Worst case scenario: $n$ comparisons (for a collection of size $n$); happens when it is at index $n-1$ or unsuccessful search
* Average case: you make about $\approx \frac{n}{2}$ comparisons
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

## Searching and Sorting in Practice

* In general you do not write your own searching/sorting algorithms
* You use one built-in generic sorting/searching algorithm/function/method
* However, the built-in functionality is *generic* so it doesn't know what the elements are or how to compare them.
* You also need to define a *comparator function* (C) or a `Comparator` in Java

### Comparators in C

* In C, a *comparator function* is a function that compares two  generic elements $a, b$ and returns:
  * it returns *something* negative if a < b
  * it returns zero if a is equal to b
  * it returns *something* positive if a > b (b < a)
* In C the signature of a comparator function *MUST* Be:

`int cmp(const void *a, const void *b)`

* returns an integer
* takes two arguments
* both use `const` and so are unchangeable
* both are *generic void pointers*
* Inside the function you follow a general pattern:
  * You cast the generic void pointers as the actual types that you are comparing
  * You setup a if-else statement to return something negative, zero, or something positive depending on the relative ordering of your arguments
* Exercise: write a comparator function for integers that orders them in increasing order...

### `Comparator`s in Java

* Typically you define an *anonymous* in-line class

```java
List<Integer> numbers = ...;

Comparator<Integer> cmpInt = new Comparator<Integer>() {

  public int compare(Integer a, Integer b) {
     if(a < b) {
       return -1;
     } else if(a > b) {
       return 1;
     } else {
       return 0;
     }
     return a.compareTo(b);
  }

};

Collections.sort(numbers, cmpInt);

```

```text






```
