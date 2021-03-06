#ifndef ANIMALES_H
#define ANIMALES_H

#include <QtWidgets/QMainWindow>
#include "ui_animales.h"
#include "QMessageBox"

#include "expertSystem.h"
#include "rulesmgmt.h"
#include "inputcauses.h"
#include "showexplanation.h"

class AnimalES : public QMainWindow
{
	Q_OBJECT

public:
	AnimalES(QWidget *parent = 0);
	~AnimalES();
public slots:
	void on_pushButton_createKB_clicked();
	void on_pushButton_inputCauses_clicked();
	void on_pushButton_explain_clicked();
	void on_pushButton_modify_clicked();
	void on_pushButton_think_clicked();
	void on_pushButton_quit_clicked();
private:
	Ui::AnimalESClass ui;
	ES es;
	RulesMGMT *r;
	InputCauses *i;
	ShowExplanation *s;

};

#endif // ANIMALES_H
