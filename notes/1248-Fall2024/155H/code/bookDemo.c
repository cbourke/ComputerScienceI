/**
 * Demonstration code template.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#include "book.h"

int main(int argc, char **argv) {

    Book *b1 = createBook("The Dispossessed", "Ursula", "le Guin", 1974);
    Book *b2 = createBook("Fahrenheit 451", "Ray", "Bradbury", 1953);

    char *s1 = bookToString(b1);
    char *s2 = bookToString(b2);

    printf("%s\n", s1);
    printf("%s\n", s2);

    int numBooks;
    Book *books = loadBookData("./goodreads-abridged.csv", &numBooks);
    for(int i=0; i<numBooks; i++) {
      char *bStr = bookToString(&books[i]);
      printf("%s\n", bStr);
    }

    //find the oldest book
    Book b = books[0];
    for(int i=0; i<numBooks; i++) {
        if(books[i].publishDate.year < b.publishDate.year) {
            b = books[i];
        }
    }
    char *oldestB = bookToString(&b);
    printf("%s\n", oldestB);



    return 0;
}
