CONFIG += console release
QT += core gui opengl
TARGET = ParticleSystem
TEMPLATE = app

DEPENDPATH += src
INCLUDEPATH = src "../lib/glew-mingw/include"

win32 {
    LIBS += -L"..\lib\glew-mingw\lib" -lglew32
}

DESTDIR = ../build/
OBJECTS_DIR = ../build/obj

# Input
HEADERS += \
    src/app.h

SOURCES += \
    src/app.cpp \
    src/main.cpp
