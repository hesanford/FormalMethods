#include <iostream>
#include "Lift.h"
#include <vector>
#include <unistd.h>
using namespace std;
Lift::Lift(int identity, int weightLimit, int minF, int maxF, int curF, int dir,
		bool dOpen) {
	ID = identity;
	wLimit = weightLimit;
	curWeight = 0;
	minFloor = minF;
	maxFloor = maxF;
	floor = curF;		//initialize with 0 ?
	direction = dir;	//initilaize with 0 ?	can be 1 (up), -1(down), 0 (idle);
	doorsOpen = dOpen;	//initialize with true?
    isMoving = false;
}


int Lift::performMove(int callingFloor) {
	//needs a lot of rework; weight etc.

    isMoving = true;

    int currentFloor = getFloor();



            if(currentFloor < callingFloor){

                while(currentFloor < callingFloor){

                    if(callingFloor != firstPriorityList.at(0)){

                        return currentFloor;

                    }
                    usleep(100);
                    currentFloor++;
                    setFloor(currentFloor);

                }

            }else if(currentFloor > callingFloor){

                   while(currentFloor > callingFloor){

                    if(callingFloor != firstPriorityList.at(0)){

                        return currentFloor;

                    }
                    usleep(100);
                    currentFloor--;
                    setFloor(currentFloor);

                }
            }

			firstPriorityList.erase(firstPriorityList.begin());

            isMoving = false;

            return currentFloor;

}

void Lift::setPriorityList(int callingFloor, int dir){

    int currentDir = getDirection();
    int currentFloor = getFloor();

    if(currentDir == 1){//if current lift is up
        if((currentDir == dir)&&(currentFloor < callingFloor)){//if calling floor is on the way

                for(vector<int>::iterator p = firstPriorityList.begin(); p < firstPriorityList.end(); p++){

                        if( (*p < callingFloor) && (*(p+1) > callingFloor)){
                            p = this->firstPriorityList.insert(p,callingFloor);// add to first priority list
                        }

                }

        }

        if((currentDir == dir) &&(currentFloor > callingFloor)){//if calling floor has same direction with current lift, but below currentLiftFloor

                int firstDir = secondPriorityList.at(0).dir;
                if (firstDir == -1) { //if has the callingFloor item that has different direction, jump over it
                    vector<secondPriorityItem>::iterator l  = secondPriorityList.begin();
                    for(; l < secondPriorityList.end(); l++){

                        if ( l->dir == -1)  ;
                        else break;

                    }
                    for(; l < secondPriorityList.end(); l++){
                        if( (l->floorNum < callingFloor) && ((l+1)->floorNum > callingFloor)){

                            secondPriorityItem newitem;
                            newitem.dir = 1;
                            newitem.floorNum = callingFloor;
                            l = this->secondPriorityList.insert(l,newitem);// add to second priority list in increase order
                            break;
                        }
                    }

                }
                else if(firstDir == 1){//if only has the callingFloor item that has same direction,
                    vector<secondPriorityItem>::iterator l  = secondPriorityList.begin();
                     for(; l < secondPriorityList.end(); l++){
                        if( (l->floorNum < callingFloor) && ((l+1)->floorNum > callingFloor)){

                            secondPriorityItem newitem;
                            newitem.dir = 1;
                            newitem.floorNum = callingFloor;
                            l = this->secondPriorityList.insert(l,newitem);// add to second priority list in increase order
                            break;
                        }
                     }
                }

        }

        if((currentDir != dir) &&(currentFloor < callingFloor)){// if calling floor has different direction with current lift, but above currentLiftFloor

            int firstDir = secondPriorityList.at(0).dir;
            if( firstDir == 1){
                vector<secondPriorityItem>::iterator l  = secondPriorityList.end();
                for(; l > secondPriorityList.begin(); l--){
                    if ( l->dir == 1)  ;
                    else break;
                }

                for(; l > secondPriorityList.begin(); l--){
                    if( (l->floorNum < callingFloor) && ((l-1)->floorNum > callingFloor)){

                        secondPriorityItem newitem;
                        newitem.dir = 1;
                        newitem.floorNum = callingFloor;
                        l = this->secondPriorityList.insert(l,newitem);// add to second priority list in increase order
                        break;
                    }
                }
            }


        }

    }else if(currentDir == -1){//if current lift is down
        if((currentDir == dir)&&(currentFloor > callingFloor)){

                for(vector<int>::iterator p = firstPriorityList.begin(); p != firstPriorityList.end(); p++){

                        if( (*p > callingFloor) && (*(p+1) < callingFloor)){
                            p = this->firstPriorityList.insert(p,callingFloor);// add to first priority list
                        }

                }

        }else if((currentDir == dir) &&(currentFloor < callingFloor)){

             int firstDir = secondPriorityList.at(0).dir;
                if (firstDir == 1) { //if has the callingFloor item that has different direction, jump over it
                    vector<secondPriorityItem>::iterator l  = secondPriorityList.begin();
                    for(; l < secondPriorityList.end(); l++){

                        if ( l->dir == 1)  ;
                        else break;

                    }
                    for(; l < secondPriorityList.end(); l++){
                        if( (l->floorNum > callingFloor) && ((l+1)->floorNum < callingFloor)){

                            secondPriorityItem newitem;
                            newitem.dir = -1;
                            newitem.floorNum = callingFloor;
                            l = this->secondPriorityList.insert(l,newitem);// add to second priority list in increase order
                            break;
                        }
                    }

                }
                else if(firstDir == -1){//if only has the callingFloor item that has same direction,
                    vector<secondPriorityItem>::iterator l  = secondPriorityList.begin();
                     for(; l < secondPriorityList.end(); l++){
                        if( (l->floorNum > callingFloor) && ((l+1)->floorNum < callingFloor)){

                            secondPriorityItem newitem;
                            newitem.dir = -1;
                            newitem.floorNum = callingFloor;
                            l = this->secondPriorityList.insert(l,newitem);// add to second priority list in increase order
                            break;
                        }
                     }
                }
        }

        if((currentDir != dir) &&(currentFloor > callingFloor)){// if calling floor has different direction with current lift, but below currentLiftFloor

            int firstDir = secondPriorityList.at(0).dir;
            if( firstDir == -1){
                vector<secondPriorityItem>::iterator l  = secondPriorityList.end();
                for(; l > secondPriorityList.begin(); l--){
                    if ( l->dir == -1)  ;
                    else break;
                }

                for(; l > secondPriorityList.begin(); l--){
                    if( (l->floorNum > callingFloor) && ((l-1)->floorNum < callingFloor)){

                        secondPriorityItem newitem;
                        newitem.dir = -1;
                        newitem.floorNum = callingFloor;
                        l = this->secondPriorityList.insert(l,newitem);// add to second priority list in increase order
                        break;
                    }
                }
            }

        }

    }
}

void Lift::checkPriority(int callingFloor, int dir){

    if(getDirection() == 0){// If pickedLift is being idle, set its direction according to the CallingFloor

       firstPriorityList.push_back(callingFloor);

       if(getFloor() > firstPriorityList.at(0)){
            setDirection(-1);
            //performMove(firstPriorityList.at(0).onFloor);
       }else if (getFloor() < firstPriorityList.at(0)){
            setDirection(1);
            // performMove(firstPriorityList.at(0).onFloor);
       }else if(getFloor() == firstPriorityList.at(0))
            setDoors(true);

    }else{
            setPriorityList(callingFloor,dir);
        //model.CallingDirList.erase(CallingDirList.at(0));
        // performMove(firstPriorityList.at(0).onFloor);
    }

}

void Lift::mergeTwoList(vector<int> firstPriorityList, vector<secondPriorityItem> secondPriorityList ){

    for(int i = 0 ; i < (int)secondPriorityList.size(); i++){

        firstPriorityList.push_back(secondPriorityList.at(i).floorNum);

    }

}

int Lift::getID() {
	return ID;
}
void Lift::setID(int identity) {
	ID = identity;
}
int Lift::getWLimit() {
	return wLimit;
}
void Lift::setWLimit(int w) {
	wLimit=w;
}

int Lift::getCurWeight(){
	return curWeight;
}

void Lift::setCurWeight(int w){
	curWeight = w;
}

int Lift::getMinFloor() {
	return minFloor;
}
void Lift::setMinFloor(int minf) {
	minFloor=minf;
}
int Lift::getMaxFloor() {
	return maxFloor;
}
void Lift::setMaxFloor(int maxf) {
	maxFloor=maxf;
}

int Lift::getFloor() {
	return floor;
}
void Lift::setFloor(int f) {
floor=f;
}

int Lift::getDirection() {
	return doorsOpen;
}
void Lift::setDirection(int dir) {
	direction=dir;
}
bool Lift::areDoorsOpen(){
	return doorsOpen;

}
void Lift::setDoors(bool d)
{
	doorsOpen=d;
}

bool Lift:: checkWeight(){
int check;
check = getWLimit()-getCurWeight();
	if (check>0)
		return 1;
	else
		return 0;
}
