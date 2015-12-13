TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11


LIBS += -L"/usr/local/lib"

#http://www.sfml-dev.org/tutorials/2.3/start-osx.php

include(deployment.pri)
qtcAddDeployment()

LIBS += -L "..\SFML-2.3.2\lib"


CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

# /user/.., not usr/...
INCLUDEPATH += "..\SFML-2.3.2\include"
DEPENDPATH += "..\SFML-2.3.2\include"

SOURCES += main.cpp \
    game.cpp



HEADERS += \
    constants.h \
    game.h
