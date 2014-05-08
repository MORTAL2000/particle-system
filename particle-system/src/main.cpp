#include <QApplication>
#include "app.h"
#include "camera.h"

int main(int argc, char *argv[]) {
    Vec3 position(0,10,0);
    Vec3 xAxis(1, 0, 0);
    Quaternion q(M_PI_2, xAxis);
    Camera c(position, q, 4/3, 80, 0.1, 1000);
    cout << "up " << c.up() << endl;
    cout << "right " << c.right() << endl;
    cout << "forward " << c.forward() << endl;
    cout << c.getViewMatrix() << endl;
    cout << c.getProjectionMatrix() << endl;
    QApplication app(argc, argv);
    App win;
    win.show();
    return app.exec();
}
