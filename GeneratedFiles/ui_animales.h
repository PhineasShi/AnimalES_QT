/********************************************************************************
** Form generated from reading UI file 'animales.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANIMALES_H
#define UI_ANIMALES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnimalESClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_modify;
    QLabel *label;
    QPushButton *pushButton_quit;
    QPushButton *pushButton_explain;
    QPushButton *pushButton_createKB;
    QPushButton *pushButton_think;
    QPushButton *pushButton_inputCauses;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AnimalESClass)
    {
        if (AnimalESClass->objectName().isEmpty())
            AnimalESClass->setObjectName(QStringLiteral("AnimalESClass"));
        AnimalESClass->resize(221, 400);
        centralWidget = new QWidget(AnimalESClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_modify = new QPushButton(centralWidget);
        pushButton_modify->setObjectName(QStringLiteral("pushButton_modify"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_modify->sizePolicy().hasHeightForWidth());
        pushButton_modify->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI Light"));
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        pushButton_modify->setFont(font);

        gridLayout->addWidget(pushButton_modify, 6, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei UI Light"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton_quit = new QPushButton(centralWidget);
        pushButton_quit->setObjectName(QStringLiteral("pushButton_quit"));
        sizePolicy.setHeightForWidth(pushButton_quit->sizePolicy().hasHeightForWidth());
        pushButton_quit->setSizePolicy(sizePolicy);
        pushButton_quit->setFont(font);

        gridLayout->addWidget(pushButton_quit, 7, 0, 1, 1);

        pushButton_explain = new QPushButton(centralWidget);
        pushButton_explain->setObjectName(QStringLiteral("pushButton_explain"));
        sizePolicy.setHeightForWidth(pushButton_explain->sizePolicy().hasHeightForWidth());
        pushButton_explain->setSizePolicy(sizePolicy);
        pushButton_explain->setFont(font);

        gridLayout->addWidget(pushButton_explain, 5, 0, 1, 1);

        pushButton_createKB = new QPushButton(centralWidget);
        pushButton_createKB->setObjectName(QStringLiteral("pushButton_createKB"));
        sizePolicy.setHeightForWidth(pushButton_createKB->sizePolicy().hasHeightForWidth());
        pushButton_createKB->setSizePolicy(sizePolicy);
        pushButton_createKB->setFont(font);

        gridLayout->addWidget(pushButton_createKB, 2, 0, 1, 1);

        pushButton_think = new QPushButton(centralWidget);
        pushButton_think->setObjectName(QStringLiteral("pushButton_think"));
        sizePolicy.setHeightForWidth(pushButton_think->sizePolicy().hasHeightForWidth());
        pushButton_think->setSizePolicy(sizePolicy);
        pushButton_think->setFont(font);

        gridLayout->addWidget(pushButton_think, 4, 0, 1, 1);

        pushButton_inputCauses = new QPushButton(centralWidget);
        pushButton_inputCauses->setObjectName(QStringLiteral("pushButton_inputCauses"));
        sizePolicy.setHeightForWidth(pushButton_inputCauses->sizePolicy().hasHeightForWidth());
        pushButton_inputCauses->setSizePolicy(sizePolicy);
        pushButton_inputCauses->setFont(font);

        gridLayout->addWidget(pushButton_inputCauses, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        AnimalESClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(AnimalESClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AnimalESClass->setStatusBar(statusBar);

        retranslateUi(AnimalESClass);

        QMetaObject::connectSlotsByName(AnimalESClass);
    } // setupUi

    void retranslateUi(QMainWindow *AnimalESClass)
    {
        AnimalESClass->setWindowTitle(QApplication::translate("AnimalESClass", "AnimalES", 0));
        pushButton_modify->setText(QApplication::translate("AnimalESClass", "\346\225\260\346\215\256\344\277\256\346\224\271", 0));
        label->setText(QApplication::translate("AnimalESClass", "\344\272\272\345\267\245\346\231\272\350\203\275\344\270\223\345\256\266\347\263\273\347\273\237\342\200\224\342\200\224\345\212\250\347\211\251\350\257\206\345\210\253", 0));
        pushButton_quit->setText(QApplication::translate("AnimalESClass", "\351\200\200\345\207\272\347\263\273\347\273\237", 0));
        pushButton_explain->setText(QApplication::translate("AnimalESClass", "\346\216\250\347\220\206\350\247\243\351\207\212", 0));
        pushButton_createKB->setText(QApplication::translate("AnimalESClass", "\345\210\233\345\273\272\347\237\245\350\257\206\345\272\223", 0));
        pushButton_think->setText(QApplication::translate("AnimalESClass", "\350\277\233\350\241\214\346\216\250\347\220\206", 0));
        pushButton_inputCauses->setText(QApplication::translate("AnimalESClass", "\350\276\223\345\205\245\344\272\213\345\256\236", 0));
    } // retranslateUi

};

namespace Ui {
    class AnimalESClass: public Ui_AnimalESClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMALES_H
