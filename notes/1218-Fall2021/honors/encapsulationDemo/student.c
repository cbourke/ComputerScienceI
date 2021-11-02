#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "student.h"

Student *constructStudent(int nuid,
                          const char *firstName,
                          const char *lastName,
                          Year year,
                          double gpa,
                          Date dateOfBirth) {

  Student *s;

  s = (Student *) malloc(1 * sizeof(Student));

  initStudent(s, nuid, firstName, lastName, year, gpa, dateOfBirth);

  return s;
}

void initStudent(Student *s, int nuid,
                          const char *firstName,
                          const char *lastName,
                          Year year,
                          double gpa,
                          Date dateOfBirth) {
  s->nuid = nuid;

  s->firstName = strdup(firstName);
  s->lastName = strdup(lastName);

  s->year = year;
  s->gpa = gpa;
  s->dateOfBirth = dateOfBirth;

  return;
}

void printRoster(Student **r, int n) {

  for(int i=0; i<n; i++) {
      printStudent(r[i]);
  }

}


void printStudent(const Student *s) {

  char *str = studentToString(s);
  printf("%s", str);
  free(str);
}

char *studentToString(const Student *s) {

  char str[1000];
  sprintf(str, "%s, %s (%08d)\n", s->lastName, s->firstName, s->nuid);
  return strdup(str);
}
