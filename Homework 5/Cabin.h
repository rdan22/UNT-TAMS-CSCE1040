/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 5
Airline Scheduling System
*/
#include "CrewMember.h"
#include <string>

#ifndef _CABIN_H_
#define _CABIN_H_

class Cabin : public CrewMember
{
public:

	Cabin();
	string getPosition();
	void setPosition(string position);
	void PrintInfo();

private:
	string position;
};
#endif