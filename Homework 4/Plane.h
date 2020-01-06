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

#ifndef _PLANE_H_
#define _PLANE_H_

using namespace std;

class Plane {

public:
	Plane();

	//accessors and mutators
	string getMake();
	void setMake(string make);
	string getModel();
	void setModel(string model);
	string getTailNum();
	void setTailNum(string tailNum);
	int getNumSeats();
	void setNumSeats(int seats);
	int getRange();
	void setRange(int range);
	string getStatus();
	void setStatus(string status);
	void printPlaneDetails();

	// Check if plane is available for given time interval
	bool checkAvailability(Interval interval);

	// Schedule plane for requested interval (to be called if time slot is available)
	void scheduleForFlight(Interval interval);

	// Used for clearing this plane's schedule once the flight completes
	void makeAvailable(Interval interval);
	
	vector<Interval> getScheduledIntervals();


private:
	//private data members
	string make;
	string model;
	string tailNum;
	int		seats;
	int		range;
	string	status;

	// Maintain a vector of scheduled intervals for this plane
	vector <Interval> scheduledIntervals;
};

#endif
