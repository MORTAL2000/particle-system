#include "app.h"

App::App()
{
    Camera *camera = new Camera(Vec3(0.0, 0.0, 4.0), Quaternion(0, Vec3(1.0, 0.0, 0.0)), width() / height());

    scene = new Scene(camera);
    shaderManager = new ShaderManager();
    renderer = new Renderer(scene, shaderManager);
}

App::~App() {
    delete shaderManager;
    delete renderer;
    delete scene;
}

void App::init()
{
    resize(800, 600);

    startTimer(30);

    initGlew();

    initShaders();

    SceneBuilder::buildScene(scene, renderer);

    setMouseTracking(true);
}

void App::initGlew()
{
    glInit();
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (err != GLEW_OK)
        cout<<"glewInit failed, aborting. error: "<< glewGetErrorString(err) << endl;
}

void App::initShaders()
{
    shaderManager->init();
    shaderManager->addShader("default");
}

void App::initializeGL() {
    timer.start();
    float c = 0;
    glClearColor(c, c, c, c);
    glEnable(GL_DEPTH_TEST);
}

void App::resizeGL(int w, int h)
{
    Camera *camera = scene->getCamera();

    if(camera) {
        camera->setAspectRatio(w / h);
    }
}

void App::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    renderer->render(timer.elapsed());
}

void App::timerEvent(QTimerEvent *)
{
    updateGL();
}

void App::mouseMoveEvent(QMouseEvent *event)
{
    const float mouseSensivity = 5e-3f;

    QPoint cursor = event->pos();

    float dx = cursor.x() - lastCursorPos.x();
    float dy = cursor.y() - lastCursorPos.y();

    Camera *camera = scene->getCamera();

    if(camera) {
        camera->rotateY(dx * mouseSensivity);
        camera->rotateX(dy * mouseSensivity);
    }

    lastCursorPos = cursor;
}

void App::keyPressEvent(QKeyEvent* event)
{
    Camera *camera = scene->getCamera();
    const float camSpeed = 0.5;

    switch(event->key())
    {
        case Qt::Key_Escape:
            close();
            break;

        case Qt::Key_Left:
            camera->translate(-camera->right() * camSpeed);
            break;

        case Qt::Key_Right:
            camera->translate(camera->right() * camSpeed);
            break;

        case Qt::Key_Up:
            camera->translate(camera->forward() * camSpeed);
            break;

        case Qt::Key_Down:
            camera->translate(-camera->forward() * camSpeed);
            break;
    }
}
