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

#include "frame.h"
#include "inputStreamCommands.h"
#include "renderStream.h"
#include "outputStream.h"
#include "logger.h"

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

	InputStreamCommands *pInputStreamCommands = new InputStreamCommands();
	pInputStreamCommands->setLogger(pLogger);
	
	RenderStream *pRenderStream = new RenderStream();
	pRenderStream->setLogger(pLogger);
	
	OutputStream *pOutputStream = new OutputStream();
	pOutputStream->setLogger(pLogger);

	pRenderStream->setInputStream(pInputStreamCommands);
	pRenderStream->setOutputStream(pOutputStream);

	pInputStreamCommands->start(31001); // started server on 31001 port 

	pRenderStream->setParams(params); // todo depricate
	pRenderStream->start();

	pOutputStream->start();

	return app.exec();
}
