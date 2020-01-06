/* 
============================================================================
Name        : EnrollmentArray.h
Author      : Riya Danait
Date        : 3/5/2018
Description : This is the EnrollmentArray header file that contains all of
              the definitions for the functions and variables used in the 
              .cpp file. 
============================================================================
*/
#include "Enrollment.h"

using namespace std;

class EnrollmentArray
{
private:
    //private data members and function
    Enrollment** enrollments;
    int enrollmentCount;
    int currentEnrollmentCapacity;
    static const int initialCapacity = 100;
    static const int maxStudentsPerCourse = 48;
    float averageGrade;
    void growEnrollmentArray();
    
public:
    //constructor and destructor
    EnrollmentArray();
    ~EnrollmentArray();
    
    // Enroll a student given Student ID and Course ID
    bool enrollAStudent(string studentID, string courseID);
    void addAnEnrollment(Enrollment *enrollment);
    
    // Get a list of all Student IDs enrolled in a given Course ID.
    string** getAllStudentsInACourse(string courseID, int& studentCount);
    
    // Compute the average grade given a Course ID
    float averageCourseGrade(string courseID);
    
    // Find a student's enrollment given their ID and the course ID.
    Enrollment* findEnrollment(string studentID, string courseID);
    
    // Save/Load all enrollments to/from a comma delimited gradebook file.
    void saveToFile(ofstream& gradebookStream);
    void loadFromFile(ifstream& gradebookStream);
    
    
};
