#ifndef EVENTABLE_H
#define EVENTABLE_H

class EventComp;

class EventAble
{
public:
    virtual void onEvent(EventComp* comp, void* data = nullptr) = 0;
};

#endif // EVENTABLE_H

