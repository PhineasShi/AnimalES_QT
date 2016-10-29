/********************************************************************************
** Form generated from reading UI file 'inputcauses.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTCAUSES_H
#define UI_INPUTCAUSES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_InputCauses
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QListWidget *listWidget_causes;
    QComboBox *comboBox_cause;
    QToolButton *toolButton_add;
    QToolButton *toolButton_minus;
    QPushButton *pushButton_confirm;
    QLabel *label;

    void setupUi(QDialog *InputCauses)
    {
        if (InputCauses->objectName().isEmpty())
            InputCauses->setObjectName(QStringLiteral("InputCauses"));
        InputCauses->resize(273, 327);
        gridLayout_2 = new QGridLayout(InputCauses);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listWidget_causes = new QListWidget(InputCauses);
        listWidget_causes->setObjectName(QStringLiteral("listWidget_causes"));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI Light"));
        font.setPointSize(10);
        listWidget_causes->setFont(font);
        listWidget_causes->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        gridLayout->addWidget(listWidget_causes, 2, 0, 5, 2);

        comboBox_cause = new QComboBox(InputCauses);
        comboBox_cause->setObjectName(QStringLiteral("comboBox_cause"));
        comboBox_cause->setFont(font);
        comboBox_cause->setEditable(true);

        gridLayout->addWidget(comboBox_cause, 1, 0, 1, 2);

        toolButton_add = new QToolButton(InputCauses);
        toolButton_add->setObjectName(QStringLiteral("toolButton_add"));
        toolButton_add->setFont(font);

        gridLayout->addWidget(toolButton_add, 1, 2, 1, 1);

        toolButton_minus = new QToolButton(InputCauses);
        toolButton_minus->setObjectName(QStringLiteral("toolButton_minus"));
        toolButton_minus->setFont(font);

        gridLayout->addWidget(toolButton_minus, 2, 2, 1, 1);

        pushButton_confirm = new QPushButton(InputCauses);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));
        pushButton_confirm->setFont(font);

        gridLayout->addWidget(pushButton_confirm, 5, 2, 1, 1);

        label = new QLabel(InputCauses);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        pushButton_confirm->raise();

        retranslateUi(InputCauses);

        QMetaObject::connectSlotsByName(InputCauses);
    } // setupUi

    void retranslateUi(QDialog *InputCauses)
    {
        InputCauses->setWindowTitle(QApplication::translate("InputCauses", "InputCauses", 0));
        toolButton_add->setText(QApplication::translate("InputCauses", "+", 0));
        toolButton_minus->setText(QApplication::translate("InputCauses", " -", 0));
        pushButton_confirm->setText(QApplication::translate("InputCauses", "\347\241\256\345\256\232", 0));
        label->setText(QApplication::translate("InputCauses", "\344\272\213\345\256\236", 0));
    } // retranslateUi

};

namespace Ui {
    class InputCauses: public Ui_InputCauses {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTCAUSES_H
