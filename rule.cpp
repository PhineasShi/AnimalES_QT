#include "rule.h"
Rule::Rule()
{
}

Rule::~Rule()
{
}

QString Rule::getResult()
{
	return result;
}

void Rule::setResult(QString result)
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

std::list<Cause> Rule::getCause()
{
	return causes;
}

void Rule::setCause(std::list<Cause> causes)
{
	this->causes = causes;
}
