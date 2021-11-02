#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "film.h"

int main(int argc, char **argv) {

  Date d = {1967, 10, 3 };
  Person denis = {
      "Denis",
      "Villenueve",
      {
          1967, 10, 3
      }
  };

  Film *arr = (Film *) malloc(sizeof(Film) * 3);
  initFilm(&arr[0], "1234", "Arrival", denis, 8.5);
  initFilm(&arr[1], "10.5240/D15F-5FCE-B8D0-FA2B-EF6A-D", "Dune", denis, 9.0);
  initFilm(&arr[2], "5678", "Blade Runner 2049", denis, 9.9);

  printFilms(arr, 3);

  Film **films = (Film **) malloc(sizeof(Film *) * 3);

  Film *arrival = createFilm("1234", "Arrival", denis, 8.5);
  Film *dune = createFilm("10.5240/D15F-5FCE-B8D0-FA2B-EF6A-D", "Dune", denis, 9.0);
  Film *bladeRunner = createFilm("5678", "Blade Runner 2049", denis, 9.9);

  films[0] = arrival;
  films[1] = dune;
  films[2] = bladeRunner;

  printFilmsV2(films, 3);


  //TODO: free properly
  // free(dune);
  // free(bladeRunner);



}
