#include "animales.h"
AnimalES::AnimalES(QWidget *parent)
	: QMainWindow(parent)
{
	//ES es;
	//es.creatKB();
	//es.think();
	//es.explain();
	
	ui.setupUi(this);
}

AnimalES::~AnimalES()
{

}

void AnimalES::on_pushButton_createKB_clicked()
{
	es.creatKB();
	causeBase = es.getCauseBase();
	knowledgeBase = es.getKnowledgeBase();
	r.exec();
}

