
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
    Date releaseDate;
    double rating;
} Book;


/**
 * This is a "factory" function that creates a new instance of a Book
 */
Book *createBook(const char *title,
                 const char *authorFirstName,
                 const char *authorLastName,
                 int releaseYear,
                 double rating);

void initBook(Book *b,
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
 * Returns a human-readable representation of the given Book
 */
char *bookToString(const Book *b);

Book *loadFromCsvFile(const char *fileName, int *numBooks);

Book *getBestBook(const Book *library, int numBooks);

Book *getWorstBook(const Book *library, int numBooks);

Book *getBooksByAuthor(const Book *library, int numBooks, Author a, int *numAuthorBooks);

/**
 * Returns an integer:
 *  something negative if a comes before b with respect to last name/first name
 *  zero if the authors have the same name
 *  something positive if b comes before a
 *
 */
int compareAuthor(const Author *a, const Author *b);