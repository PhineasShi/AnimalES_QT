/********************************************************************************
** Form generated from reading UI file 'rulesmgmt.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULESMGMT_H
#define UI_RULESMGMT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RulesMGMT
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QListWidget *listWidget_causes;
    QListWidget *listWidget_rules;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *pushButton_add;
    QLabel *label_4;
    QComboBox *comboBox_result;
    QToolButton *toolButton_minus;
    QComboBox *comboBox_cause;
    QToolButton *toolButton_add;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_modify;
    QPushButton *pushButton_quit;
    QCheckBox *checkBox_isLast;

    void setupUi(QWidget *RulesMGMT)
    {
        if (RulesMGMT->objectName().isEmpty())
            RulesMGMT->setObjectName(QStringLiteral("RulesMGMT"));
        RulesMGMT->resize(500, 300);
        gridLayout_2 = new QGridLayout(RulesMGMT);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listWidget_causes = new QListWidget(RulesMGMT);
        listWidget_causes->setObjectName(QStringLiteral("listWidget_causes"));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI Light"));
        font.setPointSize(10);
        listWidget_causes->setFont(font);
        listWidget_causes->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        listWidget_causes->setWordWrap(true);

        gridLayout->addWidget(listWidget_causes, 3, 1, 6, 1);

        listWidget_rules = new QListWidget(RulesMGMT);
        listWidget_rules->setObjectName(QStringLiteral("listWidget_rules"));
        listWidget_rules->setFont(font);
        listWidget_rules->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        listWidget_rules->setWordWrap(true);

        gridLayout->addWidget(listWidget_rules, 2, 0, 7, 1);

        label = new QLabel(RulesMGMT);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(RulesMGMT);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 3, 1, 1);

        label_2 = new QLabel(RulesMGMT);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        pushButton_add = new QPushButton(RulesMGMT);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));
        pushButton_add->setFont(font);

        gridLayout->addWidget(pushButton_add, 5, 2, 1, 3);

        label_4 = new QLabel(RulesMGMT);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 4, 1, 5);

        comboBox_result = new QComboBox(RulesMGMT);
        comboBox_result->setObjectName(QStringLiteral("comboBox_result"));
        comboBox_result->setFont(font);
        comboBox_result->setEditable(true);

        gridLayout->addWidget(comboBox_result, 2, 4, 1, 5);

        toolButton_minus = new QToolButton(RulesMGMT);
        toolButton_minus->setObjectName(QStringLiteral("toolButton_minus"));
        toolButton_minus->setFont(font);

        gridLayout->addWidget(toolButton_minus, 3, 2, 1, 1);

        comboBox_cause = new QComboBox(RulesMGMT);
        comboBox_cause->setObjectName(QStringLiteral("comboBox_cause"));
        comboBox_cause->setFont(font);
        comboBox_cause->setEditable(true);

        gridLayout->addWidget(comboBox_cause, 2, 1, 1, 1);

        toolButton_add = new QToolButton(RulesMGMT);
        toolButton_add->setObjectName(QStringLiteral("toolButton_add"));
        toolButton_add->setFont(font);

        gridLayout->addWidget(toolButton_add, 2, 2, 1, 1);

        pushButton_delete = new QPushButton(RulesMGMT);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));
        pushButton_delete->setFont(font);

        gridLayout->addWidget(pushButton_delete, 6, 2, 2, 3);

        pushButton_modify = new QPushButton(RulesMGMT);
        pushButton_modify->setObjectName(QStringLiteral("pushButton_modify"));
        pushButton_modify->setFont(font);

        gridLayout->addWidget(pushButton_modify, 5, 5, 1, 1);

        pushButton_quit = new QPushButton(RulesMGMT);
        pushButton_quit->setObjectName(QStringLiteral("pushButton_quit"));
        pushButton_quit->setFont(font);

        gridLayout->addWidget(pushButton_quit, 6, 5, 2, 1);

        checkBox_isLast = new QCheckBox(RulesMGMT);
        checkBox_isLast->setObjectName(QStringLiteral("checkBox_isLast"));
        checkBox_isLast->setFont(font);

        gridLayout->addWidget(checkBox_isLast, 4, 2, 1, 3);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(RulesMGMT);

        QMetaObject::connectSlotsByName(RulesMGMT);
    } // setupUi

    void retranslateUi(QWidget *RulesMGMT)
    {
        RulesMGMT->setWindowTitle(QApplication::translate("RulesMGMT", "RulesMGMT", 0));
        label->setText(QApplication::translate("RulesMGMT", "\350\247\204\345\210\231", 0));
        label_3->setText(QApplication::translate("RulesMGMT", "-->", 0));
        label_2->setText(QApplication::translate("RulesMGMT", "\345\211\215\346\217\220", 0));
        pushButton_add->setText(QApplication::translate("RulesMGMT", "\345\242\236\345\212\240", 0));
        label_4->setText(QApplication::translate("RulesMGMT", "\347\273\223\350\256\272", 0));
        toolButton_minus->setText(QApplication::translate("RulesMGMT", " -", 0));
        toolButton_add->setText(QApplication::translate("RulesMGMT", "+", 0));
        pushButton_delete->setText(QApplication::translate("RulesMGMT", "\345\210\240\351\231\244", 0));
        pushButton_modify->setText(QApplication::translate("RulesMGMT", "\344\277\256\346\224\271", 0));
        pushButton_quit->setText(QApplication::translate("RulesMGMT", "\351\200\200\345\207\272", 0));
        checkBox_isLast->setText(QApplication::translate("RulesMGMT", "\346\234\200\347\273\210\347\273\223\350\256\272", 0));
    } // retranslateUi

};

namespace Ui {
    class RulesMGMT: public Ui_RulesMGMT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULESMGMT_H
