#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>



int *randomArr(int n) {
  int *a = (int *)malloc(sizeof(int)*n);
  for(int i=0; i<n; i++) {
    a[i] = rand() % 100;
  }
  return a;
}

void printArray(const int *arr, int n) {
  if(arr == NULL) {
    printf("[null]\n");
    return;
  }
  printf("[ ");
  for(int i=0; i<n-1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("%d ]\n", arr[n-1]);
  return;
}

/**
 * This is a comparator for integers that orders them in ascending
 */
int cmpIntAscending(const void *a, const void *b) {


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

/**
 * This is a comparator for integers that orders them in descending
 */
int cmpIntDescending(const void *a, const void *b) {

  return cmpIntAscending(b, a);

}


int main(int argc, char **argv) {

  srand(time(NULL));

  //selection sort: 1,000,000: 20 minutes
  //selection sort: 10,000,000: 2000 minutes = 33 hours
  //selection sort: 100,000,000: 2000 minutes = 3300 hours = 4.5 months

  int n = 10;
  int *arr = randomArr(n);

  qsort(arr, n, sizeof(int), cmpIntAscending);


  return 0;
}