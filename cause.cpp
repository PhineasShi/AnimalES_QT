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

bool Cause::operator==(Cause & cause)
{
	return this->causeName==cause.causeName;
}


