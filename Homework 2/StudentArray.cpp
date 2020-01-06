/* 
============================================================================
Name        : StudentArray.cpp
Author      : Riya Danait
Date        : 3/5/2018
Description : This class represents the collection of dynamically allocated 
              student pointers. Functions such as adding students, finding 
              students, printing a list of all students, and printing student 
              details given a list of ID’s are contained here.
============================================================================
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include "StudentArray.h"

StudentArray::StudentArray()
{
    students = new Student*[initialCapacity];
    currentStudentCapacity = initialCapacity;
    studentCount = 0;
    
}

StudentArray::~StudentArray()
{
    for(int i = 0; i < studentCount; i++)
    {
        delete students[i];
    }
    delete [] students;
}
//This function adds a student to the array
void StudentArray::addAStudent(Student* student)
{
    if(studentCount == currentStudentCapacity)
    {
        //calls the grow student array function
        growStudentArray();
    }
    students[studentCount] = student;
    studentCount++;
}
//this function prints all the students
void StudentArray::printAllStudents()
{
    cout << setfill('-') << setw(65) << "-" << endl;
    cout << setfill(' ') << setw(15) << left << "Student ID";
    cout << setw(30) << left << "Student Name";
    cout << setw(20) << left << "Classification" << endl;
    cout << setfill('-') << setw(65) << "-" << endl;
    for(int i = 0; i < studentCount; i++)
    {
        cout << setfill(' ') << setw(15) << students[i]->getStudentID();
        cout << setw(30) << (students[i]->getFirstName() + ' ' + students[i]->getLastName());
        cout << setw(20) << students[i]->getStudentClassificationStr() << endl;
    }
}
//This function converts the enumerated type Classification to a string 
string StudentArray::classificationToString(Classification c)
{
    switch(c)
    {
        case 1:
            return "Freshman";
            
        case 2:
            return "Sophomore";
            
        case 3:
            return "Junior";
            
        case 4:
            return "Senior";
            
        default:
            return "unknown";
    }
    return "unknown";
    
}
//This converts the integer to the string classification
Classification StudentArray::intToClassification(int c)
{
    switch(c)
    {
        case 1:
            return Freshman;
            
        case 2:
            return Sophomore;
            
        case 3:
            return Junior;
            
        case 4:
            return Senior;
            
        default:
            return Unknown;
    }
    return Unknown;
    
}
/*This function grows the student array. It sets the current student capacity to the sum
of the initial student capacity and the current student capacity. Then it allocates a new
array of student pointers, a temporary array to populate the pointers into, and
deletes the old array.*/
void StudentArray::growStudentArray()
{
    currentStudentCapacity = currentStudentCapacity + initialCapacity;
    Student** tempArray = new Student*[currentStudentCapacity];
    
    for (int i = 0; i < studentCount; i++)
    {
        tempArray[i] = students[i];
        students[i] = NULL;
    }
    
    delete [] students;
    
    students = tempArray;
    
}
//This function find a student given the student ID
Student* StudentArray::findStudent(string studentID)
{
    for(int i = 0; i < studentCount; i++)
    {
        //as long as the student ID given matches that in the student array
        if(students[i]->getStudentID().compare(studentID) == 0)
        {
            return students[i];
        }
    }
    return NULL;
}
//This function prints all of the student in a course 
void StudentArray::printStudentsInCourse(string** studentIDs, int studentCount)
{
    Student* student;
    
    if (studentCount > 0)
    {
        cout << setfill('-') << setw(65) << "-" << endl;
        cout << setfill(' ') << setw(15) << left << "Student ID";
        cout << setw(30) << left << "Student Name";
        cout << setw(20) << left << "Classification" << endl;
        cout << setfill('-') << setw(65) << "-" << endl;
        
        for(int i = 0; i < studentCount; i++)
        {
            if(studentIDs[i] != NULL)
            {
                // For each of the given Student IDs, find and print the Student details.
                student = findStudent(*(studentIDs[i]));
                cout << setfill(' ') << setw(15) << students[i]->getStudentID();
                cout << setw(30) << (students[i]->getFirstName() + ' ' + students[i]->getLastName());
                cout << setw(20) << students[i]->getStudentClassificationStr() << endl;
                delete studentIDs[i]; // Release the dyanmic memory associated with the studentID
            }
        }
    }
    delete [] studentIDs; // Release the dynamic memory associated with the studentID array
}
//This function saves the student array data to a file
void StudentArray::saveToFile(ofstream& gradebookStream)
{
    gradebookStream << studentCount << endl;
    for(int i = 0; i < studentCount; i++)
    {
        gradebookStream << students[i]->getStudentID() << ',' << students[i]->getFirstName()
        << ',' << students[i]->getLastName() << ',' << students[i]->getStudentClassification() <<
        ',' << students[i]->getEnrolledCourseCount() << endl;
    }
}
//this function loads the student array data from a file
void StudentArray::loadFromFile(ifstream& gradebookStream)
{
    string studentID;
    string firstName;
    string lastName;
    int c;
    int numCoursesEnrolled = 0;
    //need a temporary student count to go through the file
    int tempStudentCount = 0;
    gradebookStream >> tempStudentCount;
    gradebookStream.get();
    for(int i = 0; i < tempStudentCount; i++)
    {
        getline(gradebookStream, studentID, ',');
        getline(gradebookStream, firstName, ',');
        getline(gradebookStream, lastName, ',');
        gradebookStream >> c;
        gradebookStream.get(); // eat the comma after classification value
        gradebookStream >> numCoursesEnrolled;
        gradebookStream.get();//Eat the newline at the end of each row
        Student *student = new Student(studentID, firstName, lastName, intToClassification(c));
        student->setEnrolledCourseCount(numCoursesEnrolled);
        addAStudent(student);
    }
}

