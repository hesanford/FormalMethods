#ifndef externalButton_H_
#define externalButton_H_
#include "Button.h"
using namespace std;

/*Derived class
* @param Exteral button is to set the direction
@param  get to the floor
*/
class externalButton: public Button/* @param set the exteral button */
{

	{

public:
		externalButton(int fl, int dir);            /*@parameter floor and direction as integer*/
		int getFlr();                              /*@parameter get to the floor */
		void setFlr(int);                         /*@parameter set the floor */
		int getDir();                            /*@parameter get a direction */
		void setDir(int);                       /*@parameter set the direction  */
private:
		int floor;                             /* button to the floor */
		int direction;                        /*button based on the direction */

	};



#endif /* externalButton_H_ */
