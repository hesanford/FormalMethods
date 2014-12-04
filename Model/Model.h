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
	int getMinFloor();
	int getMaxFloor();
	vector <internalButton> getInternalButtons();
	vector <externalButton> getExternalButtons();
	std::list <externalButton> CallingFloorList();
	std::list <Passenger> ChangedPassengers();
	std::list <Lift> ChangedLifts();
private:
	bool changed;
	int liftCount;
	int minFloor;
	int maxFloor;
	vector<Lift> lifts;
	vector<Passenger> passengers;
	vector<internalButton> intButtons;
	vector<externalButton> extButtons;
};
#endif /* MODEL_H_ */
