#ifndef externalButton_H_
#define externalButton_H_
using namespace std;

class externalButton
{

   public:
   externalButton(int fl,int dir);
   int getFlr();
   void setFlr(int);
   int getDir();
   void setDir(int);
   bool isPressed();
   void setPressed(bool);
   private:
   int floor;
   int direction;
   bool pressed;
};



#endif /* externalButton_H_ */
