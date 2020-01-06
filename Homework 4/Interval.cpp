/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 4
Airline Scheduling System
*/
#include <iostream>
#include <string>
#include <cstdio>
#include "Interval.h"
// 
// helper function for comparing two time_t objects
//
bool comparetime(time_t time1,time_t time2){
   return difftime(time1,time2) < 0.0 ? true : false; 
} 

//
// Utility function to convert time in string format to time_t structure for comparison purposes
// Entered times are assumed to be in UTC/GMT to avoid Time Zone complications.
//
time_t Interval::convertTime(string timeIn){
    int year = 0, month = 0, day = 0, hour = 0, min = 0;
    string tz;
    time_t convertedTime;
    if (sscanf(timeIn.c_str(), "%2d-%2d-%4d %2d:%2d", &month, &day, &year, &hour, &min) == 5) {
       struct tm breakdown = {0};
       breakdown.tm_year = year - 1900; /* years since 1900 */
       breakdown.tm_mon = month - 1;
       breakdown.tm_mday = day;
       breakdown.tm_hour = hour;
       breakdown.tm_min = min;
       breakdown.tm_gmtoff = 0; // force timezone to be GMT
       breakdown.tm_isdst = 0;  // turn off day light saving flag as its not applicable for GMT times
       convertedTime = timegm(&breakdown);  // convert to UTC for comparison purposes
       //setenv("TZ", "UTC",1);
       //cout << "timeIn=" << timeIn << " convertedTime=" << ctime(&convertedTime) << endl;
       return (convertedTime);
   }

   return ((time_t)0);
}

void Interval::setStartTime(string start_str){
    start_time_str = start_str;
    start = convertTime(start_str);
}
void Interval::setFinishTime(string finish_str)
{
    finish_time_str = finish_str;
    finish = convertTime(finish_str);
}

string Interval::getStartTimeStr() {
    return (start_time_str);
}

string Interval::getFinishTimeStr() {
    return (finish_time_str);
}

time_t Interval::getStartTime() {
    return (start);
}

time_t Interval::getFinishTime() {
    return (finish);
}

string Interval::getID()
{
  return (ID);
}

void Interval::setID(string id)
{
  ID = id;
}

bool Interval::operator < (const Interval& x) const   {
        if (finish != x.finish)
            return comparetime(finish, x.finish);
        return comparetime(start, x.start);
    }
