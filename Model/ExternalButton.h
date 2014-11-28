#ifndef ONFLOOR_H_
#define ONFLOOR_H_
#include "Button.h"
using namespace std;
//Derived class
class onFloor: public Button
{

   public:
   onFloor(int fl,int dir);
   int getFlr();
   void setFlr(int);
   int getDir();
   void setDir(int);
   private:
   int floor;
   int direction;

};



#endif /* ONFLOOR_H_ */
