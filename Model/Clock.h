#ifndef CLOCK_H_
#define CLOCK_H_
#include <ctime>
using namespace std;

class Clock {
public:
	Clock();
	clock_t getTime(int );
private:
	clock_t begin;




};
#endif /* CLOCK_H_ */
