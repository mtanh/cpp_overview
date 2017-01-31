#ifndef EVENTAPI_H
#define EVENTAPI_H

#include "eventcode.h"

class EventComp;

void RegisterEvent(EventComp* comp, EventCode event_code);

#endif // EVENTAPI_H

