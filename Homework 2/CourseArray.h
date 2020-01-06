/* 
============================================================================
Name        : CourseArray.h
Author      : Riya Danait
Date        : 3/5/2018
Description : This is the header file for the CourseArray function that 
              contains the definitions for the functions and variables. 
============================================================================
*/
#include "Course.h"
#include <string>

class CourseArray{
    
private:
    //Private data members and function
    Course** courses;
    int courseCount;
    static const int initialCapacity = 100;
    int currentCourseCapacity;
    void growCourseArray();
    
public:
    //constructor and destructor
    ~CourseArray();
    CourseArray();
    //Public member functions
    //save and load from a file
    void saveToFile(ofstream& gradebookStream);
    void loadFromFile(ifstream& gradebookStream);
    //add a course, print a course, find a course
    void addACourse(Course* course);
    void printAllCourses();
    Course* findCourse(string courseID);
    
    
};
