#pragma once

#include <QString>

class Cause
{
public:
	Cause();
	~Cause();

	QString getCauseName();
	void setCauseName(QString causeName);

	bool operator==(Cause &cause);

private:
	QString causeName;
};

