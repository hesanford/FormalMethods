#ifndef internalButton_H_
#define internalButton_H_
#include "Button.h"
using namespace std;

/*Derive the Internal button class
*@param integer 
*@return integer the destination floor number
*@return integer get the lift identification
*/
class internalButton: public Button
{
   public:
   internalButton(int, int);                /*@param capacity of the internal button first the lift identity and then the destination floor  */
   int getDestination();                   /*get to the destination*/
   void setDestinationFlr(int);           /*@param  for the desitnation floor number*/
   int getliftID();                      /*get the lift identification*/
   void setliftID(int);                 /*@param  for the  lift identification number*/
   private:
	   int liftID;                     /* capacity of the lift identification*/
	   int destination;               /* capacity of the destination*/

};



#endif /* internalButton_H_ */
