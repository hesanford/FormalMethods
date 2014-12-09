#include <iostream>
#include "Clock.h"
#include <ctime>
using namespace std;
/*Clock time
* @param int clock time
*@return start time

*/
Clock::Clock()       /*Clock constructor*/
{

	begin = time(NULL);       /*clock is set to begin*/
	current = begin;
	counter=0;
	}
bool Clock::nextTick()     /*@param the Clock get time */
{
		time_t update = time(NULL);
		if(update > current){
			current = update;
			return true;
		}
		return false;

}

int Clock::getCounter(){
	return time(NULL) - begin;
}

/*@param boolean clock ticks
*@param integer ger the time
@return clock tick 
*/


