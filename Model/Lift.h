#ifndef Lift_H
#define Lift_H
#include <vector>
#include <iostream>

using namespace std;
/*Lift class
@param integer  to set the identification of the lift
@param integer  to set the weight limit 
@param integer  to set the Current weight of the passenger
@param integer  to set Minimum number of floors the lift goes
@param integer  to set Maximum number of floors the lift can go
@param integer  to set thee direction of the lift
@param boolean   to open the doors of the lift
*/
class Lift {
public:
	Lift(int, int, int, int, int, int, bool);        /*Lift contains its identity, the weight limit, current weight,minimum floors, maximum floor, direction, open doors*/
	int getID();                                                      /*get the lift identity*/
	void setID(int);                                                  /*@param set the lift identity*/
	int getWLimit();                                                 /*get the weight limit*/
	void setWLimit(int);                                            /*@param set weight limit*/
	int getCurWeight();                                            /*get the current weight*/
	void setCurWeight(int);                                       /*@param set current weight*/
	int getMinFloor();                                           /*get the minimum floor*/
	void setMinFloor(int);                                      /*@param set the minimum floor*/
	int getMaxFloor();                                         /*get the maximum floor*/
	void setMaxFloor(int);                                    /*@param set the maximum floor*/
	int getFloor();                                          /*get the floor*/
	void setFloor(int);                                     /*@param set the floor*/
	int getDirection();                                    /*get the direction*/
	void setDirection(int);                               /*@param set the direction*/
	vector <int> getNextDests();                         /*get to next destination*/
	void updateNextDests(vector<int>);                  /*@param  update the next destination*/
	void performStep();                                /*lift perform the steps */
//		bool areDoorsOpen();
//		void setDoorsOpen(bool);
private:
	vector<int> nextDests;
	int ID;
	int wLimit;
	int curWeight;
	int minFloor;
	int maxFloor;
	int floor;
	int direction;
	bool doorsOpen;
//		int speed;
//		int failureRate;

};
#endif
