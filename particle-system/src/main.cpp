#include <QApplication>
#include "app.h"
#include "camera.h"

int main(int argc, char *argv[]) {
    Vec3 position(0,10,0);
    Vec3 xAxis(1, 0, 0);
    Quaternion q(M_PI_2, xAxis);
    Camera c(position, q, 4/3, 90, 1, 10);

    cout << c.getProjectionMatrix() << endl;

    QApplication app(argc, argv);
    App win;
    win.show();
    return app.exec();
}
