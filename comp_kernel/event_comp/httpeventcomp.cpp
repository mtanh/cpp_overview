#include <httpeventcomp.h>
#include <eventapi.h>
#include <string.h>
#include <iostream>
#include <thread>
#include <chrono>

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
    // should make threadpool to process the heavy load tasks here
    std::cout << getName() << '\n';
    return;
}
