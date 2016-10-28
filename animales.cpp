#include "animales.h"
#include "expertSystem.h"
AnimalES::AnimalES(QWidget *parent)
	: QMainWindow(parent)
{
	ES es;
	es.creatKB();
	ui.setupUi(this);
}

AnimalES::~AnimalES()
{

}

