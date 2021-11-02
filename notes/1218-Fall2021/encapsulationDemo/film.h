
typedef struct {
  int year;
  int month;
  int day;
} Date;

typedef struct {
  char *firstName;
  char *lastName;
  Date dateOfBirth;
} Person;

//model a film
typedef struct {
  char *eidr;
  char *title;
  Person director;
  double imdbRating;
} Film;

Film *createFilm(const char *eidr, const char *title, Person director, double imdbRating);

void initFilm(Film *f, const char *eidr, const char *title, Person director, double imdbRating);

void printFilm(const Film *f);

void printFilms(const Film *films, int n);

void printFilmsV2(Film **films, int n);