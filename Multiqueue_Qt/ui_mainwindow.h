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
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral(""));
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
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Multiqueue->sizePolicy().hasHeightForWidth());
        Multiqueue->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QStringLiteral("Adobe Gothic Std B"));
        font.setBold(true);
        font.setWeight(75);
        Multiqueue->setFont(font);
        Multiqueue->setAcceptDrops(false);
        Multiqueue->setToolTipDuration(0);
        Multiqueue->setAutoFillBackground(false);
        Multiqueue->setInputMethodHints(Qt::ImhNone);
        Multiqueue->setTabPosition(QTabWidget::North);
        Multiqueue->setTabShape(QTabWidget::Rounded);
        Multiqueue->setIconSize(QSize(50, 50));
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
        list0->setStyleSheet(QStringLiteral("background-image: url(:/img/background.png);"));
        list0->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        Multiqueue->addTab(tab, QString());

        gridLayout->addWidget(Multiqueue, 0, 0, 1, 1);

        next = new QPushButton(centralWidget);
        next->setObjectName(QStringLiteral("next"));
        next->setGeometry(QRect(150, 410, 50, 50));
        next->setAutoFillBackground(false);
        next->setStyleSheet(QStringLiteral("border-image: url(:/img/step_clicked.png);"));
        next->setFlat(true);
        speed = new MyCustomSlider(centralWidget);
        speed->setObjectName(QStringLiteral("speed"));
        speed->setGeometry(QRect(10, 390, 441, 22));
        speed->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(480, 270, 100, 200));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/img/doman.png);"));
        label_2->setTextFormat(Qt::PlainText);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setIndent(0);
        time = new QLCDNumber(centralWidget);
        time->setObjectName(QStringLiteral("time"));
        time->setEnabled(true);
        time->setGeometry(QRect(460, 10, 140, 100));
        time->setMinimumSize(QSize(50, 0));
        time->setStyleSheet(QStringLiteral("border-image: url(:/img/timeFrame.png);"));
        time->setInputMethodHints(Qt::ImhNone);
        time->setFrameShape(QFrame::Box);
        time->setFrameShadow(QFrame::Plain);
        time->setLineWidth(0);
        time->setSmallDecimalPoint(true);
        time->setDigitCount(3);
        time->setMode(QLCDNumber::Dec);
        time->setSegmentStyle(QLCDNumber::Flat);
        time->setProperty("value", QVariant(0));
        time->setProperty("intValue", QVariant(0));
        add_Button = new QPushButton(centralWidget);
        add_Button->setObjectName(QStringLiteral("add_Button"));
        add_Button->setGeometry(QRect(470, 200, 120, 70));
        add_Button->setStyleSheet(QStringLiteral("border-image: url(:/img/addP.png);"));
        add_queue_Button = new QPushButton(centralWidget);
        add_queue_Button->setObjectName(QStringLiteral("add_queue_Button"));
        add_queue_Button->setGeometry(QRect(470, 120, 121, 71));
        add_queue_Button->setStyleSheet(QStringLiteral("border-image: url(:/img/addM.png);"));
        pause = new QPushButton(centralWidget);
        pause->setObjectName(QStringLiteral("pause"));
        pause->setGeometry(QRect(30, 410, 100, 50));
        pause->setMouseTracking(false);
        pause->setAutoFillBackground(false);
        pause->setStyleSheet(QStringLiteral("border-image: url(:/img/run.png);"));
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
        Multiqueue->setTabText(Multiqueue->indexOf(tab), QString());
        next->setText(QString());
        label_2->setText(QString());
        add_Button->setText(QString());
        add_queue_Button->setText(QString());
        pause->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
