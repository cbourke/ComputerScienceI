/**
 * This is a collection of unit tests and
 * test functions for a color utilities C
 * library.
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <math.h>
#include <cmocka.h>
#include <time.h>

#include "colorUtils.h"

/**
 * For CMYK applications, accuracy only needs to be to within
 * 0.01, but other applications may require finer accuracy.
 */
const double EPSILON = 0.01;

/**
 * For randomized cyclical testing, this determines the number of
 * tests to run
 */
const int RANDOM_TEST = 1000;

/**
 * This function is used to determine if two floating
 * point numbers are "close enough" to each other based
 * on a small EPSILON value
 */
static int isClose(double x, double y) {
  return fabs(x - y) < EPSILON;
}

/**
 * This function is used to determine if two integer
 * numbers are "close enough" to each other; specifically
 * if their difference is 1 or less.
 */
static int isCloseInt(int x, int y) {
  return abs(x - y) <= 1;
}

/**
 * assert that for any random r, g, b, converting from RGB->CMYK->RGB
 * doesn't change the values
 */
static void testRandomCyclicalEquality(void **state) {
    srandom(time(NULL));

    for (int i = 0; i < RANDOM_TEST; i++) {
        int r, g, b, origR, origG, origB;
        origR = r = random() % 255;
        origG = g = random() % 255;
        origB = b = random() % 255;
        double c, m, y, k;

        rgbToCMYK(r, g, b, &c, &m, &y, &k);
        cmykToRGB(c, m, y, k, &r, &g, &b);

        // have to subtract 1 to allow for minor rounding differences
        assert_true(
                (r == origR || r == origR - 1) &&
                (g == origG || g == origG - 1) &&
                (b == origB || b == origB - 1)
        );
    }
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
  rgbToCMYK(71,130,181,&c,&m,&y,&k);
  assert_true(
    isClose(c, .61) &&
    isClose(m, .28) &&
    isClose(y, 0.0) &&
    isClose(k, .29)
  );
}

/**
 * This function tests cmykToRGB's error handling of NULL
 * values for its pass-by-reference parameters.  Each of
 * the three parameters are tested independently.  The function
 * should return a non-zero error value so we assert that the
 * return value is not equal to zero.
 *
 */
static void testCmykToRgbNull(void **state) {
    int r, g, b;
    assert_int_not_equal(cmykToRGB(0,0,0,0,NULL,&g,&b), 0);
    assert_int_not_equal(cmykToRGB(0,0,0,0,&r,NULL,&b), 0);
    assert_int_not_equal(cmykToRGB(0,0,0,0,&r,&g,NULL), 0);

}

/**
 * This function tests cmykToRGB's error handling of out-of-range
 * values for the c, m, y, k parameters, each tested independently.
 * two values are tested each: a less-than-zero value and a value
 * greater than 255.
 */
static void testCmykToRgbOutOfBounds(void **state) {
    int r, g, b;
    assert_int_not_equal(cmykToRGB(-1, .5, .5, .5, &r,&g,&b), 0);
    assert_int_not_equal(cmykToRGB( 2, .5, .5, .5, &r,&g,&b), 0);
    assert_int_not_equal(cmykToRGB(.5, -1, .5, .5, &r,&g,&b), 0);
    assert_int_not_equal(cmykToRGB(.5,  2, .5, .5, &r,&g,&b), 0);
    assert_int_not_equal(cmykToRGB(.5, .5, -1, .5, &r,&g,&b), 0);
    assert_int_not_equal(cmykToRGB(.5, .5,  2, .5, &r,&g,&b), 0);
    assert_int_not_equal(cmykToRGB(.5, .5, .5, -1, &r,&g,&b), 0);
    assert_int_not_equal(cmykToRGB(.5, .5, .5,  2, &r,&g,&b), 0);
}

/**
 * This function tests cmykToRGB passing a single, hard-coded
 * cmyk-value (Steele Blue, .61, .28, 0, .29).
 */
static void testCmykToRgb001(void **state) {
    int r, g, b;
    //steel blue:
    cmykToRGB(.61, .28, 0, .29, &r, &g, &b);
    assert_true(
            r == 71 &&
            g == 130 &&
            b == 181
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

/**
 * This function is a generic testing function for cmykToRGB
 * in which the passed state is expected to have 7 double values
 * corresponding to 3 RGB output values and 4 CMYK input values
 * that are known to be equivalent.
 *
 * A difference of 1 in each result is tolerated.
 */
static void testCmykToRgbValues(void **state) {
    //cast the generic state to a double array
    double *values = *((double **)state);
    int r, g, b;
    cmykToRGB(values[3], values[4], values[5], values[6], &r, &g, &b);
    assert_true(
            isCloseInt(r, values[0]) &&
            isCloseInt(g, values[1]) &&
            isCloseInt(b, values[2])
    );
}

/**
 * Takes a set of values where the first three are a color in RGB
 * and the next 4 are CMYK. These are directed to the RBG->CMYK and
 * CMYK->RGB functions
 */
static void testBidirectionalValues(void **state) {
    testRgbToCmykValues(state);
    testCmykToRgbValues(state);
}

int main(int argc, char **argv) {
    // values to test bi-directionally
    // each color is a collection of RGB and CMYK values
    // example: aquamarine has RGB values 128, 255, 212
    //          with equivalent CMYK values .5, 0, .17, 0
    double aquamarine[] =       {128, 255, 212,  0.5,    0, 0.17,    0};
    double salmon[] =           {250, 127, 115,  0.0, 0.49, 0.54, 0.02};
    double huskerRed[] =        {209,   0,   0,  0.0,    1,    1, 0.18};
    double cycleBlue[] =        { 40, 159, 209, 0.81, 0.24,    0, 0.18};
    double orange[] =           {255, 158,  33,    0, 0.38, 0.87,    0};
    double facebookBlue[] =     { 60,  90, 153, 0.61, 0.41,    0,  0.4};
    double twitterBlue[] =      { 56, 160, 242, 0.77, 0.34,    0, 0.05};
    double instagramPink[] =    {194,  43, 163,    0, 0.78, 0.16, 0.24};
    double powerpointOrange[] = {209,  69,  36,    0, 0.67, 0.83, 0.18};
    double spotifyGreen[] =     { 30, 214,  96, 0.86,    0, 0.55, 0.16};

    const struct CMUnitTest tests[] = {
            cmocka_unit_test(testRandomCyclicalEquality),
            cmocka_unit_test(testRgbToCmykNull),
            cmocka_unit_test(testRgbToCmykOutOfBounds),
            cmocka_unit_test(testRgbToCmyk001),
            cmocka_unit_test(testCmykToRgbNull),
            cmocka_unit_test(testCmykToRgbOutOfBounds),
            cmocka_unit_test(testCmykToRgb001),

            cmocka_unit_test_prestate(testBidirectionalValues, &aquamarine),
            cmocka_unit_test_prestate(testBidirectionalValues, &salmon),
            cmocka_unit_test_prestate(testBidirectionalValues, &huskerRed),
            cmocka_unit_test_prestate(testBidirectionalValues, &cycleBlue),
            cmocka_unit_test_prestate(testBidirectionalValues, &orange),
            cmocka_unit_test_prestate(testBidirectionalValues, &facebookBlue),
            cmocka_unit_test_prestate(testBidirectionalValues, &twitterBlue),
            cmocka_unit_test_prestate(testBidirectionalValues, &instagramPink),
            cmocka_unit_test_prestate(testBidirectionalValues, &powerpointOrange),
            cmocka_unit_test_prestate(testBidirectionalValues, &spotifyGreen)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);

}
