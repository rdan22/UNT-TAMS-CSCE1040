/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 5
Airline Scheduling System
*/
#include <iostream>
#include <string>
#include <map>
#include "AirlineStaff.h"
#include "Pilot.h"
#include "CoPilot.h"
#include "Cabin.h"


using namespace std;



AirlineStaff::AirlineStaff()
{

}
//add a crew member to airline staff
void AirlineStaff::addCrewMember(CrewMember *crewMember)
{
	crewMembers[crewMember->getID()] = crewMember;
}

//delete a crew member 
void AirlineStaff::deleteCrewMember(string crewID)
{
	map<string, CrewMember*>::iterator it;
	if((it = crewMembers.find(crewID)) != crewMembers.end())
	{
		CrewMember* crewMember = it->second;
		if(crewMember->getScheduledIntervals().size() > 0)
		{
			cout << "Crew member is already scheduled for a flight. If you wish to delete the crew member, delete the flight first." << endl;
		}
		else
		{
			delete it->second;
                	crewMembers.erase(crewID);
		}
	}
	else
	{
		cout << "No crew member found with crew ID " << crewID << "." << endl;
	}
}


void AirlineStaff::updateCrewMemberStatus(string crewID, string status)
{
	if(crewMembers.find(crewID) != crewMembers.end())
	{
		crewMembers[crewID]->setStatus(status);
	}
	else
	{
		cout << "No crew member found with crew ID " << crewID << "." << endl;
	}
}

//find an available pilot
string AirlineStaff::findAvailablePilot(Interval requestedInterval)
{
	string PilotID = "";

	map<string, CrewMember*>::iterator it = crewMembers.begin();
	
	while(it != crewMembers.end())
	{
		if (((it->second)->getType() == "Pilot") && ((it->second)->getStatus() == "available"))
		{
			if ((it->second)->checkAvailability(requestedInterval))
			{
				PilotID =  (it->second)->getID();
				break;
			}
		}
		it++;
	}
	return PilotID;
}

//find available CoPilot
string AirlineStaff::findAvailableCoPilot(Interval requestedInterval)
{
	string CoPilotID = "";

	map<string, CrewMember*>::iterator it = crewMembers.begin();
	
	while(it != crewMembers.end())
	{
		if (((it->second)->getType() == "CoPilot") && ((it->second)->getStatus() == "available"))
		{
			if ((it->second)->checkAvailability(requestedInterval))
			{
				CoPilotID = (it->second)->getID();
				break;
			}
		}
		it++;
	}
	return CoPilotID;
}

//find available cabin crew members
vector<string> AirlineStaff::findAvailableCabinCrewMembers(Interval requestedInterval)
{
	map<string, CrewMember*>::iterator it = crewMembers.begin();
	vector<string> crewIDs;

	while(it != crewMembers.end())
	{
		if (((it->second)->getType() == "Cabin") && ((it->second)->getStatus() == "available"))
		{
			if ((it->second)->checkAvailability(requestedInterval))
			{
				crewIDs.push_back((it->second)->getID());

				if (crewIDs.size() == 3)
					break;	// Stop once 3 available cabin crew are found.
			}
		}
		it++;
	}

	return crewIDs;
}

//schedule a crew member for a flight
void AirlineStaff::scheduleCrewMemberForFlight(string crewID, Interval requestedInterval)
{
	if(crewMembers.find(crewID) != crewMembers.end())
	{
		crewMembers[crewID]->scheduleForFlight(requestedInterval);
	}
	else
	{
		cout << "No crew member found with crew ID " << crewID << "." << endl;
	}
}

//make a crew member available
void AirlineStaff::makeCrewMemberAvailable(string crewID, Interval interval)
{
	if(crewMembers.find(crewID) != crewMembers.end())
	{
		crewMembers[crewID]->makeAvailable(interval);
	}
	else
	{
		cout << "No crew member found with crewID " << crewID << endl;
	}

}

//schedule the crew for a flight
void AirlineStaff::scheduleCrewForFlight(vector<string> crewIDs, Interval requestedInterval)
{
	vector<string>::iterator it = crewIDs.begin();

	while (it != crewIDs.end())
	{
		string crewID = *it;
		
		if(crewMembers.find(crewID) != crewMembers.end())
		{
			crewMembers[crewID]->scheduleForFlight(requestedInterval);
		}
		else
		{
			cout << "No crew member found with crew ID " << crewID << "." << endl;
		}
		it++;
	}
}


void AirlineStaff::printStaff()
{
	map<string, CrewMember*>::iterator it = crewMembers.begin();

   	cout << setfill('-') << setw(145) << "-" << endl;
    cout << setfill(' ') << setw(15) << left << "Crew ID";
    cout << setw(30) << left << "Crew Member Name";
    cout << setw(20) << left << "Crew Type";
    cout << setw(20) << left << "Status" ;
    cout << setw(20) << left << "Rating Code";
    cout << setw(25) << left << "Cumulative Flight Hrs";
    cout << setw(20) << left << "Position" << endl;
    cout << setfill('-') << setw(145) << "-" << endl;
   
	while(it != crewMembers.end())
	{
		(it->second)->PrintInfo();
		it++;
	}
}


void AirlineStaff::printStaffDetails(string crewID)
{
	cout << setfill('-') << setw(145) << "-" << endl;
    cout << setfill(' ') << setw(15) << left << "Crew ID";
    cout << setw(30) << left << "Crew Member Name";
    cout << setw(20) << left << "Crew Type";
    cout << setw(20) << left << "Status" ;
    cout << setw(20) << left << "Rating Code";
    cout << setw(25) << left << "Cumulative Flight Hrs";
    cout << setw(20) << left << "Position" << endl;
    cout << setfill('-') << setw(145) << "-" << endl;

	if(crewMembers.find(crewID) != crewMembers.end())
	{
		crewMembers[crewID]->PrintInfo();
	}
	else
	{
		cout << "No crew members found with crew ID " << crewID << "." << endl;
	}
}

void AirlineStaff::saveData(ofstream& os)
{
    os << crewMembers.size() << endl;
    map<string, CrewMember*>::iterator it = crewMembers.begin();
	while(it != crewMembers.end())
    {
    	CrewMember *crewMember = it->second;

    	// Write out the common (base class) attributes first
        os << crewMember->getID() << ',' << crewMember->getName() << ','
        	<< crewMember->getType() << ',' << crewMember->getStatus();

		if (crewMember->getType() == "Pilot")
		{
			Pilot* pilot = (Pilot *) crewMember;
			os << "," << pilot->getRatingCode() << "," << pilot->getCumulativeFlightHours() << endl;
		}        
		else if (crewMember->getType() == "CoPilot")
		{
			CoPilot* copilot = (CoPilot *) crewMember;
			os << "," << copilot->getRatingCode() << "," << copilot->getCumulativeFlightHours() << endl;
		}
		else if (crewMember->getType() =="Cabin")
		{
			Cabin* cabin = (Cabin *) crewMember;
			os << "," << cabin->getPosition() << endl;
		}

        it++;
    
    	// Save each members scheduled intervals
    	
    	os << crewMember->getScheduledIntervals().size() << endl;

    	for (int i=0; i <  crewMember->getScheduledIntervals().size(); i++)
    	{
    		os << crewMember->getScheduledIntervals()[i].getID() << ","
    		   << crewMember->getScheduledIntervals()[i].getStartTimeStr() << "," 
    		   << crewMember->getScheduledIntervals()[i].getStartZone() << ","
    		   << crewMember->getScheduledIntervals()[i].getFinishTimeStr() << ","
    		   << crewMember->getScheduledIntervals()[i].getFinishZone() << endl;
    	}

    }
    //cout << "Saved " << crewMembers.size() << " crew members to the flight schedule file." << endl;

}

void AirlineStaff::loadData(ifstream& is)
{
    string crewID;
    string name;
    string type;
    string status;
    string ID;
    string ratingCode;
    int cumulativeFlightHours;
    string position;
    string start_time;
    string start_zone;
    string finish_time;
    string finish_zone;
    Interval scheduledInterval;
    CrewMember *cm;

    int tempCount = 0;
    int intervalCount = 0;

    is >> tempCount;
    is.get();
    for(int i = 0; i < tempCount; i++)
    {
        getline(is, crewID, ',');
        getline(is, name, ',');
        getline(is, type, ',');
        getline(is, status, ',');
		
		if (type == "Pilot")
		{
			Pilot* pilot = new Pilot();
			pilot->setID(crewID);
			pilot->setName(name);
			pilot->setStatus(status);
			getline(is,ratingCode,',');
			pilot->setRatingCode(ratingCode);
			is >> cumulativeFlightHours;
			is.get();
			pilot->setCumulativeFlightHours(cumulativeFlightHours);
			cm = pilot;
		}
		else if (type == "CoPilot")
		{
			CoPilot *copilot = new CoPilot();
			copilot->setID(crewID);
			copilot->setName(name);
			copilot->setStatus(status);
			getline(is,ratingCode,',');
			copilot->setRatingCode(ratingCode);
			is >> cumulativeFlightHours;
			is.get();
			copilot->setCumulativeFlightHours(cumulativeFlightHours);
			cm = copilot;

		}
		else if (type == "Cabin")
		{
			Cabin *cabin = new Cabin();
			cabin->setID(crewID);
			cabin->setName(name);
			cabin->setStatus(status);
			getline(is,position);
			cabin->setPosition(position);
			cm = cabin;
		}
    	        
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
        	cm->scheduleForFlight(scheduledInterval);
        }
        
        addCrewMember(cm);
    }
    cout << "Loaded " << tempCount << " crew members from the flight schedule file." << endl;

}

