#include "mainwindow.h"
#include <QApplication>
#include<QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile testqss("test.qss");
    testqss.open(QFile::ReadOnly);
    a.setStyleSheet(testqss.readAll());

    MainWindow w;
    w.show();
    testqss.close();



    return a.exec();
}
