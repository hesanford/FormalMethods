#ifndef INLIFT_H_
#define INLIFT_H_
#include "Button.h"
using namespace std;

//Derived class
class inLift: public Button
{
   public:
   inLift(int ,int );
   int getDestination();
   void setDestinationFlr(int);
   int getliftID();
   void setliftID(int);
   private:
   int liftID;
   int destination;

};



#endif /* INLIFT_H_ */
