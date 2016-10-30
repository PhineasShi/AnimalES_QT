/********************************************************************************
** Form generated from reading UI file 'showexplanation.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWEXPLANATION_H
#define UI_SHOWEXPLANATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ShowExplanation
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QListWidget *listWidget_causes;
    QLabel *label;
    QPushButton *pushButton_quit;

    void setupUi(QDialog *ShowExplanation)
    {
        if (ShowExplanation->objectName().isEmpty())
            ShowExplanation->setObjectName(QStringLiteral("ShowExplanation"));
        ShowExplanation->resize(250, 300);
        gridLayout_2 = new QGridLayout(ShowExplanation);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listWidget_causes = new QListWidget(ShowExplanation);
        listWidget_causes->setObjectName(QStringLiteral("listWidget_causes"));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI Light"));
        font.setPointSize(10);
        listWidget_causes->setFont(font);
        listWidget_causes->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        gridLayout->addWidget(listWidget_causes, 1, 0, 1, 1);

        label = new QLabel(ShowExplanation);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton_quit = new QPushButton(ShowExplanation);
        pushButton_quit->setObjectName(QStringLiteral("pushButton_quit"));
        pushButton_quit->setFont(font);

        gridLayout->addWidget(pushButton_quit, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(ShowExplanation);

        QMetaObject::connectSlotsByName(ShowExplanation);
    } // setupUi

    void retranslateUi(QDialog *ShowExplanation)
    {
        ShowExplanation->setWindowTitle(QApplication::translate("ShowExplanation", "ShowExplanation", 0));
        label->setText(QApplication::translate("ShowExplanation", "\346\216\250\347\220\206\350\247\243\351\207\212", 0));
        pushButton_quit->setText(QApplication::translate("ShowExplanation", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class ShowExplanation: public Ui_ShowExplanation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWEXPLANATION_H
