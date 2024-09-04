/**
 * Chris Bourke
 * 2024-09-04
 *
 * This program reads in 3 coefficients from the user and uses
 * the quadratic formula to compute the roots of a quadratic polynomial:
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

    printf("Please enter a: ");
    scanf("%lf", &a);

    printf("Please enter b: ");
    scanf("%lf", &b);

    printf("Please enter c: ");
    scanf("%lf", &c);

    double root1 = ( -b + sqrt( pow(b, 2) - 4*a*c ) ) / (2*a);
    double root2 = ( -b - sqrt( pow(b, 2) - 4*a*c ) ) / (2*a);

    printf("The roots of %fx^2 + %fx + %f are %f and %f\n", a, b, c, root1, root2);

    return 0;
}
