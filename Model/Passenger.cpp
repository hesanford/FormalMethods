#include <iostream>
#include <cstdlib>
#include "Passenger.h"

using namespace std;
/*
The passengers requirements
*@param integer floor
*@param integer weight
*@param integer destination floor
*@param integer current lift
*@return integer floor
*@return  integer weight
*@@return integer destination floor
*@@return integer current lift
*/
Passenger::Passenger(int identity, int w, int f, string tArr, string tDept) /*Passenger constructor*/
{
	ID = identity;
	weight = w;
	travelFreq = f;
	floor = 0;
	currentLift = 0;
	destinationFloor = 0;
	idle = true;
}

//gets called on each clock tick
//if passenger is idle, random chance to call for an elevator
void Passenger::callLift() {
	if (idle) {
		int i = rand() % 100;
		if (i <= travelFreq) {
			idle = false;
			//checkLiftOnFloor
			//else push call button
		}
	}
}

/*The passenger enters the lift */
 void Passenger::enterLift(int l_id)
 {
	 currentLift = l_id;
 }

 /*Exit the lift if the passenger is idle*/
 void Passenger::exitLift()
 {
	 currentLift = 0;
	 idle = true;
 }

 int Passenger::getWeight()                            /*@param get the weight of the passenger*/
{
	return weight;                                     /*@return the value of the weight */
}
void Passenger::setWeight(int w)                       /*the weight is set */
{
	weight = w;                                       /*@param assign the weight of the passenger*/
}
int Passenger::getFloor()                             /*@param get the floor the passenger is on*/
{
	return floor;                                    /*@return the floor */
}
void Passenger::setFloor(int f)                     /*@param set the floor */
{
	floor = f;                                     /*@param assign and reseve the floor */
}
int Passenger::getDestFloor()                     /*get the destination floor the passenger want to go*/
{
	return destinationFloor;                     /*@return the destination floor*/
}
void Passenger::setDestFloor(int d)             /*@param set the destination floor*/
{
	destinationFloor = d;                      /*assign the destination floor*/
}
int Passenger::getLift()                       /*get the lift when passenger calls*/
{
	return currentLift;                        /*@return the current lift*/
}
void Passenger::setLift(int l)                 /*set the lift */
{
	currentLift = l;                           /*@param assign the current lift*/
}
