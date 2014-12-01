#ifndef internalButton_H_
#define internalButton_H_
#include "Button.h"
using namespace std;

//Derived class
class internalButton: public Button
{
   public:
   internalButton(int ,int );
   int getDestination();
   void setDestinationFlr(int);
   int getliftID();
   void setliftID(int);
   private:
   int liftID;
   int destination;

};



#endif /* internalButton_H_ */
