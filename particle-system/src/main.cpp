#include <QApplication>
#include "app.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    App win;
    win.show();
    return app.exec();
}
