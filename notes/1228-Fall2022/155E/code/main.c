#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "massUtils.h"

int main(int argc, char **argv) {


    double kgf = 78.2;
    double expectedLbs = 172.4015;
    double expectedOz = 2758.424;
    double expectedNewtons = 766.88003;
    double actualLbs, actualOz, actualNewtons;
    int expectedError = 0, actualError;
    actualError = convertWeight(kgf, &actualLbs, &actualOz, &actualNewtons);
    if(expectedError != actualError) {
        printf("FAIL: expected %d, got %d\n", expectedError, actualError);
    } else if( fabs(expectedLbs - actualLbs) >= 0.001) {
        printf("FAIL: expected %f, got %f\n", expectedLbs, actualLbs);
    } else {
        printf("PASS, I guess\n");
    }


}