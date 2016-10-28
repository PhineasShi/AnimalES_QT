#pragma once

#include <QList>
#include "cause.h"
class Rule
{
public:
	Rule();
	~Rule();

	QString getResult();
	void setResult(QString result);
	bool isLast();
	void setLast(bool last);
	QList<Cause> getCause();
	void setCause(QList<Cause> causes);

private:
	QString result;
	bool last;
	QList<Cause> causes;
};