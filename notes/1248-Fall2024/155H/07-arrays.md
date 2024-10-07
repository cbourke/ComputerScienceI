
# CSCE 155H - Computer Science I - Honors
## Arrays & Collections
### Fall 2024

* Almost never deal with just one piece of data
* Instead you deal with *collections* of data
* Both C and Java support old-school *arrays* collections of *similar* things (things of the same type: `int`, `double`, etc.) all stored *contiguously*
* In general:
  * Arrays have a single *identifier* (variable name)
  * YOu access each individual *element* using an *index*
  * Arrays always start at the 0-index
  * YOu use square brackets to access each element
  * Ex: first is at `arr[0]`, the second is at `arr[1]`, etc.
  * If there are `n` elements in an array the last one is at `arr[n-1]`

## Arrays in C

### Static Arrays

* "Static" here means that it has a fixed size when created and they are stored on the program's stack

```c

    int x;

    //integer array that holds 10 integers:
    int arr[10];
    int n = 10; //size of arr

    //a double array that can hold 20 doubles:
    int brr[20];

    arr[0] = 42;
    arr[9] = 101;
    //we're only screwing up our own memory; maybe we'll get away with it!
    //arr[10] = 1234;
    //arr[-1] = 4321;

    //there are no default values for arrays, likely garbage or 0xDEADBEEF
    for(int i=0; i<n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    //you need to set them:
    for(int i=0; i<n; i++) {
        arr[i] = 10 * i;
    }

    for(int i=0; i<n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
```

* Since static arrays are allocated on the stack, they exist inside stack frames, those stack frames are destroyed when the function returns
* Stack space is *very* limited: 4MB or 8MB or even kilobytes
* You cannot fit even a "small" array on the stack
* In Java: static arrays are NOT EVEN POSSIBLE!

## Dynamic Arrays

* Dynamic arrays are allocated not on the stack but on the *heap*
  * Much larger
  * Less organized
  * Less efficient (in some ways)
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



```text









```
