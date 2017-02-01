#ifndef THREADCPP11_H
#define THREADCPP11_H

#include <thread>
#include <chrono>
#include <iostream>

class EntryBase
{
public:
    EntryBase() {}
    virtual ~EntryBase() {}

    virtual void operator()()
    {
        std::cout << __FUNCTION__ << '\n';
    }
};

class ThreadEntry: public EntryBase
{
public:
    ThreadEntry(): EntryBase() {}
    ~ThreadEntry() {}

    void operator ()()
    {
        for(;;)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << __FUNCTION__ << '\n';
        }
    }
};

class ThreadCpp11
{
public:
    ThreadCpp11(): mThreadEntry(nullptr) {}
    ThreadCpp11(EntryBase* entry): mThreadEntry(entry) {}
    ~ThreadCpp11();

    void startThread();
    void joinThread();

private:
    std::thread mThread;
    EntryBase* mThreadEntry;
};

#endif // THREADCPP11_H
