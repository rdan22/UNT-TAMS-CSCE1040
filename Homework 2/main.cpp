/* 
============================================================================
Name        : main.cpp
Author      : Riya Danait
Date        : 3/5/2018
Description : This is the main function that implements the gradebook 
              functionality, including all of the menu choices. 
============================================================================
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "StudentArray.h"
#include "CourseArray.h"
#include "EnrollmentArray.h"

using namespace std;

int main()
{
    int choice;
    char quitChoice;
    string courseID;
    string studentID;;
    string courseName;
    string firstName;
    string lastName;
    string location;
    string meetingTime;
    int studentGrade;
    StudentArray studentArray;
    CourseArray courseArray;
    EnrollmentArray enrollmentArray;
    Student* student;
    Course* course;
    Enrollment* enrollment;
    int cls;
    Classification classification;
    ofstream gradebookOutputFileStream;
    ifstream gradebookInputFileStream;
    string fileName;
    cout << 
    "  +-------------------------------------------------------------------+\n"
    "  |              Computer Science and Engineering                     |\n"
    "  |               CSCE 1040 - Computer Science II                     |\n"
    "  |           Riya Danait    rd0305   rd0305@my.unt.edu               |\n"
    "  +-------------------------------------------------------------------+\n";
    //while loop for menu choice
    while(1)
    {
        cout <<
        "\n\n"
        "1. Add a new course \n"
        "2. Add a new student \n"
        "3. Add a student to a course (add enrollment) \n"
        "4. Add grades for a student in a course \n"
        "5. Print a list of all grades for a student in a course \n"
        "6. Print a list of all students in a course \n"
        "7. Compute the average for a student in a course \n"
        "8. Print a list of all courses \n"
        "9. Print a list of all students \n"
        "10. Compute the average for a course \n"
        "11. Store Grade book (to a disk file) \n"
        "12. Load Grade book (from a disk file) \n"
        "13. Quit \n";
        
        cout << "Please enter choice (1-13): ";
        //error checking
        if ( !(cin >> choice) )
        {
            cin.clear();
            cin.ignore();
            cout << "Incorrect entry. Try again: ";
            continue;
        }
        cin.get();
        
        switch(choice)
        {
            case 1:

                cout << "Add a new course" << endl;
                cout << "Please enter the course ID:";
                getline(cin, courseID);
                //check to see if the course already exists
                course = courseArray.findCourse(courseID);
                if(course != NULL)
                {
                    cout << "Course with ID " << courseID << " already exists in the grade book" << endl;
                    continue;
                }
                else
                {
                    cout << "Please enter the course Name:";
                    getline(cin, courseName);
                    cout << "Please enter the location:";
                    getline(cin, location);
                    cout << "Please enter the meeting time:";
                    getline(cin, meetingTime);
                    //checks to see that the user inputs actual string values for course name, id, location, and meeting time
                    if ((courseID.length()!=0) && (courseName.length()!=0) && (location.length()!=0)
                    && (meetingTime.length()!=0))
                    {
                        course = new Course(courseID, courseName, location, meetingTime);
                        courseArray.addACourse(course);
                        cout << "Course added" << endl;
                    }
                    else
                    {
                        cout << "Invalid course information entered. Please try again" << endl;
                    }
                }
                break;
            case 2:

                cout << "Add a new student" << endl;
                cout << "Please enter the StudentID of the student: ";
                getline(cin, studentID);
                //checking to see if student already exists
                student = studentArray.findStudent(studentID);
                
                if(student != NULL)
                {
                    cout << "Student with ID " << studentID << " already exists in the grade book" << endl;
                    continue;
                }
                else
                {
                    cout << "Please enter the First Name of the student: ";
                    getline(cin, firstName);
                    cout << "Please enter the Last Name of the student: ";
                    getline(cin, lastName);
                    cout << "Please enter the Classification (1: Freshman, 2: Sophomore, 3: Junior, 4: Senior) of the student: ";
                    cin >> cls;
                    cin.get();
                    //mapping the classification value to the corresponding enum
                    switch(cls)
                    {
                        case 1:
                            classification = Freshman;
                            break;
                        case 2:
                            classification = Sophomore;
                            break;
                        case 3:
                            classification = Junior;
                            break;
                        case 4:
                            classification = Senior;
                            break;
                        default:
                            classification = Unknown;
                            break;
                    }
                    //checks to make sure the user actually inputs a string for the student name and ID
                    if ((studentID.length()!=0) && (firstName.length()!=0) && (lastName.length()!=0))
                    {
                        student = new Student(studentID, firstName, lastName, classification);
                        studentArray.addAStudent(student);
                    }
                    else
                    {
                        cout << "Invalid student information entered. Please try again" << endl;
                    }
                }
                break;
                
            case 3:

                cout << "Add a student to a course" << endl;
                cout << "Please enter the ID of the student to add to the course: ";
                getline(cin, studentID);
                student = studentArray.findStudent(studentID);
                if(student != NULL)
                {
                    //check if the student is already enrolled in 5 courses
                    if (student->getEnrolledCourseCount() == Student::maxEnrollCourseCount)
                    {
                        cout << "Student is already enrolled in " << Student::maxEnrollCourseCount <<  " courses." << endl;
                    }
                    else
                    {
                        cout << "Please enter the course ID: ";
                        getline(cin, courseID);
                        Course *course = courseArray.findCourse(courseID);
                        if(course != NULL)
                        {
                            //check if the course has 48 students already
                            if(course->getEnrolledStudentCount() == Course::maxEnrollStudentCount)
                            {
                                cout << "Course " << courseID << " already has " << Course::maxEnrollStudentCount << " students enrolled in it." << endl;
                            }
                            else
                            {
                                //if not enroll the student
                                if(enrollmentArray.enrollAStudent(studentID, courseID))
                                {
                                    cout << "Student " << studentID << " successfully enrolled in course " << courseID << "." << endl;
                                }
                                else
                                {
                                    cout << "Student " << studentID << " is already enrolled in course " << courseID << "." << endl;
                                }
                            }
                        }
                        else
                        {
                            cout << "Course with ID " << courseID << " does not exist." << endl;
                        }
                    }
                }
                else
                {
                    cout << "Student with ID " << studentID << " does not exist." << endl;
                }
                
                break;

            case 4:
                cout << "Add grades for a student in a course" << endl;
                cout << "Please enter Student ID:";
                getline(cin, studentID);
                cout << "Please enter Course ID:";
                getline(cin, courseID);
                //find the students enrollment to add the grade
                enrollment = enrollmentArray.findEnrollment(studentID, courseID);
                
                if(enrollment != NULL)
                {
                    cout << "Please enter Student's grade: ";
                    cin >> studentGrade;
                    cin.get();
                    //sets the grade for the student
                    if(enrollment->setGrade(studentGrade) == true)
                    {
                        cout << "Grade for student " << studentID << " is entered." << endl;
                    }
                    else
                    {
                        cout << "Student " << studentID << " already has " << Enrollment::maxGradeCount << " grades entered." << endl;
                    }
                }
                else
                {
                    cout << "Student " << studentID << " is not enrolled in Course " << courseID << endl;
                }
                break;
                
            case 5:

                cout << "Print a list of all grades for a student in a course" << endl;
                cout << "Please enter Student ID: ";
                getline(cin, studentID);
                cout << "Please enter Course ID: ";
                getline(cin, courseID);
                //finds the student's enrollment to print a list of the grades for a student in a course
                enrollment = enrollmentArray.findEnrollment(studentID, courseID);
                
                if(enrollment != NULL)
                {
                    //prints out necessary data
                    cout << setfill('-') << setw(80) << "-" << endl;
                    cout << setfill(' ') << setw(12) << left << "Course ID";
                    cout << setw(12) << left << "Student ID";
                    cout << setw(8) << left << "Avg";
                    cout << setw(4) << left << "Ltr";
                    cout << setw(4) << left << "G1";
                    cout << setw(4) << left << "G2";
                    cout << setw(4) << left << "G3";
                    cout << setw(4) << left << "G4";
                    cout << setw(4) << left << "G5";
                    cout << setw(4) << left << "G6";
                    cout << setw(4) << left << "G7";
                    cout << setw(4) << left << "G8";
                    cout << setw(4) << left << "G9";
                    cout << setw(4) << left << "G10" << endl;
                    cout << setfill('-') << setw(80) << "-" << endl;
                    cout << setfill(' ') << setw(12) << left << courseID;
                    cout << setw(12) << left << studentID;
                    //prints the grades
                    enrollment->printAllGradesForAStudentInACourse();
                }
                else
                {
                    cout << "Student " << studentID << " is not enrolled in Course " << courseID << endl;
                }
                break;
            case 6:

                cout << "Print a list of all students in a course" << endl;
                cout << "Please enter Course ID: ";
                getline(cin, courseID);
                //if course ID exists
                if(courseArray.findCourse(courseID))
                {
                    string** studentIDs;
                    int studentCount = 0;
                    //get all students in the course
                    studentIDs = enrollmentArray.getAllStudentsInACourse(courseID, studentCount);
                    //print the students in the course
                    studentArray.printStudentsInCourse(studentIDs, studentCount);
                }
                else
                {
                    cout << "Course with ID " << courseID << " does not exist." << endl;
                }
                break;
            case 7:

                cout << "Compute the average for a student in a course." << endl;
                cout << "Please enter Student ID: ";
                getline(cin, studentID);
                cout << "Please enter Course ID: ";
                getline(cin, courseID);
                //finds the student's enrollment in a course to calculate their average grade
                enrollment = enrollmentArray.findEnrollment(studentID, courseID);
                if(enrollment != NULL)
                {
                    //couts the average grade by calling the average grade for a student function
                    cout << "Average grade for student with ID " << studentID << " in course with ID " << courseID << " is " << setprecision(2) << fixed << enrollment->averageGradeForAStudent() << endl;
                }
                else
                {
                    cout << "Student " << studentID << " is not enrolled in Course " << courseID << endl;
                }
                break;
            case 8:

                cout << "Print a list of all courses" << endl;
                cout << endl;
                courseArray.printAllCourses();
                break;
            case 9:

                cout << "Print a list of all students" << endl;
                cout << endl;
                studentArray.printAllStudents();
                break;
            case 10:

                cout << "Compute the average for a course" << endl;
                cout << "Please enter Course ID: ";
                getline(cin, courseID);
                //if course ID exists
                if(courseArray.findCourse(courseID))
                {
                    //prints the average course grade
                    cout << setprecision(2) << fixed << "The average grade for the course with ID " << courseID << " is " << enrollmentArray.averageCourseGrade(courseID) << endl;
                }
                break;
            case 11:

                cout << "Store gradebook (to a disk file)" << endl;
                cout << "Enter the name of the file to save the gradebook to: ";
                getline(cin, fileName);
                //opens the file stream
                gradebookOutputFileStream.open(fileName.c_str());
                if(gradebookOutputFileStream.fail())
                {
                    cout << "Could not open the file " << fileName << " to save the gradebook.\n";
                }
                else
                {
                    //saves the arrays to the file
                    studentArray.saveToFile(gradebookOutputFileStream);
                    courseArray.saveToFile(gradebookOutputFileStream);
                    enrollmentArray.saveToFile(gradebookOutputFileStream);
                    //closes the file
                    gradebookOutputFileStream.close();
                    cout << "Saved gradebook to file " << fileName << endl;
                }
                break;
            case 12:

                cout << "Load gradebook (from a disk file)" << endl;
                cout << "Enter the name of the file to load the gradebook from: ";
                getline(cin, fileName);
                //open the file
                gradebookInputFileStream.open(fileName.c_str());
                if(gradebookInputFileStream.fail())
                {
                    cout << "Could not open the file " << fileName << " to load the gradebook.\n";
                }
                else
                {
                    //loads from the file into the arrays
                    studentArray.loadFromFile(gradebookInputFileStream);
                    courseArray.loadFromFile(gradebookInputFileStream);
                    enrollmentArray.loadFromFile(gradebookInputFileStream);
                    //close the file stream
                    gradebookInputFileStream.close();
                    cout << "Loaded gradebook from file " << fileName << endl;
                }
                break;
            case 13:
                //quit
                cout << "Do you want to quit? Confirm with Y or N:" << endl;
                cin >> quitChoice;
                if(toupper(quitChoice) == 'Y')
                {
                    exit(0);
                }
                else
                {
                    break;
                }
            default:
                //not valid
                cout << "Invalid choice. Please try again." << endl;
                cin.clear();
                break;
        }
    }
}
