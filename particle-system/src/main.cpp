#include <QApplication>
#include "mainwindow.h"

#include "math/matrix4.h"
#include "texture.h"

int main(int argc, char *argv[]) {
    QGLFormat glFormat;
    glFormat.setVersion(3, 2);
    glFormat.setProfile(QGLFormat::CoreProfile);
    QGLFormat::setDefaultFormat(glFormat);

    QApplication app(argc, argv);

	MainWindow win;
	win.show();

	return app.exec();
}
