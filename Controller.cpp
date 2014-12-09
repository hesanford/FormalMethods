#include "Controller.h"
#include "Model.h"
#include <vector>
#include <stdlib.h>

using namespace std;

Controller::Controller(Model *m)
{
model=m;
}

Controller::~Controller()
{

}

int Controller::pickLift(int callingFloor, int callingDir){
    //int callingFloor = model->CallingDirList.at(1).onFloor;
    //int callingDir = model->CallingDirList.at(1).dir;
    int size = model->lifts.size();
    //int allLiftDir[size][2]; //liftID, liftDir
    int allPotentialLifts[size][3]; //liftID, currentLiftFloor,1 means not being idle, 0 means having same direction
    int flagID = 0;
    bool hasSameDirOnWay = 0;

    /*for (int i = 0; i < (int)model->lifts.size(); i++){ //get all lifts's info
            lifts.push_back(model->lifts.at(i));
            allLiftDir[i][0] = model->lifts.at(i).getID();
            allLiftDir[i][1] = model->lifts.at(i).getDirection();
    }
    */
    for (unsigned int i = 0; i < model->lifts.size(); i++){
            if(lifts.at(i).getDirection() == callingDir ) {//find if there is a lift having same dir as callingDir
                if (callingDir == 1) {//if callingDir is up
                   if ( callingFloor > model->lifts.at(i).getFloor() ) {
                    allPotentialLifts[flagID][0] = model->lifts.at(i).getID();
                    allPotentialLifts[flagID][1] = model->lifts.at(i).getFloor();
                    allPotentialLifts[flagID][2] = 1;
                    flagID++;
                    hasSameDirOnWay = 1;
                   }
                }
                if (callingDir == -1) {//if callingDir is down
                    if ( callingFloor < model->lifts.at(i).getFloor() ) {
                    allPotentialLifts[flagID][0] = model->lifts.at(i).getID();
                    allPotentialLifts[flagID][1] = model->lifts.at(i).getFloor();
                    allPotentialLifts[flagID][2] = 1;
                    flagID++;
                    hasSameDirOnWay = 1;
                   }
                }
            }else if(lifts.at(i).getDirection() == 0){// currentLift is being idle
                    allPotentialLifts[flagID][0] = model->lifts.at(i).getID();
                    allPotentialLifts[flagID][1] = model->lifts.at(i).getFloor();
                    allPotentialLifts[flagID][2] = 0;
                    flagID++;
            } //finishing all the potential choices

            int row = sizeof(allPotentialLifts)/(3*sizeof(int));

            if(row == 0){

                   return model->lifts.at(i).getID();

            }

            else {
                    int minDifLevel = 1000;
                    int liftID;
                    int difLevel;

                    if (hasSameDirOnWay){ //has lift with same direction on the way
                        for (int i = 0; i < row; i++){
                                if(allPotentialLifts[i][2] == 1){
                                   difLevel = abs(allPotentialLifts[i][1] - callingFloor);
                                    if (minDifLevel > difLevel){
                                        liftID = allPotentialLifts[i][0];
                                        minDifLevel = difLevel;
                                    }
                                }
                        }
                        return liftID;
                    }else { // only has lift being idle
                        for (int i = 0; i < row; i++){
                            difLevel = abs(allPotentialLifts[i][1] - callingFloor);
                            if (minDifLevel > difLevel){
                                liftID = allPotentialLifts[i][0];
                                minDifLevel = difLevel;
                            }
                        }
                        return liftID;
                    }

            }



    }

    return model->lifts.at(0).getID();

}

vector<Passenger> Controller::getRelativePassengers(int currentFloor,int dir){

     for(int i = 0; i < (int)model->passengers.size(); i++){

            if((model->passengers.at(i).getFloor() == currentFloor) && (model->passengers.at(i).getDirection() == dir)){

                RelativePassengers.push_back(model->passengers.at(i));

            }

     }

    return RelativePassengers;

}

void Controller::setDestinationListForLift(vector<Passenger> passengers, Lift lift){

    if(lift.checkWeight()){

        for(int i = 0 ; i < (int)passengers.size(); i++){

            lift.setPriorityList(passengers.at(i).getFloor(),passengers.at(i).getDirection());

        }

    }

}

void Controller::run(){

   int liftID;
   Lift pickedLift(0,0,0,0,0,0,0);

   for (int i = 0; i < (int)model->CallingDirList.size(); i++){

        int callingFloor = model->CallingDirList.at(i).onFloor;
        int callingDir = model->CallingDirList.at(i).dir;

        liftID = pickLift(callingFloor, callingDir);
        pickedLift = model->getLift(liftID);


   }

   pickedLift.checkPriority(model->CallingDirList.at(0).onFloor,model->CallingDirList.at(0).dir);
   model->CallingDirList.erase(model->CallingDirList.begin());
   if(pickedLift.isMoving == false){

    ;
   }else{
     pickedLift.setDoors(true);
   }
   getRelativePassengers(pickedLift.getFloor(), pickedLift.getDirection());
   setDestinationListForLift(RelativePassengers,pickedLift);
   pickedLift.setDoors(false);

}
