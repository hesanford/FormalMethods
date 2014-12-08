//
//  sender.cpp
//  
//
//  Created by Hanna Sanford on 08/12/2014.
//
//
#include "sender.h"

using namespace std;
    //THIS IS GOING AWAY
    int l = 3;
    int f = 5;
    int temp1[] = {4, 0,1};
    vector<int> LIFTPASSENGERS(temp1, temp1+3);
    int temp2[] = {0, 0, 3};
    vector<int> LIFTSTARTFLOOR(temp2, temp2+3);
    int temp3[] = {0, 1, -1};
    vector<int> LIFTSTARTDIR(temp3, temp3+3);
    int temp4[] = {3, 0, 0, 2, 1};
    vector<int> FLOORPASSENGERS(temp4, temp4+5);
    bool temp5[] = {0, 0, 0, 1, 0};
    bool temp6[] = {1, 1, 0, 0, 0};
    bool temp7[] = {1, 1, 1, 1, 1};
    vector<bool> t5(temp5, temp5+5);
    vector<bool> t6(temp6, temp6+5);
    vector<bool> t7(temp7, temp7+5);
    vector<bool> temp8[] = {t5, t6, t7};
    vector< vector<bool> > LIFTBUTTONS(temp8, temp8+3);
    bool temp9[] = {1, 0};
    bool temp10[] = {1, 1};
    bool temp11[] = {1, 1};
    bool temp12[] = {1, 1};
    bool temp13[] = {0, 1};
    vector<bool> t9(temp9, temp9+1);
    vector<bool> t10(temp10, temp10+2);
    vector<bool> t11(temp11, temp11+2);
    vector<bool> t12(temp12, temp12+2);
    vector<bool> t13(temp13, temp13+2);
    vector<bool> temp14[] = {t9, t10, t11, t12, t13};
    vector< vector<bool> > FLOORBUTTONS(temp14, temp14+5);
    
    int main() {
        View::View view(f, l, LIFTPASSENGERS, LIFTSTARTFLOOR, LIFTSTARTDIR, FLOORPASSENGERS, LIFTBUTTONS, FLOORBUTTONS);
        return 0;
    }