#ifndef APP_H
#define APP_H

#include <QGLWidget>
#include <QElapsedTimer>
#include <iostream>
#include "renderer.h"
#include "scene.h"

class App : public QGLWidget
{
private:
    Renderer* renderer;
    Scene* scene;
    QElapsedTimer timer;
public:
    App();
    ~App();
    void paintGL();
    void initializeGL();
};

#endif // APP_H
