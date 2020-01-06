/*
Author: Riya Danait
Email: RiyaDanait@my.unt.edu
Homework 5
Airline Scheduling System
*/
//derived class which inherits from the base class CrewMember
#include <string>
#include "Cabin.h"
#include <iostream>

Cabin::Cabin()
{

}
string Cabin::getPosition()
{
	return position;
}
void Cabin::setPosition(string position)
{
	Cabin::position = position;
}
void Cabin::PrintInfo()
{
	//overrides the printinfo function
	CrewMember::PrintInfo();
	cout << setw(45) << " ";
	cout << setw(20) << position << endl;
}