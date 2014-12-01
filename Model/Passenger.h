#ifndef Passenger_H
#define Passenger_H

#include <iostream>

using namespace std;
class Passenger {
public:
	Passenger(int, int, int, string, string);
	void callLift();
	void enterLift(int);
	void exitLift();
	int getWeight();
	void setWeight(int);
	int getFloor();
	void setFloor(int);
	int getDestFloor();
	void setDestFloor(int);
	int getLift();
	void setLift(int);
//		int getTravelFreq();
//		void setTravelFreq(int);
//		struct tm getArrivalTime();
//		void setArrivalTime(String);
//		struct tm getDeptTime();
//		void setDeptTime(String);
private:
	int ID;
	int weight;
	int travelFreq;
	int floor;
	int destinationFloor;
	int currentLift;
	bool idle;
	string tArr;
	string tDept;
};
#endif
