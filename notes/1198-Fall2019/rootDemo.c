#include <stdlib.h>
#include <stdio.h>

#include "roots.h"

int main(int argc, char **argv) {
  
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  int c = atoi(argv[3]);
  double r1, r2;
  
  int errorCode = computeRoots(a, b, c, &r1, &r2);
  
  if(errorCode == DIVISION_BY_ZERO_ERROR) {
    //we have a linear function, there is only one root
    //bx + c = 0, x = -c / b
    printf("You have a linear function with solution = %f\n", (-c / (double)b));
  } else if(errorCode == COMPLEX_ROOT_ERROR) {
    printf("use a complex number library!\n");
  } else if(errorCode == NULL_POINTER_ERROR) {
    printf("Bad pointers or something\n");
  } else if(errorCode == NO_ERROR){
    printf("Roots of %dx^2 + %dx + %d are %f and %f\n", a, b, c, r1, r2);
  } else {
    printf("something went really wrong: invalid error code\n");
  }
  return 0;
}

