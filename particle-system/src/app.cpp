#include "app.h"

App::App()
{
    Quaternion cameraOrientation(0, Vec3(1.0, 0.0, 0.0));
    Camera *camera = new Camera(Vec3(0.0, 0.0, 1.0), cameraOrientation, width() / height());

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
    const float mouseSensivity = 0.1f;
    QPoint cursor = event->pos();
    float cx = cursor.x();
    float cy = cursor.y();

    Camera *camera = scene->getCamera();

    if(camera) {
        //camera->rotateY(cx * mouseSensivity);
        //camera->rotateX(cy * mouseSensivity);
    }
}
