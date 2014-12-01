#include <iostream>
#include "Lift.h"
#include <vector>
using namespace std;
Lift::Lift(int identity, int weightLimit, int minF, int maxF, int curF, int dir,
		bool dOpen) {
	ID = identity;
	wLimit = weightLimit;
	curWeight = 0;
	minFloor = minF;
	maxFloor = maxF;
	std::vector<int> nextDests;
	floor = curF;		//initialize with 0 ?
	direction = dir;	//initilaize with 0 ?	can be 1 (up), -1(down), 0 (idle);
	doorsOpen = dOpen;	//initialize with true?
}

void Lift::performStep() {
	//needs a lot of rework; weight etc.
	if (!doorsOpen) {
		floor = floor + direction;
		if (floor == nextDests.at(0)) {
			nextDests.erase(nextDests.begin());
			doorsOpen = true;
		}
	} else {
		doorsOpen = false;
	}
}

int Lift::getID() {
	return ID;
}
void Lift::setID(int identity) {
	ID = identity;
}
int Lift::getWLimit() {
	return wLimit;
}
void Lift::setWLimit(int) {
}

int Lift::getCurWeight(){
	return curWeight;
}

void Lift::setCurWeight(int w){
	curWeight = w;
}

int Lift::getMinFloor() {
	return minFloor;
}
void Lift::setMinFloor(int) {
}
int Lift::getMaxFloor() {
	return maxFloor;
}
void Lift::setMaxFloor(int) {
}

int Lift::getFloor() {
	return direction;
}
void Lift::setFloor(int) {
}

int Lift::getDirection() {
	return doorsOpen;
}
void setDirection(int) {
}
//		bool areDoorsOpen();
//		void setDoorsOpen(bool);
