
typedef struct {
  int year;
  int month;
  int day;
} Date;

typedef struct {
  //TODO: think about an ID for a person
  char *lastName;
  char *firstName;
  Date dateOfBirth;
} Person;

typedef struct {
  char *isbn;
  char *title;
  Date publishDate;
  Person author;
} Book;


/**
 * Create a new book instance with the given pieces of data.
 *
 */
Book *createBook(const char *title,
                 const char *authorFirstName,
                 const char *authorLastName,
                 int publishYear);

/**
 * Initializes the (preexisting) book provided with the given data
 */
void initBook(Book *b,
              const char *title,
              const char *authorFirstName,
              const char *authorLastName,
              int publishYear);

/**
 * Returns a string representation of the given book.
 */
char *bookToString(const Book *b);

/**
 * Loads book data from the given file and returns an array
 * of book instances.  Communicates the resulting size of the
 * array through the pass-by-reference variable numBooks.
 */
Book *loadBookData(const char *fileName, int *numBooks);
