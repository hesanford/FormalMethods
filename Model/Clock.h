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
	clock_t getTime(int);       /* @param get time */
private:
	clock_t begin;              /*@param clock time access to begin*/




};
#endif /* CLOCK_H_ */
