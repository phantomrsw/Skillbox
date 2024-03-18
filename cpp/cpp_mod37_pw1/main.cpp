
#include <QApplication>
#include <QMainWindow>
#include <QIcon>
#include "./ui_cpp_mod37_pw1.h"
#include "calcMainWindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc,argv);
    //QMainWindow window(nullptr);
    CalcMainWindow window(nullptr);

    Ui::MainWindow calc;
    calc.setupUi(&window);

    window.init(calc);
    window.resize(320,200);

    QIcon calcIcon("Icon.ico");
    window.setWindowIcon(calcIcon);

    window.show();
    return QApplication::exec();
}
