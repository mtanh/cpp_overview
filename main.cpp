#include <stdexcept>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <array>
#include <map>
#include <list>
#include <string>
#include <cinttypes>
#include <stdlib.h>
#include <bitset>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <numeric>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

#include "globalmessagingmgr.h"
#include "rational.h"
#include "rationalutils.h"
#include "copyandswap.h"
#include "avoireturnhandletointernalclassresource.h"
#include <design_pattern/prototype.h>

#include <kernelcomp.h>
#include <httpeventcomp.h>
#include <threadcpp11.h>

void SingletonTest()
{
    GlobalMessagingMgr& gMsgMgr = GlobalMessagingMgr::getGlobalInstance();
    std::cout << &gMsgMgr << '\n';
    GlobalMessagingMgr& tmp = gMsgMgr;
    tmp.f1();
    gMsgMgr.Terminate();

    GlobalMessagingMgr& gMsgMgr1 = GlobalMessagingMgr::getGlobalInstance();
    std::cout << &gMsgMgr1 << '\n';
}

void NotMemberFuncTest()
{
    Math::Rational r1(Math::Numerator(1), Math::Denominator(2));
    Math::Rational r2(Math::Numerator(2), Math::Denominator(3));
    Math::Rational r3 = r1*r2;

    std::cout << r3.getNumerator().numerator << '\n';
    std::cout << r3.getDenominator().denominator << '\n';
}

void CopyAndSwapTest()
{
    const char strTmp[] = "SAMPLE TEST";
    Handle* h1 = new Handle;
    h1->allocateBuffer(sizeof(strTmp), strTmp);

    CopyAndSwap cas1;
    cas1.setHandle(h1);
    cas1.getHandle()->toString();

    CopyAndSwap cas2;
    cas2 = cas1;
    cas2.getHandle()->toString();
}

void AvoidReturnHandleTest()
{
    InternalHandle h;
    h.a = 1;
    h.b = 2;

    AvoiReturnHandle arh(h);
    //    InternalHandle tmp = arh.getHandle();
    arh.getHandle().a = 3;
    //    tmp.a = 3;
    //    arh.getHandle().a = 3;

    std::cout << arh.getHandle().a;
}

void Comp_KernelTest()
{
    HttpEventComp httpComp;
    httpComp.Init();

    ConnectionOpenEvent.ThrowEvent(nullptr);
}

void ThreadCpp11Test()
{
    EntryBase* entry = new ThreadEntry();
    ThreadCpp11 simpleThread(entry);


    simpleThread.startThread();
    simpleThread.joinThread();
}

void foo(int& val)
{
    val++;
    std::cout << val << '\n';
}

void DP_PrototypeTest()
{
    Factory f;
    f.initialize();

    Prototype* huge1 = f.genHugeClass(one);
    std::cout << "Done\n";

    Prototype* huge11 = f.genHugeClass(one);
    std::cout << "Done\n";

    delete huge1; huge1 = NULL;
    delete huge11; huge11 = NULL;
    f.terminate();

//    Prototype* aaa = new HugeClass1;
//    std::cout << "Done\n";

//    Prototype* bbb = new HugeClass1;
//    std::cout << "Done\n";

//    delete aaa;
//    delete bbb;
}

int main()
{
    DP_PrototypeTest();

    return 0;
}
