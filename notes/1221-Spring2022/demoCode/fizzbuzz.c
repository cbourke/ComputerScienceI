/** TODO: DOcument
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(int argc, char **argv) {

    for(int i=1; i<=100; i++) {

        if(i % 3 == 0 && i % 5 == 0) {
            printf("FizzBuzz\n");
        } else if(i % 3 == 0) {
            printf("Fizz\n");
        } else if(i % 5 == 0) {
            printf("Buzz\n");
        } else {
            printf("%d\n", i);
        }

    }

    return 0;
}