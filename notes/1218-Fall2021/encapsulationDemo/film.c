#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "film.h"

void initFilm(Film *f, const char *eidr, const char *title, Person director, double imdbRating) {
  f->eidr = strdup(eidr);
  f->title = strdup(title);
  f->imdbRating = imdbRating;
  f->director = director;
}

Film *createFilm(const char *eidr, const char *title, Person director, double imdbRating) {

  Film *f = (Film *) malloc(1 * sizeof(Film));
  initFilm(f, eidr, title, director, imdbRating);
  return f;
}

char *filmToString(const Film *f) {
    char s[1000];
    sprintf(s, "%s directed by %s, %s (%.2f)\n",
      f->title,
      f->director.lastName,
      f->director.firstName,
      f->imdbRating);
    char *result = strdup(s);
    return result;
}

void printFilm(const Film *f) {
    char *s = filmToString(f);
    printf("%s", s);
    free(s);
    return;
}

void printFilms(const Film *films, int n) {

  for(int i=0; i<n; i++) {
    printFilm(&films[i]);
  }

}

void printFilmsV2(Film **films, int n) {

  for(int i=0; i<n; i++) {
    printFilm(films[i]);
  }

}