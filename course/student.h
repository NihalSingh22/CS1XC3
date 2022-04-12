/**
 * @brief a structure student defined which contains firstname , last name  , id
 * grades and number of grades .
 */

typedef struct _student 
{ 
  char first_name[50]; /**<student first name*/
  char last_name[50]; /**<student last name */
  char id[11]; /**<student id */
  double *grades;  /**< list of grades */
  int num_grades; /**< count of student grades */
} Student;

void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student* generate_random_student(int grades); 
