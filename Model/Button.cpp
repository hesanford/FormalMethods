#include <iostream>
#include "Button.h"

using namespace std;
Button :: Button(){
	pressed=0;
}
Button :: Button(bool pr){
	pressed=pr;
}
bool Button:: isPressed(){
	return pressed;
}
void Button:: setPressed(bool pr){
	pressed=pr;
}

