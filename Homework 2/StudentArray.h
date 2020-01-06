/* 
============================================================================
Name        : main.cpp
Author      : Riya Danait
Date        : 3/5/2018
Description : This is the StudentArray header file that contains all of the
              variable and function definitions. 
============================================================================
*/
#include "Student.h"


class StudentArray{
    
private:
    //private data members and functions
    Student** students;
    int studentCount;
    int currentStudentCapacity;
    static const int initialCapacity = 100;
    void growStudentArray();
    
public:
    //constructor and destructor
    ~StudentArray();
    StudentArray();
    //add a student
    void addAStudent(Student* student);
    //convert classification value to string
    string classificationToString(Classification c);
    //convert classification value to int
    Classification intToClassification(int c);
    //print all of the students
    void printAllStudents();
    //find the students
    Student* findStudent(string studentID);
    //print the students in a course
    void printStudentsInCourse(string** studentIDs, int studentCount);
    //save and load to file
    void saveToFile(ofstream& gradebookStream);
    void loadFromFile(ifstream& gradebookStream);
    
};
