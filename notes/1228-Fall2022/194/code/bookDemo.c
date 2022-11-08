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

  //1. Find the "best" book
  Book *best = getBestBook(books, numBooks);
  printf("\n\nThe highest rated book is");
  printBook(best);

  //2. Find the "wosrt" book
  Book *worst = getWorstBook(books, numBooks);
  printf("\n\nThe worst rated book is");
  printBook(worst);

  //3. Find all books by a certain author: Frank Herbert

  int numFrankBooks;
  Author a = {"Frank", "Herbert", {0, 0, 0} };
  Book *franksBooks = getAllBooksByAuthor(books, numBooks, a, &numFrankBooks);
  for(int i=0; i<numFrankBooks; i++) {
    printBook(&franksBooks[i]);
  }




  return 0;
}