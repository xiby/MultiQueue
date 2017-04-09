#include "mainwindow.h"
#include <QApplication>
#include<QFile>
#include<QRegExp>
#include<QString>

#include<string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile testqss("test.qss");
    testqss.open(QFile::ReadOnly);
    a.setStyleSheet(testqss.readAll());
    testqss.close();

    MainWindow w;
    w.show();
    testqss.close();



    return a.exec();
}
