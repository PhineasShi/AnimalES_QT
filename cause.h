#pragma once

#include <string>

class Cause
{
public:
	Cause();
	~Cause();

	std::string getCauseName();
	void setCauseName(std::string causeName);

private:
	std::string causeName;
};

