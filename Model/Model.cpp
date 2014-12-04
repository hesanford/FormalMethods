#include <vector>
#include <iostream>
#include "Passenger.h"
#include "Lift.h"
#include "Button.h"
#include "Model.h"
#include <sstream>
#include <stdio.h>
#include <string.h>

#include "externalButton.h"
#include "internalButton.h"
using namespace std;
Model::Model(vector<string> l, vector<string> p) {
	std::vector<Lift> lifts;
	std:: vector<Passenger> passengers;

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

	setChanged(true);
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
		externalButton a(i,1);
		extButtons.push_back(a);

	}
	for (int i = 0; i < liftCount; i++) {
		int f_min = lifts.at(i).getMinFloor();
		int f_max = lifts.at(i).getMaxFloor();
		for (int j = f_min; j < f_max; j++) {
			{
			internalButton b(lifts.at(i).getID(), j);
			intButtons.push_back(b);
			}
		}
	}
}

void Model::addLift(string new_l) {
	//TODO split string by comma and parse into lift
	vector<string> elements(7);
	int  identity,weightLimit,minF,maxF,curF,dir;
	bool dOpen;
	for (int i=1; i<=7;i++)
		for(int j=0; j<=new_l.size(); j++)
	if (new_l.at(j)==','){
		if (i==1){
			istringstream buffer(elements.at(i));
			buffer >> identity;
		}
		else if (i==2){
			istringstream buffer(elements.at(i));
			buffer >> weightLimit;
		}
		else if(i==3){
			istringstream buffer(elements.at(i));
			buffer >> minF;
		}
		else if(i==4){
			istringstream buffer(elements.at(i));
			buffer >> maxF;

		}
		else if (i==5){
			istringstream buffer(elements.at(i));
			buffer >> curF;
		}
		else if(i==6){
			istringstream buffer(elements.at(i));
			buffer >>dir;
		}
		else if(i==7){
			 istringstream buffer(elements.at(i));
			 buffer >>dOpen;
		}

	}
	else
		elements.at(i)+=new_l.at(j);
	Lift l( identity,  weightLimit,  minF,  maxF,  curF,  dir, dOpen);
	lifts.push_back(l);

}

void Model::addPsgr(string new_p) {
	//TODO split string by comma and parse into passenger
	vector<string> elements(5);
		int ID,weight,travelFreq;
		std::string currentLift,destinationFloor;

		for (int i=1; i<=5;i++)
			for(int j=0; j<=new_p.size(); j++)
		if (new_p.at(j)==','){
			if (i==1){
				istringstream buffer(elements.at(i));
				buffer >> ID;
			}
			else if (i==2){
				istringstream buffer(elements.at(i));
				buffer >> weight;
			}
			else if(i==3){
				istringstream buffer(elements.at(i));
				buffer >> travelFreq;
			}
			else if(i==4){
				currentLift=elements.at(i);

			}
			else if (i==5){
				destinationFloor=elements.at(i);}
		}
		else
			elements.at(i)+=new_p.at(j);
		Passenger p(ID,weight,travelFreq,currentLift,destinationFloor);
		passengers.push_back(p);

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
vector <internalButton> Model::getInternalButtons(){
	return intButtons;
}
vector <externalButton> Model::getExternalButtons(){
	return extButtons;
}
std::list <externalButton> Model:: CallingFloorList(){
	std::list <externalButton> ExternalButtonsPressed;
for (int i=0; i<extButtons.size(); i++){
	if (extButtons.at(i).isPressed())
		ExternalButtonsPressed.push_back(extButtons.at(i));

}
return ExternalButtonsPressed;
}
std::list <Passenger> ChangedPassengers(){
	std::list <Passenger> p;
//needs implementation
	return p;
	}

std::list <Lift> ChangedLifts(){
	std::list <Lift> l;
	//needs implementation
		return l;
	}
