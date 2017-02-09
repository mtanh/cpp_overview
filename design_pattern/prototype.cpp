#include "prototype.h"

Prototype* Factory::mHugeClass1 = nullptr;
Prototype* Factory::mHugeClass2 = nullptr;

void Factory::initialize()
{
    mHugeClass1 = new HugeClass1;
    mHugeClass2 = new HugeClass2;
}

void Factory::terminate()
{
    delete mHugeClass1; mHugeClass1 = nullptr;
    delete mHugeClass2; mHugeClass2 = nullptr;
}

Prototype *Factory::genHugeClass(int type)
{
    Prototype* res = nullptr;
    switch (type)
    {
    case one:
        res = mHugeClass1->clone();
        break;
    case two:
        res = mHugeClass1->clone();
        break;
    default:
        break;
    }

    return res;
}
