/**
 * TODO: author header: name, date, purpose
 *
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

    if(argc != 4) {
        printf("ERROR: provide a b n\n");
        exit(1);
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int n = atoi(argv[3]);

    if(a < 2 || b < 2 || n < 1) {
        printf("ERROR; invalid input\n");
        exit(2);
    }

    for(int i=1; i<=n; i++) {
        if(i % a == 0 && i % b == 0) {
            printf("Go Nebraska!\n");
        } else if(i % a == 0) {
            printf("Go Huskers\n");
        } else if(i % b == 0) {
            printf("Go Mavs\n");
        } else {
            printf("%d\n", i);
        }
    }

    return 0;
}
