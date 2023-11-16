
# CSCE 155H - Computer Science I
## Algorithms, Searching & Sorting
### Fall 2023

# Introduction & Demonstration

* Huge part of Computer Science: data processing
* Fundamental operations: *searching*, *sorting*
* Form the basis or preprocessing step of many algorithms
* Large variety of algorithms have been developed  

## Demo

* Demo: write a function to search a collection for a particular element

## Searching and Sorting in Practice

* In general you do *not* write your own implementations of searching/sorting
* You use built-in functions for doing so
* Those built-in functions are *generic*: they can take an array/list of any type of thing
* Problem: it doesn't know what those "things" are or *how* to compare them
* To compare, you provide the search/sort function with a *comparator*

### Comparator in C

* In C, a *comparator function* is a function that compares two  generic elements $a, b$ and returns:
  * it returns *something* negative if a < b
  * it returns zero if a is equal to b
  * it returns *something* positive if a > b (b < a)
* In C the signature of a comparator function *MUST* Be:

`int cmp(const void *a, const void *b)`

* returns an integer
* takes two arguments
* *both* must be `const` and are unchangeable
* Both are *generic void pointers*: pointers that can point to any data type (`int`, `double`, `Book`, etc)
* Inside a comparator function, you follow the general pattern:
  1. You *cast* the two generic pointers as the types of data you expect
  2. Now that they are of a type you can deal with, you compare them: you return something positive/negative/zero depending on the order you want

### Comparators in Java



```text







```
