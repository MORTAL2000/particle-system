CONFIG += console release
QT += core gui opengl
TARGET = ParticleSystem
TEMPLATE = app

DEPENDPATH += src

win32 {
    INCLUDEPATH = src "../lib/glew-mingw/include"
    LIBS += -L"..\lib\glew-mingw\lib" -lglew32
}

unix:!macx {
	INCLUDEPATH = src "../lib/glew-unix/include"
	LIBS += -L"../lib/glew-unix/lib" -lGLEW
}

macx {
	INCLUDEPATH = src "../lib/glew-osx/include"
	LIBS += -L"../lib/glew-osx/lib" -lGLEW
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
    src/scene.h \
    src/scenenode.h \
	src/modelnode.h \
    src/mesh.h \
    src/shadermanager.h \
	src/bufferattribute.h \
	src/camera.h

SOURCES += \
    src/app.cpp \
    src/main.cpp \
    src/math/matrix3.cpp \
    src/math/matrix4.cpp \
    src/math/vec2.cpp \
    src/math/vec3.cpp \
    src/math/quaternion.cpp \
    src/renderer.cpp \
    src/shader.cpp \
    src/scene.cpp \
    src/scenenode.cpp \
	src/modelnode.cpp \
    src/mesh.cpp \
	src/shadermanager.cpp \
	src/camera.cpp

OTHER_FILES += \
    ../build/shaders/default.frag \
    ../build/shaders/default.vert
