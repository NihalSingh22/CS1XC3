/**
 * @file course.c
 * @author Nihal Singh
 * @brief 
 * The c file presented to us provides functions 
 * to enroll students into courses , printing the students of the
 * pertaining courses , and the also displayinf the student with the highest average.
 * we also display a list of students passing the course 
 * 
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "course.h"
#include <stdlib.h>
#include <stdio.h>
 

/**
 * @brief  Enrolls students into courses 
 * 
 * @param course the course that student wants to enroll in 
 * @param student student that is being enrolled 
 */

void enroll_student(Course *course, Student *student)
{ 
  // it increases the student array size 
  course->total_students++;
  if (course->total_students == 1) 
  {
    // allocating the memory and returns a pointer to it
    course->students = calloc(1, sizeof(Student));
  }
  else 
  {
    // resizing the memory block which was allocated by calloc beforehand 
    course->students = 
      realloc(course->students, course->total_students * sizeof(Student)); 
  }
  // the new index is set as the inputted student 
  course->students[course->total_students - 1] = *student;
}

/**
 * @brief prints the name , code and total students in a certain course
 * 
 * @param course the course that student wants to enroll in
 */

void print_course(Course* course)
{
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");
  for (int i = 0; i < course->total_students; i++) 
    // prints all the information of the students
    print_student(&course->students[i]);
}


/**
 * @brief Returns the student with the highest grade 
 * 
 * @param course the course that student wants to enroll in
 * @return Student* a struct 
 */
Student* top_student(Course* course)
{
  if (course->total_students == 0) return NULL;
 
  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];

  // this loop helps us find the student with the highest average and returns it 
  for (int i = 1; i < course->total_students; i++)
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average) 
    {
      max_average = student_average;
      student = &course->students[i];
    }   
  }

  return student;
}

/**
 * @brief 
 * 
 * @param course the course that student wants to enroll in
 * @param total_passing keeps a count of students passing the course ( integer )
 * @return Student* a struct 
 */

Student *passing(Course* course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL;
  
  // checks if students are passing , and the gets the count of it 
  for (int i = 0; i < course->total_students; i++) 
    if (average(&course->students[i]) >= 50) count++;
  
  // allocates an array for a certain amount of students 
  passing = calloc(count, sizeof(Student));

  int j = 0;
  for (int i = 0; i < course->total_students; i++)
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      j++; 
    }
  }

  // updates the array address 
  *total_passing = count;
  // finally returning the array for all the passed students 
  return passing;
}