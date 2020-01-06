/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 4
Airline Scheduling System
*/
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include "Interval.h"
#include "Flight.h"

using namespace std;

class FlightSchedule {
	
public:
	FlightSchedule();
	//public member functions
	void addFlight(Flight* flight);
	void deleteFlight(string planeID);
	void updateFlightStatus(string planeID, string status);
	Flight* findFlight(string planeID);
	void printFlightSchedule();
	void printFlightDetails(string planeID);
	void printFlightDetailsForStatus(string status);
	void saveData(ofstream& flightScheduleStream);
	void loadData(ifstream& flightScheduleStream);
	vector<Flight*> getCompletedFlights();


private:
	// map of planeID to Flight
	vector<Flight*> flights;
};