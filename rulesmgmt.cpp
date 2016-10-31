#include "rulesmgmt.h"

RulesMGMT::RulesMGMT(ES *es, QDialog *parent)
	: QDialog(parent)
{
	this->es = es;
	ui.setupUi(this);
	initRuleLists();
	initCauseBoxs();
	connect(ui.listWidget_rules, SIGNAL(currentRowChanged(int)), this, SLOT(ruleItemsClicked(int)));
}

RulesMGMT::~RulesMGMT()
{

}

void RulesMGMT::on_pushButton_quit_clicked()
{
	this->close();
}
void RulesMGMT::on_pushButton_add_clicked()
{
	QList<Cause> causes;
	for (int i = 0; i < ui.listWidget_causes->count() ;i++)
	{
		Cause cause;
		cause.setCauseName(ui.listWidget_causes->item(i)->text());
		causes.push_back(cause);
		if (!es->isCauseExist(cause))
		{
			QList<Cause> causeBase = es->getCauseBase();
			causeBase.push_back(cause);
			es->setCauseBase(causeBase);
		}
	}
	Cause result;
	result.setCauseName(ui.comboBox_result->currentText());
	if (!es->isCauseExist(result))
	{
		QList<Cause> causeBase = es->getCauseBase();
		causeBase.push_back(result);
		es->setCauseBase(causeBase);
	}
	Rule rule;
	rule.setLast(ui.checkBox_isLast->isChecked());
	rule.setCauses(causes);
	rule.setResult(result);
	QList<Rule> knowledgeBase=es->getKnowledgeBase();
	knowledgeBase.push_back(rule);
	es->setKnowledgeBase(knowledgeBase);
	initCauseBoxs();

	QString itemStr;
	for (int i = 0; i < causes.length(); i++)
	{
		itemStr += causes[i].getCauseName() + ",";
	}
	itemStr.chop(1);
	itemStr += "-->" + result.getCauseName();
	ui.listWidget_rules->addItem(itemStr);

}
void RulesMGMT::on_pushButton_modify_clicked()
{
	int currentRow = ui.listWidget_rules->currentRow();
	QList<Cause> causes;
	for (int i = 0; i < ui.listWidget_causes->count(); i++)
	{
		Cause cause;
		cause.setCauseName(ui.listWidget_causes->item(i)->text());
		causes.push_back(cause);
		if (!es->isCauseExist(cause))
		{
			QList<Cause> causeBase = es->getCauseBase();
			causeBase.push_back(cause);
			es->setCauseBase(causeBase);
		}
	}
	Cause result;
	result.setCauseName(ui.comboBox_result->currentText());
	if (!es->isCauseExist(result))
	{
		QList<Cause> causeBase = es->getCauseBase();
		causeBase.push_back(result);
		es->setCauseBase(causeBase);
	}
	Rule rule;
	rule.setLast(ui.checkBox_isLast->isChecked());
	rule.setCauses(causes);
	rule.setResult(result);

	if (es->deleteRuleAt(currentRow))
	{
		initCauseBoxs();
	}
	QList<Rule> knowledgeBase = es->getKnowledgeBase();
	knowledgeBase.insert(currentRow,rule);
	es->setKnowledgeBase(knowledgeBase);

	QString itemStr;
	for (int i = 0; i < causes.length(); i++)
	{
		itemStr += causes[i].getCauseName() + ",";
	}
	itemStr.chop(1);
	itemStr += "-->" + result.getCauseName();
	delete ui.listWidget_rules->takeItem(currentRow);
	ui.listWidget_rules->insertItem(currentRow,itemStr);
}
void RulesMGMT::on_pushButton_delete_clicked()
{
	if (ui.listWidget_rules->count()>1)
	{
		int currentRow = ui.listWidget_rules->currentRow();
		delete ui.listWidget_rules->takeItem(currentRow);
		if (es->deleteRuleAt(currentRow))
		{
			initCauseBoxs();
		}
	}
}
void RulesMGMT::on_toolButton_add_clicked()
{
	QString currentText = ui.comboBox_cause->currentText();
	if(ui.listWidget_causes->findItems(currentText,Qt::MatchExactly).isEmpty()&&!currentText.isEmpty())
	{
		ui.listWidget_causes->addItem(currentText);
	}
}
void RulesMGMT::on_toolButton_minus_clicked()
{
	if (ui.listWidget_causes->count() > 1)
	{
		delete ui.listWidget_causes->takeItem(ui.listWidget_causes->currentRow());
	}
}
void RulesMGMT::ruleItemsClicked(int row)
{
	Rule currentRule = es->getKnowledgeBase()[row];
	QList<Cause> causes = currentRule.getCauses();
	ui.comboBox_result->setCurrentText(currentRule.getResult().getCauseName());
	ui.checkBox_isLast->setChecked(currentRule.isLast());
	ui.listWidget_causes->clear();
	for (int i = 0; i < causes.length(); i++)
	{
		ui.listWidget_causes->addItem(causes[i].getCauseName());
	}
	ui.listWidget_causes->setCurrentRow(0);
}
void RulesMGMT::initRuleLists()
{
	QList<Rule> knowledgeBase = es->getKnowledgeBase();
	for (int i = 0; i < knowledgeBase.length(); i++)
	{
		QString itemStr;
		QList<Cause> causes = knowledgeBase[i].getCauses();
		for (int i = 0; i < causes.length(); i++)
		{
			itemStr += causes[i].getCauseName() + ",";
		}
		itemStr.chop(1);
		itemStr += "-->" + knowledgeBase[i].getResult().getCauseName();
		ui.listWidget_rules->addItem(itemStr);
	}
}
void RulesMGMT::initCauseBoxs()
{
	QList<Cause> causeList = es->getCauseBase();
	ui.comboBox_cause->clear();
	ui.comboBox_result->clear();
	for (int i = 0; i < causeList.length(); i++)
	{
		ui.comboBox_cause->addItem(causeList[i].getCauseName());
		ui.comboBox_result->addItem(causeList[i].getCauseName());
	}
	ui.comboBox_cause->setCurrentText("");
	ui.comboBox_result->setCurrentText("");
}