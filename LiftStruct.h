//
//  LiftStruct.h
//  
//
//  Created by Hanna Sanford on 08/12/2014.
//
//

#ifndef ____LiftStruct__
#define ____LiftStruct__

#include <stdio.h>
#include <vector>

using namespace std;

class LiftStruct {
    int currentFloor;
    int numPassengers;
    int direction;
    vector<bool> buttons;
    
public:
    LiftStruct(int floor, int passengers, int dir, vector<bool> btns);
    int getCurFLoor();
    int getNumPass();
    int getDir();
    vector<bool> getButtons();
    void setCurFloor(int floor);
    void setNumPass(int passengers);
    void setDir(int dir);
    void setButtons(vector<bool> btns);
    
};

#endif /* defined(____LiftStruct__) */
