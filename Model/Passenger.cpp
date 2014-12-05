#include <iostream>
#include <cstdlib>
#include "Passenger.h"

using namespace std;
Passenger::Passenger(int identity, int w, int f, string tArr, string tDept) {
	ID = identity;
	weight = w;
	travelFreq = f;
	floor = 0;
	currentLift = 0;
	destinationFloor = 0;
	idle = true;
}

//gets called on each clock tick
//if psgr is idle, random chance to call for an elevator
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


 void Passenger::enterLift(int l_id){
 currentLift = l_id;
 }


 void Passenger::exitLift(){
	 currentLift = 0;
	 idle = true;
 }

int Passenger::getWeight() {
	return weight;
}
void Passenger::setWeight(int w) {
	weight = w;
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
