TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += comp_kernel

SOURCES += main.cpp \
    globalmessagingmgr.cpp \
    rational.cpp \
    rationalutils.cpp \
    copyandswap.cpp \
    avoireturnhandletointernalclassresource.cpp \
    comp_kernel/eventapi.cpp \
    comp_kernel/kernelcomp.cpp \
    comp_kernel/event_comp/httpeventcomp.cpp \
    threadcpp11.cpp
QMAKE_CXXFLAGS += -std=c++11 -pthread
LIBS += -pthread

HEADERS += \
    globalmessagingmgr.h \
    noncopyable.h \
    rational.h \
    rationalutils.h \
    copyandswap.h \
    avoireturnhandletointernalclassresource.h \
    comp_kernel/eventable.h \
    comp_kernel/eventcomp.h \
    comp_kernel/eventapi.h \
    comp_kernel/eventcode.h \
    comp_kernel/throwable.h \
    comp_kernel/kernelcomp.h \
    comp_kernel/httpeventcomp.h \
    threadcpp11.h

