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
    src/app.h \
    src/math/matrix3.h \
    src/math/matrix4.h \
    src/math/vec2.h \
    src/math/vec3.h \
    src/math/vec4.h \
    src/math/mathshelpers.h \
    src/math/quaternion.h

SOURCES += \
    src/app.cpp \
    src/main.cpp \
    src/math/matrix3.cpp \
    src/math/matrix4.cpp \
    src/math/vec2.cpp \
    src/math/vec3.cpp \
    src/math/quaternion.cpp
