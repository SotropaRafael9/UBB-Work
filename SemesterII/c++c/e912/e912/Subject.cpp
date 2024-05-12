#include "Subject.h"

void Subject::addObserver(Observer* o)
{
	observers.push_back(o);
}

void Subject::notify()
{
	for (auto& observer: observers)
		observer->update();
}
