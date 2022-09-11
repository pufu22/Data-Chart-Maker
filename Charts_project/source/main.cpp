#include "source/view/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Enrik Rucaj & Jude Vensil Braceros");
    QCoreApplication::setApplicationName("Chart Project");
    MainWindow w;
    w.setWindowState(Qt::WindowMaximized);
    w.show();
    return a.exec();
}
