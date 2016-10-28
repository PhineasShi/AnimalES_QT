#include "animales.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	AnimalES w;
	w.show();
	return a.exec();
}
