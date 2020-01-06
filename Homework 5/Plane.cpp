/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 5
Airline Scheduling System
*/
#include <iostream>
#include <string>
#include "Plane.h"
#include <algorithm>
#include <queue>

using namespace std;


Plane::Plane()
{

}

string Plane::getMake()
{
	return make;
}

void Plane::setMake(string make)
{
	Plane::make = make;
}

string Plane::getModel()
{
	return model;
}

void Plane::setModel(string model)
{
	Plane::model = model;
}

string Plane::getTailNum()
{
	return tailNum;
}

void Plane::setTailNum(string tailNum)
{
	Plane::tailNum = tailNum;
}

int Plane::getNumSeats()
{
	return seats;
}

void Plane::setNumSeats(int seats)
{
	Plane::seats = seats;
}

int Plane::getRange()
{
	return range;
}

void Plane::setRange(int range)
{
	Plane::range = range;
}

string Plane::getStatus()
{
	return status;
}


void Plane::setStatus(string status)
{
	Plane::status = status;
}


//
// Check if the plane is available during requested interval.
// Procedure is as follows:
// 1. Build a vector of busy intervals by taking the vector of already scheduled intervals
//    and adding the requested interval to it.
// 2. Go through all the busy intervals, looking for any overlapping intervals
//    This is done by checking to see if the end-time of previous interval does not overlap
//	  with start time of current interval.
// 3. If after checking all intervals, and no overlaps are found, the plane is available for
//    scheduling.
//
bool Plane::checkAvailability(Interval requestedInterval)
{

	vector<Interval> busyIntervals = scheduledIntervals;
	vector<Interval>::iterator it;
    queue <long> conflicts;
    time_t last_interval_finish_time = {0};
    int i = 0;
    bool isAvail = false;

    // create a set of all busy intervals, including existing schedule and newly 
    // requested interval
    busyIntervals.push_back(requestedInterval);
    // sort all the busy intervals based on time.
    sort(busyIntervals.begin(), busyIntervals.begin()+busyIntervals.size());

  
    // Now go through all the intervals, including the requested one, which have been sorted by time.
    // if any of the  intervals conflict, the resource is not available. Intervals conflict if the
    // previous interval's finish time is not less than current interval's start time.
    for (it=busyIntervals.begin(); it!=busyIntervals.end(); it++)
    {   
        if (comparetime(last_interval_finish_time, (*it).getStartTime()))    
        {
            last_interval_finish_time = (*it).getFinishTime();
        }
        else
        {
            // If an overlap is found, add it to the conflicts queue.
        	conflicts.push(it-busyIntervals.begin());
        }
    }


    // If after analyzing all the intervals, if the conflicts queue size is not equal to 0, 
    // we have atleast one conflicting interval, which indicates that the resource is not available.
    if (conflicts.size()!=0)
    {
        //cout << "Some conflicting durations were found. Following are the overlapping ones" << endl;
    	// while (!conflicts.empty()) 
   		// {
     //    	i = conflicts.front();
     //    	conflicts.pop();
     //    	cout << "Start time: "  << busyIntervals[i].getStartTimeStr() 
     //             << "\t  End time:" << busyIntervals[i].getFinishTimeStr() << endl;
    	// }
        isAvail = false;
    }
    else
    {
        //cout << "Requested duration does not overlap with the existing schedule" << endl;
     //    for (it=scheduledIntervals.begin(); it!=scheduledIntervals.end(); it++)
    	// {
    	// 	cout << "Start time: "  << (*it).getStartTimeStr() 
     //             << "\t  End time:" << (*it).getFinishTimeStr() << endl;
    	// }
        isAvail = true;
    }
    return isAvail;
}

//schedule a plane for a flight
void Plane::scheduleForFlight(Interval requestedInterval)
{
	scheduledIntervals.push_back(requestedInterval);
}
//returns vector fo scheduled intervals
vector <Interval> Plane::getScheduledIntervals()
{
    return scheduledIntervals;
}

void Plane::printPlaneDetails()
{
    cout << setfill(' ') << setw(15) << tailNum;
    cout << setw(30) << make;
    cout << setw(20) << model;
    cout << setw(20) << seats;
    cout << setw(20) << range;
    cout << setw(20) << status << endl;
}

//make plane available
void Plane::makeAvailable(Interval interval)
{
    vector<Interval>::iterator it = scheduledIntervals.begin();

    while (it != scheduledIntervals.end())
    {
        if (((*it).getID() == interval.getID()) &&
            ((*it).getStartTime() == interval.getStartTime())&&
            ((*it).getFinishTime() == interval.getFinishTime()))
        {
            it = scheduledIntervals.erase(it);
        }
        else
        {
            it++;
        }
    }
}
