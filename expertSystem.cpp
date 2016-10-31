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
	//���conclusion
	conclusion.clear();
	Rule tmpRule;

	//ÿ�ζ�ȡһ�У������ݷָ������ַ����ֱ�������ʼ�������ݿ�
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
	�ж���causeBase���������cause�Ƿ��ظ�
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
	�ڵ���think����֮ǰ��Ӧ����֤dataBase�����û������ǰ������  Causes
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

			if (causeNum == count)		//���ĳһ��������ۺ����ݿ��е�ǰ����ȫƥ��
			{
				if (!rule.isLast())		//����������������յ�
				{
					//for (int index : delInx)
					//{
					//	int inx = index;
					//	conclusion.removeAt(index);	//�޸��ۺ����ݿ⣬���Ѿ�ʹ�õ���ʵ�Ƴ�
					//}
					Cause causet = rule.getResult();
					QString name = causet.getCauseName();
					if (!isCauseExsistInCon(causet))	//�ж�����������ۺ����ݿ����Ƿ���ڣ�������ڣ��Ͳ��ټ����ۺ����ݿ�
					{
						conclusion.push_back(causet);	
						/*dataBase.push_back(causet);*/
					}
					used.push_back(rule);			//�������������յĹ�����뵽��ʹ��List��used����
					knowledgeBase.removeAt(i);		//�������������յĹ����Ƴ�
					break;
				}
				else
				{
					endflag = true;					//��������������Ѿ��ҵ��������
					Cause causet= rule.getResult();
					/*for (Cause temp : causes)
					{
						conclusion.push_back(temp);
					}*/
					conclusion.push_back(causet);	//�����յ��������ŵ�conlusion��	

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

		if (UsedNumPre == used.count())	//���������֪��ʵ���������ض��Ķ����conclusion���
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