#ifndef EVENT_H
#define EVENT_H
#include <vector>
#include <iostream>

using namespace std;
/*
Event class
*@param event for clock

*/
class Event
{
public:
	event ClockEventHandler OnClock;/* clock event handler to set the clock on*/
	void OnClocktime(String, String) /*On clock time passed to set the string */
	
};
#endif
