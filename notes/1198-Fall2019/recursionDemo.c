#include <stdlib.h>
#include <stdio.h>

long numFuncCalls = 0;

long recursiveFibMem(int n, long *values) {
  numFuncCalls++;

  //if the table already has the value for fib(n): use it
  if(values[n] > 0) {
    return values[n];
  } else {
    long x = recursiveFibMem(n-1, values) + recursiveFibMem(n-2, values);
    values[n] = x;
    return x;
  }
  

}

long recursiveFib(int n) {
  numFuncCalls++;
  if(n == 0 || n == 1) {
    return 1;
  } else {
    return recursiveFib(n-1) + recursiveFib(n-2);
  }
}

int main(int argc, char **argv) {

  if(argc != 2) {
    fprintf(stderr, "Usage: %s n \n", argv[0]);
    exit(1);
  }
  int n = atoi(argv[1]);

  //set up the table of values:
  long *values = (long *) malloc(sizeof(long) * (n+1));
  //set up your base cases and "flag" values:
  for(int i=0; i<n+1; i++) {
    values[i] = 0;
  }
  values[0] = 1;
  values[1] = 1;

  long x = recursiveFibMem(n, values);
  printf("fib(%d) = %ld, number of calls: %ld\n", n, x, numFuncCalls);

  return 0;
}
