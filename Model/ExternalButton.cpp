#include "onFloor.h"
using namespace std;
onFloor:: onFloor(int fl,int dir){
	floor=fl;
	direction=dir;
}

int onFloor:: getFlr(){
	return floor;
}
void onFloor:: setFlr(int fl){
	floor=fl;
}
int onFloor:: getDir(){
	return direction;
}
void onFloor:: setDir(int dir){
	direction=dir;
}


