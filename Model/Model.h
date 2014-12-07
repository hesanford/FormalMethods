#ifndef MODEL_H_
#define MODEL_H_
#include <vector>
#include <iostream>
#include "Passenger.h"
#include "Lift.h"
#include "internalButton.h"
#include "externalButton.h"
#include <list>
using namespace std;
class Model {
public:
	Model(vector<string>, vector<string>);

	void update(bool);
	bool isChanged();
	void setChanged(bool);
	void addLift(string);
	void addPsgr(string);
	void addButtons();
	void setCallingDirList ();
	int getMinFloor();
	int getMaxFloor();
	//vector <internalButton> getInternalButtons();
	//vector <externalButton> getExternalButtons();
	vector<Lift> lifts;
	vector<Passenger> passengers;
	vector <internalButton> inButtons;
	vector <externalButton> extButtons;
    //vector<Passenger> RelativePassengers;
    //vector<Passenger> getRelativePassengers(int);
    vector<Lift> getLifts();
    Lift getLift(int);

    typedef struct CallingMessage{
            int dir;
            int onFloor;
    }CallingMessage;
    vector<CallingMessage> CallingDirList;




private:
	bool changed;
	int liftCount;
	int minFloor;
	int maxFloor;

	vector <Passenger> ChangedPassengers();
	vector <Lift> ChangedLifts();
};
#endif /* MODEL_H_ */
