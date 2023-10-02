
# CSCE 155H - Computer Science I - Honors
## Arrays & Collections
### Fall 2023

* Almost never deal with just one piece of data
* Instead, you process a *collection* of data
* In both C and Java we have *arrays*: collections of *similar* things (things of the same type)
* In general:
  * Arrays have a single name identifier
  * You access individual elements using an *index*
  * Arrays are always "0-index": the indexing starts at 0
  * You use square bracket notation to access them
  * Example: `arr[0]` is the first element
  * `arr[1]`, `arr[2]`, etc.
  * If an array holds $n$ elements then the last element is at `arr[n-1]`

## Arrays in C

### Static Arrays

* "Static" in this case means that they have a fixed size when they are created
* And: they are allocated on the stack!  


```c

    //create an array of integers that holds up to 10 elements:
    int n = 10;
    int arr[10];

    //what is stored in arr right now?
    //garbage!
    for(int i=0; i<n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    for(int i=0; i<n; i++) {
        arr[i] = (i + 10);
    }

    for(int i=0; i<n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

```

* Since static arrays are allocated on the stack, they exist inside stack frames, those stack frames are destroyed when the function returns
* Stack space is *very* limited: 4MB or 8MB or even kilobytes
* You cannot fit even a "small" array on the stack
* In Java: static arrays are NOT EVEN POSSIBLE!

* Accessing elements outside a valid array in C:
  * Stack smashing events
  * Segmentation Faults
  * Undefined/bad behavior
* Doing so in Java results in: `ArrayIndexOutOfBoundsException`

## Dynamic Arrays

* Dynamic arrays are allocated on the heap space:
  * Much much larger
  * Less organized
  * less efficient (in some ways)
* In C: you allocate memory on the heap by asking the OS = Operating System for a "chunk" of memory (however big you need)
* For example:
  * Want to store 10 million integers
  * We would ask for 40 million bytes (4 bytes each `int`)
* You use the function called `malloc` = *m*emory *alloc*ation
* Malloc:
  * Signature: `void * malloc(size_t n)`
  * You can treat `size_t` as an integer (you are asking for `n` bytes)
  * The return value is a "generic void pointer"
  * a generic void pointers is a raw memory address that can point to *any* type!
  * The returned memory can be used for whatever type you want, this means only one function is necessary
  * When you get the pointer back, you *cast* it to the proper type


```c
int n = 2147000000;
int *arr = NULL;
arr = (int *) malloc(sizeof(int) * n);

//if malloc fails for whatever reason, it returns NULL
if(arr == NULL) {
    printf("memory allocation failed, download more RAM...\n");
    exit(1);
}

//you can now use it as a "regular old" array:
arr[0] = 42;
arr[n-1] = 101;

printf("first and last: %d, %d\n", arr[0], arr[n-1]);
```

* Java:

```java

		int n = 2147000000;
		int arr[] = new int[n];

	    arr[0] = 42;
	    arr[n-1] = 101;

	    System.out.printf("first and last: %d, %d\n", arr[0], arr[n-1]);


```


```text





```
