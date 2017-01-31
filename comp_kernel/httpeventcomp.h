#ifndef HTTPEVENTCOMP_H
#define HTTPEVENTCOMP_H

#include "eventcomp.h"

const char CompName[] = "HTTP_EVENT_COMP";

class HttpEventComp: public EventComp
{
public:
    HttpEventComp();
    ~HttpEventComp();

    bool Init();
    void onEvent(void* data = nullptr);
};

#endif // HTTPEVENTCOMP_H

