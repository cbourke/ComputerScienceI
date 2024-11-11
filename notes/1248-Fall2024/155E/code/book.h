//TODO: documentation

typedef struct {
  int year;
  int month;
  int day;
} Date;

typedef struct {
  char *firstName;
  char *lastName;
  Date birthDate;
} Person;

typedef struct {
  char *isbn;
  char *title;
  double rating;
  Person author;
  Date publishDate;
} Book;

/**
 * TODO: documentation
 */
char *deepStrCopy(const char *s);

/**
 * Creates a new book instance (on the heap) and returns it with the given
 * data.
 */
Book *createBook(const char *isbn,
                 const char *title,
                 const char *authorFirstName,
                 const char *authorLastName);

/**
 * Initializes the given book with the given data.
 */
void initBook(Book *b,
              const char *isbn,
              const char *title,
              double rating,
              const char *authorFirstName,
              const char *authorLastName,
              int publishYear);

/**
 * Prints the given Book instance to the standard output
 */
void printBook(const Book *b);

/**
 * Returns a formatted string representation of the given Book instance
 */
char *bookToString(const Book *b);

/**
 * Frees up the given book along with all of its data
 */
void freeBook(Book *b);

/**
 * Loads book data from the given file and returns an array of
 * Book instances.  Also sets n to the size of the resulting array.
 */
Book *loadBookData(const char *fileName, int *n);
