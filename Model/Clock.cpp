#include <iostream>
#include "Clock.h"
using namespace std;
/*Clock time
* @param int clock time
*@return start time

*/
Clock::Clock()       /*Clock constructor*/
{

	begin = clock();       /*clock is set to begin*/
	}
clock_t Clock::getTime(int x)     /*@param the Clock get time */
{
	return ((clock() - begin) % x);       /*@return when clock begins*/

	begin=clock();
	counter=0;
	}
clock_t Clock:: getTime(){
	return (clock() - begin);                  /*@return  get the time  when clock begins*/

}
/*@param boolean clock ticks
*@param integer ger the time
@return clock tick 
*/

bool Clock::Tick(int x)
{
	if((getTime()/x)>counter)
		return 1;
	else
		return 0;
	}