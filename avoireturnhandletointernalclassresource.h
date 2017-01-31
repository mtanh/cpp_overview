#ifndef AVOIRETURNHANDLETOINTERNALCLASSRESOURCE_H
#define AVOIRETURNHANDLETOINTERNALCLASSRESOURCE_H

typedef struct InternalHandle
{
    int a;
    double b;
} InternalHandle;

class AvoiReturnHandle
{
public:
    AvoiReturnHandle() {}
    AvoiReturnHandle(const InternalHandle& h): mHandle(h) {}
    ~AvoiReturnHandle() {}

    InternalHandle& getHandle() /*const*/ { return mHandle; }

private:
    AvoiReturnHandle(const AvoiReturnHandle& other) = delete;
    AvoiReturnHandle& operator =(AvoiReturnHandle other) = delete;

private:
    InternalHandle mHandle;
};

#endif // AVOIRETURNHANDLETOINTERNALCLASSRESOURCE_H
