#include<stdio.h>
#include<stdlib.h>

#include "protein_utils.h"

int main(int argc, char **argv) {

  if(argc != 2) {
    fprintf(stderr, "Usage: %s RNA\n", argv[0]);
    exit(1);
  }

  char prot = rnaToProtein(argv[1]);

  printf("%s -> %c\n", argv[1], prot);

  return 0;
}
