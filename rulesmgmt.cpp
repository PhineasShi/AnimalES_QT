#include "rulesmgmt.h"

RulesMGMT::RulesMGMT(QDialog *parent)
	: QDialog(parent)
{
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
	
}