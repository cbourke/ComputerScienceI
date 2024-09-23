#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "my_math.h"

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

double agm(double x, double y) {

    double tolerance = 0.00000001;

    if(x < 0 || y < 0) {
        //TODO: what do we do when there are errors?
    } else if( fabs(x - y) < tolerance) {
        return x;
    }

    double a_mean_prev = x, a_mean_curr;
    double g_mean_prev = y, g_mean_curr;

    while( fabs(a_mean_prev - g_mean_prev) > tolerance ) {
        a_mean_curr = (a_mean_prev + g_mean_prev) / 2;
        g_mean_curr = sqrt(a_mean_prev * g_mean_prev);
        a_mean_prev = a_mean_curr;
        g_mean_prev = g_mean_curr;
    }
    return a_mean_curr;

}
