#include <vector>
#include <iostream>
#include "Passenger.h"
#include "Lift.h"
#include "Model.h"
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include "externalButton.h"
#include "internalButton.h"
#include <stdlib.h>
#include <random>
#include <fstream>

using namespace std;
//Model::Model(){}
Model::Model(const char* l) {
	std::vector<Lift> lifts;
	std::vector<Passenger> passengers;
	std::vector<Passenger> RelativePassengers;
	ofstream log;
	lID = 0;
	string lift;
	ifstream fp("file.csv");
	if (fp.is_open()) {
		while (getline(fp, lift)) {
			lID++;
			addLift(lift);
		}

	}
	liftCount = lID;
	minFloor = getMinFloor();
	maxFloor = getMaxFloor();
	distribution= {0,0,0,0,0,0,0,1,1,2,3,4,4,4,3,3,2,2,1,1,0,0,0,0};
	// createDist();
	time = 0;
	pID = 0;

	addButtons();
	log.open("LiftEventLog.txt");
	log << "actor,id,event,weight,tstamp\n";
	log.close();

	setChanged(true);
}
void Model::incTime() {
	if (time == 1439) {
		time = 0;
	} else {
		++time;
	}
}
//performed on clock tick to move every object in the model one step
void Model::update(bool onTick) {
	while (true) {
		if (cl.nextTick()) {
			log.open("LiftEventLog.txt", std::ios_base::app);
			log << "G,0,clocktick,0," << time << "\n";
			log.close();
			for (int i = 0; i < liftCount; i++) {
				lifts.at(i).performStep(); //needs to be changed to the new performStep
			}
			for (int i = 0; i < distribution[time / 60]; i++) {
				newPsgr();
			}
			for (unsigned int i = 0; i < passengers.size(); i++) {
				Passenger p = passengers.at(i);
				if (p.getLift() == 0) {
					for ( int j = 0; j < liftCount; j++) {
						Lift l = lifts.at(j);
						if (l.areDoorsOpen() && (l.getFloor() == p.getFloor())
								&& (l.getDirection()== p.getDirection())
								&& ((l.getCurWeight() + p.getWeight())
										< l.getWLimit())) {
							p.setLift(l.getID());
							l.setCurWeight(l.getCurWeight() + p.getWeight());
						}
					}
				} else {
					for ( int j = 0; j < liftCount; j++) {
						Lift l = lifts.at(j);
						if (l.areDoorsOpen()&& (l.getFloor()== p.getDestFloor())) {
							p.setLift(l.getID());
							l.setCurWeight(l.getCurWeight() - p.getWeight());
						}
					}
				}
			}
		}
		incTime();
	}
}

void Model::pressButton(int type, int loc, int dest){
	if(type==1){
		for(unsigned int i = 0; i < extButtons.size(); i++){
			externalButton e = extButtons.at(i);
			if(e.getFlr() == loc && (e.getDir() == dest)){
				e.setPressed(true);
			}
		}
	}
	if(type==2){
		for(unsigned int i = 0; i < inButtons.size(); i++){
			internalButton in = inButtons.at(i);
			if(in.getliftID() == loc && (in.getDestination() == dest)){
				in.setPressed(true);
			}
		}
	}
}

void Model::addButtons() {
	for (int i = minFloor; i < maxFloor; i++) {
		externalButton a(i, 1);
		externalButton b(i, -1);
		extButtons.push_back(a);
		extButtons.push_back(b);

	}
	for (int i = 0; i < liftCount; i++) {
		int f_min = lifts.at(i).getMinFloor();
		int f_max = lifts.at(i).getMaxFloor();
		for (int j = f_min; j < f_max; j++) {
			{
				internalButton b(lifts.at(i).getID(), j);
				inButtons.push_back(b);
			}
		}
	}
}

void Model::addLift(string new_l) {
	//TODO split string by comma and parse into lift

	istringstream line(new_l);
	int i = 1, weightLimit, minF, maxF;
	string element;
	while (getline(line, element, ',')) {
		if (i == 1) {
			istringstream buffer(element);
			buffer >> weightLimit;
		} else if (i == 2) {
			istringstream buffer(element);
			buffer >> minF;
		} else if (i == 3) {
			istringstream buffer(element);
			buffer >> maxF;
		}
		i++;
	}

	Lift l(lID, weightLimit, minF, maxF, 0, 0, true);
	lifts.push_back(l);

}

void Model::newPsgr() {
	//TODO split string by comma and parse into passenger
	int i = rand() % maxFloor;
	int j = rand() % maxFloor;
	Passenger pTemp(pID, rndWeight(), i, j);
	pID++;
	int dir = pTemp.getDirection();
	if (dir == 0) {
		delete (&pTemp);
	} else {
		passengers.push_back(pTemp);
		for (unsigned int i = 0; i < extButtons.size(); i++) {
			if ((extButtons.at(i).getFlr() == pTemp.getFloor())
					&& extButtons.at(i).getDir() == dir) {
				extButtons.at(i).setPressed(true);
			}
		}
	}

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

int Model::getNoLifts() {
	return liftCount;
}
vector<Lift> Model::getLifts() {
	return lifts;
}

Lift Model::getLift(int i) {
	return lifts[i];
}

bool Model::isChanged() {
	return changed;
}
void Model::setChanged(bool c) {
	changed = c;
}

void Model::setCallingDirList() {

	for (int i = 0; i < (int) extButtons.size(); i++) {

		if (extButtons.at(i).isPressed()) {

			CallingMessage callingmessage;
			callingmessage.dir = extButtons.at(i).getDir();
			callingmessage.onFloor = extButtons.at(i).getFlr();
			CallingDirList.push_back(callingmessage);

		}
	}

}
/*
 vector <int> Model:: CallingFloorList(){
 for (unsigned int i=0; i<extButtons.size(); i++)
 if (extButtons.at(i).isPressed())
 for(unsigned int j=0;j<CallingFloors.size();j=j+2)
 if(CallingFloors.at(j)==extButtons.at(i).getFlr()|| CallingFloors.at(j+1)==extButtons.at(i).getDir())
 {
 CallingFloors.push_back(extButtons.at(i).getFlr());
 CallingFloors.push_back(extButtons.at(i).getDir());
 }
 return CallingFloors;
 }
 */
//creates a poisson distribution depending on daytime
/*void Model::createDist()
 {
 int rolls = 10000; // number of experiments
 int psgrs = 40;   // maximum number of passengers to distribute
 std::default_random_engine generator;
 std::poisson_distribution<int> d(13);



 for (int i=0; i<rolls; ++i) {
 int number = d(generator);
 if (number<24) ++distribution[number];
 }
 for (int i=0; i<23; i++){
 distribution[i] = (distribution[i]*psgrs/rolls);
 }
 }*/
//randomizes passenger weight
int Model::rndWeight() {
	int w = 75;
	int acc = rand() % 2;
	if (acc == 0) {
		w += rand() % 25;
	} else {
		w -= rand() % 25;
	}
	return w;
}

