//
//  Floor.h
//  
//
//  Created by Hanna Sanford on 08/12/2014.
//
//

#ifndef ____Floor__
#define ____Floor__

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

#endif /* defined(____Floor__) */
