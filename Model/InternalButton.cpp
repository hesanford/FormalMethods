#include "inLift.h"
using namespace std;

inLift:: inLift(int lID ,int dFlr){
	liftID=lID;
	destination=dFlr;
}
int inLift:: getDestination(){
	return destination;
	}
void inLift:: setDestinationFlr(int dFlr){
	destination=dFlr;
}
int inLift:: getliftID(){
   return liftID;
   }

void inLift:: setliftID(int lID){
	liftID=lID;
}

