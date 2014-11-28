#ifndef Model_H
#define Model_H

#include <vector>
#include <iostream>
#include "Passenger.h"
#include "Lift.h"
#include "Button.h"

using namespace std;
class Model {
public:
	Model(vector<string>, vector<string>);
	vector<Lift> lifts;
	vector<Passenger> passengers;
	vector<Button> buttons;
	void update();
	bool isChanged();
	void setChanged(bool);
private:
	void addLift(string);
	void addPsgr(string);
	void addButtons();
	void getMinFloor();
	void getMaxFloor();
	bool changed;
	int liftCount;
	int minFloor;
	int maxFloor;
};
