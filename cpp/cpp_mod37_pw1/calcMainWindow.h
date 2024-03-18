
#ifndef CPP_MOD37_PW1_CALCMAINWINDOW_H
#define CPP_MOD37_PW1_CALCMAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "./ui_cpp_mod37_pw1.h"

typedef struct {
    QLineEdit *ple;
    bool neg;
    bool point;
}struct_le_t;


class CalcMainWindow : public QMainWindow{
    Q_OBJECT

    struct_le_t number1, number2, result;
    double num1{},num2{},res{};
    const int PRECISION = 12;

public:
    //CalcMainWindow(QWidget* parent = nullptr): QMainWindow(parent){}
    explicit CalcMainWindow(QWidget* parent = nullptr);

    void checkInputLine(struct_le_t &struct_le);

    void init(Ui::MainWindow mw);
public slots:

    void slotNumber1();
    void slotNumber2();
    void slotButtonAdd() const;
    void slotButtonSub() const;
    void slotButtonMul() const;
    void slotButtonDiv() const;

};


#endif //CPP_MOD37_PW1_CALCMAINWINDOW_H
