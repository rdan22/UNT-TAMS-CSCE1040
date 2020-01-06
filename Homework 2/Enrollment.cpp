/* 
==================================================================================
Name        : Enrollment.cpp
Author      : Riya Danait
Date        : 3/5/2018
Description : This class represents the basic entities of enrollments, containing 
              accessor and mutator methods to obtain enrollment data. 

==================================================================================
*/
#include <iostream>
#include <fstream>
#include "Enrollment.h"

Enrollment::Enrollment(string stID, string cID)
{
    studentID = stID;
    courseID = cID;
    gradeCount = 0;
    averageGrade = 0;
    enrollmentID = 0;
}

Enrollment::Enrollment(int enrollID, string stID, string cID, float avgGrade)
{
    studentID = stID;
    courseID = cID;
    gradeCount = 0;
    averageGrade = avgGrade;
    enrollmentID = enrollID;
}

Enrollment::~Enrollment()
{
    
}
//This function returns the enrollment ID
int Enrollment::getEnrollmentID()
{
    return enrollmentID;
}
//This function sets the enrollment ID
void Enrollment::setEnrollmentID(int enrollID)
{
    enrollmentID = enrollID;
}
//This function calculates the average grade for a student
float Enrollment::averageGradeForAStudent()
{
    float sum = 0.0;
    for(int i = 0; i < gradeCount; i++)
    {
        sum = sum + grades[i];
    }
    averageGrade = sum/gradeCount;
    //returns the average grade
    return averageGrade;
}
//This function prints all grades for a specific student in a course
void Enrollment::printAllGradesForAStudentInACourse()
{
    //calls the average grade for a student function
    cout << setw(8) << setprecision(2) << fixed << averageGradeForAStudent();
    //calls the letter grade for a student function
    cout << setw(4) << letterGradeForAStudent();
    for(int i = 0; i < gradeCount; i++)
    {
        cout << setw(4) << grades[i];
    }
    for(int i = gradeCount; i < maxGradeCount; i++)
    {
        cout << setw(4) << "-";
    }
    cout << endl;
}
//This functions saves all the grades
void Enrollment::saveAllGrades(ofstream& gradebookStream)
{
    gradebookStream << "," << gradeCount;
    for(int i = 0; i < gradeCount; i++)
    {
        gradebookStream <<  "," << grades[i];
    }
    gradebookStream << endl;
}
//This function returns the student ID
string Enrollment::getStudentID()
{
    return (studentID);
}
//This function returns the course ID
string Enrollment::getCourseID()
{
    return (courseID);
}
//This function sets the grade given that the current number of grades
//Is not already the maxGradeCount, which is 10
int Enrollment::setGrade(int grade)
{
    if(gradeCount == maxGradeCount)
    {
        return false;
    }
    else
    {
        grades[gradeCount] = grade;
        gradeCount++;
    }
    return true;
    
}
//This function calculates the letter grade for a student
char Enrollment::letterGradeForAStudent()
{
    char letterGrade;
    averageGradeForAStudent();
    if(averageGrade >= 90)
    {
        letterGrade = 'A';
    }
    else if(averageGrade < 90 && averageGrade >= 80)
    {
        letterGrade = 'B';
    }
    else if(averageGrade < 80 && averageGrade >= 70)
    {
        letterGrade = 'C';
    }
    else if(averageGrade < 70 && averageGrade >= 60)
    {
        letterGrade = 'D';
    }
    else if(averageGrade >= 0 && averageGrade < 60)
    {
        letterGrade = 'F';
    }
    else
    {
        letterGrade = '-';
    }
    return letterGrade;
}
