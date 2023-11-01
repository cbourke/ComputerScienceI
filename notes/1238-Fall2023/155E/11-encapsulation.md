
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

* once definded, you can use a structure like any other type


* To access the "member variables" or "components", use the "dot operator"

```c
Book book;

//Neuromancer,William,Gibson,1984,3.88
book.title = (char *) malloc(sizeof(char) * (11+1));
strcpy(book.title, "Neuromancer");
book.author.firstName = (char *) malloc(...);
strcpy(book.author.firstName, "William");
book.rating = 3.88;

```


```text








```
