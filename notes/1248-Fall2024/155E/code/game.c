/**
 * TODO: full author header
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char **argv) {

    if(argc != 2) {
        printf("ERROR: provide two command line arguments (points for, against)\n");
        exit(1);
    }

    int n = atoi(argv[1]);

    int round = 1;
    int aPoints = 0;
    int bPoints = 0;

    while(n != 1) {
        if(n % 2 == 0) {
            printf("Round  %d:  %d... even, player A scores!\n", round, n);
            n = n / 2;
            aPoints++;
        } else {
            //n is odd
            printf("Round  %d:  %d... odd, player B scores!\n", round, n);
            n = 3 * n + 1;
            bPoints++;
        }
        round++;
    }
    printf("Game Over\n");

    int aFinalScore = (2*aPoints - 1) / 3;
    int bFinalScore = (3*bPoints + 1) / 2;

    printf("Results:\n");
    printf("Player Points Total Score\n");
    printf("A  %d %d\n", aPoints, aFinalScore);
    printf("b  %d %d\n", bPoints, bFinalScore);
    if(aFinalScore > bFinalScore) {
        printf("A wins!\n");
    } else if(aFinalScore < bFinalScore) {
        printf("B wins!\n");
    } else {
        printf("Tie!\n");
    }
    return 0;
}
