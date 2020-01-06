/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 4
Airline Scheduling System
*/
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include "CrewMember.h"
using namespace std;

CrewMember::CrewMember()
{

}

string CrewMember::getName()
{
	return name;
}

void CrewMember::setName(string name)
{
	CrewMember::name = name;
}

string CrewMember::getID()
{
	return ID;
}
void CrewMember::setID(string ID)
{
	CrewMember::ID = ID;
}

string CrewMember::getType()
{
	return type;
}

void CrewMember::setType(string type)
{
	CrewMember::type = type;
}

string CrewMember::getStatus()
{
	return status;
}

void CrewMember::setStatus(string status)
{
	CrewMember::status = status;
}
	

/* 
Check if the CrewMember is available during requested interval.
Procedure is as follows:
1. Build a vector of busy intervals by taking the vector of already scheduled intervals
and adding the requested interval to it.
2. Go through all the busy intervals, looking for any overlapping intervals
This is done by checking to see if the end-time of previous interval does not overlap with start time of current interval.
3. If after checking all intervals, and no overlaps are found, the plane is available for scheduling. 
*/
bool CrewMember::checkAvailability(Interval requestedInterval)
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
        isAvail = false;
    }
    else
    {
        isAvail = true;
    }
    return isAvail;
}

//schedule a crew member for a flight
void CrewMember::scheduleForFlight(Interval requestedInterval)
{
	scheduledIntervals.push_back(requestedInterval);
}

vector <Interval> CrewMember::getScheduledIntervals()
{
    return scheduledIntervals;
}

void CrewMember::printCrewMemberDetails()
{
    cout << setfill(' ') << setw(15) << ID;
    cout << setw(30) << name;
    cout << setw(20) << type;
    cout << setw(20) << status << endl;
}

void CrewMember::makeAvailable(Interval interval)
{
    vector<Interval>::iterator it = scheduledIntervals.begin();

    while (it != scheduledIntervals.end())
    {
        // find matching interval and remove it 
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

