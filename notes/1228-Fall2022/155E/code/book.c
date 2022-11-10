#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "book.h"

Book *createBook(const char *title,
              const char *authorFirstName,
              const char *authorLastName,
              int releaseYear,
              double rating) {

  //TODO: error handling

  Book *b = (Book *) malloc( sizeof(Book) * 1);
  initBook(b, title, authorFirstName, authorLastName, releaseYear, rating);
  return b;
}

void initBook(Book *b,
              const char *title,
              const char *authorFirstName,
              const char *authorLastName,
              int releaseYear,
              double rating) {

  //TODO: error handling
  b->title = deepStringCopy(title);
  b->author.firstName = deepStringCopy(authorFirstName);
  b->author.lastName = deepStringCopy(authorLastName);
  b->releaseDate.year = releaseYear;
  b->rating = rating;

  return;
}


char *deepStringCopy(const char *s) {
    char *c = (char *) malloc(sizeof(char) * (strlen(s) + 1) );
    strcpy(c, s);
    return c;
}

void printBook(const Book *b) {

    char *s = bookToString(b);
    printf("%s\n", s);
    // we're done with s, free it
    free(s);

    return;
}

char *bookToString(const Book *b) {

    char temp[1000];
    sprintf(temp, "%-30s %s, %s  %d  %f",
       b->title,
       b->author.lastName,
       b->author.firstName,
       b->releaseDate.year,
       b->rating
       );
    char *s = (char *) malloc( sizeof(char) * (strlen(temp) + 1) );
    strcpy(s, temp);

    //WRONG: you cannot free your own stack free(temp);
    //WRONG: you're returning s, dont' free/destroy it.. free(s);

    return s;
}

void freeBook(Book *b) {
  free(b->title);
  free(b->author.firstName);
  free(b->author.lastName);
  free(b);
}

Book *loadBooks(const char *fileName, int *numBooks) {

  if(fileName == NULL || numBooks == NULL) {
    return NULL;
  }
  //1. open the file for processing...
  FILE *in = fopen(fileName, "r");

  if(in == NULL) {
    return NULL;
  }

  char buffer[1000];
  fgets(buffer, 1000, in);

  int numRecords = atoi(buffer);
  if(numRecords == 0) {
    return NULL;
  }
  *numBooks = numRecords;

  Book *library = (Book *) malloc( sizeof(Book) * numRecords);

  for(int i=0; i<numRecords; i++) {
    //read the next line
    fgets(buffer, 1000, in);
    //tokenize it to get each piece of data
    char *title = strtok(buffer, ",");
    char *authorFirstName = strtok(NULL, ",");
    char *authorLastName = strtok(NULL, ",");
    char *releaseYearStr = strtok(NULL, ",");
    int releaseYear = atoi(releaseYearStr);
    char *ratingStr = strtok(NULL, ",");
    double rating = atof(ratingStr);

    initBook(&library[i], title, authorFirstName, authorLastName, releaseYear, rating);

  }
  return library;
}

Book *getBestBook(const Book *library, int numBooks) {

  int indexOfBest = 0;
  for(int i=0; i<numBooks; i++) {
    if(library[i].rating > library[indexOfBest].rating) {
      indexOfBest = i;
    }
  }
  return &library[indexOfBest];
}

Book *getWorstBook(const Book *library, int numBooks) {

  int indexOfWorst = 0;
  for(int i=0; i<numBooks; i++) {
    if(library[i].rating < library[indexOfWorst].rating) {
      indexOfWorst = i;
    }
  }
  return &library[indexOfWorst];
}

Book *getBooksByAuthor(const Book *library, int numBooks, const Author *author, int *numResultingBooks){

   //1. TODO: error handling

   //2. Count the number of books by the author...
   int authorCount = 0;
   for(int i=0; i<numBooks; i++) {
     if(authorIsEqual(&library[i].author, author)) {
       authorCount++;
     }
   }
  *numResultingBooks = authorCount;
  Book *result = (Book *) malloc( sizeof(Book) * authorCount );
  int j = 0;
   for(int i=0; i<numBooks; i++) {
     if(authorIsEqual(&library[i].author, author)) {
       result[j] = library[i];
       j++;
     }
   }

  return result;

}


int authorIsEqual(const Author *a, const Author *b) {
  if( strcmp(a->lastName, b->lastName) == 0 &&
      strcmp(a->firstName, b->firstName) == 0) {
        return true;
      } else {
        return false;
      }
}