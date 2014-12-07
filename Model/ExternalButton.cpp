#include "externalButton.h"
using namespace std;
/*The action made on the external button
*@param the floor type
*@param the direction type
*@return integer the floor number
*@return integer the direction value
*/
externalButton:: externalButton(int fl,int dir).         /*  external button constructor */
{
	floor = fl;                                    /* @param initialize the floor*/
	direction = dir;                                   /* @param initialize the direction*/
}

int externalButton::getFlr(){                       /*   @param when external  button pressed , get to the floor  */
	return floor;                                    /* @return get to the floor */
}
void externalButton::setFlr(int fl)                /*   @param  set  the floor  */
{
	floor = fl;                                     /* assign the floor*/
}
int externalButton::getDir()                         /* @param  get direction*/
{
	return direction;                                 /* @retrun the direction according to the call of the external button*/
}
void externalButton::setDir(int dir)                      /*@param  set the direction*/
{
	direction = dir;                                      /* assign the  direction*/
}



