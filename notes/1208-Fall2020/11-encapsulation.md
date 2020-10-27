
# CSCE 155E - Computer Science I
## Encapsulation - Structures
### Fall 2020

* Built-in primitive types (`int, double, char`) are limiting: not everything is a simple number of character
* Real world entities are made up of multiple pieces of data
* Example: Lab 10 had baseball teams
  * It is a bad idea to represent real world entities with separate pieces of data
  * Lots of bookkeeping
  * Ideally, those pieces of *related* data should be collected into one "unit" or "thing" or "entity"
  * In C that entity is a *structure*
* This is generally referred to as *encapsulation*
  1. The grouping of data
  2. The protection of data
  3. THe grouping of functionality that acts on that data
* More of an OOP = Object Oriented Programming concept
* C only really supports #1: the grouping of data

## Defining Structures

* Goal: define a structure that models a book

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
  char *isbn;
  char *title;
  Person author;
  int numberOfPages;
  Date publishDate;
} Book;
```

Observations
* a structure is *composed* of multiple pieces of data
* a structure can be composed of primitive types and/or other strctures
* When a structure "owns" another structure it is called *composition*
* Each variable in a structure is a member variable or "field"
* You can/may want to design a unique identifier field
* Styling/conventions/syntax:
  * Names of structures use `UpperCamelCasing`
  * Names of member variables use `lowerCamelCasing`
  * You use `typedef struct` and opening/closing curly brackets to define what the structure is composed of
  * Semicolons end each variable
  * You provide the name of the structure at the end followed by a semicolon
* Order matters: you must declare a structure before you can use it or use it in other structures
* Usually structures are declared in a header file

## Using Structures

* You can easily create a "factory" function to help you create instances of structures
* YOu can use pointers to structures as you have with pointers to other variable types
  * When you have a pointer to a structure, you use the arrow operator, `->` to access member variables
* When you have a regular old structure, you use the dot operator, `.` to access member variables
* Once you have defined a structure, you can use `sizeof(Book)` to determine how many bytes each one takes
* Other common/convenience functions include:
  * A function to create a human-readable string representation of a structure (a "to string" function)
  * A function to free up all aspects of a string a "destructor" function
  * An "initialization" function: if you already have an instance of a structure and you want to initialize its values
  * Similar functions that act on arrays of structures

book.h:
```c

/**
 * models a date using the year, month and day
 */
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
  char *isbn;
  char *title;
  Person author;
  int numberOfPages;
  Date publishDate;
} Book;

//TODO: documentation!
char *deepStringCopy(const char *s);

Book * createBook(const char *isbn,
  const char *title,
  const char *authorFirstName,
  const char *authorLastName,
  int numberOfPages);

void initBook(Book *b,
  const char *isbn,
  const char *title,
  const char *authorFirstName,
  const char *authorLastName,
  int numberOfPages);

void freeBook(Book *b);

char * bookToString(const Book *b);

void printBook(const Book *b);

//TODO: create a printBooks function
void printBooks(const Book *b, int size);
```

book.c:
```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "book.h"

char *deepStringCopy(const char *s) {
  char *c = (char *) malloc( (strlen(s)+1) * sizeof(char));
  strcpy(c, s);
  return c;
}

Book * createBook(const char *isbn,
  const char *title,
  const char *authorFirstName,
  const char *authorLastName,
  int numberOfPages) {

  Book *b = (Book *) malloc(sizeof(Book) * 1);
  initBook(b, isbn, title, authorFirstName, authorLastName, numberOfPages);
  return b;
}
//TODO change the return type to int and do error handling!
void initBook(Book *b,
  const char *isbn,
  const char *title,
  const char *authorFirstName,
  const char *authorLastName,
  int numberOfPages) {

  b->isbn = deepStringCopy(isbn);
  b->title = deepStringCopy(title);
  b->author.firstName = deepStringCopy(authorFirstName);
  b->author.lastName = deepStringCopy(authorLastName);
  b->numberOfPages = numberOfPages;
  return;
}

void freeBook(Book *b) {
  free(b->isbn);
  free(b->title);
  free(b->author.firstName);
  free(b->author.lastName);
  free(b);
}


char * bookToString(const Book *b) {
  char temp[1000];
  sprintf(temp, "%-30s by %-10s, %s", b->title, b->author.lastName, b->author.firstName);
  return deepStringCopy(temp);
}

void printBook(const Book *b) {
  char *s = bookToString(b);
  printf("%s\n", s);
  free(s);
  return;
}

void printBooks(const Book *b, int size) {

    //b is... Book * (a pointer to a Book!)
    //b[i] is a... Book (a regular old structure)
    //&b[i] is a pointer to the i-th book!
    for(int i=0; i<size; i++) {
      printBook(&b[i]);
    }
}
```

demo.c version 1:
```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "book.h"





int main(int argc, char **argv) {

  Book b1, b2, b3;
  initBook(&b1, "978-0062434029", "Shakespeare for Squirrels", "Christopher", "Moore", 270);
  initBook(&b2, "978-0451524935", "1984", "George", "Orwell", 328);
  initBook(&b3, "1234", "Illiad", "Homer", "Simpson", 1000);

  int n = 3;
  Book *library = (Book *) malloc(sizeof(Book) * n);
  library[0] = b1;
  library[1] = b2;
  library[2] = b3;

  printBooks(library, n);

  return 0;
}
```

Alternative:
* You can use arrays of pointers to structures to potentially speed things up and save memroy
* Example:

```c

  int n = 3;
  Book **libraryOfPointers = (Book **) malloc(sizeof(Book*) * n);
  libraryOfPointers[0] = &b1;
  libraryOfPointers[1] = &b2;
  libraryOfPointers[2] = &b3;

  //libraryOfPointers is a Book **
  //libraryOfPointers[0] is a Book *
  //b1 is a Book
```

## Summary

* Principles of Design: when defining/designing a structure: think about the essential pieces of data that make it up
  * Identify each "field" or "member" variable and its type
  * Decompose a structure into smaller and smaller parts or "substructures" UNTIL it is either trivially representable OR a structure is already defined for you `date_t`
  * Beware of YAGNI: You Ain't Gonna Need It (don't unnecessarily over-engineer your structures)
  * Don't reinvent the wheel: if there is a nice (convenient) structure already defined, use it
  * The *semantics* of a real-world entity will dictate design

