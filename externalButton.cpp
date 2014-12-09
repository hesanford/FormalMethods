#include "externalButton.h"
using namespace std;
externalButton:: externalButton(int fl,int dir){
	floor=fl;
	direction=dir;
	pressed=0;
}

int externalButton:: getFlr(){
	return floor;
}
void externalButton:: setFlr(int fl){
	floor=fl;
}
int externalButton:: getDir(){
	return direction;
}
void externalButton:: setDir(int dir){
	direction=dir;
}
bool externalButton:: isPressed(){
	return pressed;
}
void externalButton:: setPressed(bool pr){
	pressed=pr;
}


