#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "book.h"

Book *createBook(const char *title,
                 const char *authorFirstName,
                 const char *authorLastName,
                 int publishYear) {
  //TODO: 0 basic error handling
  //1. allocate memory for the new book
  Book *b = (Book *) malloc( sizeof(Book) * 1 );

  initBook(b, title, authorFirstName, authorLastName, publishYear);

  return b;
}

void initBook(Book *b,
              const char *title,
              const char *authorFirstName,
              const char *authorLastName,
              int publishYear){
  b->title = (char *) malloc( sizeof(char) * ( strlen(title) + 1));
  strcpy(b->title, title);

  b->author.firstName = (char *) malloc( sizeof(char) * ( strlen(authorFirstName) + 1));
  strcpy(b->author.firstName, authorFirstName);

  b->author.lastName = (char *) malloc( sizeof(char) * ( strlen(authorLastName) + 1));
  strcpy(b->author.lastName, authorLastName);

  b->publishDate.year = publishYear;
  return;
}


char *bookToString(const Book *b) {
    char temp[1000];
    sprintf(temp, "%s by %s, %s (%d)", b->title, b->author.lastName, b->author.firstName, b->publishDate.year);
    char *s = (char *) malloc( sizeof(char) * (strlen(temp) + 1));
    strcpy(s, temp);
    return s;
}

Book *loadBookData(const char *fileName, int *numBooks) {

  //0. basic error handling: TODO
  if(fileName == NULL || numBooks == NULL) {
    return NULL;
  }
  //0.5 determine how many valid records there are...
  FILE *in = fopen(fileName, "r");
  if(in == NULL) {
    return NULL;
  }
  char buffer[1000];
  char *s = fgets(buffer, 1000, in);
  int numberOfBooks = 0;
  while(s != NULL) {
    //a. determine if the current line is a valid book record
    if(strlen(buffer) > 1) {
      //TODO: think of a more sophisticated method here
      numberOfBooks++;
    }
    s = fgets(buffer, 1000, in);
  }
  //correct for the first line...
  numberOfBooks--;
  *numBooks = numberOfBooks;

  Book *books = (Book *) malloc( sizeof(Book) * numberOfBooks );

  //x. rewind back to the start of the file
  rewind(in);
  //ignore the first line:
  s = fgets(buffer, 1000, in);
  for(int i=0; i<numberOfBooks; i++) {
    s = fgets(buffer, 1000, in);
    //3. tokenize the line and create a book instance
    //17182126,Steelheart (The Reckoners; #1),Brandon,Sanderson,9780385743563,4.14,Delacorte Press,2013,
    char *bookId = strtok(buffer, ",");
    char *title = strtok(NULL, ",");
    char *firstName = strtok(NULL, ",");
    char *lastName = strtok(NULL, ",");
    char *isbn = strtok(NULL, ",");
    char *strRating = strtok(NULL, ",");
    double rating = atof(strRating);
    char *publisher = strtok(NULL, ",");
    char *strYear = strtok(NULL, ",");
    int year = atoi(strYear);
    //create the Book:
    //Book *b = createBook(title, firstName, lastName, year);
    //b is a pointer to Book
    //books is a pointer to a Book (the first book in an array of books)
    //books[i] is a dereference, so it is *a* book (regular old structure!)

    //memory leak:
    //books[i] = *b;

    //better:
    initBook(&books[i], title, firstName, lastName, year);

  }

  fclose(in);
  return books;
}
