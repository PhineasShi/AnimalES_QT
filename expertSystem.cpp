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
		return ;
	QTextStream out(&file);
	for (int i = 0; i < knowledgeBase.length(); i++)
	{
		Cause result = knowledgeBase[i].getResult();
		out << result.getCauseName() << ":" << knowledgeBase[i].isLast() << ":";
		QList<Cause> causes = knowledgeBase[i].getCauses();
		int j = 0;
		for (j = 0; j < causes.length()-1; j++)
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


/*
	在调用think函数之前，应当保证dataBase中有用户输入的前提条件  Causes
*/
void ES::think() {
	bool endflag = false;
	conclusion = dataBase;
	while (true)
	{
		QList<int> delInx;
		int UsedNumPre = used.count();
		int ruleNum = knowledgeBase.count();
		int i = 0;
		while (i<knowledgeBase.count())
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
						//delInx.push_back(j);
						count++;
						break;
					}
				}
			}

			if (causeNum == count)		//如果某一条规则和综合数据库中的前提完全匹配
			{
				if (!rule.isLast())		//如果这条规则不是最终的
				{
					//for (int index : delInx)
					//{
					//	int inx = index;
					//	conclusion.removeAt(index);	//修改综合数据库，将已经使用的事实移除
					//}
					Cause causet = rule.getResult();
					QString name = causet.getCauseName();
					if (!isCauseExsistInCon(causet))	//判断这个结论在综合数据库中是否存在，如果存在，就不再加入综合数据库
					{
						conclusion.push_back(causet);	
						/*dataBase.push_back(causet);*/
					}
					used.push_back(rule);			//将这条不是最终的规则加入到已使用List（used）中
					knowledgeBase.removeAt(i);		//将这条不是最终的规则移除
					break;
				}
				else
				{
					endflag = true;					//推理结束，并且已经找到这个动物
					Cause causet= rule.getResult();
					/*for (Cause temp : causes)
					{
						conclusion.push_back(temp);
					}*/
					conclusion.push_back(causet);	//将最终的这个动物放到conlusion中	

					qDebug() << "the last result is :  " << rule.getResult().getCauseName() << endl;
					break;
				}
			}
			i++;
			
			/*for (Cause temp : conclusion)
			{
				qDebug() << temp.getCauseName()<<endl;
			}*/
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