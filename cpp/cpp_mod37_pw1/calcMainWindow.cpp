
#include <iostream>
#include <QMainWindow>
#include <iomanip>
#include "calcMainWindow.h"


CalcMainWindow::CalcMainWindow(QWidget* parent) : QMainWindow(parent){}

void CalcMainWindow::init(Ui::MainWindow mw){
    number1.ple = mw.lineEdit;
    number1.ple->setPlaceholderText("0");
    number1.neg = false;
    number1.point = false;

    number2.ple = mw.lineEdit_2;
    number2.ple->setPlaceholderText("0");
    number2.neg = false;
    number2.point = false;

    result.ple = mw.lineEdit_3;
}

void CalcMainWindow::slotNumber1(){
    checkInputLine(number1);
    num1 = number1.ple->text().toDouble();
    std::cout << std::setprecision(PRECISION) << "num1=" << num1 << std::endl;
}

void CalcMainWindow::slotNumber2(){
    checkInputLine(number2);
    num2 = number2.ple->text().toDouble();
    std::cout << std::setprecision(PRECISION) << "num2=" << num2 << std::endl;
}

void CalcMainWindow::checkInputLine(struct_le_t &struct_le){
    QLineEdit* le = struct_le.ple;
    bool *point = &struct_le.point;
    bool *neg = &struct_le.neg;

    if(le->isModified()){
        int l = le->text().length();

        if(l > 0){

            if(!(le->text()[l-1] >= '0' && le->text()[l-1] <= '9')
               && le->text()[l-1] != '-'
               && le->text()[l-1] != '.'){
                le->backspace();
                return;
            }

            if((l == 2 && le->text()[0] == '0' && le->text()[1] != '.') ||
               (l == 3 && le->text()[0] == '-' && le->text()[1] == '0' && le->text()[2] != '.')){
                le->backspace();
                std::cout << ">>23\n" << "l=" << l << " text=" << le->text().toStdString() << std:: endl;
                return;
            }

            if(le->text()[l-1] == '.'){
                if(!(*point)) *point = true;
                else{
                    le->backspace();
                    return;
                }
            }

            if(le->text()[l-1] == '-'){
                if(!(*neg) && l == 1) *neg = true;
                else {
                    le->backspace();
                    return;
                }
            }

        }
        else {
            *point = false;
            *neg = false;
        }
        std::cout << le->text().toStdString() << " l=" << l << std::endl;
    }

}

void CalcMainWindow::slotButtonAdd() const {
    QString s = QString::number((num1 + num2),'g',PRECISION);
    result.ple->clear();
    result.ple->insert(s);
}

void CalcMainWindow::slotButtonSub() const{
    QString s = QString::number((num1 - num2),'g',PRECISION);
    result.ple->clear();
    result.ple->insert(s);
}

void CalcMainWindow::slotButtonMul() const{
    QString s = QString::number((num1 * num2),'g',PRECISION);
    result.ple->clear();
    result.ple->insert(s);
}

void CalcMainWindow::slotButtonDiv() const{
    try{
        if(num2 == 0)
            throw std::invalid_argument("Divide by 0");
        QString s = QString::number((num1 / num2),'g',PRECISION);
        result.ple->clear();
        result.ple->insert(s);
    }
    catch(std::invalid_argument &ex){
        std::cerr << "Exception:" << ex.what() << std::endl;
        result.ple->clear();
        result.ple->insert("ERROR");
    }
}
