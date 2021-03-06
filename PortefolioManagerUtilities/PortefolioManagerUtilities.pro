# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = lib
TARGET = PortefolioManagerUtilities
DESTDIR = ../x64/Release
QT += core network networkauth
CONFIG += release
DEFINES += _UNICODE WIN64 QT_DLL PORTEFOLIOMANAGERUTILITIES_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/$(ConfigurationName)
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += release
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
HEADERS += ./PortefolioManagerUtilities.h \
    ./portefoliomanagerutilities_global.h \
    ./LoginManager.h \
    ./NetworkManager.h \
    ./ProjectManager.h
SOURCES += ./PortefolioManagerUtilities.cpp \
    ./LoginManager.cpp \
    ./NetworkManager.cpp \
    ./ProjectManager.cpp
