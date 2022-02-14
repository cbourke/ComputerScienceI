#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(int argc, char **argv) {

    double tolerance = 0.000001;

    double x = 42;
    double y = 103;

    double amPrev, gmPrev;
    double amCurr = (x + y) / 2;
    double gmCurr = sqrt(x * y);

    while( fabs(amCurr - gmCurr) > tolerance ) {
      amPrev = amCurr;
      gmPrev = gmCurr;

      amCurr = (amPrev + gmPrev) / 2;
      gmCurr = sqrt(amPrev * gmPrev);

    }
    printf("agm(%f, %f) = %f\n", x, y, amCurr);


    return 0;
}