/**
 * This program computes the number of primes from 2 to n (inclusive).
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/**
 * Returns true if the given integer x is prime, false if it is
 * composite.
 */
bool isPrime(int x);

int main(int argc, char **argv) {

    int n = 1000000000;
    int numPrimes = 0;

    for(int x=2; x<=n; x++) {
        //determine if x is prime or not
        //for each potential divisor d = 2...n, test if x is divisible by d
        if( isPrime(x) ) {
            numPrimes++;
        }

    }
    printf("number of primes 2 to %d is %d\n", n, numPrimes);


    return 0;
}

bool isPrime(int x) {

    if(x<=1) {
        return false;
    } else if(x == 2) {
        return true;
    } else if(x % 2 == 0) {
        return false;
    } else {
        for(int d=3; d<=sqrt(x); d+=2) {
            if(x % d == 0) {
                //x is NOT prime, it is COMPOSITE
                return false;
            }
        }
        return true;
    }
}
