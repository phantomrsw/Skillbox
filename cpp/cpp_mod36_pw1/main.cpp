#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QSpacerItem>

class CircleWidget : public QWidget{
    //Q_OBJECT
    QPixmap mCurrentCircle;
    QPixmap mGreenCircle;
    QPixmap mYellowCircle;
    QPixmap mRedCircle;

public:
    CircleWidget() = default;
    explicit CircleWidget(QWidget* parent){
        setParent(parent);
        setToolTip("Circle Widget");
        setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

        mGreenCircle = QPixmap("../greenCircle.png");
        mYellowCircle = QPixmap("../yellowCircle.png");
        mRedCircle = QPixmap("../redCircle.png");
        mCurrentCircle = mGreenCircle;
        update();
    }

    void paintEvent(QPaintEvent* e)override{
        QPainter p(this);
        p.drawPixmap(e->rect(),mCurrentCircle);
    }

    void setGreen() {
        mCurrentCircle = mGreenCircle;
        update();
        //std::cout << "Green" << std::endl;
    }
    void setYellow() {
        mCurrentCircle = mYellowCircle;
        update();
        //std::cout << "Yellow" << std::endl;
    }
    void setRed() {
        mCurrentCircle = mRedCircle;
        update();
        //std::cout << "Red" << std::endl;
    }

    QSize minimumSizeHint() const override{
        return QSize(150, 150);
    }

};

int main(int argc, char *argv[]) {
    QApplication app(argc,argv);

    QWidget* mainWindow = new QWidget;
    mainWindow->setFixedSize(200,250);

    CircleWidget* circle = new CircleWidget(mainWindow);

    QSlider* slider = new QSlider(mainWindow);
    slider->setRange(0,100);
    slider->setOrientation(Qt::Orientation(Qt::Horizontal));

    auto* layout = new QVBoxLayout;
    layout->addWidget(circle);
    layout->setAlignment(circle,Qt::AlignHCenter);
    layout->addWidget(slider);
    mainWindow->setLayout(layout);

    QObject::connect(slider, &QSlider::valueChanged, circle, [slider, circle](int newValue){
        if(newValue >= 0 && newValue < 34)
            circle->setGreen();
        else if(newValue >= 34 && newValue < 67)
            circle->setYellow();
        else if(newValue >= 67 && newValue < 100)
            circle->setRed();
        //std::cout << slider->value() << std::endl;
    });

    mainWindow->show();

    return QApplication::exec();
}
