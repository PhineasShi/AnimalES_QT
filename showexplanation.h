#ifndef SHOWEXPLANATION_H
#define SHOWEXPLANATION_H

#include <QDialog>
#include "ui_showexplanation.h"

#include "expertSystem.h"

class ShowExplanation : public QDialog
{
	Q_OBJECT

public:
	ShowExplanation(ES *es,QWidget *parent = 0);
	~ShowExplanation();
public slots:
	void on_pushButton_quit_clicked();

private:
	Ui::ShowExplanation ui;
	ES *es;
	void initProcedureList();
};

#endif // SHOWEXPLANATION_H
