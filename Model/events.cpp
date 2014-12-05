#include <iostream>
#include < vector>
#include "event.h"
#include "Lift.h"
#include "Passenger.h"
#include< string>


using namespace std;

//declare delgates
delegate void ClocktickEventHandler(String,String);
//delegate void DblClockEventHandler(String);
//class that defines events
class Event
{
public:
	event ClockEventHandler Onclocktick;
	//event DblClockEventHandler OnDblClock;

	void FireEvents()
	{
		OnClock(l, p);

	}
	class EventReciever
	{
	public:
		void Onclocktick(String, String){
	//Console::Writeline("OnClock : {0}, {1}", str, str);
	};
};
int main()
{
	Event MyEvent = gcnew Event;
	//hook handler to event
	Event->OnClock += gcnew ClockEventHandler(MyEventReceiver, &EventReceiver::OnClocktick);
	//invoke events
	MyEvent->FireEvents();
	//unhook handler to event
	MyEvent->OnClock -= gcnew ClockEventHandler(MyEventReceiver, &EventReceiver::OnClcocktick);
	
}

