/* 
===============================================================================
Name        : Course.h
Author      : Riya Danait
Date        : 3/5/2018
Description : This is the Course header file with definitions of the functions. 
===============================================================================
*/
#include <string>

using namespace std;

class Course
{
	private:
		//private data members
		string ID;
		string courseName;
		string location;
		string meetingTime;
		int enrolledStudentCount;
		

	public:
		//static constant for the max number of enrolled students in a course
		static const int maxEnrollStudentCount = 48;
		//constructor and destructor
		Course(string courseID, string courseName, string location, string meetingTime);
		~Course();
		//Accessors and mutators
		//get and set location, meetung time, course ID, course name, number of enrolled students
		string getLocation();
		string getMeetingTime();
		string getCourseID();
		string getCourseName();
		int    getEnrolledStudentCount();
        void   setEnrolledStudentCount(int count);
		void setCourseID(string id);
		void setCourseName(string nameOfCourse);
		void setLocation(string loc);
		void setMeetingTime(string time);

};
