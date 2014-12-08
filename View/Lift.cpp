//
//  Lift.cpp
//  
//
//  Created by Hanna Sanford on 08/12/2014.
//
//

#include "Lift.h"

using namespace std;

Lift :: Lift(int floor, int passengers, int dir, vector<bool> btns) {
    currentFloor = floor;
    numPassengers = passengers;
    direction = dir;
    buttons = btns;
}

int Lift :: getCurFLoor() {
    return currentFloor;
}
int Lift :: getNumPass() {
    return numPassengers;
}

int Lift :: getDir() {
    return  direction;
}

vector<bool> Lift :: getButtons() {
    return buttons;
}

void Lift :: setCurFloor(int floor) {
    currentFloor = floor;
}

void Lift :: setNumPass(int passengers) {
    numPassengers = passengers;
}

void Lift :: setDir(int dir) {
    direction = dir;
}

void Lift :: setButtons(vector<bool> btns) {
    buttons = btns;
}
