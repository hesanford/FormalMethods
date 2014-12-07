#include <iostream>
#include "Clock.h"
using namespace std;
Clock::Clock()
{
	begin=clock();
	counter=0;
	}
clock_t Clock:: getTime(){
return (clock()-begin);
}
bool Clock::Tick(int x)
{
	if((getTime()/x)>counter)
		return 1;
	else
		return 0;
	}
