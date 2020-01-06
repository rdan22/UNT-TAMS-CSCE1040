/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 5
Airline Scheduling System
*/
//This is the main.cpp
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "AirlineStaff.h"
#include "Pilot.h"
#include "CoPilot.h"
#include "Cabin.h"
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
    Pilot           *pilot;
    CoPilot         *copilot;
    Cabin           *cabin;
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
    string  position;
    string  ratingCode;
    int     cumulativeFlightHours;
    string  ID;
    int     numSeats;
    int     numPassengers;
    string  start_date;
    string  start_time;
    string  end_date;
    string  end_time;
    string  start_code;
    string  end_code;
    bool badChoice = true;

    string  fileName = "flightschedule.dat";
    ofstream outputFlightSchedule;
    ifstream inputFlightSchedule;

    //setenv("TZ","UTC",1); // All times are to be interpreted as GMT


    cout << 
    "  +-------------------------------------------------------------------+\n"
    "  |              Computer Science and Engineering                     |\n"
    "  |         CSCE 1040 - Computer Science II  (Homework 5)             |\n"
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

                cout << "Enter type (Pilot, CoPilot or Cabin):" << endl;
                getline(cin, type);
                cout << "Enter Crew ID:" << endl;
                getline(cin, ID);
                cout << "Enter name:" << endl;
                getline(cin, name);
                cout << "Enter status (available, on-leave or sick):" << endl;
                getline(cin, status);
                //depending on the crew type, allocate the corresponding derived class object
                if (type == "Pilot")
                {
                    //validate pilot 5 character code
                    cout << "Enter a 5 character rating code for the Pilot:" << endl;
                    while(badChoice)
                    {
                        getline(cin, ratingCode);
                        if(ratingCode.length() != 5)
                        {
                            cout << "Invalid code entered. Please enter a five character rating code for the pilot: " << endl;
                        }
                        else
                        {
                            badChoice = false;
                        }
                    }
                    cout << "Enter cumulative flight hours:" << endl;
                    cin >> cumulativeFlightHours;
                    cin.get();

                    pilot = new Pilot();
                    pilot->setID(ID);
                    pilot->setName(name);
                    pilot->setStatus(status);
                    pilot->setRatingCode(ratingCode);
                    pilot->setCumulativeFlightHours(cumulativeFlightHours);
                    airlineStaff.addCrewMember(pilot);
                    updateFile = true;

                }
                else
                if (type == "CoPilot")
                {
                    //validate copilot 4 character code
                    badChoice = true;
                    cout << "Enter a 4 character rating code for the CoPilot:" << endl;
                    while(badChoice)
                    {
                        getline(cin, ratingCode);
                        if(ratingCode.length() != 4)
                        {
                            cout << "Invalid code entered. Please enter a four character rating code for the pilot: " << endl;
                        }
                        else
                        {
                            badChoice = false;
                        }
                    }
                    cout << "Enter cumulative flight hours:" << endl;
                    cin >> cumulativeFlightHours;
                    cin.get();

                    copilot = new CoPilot();
                    copilot->setID(ID);
                    copilot->setName(name);
                    copilot->setStatus(status);
                    copilot->setRatingCode(ratingCode);
                    copilot->setCumulativeFlightHours(cumulativeFlightHours);
                    airlineStaff.addCrewMember(copilot);
                    updateFile = true;
                }
                else
                if (type == "Cabin" )
                {
                    cout << "Enter the position for Cabin (First Class, Business Class, Economy Front, Economy Rear, Lead):" << endl;
                    getline(cin, position);
                    cabin = new Cabin();
                    cabin->setID(ID);
                    cabin->setName(name);
                    cabin->setStatus(status);
                    cabin->setPosition(position);
                    airlineStaff.addCrewMember(cabin);
                    updateFile = true;
                }
                else
                {
                    cout << "Invalid crew type specified. Must be Pilot, CoPilot or Cabin. Please try again." << endl;
                    updateFile = false;
                }
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
    string  start_zone = "";
    string  end_date = "";
    string  end_time = "";
    string  end_zone = "";
    string  start_code;
    string  end_code;
    string  planeID;
    string  pilotID;
    string  copilotID;
    vector<string> crewIDs;

    //getting info from user
    cout << "Enter start date (MM-DD-YYYY):" << endl;
    getline(cin, start_date);
    cout << "Enter start time (HH:MM):" << endl;
    getline(cin, start_time);

    cout << "Enter start time zone (e.g. America/Chicago, America/New_York, America/Los_Angeles etc..):" << endl;
    getline(cin, start_zone);

    cout << "Enter end date (MM-DD-YYYY):" << endl;
    getline(cin, end_date);
    cout << "Enter end time (HH:MM):" << endl;
    getline(cin, end_time);
    cout << "Enter end time zone (e.g. America/Chicago, America/New_York, America/Los_Angeles etc..):" << endl;
    getline(cin, end_zone);


    cout << "Enter starting airport code:" << endl;
    getline(cin, start_code);
    cout << "Enter ending airport code:" << endl;
    getline(cin, end_code);

    cout << "Enter passenger count:" << endl;
    cin >> numPassengers;
    cin.get();

    // First create a flight interval using supplied dates and times
    flightInterval.setStartTime(start_date + " " + start_time, start_zone);
    flightInterval.setFinishTime(end_date + " " + end_time, end_zone);

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

    copilotID = staff.findAvailableCoPilot(flightInterval);

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
    flight->setCoPilotID(copilotID);
    flight->setCabinCrewIDs(crewIDs);
    flight->setStartDate(start_date);
    flight->setStartTime(start_time);
    flight->setStartTZ(start_zone);
    flight->setEndDate(end_date);
    flight->setEndTime(end_time);
    flight->setEndTZ(end_zone);
    flight->setNumPassengers(numPassengers);
    flight->setStartingCode(start_code);
    flight->setEndingCode(end_code);
    flight->setInterval(flightInterval); // needed for associating scheduled crew, plane
    flight->setStatus("SCHEDULED");

    flightSchedule.addFlight(flight); // add flight to schedule;
    cout << "Scheduled a new flight " << planeID << " departing from " << start_code 
         << " at " << start_date << " " << start_time  << " " << start_zone << " arriving at " 
         << end_code << end_date << " " << end_time << " " << end_zone << endl;

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

    // Go through the flight schedule to determine which flights were completed based
    // the current time, and fetch the list of completed flights
    completedFlights = flightSchedule.getCompletedFlights();

    it = completedFlights.begin();

    // For each of the completed flights, make the plane, and crew members available
    // for scheduling.
    while(it!=completedFlights.end())
    {
        Flight *flight = *it;
        flightInterval = flight->getInterval();

        fleet.makePlaneAvailable(flight->getPlaneID(), flightInterval);
        
        staff.makeCrewMemberAvailable(flight->getPilotID(), flightInterval);

        staff.makeCrewMemberAvailable(flight->getCoPilotID(), flightInterval);

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

        // Finally, delete the completed flight from the flight schedule.
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

    
    // Given the plane ID, delete the flight and make the plane and crew available
    // for scheduling if the flight is not ACTIVE.
    //
    flightInterval = flight->getInterval();

    fleet.makePlaneAvailable(flight->getPlaneID(), flightInterval);
        
    staff.makeCrewMemberAvailable(flight->getPilotID(), flightInterval);

    staff.makeCrewMemberAvailable(flight->getCoPilotID(), flightInterval);

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

