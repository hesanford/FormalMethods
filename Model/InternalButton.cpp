#include "internalButton.h"
using namespace std;

internalButton:: internalButton(int lID ,int dFlr){
	liftID=lID;
	destination=dFlr;
}
int internalButton:: getDestination(){
	return destination;
	}
void internalButton:: setDestinationFlr(int dFlr){
	destination=dFlr;
}
int internalButton:: getliftID(){
   return liftID;
   }

void internalButton:: setliftID(int lID){
	liftID=lID;
}

