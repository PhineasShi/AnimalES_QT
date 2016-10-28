#include "cause.h"

Cause::Cause()
{
}

Cause::~Cause()
{
}

QString Cause::getCauseName()
{
	return causeName;
}

void Cause::setCauseName(QString causeName)
{
	this->causeName = causeName;
}


