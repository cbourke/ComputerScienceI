#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "book.h"

char *deepStrCopy(const char *s) {
    char *copy = (char *) malloc( sizeof(char) * (strlen(s) + 1) );
    strcpy(copy, s);
    return copy;
}

Book *createBook(const char *isbn,
                 const char *title,
                 const char *authorFirstName,
                 const char *authorLastName) {

  //1. create a new book instance... using malloc
  Book *b = (Book *) malloc( sizeof(Book) * 1 );
  //2. set all of the given data elements
  initBook(b, isbn, title, -1.0, authorFirstName, authorLastName, 0);
  //3. return it
  return b;
}

char *bookToString(const Book *b) {

   char s[1000];
   sprintf(s, "%s by %s, %s (%s) %.2f", b->title, b->author.lastName, b->author.firstName, b->isbn, b->rating);
   char *result = deepStrCopy(s);
   return result;

}

void printBook(const Book *b) {

   char *s = bookToString(b);
   printf("%s\n", s);
   free(s);
   return;
}


void freeBook(Book *b) {
  free(b->isbn);
  free(b->title);
  free(b->author.firstName);
  free(b->author.lastName);
  free(b);
  return;
}

void initBook(Book *b,
              const char *isbn,
              const char *title,
              double rating,
              const char *authorFirstName,
              const char *authorLastName,
              int publishYear) {
  //TODO: basic error handling

  b->isbn = deepStrCopy(isbn);
  b->title = deepStrCopy(title);
  b->rating = rating;
  b->publishDate.year = publishYear;
  b->author.firstName = deepStrCopy(authorFirstName);
  b->author.lastName = deepStrCopy(authorLastName);

  return;
}

Book *loadBookData(const char *fileName, int *n) {

  //0. basic error handling
  if(fileName == NULL || n == NULL) {
    return NULL;
  }

  //1. determine how many book records there are...
  FILE *in = fopen(fileName, "r");
  char buffer[1000];
  int numRecords = 0;
  //read line by line...
  char *line = fgets(buffer, 1000, in);
  line = fgets(buffer, 1000, in);
  while(line != NULL) {
    if( strlen(line) > 1 ) {
      //TODO: do more fancy data/input validation
      numRecords++;
    }
    line = fgets(buffer, 1000, in);
  }

  *n = numRecords;
  Book *books = (Book *) malloc( sizeof(Book) * numRecords);

  //don't close, rewind:
  rewind(in);
  //2. read the file line by line...
  //ingore the first line (header data):
  line = fgets(buffer, 1000, in);
  for(int i=0; i<numRecords; i++) {
    line = fgets(buffer, 1000, in);
    //3a process the line
    //TODO
    //check to see if it is valid data
    char *id = strtok(line, ",");
    char *title = strtok(NULL, ",");
    char *firstName = strtok(NULL, ",");
    char *lastName = strtok(NULL, ",");
    char *isbn = strtok(NULL, ",");
    char *ratingStr = strtok(NULL, ",");
    double rating = atof(ratingStr);
    char *publisher = strtok(NULL, ",");
    char *yearStr = strtok(NULL, ",");
    int yearPublished = atoi(yearStr);
    char *readDate = strtok(NULL, ",");

    //_initialize_ the i-th book with this data
    initBook(&books[i], isbn, title, rating, firstName, lastName, yearPublished);
  }
  return books;

}
