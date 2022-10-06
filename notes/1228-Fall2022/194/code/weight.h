
typedef enum {
    NO_ERROR,
    NULL_POINTER_ERROR,
    NEGATIVE_VALUE_ERROR
} ErrorCode;

/**
 * Converts the given kilogram force (kgf) into the other three units
 * (pounds, ounces, Newtons) using the pass-by-reference variables.
 *
 * Returns a non-zero error code for any error conditions
 */
ErrorCode convertWeight(double kilogramForce, double *pounds, double *ounces, double *newtons);

/**
 * Sums up the values in the given array of double values.
 */
double getSum(const double *arr, int n);