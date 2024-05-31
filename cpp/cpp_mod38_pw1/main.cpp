#include <iostream>
#include <QApplication>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QMediaPlayer>
#include "MagicButton.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QApplication::setApplicationName("Magic Button");
    auto *window = new QWidget;

    MagicButton button(nullptr);
    QVBoxLayout vBox(nullptr);
    vBox.addWidget(&button);
    vBox.addStretch(10);

    QGroupBox groupBox(window);
    groupBox.setLayout(&vBox);

    auto player = new QMediaPlayer(window);
    player->setMedia(QUrl::fromLocalFile("./sound.mp3"));

    QObject::connect(&button,&QPushButton::clicked,[player](){
        player->stop();
        player->play();
    });

    window->setFixedSize(groupBox.sizeHint());
    window->show();
    return QApplication::exec();
}
