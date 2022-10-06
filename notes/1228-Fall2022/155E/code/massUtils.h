
typedef enum {
  NO_ERROR,
  NULL_POINTER_ERROR,
  NEGATIVE_VALUE_ERROR,
} ErrorCode;

/**
 * This function converts the given kilogram force value to the other
 * three units (pounds, ounces, newtons) using the three pass-by-reference
 * variables.
 *
 * Returns a non-zero error code for any error conditions
 */
ErrorCode convertWeight(double kgf, double *lbs, double *oz, double *newtons);