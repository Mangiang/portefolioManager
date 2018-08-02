#include "PortefolioManager.h"
#include <QtWidgets/QApplication>

#include <stdlib.h>
#include <crtdbg.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PortefolioManager w;
	return a.exec();
}
