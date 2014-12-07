#ifndef Button_H
#define Button_H
#include <iostream>
using namespace std;
/*Button class
* @param boolean button
* @param boolean isPressed
* @param boolean setPressed
*/
class Button {
	public:
	Button();
	Button(bool);                  /*@param button is set to boolean*/
	bool isPressed();             /*@param pressed is set to boolean*/
	void setPressed(bool);       /*@param is passed to set pressed as boolean */
	private:
		bool pressed;           /*@param boolean  has control access  when pressed */
};


#endif