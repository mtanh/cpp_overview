#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <iostream>

class Prototype
{
public:
    Prototype() {}
    virtual ~Prototype() {}

    virtual Prototype* clone() = 0;
};

class HugeClass1: public Prototype
{
public:
    HugeClass1()
    {
        for(int i=0; i < 2000000000; ++i)
        {
        }
    }

    ~HugeClass1() {}
    Prototype* clone() { return new HugeClass1(*this); }
};

class HugeClass2: public Prototype
{
public:
    HugeClass2()
    {
        for(int i=0; i < 500000; ++i)
        {
        }
    }

    ~HugeClass2() {}
    Prototype* clone() { return new HugeClass2(*this); }
};

enum
{
    one = 0,
    two
};

class Factory
{
public:
    Factory() {}
    ~Factory() {}

    void initialize();
    void terminate();
    Prototype *genHugeClass(int type);

private:
    static Prototype* mHugeClass1;
    static Prototype* mHugeClass2;

private:
    Factory(const Factory& other) = delete;
    Factory& operator =(Factory other) = delete;
};

#endif // PROTOTYPE_H
