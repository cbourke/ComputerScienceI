
# ECEN 1940 - Computer Science I
## Encapsulation - Structures
### Spring 2022

* Built-in types such as `int, double, char` are not enough to model real-world data
* Real world entities have multiple pieces of data that should be *grouped* together
* Examples: Person/office data, baseball teams, states, etc. all have multiple variables associated with them
* In C you can define a *structure*: allows you to group multiple variables together into one logical unit
* This is generally referred to as *encapsulation*
  1. Grouping of data
  2. Protection of data
  3. Grouping of functionality that acts on that data
* C only supports #1: grouping of data (weak encapsulation)

## Defining Structures

```c
typedef struct {
  int month;
  int day;
  int year;
} Date;

typedef struct {
  char *firstName;
  char *lastName;
  int nuid;
  char *city;
  char *state;
  char *office;
  double heightMeters;
  Date hireDate;
} Faculty;
```

Observations

* A structure is *composed* of multiple pieces of data or even *other structures* this is called "composition"
* The order of declaration matters: if you use a structure in another structure, it must be declared above
* Each variable inside a structure is called a *member variable*
* You can/may want to designate some unique identifier for each possible *instance* of a structure
* To get a single *component* (variable) in a structure you use the *component selection operator* `.` (dot operator)
* Styling:
  * Names of structures can/should use `UpperCamelCasing`
  * Note: internal structures in C use a `foo_t` naming convention; ex: `date_t, time_t`
  * Member variables use a `lowerCamelCasing` convention
  * You use `typedef struct` with the name at the end terminated by a semicolon
* Usually, structures are declared in a header file with an appropriate name

## Using Structures

* Once defined, a structure can be declared like any other variable: `Faculty f` or a pointer to a structure: `Faculty *f`
* You can (and should) design and implement a "factory" function to make creating *instances* of a structure easy
* When you have a regular old structure, you use the dot operator
* When you have a pointer to a structure, you use the arrow operator: `->`
* You can dynamically allocate a new structure using `malloc()` and `sizeof()` with your structure; example: `sizeof(Faculty)`
* You can use the curly brackets to initialize a quick and dirty structure for testing:
  `  Faculty f = {"Joe", "Smith", 1234, 1.25, {4, 6, 2022}};
`
* Often you can write and implement other convenience functions:
  * Destructor: a way to "clean" up (free) a structure
  * An initialization function
  * A function to print a structure in a human-readable format
  * Serialize to a JSON format
  * More generally: a `toString()`-style function
  * You can do similar functions for arrays of structures

## Arrays of Structures

* An array of integers is `int *a`
* An array of structures would be `Faculty *deptFaculty`
* Just as with an array of anything, you have to keep track of its size

### Alternatives

* We demonstrated an array of structures
* You can also have an array of pointers to structures:

`Faculty **faculty;`

* A hybrid approach: you have a contiguous allocation of memory of structures AND an array of pointers to them
* If you want to know more: see the tutorial videos and the book

## Demo Code

```c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "faculty.h"

Faculty * createFaculty(const char *firstName,
              const char *lastName,
              int nuid,
              double heightMeters,
              int yearOfHire,
              int monthOfHire,
              int dayOfHire) {

  Faculty *f = (Faculty *) malloc( sizeof(Faculty) * 1 );

  initFaculty(f, firstName, lastName, nuid, heightMeters, yearOfHire, monthOfHire, dayOfHire);

  return f;

}

void initFaculty(Faculty *f,
              const char *firstName,
              const char *lastName,
              int nuid,
              double heightMeters,
              int yearOfHire,
              int monthOfHire,
              int dayOfHire) {

  f->firstName = (char *) malloc(sizeof(char) * (strlen(firstName) + 1));
  strcpy(f->firstName, firstName);
  f->lastName = (char *) malloc(sizeof(char) * (strlen(lastName) + 1));
  strcpy(f->lastName, lastName);
  f->nuid = nuid;
  f->heightMeters = heightMeters;
  f->hireDate.day = dayOfHire;
  f->hireDate.month = monthOfHire;
  f->hireDate.year = yearOfHire;

  return;
}

void freeFaculty(Faculty *f) {
  free(f->firstName);
  free(f->lastName);
  free(f);
}

char * facultyToString(const Faculty *f) {

  char temp[1000];
  sprintf(temp, "%-15s %-15s (%08d) %04d-%02d-%02d", f->lastName, f->firstName, f->nuid, f->hireDate.year, f->hireDate.month, f->hireDate.day);
  char *result = (char *) malloc(sizeof(char) * (strlen(temp)+1));
  strcpy(result, temp);
  return result;
}

void printAllFaculty(const Faculty *faculty, int n) {

  for(int i=0; i<n; i++) {
    char *s = facultyToString(&faculty[i]);
    printf("%s\n", s);
    free(s);
  }
  return;
}


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "faculty.h"

int main(int argc, char **argv) {

  Faculty *me = createFaculty("Chris", "Bourke", 00123456, 1.7526, 2010, 7, 1);
  Faculty *grace =createFaculty("Grace", "Hopper", 12332112, 1.5, 1906, 12, 9);
  Faculty *joe =createFaculty("Joe", "Smith", 1234, 1.5, 1956, 12, 9);
  Faculty *jane =createFaculty("Jane", "Smith", 5678, 1.5, 2016, 10, 3);
  printf("Hello, %s and %s\n", me->firstName, grace->firstName);

  int n = 4;
  Faculty *deptFaculty = (Faculty *) malloc(sizeof(Faculty) * n);
  deptFaculty[0] = *me;
  deptFaculty[1] = *grace;
  deptFaculty[2] = *joe;
  deptFaculty[3] = *jane;

  printAllFaculty(deptFaculty, n);

  return 0;

}

```


```text











```
