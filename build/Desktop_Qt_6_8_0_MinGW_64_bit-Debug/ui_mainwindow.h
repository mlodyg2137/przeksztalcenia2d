/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "screen.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    Screen *widget;
    QVBoxLayout *verticalLayout;
    QFrame *translation_frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSlider *translationX;
    QSlider *translationY;
    QFrame *rotation_frame;
    QVBoxLayout *verticalLayout_3;
    QLabel *label2;
    QSlider *rotation;
    QFrame *scaling_frame;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QSlider *scalingX;
    QSlider *scalingY;
    QFrame *shearing_frame;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QSlider *shearingX;
    QSlider *shearingY;
    QFrame *frame;
    QVBoxLayout *verticalLayout_6;
    QPushButton *reset_btn;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1004, 661);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        widget = new Screen(centralwidget);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(800, 600));

        horizontalLayout->addWidget(widget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        translation_frame = new QFrame(centralwidget);
        translation_frame->setObjectName("translation_frame");
        translation_frame->setFrameShape(QFrame::Shape::StyledPanel);
        translation_frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(translation_frame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(translation_frame);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label);

        translationX = new QSlider(translation_frame);
        translationX->setObjectName("translationX");
        translationX->setMinimum(-100);
        translationX->setMaximum(100);
        translationX->setValue(0);
        translationX->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout_2->addWidget(translationX);

        translationY = new QSlider(translation_frame);
        translationY->setObjectName("translationY");
        translationY->setMinimum(-100);
        translationY->setMaximum(100);
        translationY->setValue(0);
        translationY->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout_2->addWidget(translationY);


        verticalLayout->addWidget(translation_frame);

        rotation_frame = new QFrame(centralwidget);
        rotation_frame->setObjectName("rotation_frame");
        rotation_frame->setMinimumSize(QSize(0, 30));
        rotation_frame->setFrameShape(QFrame::Shape::StyledPanel);
        rotation_frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(rotation_frame);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label2 = new QLabel(rotation_frame);
        label2->setObjectName("label2");
        label2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label2);

        rotation = new QSlider(rotation_frame);
        rotation->setObjectName("rotation");
        rotation->setMaximum(100);
        rotation->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout_3->addWidget(rotation);


        verticalLayout->addWidget(rotation_frame);

        scaling_frame = new QFrame(centralwidget);
        scaling_frame->setObjectName("scaling_frame");
        scaling_frame->setMinimumSize(QSize(0, 30));
        scaling_frame->setFrameShape(QFrame::Shape::StyledPanel);
        scaling_frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_4 = new QVBoxLayout(scaling_frame);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_2 = new QLabel(scaling_frame);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        scalingX = new QSlider(scaling_frame);
        scalingX->setObjectName("scalingX");
        scalingX->setMinimum(-99);
        scalingX->setMaximum(100);
        scalingX->setValue(0);
        scalingX->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout_4->addWidget(scalingX);

        scalingY = new QSlider(scaling_frame);
        scalingY->setObjectName("scalingY");
        scalingY->setMinimum(-99);
        scalingY->setMaximum(100);
        scalingY->setValue(0);
        scalingY->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout_4->addWidget(scalingY);


        verticalLayout->addWidget(scaling_frame);

        shearing_frame = new QFrame(centralwidget);
        shearing_frame->setObjectName("shearing_frame");
        shearing_frame->setMinimumSize(QSize(0, 30));
        shearing_frame->setFrameShape(QFrame::Shape::StyledPanel);
        shearing_frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_5 = new QVBoxLayout(shearing_frame);
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_3 = new QLabel(shearing_frame);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(label_3);

        shearingX = new QSlider(shearing_frame);
        shearingX->setObjectName("shearingX");
        shearingX->setMinimum(-100);
        shearingX->setMaximum(100);
        shearingX->setValue(0);
        shearingX->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout_5->addWidget(shearingX);

        shearingY = new QSlider(shearing_frame);
        shearingY->setObjectName("shearingY");
        shearingY->setMinimum(-100);
        shearingY->setMaximum(100);
        shearingY->setValue(0);
        shearingY->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout_5->addWidget(shearingY);


        verticalLayout->addWidget(shearing_frame);

        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(0, 30));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_6 = new QVBoxLayout(frame);
        verticalLayout_6->setObjectName("verticalLayout_6");
        reset_btn = new QPushButton(frame);
        reset_btn->setObjectName("reset_btn");

        verticalLayout_6->addWidget(reset_btn);


        verticalLayout->addWidget(frame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1004, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Translation", nullptr));
        label2->setText(QCoreApplication::translate("MainWindow", "Rotation", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Scaling", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Shearing", nullptr));
        reset_btn->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
