#ifndef APP_H
#define APP_H

#include <QGLWidget>
#include <QElapsedTimer>
#include <iostream>
#include "renderer.h"

class App : public QGLWidget
{
private:
    Renderer renderer;
    QElapsedTimer timer;
public:
    App();
    void paintGL();
    void initializeGL();
};

#endif // APP_H
