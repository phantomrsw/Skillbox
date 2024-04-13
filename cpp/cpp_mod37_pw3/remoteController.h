
#ifndef CPP_MOD37_PW3_REMOTECONTROLLER_H
#define CPP_MOD37_PW3_REMOTECONTROLLER_H

#include <QMainWindow>
#include <QLineEdit>
#include "./ui_cpp_mod37_pw3.h"

class RemoteController : public QMainWindow {
    Q_OBJECT
    QLineEdit* display;
    int volume, channel;

    const int MAX_CHANNEL = 999;

public:

    explicit RemoteController(QWidget* parent = nullptr);

    void init(Ui::MainWindow mw);

    void update_display();

public slots:

    void slotButton1();
    void slotButton2();
    void slotButton3();
    void slotButton4();
    void slotButton5();
    void slotButton6();
    void slotButton7();
    void slotButton8();
    void slotButton9();
    void slotButton0();

    void slotButtonChUp();
    void slotButtonChDown();

    void slotButtonVolUp();
    void slotButtonVolDown();

};


#endif //CPP_MOD37_PW3_REMOTECONTROLLER_H
