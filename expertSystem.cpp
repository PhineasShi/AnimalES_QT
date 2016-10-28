#include "expertSystem.h"

using namespace std;
ES::ES()
{

}

ES::~ES()
{
	//comment here!
}

void ES::creatKB()
{
	//以只读的方式打开文件
	QFile file("ES.dat");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	QTextStream in(&file);
	//清空causeBase
	causeBase.clear();
	//清空knowledgeBase
	knowledgeBase.clear();
	Rule tmpRule;

	//每次读取一行，并根据分隔符将字符串分别用来初始化各数据库
	while (!in.atEnd()) {
		QString line = in.readLine();
		QStringList qstr = line.split(":");

		QString result = qstr.at(0);
		QString isLaststr = qstr.at(1);
		bool isLastbool = (isLaststr == "true");
		QString causes = qstr.at(2);

		QStringList causesQL = causes.split(",");

		QList<Cause> qc;
		for (QString tmp : causesQL)
		{
			Cause cause;
			cause.setCauseName(tmp);
			qc.push_back(cause);

			if (!isCauseExist(cause))
			{
				causeBase.push_back(cause);
			}
		}

		tmpRule.setResult(result);
		tmpRule.setLast(isLastbool);
		tmpRule.setCause(qc);
		knowledgeBase.push_back(tmpRule);
	}
}

/*
	判断在causeBase中与给定的cause是否重复
*/
bool ES::isCauseExist(Cause cause)
{
	bool flag = false;
	for (Cause tmp : causeBase)
	{
		if (tmp.getCauseName() == cause.getCauseName())
		{
			flag = true;
		}
	}
	return flag;
}


/*
	在调用think函数之前，应当保证dataBase中有用户输入的前提条件  Causes
*/
void ES::think() {

	/*Cause temp;
	temp.setCauseName("cause1");
	dataBase.push_back(temp);

	temp.setCauseName("cause2");
	dataBase.push_back(temp);

	temp.setCauseName("cause4");
	dataBase.push_back(temp);*/


	bool endflag = false;
	while (true)
	{
		int ruleNum = knowledgeBase.size();
		int i = 0;
		while (i<knowledgeBase.size())
		{
			ruleNum = knowledgeBase.size();
			int databaseNum = dataBase.size();
			Rule rule = knowledgeBase.at(i);
			QList<Cause> causes = rule.getCause();
			int causeNum = causes.size();
			int count = 0;
			for (int i = 0; i < causeNum; i++)
			{	
				Cause ruleCause = causes.at(i);
				for (int j = 0; j < databaseNum; j++)
				{
					Cause databaseCause = dataBase.at(j);
					if (ruleCause.getCauseName() == databaseCause.getCauseName())
					{
						count++;
						break;
					}
				}
			}

			if (causeNum == count&&count==databaseNum)
			{
				if (!rule.isLast())
				{
					used.push_back(rule);
					knowledgeBase.removeAt(i);
					Cause causet;
					causet.setCauseName(rule.getResult());
					conclusion.push_back(causet);
					dataBase.push_back(causet);
					break;
				}
				else
				{
					endflag = true;
					Cause causet;
					causet.setCauseName(rule.getResult());
					conclusion.push_back(causet);
					qDebug() << "the last result is :  " << rule.getResult() << endl;
					return;
				}
			}
			i++;
		}	
	}
}


void ES::explain() {

	qDebug() << "the conclusion is    " << endl;
	for (Cause tmp : conclusion)
	{
		qDebug() <<tmp.getCauseName()<< endl;
	}
}