#include <QApplication>
#include <QMainWindow>
#include <QIcon>
#include "./ui_cpp_mod37_pw3.h"
#include "remoteController.h"

int main(int argc, char* argv[]) {
    QApplication app(argc,argv);
    //QMainWindow window(nullptr);
    RemoteController window(nullptr);

    Ui::MainWindow remote;
    remote.setupUi(&window);

    window.init(remote);
    window.resize(240,680);

    QIcon calcIcon("Icon.ico");
    window.setWindowIcon(calcIcon);

    window.show();
    return QApplication::exec();
}
