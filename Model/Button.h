#ifndef Button_H
#define Button_H
#include <iostream>
using namespace std;
// Base class
class Button {
	public:
	Button();
	Button(bool);
		bool isPressed();
		void setPressed(bool);
	private:
		bool pressed;
};


#endif