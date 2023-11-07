
# CSCE 155E - Computer Science I
## Encapsulation - Structures
### Fall 2023

* Built-in primitive types (`int, double, char`) are limiting: not everything is a simple number of character
* Real world entities are made up of multiple pieces of data
* In programming languages you can *collect* and **encapsulate** multiple pieces of data together into one logical unit
* In C this is achieved using *structures*
* Structures support "weak" encapsulation
* Encapsulation in general:
  1. The grouping of data
  2. The protection of data
  3. The grouping of functionality that acts on that data
* Generally OOP languages (Object-Oriented Programming languages) support all three ("Strong" encapsulation)
* C is NOT an OOP language and only supports #1

## Defining Structures

* Create a structure that models a *book*

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
  char *title;
  Person author;
  Date publishDate;
  double rating;
} Book;


```

* Generally (modern) convention: use `UpperCamelCasing`
* Generally, structure declarations are placed into header files, often of similar name, `book.h`
* Generally you should document them
* The order matters if you use *composition*: one structure may be composed of other variables and structures which may be composed of others, etc.


## Structure Usage

* Once defined, you can use a structure like any other type

```c
Book book;
```

* To access the "member variables" or "components", *directly* use the "dot operator"
* When you have a *pointer* to a structure, you use the arrow operator: `->`

```c
Book *b = ...;
b->title = ...;
```

* YOu can define factory functions to create new instances of your structure, returning a pointer to a *dynamically allocated* instance of the structure
  * remember: to use `sizeof(Book)` with `malloc()`
* Other common functions:
  * A "toString" function that returns a string (`char *`) representation of the structure
  * A "destructor" function that cleans up all memory associated with a structure
  * An "initialization" function: if you already have an instance of a structure and you want to initialize its values
  * Similar functions that act on arrays of structures
    * example: "print all books"

# Demo Code

demo.c:

```c
/**
 * Demo Code
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "book.h"

int main(int argc, char **argv) {

  char *fileName = "books.csv";
  int numBooks;
  Book *books = loadBookCsvData(fileName, &numBooks);

  double highestRating = -1;
  Book *bestBook;

  for(int i=0; i<numBooks; i++) {

    printBook(&books[i]);

    if(books[i].rating > highestRating) {
      highestRating = books[i].rating;
      bestBook = &books[i];
    }

  }

  //print the title, author, year of the "best" book (highest rated book)
  printf("Highest Rating is %f\n", highestRating);
  printBook(bestBook);

  //bad, memory leak:
  //Book b =  *createBook("Mattimeo", "Brian", "Jacques", 1989, 4.25);
  Book b;
  initBook(&b, "Mattimeo", "Brian", "Jacques", 1989, 4.25);
  printf("title = %s\n", b.title);

  Book *b2 = createBook("Redwall", "Brian", "Jacques", 1985, 4.75);
  freeBook(b2);

  Book myBooks[3];
  initBook(&myBooks[0], "Three Body Problem", "Cixin", "Liu", 2008, 5.0);
  initBook(&myBooks[1], "Art of War", "Sun", "Tzu", 1, 4.5);
  initBook(&myBooks[2], "Good Omens", "Terry", "Pratchett", 1990, 5.0);
  printBooks(myBooks, 3);
}

```

book.h:

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
	    char *title;
	    Person author;
	    Date publishDate;
	    double rating;
	} Book;


Book *loadBookCsvData(const char *filePath, int *numBooks);

/**
 * Creates a brand new instance of a Book with the
 * values passed in and returns a pointer to it in memory
 */
  Book *createBook(const char *title,
                   const char *authorFirstName,
                   const char *authorLastName,
                   int publishYear,
                   double rating);
  /**
   * This function initializes the given book with the
   * values passed in.
   */
  void initBook(Book *b,
                 const char *title,
                   const char *authorFirstName,
                   const char *authorLastName,
                   int publishYear,
                   double rating);

void freeBook(Book *b);

char *bookToString(const Book *b);

void printBook(const Book *b);

/**
 * Prints each of the books in the array books to the
 * standard output
 */
void printBooks(const Book *books, int n);


char *bookToString(const Book *b);

```

book.c:

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "book.h"

char *bookToString(const Book *b) {

    char temp[1000];
    sprintf(temp, "%-40s %s, %s (%d), %5.2f", b->title, b->author.lastName, b->author.firstName, b->publishDate.year, b->rating);
    char *result = (char *) malloc( sizeof(char) * ( strlen(temp) + 1 ));
    strcpy(result, temp);
    return result;
}

void printBook(const Book *b) {
    char *str = bookToString(b);
    printf("%s\n", str);
    free(str);
    return;
}



Book *loadBookCsvData(const char *filePath, int *numBooks) {

  FILE *f = fopen(filePath, "r");

  char buffer[1000];
  //read the first line:
  char *line = fgets(buffer, 1000, f);
  int numberOfBooks = atoi(buffer);
  *numBooks = numberOfBooks;
  Book *books = (Book *) malloc(sizeof(Book) * numberOfBooks);

  for(int i=0; i<numberOfBooks; i++) {
    line = fgets(buffer, 1000, f);
    if( buffer[strlen(buffer)-1] == '\n' ) {
      buffer[strlen(buffer)-1] = '\0';
    }
    char *title = strtok(buffer, ",");
    char *authorFirstName = strtok(NULL, ",");
    char *authorLastName = strtok(NULL, ",");
    int yearPublished = atoi(strtok(NULL, ","));
    double rating = atof(strtok(NULL, ","));

    Book *b = createBook(title, authorFirstName, authorLastName, yearPublished, rating);
    //TODO: check memory leaks here!
    books[i] = *b;
  }

  fclose(f);
  return books;
}

Book *createBook(const char *title,
                 const char *authorFirstName,
                 const char *authorLastName,
                 int publishYear,
                 double rating) {
  if(title == NULL || authorFirstName == NULL || authorLastName == NULL) {
    return NULL;
  } else if( publishYear <= 0 || rating < 0 || rating > 5.0) {
    return NULL;
  }
  Book *b = (Book *) malloc( sizeof(Book) * 1 );

  initBook(b, title, authorFirstName, authorLastName, publishYear, rating);

  return b;

}

void initBook(Book *b,
               const char *title,
                 const char *authorFirstName,
                 const char *authorLastName,
                 int publishYear,
                 double rating) {
  if(b == NULL || title == NULL || authorFirstName == NULL || authorLastName == NULL) {
    return;
  } else if( publishYear <= 0 || rating < 0 || rating > 5.0) {
    return;
  }

  b->title = (char *) malloc(sizeof(char) * (strlen(title) + 1 ));
  strcpy(b->title, title);
  b->author.firstName = (char *) malloc(sizeof(char) * (strlen(authorFirstName) + 1 ));
  strcpy(b->author.firstName, authorFirstName);
  b->author.lastName = (char *) malloc(sizeof(char) * (strlen(authorLastName) + 1 ));
  strcpy(b->author.lastName, authorLastName);

  b->publishDate.year = publishYear;
  b->rating = rating;
  return;
}

void freeBook(Book *b) {
  free(b->title);
  free(b->author.firstName);
  free(b->author.lastName);
  free(b);
  return;
}


void printBooks(const Book *books, int n) {

  printf("Title           Author        Year\n");
  printf("-=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=-\n");
  for(int i=0; i<n; i++) {

      //books is a pointer to an array of books: Book *
      //books[i] is a single book: Book
      //printBook expects a pointer to a book: Book *
      // we need to translate books[i] into a pointer in
      // order to pass it to printBook...
      //  To do that: &books[i]
      printBook(&books[i]);
  }
  printf("-=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=-\n");
}


```


```text








```
