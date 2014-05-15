#include "app.h"

App::App()
{
    initGlew();

    Quaternion cameraOrientation(0, Vec3::up());
    Camera *camera = new Camera(Vec3::zero(), cameraOrientation, width() / height());

    scene = new Scene(camera);
    shaderManager = new ShaderManager();
    renderer = new Renderer(scene, shaderManager);

    initShaders();

    setMouseTracking(true);
}

App::~App() {
    delete shaderManager;
    delete renderer;
    delete scene;
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
    try {
        shaderManager->addShader("default");
    } catch(exception &e) {
        cerr << e.what();
    }
}

void App::initializeGL() {
    timer.start();
    float c = 150 / 255.0;
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

void App::mouseMoveEvent(QMouseEvent *event)
{
    const float mouseSensivity = 0.1f;
    QPoint cursor = event->pos();
    float cx = cursor.x();
    float cy = cursor.y();

    Camera *camera = scene->getCamera();

    if(camera) {
        camera->rotateY(cx * mouseSensivity);
        camera->rotateX(cy * mouseSensivity);
    }
}
