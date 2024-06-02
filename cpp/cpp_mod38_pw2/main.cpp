#include <iostream>
#include <fstream>
#include <QApplication>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QPlainTextEdit>
#include <QWebEngineView>
#include <QSizePolicy>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    QApplication::setApplicationName("HTML Editor");
    auto *window = new QWidget;
    auto *hBox = new QHBoxLayout(window);
    auto *policy = new QSizePolicy;

    QPlainTextEdit htmlEdit(window);
    *policy = htmlEdit.sizePolicy();
    policy->setHorizontalStretch(1);
    policy->setHorizontalPolicy(QSizePolicy::Expanding);
    htmlEdit.setSizePolicy(*policy);
    htmlEdit.setTabStopWidth(20);

    QWebEngineView htmlView(window);
    *policy = htmlView.sizePolicy();
    policy->setHorizontalStretch(1);
    policy->setHorizontalPolicy(QSizePolicy::Expanding);
    htmlView.setSizePolicy(*policy);

    delete policy;

    hBox->addWidget(&htmlEdit);
    hBox->addWidget(&htmlView);

    QObject::connect(&htmlEdit,&QPlainTextEdit::textChanged,[&htmlView,&htmlEdit](){
        htmlView.setHtml(htmlEdit.toPlainText());
    });

    const char path[] = "example.html";
    std::ifstream file(path);
    if(!file.is_open()){
        htmlEdit.setPlaceholderText(QString::fromStdString(
                "File " + (std::string)path + " not found. " + "Enter your html code here"));
    }
    else{
        std::string s;
        while(!file.eof()){
            file >> s;
            s += " ";
            htmlEdit.insertPlainText(QString::fromStdString(s));
        }
        file.close();
    }

    window->setMinimumSize(640,480);
    window->show();
    return QApplication::exec();
}
