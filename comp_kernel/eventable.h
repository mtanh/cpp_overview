#ifndef EVENTABLE_H
#define EVENTABLE_H

class EventAble
{
public:
    virtual void onEvent(void* data = nullptr) = 0;
};

#endif // EVENTABLE_H

