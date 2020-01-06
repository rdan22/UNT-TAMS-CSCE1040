
all: a.out

clean: 
	rm -f a.out *.o

a.out : CrewMember.o Pilot.o CoPilot.o Cabin.o Fleet.o Flight.o FlightSchedule.o AirlineStaff.o Plane.o Interval.o main.cpp
	g++ main.cpp Plane.o Interval.o CrewMember.o Pilot.o CoPilot.o Cabin.o Fleet.o Flight.o FlightSchedule.o AirlineStaff.o

Interval.o: Interval.h Interval.cpp
	g++ -c Interval.cpp

Plane.o: Plane.h Plane.cpp
	g++ -c Plane.cpp

CrewMember.o: CrewMember.h CrewMember.cpp
	g++ -c CrewMember.cpp

Pilot.o: Pilot.h Pilot.cpp
	g++ -c Pilot.cpp

CoPilot.o: CoPilot.h CoPilot.cpp
	g++ -c CoPilot.cpp

Cabin.o: Cabin.h Cabin.cpp
	g++ -c Cabin.cpp

Fleet.o: Fleet.h Fleet.cpp
	g++ -c Fleet.cpp

Flight.o: Flight.h Flight.cpp
	g++ -c Flight.cpp

FlightSchedule.o: FlightSchedule.h FlightSchedule.cpp
	g++ -c FlightSchedule.cpp

AirlineStaff.o: AirlineStaff.h AirlineStaff.cpp
	g++ -c AirlineStaff.cpp


