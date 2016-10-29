#include "animales.h"

#pragma execution_character_set("utf-8")

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
	if (es.creatKB())
	{
		QMessageBox::information(this,"�����ɹ�","�ɹ������ļ��й����");
	}
	else
	{
		QMessageBox::warning(this, "δ�������ݿ�", "��ʼ��ʼ�������");
		r = new  RulesMGMT(&es);
		r->exec();
		delete r;
	}
}

void AnimalES::on_pushButton_modify_clicked()
{
	r = new  RulesMGMT(&es);
	r->exec();
	delete r;
}

