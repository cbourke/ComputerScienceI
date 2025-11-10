#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "book.h"

int initBook(Book *b,
             int id,
             const char *title,
             const char *lastName,
             const char *firstName,
             const char *isbn,
             double rating,
             const char *publisher,
             int publishYear,
             const char *dateRead) {

    //TODO: do some erro rhandling here

    b->id = id;
    b->title = (char *) malloc( sizeof(char) * (strlen(title) + 1) );
    strcpy(b->title, title);
    b->isbn = (char *) malloc( sizeof(char) * (strlen(isbn) + 1) );
    strcpy(b->isbn, isbn);
    b->rating = rating;
    b->publisher = (char *) malloc( sizeof(char) * (strlen(publisher) + 1) );
    strcpy(b->publisher, publisher);
    b->year = publishYear;

    //TODO: write an initPerson function
    b->author.lastName = (char *) malloc( sizeof(char) * (strlen(lastName) + 1) );
    strcpy(b->author.lastName, lastName);
    b->author.firstName = (char *) malloc( sizeof(char) * (strlen(firstName) + 1) );
    strcpy(b->author.firstName, firstName);

    //TODO: dateRead
    return 0;
}

char *bookToString(const Book *b) {

    char temp[1000];
    sprintf(temp, "%s by %s, %s (%d, %.2f)", b->title, b->author.lastName, b->author.firstName, b->year, b->rating);
    char *result = (char *) malloc( sizeof(char) + (strlen(temp) + 1) );
    strcpy(result, temp);
    return result;
}

Book *createBook(int id,
             const char *title,
             const char *lastName,
             const char *firstName,
             const char *isbn,
             double rating,
             const char *publisher,
             int publishYear,
             const char *dateRead) {
  Book *b;
  b = (Book *) malloc( sizeof(Book) * 1 );
  initBook(b, id, title, lastName, firstName, isbn, rating, publisher, publishYear, dateRead);

  return b;
}

void freeBook(Book *b) {

    free(b->title);
    free(b->isbn);
    free(b->publisher);
    free(b->author.firstName);
    free(b->author.lastName);

    return;
}
