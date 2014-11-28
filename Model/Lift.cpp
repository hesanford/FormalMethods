#include <iostream>
#include "Lift.h"

using namespace std;
		Lift :: Lift(int identity,int weightLimit, int minF, int maxF,int curF,int dir,bool dOpen)
		{
			ID=identity;
			wLimit=weightLimit;
			minFloor=minF;
			maxFloor=maxF;
			floor=curF;		//initialize with 0 ?
			direction=dir;	//initilaize with 0 ?
			doorsOpen=dOpen;//initialize with true?
		}

		int Lift:: getID(){
			return ID;
		}
		void Lift:: setID(int identity){
			ID=identity;
		}
		int Lift:: getWLimit(){
			return wLimit;
		}
		void Lift:: setWLimit(int){}
		int Lift:: getMinFloor(){
			return minFloor;
		}
		void Lift:: setMinFloor(int){}
		int Lift:: getMaxFloor(){
			return maxFloor;
		}
		void Lift:: setMaxFloor(int){}

		int Lift:: getFloor(){
			return direction;
		}
		void Lift:: setFloor(int){}

		int Lift:: getDirection(){
			return doorsOpen;
		}
		void setDirection(int){
		}
//		bool areDoorsOpen();
//		void setDoorsOpen(bool);

