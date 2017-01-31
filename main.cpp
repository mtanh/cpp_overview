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

#include "globalmessagingmgr.h"
#include "rational.h"
#include "rationalutils.h"
#include "copyandswap.h"
#include "avoireturnhandletointernalclassresource.h"

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

int main()
{


    return 0;
}
