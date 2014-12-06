//
//  Floor.cpp
//  
//
//  Created by Hanna Sanford on 04/12/2014.
//
//

#include "Floor.h"

using namespace std;

Floor :: Floor(int passengers, vector<bool> btns) {
        numPassengers = passengers;
        buttons = btns;
    }
    
Floor :: int getNumPass() {
        return numPassengers;
    }
    
Floor :: vector<bool> getButtons() {
        return buttons;
    }
    
Floor :: void setNumPass(int passengers) {
        numPassengers = passengers;
    }
    
FLoor :: void setButtons(vector<bool> btns) {
        buttons = btns;
    }
