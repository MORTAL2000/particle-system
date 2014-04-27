#include "app.h"

App::App()
{
    scene = new Scene(NULL);
    renderer = new Renderer(scene);
}

App::~App() {
    delete renderer;
    delete scene;
}

void App::initializeGL() {
    timer.start();
    float c = 150 / 255.0;
    glClearColor(c, c, c, c);
}

void App::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    renderer->render(timer.elapsed());
}
