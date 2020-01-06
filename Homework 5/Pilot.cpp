/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 5
Airline Scheduling System
*/
#include "Pilot.h"
#include <string>
#include <iostream>
//derived Pilot class that inherits from the base class CrewMember
Pilot::Pilot()
{

}
string Pilot::getRatingCode()
{
	return ratingCode;
}
void Pilot::setRatingCode(string ratingCode)
{
	Pilot::ratingCode = ratingCode;
}
int Pilot::getCumulativeFlightHours()
{
	return cumulativeFlightHours;
}
void Pilot::setCumulativeFlightHours(int cumulativeFlightHours)
{
	Pilot::cumulativeFlightHours = cumulativeFlightHours;
}
void Pilot::PrintInfo()
{
	//overrides the printinfo function
	CrewMember::PrintInfo();
	cout << setw(20) << ratingCode;
	cout << setw(25) << cumulativeFlightHours << endl;
}