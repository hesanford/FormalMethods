#include "InternalButton.h"
using namespace std;

InternalButton:: InternalButton(int lID ,int dFlr){
	liftID=lID;
	destination=dFlr;
}
int InternalButton:: getDestination(){
	return destination;
	}
void InternalButton:: setDestinationFlr(int dFlr){
	destination=dFlr;
}
int InternalButton:: getliftID(){
   return liftID;
   }

void InternalButton:: setliftID(int lID){
	liftID=lID;
}

