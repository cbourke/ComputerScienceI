#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#include "book.h"

int main(int argc, char **argv) {

  int numBooks;
  Book *books = loadBooksFromCsvFile("books.csv", &numBooks);

  qsort(books, numBooks, sizeof(Book), cmpBooksByRatingDesc);

  printf("Books:\n");
  for(int i=0; i<numBooks; i++) {
    printBook(&books[i]);
  }

  //1. Find the "best" book
  Book *best = &books[0];
  printf("\n\nThe highest rated book is");
  printBook(best);

  //2. Find the "wosrt" book
  Book *worst = &books[numBooks-1];
  printf("\n\nThe worst rated book is");
  printBook(worst);

  //3. Find all books by a certain author: Frank Herbert

  int numFrankBooks;
  Author a = {"Frank", "Herbert", {0, 0, 0} };
  Book *franksBooks = getAllBooksByAuthor(books, numBooks, a, &numFrankBooks);
  for(int i=0; i<numFrankBooks; i++) {
    printBook(&franksBooks[i]);
  }

  //find any book by Frank Herbert:
  //1. create a "dummy key": an instance of a book with the values that you want to search along...
  Book key = { NULL, a, 0.0, { 0, 0, 0 }};
  qsort(books, numBooks, sizeof(Book), cmpBooksByAuthor);

  Book *aFrankBook = bsearch(&key, books, numBooks, sizeof(Book), cmpBooksByAuthor);

  printf("searching for Frank...\n");
  if(aFrankBook == NULL) {
    printf("can't find a book by Frank\n");
  } else {
    printBook(aFrankBook);
  }


  printf("Books:\n");
  for(int i=0; i<numBooks; i++) {
    printBook(&books[i]);
  }



  return 0;
}