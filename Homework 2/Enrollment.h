/* 
============================================================================
Name        : Enrollment.h
Author      : Riya Danait
Date        : 3/5/2018
Description : This is the Enrollment header file that contains all of the
              definitions for the functions and variables. 
============================================================================
*/
#include <string>
#include <iomanip>
using namespace std;

class Enrollment
{
    
private:
    
    //private data members
    string studentID;
    string courseID;
    int enrollmentID;
    int grades[10];
    int gradeCount;
    float averageGrade;
    char letterGrade;
    
    
public:
    //static constant for the max number of grades a student can have in a course
    static const int maxGradeCount = 10;
    //Constructors and destructor
    Enrollment(string stID, string cID);
    Enrollment(int enrollID, string stID, string cID, float avgGrade);
    ~Enrollment();
    //Printing, calculating average, and saving grades 
    void saveAllGrades(ofstream& gradebookStream);
    float averageGradeForAStudent();
    char letterGradeForAStudent();
    void printAllGradesForAStudentInACourse();
    //Accessors and mutators for the grades, enrollment id, student id, and course id
    int setGrade(int grade);
    int getEnrollmentID();
    void setEnrollmentID(int enrollID);
    string getStudentID();
    void setStudentID();
    string getCourseID();
    void setCourseID();
    
    
    
};
