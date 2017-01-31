#ifndef EVENTCOMP_H
#define EVENTCOMP_H

#include "eventable.h"

class EventComp: public EventAble
{
public:
    EventComp() {}
    virtual ~EventComp() {}
    virtual bool Init() = 0;
    virtual void onEvent(void* data = nullptr) = 0;

    const char* getName() const { return mCompName; }

protected:
    char mCompName[50];
};

#endif // EVENTCOMP_H
