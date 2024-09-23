/**
 * Demonstration code template.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "my_math.h"

int main(int argc, char **argv) {

    const double TOLERANCE = 0.0000001;

    double inputX, inputY, actual, expected;
    int numPassed = 0;
    int numFailed = 0;

    inputX = 24;
    inputY = 6;
    expected = 13.4581714817;
    actual = agm(inputX, inputY);
    if( fabs(expected - actual) <= TOLERANCE) {
        printf("agm(%f, %f) PASSED!\n", inputX, inputY);
        numPassed++;
    } else {
        printf("agm(%f, %f) FAILED!\n", inputX, inputY);
        numFailed++;
    }

    inputX = 13;
    inputY = 42;
    expected = 25.391250597;
    actual = agm(inputX, inputY);
    if( fabs(expected - actual) <= TOLERANCE) {
        printf("agm(%f, %f) PASSED!\n", inputX, inputY);
        numPassed++;
    } else {
        printf("agm(%f, %f) FAILED!\n", inputX, inputY);
        numFailed++;
    }

    int input = 1332894727;
    bool expected_bool = false;
    bool actual_bool = isPrime(input);
    if( expected_bool == actual_bool) {
        printf("isPrime(%d) PASSED!\n", input);
        numPassed++;
    } else {
        printf("isPrime(%d) FAILED!\n", input);
        numFailed++;
    }

    printf("Num passed: %d\n", numPassed);
    printf("Num failed: %d\n", numFailed);
    printf("Percent: %f%%\n", (double) numPassed / (numPassed + numFailed) * 100.0);


    return 0;
}
