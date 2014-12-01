#ifndef MODEL_H_
#define MODEL_H_
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
	void update(bool);
	bool isChanged();
	void setChanged(bool);
	void addLift(string);
	void addPsgr(string);
	void addButtons();
	int getMinFloor();
	int getMaxFloor();
private:
	bool changed;
	int liftCount;
	int minFloor;
	int maxFloor;
};
#endif /* MODEL_H_ */
