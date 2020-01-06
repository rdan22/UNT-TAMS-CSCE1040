/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 5
Airline Scheduling System
*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <cstring>
#include "Interval.h"
// 
// helper function for comparing two time_t objects
//
bool comparetime(time_t time1,time_t time2){
   return difftime(time1,time2) < 0.0 ? true : false; 
} 

time_t Interval::convertTime(string timeIn)
{
	struct tm localtime;
	char buf[30];

	memset(&localtime, 0, sizeof(struct tm));

	strptime(timeIn.c_str(), "%m-%d-%Y %H:%M %Z", &localtime);
	localtime.tm_isdst = -1;

	time_t time_seconds = mktime(&localtime);    

	strftime(buf, sizeof(buf), "%d %b %Y %H:%M %Z", &localtime);

  struct tm* utc_field = gmtime(&time_seconds);       // convert it to UTC time
  strftime(buf, sizeof(buf), "%F %T UTC\n", utc_field);


    return time_seconds;
}


void Interval::setStartTime(string start_str, string start_zone)
{
  char *tz;

    // Support all the US 3 character timezone abbreviations
  if ((start_zone == "CST") || (start_zone == "CDT"))
		Interval::start_zone = "America/Chicago";
  else if ((start_zone == "MST") || (start_zone == "MDT"))
    	Interval::start_zone = "America/Denver";
  else if ((start_zone == "PST") || (start_zone == "PDT"))
  		Interval::start_zone = "America/Los_Angeles";
  else if ((start_zone == "EST") || (start_zone == "EDT"))
  		Interval::start_zone = "America/New_York";
  else
  		Interval::start_zone = start_zone;

    	 
  Interval::start_date_time_str = start_str;

  tz = getenv("TZ");
  setenv("TZ", start_zone.c_str(), 1); // switch to requested timezone to compute time_t
  tzset();

  start = convertTime(start_date_time_str + " " + start_zone);  

  if (tz)
      setenv("TZ", tz, 1);
  else
      unsetenv("TZ");

  tzset();

}


void Interval::setFinishTime(string finish_str, string end_zone)
{
  char *tz;

  // Support all the US 3 character timezone abbreviations
  if ((end_zone == "CST") || (end_zone == "CDT"))
		Interval::finish_zone = "America/Chicago";
  else if ((end_zone == "MST") || (end_zone == "MDT"))
    	Interval::finish_zone = "America/Denver";
  else if ((start_zone == "PST") || (start_zone == "PDT"))
  		Interval::finish_zone = "America/Los_Angeles";
  else if ((start_zone == "EST") || (start_zone == "EDT"))
  		Interval::finish_zone = "America/New_York";
  else
		Interval::finish_zone = end_zone;

  Interval::finish_date_time_str = finish_str;

  tz = getenv("TZ");
  setenv("TZ", end_zone.c_str(), 1); // switch to requested timezone to compute time_t
  tzset();
  
  finish = convertTime(finish_date_time_str + " " + finish_zone);

  if (tz)
      setenv("TZ", tz, 1);
  else
      unsetenv("TZ");

  tzset();

}

string Interval::getStartTimeStr() {
    return (start_date_time_str + " " + start_zone);
}

string Interval::getFinishTimeStr() {
    return (finish_date_time_str + " " + finish_zone);
}

time_t Interval::getStartTime() {
    return (start);
}

time_t Interval::getFinishTime() {
    return (finish);
}
string Interval::getStartZone() {
    return (start_zone);
}

string Interval::getFinishZone() {
    return (finish_zone);
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
