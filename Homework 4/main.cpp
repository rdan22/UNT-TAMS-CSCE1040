/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 4
Airline Scheduling System
*/
//This is the main.cpp
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "AirlineStaff.h"
#include "CrewMember.h"
#include "Fleet.h"
#include "Flight.h"
#include "FlightSchedule.h"
#include "Plane.h"

using namespace std;


// Flight scheduling transaction 
bool scheduleAFlight(FlightSchedule& flightSchedule,Fleet& fleet, AirlineStaff& staff);

// For updating entire flight schedule based on time.
void updateAllFlights(FlightSchedule& flightSchedule,Fleet& fleet, AirlineStaff& staff);

// For deleting a SCHEDULED, COMPLETED or CANCELED flight
bool deleteAFlight(string planeID, FlightSchedule& flightSchedule,Fleet& fleet, AirlineStaff& staff);

int main() {
    //variables
    int choice;
    char quitChoice;
    FlightSchedule  flightSchedule;
    Fleet           fleet;
    AirlineStaff    airlineStaff;
    Plane           *plane;
    CrewMember      *crewMember;
    Flight          *flight;

    // Temporary variables for reading in Plane, Crew and Flight details from user input
    string  tailNum;
    string  planeID;
    string  make;
    string  model;
    int     range;
    string  status;
    string  name;
    string  type;
    string  startingCode;
    string  endingCode;
    string  ID;
    int     numSeats;
    int     numPassengers;
    string  start_date;
    string  start_time;
    string  end_date;
    string  end_time;
    string  start_code;
    string  end_code;

    string  fileName = "flightschedule.dat";
    ofstream outputFlightSchedule;
    ifstream inputFlightSchedule;

    setenv("TZ","UTC",1); // All times are to be interpreted as GMT


    


    cout << 
    "  +-------------------------------------------------------------------+\n"
    "  |              Computer Science and Engineering                     |\n"
    "  |         CSCE 1040 - Computer Science II  (Homework 4)             |\n"
    "  |           Riya Danait    rd0305   rd0305@my.unt.edu               |\n"
    "  +-------------------------------------------------------------------+\n";

// open and read in the flight schedule file
    inputFlightSchedule.open(fileName.c_str());

    if (!inputFlightSchedule.fail())
    {
        cout << "Found pre-existing \"flightschedule.dat\" file. Loading data from the file.\n" << endl;
        fleet.loadData(inputFlightSchedule);
        airlineStaff.loadData(inputFlightSchedule);
        flightSchedule.loadData(inputFlightSchedule);
        cout << "\nCompleted loading flight schedule from file " << fileName << endl;
        inputFlightSchedule.close();
    }

    while(1)
    {
        bool updateFile = false;  // flag to update the file if making any changes to entities, so that changes are persisted.

        cout <<
        "\n\n"
        "1. Add a new plane to the fleet \n"
        "2. Add a new crew member to the airline staff \n"
        "3. Add a new flight to the flight schedule \n"
        "4. Update a flight in flight schedule \n"
        "5. Update a crew member \n"
        "6. Update a plane status\n"
        "7. Delete a flight from flight schedule \n"
        "8. Delete a crew member from airline staff \n"
        "9. Delete a plane from fleet \n"
        "10. Print the entire flight schedule \n"
        "11. Print a list of all flights based on status \n"
        "12. Print the details of a single flight in flight schedule \n"
        "13. Print the entire airline staff \n"
        "14. Print details of a single crew member in airline staff\n"
        "15. Print the entire fleet of planes \n"
        "16. Print the details of a plane from the fleet \n"
        "17. Update entire flight schedule based on current time\n"
        "18. Quit \n";
        
        cout << "Please enter choice (1-18): ";

        //error checking
        if ( !(cin >> choice) )
        {
            cin.clear();
            cin.ignore();
            cout << "Incorrect entry. Try again: ";
            continue;
        }
        cin.get();
        //cases for the choices
        switch(choice)
        {
            case 1:
                cout << "ADD A NEW PLANE TO THE FLEET \n" << endl;
                plane = new Plane();
                cout << "Enter tail Number:" << endl;
                getline(cin, tailNum);
                plane->setTailNum(tailNum);
                cout << "Enter make:" << endl;
                getline(cin, make);
                plane->setMake(make);
                cout << "Enter model:" << endl;
                getline(cin, model);
                plane->setModel(model);
                cout << "Enter status (in, out or repair):" << endl;
                getline(cin, status);
                plane->setStatus(status);
                cout << "Enter number of seats:" << endl;
                cin >> numSeats;
                cin.get();
                cout << "Enter range:" << endl;
                cin >> range;
                cin.get();
                plane->setNumSeats(numSeats);
                plane->setRange(range);
                fleet.addPlane(plane);
                updateFile = true;
                break;

            case 2:
                cout << "ADD A CREW MEMBER TO AIRLINE STAFF \n" << endl;
                crewMember = new CrewMember();
                cout << "Enter Crew ID:" << endl;
                getline(cin, ID);
                crewMember->setID(ID);
                cout << "Enter name:" << endl;
                getline(cin, name);
                crewMember->setName(name);
                cout << "Enter type (Pilot, Copilot or CabinCrew):" << endl;
                getline(cin, type);
                crewMember->setType(type);
                cout << "Enter status (available, on-leave or sick):" << endl;
                getline(cin, status);
                crewMember->setStatus(status);
                airlineStaff.addCrewMember(crewMember);
                updateFile = true;

                break;

            case 3:
                cout << "ADD A NEW FLIGHT TO FLIGHT SCHEDULE \n" << endl;
                if (scheduleAFlight(flightSchedule,fleet, airlineStaff))
                {
                    updateFile = true;  // Update the file as we successfully scheduled a flight.
                }
                break;

            case 4:
                cout <<  "UPDATE A FLIGHT IN FLIGHT SCHEDULE \n" << endl;
                cout << "Enter plane ID:" << endl;
                getline(cin, planeID);
                cout << "Enter new flight status (SCHEDULED, ACTIVE, CANCELED or COMPLETED):" << endl;
                getline(cin, status);
                flightSchedule.updateFlightStatus(planeID, status);
                updateFile = true;

                break;

            case 5:
                cout << "UPDATE A CREW MEMBER \n" << endl;
                cout << "Enter crew member ID:" << endl;
                getline(cin, ID);
                cout << "Enter status (available, on-leave or sick):" << endl;
                getline(cin, status);
                airlineStaff.updateCrewMemberStatus(ID,status);
                updateFile = true;

                break;

            case 6:
                cout << "UPDATE A PLANE STATUS\n" << endl;

                cout << "Enter tail number:" << endl;
                getline(cin, tailNum);
                cout << "Enter status (in, out or repair):" << endl;
                getline(cin, status);
                fleet.updatePlaneStatus(tailNum, status);
                updateFile = true;

                break;

            case 7:
                cout << "DELETE A FLIGHT FROM FLIGHT SCHEDULE \n" << endl;
                cout << "Enter plane ID:" << endl;
                getline(cin, planeID);
                deleteAFlight(planeID,flightSchedule, fleet, airlineStaff);
                updateFile = true;

                break;

            case 8:
                cout << "DELETE A CREW MEMBER FROM AIRLINE STAFF \n" << endl;
                cout << "Enter crew member ID:" << endl;
                getline(cin, ID);
                airlineStaff.deleteCrewMember(ID);
                updateFile = true;
                break;

            case 9:
                cout << "DELETE A PLANE FROM FLEET \n" << endl;

                cout << "Enter tail number:" << endl;
                getline(cin, tailNum);
                fleet.deletePlane(tailNum);
                updateFile = true;                
                break;

            case 10:
                cout << "PRINT THE ENTIRE FLIGHT SCHEDULE \n" << endl;
                flightSchedule.printFlightSchedule();
                break;
            
            case 11:
                cout << "PRINT A LIST OF ALL FLIGHTS BASED ON STATUS \n" << endl;
                cout << "Enter flight status (SCHEDULED, ACTIVE, CANCELED or COMPLETED):" << endl;
                getline(cin, status);
                flightSchedule.printFlightDetailsForStatus(status);
                break;

            case 12:
                cout << "PRINT THE DETAILS OF A SINGLE FLIGHT IN FLIGHT SCHEDULE \n" << endl;
                cout << "Enter plane ID:" << endl;
                getline(cin, planeID);
                flightSchedule.printFlightDetails(planeID);
                break;
            
            case 13:
                cout << "PRINT ENTIRE AIRLINE STAFF \n" << endl;
                airlineStaff.printStaff();
                break;

            case 14:
                cout << "PRINT DETAILS OF A SINGLE CREW MEMBER\n" << endl;
                cout << "Enter crew member ID:" << endl;
                getline(cin, ID);
                airlineStaff.printStaffDetails(ID);
                break;
            
            case 15: 
                cout << "PRINT THE ENTIRE FLEET OF PLANES\n" << endl;
                fleet.printPlaneInventory();
                break;

            case 16:
                cout << "PRINT THE DETAILS OF A PLANE FROM THE FLEET \n" << endl;

                cout << "Enter tail number:" << endl;
                getline(cin, tailNum);
                fleet.printPlaneDetails(tailNum);
                break;            

            case 17: 
                cout << "UPDATE ENTIRE FLIGHT SCHEDULE BASED ON CURRENT TIME\n" << endl;
                cout << "This option will update flight status based on current time and \n";
                cout << "will remove all COMPLETED and CANCELED flights from the schedule\n";
                cout << "Do you wish to continue? (Y/N):" ;
                cin >> quitChoice;
                if(toupper(quitChoice) == 'Y')
                {
                    updateAllFlights(flightSchedule, fleet, airlineStaff);
                    updateFile = true;
                }                           
                break;

            case 18:
                cout << "Do you wish to quit? (Y/N):" << endl;
                cin >> quitChoice;
                if(toupper(quitChoice) == 'Y')
                {
                	cout << "Flight schedule was saved to flightschedule.dat." << endl;
                    exit(0);
                }
                else
                {
                    break;
                }               
            default:
                //not valid
                cout << "Invalid choice. Valid choices are (1-18). Please try again." << endl;
                cin.clear();
                break;
        }

        // Check if data file needs to be written to capture any changes
        // This will be the case when adding/deleting/updating planes, crew members and flights.
        if (updateFile)
        {
            outputFlightSchedule.open(fileName.c_str());
            if(outputFlightSchedule.fail())
            {
                cout << "Could not open the file " << fileName << " to save the flight schedule.\n";
            }
            else
            {
                fleet.saveData(outputFlightSchedule);
                airlineStaff.saveData(outputFlightSchedule);
                flightSchedule.saveData(outputFlightSchedule);
                // cout << "Updated flight schedule in file " << fileName << endl;
                outputFlightSchedule.close();
            }
        }
    }
}

// Flight scheduling transaction
// Check for availability of all resources first,
// If Plane, Pilot, CoPilot and Cabin Crew are available for the requested time
// then schedule the Flight. Otherwise abort the transaction.
bool scheduleAFlight(FlightSchedule& flightSchedule,Fleet& fleet, AirlineStaff& staff)
{
    //variables
    Interval flightInterval;
    Flight *flight = NULL;
    int     numPassengers = 0;
    string  start_date = "";
    string  start_time = "";
    string  end_date;
    string  end_time;
    string  start_code;
    string  end_code;
    string  planeID;
    string  pilotID;
    string  copilotID;
    vector<string> crewIDs;

    //getting info from user
    cout << "Enter start date (MM-DD-YYYY):" << endl;
    getline(cin, start_date);
    cout << "Enter start time (HH:MM) in GMT:" << endl;
    getline(cin, start_time);

    cout << "Enter end date (MM-DD-YYYY):" << endl;
    getline(cin, end_date);
    cout << "Enter end time (HH:MM) in GMT:" << endl;
    getline(cin, end_time);

    cout << "Enter starting airport code:" << endl;
    getline(cin, start_code);
    cout << "Enter ending airport code:" << endl;
    getline(cin, end_code);

    cout << "Enter passenger count:" << endl;
    cin >> numPassengers;
    cin.get();

    // First create a flight interval using supplied dates and times
    flightInterval.setStartTime(start_date + " " + start_time);
    flightInterval.setFinishTime(end_date + " " + end_time);

    // Then look for an available plane with right capacity in that interval
    planeID = fleet.findAvailablePlane(numPassengers, flightInterval);

    if (planeID.compare("") == 0)
    {
        cout << "No plane available for the requested time or passenger capacity. Flight cannot be scheduled." << endl;
        return false;
    }
    else
    {
        cout << "Found planeID " << planeID << " for flight." << endl;
    }

    flightInterval.setID(planeID); // store planeID in the interval object

    // Next, Look for crew members for this flight: pilot + copilot + 3 cabin crew members
    pilotID = staff.findAvailablePilot(flightInterval);

    if (pilotID.compare("") == 0)
    {
        cout << "No pilot available at the requested time. Flight cannot be scheduled." << endl;
        return false;
    }
    else
    {
        cout << "Found pilotID " << pilotID << " for flight." << endl;
    }

    copilotID = staff.findAvailableCopilot(flightInterval);

    if (copilotID.compare("") == 0)
    {
        cout << "No copilot available at the requested time. Flight cannot be scheduled." << endl;
        return false;
    }
    else
    {
        cout << "Found copilot ID " << copilotID << " for flight." << endl;
    }

    crewIDs = staff.findAvailableCabinCrewMembers(flightInterval);

    if (crewIDs.size() < 3)
    {
        cout << "Not enough cabin crew members available. Flight cannot be scheduled." << endl;
        return false;
    }
    else
    {
        cout << "Found 3 available cabin crew for flight" << endl;
    }

    // All resources needed are available. Go ahead and schedule the flight
    fleet.schedulePlaneForFlight(planeID, flightInterval);
    staff.scheduleCrewMemberForFlight(pilotID, flightInterval);
    staff.scheduleCrewMemberForFlight(copilotID, flightInterval);
    staff.scheduleCrewForFlight(crewIDs, flightInterval);



    // Create a new Flight object and save it in FlightSchedule for tracking this flight
    flight = new Flight();
    flight->setPlaneID(planeID);
    flight->setPilotID(pilotID);
    flight->setCopilotID(copilotID);
    flight->setCabinCrewIDs(crewIDs);
    flight->setStartDate(start_date);
    flight->setStartTime(start_time);
    flight->setEndDate(end_date);
    flight->setEndTime(end_time);
    flight->setNumPassengers(numPassengers);
    flight->setStartingCode(start_code);
    flight->setEndingCode(end_code);
    flight->setInterval(flightInterval); // needed for associating scheduled crew, plane
    flight->setStatus("SCHEDULED");

    flightSchedule.addFlight(flight); // add flight to schedule;
    cout << "Scheduled a new flight " << planeID << " from " << start_code << " to " << end_code 
         << " at " << start_date << " " << start_time << endl;

    return true;
   
}
       
//
// Go through all flights in the flight schedule
// Get completed flights (Those that aren't marked as ACTIVE) based on current time 
// For each completed or canceled flight, make the plane and crew members available
//
void updateAllFlights(FlightSchedule& flightSchedule,Fleet& fleet, AirlineStaff& staff)
{
    Interval flightInterval;
    vector<Flight*> completedFlights;
    vector<Flight*>::iterator it;
    string planeID;

    completedFlights = flightSchedule.getCompletedFlights();

    it = completedFlights.begin();

    while(it!=completedFlights.end())
    {
        Flight *flight = *it;
        flightInterval = flight->getInterval();

        fleet.makePlaneAvailable(flight->getPlaneID(), flightInterval);
        
        staff.makeCrewMemberAvailable(flight->getPilotID(), flightInterval);

        staff.makeCrewMemberAvailable(flight->getCopilotID(), flightInterval);

        for (int i = 0; i < 3; i++)
        {
            staff.makeCrewMemberAvailable(flight->getCabinCrewIDs()[i], flightInterval);
        }
        cout << "\nRemoving Flight " << flight->getPlaneID() << " from " 
                 << flight->getStartingCode() << " to " 
                 << flight->getEndingCode() 
                 <<  " from flight schedule as it in " 
                 << flight->getStatus() << " state.\n" << endl;

        planeID = flight->getPlaneID();

        flightSchedule.deleteFlight(planeID);

        it++;
    }

}

//
// Given a plane ID, delete the flight and make the resources available for scheduling
// on other flights
//
bool deleteAFlight(string planeID, FlightSchedule& flightSchedule,Fleet& fleet, AirlineStaff& staff)
{
    Interval flightInterval;

    Flight *flight = flightSchedule.findFlight(planeID);

    if (flight == NULL)
    {
        cout << "Flight with plane ID " << planeID << " not found." << endl;
        return false;
    }

    if (flight->getStatus() == "ACTIVE")
    {
        cout << "Flight with plane ID " << planeID << " is currently ACTIVE." << endl;
        cout << "Only SCHEDULED, CANCELED or COMPLETED flights can be deleted." << endl;
        return false;
    }

    
    flightInterval = flight->getInterval();

    fleet.makePlaneAvailable(flight->getPlaneID(), flightInterval);
        
    staff.makeCrewMemberAvailable(flight->getPilotID(), flightInterval);

    staff.makeCrewMemberAvailable(flight->getCopilotID(), flightInterval);

    for (int i = 0; i < 3; i++)
    {
        staff.makeCrewMemberAvailable(flight->getCabinCrewIDs()[i], flightInterval);
    }
    cout << "\nRemoving Flight " << flight->getPlaneID() << " from " 
         << flight->getStartingCode() << " to " 
         << flight->getEndingCode() 
         <<  " from flight schedule. It was in " 
         << flight->getStatus() << " state.\n" << endl;

    planeID = flight->getPlaneID();

    flightSchedule.deleteFlight(planeID);
    return true;
}

