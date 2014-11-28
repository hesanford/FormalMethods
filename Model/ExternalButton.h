#ifndef ExternalButton_H_
#define ExternalButton_H_
#include "Button.h"
using namespace std;
//Derived class
class ExternalButton: public Button
{

   public:
   ExternalButton(int fl,int dir);
   int getFlr();
   void setFlr(int);
   int getDir();
   void setDir(int);
   private:
   int floor;
   int direction;

};



#endif /* ExternalButton_H_ */
