#include <stdlib.h>

#include "massUtils.h"

ErrorCode convertWeight(double kgf, double *lbs, double *oz, double *newtons) {

    if(lbs == NULL || oz == NULL || newtons == NULL) {
        return NULL_POINTER_ERROR;
    } else if(kgf < 0) {
        return NEGATIVE_VALUE_ERROR;
    }

    *lbs = 2.20462 * kgf;
    *oz = 2.20462 * 16 * kgf;
    *newtons = 9.80665 * kgf;

    return NO_ERROR;
}

