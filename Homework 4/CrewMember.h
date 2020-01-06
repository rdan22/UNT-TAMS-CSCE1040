/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 4
Airline Scheduling System
*/
#include <iostream>
#include <string>
#include <vector>
#include "Interval.h"

#ifndef _CREW_MEMBER_H_
#define _CREW_MEMBER_H_

using namespace std;

class CrewMember {
	

public:
	CrewMember();
	//accessors and mutators
	string getName();
	void setName(string name);
	string getID();
	void setID(string ID);
	string getType();
	void setType(string type);
	string getStatus();
	void setStatus(string status);
	void printCrewMemberDetails();

	// Check if crew member is available for given time interval
	bool checkAvailability(Interval interval);

	// Schedule crew member for requested interval (to be called if time slot is available)
	void scheduleForFlight(Interval interval);

	// Used for clearing this crew member's schedule once the flight completes
	void makeAvailable(Interval interval);

	vector<Interval> getScheduledIntervals();
	
private:
	//private data members
	string name;
	string ID;
	string type;
	string	status;

	// Maintain a vector of scheduled intervals for this crew member
	vector <Interval> scheduledIntervals;
};

#endif