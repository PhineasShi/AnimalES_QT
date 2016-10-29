#include "rule.h"
Rule::Rule()
{
}

Rule::~Rule()
{
}

Cause Rule::getResult()
{
	return result;
}

void Rule::setResult(Cause result)
{
	this->result = result;
}

bool Rule::isLast()
{
	return last;
}

void Rule::setLast(bool last)
{
	this->last = last;
}

QList<Cause> Rule::getCauses()
{
	return causes;
}

void Rule::setCauses(QList<Cause> causes)
{
	this->causes = causes;
}
