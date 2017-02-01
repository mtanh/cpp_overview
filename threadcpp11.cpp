#include <iostream>
#include "threadcpp11.h"

ThreadCpp11::~ThreadCpp11()
{
    if(mThreadEntry)
    {
        delete mThreadEntry;
        mThreadEntry = nullptr;
    }
}

void ThreadCpp11::startThread()
{
    if(mThreadEntry != nullptr)
    {
        std::cout << __FUNCTION__ << '\n';
        std::thread tmp(*mThreadEntry);
        tmp.swap(mThread);
    }
}

void ThreadCpp11::joinThread()
{
    if(mThread.joinable())
    {
        mThread.join();
    }
}
