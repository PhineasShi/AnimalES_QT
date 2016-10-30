#ifndef INPUTCAUSES_H
#define INPUTCAUSES_H

#include <QDialog>
#include "ui_inputcauses.h"

#include "expertSystem.h"

class InputCauses : public QDialog
{
	Q_OBJECT

public:
	InputCauses(ES *es, QWidget *parent = 0);
	~InputCauses();
public slots:
	void on_toolButton_add_clicked();
	void on_toolButton_minus_clicked();
	void on_pushButton_confirm_clicked();

private:
	Ui::InputCauses ui;
	ES *es;

	void initCauseBox();
};

#endif // INPUTCAUSES_H
