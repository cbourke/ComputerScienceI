
# CSCE 155E - Computer Science I
## Encapsulation - Structures
### Fall 2026

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
  * You use the syntax `typedef struct`
  * You place a collection of variables inside the `{}` each ended with a `;`
  * You provide a name at the end + `;`
  * Generally: modern convention is to use `UpperCamelCasing`
  * Generally, structure declarations are placed into header files, often of similar name, `book.h`
  * Generally you should document them
  * Order matters: if you use *composition* (one structure is composed of other structures) then you need to declare the used structures first

## Using Structures

* Once defined you can declare them:
```c
//regular old structure
Book b1;
//pointer to a structure
Book *b2;
```
* To access member variables of a regular-old-struture: dot operator: `b1.isbn`
* To access member variables of a *pointer* to a structure: use the arrow operator: `b2->isbn`
* You can define factory functions to create new instances of your structure, returning a pointer to a *dynamically allocated* instance of the structure
  * remember: to use `sizeof(Book)` with `malloc()`
  * You can create "to string" function(s) to give a human-readable representation of your structure
  * You can create "factory" functions `init` or `create` to initialize/create new instances of your structures
  * You can create a "destructor" that frees all memory associated with your structure: `freeBook()`
  * Other ideas: bulk functions: print all books, destroy all books, etc.
  * Textbook: you can also have array of pointers to structures

# Code

# `book.h`

```c
typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {

    char *firstName;
    char *lastName;
    Date dateOfBirth;

} Person;

typedef struct {

    int bookId;
    char *title;
    Person author;
    char *isbn;
    double averageRating;
    char *publisher;
    int publishYear;
    Date dateRead;

} Book;

/**
 * TODO: Write proper doc-style comment documentation for this
 */
char *deepStrCpy(const char *s);

/**
 * This function initializes the given book structure with
 * the given data.
 */
void initBook(Book *b,
              int bookId,
              const char *title,
              const char *firstName,
              const char *lastName,
              int publishYear,
              double averageRating);

Book *createBook(int bookId,
              const char *title,
              const char *firstName,
              const char *lastName,
              int publishYear,
              double averageRating);

void printBook(const Book *b);

char *bookToString(const Book *b);

void freeBook(Book *b);
```

# `book.c`

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "book.h"

char *deepStrCpy(const char *s) {
    char *copy = (char *) malloc( sizeof(char) * (strlen(s) + 1) ) ;
    strcpy(copy, s);
    return copy;
}

void initBook(Book *b,
              int bookId,
              const char *title,
              const char *firstName,
              const char *lastName,
              int publishYear,
              double averageRating) {
    //TODO: basic error handling
    b->bookId = bookId;
    b->title = deepStrCpy(title);
    b->author.firstName = deepStrCpy(firstName);
    b->author.lastName = deepStrCpy(lastName);
    b->publishYear = publishYear;
    b->averageRating = averageRating;
    return;
}

Book *createBook(int bookId,
              const char *title,
              const char *firstName,
              const char *lastName,
              int publishYear,
              double averageRating) {

    Book *b = (Book *) malloc( sizeof(Book) * 1);
    initBook(b, bookId, title, firstName, lastName, publishYear, averageRating);
    return b;
}

void printBook(const Book *b) {

    char *s = bookToString(b);
    printf("%s\n", s);
    free(s);
    return;
}

char *bookToString(const Book *b) {

    char buffer[1000];
    sprintf(buffer, "%s by %s, %s in %d (%.2f)",
        b->title,
        b->author.lastName,
        b->author.firstName,
        b->publishYear,
        b->averageRating
    );
    return deepStrCpy(buffer);
}

void freeBook(Book *b) {
    free(b->title);
    free(b->author.firstName);
    free(b->author.lastName);
    return;
}
```

# `bookDemo.c`

```c
/**
 * Author: Chris Bourke
 *
 * Demo Code
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#include "book.h"

int main(int argc, char **argv) {

    FILE *f = fopen("./books.csv", "r");

    //1. process the file line by line
    //.   * skip the first line (header data)
    //.   * ignore any blank line(s)
    //.   * process each line, find the rating

    int numBooks = 28;  //TODO: use my getFileLines() to determine the number of records
    Book *books = (Book *) malloc( sizeof(Book) * numBooks );

    char buffer[1000];
    char *line;
    //ignore the first line
    line = fgets(buffer, 1000, f);
    line = fgets(buffer, 1000, f);
    int i = 0;
    while(line != NULL) {
        //chomp out/remove the endline character
        if(buffer[strlen(buffer)-1] == '\n') {
            buffer[strlen(buffer)-1] = '\0';
        }
        if(strlen(buffer) > 0) {
            //printf("processing line = %s\n", line);
            //process the book record: tokenize
            //strtok
            char *token;
            token = strtok(buffer, ",");
            int bookId = atoi(token);
            //printf("bookId = %d\n", bookId);
            token = strtok(NULL, ",");
            char *title = deepStrCpy(token);
            token = strtok(NULL, ",");
            char *firstName = deepStrCpy(token);
            token = strtok(NULL, ",");
            char *lastName = deepStrCpy(token);
            token = strtok(NULL, ",");
            char *isbn = deepStrCpy(token);
            token = strtok(NULL, ",");
            double rating = atof(token);
            token = strtok(NULL, ",");
            char *publisher = deepStrCpy(token);
            token = strtok(NULL, ",");
            int year = atoi(token);
            //printf("%s by %s, %s (%s) %.2f\n", title, lastName, firstName, isbn, rating);
            //TODO: read in the rest of the data

            //TODO: initialize i-th book with the data above
            initBook(&books[i], bookId, title, firstName, lastName, year, rating);
            i++;
        }
        line = fgets(buffer, 1000, f);
    }

    fclose(f);

    for(i=0; i<numBooks; i++) {
        printBook(&books[i]);
    }

    Book *bestBook = &books[0];
    for(i=0; i<numBooks; i++) {
        if(books[i].averageRating > bestBook->averageRating) {
            bestBook = &books[i];
        }
    }
    printf("Best Book:\n");
    printBook(bestBook);

    Book *worstBook = &books[0];
    for(i=0; i<numBooks; i++) {
        if(books[i].averageRating < worstBook->averageRating) {
            worstBook = &books[i];
        }
    }
    printf("Worst Book:\n");
    printBook(worstBook);

    Book *oldestBook = &books[0];
    for(i=0; i<numBooks; i++) {
        if(books[i].publishYear < oldestBook->publishYear) {
            oldestBook = &books[i];
        }
    }
    printf("Oldest Book:\n");
    printBook(oldestBook);

    // printf("The best book has a rating of %.2f\n", bestRating);
    // printf("Title: %s\n", bestTitle);
    // printf("Author: %s, %s\n", authorLastName, authorFirstName);

    return 0;
}

```

```text













```
