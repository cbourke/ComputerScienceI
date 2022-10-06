

#include <stdlib.h>

#include "weight.h"

ErrorCode convertWeight(double kilogramForce, double *pounds, double *ounces, double *newtons) {

  if(pounds == NULL || ounces == NULL || newtons == NULL) {
    return NULL_POINTER_ERROR;
  } else if (kilogramForce < 0) {
    return NEGATIVE_VALUE_ERROR;
  }

  *pounds  = kilogramForce * 2.20462;
  *ounces  = kilogramForce * 2.20462 * 16;
  *newtons = kilogramForce * 9.80665;

  return NO_ERROR;

}

double getSum(const double *arr, int n) {
    double total = 0.0;
    for(int i=0; i<n; i++) {
        total += arr[i];
        //arr[i] = -1;
    }
    return total;
}