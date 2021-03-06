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
	//清空conclusion
	conclusion.clear();
	//清空步骤解释
	procedure.clear();

	Rule tmpRule;

	//每次读取一行，并根据分隔符将字符串分别用来初始化各数据库
	while (!in.atEnd()) {
		QString line = in.readLine();
		QStringList qstr = line.split(":");

		QString result = qstr.at(0);
		bool isLastbool = QVariant::fromValue(qstr.at(1)).toBool();
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

void ES::saveKB()
{
	QFile file("ES.dat");
	//if (file.exists())
	//{
	//	file.remove();
	//}
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return;
	QTextStream out(&file);
	for (int i = 0; i < knowledgeBase.length(); i++)
	{
		Cause result = knowledgeBase[i].getResult();
		out << result.getCauseName() << ":" << knowledgeBase[i].isLast() << ":";
		QList<Cause> causes = knowledgeBase[i].getCauses();
		int j = 0;
		for (j = 0; j < causes.length() - 1; j++)
		{
			out << causes[j].getCauseName() << ",";
		}
		out << causes[j].getCauseName() << endl;
	}
	file.close();
}

/*
	判断在causeBase中与给定的cause是否重复
*/
bool ES::isCauseExist(Cause cause)
{
	bool flag = false;
	for (Cause tmp : causeBase)
	{
		if (tmp == cause)
		{
			flag = true;
		}
	}
	return flag;
}

bool ES::isLastResult(Cause cause)
{
	for (int i = 0; i < knowledgeBase.length(); i++)
	{
		if (knowledgeBase[i].getResult() == cause&&knowledgeBase[i].isLast())
		{
			return true;
		}

	}
	return false;
}


/*
	在调用think函数之前，应当保证dataBase中有用户输入的前提条件  Causes
*/
void ES::think() {
	used.clear();
	bool endflag = false;
	/*将用户输入的事实加入到综合数据库中*/
	conclusion = dataBase;
	/*将解释说明清空*/
	procedure.clear();
	while (true)
	{
		QList<int> delInx;
		int UsedNumPre = used.count();
		int ruleNum = knowledgeBase.count();
		int i = 0;
		while (i < knowledgeBase.count())
		{
			ruleNum = knowledgeBase.count();
			int conclusionNum = conclusion.count();
			Rule rule = knowledgeBase.at(i);
			QList<Cause> causes = rule.getCauses();
			int causeNum = causes.count();
			int count = 0;
			for (int i = 0; i < causeNum; i++)
			{
				Cause ruleCause = causes.at(i);
				for (int j = 0; j < conclusionNum; j++)
				{
					Cause conclusionCause = conclusion.at(j);
					if (ruleCause.getCauseName() == conclusionCause.getCauseName())
					{
						count++;
						break;
					}
				}
			}

			if (causeNum == count)		//如果某一条规则和综合数据库中的前提完全匹配
			{
				if (!rule.isLast())		//如果这条规则不是最终的
				{
					Cause causet = rule.getResult();
					QString name = causet.getCauseName();
					if (!isCauseExsistInCon(causet))	//判断这个结论在综合数据库中是否存在，如果存在，就不再加入综合数据库
					{
						conclusion.push_back(causet);
					}
					used.push_back(rule);			//将这条不是最终的规则加入到已使用List（used）中
					knowledgeBase.removeAt(i);		//将这条不是最终的规则移除
					procedure.push_back(rule);
					break;
				}
				else
				{
					endflag = true;					//推理结束，并且已经找到这个动物
					Cause causet = rule.getResult();
					conclusion.push_back(causet);	//将最终的这个动物放到conlusion中	
					qDebug() << "the last result is :  " << rule.getResult().getCauseName() << endl;
					procedure.push_back(rule);
					break;
				}
			}
			i++;
		}

		if (endflag)
		{
			break;
		}

		if (UsedNumPre == used.count())	//如果根据已知事实，推理不出特定的动物，将conclusion清空
		{
			conclusion.clear();
			qDebug() << "result not found!" << endl;
			break;
		}
	}

	/*打印一些用于调试的信息*/
	qDebug() << "-------------" << endl;

	for (Rule temp : procedure)
	{
		QList<Cause> ctmp = temp.getCauses();
		int j = 0;
		for (; j < ctmp.count() - 1; j++)
		{
			Cause cause = ctmp.at(j);
			qDebug() << cause.getCauseName() << ",";
		}
		Cause cause = ctmp.last();
		qDebug() << cause.getCauseName() << "--->";
		qDebug() << temp.getResult().getCauseName() << endl;
	}


	int knum = knowledgeBase.count();

	/*推理结束后将规则库恢复*/
	for (Rule rule : used)
	{
		knowledgeBase.push_back(rule);
	}

	knum = knowledgeBase.count();

}


void ES::explain() {

	qDebug() << "the conclusion is    " << endl;
	for (Cause tmp : conclusion)
	{
		qDebug() << tmp.getCauseName() << endl;
	}
}

bool ES::deleteRuleAt(int row)
{
	bool causesDeleted = false;
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
		if (causeBase[i] == cause)
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
		if (rule.getResult() == cause)
		{
			return true;
		}
		QList<Cause> causes = rule.getCauses();
		//Is the cause used in the causes
		for (int i = 0; i < causes.length(); i++)
		{
			if (causes[i] == cause)
			{
				return true;
			}
		}
	}
	return false;
}

bool ES::isCauseExsistInCon(Cause cause)
{
	bool flag = false;

	for (Cause tmp : conclusion)
	{
		if (cause.getCauseName() == tmp.getCauseName())
		{
			return true;
		}
	}

	return flag;
}
