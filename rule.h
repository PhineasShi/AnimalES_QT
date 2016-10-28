#pragma once

#include <list>

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
	std::list<Cause> getCause();
	void setCause(std::list<Cause> causes);

private:
	QString result;
	bool last;
	std::list<Cause> causes;
};