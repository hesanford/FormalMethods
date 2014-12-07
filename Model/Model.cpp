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
/*
Model structure
*@param integer for the identity of the lift,
*@param integer for the weight limit
*@param integer for the minimum floor
*@param integer for the maximum floor
*@param integer for the current floor
*@param integer for the direction
*@param boolean to open the doors
*@return integer for minimum floors
*@return integer for maximum floors
*@return the change
*@return external button
*/
Model::Model(vector<string> l, vector<string> p) /*Model constructor*/
{
	std::vector<Lift> lifts;                      /*new vector lift from namespace*/
	std::vector<Passenger> passengers;           /*new vector passenger from namespace*/
	/*
	To define the capacity of the lift and passengers
	*/
	liftCount = l.size();

	for (int i = 0; i < l.size(); i++) {
		addLift(l.at(i));
	}
	for (int i = 0; i < p.size(); i++) {
		addPsgr(p.at(i));
	}
	/*Get the maximum and minimum floors */
	minFloor = getMinFloor();
	maxFloor = getMaxFloor();

	addButtons();//add buttons 

	setChanged(true);// set change when lift working either set when true
}

void Model::update(bool onTick)               /*Update the model according to time*/
{
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
/*Add external for the floors  and internal buttons in the lift  */
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
/*add the lift to the model 
*@param integer for the identity of the lift, 
*@param integer for the weight limit
*@param integer for the minimum floor
*@param integer for the maximum floor
*@param integer for the current floor
*@param integer for the direction
*@param boolean to open the doors 
*/
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
/*add the passengers tot the model
*@param integer  the identity of the passenger, 
*@param integer  theweight
*@param integer  thetravel frequency
*/
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
/*get to the 'minimum floor 
*@return the minimum count of the floor*/
int Model::getMinFloor() {
	int re = 0;
	for (int i = 0; i < liftCount; i++) {
		re = min(re, lifts.at(i).getMinFloor());
	}
	return re;

}
/*get to the maximum floor
* @return the maximum count of the floor*/
int Model::getMaxFloor() {
	int re = 0;
	for (int i = 0; i < liftCount; i++) {
		re = max(re, lifts.at(i).getMaxFloor());
	}
	return re;

}
/*To change the model
*@param boolean if changed 
*@return the change*/
bool Model::isChanged() {
	return changed;
}
void Model::setChanged(bool c) {
	changed = c;
}
vector <internalButton> Model::getInternalButtons()
{
	return intButtons;
}
vector <externalButton> Model::getExternalButtons()
{
	return extButtons;
}
/*when external button pressed the model checks the floor list 
*@param integer the number of external buttons 
*@return external button is pressed*/
std::list <externalButton> Model:: CallingFloorList()
{
	std::list <externalButton> ExternalButtonsPressed;
for (int i=0; i<extButtons.size(); i++){
	if (extButtons.at(i).isPressed())
		ExternalButtonsPressed.push_back(extButtons.at(i));

}
return ExternalButtonsPressed;
}
