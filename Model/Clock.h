#ifndef CLOCK_H_
#define CLOCK_H_
#include <ctime>
using namespace std;

class Clock {
public:
	Clock();
	clock_t getTime();
	bool Tick(int x);
private:
	clock_t begin;
	int counter;



};
#endif /* CLOCK_H_ */
