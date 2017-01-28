#include"Event.h"
//Singleton
suken::CEvent Event;



suken::CEvent::CEvent()
{
	EVERY_FRAME=FRAME_EVENT;
	LMouse.SetLeft();
	RMouse.SetRight();
	MMouse.SetMiddle();
	IsActivated = true;
}
void suken::CEvent::Loop()
{
	key.Loop();
	LMouse.Loop();
	RMouse.Loop();
	MMouse.Loop();
}
void suken::CEvent::Activate()
{
	IsActivated = true;
}
void suken::CEvent::Deactivate()
{
	IsActivated = false;
}
bool suken::CEvent::GetValid()
{
	return IsActivated;
}

