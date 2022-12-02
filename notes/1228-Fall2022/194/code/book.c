#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "book.h"

//TODO: also add some error handling...

Book * createBook(const char *title,
                  const char *authorFirstName,
                  const char *authorLastName,
                  int releaseYear,
                  double rating) {

  Book *b = (Book *) malloc( 1 * sizeof(Book) );

  initBook(b, title, authorFirstName, authorLastName, releaseYear, rating);

  return b;

}

int initBook(Book *b,
             const char *title,
             const char *authorFirstName,
             const char *authorLastName,
             int releaseYear,
             double rating) {

  if(b == NULL || title == NULL || authorFirstName == NULL || authorLastName == NULL || rating < 0 || rating > 5) {
    return 1;
  }

  b->title = (char *) malloc( sizeof(char) * (strlen(title) + 1) );
  strcpy(b->title, title);
  b->author.firstName = (char *) malloc( sizeof(char) * (strlen(title) + 1) );
  strcpy(b->author.firstName, authorFirstName);
  b->author.lastName = (char *) malloc( sizeof(char) * (strlen(title) + 1) );
  strcpy(b->author.lastName, authorLastName);
  b->releaseDate.year = releaseYear;
  b->rating = rating;

  return 0;

}


void printBook(const Book *b) {
    if(b == NULL) {
        printf("(null)\n");
        return;
    }
    char *s = bookToString(b);
    printf("%s\n", s);
    //RIGHT:
    free(s);
    return;
}

//TODO: documentation
char *bookToString(const Book *b) {

    char s[1000];
    sprintf(s, "%-40s %s, %s  %10d   %.2f", b->title, b->author.lastName, b->author.firstName, b->releaseDate.year, b->rating);
    char *str = (char *) malloc( sizeof(char) * (strlen(s) + 1) );
    strcpy(str, s);
    //WRONG: free(s);
    return str;
}

Book *loadBooksFromCsvFile(const char *fileName, int *numBooks) {

  //0. TODO: error handling

  //1. open the file for input/processing:
  FILE *f = fopen(fileName, "r");

  //read in the first line to determine the number of records...
  char buffer[1000];
  char *line = fgets(buffer, 1000, f);

  int numRecords = atoi(buffer);
  *numBooks = numRecords;

  Book *books = (Book *) malloc( sizeof(Book) * numRecords );

  for(int i=0; i<numRecords; i++) {
    //read the next line
    line = fgets(buffer, 1000, f);
    //process the line: split it up into its tokens
    char *title = strtok(buffer, ",");
    char *authorFirstName = strtok(NULL, ",");
    char *authorLastName = strtok(NULL, ",");
    char *yearString = strtok(NULL, ",");
    int year = atoi(yearString);
    char *ratingString = strtok(NULL, ",");
    double rating = atof(ratingString);

    initBook(&books[i], title, authorFirstName, authorLastName, year, rating);
  }
  fclose(f);

  return books;
}

Book * getBestBook(const Book *books, int numBooks) {

  int indexOfBest = 0;
  for(int i=0; i<numBooks; i++) {
    if( books[i].rating > books[indexOfBest].rating ) {
      indexOfBest = i;
    }
  }
  return &books[indexOfBest];
}


Book * getWorstBook(const Book *books, int numBooks) {

  int indexOfWorst = 0;
  for(int i=0; i<numBooks; i++) {
    if( books[i].rating < books[indexOfWorst].rating ) {
      indexOfWorst = i;
    }
  }
  return &books[indexOfWorst];
}

Book * getAllBooksByAuthor(const Book *books, int numBooks, Author author, int *numResults) {

  //0. TODO: error handling

  //1. iterate through the books and count how many are by the author..
  int count = 0;
  for(int i=0; i<numBooks; i++) {
    if( cmpAuthor(&books[i].author, &author) == 0 ) {
        count++;
    }
  }

  //2. communicate the size of the resulting array to the calling function
  *numResults = count;
  //3. set up memory:
  Book *result = malloc( sizeof(Book) * count );

  //4. iterate again through the books and add them if they are by the author
  int j = 0;
  for(int i=0; i<numBooks; i++) {
    if( cmpAuthor(&books[i].author, &author) == 0 ) {
        result[j] = books[i];
        j++;
    }
  }

  return result;
}

int cmpAuthor(const Author *a, const Author *b) {

  int result = strcmp(a->lastName, b->lastName);
  if(result == 0) {
    //have the same last name, compare the first name:
    result = strcmp(a->firstName, b->firstName);
  }

  return result;
}

int cmpBooksByRatingDesc(const void *a, const void *b) {

  const Book *x = (const Book *) a;
  const Book *y = (const Book *) b;

  if( x->rating < y->rating) {
    return 1;
  } else if( x->rating > y->rating) {
    return -1;
  } else {
    return 0;
  }

}

int cmpBooksByAuthor(const void *a, const void *b) {

  const Book *x = (const Book *) a;
  const Book *y = (const Book *) b;

  int result = strcmp(x->author.lastName, y->author.lastName);
  if(result == 0) {
    //break ties by looking at the first name:
    result = strcmp(x->author.firstName, y->author.firstName);
  }
  return result;

}