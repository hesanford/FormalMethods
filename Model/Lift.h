#ifndef Lift_H
#define Lift_H
#include <vector>
#include <iostream>
#include "Passenger.h"

using namespace std;
class Lift {
public:
	Lift(int, int, int, int, int, int, bool);
	int getID();
	void setID(int);
	int getWLimit();
	void setWLimit(int);
	int getCurWeight();
	void setCurWeight(int);
	bool checkWeight();
	int getMinFloor();
	void setMinFloor(int);
	int getMaxFloor();
	void setMaxFloor(int);
	int getFloor();
	void setFloor(int);
	int getDirection();
	void setDirection(int);
	vector <int> getNextDests();
	void updateNextDests(vector<int>);
	void performStep();
    bool areDoorsOpen();
    void setDoors(bool);
private:
	vector<int> firstPriorityList;
	vector<int> secondPriorityList;
	int ID;
	int wLimit;
	int curWeight;
	int minFloor;
	int maxFloor;
	int floor;
	int direction;
	bool doorsOpen;
//		int speed;
//		int failureRate;
	vector <Passenger> passengers;
};
#endif
