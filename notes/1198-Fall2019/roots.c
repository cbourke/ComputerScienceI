#include <math.h>
#include <stdlib.h>

#include "roots.h"

double firstRoot(int a, int b, int c) {
  
  return (-b + sqrt(b*b - 4*a*c)) / (2*a);
}

double secondRoot(int a, int b, int c) {
  
  return (-b - sqrt(b*b - 4*a*c)) / (2*a);
}

RootError computeRoots(int a, int b, int c, double *root1, double *root2) {

  //potential errors?
  if(a == 0) {
    return DIVISION_BY_ZERO_ERROR;
  } else if(b*b - 4*a*c < 0) {
    return COMPLEX_ROOT_ERROR;
  } else if(root1 == NULL || root2 == NULL) {
    return NULL_POINTER_ERROR; 
  } else {
    *root1 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
    *root2 = (-b - sqrt(b*b - 4*a*c)) / (2*a);
    return NO_ERROR;
  }
}

