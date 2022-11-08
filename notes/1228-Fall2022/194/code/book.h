
typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    char *firstName;
    char *lastName;
    Date dateOfBirth;
} Author;

typedef struct {
    char *title;
    Author author;
    double rating;
    Date releaseDate;
} Book;

/**
 * Factory function that creates Book instances given the
 * data provided.
 */
Book * createBook(const char *title,
                  const char *authorFirstName,
                  const char *authorLastName,
                  int releaseYear,
                  double rating);

/**
 * This function *initializes* the given Book's variables assuming
 * that the book has already been created
 */
int initBook(Book *b,
             const char *title,
             const char *authorFirstName,
             const char *authorLastName,
             int releaseYear,
             double rating);

/**
 * Prints the given book to the standard output
 */
void printBook(const Book *b);

/**
 * Returns a (new) string representation of the given Book
 */
char *bookToString(const Book *b);

/**
 * Loads Book data from teh given CSV file and returns a new
 * array containing all the Book instances.
 *
 * The size of the resulting array is communicated through hte
 * pass-by-reference variable numBooks
 */
Book *loadBooksFromCsvFile(const char *fileName, int *numBooks);

/**
 * This function finds the "best" book with respect to the rating
 * and returns a pointer to it
 */
Book * getBestBook(const Book *books, int numBooks);

/**
 * This function finds the "worst" book with respect to the rating
 * and returns a pointer to it
 */
Book * getWorstBook(const Book *books, int numBooks);

/**
 * Returns a new array containing all books by the given author.
 *
 * Communicates the size of the resulting array in the pass-by-reference
 * varaible numResults
*/
Book * getAllBooksByAuthor(const Book *books, int numBooks, Author author, int *numResults);

/**
 * This is a "comparator" function that takes two authors and determines if they
 * are equal based on whether or not the first name and the last name are the same
 */
int cmpAuthor(const Author *a, const Author *b);