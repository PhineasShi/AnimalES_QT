#include "expertSystem.h"
#include <QFile>
#include <QTextStream>
#include <qdebug.h>

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
		Cause tmpCause;
		

		qDebug() << line << endl;
	}
}
