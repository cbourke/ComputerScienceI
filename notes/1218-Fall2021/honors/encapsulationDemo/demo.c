#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "student.h"


int main(int argc, char **argv) {

  Date d = { 2000, 10, 28 };

  Student *jane = constructStudent(1234, "Jane", "Doe", FRESHMAN, 4.0, d);
  Student *john = constructStudent(4321, "John", "Doe", FRESHMAN, 4.0, d);
  Student *jahm = constructStudent(9876, "Jahm", "Smith", FRESHMAN, 4.0, d);

  // Student *r = (Student *) malloc(sizeof(Student) * 3);
  // r[0] = *jane;
  // r[1] = *john;
  // r[2] = *jahm;

  int n = 3;

  Student **roster = (Student **) malloc( sizeof(Student*) * n );
  roster[0] = jane;
  roster[1] = john;
  roster[2] = jahm;

  printRoster(roster, n);

}
