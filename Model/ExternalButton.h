#ifndef externalButton_H_
#define externalButton_H_
using namespace std;


/*Derived class
* @param Exteral button  to set the direction
* @param  boolean external button pressed
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

class externalButton
{

   public:
   externalButton(int fl,int dir);
   int getFlr();
   void setFlr(int);
   int getDir();
   void setDir(int);
   bool isPressed();
   void setPressed(bool);                   /*@param boolean when set pressed*/
   private:
   int floor;
   int direction;
   bool pressed;                           /*@param boolean exteral button pressed */
};


#endif /* externalButton_H_ */