#ifndef RULESMGMT_H
#define RULESMGMT_H

#include <QDialog>
#include "ui_rulesmgmt.h"

class RulesMGMT : public QDialog
{
	Q_OBJECT

public:
	RulesMGMT(QDialog *parent = 0);
	~RulesMGMT();

public slots:
	void on_pushButton_quit_clicked();
	void ruleItemsClicked();

private:
	Ui::RulesMGMT ui;
	void initLists();
	
};

#endif // RULESMGMT_H
