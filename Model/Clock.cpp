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
	return ((clock() - begin) % x);       /*@return the clock begins*/
}
