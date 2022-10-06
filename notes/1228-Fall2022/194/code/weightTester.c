#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "weight.h"

int main(int argc, char **argv) {

    //test the weight conversion:
    double kgf = 100.0;
    double expectedPounds = 220.462;
    double expectedOunces = 3527.392;
    double expectedNewtons = 9.80665;
    double actualPounds, actualOunces, actualNewtons;
    int errorCode = convertWeight(kgf, &actualPounds, &actualOunces, &actualNewtons);
    if(errorCode != 0) {
        printf("FAIL\n");
    } else if( fabs(actualPounds - expectedPounds) ) {
        printf("FAIL\n");
    }

    //using arrays and functions:
    // often you need to pass an array to a function
    // Ex: pass an array of weights to a function to sum them up!
    int n = 5;
    double weights[] = {42.5, 98.1, 4324.23, 123.45};
    double total = getSum(weights, n);
    printf("total = %f\n", total);

    total = getSum(weights, n);
    printf("total = %f\n", total);

    return 0;
}