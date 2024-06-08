#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    resultERR();

    QObject::connect(ui->lineEdit,&QLineEdit::textChanged,[this](){
        QRegularExpression regexp("^\\+\[0-9]{11}$");
        if((regexp.match(ui->lineEdit->text()).hasMatch())){
            resultOK();
        }
        else{
            resultERR();
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resultOK()
{
    ui->label->setText("OK");
    ui->label->setStyleSheet("QLabel {color : green;}");
}

void MainWindow::resultERR()
{
    ui->label->setText("ERROR");
    ui->label->setStyleSheet("QLabel {color : red;}");
}



