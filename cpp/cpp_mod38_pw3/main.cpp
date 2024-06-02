#include <iostream>
#include <QApplication>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsBlurEffect>
#include <QPainter>
#include <QString>
#include <QFileDialog>

QImage blurImage(QImage &source, int blurRadius){
    if(source.isNull())
        return {};
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));
    auto *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blurRadius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(),QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter,QRectF(),
                 QRectF(0,0,source.width(),source.height()));
    return result;
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QApplication::setApplicationName("Blur app");
    auto *window = new QWidget;

    QVBoxLayout vBox(window);

    QLabel imageLabel;

    QSlider slider;
    slider.setOrientation(Qt::Orientation::Horizontal);
    slider.setRange(0,10);
    slider.setDisabled(true);

    QPushButton button("Open file", nullptr);

    vBox.addWidget(&imageLabel);
    vBox.addWidget(&slider);
    vBox.addWidget(&button);

    QString path;

    QObject::connect(&button,&QPushButton::clicked,[&path,&slider,&imageLabel](){
        path = QFileDialog::getOpenFileName(nullptr,
                                            "Open image file",
                                            ".",
                                            "*.jpg *.png");
        if(!path.isEmpty()){
            slider.setEnabled(true);
            imageLabel.setPixmap(QPixmap::fromImage(QImage(path).scaled(
                    imageLabel.width(),
                    imageLabel.height(), Qt::KeepAspectRatio)));
        }
    });

    QObject::connect(&slider,&QSlider::valueChanged,[&slider,&imageLabel,&path](){
        if(slider.isEnabled()){
            std::cout << "\nSlider value:" << slider.value();
            QImage sourceImage(path);
            imageLabel.setPixmap(QPixmap::fromImage(blurImage(sourceImage, slider.value()).scaled(
                    imageLabel.width(),
                    imageLabel.height(), Qt::KeepAspectRatio)));
        }
    });

    window->setMinimumSize(640,480);
    window->show();
    return QApplication::exec();
}
