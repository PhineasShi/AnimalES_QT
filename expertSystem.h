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
	bool creatKB();
	void think();
	void explain();

	




	/*getters and setters*/
	void setCauseBase(QList<Cause> cb) { causeBase = cb; };
	QList<Cause> getCauseBase() { return causeBase; };
	
	void setDataBase(QList<Cause> db) { dataBase = db; };
	QList<Cause> getDataBase() { return dataBase; };

	void setConclusion(QList<Cause> cc) { conclusion = cc; };
	QList<Cause> getConclusion() { return conclusion; };

	void setKnowledgeBase(QList<Rule> kb) { knowledgeBase = kb; };
	QList<Rule> getKnowledgeBase() { return knowledgeBase; };

	void setUsed(QList<Rule> u) { used = u; };
	QList<Rule> getUsed() { return used; };


private:
	QList<Cause> causeBase;
	QList<Cause> dataBase;
	QList<Cause> conclusion;
	QList<Rule> knowledgeBase;
	QList<Rule> used;
	void deleteRule(Rule rule);
	bool isCauseExist(Cause cause);
	bool isCauseUseful(Cause cause);	//Detemine the cause is useful or not.

};

