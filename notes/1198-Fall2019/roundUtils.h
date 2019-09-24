
/**
 * This function rounds the given value to a decimal
 * places defined by the given digit.
 * For example for 
 *   value = 123.456 and digit = 2 it would round to 100
 *   value = 123.456 and digit = 0 it would round to 123
 *   value = 123.456 and digit = -2 it would round to 123.46
 */
double roundToDigit(double value, int digit);

/**
 * This function rounds the given amount to the 
 * nearest hundredth (ie the nearest cent) and
 * returns the value.
 *
 */
double roundToCents(double amount);