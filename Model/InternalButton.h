#ifndef internalButton_H_
#define internalButton_H_
using namespace std;


/*Derive the Internal button class
*@param integer  the destination floor
*@param integer  the lift identity
*@param boolean button pressed
*@return integer the destination floor number
*@return integer get the lift identification
*/
class internalButton: public Button
{
   public:
   internalButton(int, int);                /*@param capacity of the internal button first the lift identity and then the destination floor  */
   int getDestination();                   /*get to the destination*/
   void setDestinationFlr(int);           /*@param  for the desitnation floor number*/
   int getliftID();                      /*get the lift identification*/
   void setliftID(int);                 /*@param  for the  lift identification number*/
   private:
	   int liftID;                     /* capacity of the lift identification*/
	   int destination;               /* capacity of the destination*/


class internalButton
{
   public:
   internalButton(int ,int );
   int getDestination();
   void setDestinationFlr(int);
   int getliftID();
   void setliftID(int);
   bool isPressed();
   void setPressed(bool);          /*@param boolean set pressed button */
   private:
   int liftID;
   int destination;
   bool pressed;                  /*@param boolean internal button pressed*/


};



#endif /* internalButton_H_ */
