
# CSCE 155H - Computer Science I
## Encapsulation - Structures & Classes
### Fall 2020

* Built-in primitive types `int, double, char` are very limiting: not everything is a number or character
* Real world entities are made up of multiple aspects (data)
* Example Lab 10 sorting teams
  * Kept a lot of different but related data in separate arrays
  * Every swap required the swap of very record in both arrays
  * Lot of extra bookkeeping
  * Very inconvenient to separate related pieces of data
* Solution: encapsulation
  * C: structures
  * Java: Class 
* Encapsulation is a mechanism that allows you to:
  1. Group pieces of data together into one logical "unit"
  2. Protect that data from the outside code
  3. Group functionality that acts on that data with the data
* C only supports #1: grouping of data
* Java supports all three

## Example: C

* Design a structure that models a film

```c

typedef struct {
  int year;
  int month;
  int day;
} Date;

typedef struct {
  char * title;
  int runTime;
  double imdbRating;
  Date releaseDate;
} Film;
```

Observations
  * To define a structure you use `typedef struct`
  * Opening/closing curly brackets enclose or encapsulate the variables that belong to the structure
  * Variables in a structure a known as *member variables* 
  * At the end you provide the *name* of the structure
    * By convention: the name of the sturcture is `UpperCamelCased`
    * By convention: member variables are `lowerCamelCased`
  * You use a semicolon at the end of each variable!
  * Order matters: if you have a structure that uses another structure, the declaration must be in order
  * Usually structure declarations are placed into header files
  * When a structure has an instance of another structure in it, we refer to this as *composition*; alternatively we say that a structure "owns" an instance of another structure

## Example: java

* Design a class that models a film

```java
import java.time.LocalDate;

public class Film {

	private String title;
	private int runTime;
	private double imdbRating;
	private LocalDate releaseDate;

}
```

Observations
  * Similar naming conventions: `UpperCamelCasing` for class names, `lowerCamelCasing` for member variable names
  * With Java there is "strong encapsulation": you can "protect" your variables from the outside world
    * `public` - ANY code can see and change your variables!
    * The lack of a keyword makes a variable "package protected"
    * `protected` - the class and any subclass can see your variables (involves inheritance)
    * `private` - only your class can "see" the variables, in general make all of your variables `private` unless there is Very Good Reason to do so

## Using Structures

* once declared, you can create an instance of a structure naturally

```c

Film * createFilm(const char *title,
                  int runTime,
                  double imdbRating,
                  Date releaseDate) {

    Film *f = (Film *) malloc(sizeof(Film) * 1);

    f->title = (char *) malloc(sizeof(char) * (strlen(title)+1));
    strcpy(f->title, title);
    f->runTime = runTime;
    f->imdbRating = imdbRating;
    f->releaseDate = releaseDate;

    return f;
}
```

```text














```