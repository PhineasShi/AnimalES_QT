#include "rule.h"
Rule::Rule()
{
}

Rule::~Rule()
{
}

std::string Rule::getResult()
{
	return result;
}

void Rule::setResult(std::string result)
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
