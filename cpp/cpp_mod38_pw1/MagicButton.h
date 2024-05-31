#include <QPushButton>
#include <QPainter>
#include <QPaintEvent>

#ifndef CPP_MOD38_PW1_MAGICBUTTON_H
#define CPP_MOD38_PW1_MAGICBUTTON_H


class MagicButton : public QPushButton {
    Q_OBJECT
    QPixmap currButtonImage;
    QPixmap upButtonImage;
    QPixmap downButtonImage;

public:
    MagicButton() = default;

    explicit MagicButton(QWidget *parent);

    void paintEvent(QPaintEvent *e) override;

    QSize sizeHint() const override;

    QSize minimumSizeHint() const override;

    void keyPressEvent(QKeyEvent *e) override;

public slots:

    void setUp();
    void setDown();

};


#endif //CPP_MOD38_PW1_MAGICBUTTON_H
