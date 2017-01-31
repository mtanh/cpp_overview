#ifndef EVENTCOMP_H
#define EVENTCOMP_H

#include "eventable.h"

class EventComp: public EventAble
{
public:
    EventComp() {}
    virtual ~EventComp() {}
    virtual bool Init() = 0;
};

#endif // EVENTCOMP_H
