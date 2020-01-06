/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 5
Airline Scheduling System
*/
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "Plane.h"
#include "Interval.h"

#ifndef _FLEET_H_
#define _FLEET_H_

using namespace std;

class Fleet {
	
public:
	Fleet();
	//public member functions
	void addPlane(Plane *plane);
	void deletePlane(string tailNum);
	void updatePlaneStatus(string tailNum, string status);
	string findAvailablePlane(int numPassengers, Interval requestedInterval);
	void makePlaneAvailable(string tailNum, Interval interval);
	void printPlaneInventory();
	void printPlaneDetails(string tailNum);
	void schedulePlaneForFlight(string tailNum, Interval requestedInterval);
	void saveData(ofstream& outputStream);
	void loadData(ifstream& inputStream);

private:
	// map of tailnum to Plane
	map<string, Plane*> planes;
};

#endif