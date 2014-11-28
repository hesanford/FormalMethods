#include <vector>
#include <iostream>
#include "Passenger.h"
#include "Lift.h"
#include "Button.h"
#include "Model.h"

using namespace std;
Model::Model(vector<string> l, vector<string> p) {
	lifts = new vector<Lift>;
	liftCount = l.size();

	for(int i = 0; i < l.size(); i++){
		addLift(l.at(i));
	}
	for(int i = 0; i < p.size(); i++){
		addPsgr(p.at(i));
	}

	minFloor = getMinFloor();
	maxFloor = getMaxFloor();

	addButtons();

	changed = true;
}

void Model::addButtons(){

}
