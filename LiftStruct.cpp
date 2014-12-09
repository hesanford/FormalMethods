//
//  Lift.cpp
//  
//
//  Created by Hanna Sanford on 08/12/2014.
//
//

#include "LiftStruct.h"

using namespace std;

LiftStruct :: LiftStruct(int floor, int passengers, int dir, vector<bool> btns) {
    currentFloor = floor;
    numPassengers = passengers;
    direction = dir;
    buttons = btns;
}

int LiftStruct :: getCurFLoor() {
    return currentFloor;
}
int LiftStruct :: getNumPass() {
    return numPassengers;
}

int LiftStruct :: getDir() {
    return  direction;
}

vector<bool> LiftStruct :: getButtons() {
    return buttons;
}

void LiftStruct :: setCurFloor(int floor) {
    currentFloor = floor;
}

void LiftStruct :: setNumPass(int passengers) {
    numPassengers = passengers;
}

void LiftStruct :: setDir(int dir) {
    direction = dir;
}

void LiftStruct :: setButtons(vector<bool> btns) {
    buttons = btns;
}
