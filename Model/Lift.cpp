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
	floor = curF;		//initialize with 0 ?
	direction = dir;	//initilaize with 0 ?	can be 1 (up), -1(down), 0 (idle);
	doorsOpen = dOpen;	//initialize with true?
}

void Lift::performStep() {
	//needs a lot of rework; weight etc.
	if (!doorsOpen) {
		floor = floor + direction;
		if (floor == firstPriorityList.at(0)) {
			firstPriorityList.erase(firstPriorityList.begin());
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
void Lift::setWLimit(int w) {
	wLimit=w;
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
void Lift::setMinFloor(int minf) {
	minFloor=minf;
}
int Lift::getMaxFloor() {
	return maxFloor;
}
void Lift::setMaxFloor(int maxf) {
	maxFloor=maxf;
}

int Lift::getFloor() {
	return floor;
}
void Lift::setFloor(int f) {
floor=f;
}

int Lift::getDirection() {
	return doorsOpen;
}
void Lift::setDirection(int dir) {
	direction=dir;
}
bool Lift::areDoorsOpen(){
	return doorsOpen;

}
void Lift::setDoors(bool d)
{
	doorsOpen=d;
}

bool Lift:: checkWeight(){
int check;
check=getWLimit()-getCurWeight();
	if (check>0)
		return 1;
	else
		return 0;
}
