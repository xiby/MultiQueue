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
    QTableWidget *list0;
    QPushButton *next;
    MyCustomSlider *speed;
    QLabel *label;
    QGraphicsView *graphicsView_2;
    QLabel *label_2;
    QLCDNumber *time;
    QPushButton *add_Button;
    QPushButton *add_queue_Button;
    QPushButton *pause;
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
        MainWindow->setBaseSize(QSize(480, 600));
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral("background-image: url(:/img/background.png);"));
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
        Multiqueue->setAcceptDrops(false);
        Multiqueue->setToolTipDuration(0);
        Multiqueue->setAutoFillBackground(false);
        Multiqueue->setInputMethodHints(Qt::ImhNone);
        Multiqueue->setTabPosition(QTabWidget::North);
        Multiqueue->setTabShape(QTabWidget::Rounded);
        Multiqueue->setElideMode(Qt::ElideLeft);
        Multiqueue->setDocumentMode(true);
        Multiqueue->setTabsClosable(false);
        Multiqueue->setMovable(false);
        Multiqueue->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        list0 = new QTableWidget(tab);
        list0->setObjectName(QStringLiteral("list0"));
        list0->setGeometry(QRect(0, 0, 461, 369));
        list0->setStyleSheet(QStringLiteral(""));
        Multiqueue->addTab(tab, QString());

        gridLayout->addWidget(Multiqueue, 0, 0, 1, 1);

        next = new QPushButton(centralWidget);
        next->setObjectName(QStringLiteral("next"));
        next->setGeometry(QRect(480, 140, 111, 51));
        next->setAutoFillBackground(false);
        next->setStyleSheet(QStringLiteral("border-image: url(:/img/step_hover.png);"));
        next->setFlat(true);
        speed = new MyCustomSlider(centralWidget);
        speed->setObjectName(QStringLiteral("speed"));
        speed->setGeometry(QRect(480, 360, 111, 22));
        speed->setStyleSheet(QStringLiteral("border-image: url(:/img/background.png);"));
        speed->setOrientation(Qt::Horizontal);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(480, 340, 71, 16));
        label->setStyleSheet(QStringLiteral("border-image: url(:/img/background.png);"));
        graphicsView_2 = new QGraphicsView(centralWidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(230, 390, 231, 51));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(480, 420, 101, 21));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setTextFormat(Qt::PlainText);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setIndent(0);
        time = new QLCDNumber(centralWidget);
        time->setObjectName(QStringLiteral("time"));
        time->setEnabled(true);
        time->setGeometry(QRect(470, 20, 121, 91));
        time->setMinimumSize(QSize(50, 0));
        time->setStyleSheet(QStringLiteral("border-image: url(:/img/background.png);"));
        time->setFrameShadow(QFrame::Raised);
        time->setSmallDecimalPoint(false);
        time->setDigitCount(3);
        time->setSegmentStyle(QLCDNumber::Flat);
        time->setProperty("value", QVariant(0));
        time->setProperty("intValue", QVariant(0));
        add_Button = new QPushButton(centralWidget);
        add_Button->setObjectName(QStringLiteral("add_Button"));
        add_Button->setGeometry(QRect(0, 390, 231, 51));
        add_Button->setStyleSheet(QStringLiteral("border-color: rgb(43, 43, 43);"));
        add_queue_Button = new QPushButton(centralWidget);
        add_queue_Button->setObjectName(QStringLiteral("add_queue_Button"));
        add_queue_Button->setGeometry(QRect(230, 390, 231, 51));
        add_queue_Button->setStyleSheet(QStringLiteral("border-color: rgb(125, 125, 125);"));
        pause = new QPushButton(centralWidget);
        pause->setObjectName(QStringLiteral("pause"));
        pause->setGeometry(QRect(490, 240, 81, 81));
        pause->setMouseTracking(false);
        pause->setAutoFillBackground(false);
        pause->setStyleSheet(QStringLiteral("border-image: url(:/img/stop.png);"));
        pause->setAutoRepeat(false);
        pause->setAutoExclusive(false);
        pause->setAutoDefault(false);
        pause->setFlat(true);
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
#ifndef QT_NO_STATUSTIP
        Multiqueue->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        Multiqueue->setTabText(Multiqueue->indexOf(tab), QApplication::translate("MainWindow", "\345\244\232\347\272\247\345\217\215\351\246\210\351\230\237\345\210\227", 0));
        next->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Speed", 0));
        label_2->setText(QApplication::translate("MainWindow", "DoMan", 0));
        add_Button->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\350\277\233\347\250\213", 0));
        add_queue_Button->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\351\230\237\345\210\227", 0));
        pause->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
