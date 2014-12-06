//
//  Lift.cpp
//  
//
//  Created by Hanna Sanford on 04/12/2014.
//
//

#include <stdio.h>
#include <vector>

using namespace std;

class Lift {
    int currentFloor;
    int numPassengers;
    int direction;
    vector<bool> buttons;
    
public: Lift(int floor, int passengers, int dir, vector<bool> btns) {
        currentFloor = floor;
        numPassengers = passengers;
        direction = dir;
        buttons = btns;
    }
    
public: int getCurFLoor() {
        return currentFloor;
    }
    
public: int getNumPass() {
        return numPassengers;
    }
    
public: int getDir() {
        return  direction;
    }
    
public: vector<bool> getButtons() {
        return buttons;
    }
    
public: void setCurFloor(int floor) {
        currentFloor = floor;
    }
    
public: void setNumPass(int passengers) {
        numPassengers = passengers;
    }
    
public: void setDir(int dir) {
        direction = dir;
    }
    
public: void setButtons(vector<bool> btns) {
        buttons = btns;
    }
};