#ifndef RULESMGMT_H
#define RULESMGMT_H

#include <QDialog>
#include "ui_rulesmgmt.h"
#include <QDebug>

#include "expertSystem.h"

class RulesMGMT : public QDialog
{
	Q_OBJECT

public:
	RulesMGMT(ES *es,QDialog *parent = 0);

	~RulesMGMT();


public slots:
	void on_pushButton_quit_clicked();
	void on_pushButton_add_clicked();
	void on_pushButton_delete_clicked();
	void on_toolButton_add_clicked();
	void on_toolButton_minus_clicked();
	void ruleItemsClicked(int row);
private:
	Ui::RulesMGMT ui;
	ES *es;
	void initRuleLists();
	void initCauseBoxs();
	
};

#endif // RULESMGMT_H
