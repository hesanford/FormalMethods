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
    
int Floor :: getNumPass() {
        return numPassengers;
    }
    
vector<bool> Floor :: getButtons() {
        return buttons;
    }
    
void Floor :: setNumPass(int passengers) {
        numPassengers = passengers;
    }
    
void Floor :: setButtons(vector<bool> btns) {
        buttons = btns;
    }
