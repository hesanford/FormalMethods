#ifndef MODEL_H_
#define MODEL_H_
#include <vector>
#include <iostream>
#include <fstream>
#include "Passenger.h"
#include "Lift.h"
#include "Clock.h"
#include "internalButton.h"
#include "externalButton.h"

#include <list>
using namespace std;
class Model {
public:
	Model(const char*);
	void update(bool);
	bool isChanged();
	void setChanged(bool);
	void addLift(string);
	void addButtons();
	void setCallingDirList ();
	int getMinFloor();
	int getMaxFloor();
	int getNoLifts();
	void newPsgr();
	void incTime();
	void pressButton(int , int , int );
	vector <internalButton> getInternalButtons();
	vector <externalButton> getExternalButtons();
	vector<Lift> lifts;
	vector<Passenger> passengers;
	vector <internalButton> inButtons;
	vector <externalButton> extButtons;
    vector<Passenger> RelativePassengers;
    vector<Passenger> getRelativePassengers(int);
    vector<Lift> getLifts();
    Lift getLift(int);
    Clock cl;
    typedef struct CallingMessage{
            int dir;
            int onFloor;
    }CallingMessage;
	vector<int> CallingFloors;
	vector<CallingMessage> CallingDirList;
	vector <int> CallingFloorList();

private:
	bool changed;
	int liftCount;
	int minFloor;
	int maxFloor;
	void createDist();
	int calcPoisson();
	int rndWeight();
	int time;
	int pID;
	int lID;
	vector<int> distribution;
	ofstream log;
	vector <Passenger> ChangedPassengers();
	vector <Lift> ChangedLifts();
};
#endif /* MODEL_H_ */
