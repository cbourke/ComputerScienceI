
# CSCE 155E - Computer Science I
## Searching & Sorting: Wrap up
### CSCE 155E, Fall 2019

## Searching In Practice

* As with sorting: you don't roll your own
* Search library: `search.h`: `lfind` and `lsearch`: RTM
* Standard library: `bsearch()`:

```c
void * bsearch(const void *key,
               const void *base,
               size_t nel,
               size_t size,
               int (*compar) (const void *, const void *));
```

* Remember: you must always search using the same comparator (or ordering) as you sorted with
* Remember: to use binary search, you must always have a sorted array

## Artificial vs "Natural" ordering:

* Consider the `Student` structure from before
* Artificial ordering: "Freshmen", "Sophomore", "Junior", "Senior"
* Natural Ordering: "Freshmen", "Junior", "Senior", "Sophomore"

## Sorting Stability

* Consider the following values: 
  3A, 7, 3B, 1
  1, 3B, 3A, 7 
* Sorted it would like:
  1, 3, 3, 7
* If a sorting algorithm never puts two otherwise equal elements out of order, then it is called stable
* Selection sort is not stable, quick sort *can* be stable 

## Sorting Strings

* When passing an array of strings to `qsort` it will pass the strings to your comparator by reference 
* Meaning that the `char *` (strings) become a `char **` (a pointer to a string), so
* IN the comparator you need to cast them as `char **` and dereference to recover `char *` 
* THEN you can use `strcmp`

```c
#include <stdlib.h>
#include <stdio.h>

int cmpInt(const void *a, const void *b) {
  const int *x = (const int *) a;
  const int *y = (const int *) b;
  if(*x < *y) {
    return -1;
  } else if(*x > *y) {
    return 1;
  } else {
    return 0;
  }
}

int cmpDouble(const void *a, const void *b) {
  const double *x = (const double *) a;
  const double *y = (const double *) b;
  if(*x < *y) {
    return -1;
  } else if(*x > *y) {
    return 1;
  } else {
    return 0;
  }
}

/**
 * This function searches the given array
 * and returns the maximum value in it
 */
int getMaxInt(const int *arr, int n) {

  int max_index = 0;
  for(int i=1; i<n; i++) {
    if(arr[i] > arr[max_index]) {
      max_index = i;
    }
  }
  return arr[max_index];
}

int getMaxGeneric(const void *arr, 
                  int n,
                  int size,
                  int (*compar)(const void *, const void *)) {
  int max_index = 0;
  for(int i=1; i<n; i++) {
    //get the address of the i-th element:
    const void *A = arr + i * size;
    //get the adddress of the max_index-th element:
    const void *B = arr + max_index * size;
    if( compar(A, B) > 0) {
      max_index = i;
    }
  }
  return max_index;
}

int main(void) {
  int n = 8;
  int arr[] = {5, 9, 0, 1, 3, 10, 2, 7};
  int index = getMaxGeneric(arr, n, sizeof(int), cmpInt);
  printf("Max value is %d at index %d\n", arr[index], index);
  return 0;
}

```

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpString(const void *a, const void *b) {
  const char **x = (const char **) a;
  const char **y = (const char **) b;
  return strcmp(*x, *y);
}

int main(void) {

  char *names[] = {
    "Chris", "Margaret", "Alan", "Grace", "Zeppo"
  };
  qsort(names, 5, sizeof(char *), cmpString);

  for(int i=0; i<5; i++) {
    printf("%s\n", names[i]);
  }

  return 0;
}
```


```c
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  FRESHMAN,
  SOPHOMORE,
  JUNIOR,
  SENIOR
} ClassYear;

const char *yearToStringArr[] = {"Freshman", "Sophomore", "Junior", "Senior"};

const char *yearToString(ClassYear year) {
  return yearToStringArr[year];
}

typedef struct {
  int nuid;
  char *firstName;
  char *lastName;
  double gpa;
  ClassYear year;
} Student;

int main(void) {

  return 0;
}
```


```c
#include <stdio.h>
#include <stdlib.h>


int cmpInt(const void *a, const void *b) {
  const int *x = (const int *)a;
  const int *y = (const int *)b;
  if(*x < *y) {
    //avoid the difference trick: return *x - *y
    //suceptible to overflow
    return -1;
  } else if(*x > *y) {
    return 1;
  } else {
    return 0;
  }
  return 0;
}



int cmpIntDesc(const void *a, const void *b) {
  return cmpInt(b, a);
}

int cmpDouble(const void *a, const void *b) {
  const double *x = (const double *)a;
  const double *y = (const double *)b;
  if(*x < *y) {
    //avoid the difference trick: return *x - *y
    //.5 - .75 = -.25 -> 0
    return -1;
  } else if(*x > *y) {
    return 1;
  } else {
    return 0;
  }
  return 0;
}


int main(void) {
  int n = 10;
  int key = 21;
  int arr[] = {6, 3, 9, 4, 1, 8, 3, 12, 2, 21};
  qsort(arr, n, sizeof(int), cmpInt);
  for(int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }

  int *needle = bsearch(&key, arr, n, sizeof(int), cmpDouble);
  if(needle == NULL) {
    printf("did not find element\n");
  } else {
    printf("found %d at memory address %p which contains the value %d", key, needle, *needle);
  }
  return 0;
}
```