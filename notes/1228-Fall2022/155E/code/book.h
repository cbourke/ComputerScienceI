
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
 * This is a factory function that creates a new instance of a Book
 * structure.
 */
Book *createBook(const char *title,
                 const char *authorFirstName,
                 const char *authorLastName,
                 int releaseYear,
                 double rating);

/**
 * Initializes an existing Book structure's variables
 */
void initBook(Book *b,
              const char *title,
              const char *authorFirstName,
              const char *authorLastName,
              int releaseYear,
              double rating);


/**
 * Creates a deep copy of the given string and returns a pointer
 * to it.
 */
char *deepStringCopy(const char *s);

/**
 * Prints the given instance of a Book to the standard output
 */
void printBook(const Book *b);

/**
 * Returns a tabular/human readable format of the given book as
 * a string
 */
char *bookToString(const Book *b);

/**
 * Frees all memory associated with the given Book and then
 * frees the Book structure itself
 */
void freeBook(Book *b);

/**
 * Loads Book records/data from the given file...
 */
Book *loadBooks(const char *fileName, int *numBooks);

/**
 * This function finds the best book (with respect to the
 * highest rating) and returns it
 */
Book *getBestBook(const Book *library, int numBooks);

/**
 * This function finds the words book (with respect to the
 * lowest rating) and returns it
 */
Book *getWorstBook(const Book *library, int numBooks);

/**
 * Returns a new array containing all the books by the given
 * author (passed by reference) in the array of Books (library)
 * which is of size numBooks.
 *
 * The size of the resulting array is communicated in the numResultingBooks
 * variable
 */
Book *getBooksByAuthor(const Book *library, int numBooks, const Author *author, int *numResultingBooks);


int authorIsEqual(const Author *a, const Author *b);