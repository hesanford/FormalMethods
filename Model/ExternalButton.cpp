#include "ExternalButton.h"
using namespace std;
ExternalButton:: ExternalButton(int fl,int dir){
	floor=fl;
	direction=dir;
	pressed=0;
}

int ExternalButton:: getFlr(){
	return floor;
}
void ExternalButton:: setFlr(int fl){
	floor=fl;
}
int ExternalButton:: getDir(){
	return direction;
}
void ExternalButton:: setDir(int dir){
	direction=dir;
}


