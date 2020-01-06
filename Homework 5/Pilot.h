/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 5
Airline Scheduling System
*/
#include "CrewMember.h"
#include <string>

#ifndef _PILOT_H_
#define _PILOT_H_

class Pilot : public CrewMember
{
public:

	Pilot();
	string getRatingCode();
	void setRatingCode(string ratingCode);
	int getCumulativeFlightHours();
	void setCumulativeFlightHours(int cumulativeFlightHours);
	void PrintInfo();

private:
	string ratingCode;
	int cumulativeFlightHours;
};

#endif