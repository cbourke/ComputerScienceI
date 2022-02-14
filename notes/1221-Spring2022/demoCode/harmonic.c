#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(int argc, char **argv) {

    if(argc != 2) {
        printf("Usage: give me a positive integer\n");
        exit(1);
    }

    int n = atoi(argv[1]);
    if(n <= 0) {
        printf("Error: integer must be positive\n");
        exit(2);
    }

    double sum = 0.0;
    for(int i=1; i<=n; i++) {
        sum += (1.0 / i);
    }

    printf("sum 1/i, i = 1..%d = %f\n", n, sum);

    return 0;
}