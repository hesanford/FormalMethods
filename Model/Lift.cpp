#include <iostream>
#include "Lift.h"
#include <vector>
using namespace std;

/*
Lift Performance
*@param integer for identity
*@param integer for weight limit
*@param integer for minimum floors
*@param integer for maximum floors
*@param integer for direction
*@param boolean open the doors of the lift
*@return integer for identity
*@return integer for weight limit
*@return integer for minimum floors
*@return integer for maximum floors
*@return integer for direction
*@return boolean to open doors of the lift

*/

Lift::Lift(int identity, int weightLimit, int minF, int maxF, int curF, int dir,                           /*Lift constructor*/
	bool dOpen)
{
	ID = identity;                                        /*initialize the identification of the lift?*/
	wLimit = weightLimit;                                /*initialize the weight limit ?*/
	curWeight = 0;                                      /*initialize the current weight as 0?*/
	minFloor = minF;                                   /*initialize the minimum floor ?*/
	maxFloor = maxF;                                  /*initialize the maximum floor?*/
	std::vector<int> nextDests;                      /*create the vector to  the next destination*/
	floor = curF;		                            /*initialize with 0 ?; initilize the current floor*/
	direction = dir;	                           /*initilaize with 0 ?	can be 1 (up), -1(down), 0 (idle);Set the direction towards up or down*/
	doorsOpen = dOpen;	                          /*initialize with true?; set the doors open if true */
}

void Lift::performStep()                               /*The lift must perform the following steps*/
{
	//needs a lot of rework; weight etc.
	if (!doorsOpen)
	{
		floor = floor + direction;                    /*The lift doors open when it goes to the floor in  the required direction*/
		if (floor == nextDests.at(0))                  /* doors open when lift reaches destination*/
		{
			nextDests.erase(nextDests.begin());
			doorsOpen = true;
		}
	} else {
		doorsOpen = false;                            /*doors don't open*/
	}
}
/*get the lift identification 
*@return the identification of the lift*/
int Lift::getID()
{
	return ID;
}
void Lift::setID(int identity)                  /*@param set the identity of the lift*/
{
	ID = identity;                  /*@param set the identity of the lift*/
}
int Lift::getWLimit()                  /*@param get the weight limit*/
{
	return wLimit;                  /*@return the weight limit*/
}
void Lift::setWLimit(int)                  /*@param set weight limit*/
{
	weightlimit = wLimit;                /*@param assign the weight limit*/
}

int Lift::getCurWeight()                  /*@param get the current weight*/
{
	return curWeight;                  /*@return the current weight  */
}

void Lift::setCurWeight(int w)                  /*@param integer set the current weight */
{
	curWeight = w;                  /*@param assign the current weight */
}

int Lift::getMinFloor()                   /*get to the minimum floor*/
{
	return minFloor;                  /*@return  the minimum floor*/
}
void Lift::setMinFloor(int)                   /* set the minimum floor*/
{
	minFloor = minF;                  /*@param assign the minimum floor*/
}
int Lift::getMaxFloor()                   /*get to the maximum floor*/
{
	return maxFloor;                  /*@return  the maximum floor*/
}
void Lift::setMaxFloor(int maxF)                   /*set the maximum floor*/
{
	maxFloor = maxF;                   /*@param assign the maximum floor*/
}

int Lift::getFloor()                   /*The Lift goes to the floor*/
{
	return direction;                  /*@return to the direction*/
}
void Lift::setFloor(int)                   /*@param set the Floor*/
{
}

int Lift::getDirection()                   /*@param get the direction iether up or down*/
{
	return doorsOpen;                  /*@return the doors open */
}
void setDirection(int)                  /*@param set the direction */
{
}
//		bool areDoorsOpen();
//		void setDoorsOpen(bool);
