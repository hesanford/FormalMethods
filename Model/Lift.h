#ifndef Lift_H
#define Lift_H
#include <vector>
#include <iostream>
#include "Passenger.h"

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

	Lift(int, int, int, int, int, int, bool);
	int getID();
	void setID(int);
	int getWLimit();
	void setWLimit(int);
	int getCurWeight();
	void setCurWeight(int);
	bool checkWeight();
	int getMinFloor();
	void setMinFloor(int);
	int getMaxFloor();
	void setMaxFloor(int);
	int getFloor();
	void setFloor(int);
	int getDirection();
	void setDirection(int);
	vector <int> getNextDests();
	void updateNextDests(vector<int>);
	void setPriority();
	int performMove(int);
    bool areDoorsOpen();
    void setDoors(bool);
    void checkPriority(int,int);
    void setPriorityList(int,int);
    vector<int> firstPriorityList;
    struct secondPriorityItem{
        int dir;
        int floorNum;
    }secondPriorityitem;
	vector<secondPriorityItem> secondPriorityList;
	bool isMoving;
    void mergeTwoList(vector<int>,vector<secondPriorityItem>);


private:

	int ID;
	int wLimit;
	int curWeight;
	int minFloor;
	int maxFloor;
	int floor;
	int direction;
	bool doorsOpen;
	vector <Passenger> passengers;
};
#endif