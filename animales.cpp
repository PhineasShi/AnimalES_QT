#include "animales.h"
#include "expertSystem.h"
AnimalES::AnimalES(QWidget *parent)
	: QMainWindow(parent)
{
	ES es;
	es.creatKB();
	
	QList<Cause> cb=es.getCauseBase();
	QList<Rule> kb = es.getKnowledgeBase();

	for (Cause cause : cb)
	{
		qDebug() << cause.getCauseName() << endl;
	}


	/*for (Rule rule : kb)
	{
		qDebug() << "result:  "<< rule.getResult() << endl;
		QList<Cause> causes = rule.getCause();
		qDebug() << "causes:  " << endl;
		for (Cause ctmp : causes)
		{
			qDebug() << ctmp.getCauseName() << endl;
		}
	}
*/
	ui.setupUi(this);
}

AnimalES::~AnimalES()
{

}

