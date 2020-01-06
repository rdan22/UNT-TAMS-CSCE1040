/* 
============================================================================
Name        : EnrollmentArray.cpp
Author      : Riya Danait
Date        : 3/5/2018
Description : This class represents the collection of dynamically allocated 
              enrollment pointers. Functions such as adding enrollments, 
              finding enrollments, printing a list of all students enrolled 
              in a course, and calculating average course grade are 
              contained here.
============================================================================
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include "EnrollmentArray.h"


EnrollmentArray::EnrollmentArray()
{
    // Allocating a dynamic array of enrollment pointers to store student enrollments.
    enrollments = new Enrollment*[initialCapacity];
    currentEnrollmentCapacity = initialCapacity;
    enrollmentCount = 0;
    
}

EnrollmentArray::~EnrollmentArray()
{
    
    // Clean up all enrollments as well as the dynamic array.
    for(int i = 0; i < enrollmentCount; i++)
    {
        delete enrollments[i];
    }
    delete [] enrollments;
    
}
//This function enrolls a student to a course
bool EnrollmentArray::enrollAStudent(string studentID, string courseID)
{
    bool found = false;
    //for each enrollment
    for(int i = 0; i < enrollmentCount; i++)
    {
        //as long as the student ID the user gives matches the student ID that exists
        //and as long as the course ID the user gives matches the course ID that exists
        if((enrollments[i]->getStudentID().compare(studentID) == 0) && (enrollments[i]->getCourseID().compare(courseID) == 0))
        {
            //found is true and the enrollment already exists
            found = true;
            break;
        }
    }
    //if true
    if(!found)
    {
        //allocates a new enrollment pointer with the student ID and course ID the user gave
        Enrollment* enrollment = new Enrollment(studentID, courseID);
        if(enrollmentCount == currentEnrollmentCapacity)
        {
            //calls the function grow enrollment array
            growEnrollmentArray();
        }
        enrollments[enrollmentCount] = enrollment;
        //calls the set enrollment ID function as well
        enrollment->setEnrollmentID(enrollmentCount);
        enrollmentCount++;
        //returns true (that the student ID course ID enrollment does not already exist)
        return true;
    }
    
    return false;	// Student is already enrolled in the course
}
//This function finds the enrollment given the student ID and course ID
Enrollment* EnrollmentArray::findEnrollment(string studentID, string courseID)
{
    //for each enrollment
    for(int i = 0; i < enrollmentCount; i++)
    {
        //as long as the student ID the user gives matches the student ID that exists
        //and as long as the course ID the user gives matches the course ID that exists
        if((enrollments[i]->getStudentID().compare(studentID) == 0) && (enrollments[i]->getCourseID().compare(courseID) == 0))
        {
            //returns the enrollments array
            return enrollments[i];
        }
    }
    return NULL;
}

// Given a Course ID, find all Student IDs that are enrolled in that course.
string** EnrollmentArray::getAllStudentsInACourse(string courseID, int& studentCount)
{
    int j = 0;
    
    // Allocate a dynamic array to store Student ID strings
    string** studentIDs = new string*[maxStudentsPerCourse];
    
    
    for(int i = 0; i < enrollmentCount; i++)
    {
        // Loop through the Enrollment Array, finding all enrollments that match the given Course ID
        if(enrollments[i]->getCourseID().compare(courseID) == 0)
        {
            // If the Enrollment course ID matches, allocate a string for storing the corresponding studentID
            // associated with that enrollment. Then save the student ID pointer in the dynamic array.
            studentIDs[j] = new string(enrollments[i]->getStudentID());
            j++;
        }
    }
    
    // Return the count of students enrolled in the course, along with their IDs stored in the dynamic array
    studentCount = j;
    return studentIDs;
}
//This function calculates the average course grade
float EnrollmentArray::averageCourseGrade(string courseID)
{
    float sum = 0.0;
    int studentCount = 0;
    float averageCourseGrade = 0.0;
    //for each enrollment
    for(int i = 0; i < enrollmentCount; i++)
    {
        if(enrollments[i]->getCourseID().compare(courseID) == 0)
        {
            //adds the average grade for each student to the sum
            sum = sum + enrollments[i]->averageGradeForAStudent();
            //increments student count
            studentCount++;
        }
    }
    averageCourseGrade = sum/studentCount;
    //returns the average course grade
    return averageCourseGrade;
}
/*This function grows the enrollment array. It sets the current enrollment capacity to the sum
of the initial enrollment capacity and the current enrollment capacity. Then it allocates a new
array of enrollment pointers, a temporary array to populate the pointers into, and
deletes the old array.*/
void EnrollmentArray::growEnrollmentArray()
{
    currentEnrollmentCapacity = currentEnrollmentCapacity + initialCapacity;
    Enrollment** tempArray = new Enrollment*[currentEnrollmentCapacity];
    
    for (int i = 0; i < enrollmentCount; i++)
    {
        tempArray[i] = enrollments[i];
        enrollments[i] = NULL;
    }
    
    delete [] enrollments;
    
    enrollments = tempArray;
    
}
//This function loads enrollments from a file
void EnrollmentArray::loadFromFile(ifstream& gradebookStream)
{
    int enrollmentID;
    string studentID;
    string courseID;
    float averageGrade;
    //need a temporary enrollment count to go through the file 
    int tempEnrollmentCount = 0;
    int tempGradeCount = 0;
    gradebookStream >> tempEnrollmentCount;
    gradebookStream.get();
    
    for(int i = 0; i < tempEnrollmentCount; i++)
    {
        //gets the enrollment id, student id, and course id as well as the average grade
        gradebookStream >> enrollmentID;
        gradebookStream.get();
        getline(gradebookStream, studentID, ',');
        getline(gradebookStream, courseID, ',');
        gradebookStream >> setprecision(2) >> averageGrade;
        gradebookStream.get();
        Enrollment *enrollment = new Enrollment(enrollmentID, studentID, courseID, averageGrade);
        gradebookStream >> tempGradeCount;
        gradebookStream.get();
        //cout << "Enrollment ID=" << enrollmentID << " StudentID=" << studentID << " courseID=" << courseID << " averageGrade =" << setprecision(2) << fixed << averageGrade << " gradeCount = " << tempGradeCount << endl;
        
        //cout << "Allocated enrollment for student ID " << studentID << endl;
        
        
        //based on the temporary grade count
        for (int j=0; j < tempGradeCount; j++)
        {
            //gets each grade
            int grade;
            gradebookStream >> grade;
            gradebookStream.get();
            enrollment->setGrade(grade);
        }
        addAnEnrollment(enrollment);
    }
}
//This function saves the enrollments to a file. 
void EnrollmentArray::saveToFile(ofstream& gradebookStream)
{
    gradebookStream << enrollmentCount << endl;
    for(int i = 0; i < enrollmentCount; i++)
    {
        //saves the enrollment id, student id, course id, and average grade to a file
        gradebookStream << enrollments[i]->getEnrollmentID() << "," << enrollments[i]->getStudentID()
        << "," << enrollments[i]->getCourseID() << "," << setprecision(2) << fixed << enrollments[i]->averageGradeForAStudent();
        //calls the save all grades function to save the grades as well
        enrollments[i]->saveAllGrades(gradebookStream);
    }
}
//This function adds an enrollment
void EnrollmentArray::addAnEnrollment(Enrollment *enrollment)
{
    if(enrollmentCount == currentEnrollmentCapacity)
    {
        //calls the grow enrollment array
        growEnrollmentArray();
    }
    enrollments[enrollmentCount] = enrollment;
    //also sets an enrollment ID
    enrollment->setEnrollmentID(enrollmentCount);
    enrollmentCount++;
}

