#include <httpeventcomp.h>
#include <eventapi.h>
#include <string.h>
#include <iostream>

HttpEventComp::HttpEventComp(): EventComp()
{
    memcpy(mCompName, CompName, sizeof(CompName));
}

HttpEventComp::~HttpEventComp()
{
}

bool HttpEventComp::Init()
{
    RegisterEvent(this, EVENT_CONN_OPEN);
    RegisterEvent(this, EVENT_CONN_CLOSE);

    return true;
}

void HttpEventComp::onEvent(void *data)
{
    std::cout << __FUNCTION__ << '\n';
}
