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

  //sort the books in descreasing order according to their rating...
  qsort(library, numBooks, sizeof(Book), cmpBookByRating);

  Book *bestBook = &library[0];
  printf("Best book is:\n\t");
  printBook(bestBook);

  Book *worstBook = &library[numBooks-1];
  printf("Worst book is:\n\t");
  printBook(worstBook);

  int numFranksBooks;
  Author a = { "Frank", "Herbert", {0, 0, 0 } };
  Book *franksBooks = getBooksByAuthor(library, numBooks, a, &numFranksBooks);

  printf("Frank's Books:\n");
  for(int i=0; i<numFranksBooks; i++) {
    printBook(&franksBooks[i]);
  }

  Book dummyKey = {NULL, a, {0, 0, 0}, 0.0};
  Book *result = bsearch(&dummyKey, library, numBooks, sizeof(Book), cmpBookByAuthor);
  if(result == NULL) {
    printf("nope\n");
  } else {
    printf("Found book: %s\n", result->title);
  }

  return 0;
}

