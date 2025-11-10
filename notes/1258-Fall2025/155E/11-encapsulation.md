
# CSCE 155E - Computer Science I
## Encapsulation - Structures
### Fall 2025

* Built-in primitive types (`int, double, char`) are limiting: not everything is a simple number of character
* Real world entities are made up of multiple pieces of data
* In programming languages you can *collect* and **encapsulate** multiple pieces of data together into one logical unit
* In C this is achieved using *structures*
* Structures are "weak" encapsulation
* Encapsulation in general:
  1. The grouping of data
  2. The protection of data
  3. The grouping of functionality that acts on that data
* C is NOT an OOP language and only supports #1 ("weak" encapsulation)

## Defining Structures

* Create a structure that models a *book*
  * You use the syntax: `typedef struct`
  * You place a collection of variables inside `{}` (delimited by `;`)
  * You provide a name at the end + `;`
  * Generally: modern convention is to use `UpperCamelCasing`
  * Generally, structure declarations are placed into header files, often of similar name, `book.h`
  * Generally you should document them
  * Order matters: if you use *composition* (one structure is composed of other structures) then you need to declare the used structures first

## Using Structures

* Once defined you can declare them: `Book b1;` or a pointer: `Book *b2;`
  * To access member variables of a regular-old-struture: dot operator: `b1.isbn`
  * To access member variables of a *pointer* to a structure: use the arrow operator: `b2->isbn`
* You can define factory functions to create new instances of your structure, returning a pointer to a *dynamically allocated* instance of the structure
  * remember: to use `sizeof(Book)` with `malloc()`
  * You can create "to string" function(s) to give a human-readable representation of your structure
  * You can create "factory" functions `init` or `create` to initialize/create new instances of your structures
  * You can create a "destructor" that frees all memory associated with your structure
  * Other ideas: bulk functions: print all books, destroy all books, etc.
  * Textbook: you can also have array of pointers to structures

# `book.h`

```c
typedef struct {
  int year;
  int month;
  int day;
} Date;

typedef struct {

  char *lastName;
  char *firstName;
  Date birthDate;

} Person;

typedef struct {

    int id;
    char *title;
    Person author;
    char *isbn;
    double rating;
    char *publisher;
    int year;
    Date dateRead;

} Book;

/**
 * Initializes the given book with the given values
 */
void initBook(Book *b,
              int id,
              char *title,
              char *authorLastName,
              char *authorFirstName,
              char *isbn,
              double rating,
              char *publisher,
              int year,
              char *dateRead);

Book *createBook(int id,
              char *title,
              char *authorLastName,
              char *authorFirstName,
              char *isbn,
              double rating,
              char *publisher,
              int year,
              char *dateRead);
//TODO: write a freeBook() function
void freeBook(Book *book);

/**
 * Formats the given Book structure into a human readable string
 */
char *bookToString(const Book *b);

void printBook(const Book *b);

```

# `book.c`

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "book.h"

void initBook(Book *b,
              int id,
              char *title,
              char *authorLastName,
              char *authorFirstName,
              char *isbn,
              double rating,
              char *publisher,
              int year,
              char *dateRead) {

    b->id = id;
    b->title = (char *) malloc( sizeof(char) * (strlen(title) + 1) );
    strcpy(b->title, title);
    //TODO: make an initPerson function
    b->author.firstName = (char *) malloc( sizeof(char) * (strlen(authorFirstName) + 1) );
    strcpy(b->author.firstName, authorFirstName);
    b->author.lastName = (char *) malloc( sizeof(char) * (strlen(authorLastName) + 1) );
    strcpy(b->author.lastName, authorLastName);
    b->isbn = (char *) malloc( sizeof(char) * (strlen(isbn) + 1) );
    strcpy(b->isbn, isbn);
    b->rating = rating;
    b->publisher = (char *) malloc( sizeof(char) * (strlen(publisher) + 1) );
    strcpy(b->publisher, publisher);
    b->year = year;
    //TODO: dateRead


}

char *bookToString(const Book *b) {

    char temp[1000];
    sprintf(temp, "%s by %s, %s (%.2f, %d)", b->title, b->author.lastName, b->author.firstName, b->rating, b->year);
    char *result = (char *) malloc( sizeof(char) * (strlen(temp) + 1) );
    strcpy(result, temp);
    return result;
}

Book *createBook(int id,
              char *title,
              char *authorLastName,
              char *authorFirstName,
              char *isbn,
              double rating,
              char *publisher,
              int year,
              char *dateRead) {

    //create a new book on the heap...
    Book *result = (Book *) malloc( sizeof(Book) * 1 );
    initBook(result, id, title, authorLastName, authorFirstName, isbn, rating, publisher, year, dateRead);
    return result;
}

void printBook(const Book *b){
    char *bookStr = bookToString(b);
    printf("%s\n", bookStr);
    free(bookStr);
    return;
}

void freeBook(Book *book) {

    free(book->title);
    free(book->isbn);
    free(book->publisher);
    free(book->author.lastName);
    free(book->author.firstName);

}

```

# Demo

```c
/**
 * Chris Bourke
 *
 * Demo Code
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "book.h"

int main(int argc, char **argv) {


  //Exercise: process a full CSV file
  FILE *f = fopen("./my_goodreads_data.csv", "r");

  char buffer[1000];

  //reads the first line, ignore it...
  char *line = fgets(buffer, 1000, f);
  line = fgets(buffer, 1000, f);
  int numBooks = 0;
  //count up the number of remaining lines
  while(line != NULL) {
    numBooks++;
    //get the next line
    line = fgets(buffer, 1000, f);
  }
  rewind(f);
  //burn the first line
  line = fgets(buffer, 1000, f);
  line = fgets(buffer, 1000, f);

  printf("read %d book records\n", numBooks);

  Book *library = (Book *) malloc( sizeof(Book) * numBooks );

  int i = 0;
  while(line != NULL) {
    //process the current line...
    char *idStr = strtok(buffer, ",");
    int id = atoi(idStr);
    char *title = strtok(NULL, ",");
    char *lastName = strtok(NULL, ",");
    char *firstName = strtok(NULL, ",");
    char *isbn = strtok(NULL, ",");
    char *averageRatingStr = strtok(NULL, ",");
    double averageRating = atof(averageRatingStr);
    char *publisher = strtok(NULL, ",");
    char *yearStr = strtok(NULL, ",");
    int year = atoi(yearStr);
    char *dateRead = strtok(NULL, ",");

    initBook(&library[i], id, title, lastName, firstName, isbn, averageRating, publisher, year, dateRead);
    i++;

    //get the next line
    line = fgets(buffer, 1000, f);
  }
  fclose(f);


  for(int i=0; i<numBooks; i++) {
    char *bookStr = bookToString(&library[i]);
    printf("%s\n", bookStr);
    free(bookStr);
  }

  //what is the oldest book?
  Book oldestBook = library[0];
  for(int i=0; i<numBooks; i++) {
    if(library[i].year < oldestBook.year) {
      oldestBook = library[i];
    }
  }
  printf("Oldest book: ");
  printBook(&oldestBook);

  //what is the newest book?
  Book newestBook = library[0];
  for(int i=0; i<numBooks; i++) {
    if(library[i].year > newestBook.year) {
      newestBook = library[i];
    }
  }
  printf("Newest book: ");
  printBook(&newestBook);

  //clean up
  for(int i=0; i<numBooks; i++) {
    freeBook(&library[i]);
  }
  free(library);


  return 0;
}

```

* Write a program that counts down 10, 9, 8, etc. 1, blast off!
  * You may NOT use any loops (no for loops, no while loops,e tc.)
  * You may NOT hard code values


```text













```
