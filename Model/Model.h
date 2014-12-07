#ifndef MODEL_H_
#define MODEL_H_
#include <vector>
#include <iostream>
#include "Passenger.h"
#include "Lift.h"
#include "internalButton.h"
#include "externalButton.h"
#include <list>
using namespace std;
/*Model class
@param boolean update 
@param boolean change
@param integer liftcount
@param integer minimum floor
@param integer maximum floor*/
class Model {
public:
	Model(vector<string>, vector<string>);

	void update(bool);                                          /*@param boolean update if true, else continue*/
	bool isChanged();
	void setChanged(bool);                                     /*@param boolean set the change */
	void addLift(string);
	void addPsgr(string);
	void addButtons();
	int getMinFloor();                                         /*get the maximum floors*/
	int getMaxFloor();                                        /*get the maximum floors*/
	vector <internalButton> getInternalButtons();            /* get internal buttons*/
	vector <externalButton> getExternalButtons();           /* get external buttons*/
	std::list <externalButton> CallingFloorList();         /* calling floor list initialized extrnal buttons*/

private:
	bool changed;
	int liftCount;
	int minFloor;
	int maxFloor;
	vector<Lift> lifts;
	vector<Passenger> passengers;
	vector<internalButton> intButtons;
	vector<externalButton> extButtons;
	std::list <Passenger> ChangedPassengers();           /*change the passengers is initialized from passenger list*/
	std::list <Lift> ChangedLifts();                    /*change the lifts is initialized from lifts list */
};
#endif /* MODEL_H_ */
