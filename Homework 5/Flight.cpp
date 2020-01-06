/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 5
Airline Scheduling System
*/
#include <iostream>
#include <string>
#include <iomanip>
#include "Flight.h"
using namespace std;

Flight::Flight()
{

}

string Flight::getPlaneID()
{
	return planeID;
}
void Flight::setPlaneID(string planeID)
{
	Flight::planeID = planeID;
}
string Flight::getPilotID()
{
	return pilotID;
}
void Flight::setPilotID(string pilotID)
{
	Flight::pilotID = pilotID;
}
string Flight::getCoPilotID()
{
	return copilotID;
}
void Flight::setCoPilotID(string copilotID)
{
	Flight::copilotID = copilotID;
}
vector<string> Flight::getCabinCrewIDs()
{	
	return (cabinCrewIDs);
}
void Flight::setCabinCrewIDs(vector<string> crewIDs)
{
	cabinCrewIDs = crewIDs;
}
void Flight::addCabinCrewID(string crewID)
{
	cabinCrewIDs.push_back(crewID);
}

string Flight::getStartTime()
{
	return startTime;
}
void Flight::setStartTime(string startTime)
{
	Flight::startTime = startTime;
}
string Flight::getEndTime()
{
	return endTime;
}
void Flight::setEndTime(string endTime)
{	
	Flight::endTime = endTime;
}

string Flight::getStartTZ()
{
	return startTZ;
}
void Flight::setStartTZ(string startTZ)
{
	Flight::startTZ = startTZ;
}

string Flight::getEndTZ()
{
	return endTZ;
}
void Flight::setEndTZ(string endTZ)
{
	Flight::endTZ = endTZ;
}

string Flight::getStartDate()
{
	return startDate;
}
void Flight::setStartDate(string startDate)
{
	Flight::startDate = startDate;
}
string Flight::getEndDate()
{
	return endDate;
}
void Flight::setEndDate(string endDate)
{
	Flight::endDate = endDate;
}
string Flight::getStartingCode()
{
	return startingCode;
}
void Flight::setStartingCode(string startingCode)
{
	Flight::startingCode = startingCode;
}
string Flight::getEndingCode()
{
	return endingCode;
}
void Flight::setEndingCode(string endingCode)
{
	Flight::endingCode = endingCode;
}
int Flight::getNumPassengers()
{
	return numPassengers;
}
void Flight::setNumPassengers(int numPassengers)
{
	Flight::numPassengers = numPassengers;
}
string Flight::getStatus()
{
	return status;
}
void Flight::setStatus(string status)
{
	Flight::status = status;
}

Interval Flight::getInterval()
{
	return flightInterval;
}

void Flight::setInterval(Interval interval)
{
	flightInterval = interval;
}

void Flight::printFlightDetails()
{
 	cout << setfill(' ') << setw(10) << planeID;
 	cout << setfill(' ') << setw(10) << pilotID;
 	cout << setfill(' ') << setw(10) << copilotID;
	for (int i = 0; i < 3; i++)
    {
    	cout << setw(10) << cabinCrewIDs[i];
    }
    cout << setw(12) << startDate;
    cout << setw(8) << startTime;
    cout << setw(20) << startTZ;
    cout << setw(12) << endDate;
    cout << setw(8) << endTime;
    cout << setw(20) << endTZ;
    cout << setw(10) << startingCode;
    cout << setw(10) << endingCode;
    cout << setw(10) << numPassengers;
    cout << setw(10) << status << endl;
}



