#include <stdlib.h>
#include <stdio.h>

#include "airport.h"

void generateReports(Airport *airports, int n) {

  printf("Airports (original): \n");
  printf("==============================\n");
  printAirports(airports, n);

  printf("\nAirports By GPS ID: \n");
  printf("==============================\n");

  printf("\nAirports By Type: \n");
  printf("==============================\n");

  printf("\nAirports By Name: \n");
  printf("==============================\n");

  printf("\nAirports By Name - Reversed: \n");
  printf("==============================\n");

  printf("\nAirports By Country/City: \n");
  printf("==============================\n");

  printf("\nAirports By Latitude: \n");
  printf("==============================\n");

  printf("\nAirports By Longitude: \n");
  printf("==============================\n");

  printf("\nAirports By Distance from Lincoln: \n");
  printf("==============================\n");

  printf("\nClosest Airport to Lincoln: \n");
  printf("==============================\n");

  printf("\nFurthest Airport from Lincoln: \n");
  printf("==============================\n");

  printf("\nEast-West Geographic Center: \n");
  printf("==============================\n");

  printf("\nNew York, NY airport: \n");
  printf("==============================\n");
  //if none found, print: "No New York airport found!\n"

  printf("\nLarge airport: \n");
  printf("==============================\n");
  //if none found, print: "No large airport found!\n"


  return;
}
