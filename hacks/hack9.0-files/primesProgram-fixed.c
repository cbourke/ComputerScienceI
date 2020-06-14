/**
 * This program computes the sum of the first n
 * prime numbers.  Optionally, it allows the user
 * to provide n as a command line argument, but
 * defaults to the first n = 10 primes
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * This function takes an integer array (of size n) and
 * returns the sum of its elements.  It returns 0 if the
 * array is NULL or if its size is <= 0
 */
int sum(int *arr, int n);

/**
 * This function returns an array containing the first
 * n prime numbers
 */
int* getPrimes(int n);

/**
 * This function determines returns true if the give
 * integer is prime and false otherwise.
 */
int isPrime(int x);

int main(int argc, char **argv) {

  int n = 10; //default to the first 10 primes
  if(argc == 2) {
    n = atoi(argv[1]);
  }
  int *primes = getPrimes(n);

  int s = sum(primes, n);
  printf("The sum of the first %d primes is %d\n", n, s);

  return 0;
}

int sum(int *arr, int n) {
  int i;
  int total = 0;
  for(i=0; i<n; i++) {
    total += arr[i];
  }
  return total;
}

int* getPrimes(int n) {
  int *result = (int *) malloc(sizeof(int) * n);
  result[0] = 2;
  int i = 1;
  int x = 3;
  while(i < n) {
    if(isPrime(x)) {
      result[i] = x;
      i++;
    }
    x += 2;
  }
  return result;
}

int isPrime(int x) {

  if(x < 2) {
    return 0;
  } else if(x == 2) {
    return 1;
  } else if(x % 2 == 0) {
    return 0;
  }
  for(int i=3; i<=sqrt(x); i+=2) {
    if(x % i == 0) {
      return 0;
    }
  }
  return 1;
}
