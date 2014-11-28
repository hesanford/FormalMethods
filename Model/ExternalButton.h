#ifndef externalButton_H_
#define externalButton_H_
#include "Button.h"
using namespace std;
//Derived class
class externalButton: public Button
{

   public:
   externalButton(int fl,int dir);
   int getFlr();
   void setFlr(int);
   int getDir();
   void setDir(int);
   private:
   int floor;
   int direction;

};



#endif /* externalButton_H_ */
