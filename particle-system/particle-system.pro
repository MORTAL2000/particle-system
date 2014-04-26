CONFIG += console release
QT += core gui opengl
TARGET = ParticleSystem
TEMPLATE = app

DEPENDPATH += src

win32 {
    INCLUDEPATH = src "../lib/glew-mingw/include"
    LIBS += -L"..\lib\glew-mingw\lib" -lglew32
}

macx {
    INCLUDEPATH = src "../lib/glew-osx/include"
    LIBS += -L"../lib/glew-osx/lib"
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
    src/math/quaternion.h \
    src/renderer.h \
    src/renderframework.h \
    src/matrixstack.h \
    src/shader.h \
    src/bufferattributes.h

SOURCES += \
    src/app.cpp \
    src/main.cpp \
    src/math/matrix3.cpp \
    src/math/matrix4.cpp \
    src/math/vec2.cpp \
    src/math/vec3.cpp \
    src/math/quaternion.cpp \
    src/renderer.cpp \
    src/shader.cpp
