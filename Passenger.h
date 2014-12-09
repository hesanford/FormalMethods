#ifndef Passenger_H
#define Passenger_H

#include <iostream>

using namespace std;
class Passenger {
public:
	Passenger(int, int, int, int);
	int getDirection();
	int getWeight();
	int getFloor();
	void setFloor(int);
	int getDestFloor();
	void setDestFloor(int);
	int getLift();
	void setLift(int);
private:
	int ID;
	int weight;
	int floor;
	int destinationFloor;
	int currentLift;
};
#endif
