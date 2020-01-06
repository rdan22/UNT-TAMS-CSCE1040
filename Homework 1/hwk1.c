/* 
============================================================================
Name        : hwk1.cpp
Class       : CSCE 1040
Author      : Riya Danait (RiyaDanait@my.unt.edu)
Instructor  : Professor Keathly
Date        : 2/4/18
Description : The program uses redirection to read in from a student grade 
			  data file into two data structures, perform some calculations, 
			  sort the students in ascending order by average, determine 
			  some class statistics, and output the results. 
			  Example: 
			  To compile: g++ hwk1.cpp bubble.cpp
			  To run: ./a.out < grades
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "bubble.h"
//defining the struct classStats
struct classStats{

	float mean;
	float min;
	float max;
	float median;
	char *name;

};

int main()
{
	//defining the necessary variables
	struct classStats ClassStats;
	float total = 0.0;
	//malloc for the name
	ClassStats.name = (char *)malloc(sizeof(char) * 30);
	//scanning in the class name 
	scanf("%s", ClassStats.name);

	student **students;

	// First allocate an array of 19 'student' pointers
	students = (student **)malloc(sizeof(student *)*19);


	for(int i = 0; i < 19; i++)
	{
		// For each of the 19 pointers, allocate memory for the student structure.
		students[i] = (student *)malloc(sizeof(student));

		// Allocate memory for each student's first and last names
		students[i]->first = (char *)malloc(sizeof(char)*30);
		students[i]->last = (char *)malloc(sizeof(char)*30);

		// Read in student details from standard input using scanf
		scanf("%s %s %d %d %d", students[i]->first, students[i]->last, &students[i]->exam1, &students[i]->exam2, &students[i]->exam3);

		// Compute the mean of each students exam1, exam2 and exam3 grades, assuming equal weightage. Store the result for each student.
		students[i]->mean = (students[i]->exam1 + students[i]->exam2 + students[i]->exam3)/3.0;

	}
	//calling the bubble function
	bubble(students, 19);

	for(int i = 0; i < 19; i++)
	{
		//summing all the means 
		total = total + students[i]->mean;
	}
	//calculating the mean, min, max, median of the class data and store them in ClassStats
	ClassStats.mean = total / 19.0;
	ClassStats.min  = students[0]->mean;
	ClassStats.max  = students[18]->mean;
	ClassStats.median = students[9]->mean;


	//outputting the data
	printf("123456789012345678901234567890123456789012345678901234567890\n");
	printf("%s MEAN:  %.2f MIN:  %.2f MAX:  %.2f MEDIAN:  %.2f\n", ClassStats.name, ClassStats.mean, ClassStats.min, ClassStats.max, ClassStats.median);
	
	for(int i = 0; i < 19; i++)
	{
		printf("%12s %11s  %2.2f\n", students[i]->first, students[i]->last, students[i]->mean);
	}

	// Free dynamically allocated memory

	for (int i= 0; i < 19; i++)
	{

		// Free the pointers for student first and last names
		free(students[i]->first);
		free(students[i]->last);

		// Free each student structure
		free(students[i]);
	}
	// Free the array of student pointers
	free (students);

  return 0;
}