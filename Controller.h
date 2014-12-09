#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <iostream>
#include <vector>
#include "Lift.h"
#include "Model.h"
#include <math.h>

using namespace std;

class Controller
{
    public:

        vector<Lift> lifts;
        vector<Passenger> RelativePassengers;
        vector<Passenger> getRelativePassengers(int,int);

        typedef struct CallingMessage{
            int dir;
            int onFloor;
        }CallingMessage;

        int pickLift(int,int);
        void run();
        void setDestinationListForLift(vector<Passenger>,Lift);

        Controller(Model* m);
        virtual ~Controller();
Model *model;


};

#endif // CONTROLLER_H
