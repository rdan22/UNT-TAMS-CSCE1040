/* 
=============================================================================
Name        : Course.cpp
Author      : Riya Danait
Date        : 3/5/2018
Description : This class represents the basic entities of courses, containing 
              accessor and mutator methods to obtain course data. 

=============================================================================
*/
#include <string>
#include <iostream>
#include "Course.h"

using namespace std;

Course::Course(string courseID, string name, string loc, string mtgTime)
{
    ID = courseID;
    courseName = name;
    location = loc;
    meetingTime = mtgTime;
    enrolledStudentCount = 0;
}

Course::~Course()
{
    
}
//This function returns the number of enrolled students
int Course::getEnrolledStudentCount()
{
    return (enrolledStudentCount);
}

//This function sets the number of enrolled students in this course
void Course::setEnrolledStudentCount(int count)
{
    enrolledStudentCount = count;
}

//This function returns the location of a course
string Course::getLocation()
{
    return (location);
}
//This function returns the meeting time of a course
string Course::getMeetingTime()
{
    return (meetingTime);
}
//This function returns the course ID
string Course::getCourseID()
{
    return (ID);
}
//This function returns the course name
string Course::getCourseName()
{
    return (courseName);
}
//This function sets the course ID
void Course::setCourseID(string id)
{
    ID = id;
}
//This function sets the course name
void Course::setCourseName(string nameOfCourse)
{
    courseName = nameOfCourse;
}
//This fucntion sets the course location
void Course::setLocation(string loc)
{
    location = loc;
}
//This function sets the meeting time
void Course::setMeetingTime(string time)
{
    meetingTime = time;
}
