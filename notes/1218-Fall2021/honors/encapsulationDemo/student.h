
typedef enum {
  FRESHMAN,
  SOPHOMORE,
  JUNIOR,
  SENIOR
} Year;

typedef struct {
  int year;
  int month;
  int day;
} Date;

typedef struct {
  int nuid;
  char *firstName;
  char *lastName;
  Year year;
  double gpa;
  Date dateOfBirth;
} Student;

Student *constructStudent(int nuid,
                          const char *firstName,
                          const char *lastName,
                          Year year,
                          double gpa,
                          Date dateOfBirth);

void initStudent(Student *s, int nuid,
                          const char *firstName,
                          const char *lastName,
                          Year year,
                          double gpa,
                          Date dateOfBirth);

void printStudent(const Student *s);
void printRoster(Student **s, int n);

char *studentToString(const Student *s);