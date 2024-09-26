/**
 * TODO: author header: name, date, purpose
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define CORN_DENSITY 720.83;

int main(int argc, char **argv) {

    const double CORN_DENSITY = 720.83;

    CORN_DENSITY = 2;
    if(argc != 4) {
        printf("ERROR: provide radius height percent\n");
        exit(1);
    }

    double radius = atof(argv[1]);
    double height = atof(argv[2]);
    double percent = atof(argv[3]);

    if(radius < 0 || height < 0 || percent < 0 || percent > 1) {
        printf("ERROR: invalid input(s)\n");
        exit(2);
    }

    double volume = height * M_PI * radius * radius;
    double weight = volume * CORN_DENSITY * percent;

    printf("Radius: %fm\n", radius);
    printf("Height: %fm\n", height);
    printf("Percentage: %f%%\n", percent * 100);
    printf("Total Volume: %f mˆ3\n", volume);
    printf("Total Weight: %f kg\n", weight);

    return 0;
}
