/**
 * Chris Bourke
 *
 * Demo Code
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "book.h"

int main(int argc, char **argv) {

    //Exercise: process a full CSV file
    FILE *f = fopen("./my_goodreads_data.csv", "r");

    char buffer[1000];

    //reads the first line, ignore it...
    char *line = fgets(buffer, 1000, f);
    line = fgets(buffer, 1000, f);
    int i = 0;
    int numBooks = 0;
    while(line != NULL) {
        numBooks++;
        line = fgets(buffer, 1000, f);
    }

    Book *books = (Book *) malloc( sizeof(Book) * numBooks );

    rewind(f);
    //burn/ignore the first line
    line = fgets(buffer, 1000, f);
    //setup the first iteration of the while loop...
    line = fgets(buffer, 1000, f);

    while(line != NULL) {
        //process the current line...
        char *idStr = strtok(buffer, ",");
        int id = atoi(idStr);
        char *title = strtok(NULL, ",");
        char *lastName = strtok(NULL, ",");
        char *firstName = strtok(NULL, ",");
        char *isbn = strtok(NULL, ",");
        char *averageRatingStr = strtok(NULL, ",");
        double averageRating = atof(averageRatingStr);
        char *publisher = strtok(NULL, ",");
        char *yearStr = strtok(NULL, ",");
        int year = atoi(yearStr);
        char *dateRead = strtok(NULL, ",");

        //books:    Book *
        //books[i]: Book
        //&books[i]: Book *
        initBook(&books[i], id, title, lastName, firstName, isbn, averageRating, publisher, year, dateRead);

        i++;
        //get the next line
        line = fgets(buffer, 1000, f);
    }
    fclose(f);


    for(int i=0; i<numBooks; i++) {
        char *str = bookToString(&books[i]);
        printf("%s\n", str);
        free(str);

    }

    //find the oldest book
    Book oldestBook = books[0];
    for(int i=0; i<numBooks; i++) {
        if(books[i].year < oldestBook.year) {
            oldestBook = books[i];
        }
    }
    char *str = bookToString(&oldestBook);
    printf("Oldest Book: %s\n", str);
    free(str);

    //find the oldest book
    Book newestBook = books[0];
    for(int i=0; i<numBooks; i++) {
        if(books[i].year > newestBook.year) {
            newestBook = books[i];
        }
    }
    char *str2 = bookToString(&newestBook);
    printf("Newest Book: %s\n", str2);
    free(str2);

    for(int i=0; i<numBooks; i++) {
        freeBook(&books[i]);
    }
    free(books);

    return 0;
}
