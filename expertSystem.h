#pragma once
#include <QFile>
#include <QTextStream>
#include <qdebug.h>
#include <QStringList>
#include <QList>
#include "rule.h"
#include "cause.h"
class ES
{
public:
	ES();
	~ES();
	void creatKB();
	QList<Cause> setCauseBase(QList<Cause> cb);
	

	

private:
	QList<Cause> causeBase;
	QList<Cause> dataBase;
	QList<Cause> conclusion;
	QList<Rule> knowledgeBase;
	QList<Rule> used;
	bool isCauseExist(Cause cause);
	

};

