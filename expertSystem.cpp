#include "expertSystem.h"

using namespace std;
ES::ES()
{

}

ES::~ES()
{
	//comment here!
}

//TODO 对文件内容为空和格式不正确的判断
bool ES::creatKB()
{
	//以只读的方式打开文件
	QFile file("ES.dat");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return false;
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

	bool endflag = false;
	while (true)
	{
		QList<int> delInx;
		int conclusionNumPre = conclusion.count();
		int ruleNum = knowledgeBase.count();
		int i = 0;
		while (i<knowledgeBase.count())
		{
			
			ruleNum = knowledgeBase.count();
			int databaseNum = dataBase.count();
			Rule rule = knowledgeBase.at(i);
			QList<Cause> causes = rule.getCauses();
			int causeNum = causes.count();
			int count = 0;

			qDebug() << "rule " << i + 1 << " :   " << endl;
			qDebug() << rule.getResult().getCauseName() << "  ";
			for (Cause cause : causes)
			{
				qDebug() << cause.getCauseName() << "  ";
			}
			qDebug() << endl;

			for (int i = 0; i < causeNum; i++)
			{	
				Cause ruleCause = causes.at(i);
				for (int j = 0; j < databaseNum; j++)
				{
					Cause databaseCause = dataBase.at(j);
					if (ruleCause.getCauseName() == databaseCause.getCauseName())
					{
						delInx.push_back(j);
						count++;
						break;
					}
				}
			}

			qDebug() << "-------------match count:----" << count << endl;

			if (causeNum == count)
			{
				if (!rule.isLast())
				{
					for (int index : delInx)
					{
						dataBase.removeAt(index);
					}

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
					endflag = true;
					break;
				}
			}
			i++;
		}

		/*for (Cause cause : dataBase)
		{
			qDebug() << "++++++++" << cause.getCauseName() << endl;
		}*/

		if (endflag)
		{
			break;
		}

		
		if (conclusionNumPre == conclusion.count())
		{
			/*qDebug() << "----------"<<conclusionNumPre<<"----------------"<<conclusion.count() <<endl;*/
			break;
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

bool ES::deleteRuleAt(int row)
{
	bool causesDeleted= false;
	Rule rule = knowledgeBase[row];
	knowledgeBase.removeAt(row);
	Cause result = rule.getResult();
	//Try to delete the result
	if (!isCauseUseful(result))
	{
		deleteCause(result);
		causesDeleted = true;
	}
	QList<Cause> causes = rule.getCauses();
	//Try to delete the causes in the result
	for (int i = 0; i < causes.length(); i++)
	{
		if (!isCauseUseful(causes[i]))
		{
			deleteCause(causes[i]);
			causesDeleted = true;
		}
	}
	return causesDeleted;
}
bool ES::deleteCause(Cause cause)
{
	for (int i = 0; i < causeBase.length(); i++)
	{
		if (causeBase[i]==cause)
		{
			causeBase.removeAt(i);
			return true;
		}
	}
	return false;
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
			return true;
		}
		QList<Cause> causes = rule.getCauses();
		//Is the cause used in the causes
		for (int i = 0; i < causes.length(); i++)
		{
			if (causes[i]==cause)
			{
				return true;
			}
		}
	}
	return false;
}

