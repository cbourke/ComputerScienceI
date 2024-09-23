/**
 * TODO: full author header
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char **argv) {

    if(argc != 3) {
        printf("ERROR: provide two command line arguments (points for, against)\n");
        exit(1);
    }

    int pointsFor = atoi(argv[1]);
    int pointsAgainst = atoi(argv[2]);

    double winPercentage = pow(pointsFor, 2.37) / (pow(pointsFor, 2.37) + pow(pointsAgainst, 2.37));

    int numWins = round(winPercentage * 12);
    int numLoss = 12 - numWins;

    printf("Win Percentage: %.2f%%\n", winPercentage * 100.0);
    printf("Win/Loss: %d/%d\n", numWins, numLoss);


    return 0;
}
