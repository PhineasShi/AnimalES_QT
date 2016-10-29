#include "rulesmgmt.h"

RulesMGMT::RulesMGMT(ES &es,QDialog *parent)
	: QDialog(parent)
{
	this->es = es;
	ui.setupUi(this);

	/*connect(this,SIGNAL(itemClicked()),);*/

}

RulesMGMT::~RulesMGMT()
{

}

void RulesMGMT::on_pushButton_quit_clicked()
{
	this->close();
}
void RulesMGMT::ruleItemsClicked()
{

}
void RulesMGMT::initLists()
{
	QList<Rule> knowledgeBase = es.getKnowledgeBase();
	for (int i = 0; i < knowledgeBase.length(); i++)
	{
		QString itemStr;
		QList<Cause> causes = knowledgeBase[i].getCauses();
		for (int  i = 0; i < causes.length(); i++)
		{
			itemStr += causes[i].getCauseName()+",";
		}
		itemStr.chop(1);
		itemStr += "-->"+ knowledgeBase[i].getResult().getCauseName();
		ui.listWidget_rules->addItem(itemStr);
	}
}