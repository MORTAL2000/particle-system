#ifndef APP_H
#define APP_H

#include "GL/glew.h"

#include <QGLWidget>
#include <QElapsedTimer>
#include <iostream>
#include "renderer.h"
#include "scene.h"
#include "shadermanager.h"

class App : public QGLWidget
{
private:
    Renderer* renderer;
    Scene* scene;
    QElapsedTimer timer;
    ShaderManager* shaderManager;
public:
    App();
    ~App();
    void paintGL();
    void initializeGL();
};

#endif // APP_H
