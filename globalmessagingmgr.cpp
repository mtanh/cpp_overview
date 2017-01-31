#include "globalmessagingmgr.h"

GlobalMessagingMgr* GlobalMessagingMgr::theGlobalMgrInstance = nullptr;

GlobalMessagingMgr::GlobalMessagingMgr()
{
  std::cout << __FUNCTION__ << '\n';
}

GlobalMessagingMgr::~GlobalMessagingMgr()
{
  std::cout << __FUNCTION__ << '\n';
}

GlobalMessagingMgr& GlobalMessagingMgr::getGlobalInstance()
{
  if(nullptr == theGlobalMgrInstance) {
      Initialize();
    }
  return *theGlobalMgrInstance;
}

void GlobalMessagingMgr::Initialize()
{
  theGlobalMgrInstance = new GlobalMessagingMgr();
}

void GlobalMessagingMgr::Terminate()
{
  if(theGlobalMgrInstance != nullptr)
    {
      delete theGlobalMgrInstance;
      theGlobalMgrInstance = nullptr;
    }
}

