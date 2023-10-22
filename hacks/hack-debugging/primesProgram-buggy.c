#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int sum(int *arr, int n);
int* getPrimes(int n);
int isPrime(int x);

int main(int argc, char **argv) {
  int n = 10; // Default to the first 10 primes
  if (argc == 2) {
    n = atoi(argv[1]); // Corrected the argument parsing
  }
  int *primes = getPrimes(n);
  int s = sum(primes, n);
  printf("The sum of the first %d primes is %d\n", n, s);

  free(primes); // Free the dynamically allocated primes array
  return 0;
}

int sum(int *arr, int n) {
  int i;
  int total = 0; // Initialize total to 0
  for (i = 0; i < n; i++) {
    total += arr[i]; // Corrected the addition operator
  }
  return total;
}

int* getPrimes(int n) {
  int *result = (int *)malloc(n * sizeof(int)); // Dynamically allocate the result array
  if (result == NULL) {
    fprintf(stderr, "Memory allocation failed.\n");
    exit(1);
  }
  int i = 0;
  int x = 2;
  while (i < n) {
    if (isPrime(x)) {
      result[i] = x;
      i++;
    }
    x += 1; // Increment x by 1, not 2, to find all prime numbers
  }
  return result;
}

int isPrime(int x) {
  if (x <= 1) {
    return 0; // Numbers less than or equal to 1 are not prime
  }
  if (x <= 3) {
    return 1; // 2 and 3 are prime
  }
  if (x % 2 == 0 || x % 3 == 0) {
    return 0; // Numbers divisible by 2 or 3 are not prime
  }
  for (int i = 5; i * i <= x; i += 6) {
    if (x % i == 0 || x % (i + 2) == 0) {
      return 0; // Check divisors of the form 6k ± 1
    }
  }
  return 1;
}







  

