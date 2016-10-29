#ifndef INPUTCAUSES_H
#define INPUTCAUSES_H

#include <QDialog>
#include "ui_inputcauses.h"

class InputCauses : public QDialog
{
	Q_OBJECT

public:
	InputCauses(QWidget *parent = 0);
	~InputCauses();

private:
	Ui::InputCauses ui;
};

#endif // INPUTCAUSES_H
