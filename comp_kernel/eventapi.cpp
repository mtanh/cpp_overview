#include "eventapi.h"
#include "kernelcomp.h"

KernelComp ConnectionOpenEvent;
KernelComp ConnectionCloseEvent;
KernelComp ImageMsgEvent;
KernelComp TextMsgEvent;

void RegisterEvent(EventComp *comp, EventCode event_code)
{
    // checking input
    if(nullptr==comp) {
        return;
    }

    switch (event_code)
    {
    case EVENT_CONN_OPEN:
        ConnectionOpenEvent.RegisterEventComp(comp);
        break;
    case EVENT_CONN_CLOSE:
        ConnectionCloseEvent.RegisterEventComp(comp);
        break;
    case EVENT_IMG_MSG:
        ImageMsgEvent.RegisterEventComp(comp);
        break;
    case EVENT_TEXT_MSG:
        TextMsgEvent.RegisterEventComp(comp);
        break;
    case EVENT_INVALID:
    default:
        break;
    }
}
