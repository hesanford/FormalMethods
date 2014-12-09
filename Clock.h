#ifndef CLOCK_H_
#define CLOCK_H_
#include <ctime>
using namespace std;
/* Clock class
@param integer time
@param begin time
*/
class Clock {
public:
	Clock();

	bool nextTick();       /* @param get time */
	int getCounter();
	bool Tick(int x);  /*get the time when clock ticks */
private:
	time_t begin;              /*@param clock time access to begin*/
	time_t current;
	int counter;



};
#endif /* CLOCK_H_ */
