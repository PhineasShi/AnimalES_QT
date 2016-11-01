#include "showexplanation.h"

ShowExplanation::ShowExplanation(ES *es,QWidget *parent)
	: QDialog(parent)
{
	this->es = es;
	ui.setupUi(this);
	initProcedureList();
}

ShowExplanation::~ShowExplanation()
{

}
void ShowExplanation::initProcedureList()
{
	QList<Rule> procedure = es->getProcedure();
	for (int i = 0; i < procedure.length(); i++)
	{
		QString itemStr;
		QList<Cause> causes = procedure[i].getCauses();
		for (int i = 0; i < causes.length(); i++)
		{
			itemStr += causes[i].getCauseName() + ",";
		}
		itemStr.chop(1);
		itemStr += "-->" + procedure[i].getResult().getCauseName();
		ui.listWidget_rules->addItem(itemStr);
	}
}
void ShowExplanation::on_pushButton_quit_clicked()
{
	this->close();
}

