
# CSCE 155E - Computer Science I
## Arrays
### Fall 2020

* It is really rare that you only deal with say one variable or one piece of data
* You usually want to process or operate on a *collection* of pieces of data
* In C, collections of similar pieces of data can be stored *arrays*
  * Arrays are a collection of variables of the same type
  * Arrays have a single identifier (name)
  * Elements in an array can be accessed using an *index*: the first element is always at index 0.  The second is at index 1, etc.
  * If there are `n` element in an array, the last one is at index `n-1`
  * Indexing is achieved using square brackets: `a[0]` would be the first element
  
## Static Arrays

* Static arrays are arrays of a fixed size that are allocated on top of the program stack
* Syntax:

```c
//create an array that can hold 10 integers:
int arr[10];

//create an array that can hold 20 doubles:
double numbers[20];
```

Observations:
* Just like any other uninitialized variables, the contents of the an array have no default values
* Generally, there is random garbage stored in uninitialized arrays
* Once you have an array though, you can start setting the values using indexing and the normal assignment operator

```c
arr[0] = 42;
arr[1] = -5;
arr[2] = 3.5; //truncation: results in 3
arr[9] = 42; //sets the last value

//uh oh:
arr[10] = 101;
arr[-1] = 102;
```

* Accessing elements outside an array is *undefined behavior*
  * MAY be a segmentation fault
  * MAY be a stack smashing 
  * MAY simply corrupt your own memory
  * It may or may not result in bad consequences, but it is just not good!

## More Syntax

* You can declare an initialize a static array in one line:

```c
int n = 7;
int primes[] = {2, 3, 5, 7, 11, 13, 17};
```

* In general, there is NO WAY to determine the size of an array after it has been created in C
* In C, YOU *must* keep track of the size of every array that you create; this is known as *memory management* 
* Also called "bookkeeping"
* It is *your* responsibility to keep track of all teh sizes of every array
* Consequence: if you pass an array to a function, you *also* need to pass the *size* of the array to the function (in general this is a separate integer value)
* Example: declare an array of size 100, set each element equal to 1, 2, 3, ... 100, then print the elements in the array then sum up all values


```text






```