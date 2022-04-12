/**
 * @file course.h
 * @author Nihal Singh
 * @brief a structure courses defined which contains name , code , students enrolled 
 * and total number of students.
 * 
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "student.h"
#include <stdbool.h>
 
typedef struct _course 
{
  char name[100]; /** < name of course */
  char code[10]; /** < code of course  */
  Student *students; /** < students taking the course  */
  int total_students; /** < count of students taking the course  */
} Course;

void enroll_student(Course *course, Student *student);
void print_course(Course *course);
Student *top_student(Course* course);
Student *passing(Course* course, int *total_passing);


