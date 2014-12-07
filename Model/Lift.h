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
	void setPriority();
	int performMove(int);
    bool areDoorsOpen();
    void setDoors(bool);
    void checkPriority(int,int);
    void setPriorityList(int,int);
    vector<int> firstPriorityList;
    struct secondPriorityItem{
        int dir;
        int floorNum;
    }secondPriorityitem;
	vector<secondPriorityItem> secondPriorityList;
	bool isMoving;
    void mergeTwoList(vector<int>,vector<secondPriorityItem>);

private:

	int ID;
	int wLimit;
	int curWeight;
	int minFloor;
	int maxFloor;
	int floor;
	int direction;
	bool doorsOpen;
	vector <Passenger> passengers;
};
#endif
