/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 5
Airline Scheduling System
*/
#include "CoPilot.h"
#include <string>
#include <iostream>
//derived CoPilot class declarations that inherits from the base class CrewMember
CoPilot::CoPilot()
{

}
string CoPilot::getRatingCode()
{
	return ratingCode;
}
void CoPilot::setRatingCode(string ratingCode)
{
	CoPilot::ratingCode = ratingCode;
}
int CoPilot::getCumulativeFlightHours()
{
	return cumulativeFlightHours;
}
void CoPilot::setCumulativeFlightHours(int cumulativeFlightHours)
{
	CoPilot::cumulativeFlightHours = cumulativeFlightHours;
}
void CoPilot::PrintInfo()
{
	//overrides the printinfo function
	CrewMember::PrintInfo();
	cout << setw(20) << ratingCode;
	cout << setw(25) << cumulativeFlightHours << endl;
}