#include "expertSystem.h"

using namespace std;
ES::ES()
{

}

ES::~ES()
{
	//comment here!
}

//TODO ���ļ�����Ϊ�պ͸�ʽ����ȷ���ж�
bool ES::creatKB()
{
	//��ֻ���ķ�ʽ���ļ�
	QFile file("ES.dat");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return false;
	QTextStream in(&file);
	//���causeBase
	causeBase.clear();
	//���knowledgeBase
	knowledgeBase.clear();
	Rule tmpRule;

	//ÿ�ζ�ȡһ�У������ݷָ������ַ����ֱ�������ʼ�������ݿ�
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
		Cause resultCause;
		resultCause.setCauseName(result);
		if (!isCauseExist(resultCause))
		{
			causeBase.push_back(resultCause);
		}
		tmpRule.setResult(resultCause);
		tmpRule.setLast(isLastbool);
		tmpRule.setCauses(qc);
		knowledgeBase.push_back(tmpRule);
	}
	return true;
}

/*
	�ж���causeBase���������cause�Ƿ��ظ�
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
	�ڵ���think����֮ǰ��Ӧ����֤dataBase�����û������ǰ������  Causes
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
			QList<Cause> causes = rule.getCauses();
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
					Cause causet= rule.getResult();
					conclusion.push_back(causet);
					dataBase.push_back(causet);
					break;
				}
				else
				{
					endflag = true;
					Cause causet= rule.getResult();
					conclusion.push_back(causet);
					qDebug() << "the last result is :  " << rule.getResult().getCauseName() << endl;
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

void ES::deleteRule(Rule rule)
{

}
bool ES::isCauseUseful(Cause cause)
{
	QString causeName = cause.getCauseName();
	for (int i = 0; i < knowledgeBase.length(); i++)
	{
		Rule rule = knowledgeBase[i];
		//Is cause used in the result
		if (rule.getResult()==cause)
		{
			return false;
		}
		QList<Cause> causes = rule.getCauses();
		//Is the cause used in the causes
		for (int i = 0; i < causes.length(); i++)
		{
			if (causes[i]==cause)
			{
				return false;
			}
		}
	}
	return true;
}