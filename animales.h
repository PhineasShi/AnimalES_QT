#ifndef ANIMALES_H
#define ANIMALES_H

#include <QtWidgets/QMainWindow>
#include "ui_animales.h"

class AnimalES : public QMainWindow
{
	Q_OBJECT

public:
	AnimalES(QWidget *parent = 0);
	~AnimalES();

private:
	Ui::AnimalESClass ui;
};

#endif // ANIMALES_H
