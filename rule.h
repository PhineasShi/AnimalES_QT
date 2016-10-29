#pragma once

#include <QList>

#include "cause.h"
class Rule
{
public:
	Rule();
	~Rule();

	Cause getResult();
	void setResult(Cause result);

	bool isLast();
	void setLast(bool last);

	QList<Cause> getCauses();
	void setCauses(QList<Cause> causes);

private:
	Cause result;
	bool last;
	QList<Cause> causes;
};