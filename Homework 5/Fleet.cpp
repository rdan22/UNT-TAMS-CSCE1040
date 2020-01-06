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
#include "Fleet.h"
using namespace std;

Fleet::Fleet()
{

}
//add plane
void Fleet::addPlane(Plane *plane)
{
	planes[plane->getTailNum()] = plane;
}
//delete plane
void Fleet::deletePlane(string tailNum)
{
	map<string, Plane*>::iterator it;
	
        if((it = planes.find(tailNum)) != planes.end())
        {
        	Plane *plane = it->second;
		if(plane->getScheduledIntervals().size() > 0)
		{
			cout << "Plane is already scheduled for a flight. If you would like to delete it, please delete the flight first." << endl;
		}
		else
		{
	        	delete it->second;
                	planes.erase(tailNum);
		}
        }
        else
        {
                cout << "No plane found with tailNum " << tailNum << "." << endl;
        }

}

void Fleet::updatePlaneStatus(string tailNum, string status)
{
	if(planes.find(tailNum) != planes.end())
	{
		planes[tailNum]->setStatus(status);
	}
	else
	{
		cout << "No plane found with tailNum " << tailNum << "." << endl;
	}
}
//find available plane 
string Fleet::findAvailablePlane(int numPassengers, Interval requestedInterval)
{
	map<string, Plane*>::iterator it = planes.begin();

	while(it != planes.end())
	{
		// A plane can be used if it has the right capacity, and is not already in 'out' or 'repair' status
		if (((it->second)->getNumSeats() >= numPassengers) && 
			((it->second)->getStatus() != "repair") && 
			((it->second)->getStatus() != "out"))
		{
			if ( (it->second)->checkAvailability(requestedInterval))
			{
				return (it->second)->getTailNum();
			}
		}
		it++;
	}
	return "";
}
//schedule a plane for a flight
void Fleet::schedulePlaneForFlight(string tailNum, Interval requestedInterval)
{
	if(planes.find(tailNum) != planes.end())
	{
		planes[tailNum]->scheduleForFlight(requestedInterval);
	}
	else
	{
		cout << "No plane found with tailNum " << tailNum << ". Plane could not be scheduled for flight" << endl;
	}

}
//make a plane available
void Fleet::makePlaneAvailable(string tailNum, Interval interval)
{
	if(planes.find(tailNum) != planes.end())
	{
		planes[tailNum]->makeAvailable(interval);
	}
	else
	{
		cout << "No plane found with tailNum " << tailNum << endl;
	}

}

void Fleet::printPlaneInventory()
{
	map<string, Plane*>::iterator it = planes.begin();

	cout << setfill('-') << setw(125) << "-" << endl;
    cout << setfill(' ') << setw(15) << left << "Tail Number";
    cout << setw(30) << left << "Make";
    cout << setw(20) << left << "Model";
    cout << setw(20) << left << "Seats";
    cout << setw(20) << left << "Range";
    cout << setw(20) << left << "Status" << endl;
    cout << setfill('-') << setw(125) << "-" << endl;
   
	while(it != planes.end())
	{
		(it->second)->printPlaneDetails();
		it++;
	}
}

void Fleet::printPlaneDetails(string tailNum)
{
    cout << setfill('-') << setw(125) << "-" << endl;
    cout << setfill(' ') << setw(15) << left << "Tail Number";
    cout << setw(30) << left << "Make";
    cout << setw(20) << left << "Model";
    cout << setw(20) << left << "Seats";
    cout << setw(20) << left << "Range";
    cout << setw(20) << left << "Status" << endl;
    cout << setfill('-') << setw(125) << "-" << endl;

	if(planes.find(tailNum) != planes.end())
	{
		planes[tailNum]->printPlaneDetails();
	}
	else
	{
		cout << "No plane found with tailNum " << tailNum << "." << endl;
	}
}


void Fleet::saveData(ofstream& os)
{
    os << planes.size() << endl;
    map<string, Plane*>::iterator it = planes.begin();
	while(it != planes.end())
    {
    	Plane *plane = it->second;

        os << plane->getTailNum() << ',' << plane->getMake() << ','
        	<< plane->getModel() << ',' << plane->getNumSeats() << ','
        	<< plane->getRange() << ',' << plane->getStatus() << endl;
        it++;
 		// Save each plane's scheduled intervals
    	
    	os << plane->getScheduledIntervals().size() << endl;

    	for (int i=0; i <  plane->getScheduledIntervals().size(); i++)
    	{
    		os << plane->getScheduledIntervals()[i].getID() << ","
    		   << plane->getScheduledIntervals()[i].getStartTimeStr() << "," 
               << plane->getScheduledIntervals()[i].getStartZone()  << ","
    		   << plane->getScheduledIntervals()[i].getFinishTimeStr() << "," 
               << plane->getScheduledIntervals()[i].getFinishZone() << endl;
    	}

    }
    //cout << "Saved " << planes.size() << " planes to the flight schedule file." << endl;
}


void Fleet::loadData(ifstream& is)
{
    string tailNum;
    string make;
    string model;
    int numSeats;
    int range;
    string status;
    string ID;
    string start_time;
    string start_zone;
    string finish_time;
    string finish_zone;
    Interval scheduledInterval;

    int tempCount = 0;
    int intervalCount = 0;
    
    is >> tempCount;
    is.get();
    for(int i = 0; i < tempCount; i++)
    {
        getline(is, tailNum, ',');
        getline(is, make, ',');
        getline(is, model, ',');
        is >> numSeats;
        is.get(); // eat the newline at the end;
        is >> range;
        is.get();
        getline(is, status);
        
        Plane* plane = new Plane();
        plane->setTailNum(tailNum);
        plane->setMake(make);
        plane->setModel(model);
        plane->setRange(range);
        plane->setNumSeats(numSeats);

    	is >> intervalCount;
        is.get();
        for(int j = 0; j < intervalCount; j++)
        {
        	getline(is, ID, ',');
        	getline(is, start_time, ',');
            getline(is, start_zone, ',');
        	getline(is, finish_time, ',');
            getline(is, finish_zone);
        	scheduledInterval.setID(ID);
        	scheduledInterval.setStartTime(start_time, start_zone);
    		scheduledInterval.setFinishTime(finish_time, finish_zone);
        	plane->scheduleForFlight(scheduledInterval);
        }

        plane->setStatus(status);
        addPlane(plane);
    }
    cout << "Loaded " << tempCount << " planes from the flight schedule file." << endl;

}


