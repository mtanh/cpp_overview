#ifndef GLOBALMESSAGINGMGR_H
#define GLOBALMESSAGINGMGR_H

#include <iostream>
#include "noncopyable.h"

class GlobalMessagingMgr: private NonCopyable
{
public:
  ~GlobalMessagingMgr();
  static GlobalMessagingMgr& getGlobalInstance(); // not thread-safe. use with care
  void Terminate();

  void f1() { std::cout << __FUNCTION__ << '\n'; }

private:
  GlobalMessagingMgr();
  static void Initialize();

private:
  static GlobalMessagingMgr* theGlobalMgrInstance;
};

#endif // GLOBALMESSAGINGMGR_H
