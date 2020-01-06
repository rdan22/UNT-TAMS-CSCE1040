/* 
============================================================================
Name        : Student.h
Author      : Riya Danait
Date        : 3/5/2018
Description : This is the Student header file that contain function and 
              variable definitions. 
============================================================================
*/
#include <string>

using namespace std;
//enum classificaition
//1 = freshman, 2 = sophomore, 3 = junior 4 = senior, 5 = unknown
enum Classification {Freshman = 1, Sophomore, Junior, Senior, Unknown};

class Student
{
private:
    //private data members and function
    string ID;
    string firstName;
    string lastName;
    Classification c;
    int enrolledCourseCount;
    string classificationToString(Classification c);
    
public:
    //static constant integer for the max number of courses a student can be enrolled in
    static const int maxEnrollCourseCount = 5;
    //constructor and destructor
    Student(string ID, string firstName, string lastName, Classification c);
    ~Student();
    //gets first and last name
    string getFirstName();
    string getLastName();
    //gets the number of courses the student is enrolled in
    int    getEnrolledCourseCount();
    //sets the number of courses the student is enrolled in
    void   setEnrolledCourseCount(int count);
    //sets the student name
    void setStudentName(string first, string last);
    // gets the ID
    string getStudentID();
    //sets the student ID
    void setStudentID(string id);
    //gets the student Classification 
    Classification getStudentClassification();
    string getStudentClassificationStr();
    //sets the student Classification
    void setStudentClassification(Classification c);
};
