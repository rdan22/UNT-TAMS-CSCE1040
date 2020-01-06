/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 5
Airline Scheduling System
*/
#include "CrewMember.h"
#include <string>

#ifndef _COPILOT_H_
#define _COPILOT_H_

class CoPilot : public CrewMember
{
public:

	CoPilot();
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