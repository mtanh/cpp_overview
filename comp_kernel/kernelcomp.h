#ifndef KERNELCOMP_H
#define KERNELCOMP_H

#include <vector>
#include <mutex>
#include "throwable.h"

class EventComp;

class KernelComp: public ThrowAble
{
public:
    KernelComp();
    ~KernelComp();

    bool RegisterEventComp(EventComp* comp);
    KernelComp &getInstance();
    void ThrowEvent(void* data);

private:

    KernelComp(const KernelComp& other) = delete;
    KernelComp& operator =(const KernelComp& other) = delete;

private:
    std::mutex mEventListGuard;

    typedef std::vector<EventComp*> EventCompList;
    EventCompList mEventList;
};

extern KernelComp ConnectionOpenEvent;
extern KernelComp ConnectionCloseEvent;
extern KernelComp ImageMsgEvent;
extern KernelComp TextMsgEvent;

#endif // KERNELCOMP_H
