
# CSCE 155H - Computer Science I
## Encapsulation - Structures & Classes
### Fall 2023

* Built-in primitive types `int, double, char` are very limiting: not everything is a number or character
* Real world entities are *composed* of multiple pieces of data
* Encapsulating multiple pieces of data into one "object" or "thing" allows you to deal with that one "thing"
* Solution: encapsulation
  * C: structures
  * Java: Class
* Encapsulation is a mechanism that allows you to:
  1. Group pieces of data together to form one logical "unit"
  2. Protect that data from the outside world/code
  3. Group functionality that acts on that data with the data
* Java: supports all three, it has *strong* encapsulation (because it is an OOP = Object-Oriented Programming language)
* C: weak encapsulation, it only supports #1

## Java

* Java is an OOP language that uses classes for encapsulation
  * Class names are `UpperCamelCased`
  * *Member variables* are `lowerCamelCased`
* Java supports "strong encapsulation": you can "protect" your variables from the outside world
    * `public` - ANY code can see and change your variables!
    * The lack of a keyword makes a variable "package protected"
    * `protected` - the class and any subclass can see your variables (involves inheritance)
    * `private` - only your class can "see" the variables, in general make all of your variables `private` unless there is Very Good Reason to do so
* Java allows you to define *nontrivial* methods; ex: `getAge()`
  * It would be *bad design* to locate this functionality *outside* the class

## C

* C only supports *weak* encapsulation: #1 the grouping of data through *structures*
* Syntax:
  * Define using `typedef struct`
  * Generally: use `UpperCamelCasing` for structure name
  * Use `lowerCamelCasing` for structure variables
  * Declaration order matters
* Other:
  * IF you have a regular structure, `Book b`, then use the dot operator: `b.title`
  * If you have a pointer: `Book *b` then use the arrow operator
  `b->title`

## Demo Code

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
} Person;

typedef struct {
    char *title;
    Person author;
    Date publishDate;
    double rating;
} Book;

Book *createBook(const char *title,
                 const char *authorFirstName,
                 const char *authorLastName,
                 int publishYear,
                 double rating);

void initBook(Book *b,
              const char *title,
              const char *authorFirstName,
              const char *authorLastName,
              int publishYear,
              double rating);

char *bookToString(const Book *b);

//TODO: documentation
void printBook(const Book *b);

void printBooks(const Book *books, int n);

void freeBook(Book *b);
```

book.c:
```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "book.h"

Book *createBook(const char *title,
                 const char *authorFirstName,
                 const char *authorLastName,
                 int publishYear,
                 double rating) {

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

    b->title = (char *) malloc( sizeof(char) * (strlen(title) + 1) );
    strcpy(b->title, title);
    b->author.firstName = (char *) malloc( sizeof(char) * (strlen(authorFirstName) + 1) );
    strcpy(b->author.firstName, authorFirstName);
    b->author.lastName = (char *) malloc( sizeof(char) * (strlen(authorLastName) + 1) );
    strcpy(b->author.lastName, authorLastName);
    b->publishDate.year = publishYear;
    b->rating = rating;


}

char *bookToString(const Book *b) {
    char temp[1000];
    sprintf(temp, "%-40s %s, %s (%.2f)", b->title, b->author.lastName, b->author.firstName, b->rating);
    char *result = (char *) malloc( sizeof(char) * (strlen(temp) + 1) );
    strcpy(result, temp);
    return result;
}

void printBook(const Book *b) {
    char *s = bookToString(b);
    printf("%s\n", s);
    free(s);
    return;
}

void freeBook(Book *b) {
    if(b->title != NULL) {
        free(b->title);
    }
    free(b->author.firstName);
    free(b->author.lastName);
    free(b);
}

void printBooks(const Book *books, int n) {
  for(int i=0; i<n; i++) {
    printBook(&books[i]);
  }
}


```

bookDemo.c:
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

  Book *b = createBook("Venus Plus X", "Theodore", "Sturgeon", 1960, 3.5);
  printBook(b);
  freeBook(b);

  //books is an array: Book *
  //books[0] (one of them) is a Book
  // we need to *dereference* whatever createBook returns in order to assign it..
  // Book * => Book
  Book books[3];
  initBook(&books[0], "Mattimeo", "Jacque", "Bryan", 1989, 3.75);
  initBook(&books[1], "Butlerian Jihad", "Brian", "Herbert", 2004, 0.50);
  initBook(&books[2], "Emma", "Jane", "Austen", 1800, 4.5);
  // Book *books = (Book *) malloc( sizeof(Book) * 3 );
  // initBook(&books[0], "Mattimeo", "Jacque", "Bryan", 1989, 3.75);
  // initBook(&books[1], "Butlerian Jihad", "Brian", "Herbert", 2004, 0.50);
  // initBook(&books[2], "Emma", "Jane", "Austen", 1800, 4.5);

  printBooks(books, 3);

  // free(&books[0]);
  // free(&books[1]);
  // free(&books[2]);

  return 0;
}


```

```text




```
