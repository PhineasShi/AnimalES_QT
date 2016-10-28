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
	QFile file("ES.dat");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	QTextStream in(&file);
	dataBase.clear();
	knowledgeBase.clear();
	Rule tmpRule;
	while (!in.atEnd()) {
		QString line = in.readLine();
		QStringList qstr = line.split(":");
		
		QString result = qstr.at(0);
		QString causes = qstr.at(1);

		QStringList causesQL = causes.split(",");

		QList<Cause> qc;
		for (QString tmp : causesQL)
		{
			Cause cause;
			cause.setCauseName(tmp);
			qc.push_back(cause);

			if (!isCauseExist(cause))
			{
				dataBase.push_back(cause);
			}

		}

		tmpRule.setResult(result);
		tmpRule.setCause(qc);
		knowledgeBase.push_back(tmpRule);
		
	}

	
}

bool ES::isCauseExist(Cause cause)
{
	bool flag = false;
	for (Cause tmp : dataBase)
	{
		if (tmp.getCauseName() == cause.getCauseName())
		{
			flag = true;
		}
	}
	return flag;
}