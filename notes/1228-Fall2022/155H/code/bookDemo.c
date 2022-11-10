#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#include "book.h"

int main(int argc, char **argv) {

  int numBooks;
  Book *library = loadFromCsvFile("books.csv", &numBooks);

  //print each book
  for(int i=0; i<numBooks; i++) {
    printBook(&library[i]);
  }

  Book *bestBook = getBestBook(library, numBooks);
  printf("Best book is:\n\t");
  printBook(bestBook);

  Book *worstBook = getWorstBook(library, numBooks);
  printf("Worst book is:\n\t");
  printBook(worstBook);

  int numFranksBooks;
  Author a = { "Frank", "Herbert", {0, 0, 0 } };
  Book *franksBooks = getBooksByAuthor(library, numBooks, a, &numFranksBooks);

  printf("Frank's Books:\n");
  for(int i=0; i<numFranksBooks; i++) {
    printBook(&franksBooks[i]);
  }

  return 0;
}

