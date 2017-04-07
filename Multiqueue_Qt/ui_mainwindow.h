/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <mycustomslider.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTabWidget *Multiqueue;
    QWidget *tab;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *show;
    QTableWidget *list0;
    QWidget *tab_2;
    QWidget *tab_3;
    QPushButton *next;
    QPushButton *exit;
    MyCustomSlider *speed;
    QLabel *label;
    QGraphicsView *graphicsView_2;
    QLabel *label_2;
    QPushButton *pause;
    QLCDNumber *time;
    QPushButton *add_Button;
    QPushButton *add_queue_Button;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(600, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(600, 480));
        MainWindow->setMaximumSize(QSize(600, 480));
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 461, 391));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Multiqueue = new QTabWidget(gridLayoutWidget);
        Multiqueue->setObjectName(QStringLiteral("Multiqueue"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayoutWidget = new QWidget(tab);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 451, 371));
        show = new QHBoxLayout(horizontalLayoutWidget);
        show->setSpacing(6);
        show->setContentsMargins(11, 11, 11, 11);
        show->setObjectName(QStringLiteral("show"));
        show->setContentsMargins(0, 0, 0, 0);
        list0 = new QTableWidget(horizontalLayoutWidget);
        list0->setObjectName(QStringLiteral("list0"));

        show->addWidget(list0);

        Multiqueue->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        Multiqueue->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        Multiqueue->addTab(tab_3, QString());

        gridLayout->addWidget(Multiqueue, 0, 0, 1, 1);

        next = new QPushButton(centralWidget);
        next->setObjectName(QStringLiteral("next"));
        next->setGeometry(QRect(480, 240, 111, 51));
        exit = new QPushButton(centralWidget);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(480, 370, 111, 51));
        speed = new MyCustomSlider(centralWidget);
        speed->setObjectName(QStringLiteral("speed"));
        speed->setGeometry(QRect(480, 330, 111, 22));
        speed->setOrientation(Qt::Horizontal);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(480, 310, 54, 12));
        graphicsView_2 = new QGraphicsView(centralWidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(230, 390, 231, 51));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(480, 430, 101, 21));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setTextFormat(Qt::PlainText);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setIndent(0);
        pause = new QPushButton(centralWidget);
        pause->setObjectName(QStringLiteral("pause"));
        pause->setGeometry(QRect(500, 160, 61, 61));
        pause->setStyleSheet(QStringLiteral("background-image: url(:/img/stop.png);"));
        pause->setAutoDefault(false);
        pause->setFlat(true);
        time = new QLCDNumber(centralWidget);
        time->setObjectName(QStringLiteral("time"));
        time->setEnabled(true);
        time->setGeometry(QRect(470, 20, 121, 91));
        time->setMinimumSize(QSize(50, 0));
        time->setFrameShadow(QFrame::Raised);
        time->setSmallDecimalPoint(false);
        time->setDigitCount(3);
        time->setSegmentStyle(QLCDNumber::Flat);
        time->setProperty("value", QVariant(0));
        time->setProperty("intValue", QVariant(0));
        add_Button = new QPushButton(centralWidget);
        add_Button->setObjectName(QStringLiteral("add_Button"));
        add_Button->setGeometry(QRect(0, 390, 231, 51));
        add_queue_Button = new QPushButton(centralWidget);
        add_queue_Button->setObjectName(QStringLiteral("add_queue_Button"));
        add_queue_Button->setGeometry(QRect(230, 390, 231, 51));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        Multiqueue->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        Multiqueue->setTabText(Multiqueue->indexOf(tab), QApplication::translate("MainWindow", "\345\244\232\347\272\247\345\217\215\351\246\210\351\230\237\345\210\227", 0));
        Multiqueue->setTabText(Multiqueue->indexOf(tab_2), QApplication::translate("MainWindow", "\345\205\210\350\277\233\345\205\210\345\207\272\351\230\237\345\210\227", 0));
        Multiqueue->setTabText(Multiqueue->indexOf(tab_3), QApplication::translate("MainWindow", "\351\241\265", 0));
        next->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\346\255\245", 0));
        exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_2->setText(QApplication::translate("MainWindow", "DoMan", 0));
        pause->setText(QString());
        add_Button->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\350\277\233\347\250\213", 0));
        add_queue_Button->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\351\230\237\345\210\227", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
