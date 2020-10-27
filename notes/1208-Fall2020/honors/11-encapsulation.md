
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

Observations:
* when you have a regular old structure, you use the dot operator `.` to access member variables
* When you have a pointer to a structure, you use the arrow operator `->`
* Alternatively: you can create an "initialization" function: if you already have a structure allocated, you simpley need to set is values
* Other convenience functions
  * A way to print a structure to the standard output
  * A way to generally provide a string representation of a structure
     * Human readable
     * XML or JSON for EDI = Electronic Data Interchange
  * A function to free up a structure (destructor)

## Java; convenience methods

* Java: creational methods are called *constructors*
* You can have more than one constructor as long as they differ in the number of type of parameters
* You can easily auto-generate constructor code in eclipse: `Source` > `Generate Constructor Using Fields`
* Constructors may call other constructors to avoid duplicating code using the keyword `this()`
* By default, if no constructor is defined, then a no-argument default constructor is provided that sets all member variable values to defaults (zeros, `null`, `false`)
* Other convenience structures:
  * Destructors in Java?  Do not exist ;) no memory management
  * All objects have a `toString()` method you can define; by default it prints the JVM memory address; you can "override" this functionality by defining your own method (or use eclipse to auto-generate your code)
  * When classes are used in standard collections (`List`, `Set`, `Map`), often it is required that they have properly defined `hashCode()` and `equals()` methods implemented
  * Getters (accessors): from outside the class, you may want to get the value of an individual member variable
  * Setters (mutators): allow the outside world to change a class's member variable values.  Only do this if you have a Very Good Reason to do so
  * In general you want to prefer *immutable* objects


## Arrays of structures, Collections of classes

### Arrays of structures in C


## Code

film.h:
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

/**
 * Dynamically creates a new film instance from the given
 * data and returns a pointer to it.
 */
Film * createFilm(const char *title, int runTime, double imdbRating, Date releaseDate);

void initFilm(Film *f,
              const char *title,
              int runTime,
              double imdbRating,
              Date releaseDate);

//TODO: documentation
void printFilm(const Film *f);

char *filmToString(const Film *f);

void freeFilm(Film *f);
```

film.c: 
```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "film.h"

Film * createFilm(const char *title,
                  int runTime,
                  double imdbRating,
                  Date releaseDate) {

    Film *f = (Film *) malloc(sizeof(Film) * 1);

    initFilm(f, title, runTime, imdbRating, releaseDate);

    return f;
}
//TODO: consider basic error handling and data validation
void initFilm(Film *f,
              const char *title,
              int runTime,
              double imdbRating,
              Date releaseDate) {

    f->title = (char *) malloc(sizeof(char) * (strlen(title)+1));
    strcpy(f->title, title);
    f->runTime = runTime;
    f->imdbRating = imdbRating;
    f->releaseDate = releaseDate;
    return;
}

void printFilm(const Film *f) {
    char *s = filmToString(f);
    printf("%s\n", s);
    free(s);
    return;
}

char *filmToString(const Film *f) {
    char temp[1000];
    sprintf(temp, "%-20s (%d-%02d-%02d)", f->title, f->releaseDate.year, f->releaseDate.month, f->releaseDate.day);
    char *result = (char *) malloc((strlen(temp) + 1) * sizeof(char));
    strcpy(result, temp);
    return result;
}

void freeFilm(Film *f) {
    free(f->title);
    free(f);
    return;
}
```
demo.c:
```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "film.h"

int main(int argc, char **argv) {

    Date d;
    d.year = 1979;
    d.month = 8;
    d.day = 15;
    Film *f1 = createFilm("Apocalypse Now", 147, 8.4, d);

    Date d2 = {1977, 5, 25};
    Film *f2 = createFilm("Star Wars", 121, 8.6, d2);

    Date d3 = {2019, 12, 20};
    Film *f3 = createFilm("Cats", 110, 2.8, d3);

    int n = 3;
    // Film *films = (Film *) malloc(sizeof(Film) * n);
    // //films is a Film * (Film pointer)
    // //films[0] is a regular old structure: Film
    // //f1 is a Film * (Film pointer)
    // films[0] = *f1;
    // films[1] = *f2;
    // films[2] = *f3;

    //alternative:
    Film **films = (Film **) malloc(sizeof(Film *) * n);
    films[0] = f1;
    films[1] = f2;
    films[2] = f3;

    printFilm(f1);
    printFilm(films[1]);
    printFilm(films[2]);

    freeFilm(f1);
    freeFilm(f2);
    freeFilm(f3);

    //third alternative: see the book

    return 0;
}
```

Film.java:
```java
import java.time.LocalDate;

public class Film {

	private String title;
	private int runTime;
	private double imdbRating;
	private LocalDate releaseDate;
	
	public Film(String title, double imdbRating) {
		this(title, 0, imdbRating, null);
	}

	public Film(String title, int runTime, double imdbRating, LocalDate releaseDate) {
		if(title == null) {
			throw new IllegalArgumentException("You cannot provide a null title!");
		}
		this.title = title;
		this.runTime = runTime;
		this.imdbRating = imdbRating;
		this.releaseDate = releaseDate;
	}
	
	public String getTitle() {
		return this.title;
	}
	
//	public void setTitle(String title) {
//		if(title == null) {
//			throw new IllegalArgumentException("You cannot provide a null title!");
//		}
//		this.title = title;
//	}

	public int getRunTime() {
		return runTime;
	}

	public double getImdbRating() {
		return imdbRating;
	}

	public LocalDate getReleaseDate() {
		return releaseDate;
	}

	public String toString() {
		return this.title + " (" + this.releaseDate.getYear() + ")";
	}


	
	
	

}
```

Demo.java:
```java
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Demo {

	public static void main(String args[]) {
		
		LocalDate d = LocalDate.of(2019, 12, 20);
		
		Film f1 = new Film("Cats", 110, 2.8, d);
		Film f2 = new Film("Star Wars", 110, 2.8, d);
		Film f3 = new Film("Apocolypse Now", 110, 2.8, d);
		
		List<Film> films = new ArrayList<>();
		films.add(f1);
		films.add(f2);
		films.add(f3);
		System.out.println(films);
		
	}

}

```

```text














```