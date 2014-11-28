#ifndef Lift_H
#define Lift_H

#include <iostream>

using namespace std;
class Lift {
public:
	Lift(int, int, int, int, int, int, bool);
	int getID();
	void setID(int);
	int getWLimit();
	void setWLimit(int);
	int getMinFloor();
	void setMinFloor(int);
	int getMaxFloor();
	void setMaxFloor(int);
	int getFloor();
	void setFloor(int);
	int getDirection();
	void setDirection(int);
	vector<int> getNextDests();
	void updateNextDests(vector<int>);
//		bool areDoorsOpen();
//		void setDoorsOpen(bool);
private:
	vector<int> nextDests;
	int ID;
	int wLimit;
	int minFloor;
	int maxFloor;
	int floor;
	int direction;
	bool doorsOpen;
//		int speed;
//		int failureRate;

};
#endif
