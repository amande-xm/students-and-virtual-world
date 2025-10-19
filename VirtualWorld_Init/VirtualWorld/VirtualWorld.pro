# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = TP4_VirtualWorld
QT       += core gui opengl widgets
CONFIG += c++17
QMAKE_CFLAGS += -DENABLE_QT6=0

HEADERS = \
   circle.h \
   controller.h \
   group.h \
   observer.h \
   rectangle.h \
   shape.h \
   shapefactory.h \
   shapemanager.h \
   paintview.h \
   square.h \
   treeview.h \
   virtualworld.h

SOURCES = \
   circle.cpp \
   controller.cpp \
   group.cpp \
   main.cpp \
   paintview.cpp \
   rectangle.cpp \
   shape.cpp \
   shapefactory.cpp \
   shapemanager.cpp \
   square.cpp \
   treeview.cpp \
   virtualworld.cpp

FORMS += \
    virtualworld.ui

RESOURCES += \
    virtualworld.qrc

#DEFINES = 

