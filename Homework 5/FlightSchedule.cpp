/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 5
Airline Scheduling System
*/
#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include "FlightSchedule.h"

using namespace std;

FlightSchedule::FlightSchedule()
{

}
//add flight
void FlightSchedule::addFlight(Flight* flight)
{

	flights.push_back(flight);
}
//delete flight
void FlightSchedule::deleteFlight(string planeID)
{
	vector<Flight*>::iterator it = flights.begin();

	while(it != flights.end())
	{
		Flight *flight = *it;

		if (flight != NULL)
		{
			if ((flight->getPlaneID() == planeID) && (flight->getStatus() != "ACTIVE"))
			{
                // only allow deletion of inactive flights from the schedule
                it = flights.erase(it);
                cout << "Flight " << flight->getPlaneID() << " removed from schedule" << endl;           
                delete flight;
                return;
			}
			else
			{
				it++;
			}
		}
	}
}

void FlightSchedule::updateFlightStatus(string planeID, string status)
{
	
	vector<Flight*>::iterator it = flights.begin();

	while(it != flights.end())
	{
		if ((*it)->getPlaneID() == planeID)
		{
			(*it)->setStatus(status);
			break;
		}
		it++;
	}
}


Flight* FlightSchedule::findFlight(string planeID)
{
	vector<Flight*>::iterator it = flights.begin();

	while(it != flights.end())
	{
		if ((*it)->getPlaneID() == planeID)
		{
			return *it;
		}
		it++;
	}

	return NULL;
}


void FlightSchedule::printFlightSchedule()
{
	vector<Flight*>::iterator it = flights.begin();

	cout << setfill('-') << setw(175) << "-" << endl;
    cout << setfill(' ') << setw(10) << left << "Plane ID";
    cout << setw(10) << left << "PilotID";
    cout << setw(10) << left << "CoPilotID";
    cout << setw(10) << left << "CabinID1";
    cout << setw(10) << left << "CabinID2";
    cout << setw(10) << left << "CabinID3";
    cout << setw(10) << left << "StartDate";
    cout << setw(10) << left << "StartTime";
    cout << setw(20) << left << "StartTZ";
    cout << setw(10) << left << "EndDate";
    cout << setw(10) << left << "EndTime";
    cout << setw(20) << left << "EndTZ";
    cout << setw(10) << left << "Departure";
    cout << setw(10) << left << "Arrival";
    cout << setw(10) << left << "Passgrs.";
    cout << setw(10) << left << "Status" << endl;
    cout << setfill('-') << setw(175) << "-" << endl;

	while(it != flights.end())
	{
		(*it)->printFlightDetails();
		it++;
	}
}


void FlightSchedule::printFlightDetails(string planeID)
{
	vector<Flight*>::iterator it = flights.begin();

	cout << setfill('-') << setw(175) << "-" << endl;
    cout << setfill(' ') << setw(10) << left << "Plane ID";
    cout << setw(10) << left << "PilotID";
    cout << setw(10) << left << "CoPilotID";
    cout << setw(10) << left << "CabinID1";
    cout << setw(10) << left << "CabinID2";
    cout << setw(10) << left << "CabinID3";
    cout << setw(10) << left << "StartDate";
    cout << setw(10) << left << "StartTime";
    cout << setw(20) << left << "StartTZ";
    cout << setw(10) << left << "EndDate";
    cout << setw(10) << left << "EndTime";
    cout << setw(20) << left << "EndTZ";
    cout << setw(10) << left << "Departure";
    cout << setw(10) << left << "Arrival";
    cout << setw(10) << left << "Passgrs.";
    cout << setw(10) << left << "Status" << endl;
    cout << setfill('-') << setw(175) << "-" << endl;


	while(it != flights.end())
	{
		if ((*it)->getPlaneID() == planeID)
		{
			(*it)->printFlightDetails();
		}
		it++;
	}
}


void FlightSchedule::printFlightDetailsForStatus(string status)
{
    vector<Flight*>::iterator it = flights.begin();

    cout << setfill('-') << setw(175) << "-" << endl;
    cout << setfill(' ') << setw(10) << left << "Plane ID";
    cout << setw(10) << left << "PilotID";
    cout << setw(10) << left << "CoPilotID";
    cout << setw(10) << left << "CabinID1";
    cout << setw(10) << left << "CabinID2";
    cout << setw(10) << left << "CabinID3";
    cout << setw(10) << left << "StartDate";
    cout << setw(10) << left << "StartTime";
    cout << setw(20) << left << "StartTZ";
    cout << setw(10) << left << "EndDate";
    cout << setw(10) << left << "EndTime";
    cout << setw(20) << left << "EndTZ";
    cout << setw(10) << left << "Departure";
    cout << setw(10) << left << "Arrival";
    cout << setw(10) << left << "Passgrs.";
    cout << setw(10) << left << "Status" << endl;
    cout << setfill('-') << setw(175) << "-" << endl;


    while(it != flights.end())
    {
        if ((*it)->getStatus() == status)
        {
            (*it)->printFlightDetails();
        }
        it++;
    }
}

void FlightSchedule::saveData(ofstream& os)
{
  	os << flights.size() << endl;
    vector<Flight*>::iterator it = flights.begin();
	while(it != flights.end())
    {
    	Flight *flight = *it;

   	    os << flight->getPlaneID() << ',' << flight->getPilotID() << ','
        	<< flight->getCoPilotID() << ',';
        for (int i = 0; i < 3; i++)
        {
        	os << flight->getCabinCrewIDs()[i] << ',';
        }
        os << flight->getStartDate() << ','
        	<< flight->getStartTime() << ',' << flight->getStartTZ() << ',' << flight->getEndDate() << ','
        	<< flight->getEndTime() << ','  << flight->getEndTZ() << ',' << flight->getStartingCode() << ','
        	<< flight->getEndingCode() << ',' << flight->getNumPassengers() << ','
        	<< flight->getStatus() << endl;
  
    	it++;

    }
    // cout << "Saved " << flights.size() << " flights to the flight schedule file." << endl;

}


void FlightSchedule::loadData(ifstream& is)
{
    string planeID;
    string pilotID;
    string coPilotID;
    string crewID1;
    string crewID2;
    string crewID3;
    string startDate;
    string startTime;
    string startTZ;
    string endDate;
    string endTime;
    string endTZ;
    string startingCode;
    string endingCode;
    int numPassengers;
    string status;
    Interval flightInterval;

    int tempCount = 0;
    
    is >> tempCount;
    is.get();
    for(int i = 0; i < tempCount; i++)
    {
        getline(is, planeID, ',');
        getline(is, pilotID, ',');
        getline(is, coPilotID, ',');
        getline(is, crewID1, ',');
        getline(is, crewID2, ',');
        getline(is, crewID3, ',');
        getline(is, startDate, ',');
        getline(is, startTime, ',');
        getline(is, startTZ, ',');
        getline(is, endDate, ',');
        getline(is, endTime, ',');
        getline(is, endTZ, ',');
        getline(is, startingCode, ',');
        getline(is, endingCode, ',');   
        is >> numPassengers;
        is.get(); // eat the comma at the end;
        getline(is, status);
        
        Flight* flight = new Flight();

        flight->setPlaneID(planeID);
        flight->setPilotID(pilotID);
        flight->setCoPilotID(coPilotID);
        flight->addCabinCrewID(crewID1);
        flight->addCabinCrewID(crewID2);
        flight->addCabinCrewID(crewID3);
        flight->setStartDate(startDate);
        flight->setStartTime(startTime);
        flight->setStartTZ(startTZ);
        flight->setEndDate(endDate);
        flight->setEndTime(endTime);
        flight->setEndTZ(endTZ);
        flight->setStartingCode(startingCode);
        flight->setEndingCode(endingCode);
        flight->setNumPassengers(numPassengers);
        flight->setStatus(status);

        flightInterval.setID(planeID);
		flightInterval.setStartTime(startDate + " " + startTime, startTZ);
    	flightInterval.setFinishTime(endDate + " " + endTime, endTZ);

        flight->setInterval(flightInterval);

        addFlight(flight);
    }
    cout << "Loaded " << tempCount << " flights from the flight schedule file." << endl;

}
//gets all of the completed flights
vector<Flight*> FlightSchedule::getCompletedFlights()
{
	vector<Flight*> completedFlights;
	time_t now;

  	time (&now);

    cout << "Current time in GMT is " << ctime(&now) << endl;

	vector<Flight*>::iterator it = flights.begin();

	while(it != flights.end())
	{
        Flight *flight = *it;
        time_t flight_start_time = (*it)->getInterval().getStartTime();
		time_t flight_end_time = (*it)->getInterval().getFinishTime();

        if (comparetime(flight_start_time, now) &&
            comparetime(now, flight_end_time) &&
            (flight->getStatus() == "SCHEDULED"))
        {
            // current time is past departure time, but less than arrival time.
            // we are in the active time for this flight. if SCHEDULED, mark it ACTIVE
            flight->setStatus("ACTIVE");
            cout << "Flight " << flight->getPlaneID() << " from " 
                 << flight->getStartingCode() << " to " 
                 << flight->getEndingCode() << " updated to ACTIVE" << endl;
        }

		if (comparetime(flight_end_time, now))
		{
			// current time is past the end time of the flight
			// update flight status to completed
			// return the completed interval so that flight resources can be marked available
			// for scheduling on the next flight
			if ((flight->getStatus() == "SCHEDULED") || (flight->getStatus() == "ACTIVE"))
			{
				flight->setStatus("COMPLETED");
                cout << "Flight " << flight->getPlaneID() << " from " 
                 << flight->getStartingCode() << " to " 
                 << flight->getEndingCode() << " updated to COMPLETED" << endl;
  			}
        }

		if ((flight->getStatus() == "COMPLETED") || (flight->getStatus() == "CANCELED"))
		{
				completedFlights.push_back(flight);
		}
		it++;
	}

    // Return all completed flights
	return completedFlights;
}
