#ifndef COPYANDSWAP_H
#define COPYANDSWAP_H

#include <vector>

class Handle;

class CopyAndSwap
{
public:
    CopyAndSwap();
    ~CopyAndSwap();

    CopyAndSwap(const CopyAndSwap& other);
    CopyAndSwap &operator =(CopyAndSwap other);

    friend void swap(CopyAndSwap& lhs,
                     CopyAndSwap& rhs);

    void setHandle(const Handle* h) { mHandle = h; }
    const Handle *getHandle() const { return mHandle; }

private:
    const Handle* mHandle;
    int mIntData;
    double mDoubleData;
};

class Handle
{
public:
    Handle();
    ~Handle();

    Handle(const Handle& other);
    Handle operator =(Handle other);

    friend void swap(Handle& lhs,
                     Handle& rhs);

    bool allocateBuffer(unsigned int size,
                        const char* buf);
    void toString() const {
        printf("%s\n", mBuffer!=nullptr?mBuffer:"null");
    }

private:
    int mBufSize;
    char* mBuffer; // Inline buffer. TODO: Pointer buffer
    bool mInitialized;
};

#endif // COPYANDSWAP_H
