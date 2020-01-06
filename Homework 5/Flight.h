/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 5
Airline Scheduling System
*/
#include <iostream>
#include <string>
#include <vector>
#include "Interval.h"

#ifndef _FLIGHT_H_
#define _FLIGHT_H_

using namespace std;

class Flight {
	

public:
	Flight();
	//accessors and mutators
	string getPlaneID();
	void setPlaneID(string planeID);
	string getPilotID();
	void setPilotID(string pilotID);
	string getCoPilotID();
	void setCoPilotID(string copilotID);
	vector<string> getCabinCrewIDs();
	void setCabinCrewIDs(vector<string> crewIDs);
	void addCabinCrewID(string crewID);
	string getStartTime();
	void setStartTime(string startTime);

	string getEndTime();
	void setEndTime(string endTime);
	string getStartDate();
	void setStartDate(string startDate);
	string getEndDate();
	void setEndDate(string endDate);	
	string getStartTZ();
	void setStartTZ(string startTZ);
	string getEndTZ();
	void setEndTZ(string endTZ);
	string getStartingCode();
	void setStartingCode(string startingCode);
	string getEndingCode();
	void setEndingCode(string endingCode);
	int getNumPassengers();
	void setNumPassengers(int numPassengers);
	string getStatus();
	void setStatus(string status);
	void printFlightDetails();
	void setInterval(Interval interval);
	Interval getInterval();

private:
	//private data members
	string planeID;
	string pilotID;
	string copilotID;
	vector<string> cabinCrewIDs;
	string startDate;
	string endDate;
	string startTime;
	string endTime;
	string startTZ;
	string endTZ;
	string startingCode;
	string endingCode;
	int	   numPassengers;
	string status;
	Interval flightInterval;
};

#endif
