#include <iostream>
#include <cstdlib>
#include "Passenger.h"

using namespace std;
Passenger::Passenger(int identity, int w, int f, int dest) {
	ID = identity;
	weight = w;
	floor = f;
	destinationFloor = dest;
	currentLift = 0;
}

//gets called on each clock tick
//if psgr is idle, random chance to call for an elevator
/*void Passenger::callLift() {
	if (idle) {
		int i = rand() % 100;
		if (i <= travelFreq) {
			idle = false;
			//checkLiftOnFloor
			//else push call button
		}
	}
}

*/


int Passenger::getWeight() {
	return weight;
}

//gets called after passenger creation to determine which button should be pressed
int Passenger::getDirection() {
	if (floor < destinationFloor){
		return 1;
	}
	if (floor > destinationFloor){
		return -1;
	}
	else return 0;
}

int Passenger::getFloor() {
	return floor;
}
void Passenger::setFloor(int f) {
	floor = f;
}
int Passenger::getDestFloor() {
	return destinationFloor;
}
void Passenger::setDestFloor(int d) {
	destinationFloor = d;
}
int Passenger::getLift() {
	return currentLift;
}
void Passenger::setLift(int l) {
	currentLift = l;
}

