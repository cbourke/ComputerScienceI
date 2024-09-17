/**
 * CSCE 155E - Fall 2024
 *
 * An implementation of the classic fizz buzz program.
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  int i = 1;
  int n = 100;
  while(i <= n) {

    if( i % 15 == 0 ) {
      printf("FizzBuzz\n");
    } else if(i % 3 == 0) {
      //divisible by three
      printf("Fizz\n");
    } else if(i % 5 == 0) {
      //divisible by five
      printf("Buzz\n");
    } else {
      printf("%d\n", i);
    }
    i++;
  }


  return 0;
}
