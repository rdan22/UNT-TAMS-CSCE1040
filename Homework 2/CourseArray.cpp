/* 
============================================================================
Name        : CourseArray.cpp
Author      : Riya Danait
Date        : 3/5/2018
Description : This class represents the collection of dynamically allocated 
              course pointers. Functions such as adding courses, finding 
              courses, and printing a list of all courses are contained here.
============================================================================
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include "CourseArray.h"


CourseArray::CourseArray()
{
    courses = new Course*[initialCapacity];
    currentCourseCapacity = initialCapacity;
    courseCount = 0;
    
}

CourseArray::~CourseArray()
{
    for(int i = 0; i < courseCount; i++)
    {
        delete courses[i];
    }
    delete [] courses;
}
/*This function adds a course by calling the grow course array function.
It first checks if the number of courses equals the course capacity of the
array, and if it does, calls the function.*/
void CourseArray::addACourse(Course* course)
{
    if(courseCount == currentCourseCapacity)
    {
        //calling the grow course array function
        growCourseArray();
    }
    courses[courseCount] = course;
    courseCount++;
}
/*This function prints all courses.*/
void CourseArray::printAllCourses()
{
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << setfill(' ') << setw(15) << left << "Course ID";
    cout << setw(25) << left << "Course Name";
    cout << setw(20) << left << "Location";
    cout << setw(20) << left << "Meeting Time" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    for(int i = 0; i < courseCount; i++)
    {
        cout << setfill(' ') << setw(15) << left << courses[i]->getCourseID();
        cout << setw(25) << left << courses[i]->getCourseName();
        cout << setw(20) <<  courses[i]->getLocation();
        cout << setw(20) <<  courses[i]->getMeetingTime() << endl;
    }
}
/*This function grows the course array. It sets the current course capacity to the sum
of the initial course capacity and the current course capacity. Then it allocates a new
array of course pointers, a temporary array to populate the pointers into, and
deletes the old array. */
void CourseArray::growCourseArray()
{
    currentCourseCapacity = currentCourseCapacity + initialCapacity;
    Course** tempArray = new Course*[currentCourseCapacity];
    
    for (int i = 0; i < courseCount; i++)
    {
        tempArray[i] = courses[i];
        courses[i] = NULL;
    }
    
    delete [] courses;
    
    courses = tempArray;
    
}
//This function finds a course given the course ID
//It basically checks to see if the course ID the user inputted
//matches a course ID in the array. 
Course* CourseArray::findCourse(string courseID)
{
    for(int i = 0; i < courseCount; i++)
    {
        if(courses[i]->getCourseID().compare(courseID) == 0)
        {
            return courses[i];
        }
    }
    return NULL;
}
//This function saves the course array to a file. 
void CourseArray::saveToFile(ofstream& gradebookStream)
{
    gradebookStream << courseCount << endl;
    for(int i = 0; i < courseCount; i++)
    {
        gradebookStream << courses[i]->getCourseID() << ',' << courses[i]->getCourseName() << ','
        << courses[i]->getLocation() << ',' << courses[i]->getMeetingTime() << ','
        << courses[i]->getEnrolledStudentCount() << endl;
    }

}
//This function loads the course array from a file. 
void CourseArray::loadFromFile(ifstream& gradebookStream)
{
    string courseID;
    string courseName;
    string location;
    string meetingTime;
    //need a temporary course count to go through the file
    int tempCourseCount = 0;
    int enrolledCount = 0;
    
    gradebookStream >> tempCourseCount;
    gradebookStream.get();
    for(int i = 0; i < tempCourseCount; i++)
    {
        getline(gradebookStream, courseID, ',');
        getline(gradebookStream, courseName, ',');
        getline(gradebookStream, location, ',');
        getline(gradebookStream, meetingTime, ',');
        gradebookStream >> enrolledCount;
        gradebookStream.get(); // eat the newline at the end;
        
        Course* course = new Course(courseID, courseName, location, meetingTime);
        course->setEnrolledStudentCount(enrolledCount);
        addACourse(course);
    }
    
}

