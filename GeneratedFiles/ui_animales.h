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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnimalESClass
{
public:
    QWidget *centralWidget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AnimalESClass)
    {
        if (AnimalESClass->objectName().isEmpty())
            AnimalESClass->setObjectName(QStringLiteral("AnimalESClass"));
        AnimalESClass->resize(600, 400);
        centralWidget = new QWidget(AnimalESClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        AnimalESClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(AnimalESClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        AnimalESClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AnimalESClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AnimalESClass->setStatusBar(statusBar);

        retranslateUi(AnimalESClass);

        QMetaObject::connectSlotsByName(AnimalESClass);
    } // setupUi

    void retranslateUi(QMainWindow *AnimalESClass)
    {
        AnimalESClass->setWindowTitle(QApplication::translate("AnimalESClass", "AnimalES", 0));
    } // retranslateUi

};

namespace Ui {
    class AnimalESClass: public Ui_AnimalESClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMALES_H
