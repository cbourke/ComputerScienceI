
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#include "book.h"

int main(int argc, char **argv) {


  int numBooks;
  Book *library = loadBooks("books.csv", &numBooks);

  //print them out as an ad-hoc test...
  for(int i=0; i<numBooks; i++) {
    printBook(&library[i]);
  }

  Book *bestBook = getBestBook(library, numBooks);
  printf("The best book is: \n");
  printBook(bestBook);

  Book *worstBook = getWorstBook(library, numBooks);
  printf("The worst book is: \n");
  printBook(worstBook);

  int numFrankBooks;
  Author a;
  a.firstName = deepStringCopy("Frank");
  a.lastName = deepStringCopy("Herbert");
  Book *franksBooks = getBooksByAuthor(library, numBooks, &a, &numFrankBooks);
  for(int i=0; i<numFrankBooks; i++) {
    printBook(&franksBooks[i]);
  }



  return 0;
}
