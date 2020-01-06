/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 4
Airline Scheduling System
*/
#include <time.h>
#include <iomanip>
#include <string>

#ifndef _INTERVAL_H_
#define _INTERVAL_H_

using namespace std;

// helper function for comparing two time_t objects
bool comparetime(time_t time1,time_t time2); 

// Class for maintaining busy intervals for Crew and Planes
class Interval {

private:
    //private data members
    string    ID;        // same as PlaneID - to associate this interval to the resources being scheduled
	time_t start;           // time converted to time_t
	time_t finish;
    string start_time_str;  // time as entered by user in string format
    string finish_time_str;

    // convert time from MM-DD-YYYY HH:MM (UTC) format to time_t for storing in Interval and comparing
	time_t convertTime(string timeIn);

public:
    //public functions
    void setStartTime(string start_str);  // date + time format  MM-DD-YYYY HH:MM
    void setFinishTime(string finish_str); // date + time format
    string getStartTimeStr();
    string getFinishTimeStr();
    time_t getStartTime();
    time_t getFinishTime();
    void   setID(string id);
    string getID();
    bool operator < (const Interval& x) const;
};

#endif