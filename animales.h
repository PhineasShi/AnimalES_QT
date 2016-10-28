#ifndef ANIMALES_H
#define ANIMALES_H

#include <QtWidgets/QMainWindow>
#include "ui_animales.h"

#include "expertSystem.h"
#include "rulesmgmt.h"

class AnimalES : public QMainWindow
{
	Q_OBJECT

public:
	AnimalES(QWidget *parent = 0);
	~AnimalES();
public slots:
	void on_pushButton_createKB_clicked();
private:
	Ui::AnimalESClass ui;
	QList<Cause> causeBase;
	QList<Rule> knowledgeBase;
	ES es;
	RulesMGMT r;
};

#endif // ANIMALES_H
