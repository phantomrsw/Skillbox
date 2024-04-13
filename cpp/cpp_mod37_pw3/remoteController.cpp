
#include <iostream>
#include <QMainWindow>
#include <QString>
#include <iomanip>
#include "remoteController.h"


RemoteController::RemoteController(QWidget* parent) : QMainWindow(parent){}

void RemoteController::init(Ui::MainWindow mw){
    volume = 0;
    channel = 0;
    display = mw.lineEdit;
    display->setReadOnly(true);
    update_display();
}

void RemoteController::update_display(){
    QString s = "Channel:" + QString::number(channel) +
                "\tVolume:" + QString::number(volume) + "%";
    display->clear();
    display->insert(s);
}

void RemoteController::slotButton1(){
    channel = channel * 10 + 1;
    if(channel > MAX_CHANNEL) channel = 0;
    update_display();
}

void RemoteController::slotButton2(){
    channel = channel * 10 + 2;
    if(channel > MAX_CHANNEL) channel = 0;
    update_display();
}
void RemoteController::slotButton3(){
    channel = channel * 10 + 3;
    if(channel > MAX_CHANNEL) channel = 0;
    update_display();
}
void RemoteController::slotButton4(){
    channel = channel * 10 + 4;
    if(channel > MAX_CHANNEL) channel = 0;
    update_display();
}
void RemoteController::slotButton5(){
    channel = channel * 10 + 5;
    if(channel > MAX_CHANNEL) channel = 0;
    update_display();
}
void RemoteController::slotButton6(){
    channel = channel * 10 + 6;
    if(channel > MAX_CHANNEL) channel = 0;
    update_display();
}
void RemoteController::slotButton7(){
    channel = channel * 10 + 7;
    if(channel > MAX_CHANNEL) channel = 0;
    update_display();
}
void RemoteController::slotButton8(){
    channel = channel * 10 + 8;
    if(channel > MAX_CHANNEL) channel = 0;
    update_display();
}
void RemoteController::slotButton9(){
    channel = channel * 10 + 9;
    if(channel > MAX_CHANNEL) channel = 0;
    update_display();
}
void RemoteController::slotButton0(){
    channel = channel * 10 + 0;
    if(channel > MAX_CHANNEL) channel = 0;
    update_display();
}

void RemoteController::slotButtonChUp(){
    if(channel < MAX_CHANNEL) channel++;
    if(channel > MAX_CHANNEL) channel = MAX_CHANNEL;
    update_display();
}
void RemoteController::slotButtonChDown(){
    if(channel > 0) channel--;
    if(channel < 0) channel = 0;
    update_display();
}

void RemoteController::slotButtonVolUp(){
    if(volume < 100) volume += 10;
    if(volume > 100) volume = 100;
    update_display();
}

void RemoteController::slotButtonVolDown(){
    if(volume > 0) volume -= 10;
    if(volume < 0) volume = 0;
    update_display();
}

