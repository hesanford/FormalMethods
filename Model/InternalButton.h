#ifndef InternalButton_H_
#define InternalButton_H_
#include "Button.h"
using namespace std;

//Derived class
class InternalButton: public Button
{
   public:
   InternalButton(int ,int );
   int getDestination();
   void setDestinationFlr(int);
   int getliftID();
   void setliftID(int);
   private:
   int liftID;
   int destination;

};



#endif /* InternalButton_H_ */
