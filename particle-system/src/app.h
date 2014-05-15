#ifndef APP_H
#define APP_H

#include "GL/glew.h"

#include <QGLWidget>
#include <QMouseEvent>
#include <QElapsedTimer>
#include <iostream>
#include "renderer.h"
#include "scene.h"
#include "shadermanager.h"
#include "scenebuilder.h"

class App : public QGLWidget
{
private:
    Renderer* renderer;
    Scene* scene;
    QElapsedTimer timer;
    ShaderManager* shaderManager;

    void initShaders();
    void initGlew();

public:
    App();
    ~App();

    void init();

    void paintGL();
    void resizeGL(int w, int h);
    void initializeGL();
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // APP_H
