#ifndef internalButton_H_
#define internalButton_H_
using namespace std;


class internalButton
{
   public:
   internalButton(int ,int );
   int getDestination();
   void setDestinationFlr(int);
   int getliftID();
   void setliftID(int);
   bool isPressed();
   void setPressed(bool);
   private:
   int liftID;
   int destination;
   bool pressed;

};



#endif /* internalButton_H_ */
