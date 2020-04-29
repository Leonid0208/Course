TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "/home/leonid/C++/gumbo-query/src"
INCLUDEPATH += "~/C++/gumbo-parser-master/src"

LIBS += -lgq
LIBS += -lgumbo


SOURCES += main.cpp \
    test.cpp

DISTFILES += \
    Index.html
