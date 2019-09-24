#include <math.h>

#include "roundUtils.h"

double roundToCents(double amount) {
  return roundToDigit(amount, -2);
}

double roundToDigit(double value, int digit) {
  double power = pow(10, digit);
  return round(value / power) * power;
}
