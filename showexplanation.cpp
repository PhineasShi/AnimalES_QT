#include "showexplanation.h"

ShowExplanation::ShowExplanation(ES *es,QWidget *parent)
	: QDialog(parent)
{
	this->es = es;
	ui.setupUi(this);
	initConclusionList();
}

ShowExplanation::~ShowExplanation()
{

}
void ShowExplanation::initConclusionList()
{
	QList<Cause> conclusion = es->getConclusion();
	for (int i = 0; i < conclusion.length(); i++)
	{
		ui.listWidget_causes->addItem(conclusion[i].getCauseName());
	}
}
void ShowExplanation::on_pushButton_quit_clicked()
{
	this->close();
}

