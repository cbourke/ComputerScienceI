/**
 * Chris Bourke
 * 2024-09-04
 *
 * This program reads in 3 coefficients (from command line arguments)
 * and uses the quadratic formula to compute the roots of a quadratic polynomial:
 *
 * ax^2 + bx + c
 *
 * See more at <a href="https://en.wikipedia.org/wiki/Quadratic_formula">here</a>.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

    double a, b, c;

    //if argc is not 4, then we have error...
    if(argc != 4) {
        printf("ERROR: you need to provide a, b, c as command line arguments!\n");
        exit(1);
    }

    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);

    //if a is zero, this is not a quadratic equation
    if(a == 0) {
        printf("ERROR: a cannot be zero, that is a linear equation, you know how to solve that!\n");
        exit(1);
    }

    double root1 = ( -b + sqrt( pow(b, 2) - 4*a*c ) ) / (2*a);
    double root2 = ( -b - sqrt( pow(b, 2) - 4*a*c ) ) / (2*a);

    printf("The roots of %fx^2 + %fx + %f are %f and %f\n", a, b, c, root1, root2);

    return 0;
}
