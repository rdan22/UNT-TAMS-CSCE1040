
all: a.out

clean: 
	rm -f a.out *.o

a.out : CrewMember.o Fleet.o Flight.o FlightSchedule.o AirlineStaff.o Plane.o Interval.o main.cpp
	g++ main.cpp Plane.o Interval.o CrewMember.o Fleet.o Flight.o FlightSchedule.o AirlineStaff.o

Interval.o: Interval.h Interval.cpp
	g++ -c Interval.cpp

Plane.o: Plane.h Plane.cpp
	g++ -c Plane.cpp

CrewMember.o: CrewMember.h CrewMember.cpp
	g++ -c CrewMember.cpp

Fleet.o: Fleet.h Fleet.cpp
	g++ -c Fleet.cpp

Flight.o: Flight.h Flight.cpp
	g++ -c Flight.cpp

FlightSchedule.o: FlightSchedule.h FlightSchedule.cpp
	g++ -c FlightSchedule.cpp

AirlineStaff.o: AirlineStaff.h AirlineStaff.cpp
	g++ -c AirlineStaff.cpp


