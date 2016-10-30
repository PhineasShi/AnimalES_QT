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

void AnimalES::on_pushButton_inputCauses_clicked()
{
	i = new InputCauses(&es);
	i->exec();
	delete i;
}

void AnimalES::on_pushButton_modify_clicked()
{
	r = new  RulesMGMT(&es);
	r->exec();
	delete r;
}

void AnimalES::on_pushButton_think_clicked()
{

	QList<Cause> dataBase;
	Cause temp;
	temp.setCauseName("���ߵ�");
	dataBase.push_back(temp);

	temp.setCauseName("������");
	dataBase.push_back(temp);

	temp.setCauseName("����");
	dataBase.push_back(temp);

	temp.setCauseName("����");
	dataBase.push_back(temp);

	temp.setCauseName("ë��");
	dataBase.push_back(temp);

	temp.setCauseName("����");
	dataBase.push_back(temp);

	es.setDataBase(dataBase);
	es.think();
	if (!es.getConclusion().isEmpty())
	{
		QString result = es.getConclusion().last().getCauseName();
		QMessageBox::information(this, "�������", result);
	}
	else
	{
		QMessageBox::information(this, "�������", "�������,����δ�ҵ����");
	}
	
	
	
	/*if (!es.getDataBase().isEmpty())
	{
		es.think();
		QString result = es.getConclusion().last().getCauseName();
		QMessageBox::information(this, "�������", result);
	}
	else
	{
		QMessageBox::warning(this, "����ʧ��", "����������ʵ");
	}*/
	
}

