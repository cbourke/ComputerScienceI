/**
 * Author: 
 * Date: 
 *
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

// ... (Rest of the code remains the same)
// Ensure the main function remains intact.

int main(int argc, char **argv) {
    // values to test bi-directionally
    // each color is a collection of RGB and CMYK values
    // example: aquamarine has RGB values 128, 255, 212
    // with equivalent CMYK values .5, 0, .17, 0
    double aquamarine[] = {128, 255, 212,  0.5, 0, 0.17, 0};

    double black[] = {0, 0, 0, 0, 0, 0, 1.00};
    double white[] = {255, 255, 255, 0, 0, 0, 0};

    double red[] = {255, 0, 0, 0, 1, 1, 0};
    double green[] = {0, 255, 0, 1, 0, 1, 0};
    double blue[] = {0, 0, 255, 1, 1, 0, 0};

    double cyan[] = {0, 255, 255, 1, 0, 0, 0};
    double magenta[] = {255, 0, 255, 0, 1, 0, 0};
    double yellow[] = {255, 255, 0, 0, 0, 1, 0};

    double salmon[] = {250, 127, 115,  0.0, 0.49, 0.54, 0.02};
    double huskerRed[] = {209, 0, 0,  0.0, 1, 1, 0.18};
    double cycleBlue[] = {40, 159, 209, 0.81, 0.24, 0, 0.18};
    double orange[] = {255, 158, 33, 0, 0.38, 0.87, 0};
    double twitterBlue[] = {56, 160, 242, 0.77, 0.34, 0, 0.05};
    double instagramPink[] = {194, 43, 163, 0, 0.78, 0.16, 0.24};
    double powerpointOrange[] = {209, 69, 36, 0, 0.67, 0.83, 0.18};
    double spotifyGreen[] = {30, 214, 96, 0.86, 0, 0.55, 0.16};

    const struct CMUnitTest tests[] = {
        cmocka_unit_test(testRandomCyclicalEquality),
        cmocka_unit_test(testRgbToCmykNull),
        cmocka_unit_test(testRgbToCmykOutOfBounds),
        cmocka_unit_test(testRgbToCmyk001),
        cmocka_unit_test(testCmykToRgbNull),
        cmocka_unit_test(testCmykToRgbOutOfBounds),
        cmocka_unit_test(testCmykToRgb001),

        cmocka_unit_test_prestate(testBidirectionalValues, &aquamarine),
        cmocka_unit_test_prestate(testBidirectionalValues, &black),
        cmocka_unit_test_prestate(testBidirectionalValues, &white),
        cmocka_unit_test_prestate(testBidirectionalValues, &red),
        cmocka_unit_test_prestate(testBidirectionalValues, &green),
        cmocka_unit_test_prestate(testBidirectionalValues, &blue),
        cmocka_unit_test_prestate(testBidirectionalValues, &cyan),
        cmocka_unit_test_prestate(testBidirectionalValues, &magenta),
        cmocka_unit_test_prestate(testBidirectionalValues, &yellow),
        cmocka_unit_test_prestate(testBidirectionalValues, &salmon),
        cmocka_unit_test_prestate(testBidirectionalValues, &huskerRed),
        cmocka_unit_test_prestate(testBidirectionalValues, &cycleBlue),
        cmocka_unit_test_prestate(testBidirectionalValues, &orange),
        cmocka_unit_test_prestate(testBidirectionalValues, &twitterBlue),
        cmocka_unit_test_prestate(testBidirectionalValues, &instagramPink),
        cmocka_unit_test_prestate(testBidirectionalValues, &powerpointOrange),
        cmocka_unit_test_prestate(testBidirectionalValues, &spotifyGreen)
    }

    return cmocka_run_group_tests(tests, NULL, NULL);
}






