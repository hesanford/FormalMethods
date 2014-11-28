#include <vector>
#include <iostream>
#include "Passenger.h"
#include "Lift.h"
#include "Button.h"
#include "ExternalButton.h"
#include "Model.h"

using namespace std;
Model::Model(vector<string> l, vector<string> p) {
	lifts = new vector<Lift>;
	passengers = new vector<Passenger>;
	buttons = new vector<Button>;
	liftCount = l.size();

	for (int i = 0; i < l.size(); i++) {
		addLift(l.at(i));
	}
	for (int i = 0; i < p.size(); i++) {
		addPsgr(p.at(i));
	}

	minFloor = getMinFloor();
	maxFloor = getMaxFloor();

	addButtons();

	changed = true;
}

void Model::update(bool onTick) {
	if (onTick) {
		for (int i = 0; i < liftCount; i++) {
			lifts.at(i).performStep();
		}
		for (int i = 0; i < passengers.size(); i++) {
			//implement passengers.at(i).performStep();
		}
	}
	//everything else; update destination lists etc.
}

void Model::addButtons() {
	for (int i = minFloor; i < maxFloor; i++) {
		buttons.insert(new ExternalButton(i, 1));
	}
	for (int i = 0; i < liftCount; i++) {
		int f_min = lifts.at(i).getMinFloor();
		int f_max = lifts.at(i).getMaxFloor();
		for (int j = f_min; j < f_max; j++) {
			buttons.insert(new InternalButton(lifts.at(i).getID(), j));
		}
	}
}

void Model::addLift(string) {
	//TODO split string by comma and parse into lift
}

void Model::addPsgr(string) {
	//TODO split string by comma and parse into passenger
}

int Model::getMinFloor() {
	int re = 0;
	for (int i = 0; i < liftCount; i++) {
		re = min(re, lifts.at(i).getMinFloor());
	}
	return re;

}
int Model::getMaxFloor() {
	int re = 0;
	for (int i = 0; i < liftCount; i++) {
		re = max(re, lifts.at(i).getMaxFloor());
	}
	return re;

}

bool Model::isChanged() {
	return changed;
}
void Model::setChanged(bool c) {
	changed = c;
}
