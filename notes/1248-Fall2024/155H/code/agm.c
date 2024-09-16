/**
 * Chris Bourke
 * 2024-09-13
 *
 * This program reads command line arguments for two numbers
 * and computes and outputs their arithmetic–geometric.  See
 *
 * <a href="https://en.wikipedia.org/wiki/Arithmetic%E2%80%93geometric_mean">here</a>
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(int argc, char **argv) {

    const double tolerance = 0.0000001;

    if(argc != 3) {
        printf("ERROR: expected 2 numbers\n");
        exit(1);
    }
    double x = atof(argv[1]);
    double y = atof(argv[2]);

    if(x < 0 || y < 0) {
        printf("ERROR: both values should be non-negative\n");
        exit(2);
    } else if( fabs(x - y) < tolerance) {
        printf("agm(%f, %f) = %.20f\n", x, y, x);
        exit(0);
    }

    double a_mean_prev = x, a_mean_curr;
    double g_mean_prev = y, g_mean_curr;

    while( fabs(a_mean_prev - g_mean_prev) > tolerance ) {
        a_mean_curr = (a_mean_prev + g_mean_prev) / 2;
        g_mean_curr = sqrt(a_mean_prev * g_mean_prev);
        a_mean_prev = a_mean_curr;
        g_mean_prev = g_mean_curr;
    }
    printf("agm(%f, %f) = %.20f\n", x, y, a_mean_curr);



    return 0;
}
