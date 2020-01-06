/* 
============================================================================+
Name        : Student.cpp
Author      : Riya Danait
Date        : 3/5/2018
Description : This class represents the basic entities of students, containing 
              accessor and mutator methods to obtain student data. 

============================================================================+
*/
#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(string studentID, string firstname, string lastname, Classification cls)
{
    ID = studentID;
    firstName = firstname;
    lastName = lastname;
    c = cls;
    enrolledCourseCount = 0;
}

Student::~Student()
{
    
}
//This function returns the first name of a student
string Student::getFirstName()
{
    return (firstName);
}
//This function returns the last name of a student
string Student::getLastName()
{
    return (lastName);
}
//This function returns the number of courses the student is enrolled in
int Student::getEnrolledCourseCount()
{
    return (enrolledCourseCount);
}

//This function sets the number of courses the student is enrolled in
void Student::setEnrolledCourseCount(int count)
{
    enrolledCourseCount = count;
}
//This function takes in the enumuerated type Classification and converts it
//to the string value
string Student::classificationToString(Classification c)
{
    switch(c)
    {
        case Freshman:
            return "Freshman";
            
        case Sophomore:
            return "Sophomore";
            
        case Junior:
            return "Junior";
            
        case Senior:
            return "Senior";
            
        case Unknown:
            return "Unknown";
            
        default:
            return "Unknown";
    }
    return "Unknown";
    
}
//This function sets the first and last name for the student
void Student::setStudentName(string first, string last)
{
    firstName = first;
    lastName = last;
}
//This function returns the student ID
string Student::getStudentID()
{
    return (ID);
}
//This function sets the student ID
void Student::setStudentID(string id)
{
    ID = id;
}
//This function gets the student Classification
Classification Student::getStudentClassification()
{
    return(c);
}
//This function gets the student Classification as a string
string Student::getStudentClassificationStr()
{
    return(classificationToString(c));
}
//This function sets the student Classification
void Student::setStudentClassification(Classification cls)
{
    c = cls;
}
