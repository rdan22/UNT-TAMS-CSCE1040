/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 5
Airline Scheduling System
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "Interval.h"
#include "CrewMember.h"

#ifndef _AIRLINE_STAFF_H_
#define _AIRLINE_STAFF_H_

using namespace std;

class AirlineStaff {
	

public:
	AirlineStaff();
	//public member functions
	void addCrewMember(CrewMember *crewMember);
	void deleteCrewMember(string crewID);
	void updateCrewMemberStatus(string crewID, string status);
	string findAvailablePilot(Interval interval);
	string findAvailableCoPilot(Interval interval);
	vector<string> findAvailableCabinCrewMembers(Interval interval);
	void printStaff();
	void printStaffDetails(string crewID);
	void scheduleCrewMemberForFlight(string crewID, Interval requestedInterval);
	void makeCrewMemberAvailable(string crewID, Interval interval);
	void scheduleCrewForFlight(vector<string> crewIDs, Interval requestedInterval);
	void saveData(ofstream& outputStream);
	void loadData(ifstream& inputStream);


private:
	// Map of crew members, keyed on CrewID
	map<string, CrewMember*> crewMembers;
};

#endif
