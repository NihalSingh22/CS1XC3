/**
 * @file main.c
 * @author Nihal Singh
 * @version 0.1
 * @date 2022-04-11
 * 
 * 
 */


#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"

/**
 * @brief Gives a rundown of other files and libraries
 * 
 * @return int 
 */

int main()
{
  // Initialize number generator by passing the argument seed
  srand((unsigned) time(NULL));

  // Math101 is created 
  Course *MATH101 = calloc(1, sizeof(Course));
  strcpy(MATH101->name, "Basics of Mathematics");
  strcpy(MATH101->code, "MATH 101");


  for (int i = 0; i < 20; i++) 
    enroll_student(MATH101, generate_random_student(8));
  
  print_course(MATH101);

  // gets a print of the top student 
  Student *student;
  student = top_student(MATH101);
  printf("\n\nTop student: \n\n");
  print_student(student);

  // prints all the passing students and the amount that are 
  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing);
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");
  for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]);
  
  return 0;
}