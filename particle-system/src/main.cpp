#include <QApplication>
#include "app.h"
#include "camera.h"

int main(int argc, char *argv[]) {
    Vec3 position(0,0,0);
    Quaternion q(0.0, Vec3::up());
    Camera c(position, q, 4/3, 80, 0.1, 1000);
    cout << "up " << c.up() << endl;
    cout << "right " << c.right() << endl;
    cout << "forward " << c.forward() << endl;
    cout << c.getViewMatrix() << endl;
    QApplication app(argc, argv);
    App win;
    win.show();
    return app.exec();
}
