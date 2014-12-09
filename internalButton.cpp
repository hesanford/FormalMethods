#include "internalButton.h"
using namespace std;

/*The action made on the internal button
*@param integer of floor type
*@param integer to identify lift
*@return integer the destination floor number
*@return integer get the lift identification
*/
internalButton::internalButton(int lID, int dFlr)          /*Internal button constructor */
{
	liftID = lID;                                               /*@param initialize the lift identification*/
	destination = dFlr;                                        /*@param initialize the destination floor*/
	pressed=0;
}
int internalButton::getDestination()                          /*get to the destination*/
{
	return destination;                                       /*@return arrives to the destination*/
	}
void internalButton::setDestinationFlr(int dFlr)             /*set the destination floor number*/
{
	destination = dFlr;                                         /*@param assign the destination floor*/
}
int internalButton::getliftID()                                 /*get the lift identification */
{
	return liftID;                                               /*@return the lift identification */
   }

void internalButton::setliftID(int lID)                          /*set the lift identification number*/
{
	liftID = lID;                                                  /*@param assign the lift identification*/
}

bool internalButton:: isPressed(){
	return pressed;
}
void internalButton:: setPressed(bool pr){
	pressed=pr;
}
