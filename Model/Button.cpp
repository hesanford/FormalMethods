#include <iostream>
#include "Button.h"
/*Press the Button 
*@param boolean button is pressed
*@param boolean button is set pressed 
@return action of the button pressed
*/

using namespace std;
Button::Button()        /*Button constructor*/
{
	pressed = 0;                /*button not yet pressed*/
}
Button::Button(bool pr)       /*@param boolean if button pressed */
{
	pressed = pr;           /*@param reserve pressed*/
}
bool Button::isPressed()     /*set button is pressed*/
{
	return pressed;            /*@return the action made as the button pressed*/
}
void Button::setPressed(bool pr)   /*@param boolean set button pressed*/
{
	pressed = pr;                     /*@param reserve pressed*/
}