#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "book.h"


Book *createBook(const char * title,
                 const char * authorFirstName,
                 const char * authorLastName,
                 int          releaseYear,
                 double       rating) {

  //TODO: basic error checking

  Book *b = (Book *) malloc( sizeof(Book) );
  initBook(b, title, authorFirstName, authorLastName, releaseYear, rating);
  return b;

}

void initBook(Book *b,
                const char *title,
                 const char *authorFirstName,
                 const char *authorLastName,
                 int releaseYear,
                 double rating) {

  b->title = (char *) malloc( sizeof(char) * (strlen(title) + 1) );
  strcpy(b->title, title);

  b->author.firstName = (char *) malloc( sizeof(char) * (strlen(authorFirstName) + 1) );
  strcpy(b->author.firstName, authorFirstName);

  b->author.lastName = (char *) malloc( sizeof(char) * (strlen(authorLastName) + 1) );
  strcpy(b->author.lastName, authorLastName);

  b->releaseDate.year = releaseYear;

  b->rating = rating;
}



void printBook(const Book *b) {

  char *s = bookToString(b);
  printf("%s\n", s);
  //free it so there are no memory leaks:
  free(s);
  return;

}

char *bookToString(const Book *b) {

  char s[1000];
  sprintf(s, "%s by %s, %s was released in %d with a rating of %f", b->title, b->author.lastName, b->author.firstName, b->releaseDate.year, b->rating);
  char *result = (char *) malloc( sizeof(char) * (strlen(s) + 1) );
  strcpy(result, s);
  //BAD: you cannot free your own stack!
  //free(s);
  return result;

}


Book *loadFromCsvFile(const char *fileName, int *numBooks) {

  FILE *f = fopen(fileName, "r");
  char buffer[1000];
  char *line = fgets(buffer, 1000, f);

  int numRecords = atoi(buffer);
  *numBooks = numRecords;

  Book *library = (Book *) malloc( numRecords * sizeof(Book) );

  //library is a structure pointer: Book *
  //library[i] is a single structure: a regular old structure: a Book
  //regular old variable -> pointer variable use... &
  //&library[i]

  for(int i=0; i<numRecords; i++) {
    //read the next line...
    line = fgets(buffer, 1000, f);
    // tokenize each line to get each token of data

    char *title = strtok(buffer, ",");
    char *authorFirstName = strtok(NULL, ",");
    char *authorLastName = strtok(NULL, ",");
    char *yearString = strtok(NULL, ",");
    int yearReleased = atoi(yearString);
    char *ratingString = strtok(NULL, ",");
    double rating = atof(ratingString);

    //initialize the i-th book
    initBook(&library[i], title, authorFirstName, authorLastName, yearReleased, rating);
  }

  fclose(f);
  return library;
}

Book *getBestBook(const Book *library, int numBooks) {

  Book *bestBook = &library[0];
  for(int i=0; i<numBooks; i++) {
    if( library[i].rating > bestBook->rating) {
      bestBook = &library[i];
    }
  }
  return bestBook;
}

Book *getWorstBook(const Book *library, int numBooks) {

  Book *worstBook = &library[0];
  for(int i=0; i<numBooks; i++) {
    if( library[i].rating < worstBook->rating) {
      worstBook = &library[i];
    }
  }
  return worstBook;
}

int compareAuthor(const Author *a, const Author *b) {
  int result = strcmp(a->lastName, b->lastName);
  if(result == 0) {
    result = strcmp(a->firstName, b->firstName);
  }
  return result;
}

Book *getBooksByAuthor(const Book *library, int numBooks, Author a, int *numAuthorBooks) {

  int count = 0;
  for(int i=0; i<numBooks; i++) {
    if( compareAuthor(&library[i].author, &a) == 0 ) {
      count++;
    }
  }
  *numAuthorBooks = count;

  //set up memory:
  Book *authorBooks = (Book *) malloc( count * sizeof(Book) );

  int j = 0;
  for(int i=0; i<numBooks; i++) {
    if( compareAuthor(&library[i].author, &a) == 0 ) {
      authorBooks[j] = library[i];
      j++;
    }
  }


  return authorBooks;

}