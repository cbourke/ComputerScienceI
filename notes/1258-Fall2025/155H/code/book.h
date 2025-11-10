
typedef struct {

    int year;
    int month;
    int day;

} Date;

typedef struct {
    char *lastName;
    char *firstName;
    Date dateOfBirth;

} Person;

typedef struct {

    int id;
    char *title;
    Person author;
    char *isbn;
    double rating;
    char *publisher;
    int year;
    Date dateRead;

} Book;

/**
 * Initializes the given book with the given values, returns a non-zero
 * error code for any errors.
 */
int initBook(Book *b,
             int id,
             const char *title,
             const char *lastName,
             const char *firstName,
             const char *isbn,
             double rating,
             const char *publisher,
             int publishYear,
             const char *dateRead);
/**
 * TODO: document
 */
char *bookToString(const Book *b);

//TODO:
void freeBook(Book *b);

//TODO:
Book *createBook(int id,
             const char *title,
             const char *lastName,
             const char *firstName,
             const char *isbn,
             double rating,
             const char *publisher,
             int publishYear,
             const char *dateRead);
