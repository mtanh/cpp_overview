#include "kernelcomp.h"
#include "eventcomp.h"

KernelComp::KernelComp()
{
}

KernelComp::~KernelComp()
{
    mEventList.clear();
}

bool KernelComp::RegisterEventComp(EventComp *comp)
{
    bool returnCode = true;
    do
    {
        if(nullptr == comp)
        {
            returnCode = false;
            break;
        }

        {
            std::lock_guard<std::mutex> guard(mEventListGuard);
            mEventList.push_back(comp);
        }

    } while(false);

    return returnCode;
}

void KernelComp::ThrowEvent(void *data)
{
    {
        std::lock_guard<std::mutex> guard(mEventListGuard);
        for(EventCompList::iterator iter=mEventList.begin();
            iter!=mEventList.end();
            ++iter)
        {
//            iter->onEvent(iter, data);
        }
    }
}
