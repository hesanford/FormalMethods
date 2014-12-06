//
//  Floor.h
//  
//
//  Created by Hanna Sanford on 06/12/2014.
//
//

#ifndef _Floor_h
#define _Floor_h
#include <stdio.h>
#include <vector>

using namespace std;

class Floor {
private:
    int numPassengers;
    vector<bool> buttons;
    
public:
    Floor(int passengers, vector<bool> btns);
    int getNumPass();
    vector<bool> getButtons();
    void setNumPass(int passengers);
    void setButtons(vector<bool> btns);
    
};

#endif
