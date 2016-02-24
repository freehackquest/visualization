#include <QApplication>
#include <QString>
#include <QMap>
#include <QDir>
#include <QImage>
#include <QTime>
#include <QFont>
#include <QList>
#include <QPaintDevice>
#include <QVector>
#include <QImage>
#include <QColor>

#include <iostream>
#include <math.h>
#include "core.h"


int main(int argc, char *argv[]){
	QApplication app(argc, argv);

	QVector<QString> params;
	for(int i = 0; i < argc; i++){
		params.push_back(argv[i]);
	}

	Logger *pLogger = new Logger("visualization.log");
	pLogger->info("visualization started.");
	if(params.indexOf("--disablelog") >= 0)
		pLogger->disable();

	Core *pCore = new Core(pLogger);
	pCore->start();

	return app.exec();
}
