#pragma once

#include <string>
#include <list>

#include "cause.h"
class Rule
{
public:
	Rule();
	~Rule();

	std::string getResult();
	void setResult(std::string result);
	bool isLast();
	void setLast(bool last);
	std::list<Cause> getCause();
	void setCause(std::list<Cause> causes);

private:
	std::string result;
	bool last;
	std::list<Cause> causes;
};