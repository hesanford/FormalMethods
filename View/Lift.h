//
//  Lift.h
//  
//
//  Created by Hanna Sanford on 06/12/2014.
//
//

#ifndef _Lift_h
#define _Lift_h
#include <stdio.h>
#include <vector>

using namespace std;

class Lift {
    int currentFloor;
    int numPassengers;
    int direction;
    vector<bool> buttons;
    
public:
    Lift(int floor, int passengers, int dir, vector<bool> btns);
    int getCurFLoor();
    int getNumPass();
    int getDir();
    vector<bool> getButtons();
    void setCurFloor(int floor);
    void setNumPass(int passengers);
    void setDir(int dir);
    void setButtons(vector<bool> btns);
    
};

#endif
