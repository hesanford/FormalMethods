//
//  Lift.cpp
//  
//
//  Created by Hanna Sanford on 04/12/2014.
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
    
Lift :: int getCurFLoor() {
        return currentFloor;
    }
Lift :: int getNumPass() {
        return numPassengers;
    }
    
Lift :: int getDir() {
        return  direction;
    }
    
Lift :: vector<bool> getButtons() {
        return buttons;
    }
    
Lift :: void setCurFloor(int floor) {
        currentFloor = floor;
    }
    
Lift :: void setNumPass(int passengers) {
        numPassengers = passengers;
    }
    
Lift :: void setDir(int dir) {
        direction = dir;
    }
    
Lift :: void setButtons(vector<bool> btns) {
        buttons = btns;
    }
};