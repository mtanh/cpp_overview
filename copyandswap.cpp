#include <string.h>
#include <stdio.h>
#include <iostream>

#include "copyandswap.h"

CopyAndSwap::CopyAndSwap()
    : mHandle(nullptr)
    , mIntData(0)
    , mDoubleData(0.0)
{
}

CopyAndSwap::~CopyAndSwap()
{
    if(mHandle)
    {
        delete mHandle;
        mHandle = nullptr;
    }
}

CopyAndSwap::CopyAndSwap(const CopyAndSwap &other)
    : mHandle(new Handle(*other.mHandle))
    , mIntData(other.mIntData)
    , mDoubleData(other.mDoubleData)
{
}

CopyAndSwap &CopyAndSwap::operator =(CopyAndSwap other)
{
    swap(*this, other);
    return *this;
}

void swap(CopyAndSwap &lhs, CopyAndSwap &rhs)
{
    using std::swap;
    swap(lhs.mHandle, rhs.mHandle);
    swap(lhs.mIntData, rhs.mIntData);
    swap(lhs.mDoubleData, rhs.mDoubleData);
}

Handle::Handle()
    : mBufSize(0)
    , mBuffer(nullptr)
    , mInitialized(false)
{
}

Handle::~Handle()
{
    if(mBuffer)
    {
        delete[] mBuffer;
        mBuffer = nullptr;
    }
}

Handle::Handle(const Handle &other)
    : mBuffer((other.mBuffer<=0) ? nullptr : new char[mBufSize])
    , mBufSize(other.mBufSize)
{
    memcpy(mBuffer, other.mBuffer, mBufSize);
}

Handle Handle::operator =(Handle other)
{
    swap(*this, other);
    return *this;
}

bool Handle::allocateBuffer(unsigned int size, const char *buf)
{
    bool returnCode = true;

    do {
        if(mInitialized)
        {
            returnCode = false;
            break;
        }

        // checking input
        // ...

        // just demo simple version of buffer data within class
        // it should be done with multiple mode {Inline-Buffer, Pointer-2-Buffer, ...}
        // in order to support the append/remove buffer fragment
        mBufSize = size;
        mBuffer = new char[mBufSize];
        memcpy(mBuffer, buf, size);

        mInitialized = true;

    } while(false);

    return returnCode;
}

void swap(Handle &lhs, Handle &rhs)
{
    using std::swap;
    swap(lhs.mBufSize, rhs.mBufSize);
    swap(lhs.mBuffer, rhs.mBuffer);
}
