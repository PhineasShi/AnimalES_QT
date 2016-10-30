#include "inputcauses.h"

InputCauses::InputCauses(ES *es,QWidget *parent)
	: QDialog(parent)
{
	this->es = es;
	ui.setupUi(this);
	initCauseBox();
}

InputCauses::~InputCauses()
{

}
void InputCauses::initCauseBox()
{
	QList<Cause> causeList = es->getCauseBase();
	ui.comboBox_cause->clear();
	for (int i = 0; i < causeList.length(); i++)
	{
		ui.comboBox_cause->addItem(causeList[i].getCauseName());
	}
	ui.comboBox_cause->setCurrentText("");
}
void InputCauses::on_toolButton_add_clicked()
{
	QString currentText = ui.comboBox_cause->currentText();
	if (ui.listWidget_causes->findItems(currentText, Qt::MatchExactly).isEmpty() && !currentText.isEmpty())
	{
		ui.listWidget_causes->addItem(currentText);
	}
}
void InputCauses::on_toolButton_minus_clicked()
{
	if (ui.listWidget_causes->count() > 1)
	{
		delete ui.listWidget_causes->takeItem(ui.listWidget_causes->currentRow());
	}
}
void InputCauses::on_pushButton_confirm_clicked()
{
	//ui.listWidget_causes->item();
}