#pragma once
#include <QFile>
#include <QTextStream>
#include <qdebug.h>
#include <QStringList>
#include "rule.h"
#include "cause.h"
class ES
{
public:
	ES();
	~ES();
	void creatKB();
private:
	std::list<Cause> dataBase;
	std::list<Cause> conclusion;
	std::list<Rule> knowledgeBase;
	std::list<Rule> used;

	

};

