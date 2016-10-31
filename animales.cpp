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
		QMessageBox::information(this,"创建成功","成功加载文件中规则库");
	}
	else
	{
		QMessageBox::warning(this, "未发现数据库", "开始初始化规则库");
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

void AnimalES::on_pushButton_explain_clicked()
{
	s = new ShowExplanation(&es);
	s->exec();
	delete s;
}

void AnimalES::on_pushButton_modify_clicked()
{
	r = new  RulesMGMT(&es);
	r->exec();
	delete r;
}

void AnimalES::on_pushButton_think_clicked()
{
	if (!es.getDataBase().isEmpty())
	{
		es.think();
		if (!es.getConclusion().isEmpty())
		{
			QString result = es.getConclusion().last().getCauseName();
			QMessageBox::information(this, "推理完成", result);
		}
		else
		{
			QMessageBox::information(this, "推理完成", "推理完成,但并未找到结果");
		}
	}
	else
	{
		QMessageBox::warning(this, "推理失败", "请先输入事实");
	}
}

void AnimalES::on_pushButton_quit_clicked()
{
	if (!es.getKnowledgeBase().isEmpty())
	{
		es.saveKB();
	}
	this->close();
}

