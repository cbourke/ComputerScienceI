/**
 * TODO: do the documentation later
 */
typedef enum {
  NO_ERROR,
  DIVISION_BY_ZERO_ERROR,
  NULL_POINTER_ERROR,
  COMPLEX_ROOT_ERROR,
} RootError;

/**
 * Computes the first root of a quadratic
 * polynomial with the given coefficients.
 */
double firstRoot(int a, int b, int c);

/**
 * Computes the second root of a quadratic
 * polynomial with the given coefficients.
 */
double secondRoot(int a, int b, int c);

/**
 * Computes the roots of a quadratic
 * polynomial with the given coefficients, 
 * placing the results in the two variables
 * pased by reference.
 * 
 * Returns an error code (see RootError) in 
 * the event of an error
 */
RootError computeRoots(int a, int b, int c, double *root1, double *root2);
