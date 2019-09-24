#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "roundUtils.h"

int main(int argc, char **argv) {
  
  double x = 123.456;
  double y;
  int numPassed = 0;
  int numFailed = 0;
  
  y = roundToCents(x);
  if( fabs(y - 123.46) > 0.00001) {
    printf("FAILED: expected 123.46, but got %f\n", y);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  y = roundToDigit(x, -2);
  printf("y = %f\n", y);

  y = roundToDigit(x, 0);
  printf("y = %f\n", y);

  y = roundToDigit(x, 2);
  printf("y = %f\n", y);
  
  printf("Number failed: %d\n", numFailed);
  
  return 0;
}