/**
 * Demonstration code template.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "book.h"

int main(int argc, char **argv) {

    // Book *scythe = createBook("2983479238", "Scythe", "Neal", "Shusterman");
    // Book *dispossessed = createBook("23423532", "The Dispossessed", "Ursula", "le Guin");

    // printBook(scythe);
    // printBook(dispossessed);

    // freeBook(scythe);
    // freeBook(dispossessed);

    // Book goodOmens;
    // initBook(&goodOmens, "987423987", "Good Omens", "Neil", "Gaiman");
    // printBook(&goodOmens);

    int numBooks;
    Book *books = loadBookData("./goodreads-abridged.csv", &numBooks);
    for(int i=0; i<numBooks; i++) {
        printBook(&books[i]);
    }

    //1. Goal A: find the "best/worst" book (highest rating)
    //outline:
    //assume initially that its the first one:
    Book bestBook = books[0];
    for(int i=0; i<numBooks; i++) {
        //books is a Book *
        //books[i] is essentially a dereference: a regular old Book
        if( books[i].rating > bestBook.rating ) {
            bestBook = books[i];
        }
    }
    printf("Best book is:\n");
    printBook(&bestBook);


    //2. Goal B: find the "Worst" book (lowest year);
    //outline:
    //assume initially that its the first one:
    Book worstBook = books[0];
    for(int i=0; i<numBooks; i++) {
        //books is a Book *
        //books[i] is essentially a dereference: a regular old Book
        if( books[i].rating < worstBook.rating ) {
            worstBook = books[i];
        }
    }
    printf("Worst book is:\n");
    printBook(&worstBook);


    //3. Goal C: find a book/all books by Neil Gaiman

    return 0;
}
