#include<stdlib.h>
#include<stdio.h>
#include<stdarg.h>
#include<stddef.h>
#include<setjmp.h>
#include<math.h>
#include<cmocka.h>

#include "colorUtils.h"

/**
 * For CMYK applications, accuracy only needs to be to within
 * 0.01, but other applications may require finer accuracy.
 */
const double EPSILON = 0.01;

/**
 * This function is used to determine if two floating
 * point numbers are "close enough" to each other based
 * on a small EPSILON value
 */
static int isClose(double x, double y) {
  return fabs(x - y) < EPSILON;
}

/**
 * This function tests rgbToCMYK's error handling of NULL
 * values for its pass-by-reference parameters.  Each of
 * the four parameters are tested independently.  The function
 * should return a non-zero error value so we assert that the
 * return value is not equal to zero.
 *
 */
static void testRgbToCmykNull(void **state) {
  double c, m, y, k;
  assert_int_not_equal(rgbToCMYK(0,0,0,NULL,&m,&y,&k), 0);
  assert_int_not_equal(rgbToCMYK(0,0,0,&c,NULL,&y,&k), 0);
  assert_int_not_equal(rgbToCMYK(0,0,0,&c,&m,NULL,&k), 0);
  assert_int_not_equal(rgbToCMYK(0,0,0,&c,&m,&y,NULL), 0);

}

/**
 * This function tests rgbToCMYK's error handling of out-of-range
 * values for the r, g, b parameters, each tested independently.
 * two values are tested each: a less-than-zero value and a value
 * greater than 255.
 */
static void testRgbToCmykOutOfBounds(void **state) {
  double c, m, y, k;
  assert_int_not_equal(rgbToCMYK(-1,127,127,&c,&m,&y,&k), 0);
  assert_int_not_equal(rgbToCMYK(256,127,127,&c,&m,&y,&k), 0);
  assert_int_not_equal(rgbToCMYK(127,-1,127,&c,&m,&y,&k), 0);
  assert_int_not_equal(rgbToCMYK(127,256,127,&c,&m,&y,&k), 0);
  assert_int_not_equal(rgbToCMYK(127,127,-1,&c,&m,&y,&k), 0);
  assert_int_not_equal(rgbToCMYK(127,127,256,&c,&m,&y,&k), 0);
}

/**
 * This function tests rgbToCMYK passing a single, hard-coded
 * rgb-value (Steele Blue, 70, 130, 180).  
 */
static void testRgbToCmyk001(void **state) {
  double c, m, y, k;
  //steel blue:
  rgbToCMYK(70,130,180,&c,&m,&y,&k);
  assert_true(
    isClose(c, .61) &&
    isClose(m, .28) &&
    isClose(y, 0.0) &&
    isClose(k, .29)
  );
}

/**
 * This function is a generic testing function for rgbToCMYK
 * in which the passed state is expected to have 7 double values
 * corresponding to 3 RGB input values and 4 CMYK output values
 * that are known to be equivalent.
 *
 */
static void testRgbToCmykValues(void **state) {
  //cast the generic state to a double array
  double *values = *((double **)state);
  double c, m, y, k;
  rgbToCMYK( (int) values[0], (int) values[1], (int) values[2], &c, &m, &y, &k);
  assert_true(
    isClose(c, values[3]) &&
    isClose(m, values[4]) &&
    isClose(y, values[5]) &&
    isClose(k, values[6])
  );

}

int main(int argc, char **argv) {

  double aquamarine[] =  {127.0, 255.0, 212.0, 0.50, 0.0, 0.17, 0.0};
  double salmon[] = {250, 128, 114, 0.0, 0.49, 0.54, 0.02};

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(testRgbToCmykNull),
    cmocka_unit_test(testRgbToCmykOutOfBounds),
    cmocka_unit_test(testRgbToCmyk001),
    cmocka_unit_test_prestate(testRgbToCmykValues, &aquamarine),
    cmocka_unit_test_prestate(testRgbToCmykValues, &salmon)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);

}
