//
//  Floor.cpp
//  
//
//  Created by Hanna Sanford on 04/12/2014.
//
//

#include <stdio.h>
#include <vector>

using namespace std;

class Floor {
    int numPassengers;
    vector<bool> buttons;
    
public: Floor(int passengers, vector<bool> btns) {
        numPassengers = passengers;
        buttons = btns;
    }
    
public: int getNumPass() {
        return numPassengers;
    }
    
public: vector<bool> getButtons() {
        return buttons;
    }
    
public: void setNumPass(int passengers) {
        numPassengers = passengers;
    }
    
public: void setButtons(vector<bool> btns) {
        buttons = btns;
    }
};
