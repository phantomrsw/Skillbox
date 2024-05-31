
#include "MagicButton.h"

 MagicButton::MagicButton(QWidget *parent){
    setParent(parent);
    setToolTip("This is Magic Button");
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    upButtonImage = QPixmap("btn_up.png");
    downButtonImage = QPixmap("btn_down.png");
    currButtonImage = upButtonImage;
    setGeometry(currButtonImage.rect());
    QObject::connect(this, &QPushButton::pressed,this,&MagicButton::setDown);
    QObject::connect(this, &QPushButton::released,this,&MagicButton::setUp);
}

void MagicButton::paintEvent(QPaintEvent *e){
    QPainter p(this);
    p.drawPixmap(e->rect(),currButtonImage);
}

QSize MagicButton::sizeHint() const{
    return {currButtonImage.width(),currButtonImage.height()};
};

QSize MagicButton::minimumSizeHint() const{
    return sizeHint();
};

void MagicButton::keyPressEvent(QKeyEvent *e){
    setDown();
}

void MagicButton::setUp(){
    currButtonImage = upButtonImage;
    update();
}

void MagicButton::setDown(){
    currButtonImage = downButtonImage;
    update();
}